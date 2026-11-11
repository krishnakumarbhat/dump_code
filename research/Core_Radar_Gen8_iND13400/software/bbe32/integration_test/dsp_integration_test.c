/*===========================================================================*/
/**
 * @file dsp_integration_test.c
 *
 * SWE5 Integration Test Implementation for BBE32/DSP Core
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2026 Aptiv. All rights reserved.
 * Aptiv Sensitive Business - Restricted Aptiv information. Do not disclose.
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *   Implements stubbing and validation functions for the BBE32/DSP core
 *   integration test (SWE5) framework. Provides Set_Shared_Ptr, stub/validate
 *   helpers, IPC transfer, and module-specific test functions.
 *
 * @section ABBR ABBREVIATIONS:
 *   - IPC  - Inter-Processor Communication
 *   - SWE5 - Software Engineering Level 5 (Integration Testing)
 *   - SIT  - Software Integration Testing
 *   - RDD  - Range Doppler Detection
 *   - AF   - Angle Finding
 *   - USC  - Unit Specific Calibration
 *   - D2M  - DSP to Master
 *   - M2D  - Master to DSP
 *
 * @section TRACE TRACEABILITY INFO:
 *   - Design Document(s):
 *     - SWE5 Integration Test Framework Design
 *
 *   - Requirements Document(s):
 *     - Integration test framework for Gen8 radar system
 *
 *   - Applicable Standards (in order of precedence: highest first):
 *     - ESGW_4-2_PE-SWx_00-01-A02_EN - C Coding Standards [20120506]
 *
 * @section DFS DEVIATIONS FROM STANDARDS:
 *   - None.
 *
 * @defgroup dsp_integration_test_impl DSP Integration Test Implementation
 * @{
 */
/*==========================================================================*/

#if defined(Integration_Testing)

   /*===========================================================================*
    * Standard Header Files
    *===========================================================================*/
   #include <math.h>
   #include <string.h>

   /*===========================================================================*
    * Other Header Files
    *===========================================================================*/
   #include "dsp_integration_test.h"

/*===========================================================================*
 * Local Preprocessor #define Constants
 *===========================================================================*/

/*===========================================================================*
 * Local Preprocessor #define MACROS
 *===========================================================================*/
/* Section attribute macros - Integration test uses SRAM0 (large DDR-backed memory)
 * for both code and data to avoid overflowing small DTCM regions. */
   #define SRAM0_BSS       __attribute__((section(".sram0.bss")))        /* Zero-init data in SRAM0 */
   #define SRAM0_DATA      __attribute__((section(".sram0.data")))       /* Non-zero init data in SRAM0 */
   #define SRAM0_TEXT      __attribute__((section(".sram0.text")))       /* Code/functions in SRAM0 */
   #define SRAM0_BSS_USED  __attribute__((section(".sram0.bss"), used))  /* + prevent optimization */
   #define SRAM0_TEXT_USED __attribute__((section(".sram0.text"), used)) /* + prevent optimization */
   #define ATTR_UNUSED     __attribute__((unused))                       /* Suppress unused warnings */

/* Helper macro for receivers - check if provider stub succeeded before validating */
   #define CHECK_PROVIDER_STUB(flag)                                                                                              \
      if (!(flag))                                                                                                                \
      {                                                                                                                           \
         DSP_Res = TEST_STUB_INVALID;                                                                                             \
         return;                                                                                                                  \
      }

/*===========================================================================*
 * Local Type Declarations
 *===========================================================================*/

/*===========================================================================*
 * Exported Object Definitions
 *===========================================================================*/

/*===========================================================================*
 * Local Const Object Definitions
 *===========================================================================*/

/*===========================================================================*
 * Local Object Definitions
 *===========================================================================*/
/* Global pointer structures for debugger visibility */
/* Common Provider Pointer for DSP Core - shows provider test data */
/* Placed in SRAM0 (DDR-backed) to avoid DTCM0 overflow */
volatile SRAM0_BSS_USED G_Pointer_T DSP_Shared_Pi;

/* Common Receiver Pointer for DSP Core - shows receiver test data */
/* Placed in SRAM0 (DDR-backed) to avoid DTCM0 overflow */
volatile SRAM0_BSS_USED G_Pointer_T DSP_Shared_Ri;

/* Variables for integration testing in DSP core */
/* Test interface number identifying which interface is being tested */
/* Placed in SRAM0 (DDR-backed) to avoid DTCM0 overflow */
static SRAM0_BSS uint32_t DSP_Test_Iface_Num = 0U;

/* Stub value to be injected into test data for validation */
/* Placed in SRAM0 (DDR-backed) to avoid DTCM0 overflow */
static SRAM0_BSS double DSP_Stub_Val = 0.0;

/* Number of elements in the stub array for batch operations */
/* Placed in SRAM0 (DDR-backed) to avoid DTCM0 overflow */
static SRAM0_DATA uint32_t DSP_Stub_Len = 1U;

/* Result status of the current SIT test execution */
/* Placed in SRAM0 (DDR-backed) to avoid DTCM0 overflow */
static SRAM0_DATA SIT_Test_Result_T DSP_Res = TEST_NOT_PERFORMED;

/* Last interface number processed - used to detect interface changes */
/* Placed in SRAM0 (DDR-backed) to avoid DTCM0 overflow */
static SRAM0_BSS uint32_t last_interface_number = 0U;

/* Last stub value processed - used to detect stub value changes */
/* Placed in SRAM0 (DDR-backed) to avoid DTCM0 overflow */
static SRAM0_BSS double last_stub_value = 0.0;

/* Provider stub validation success flag - indicates if provider successfully stubbed and validated the value */
static bool DSP_Prov_Stub_From_Master = false;
static bool DSP_Prov_Stub             = false;

   #if defined(FirstPass_IT)
// First pass provider stub validation success flag
static bool FP_Provider_Stubbed = false;
   #endif /* FirstPass_IT */

/*===========================================================================*
 * Local Function Prototypes
 *===========================================================================*/
static void Stub_Scalar_Values(void *dstb_ptr, DataType_T data_type, double stub_value);
static void Stub_1D_Array_Values(void *dstb_ptr, DataType_T data_type, double stub_value, uint32_t num_elements);
static void Stub_3D_Array_Values(void *dstb_ptr, DataType_T data_type, double stub_value, uint32_t dim1, uint32_t dim2,
                                 uint32_t dim3);
static bool Validate_Scalar_Values(const void *dvld_ptr, DataType_T data_type, double expected_value);
static bool Validate_1D_Array_Values(const void *dvld_ptr, DataType_T data_type, double expected_value, uint32_t num_elements);
static bool Validate_3D_Array_Values(const void *dvld_ptr, DataType_T data_type, double expected_value, uint32_t dim1,
                                     uint32_t dim2, uint32_t dim3);
static SIT_Test_Result_T Is_Valid_Interface(uint32_t interface_number);
static inline void Set_Shared_Ptr(volatile G_Pointer_T *dst_ptr, const void *src_ptr, size_t elem_size, size_t no_of_elements,
                                  Test_Interface_Name_T name, DataType_T data_type);

/*===========================================================================*
 * Local Inline Function Definitions and Function-Like Macros
 *===========================================================================*/

/******************************************************************************
 * Name:  Set_Shared_Ptr
 *   Helper function to set common global pointer structure for debugger visibility.
 *
 * Shared Variables: none
 *
 * Parameters: dst_ptr - Pointer to common global pointer structure to populate
 *             src_ptr - Pointer to the data variable
 *             elem_size - Size of each element in bytes
 *             no_of_elements - Number of elements in the data variable
 *             name - Enum identifying the variable (for debugger display)
 *             data_type - Data type enumeration
 *
 * Return Value: none
 *
 * Design Information:
 *  - Provides type-safe pointer assignment based on data type
 *
 *  Change References:
 *  - Initial implementation
 *
 ******************************************************************************/
static inline SRAM0_TEXT ATTR_UNUSED void Set_Shared_Ptr(volatile G_Pointer_T *dst_ptr, const void *src_ptr, size_t elem_size,
                                                         size_t no_of_elements, Test_Interface_Name_T name, DataType_T data_type)
{
   switch (data_type)
   {
      case DATATYPE_UINT8:
         dst_ptr->data.u8 = (uint8_t *)src_ptr;
         break;
      case DATATYPE_UINT16:
         dst_ptr->data.u16 = (uint16_t *)src_ptr;
         break;
      case DATATYPE_UINT32:
         dst_ptr->data.u32 = (uint32_t *)src_ptr;
         break;
      case DATATYPE_INT16:
         dst_ptr->data.i16 = (int16_t *)src_ptr;
         break;
      case DATATYPE_INT32:
         dst_ptr->data.i32 = (int32_t *)src_ptr;
         break;
      case DATATYPE_FLOAT32:
         dst_ptr->data.f32 = (float *)src_ptr;
         break;
      default:
         dst_ptr->data.ptr = (void *)src_ptr;
         break;
   }

   dst_ptr->elem_size      = elem_size;
   dst_ptr->no_of_elements = no_of_elements;
   dst_ptr->name           = name;
   dst_ptr->data_type      = data_type;
}

/******************************************************************************
 * Name:  Clear_Prov_Stub_Flags
 *   Helper function to reset provider stub validation flags after test completion.
 *
 * Shared Variables: DSP_Prov_Stub, DSP_Prov_Stub_From_Master (static)
 *
 * Parameters: none
 *
 * Return Value: none
 *
 * Design Information:
 *  - Resets both provider stub flags to false
 *  - Called at the end of each receiver case statement
 *  - Ensures clean state for next test iteration
 *
 *  Change References:
 *  - Added to consolidate flag reset logic across receiver functions
 *
 ******************************************************************************/
static inline SRAM0_TEXT ATTR_UNUSED void Clear_Prov_Stub_Flags(void)
{
   DSP_Prov_Stub             = false;
   DSP_Prov_Stub_From_Master = false;
}

/******************************************************************************
 * Name:  Clear_Shared_Ptrs
 *   Helper function to clear/reset shared pointer structures.
 *
 * Shared Variables: DSP_Shared_Pi, DSP_Shared_Ri (volatile global)
 *
 * Parameters: none
 *
 * Return Value: none
 *
 * Design Information:
 *  - Resets all fields in provider and receiver shared pointer structures
 *  - Called when transitioning to new interface or on invalid interface
 *  - Prevents stale data from previous interface contaminating current test
 *  - Sets pointer to NULL, element count to 0, interface name to None
 *
 *  Change References:
 *  - Added to fix stale data issue when invalid interface follows valid one
 *
 ******************************************************************************/
static inline SRAM0_TEXT ATTR_UNUSED void Clear_Shared_Ptrs(void)
{
   /* Clear provider shared pointer structure */
   DSP_Shared_Pi.data.ptr       = NULL;
   DSP_Shared_Pi.elem_size      = 0U;
   DSP_Shared_Pi.no_of_elements = 0U;
   DSP_Shared_Pi.name           = Test_Interface_None;
   DSP_Shared_Pi.data_type      = DATATYPE_UINT8;

   /* Clear receiver shared pointer structure */
   DSP_Shared_Ri.data.ptr       = NULL;
   DSP_Shared_Ri.elem_size      = 0U;
   DSP_Shared_Ri.no_of_elements = 0U;
   DSP_Shared_Ri.name           = Test_Interface_None;
   DSP_Shared_Ri.data_type      = DATATYPE_UINT8;
}

/*===========================================================================*
 * Function Definitions
 *===========================================================================*/

/******************************************************************************
 * Name:  Is_Valid_Interface
 *   Validates interface number and initializes test result.
 *
 * Shared Variables: DSP_Res, last_interface_number (static)
 *
 * Parameters: interface_number - Interface number to validate
 *
 * Return Value: Test result status (TEST_PASSED, TEST_FAILED, TEST_INTERFACE_INVALID, TEST_NOT_PERFORMED)
 *
 * Design Information:
 *  - Uses DCS_X-macro expansion to validate against INTERFACE_ENUM_LIST
 *  - Initializes DSP_Res on new interface (TEST_PASSED)
 *  - Marks invalid interface with TEST_INTERFACE_INVALID result
 *  - Prevents re-initialization on duplicate interface calls
 *  - Returns result status for caller verification
 *
 *  Change References:
 *  - Initial implementation
 *
 ******************************************************************************/
static SRAM0_TEXT ATTR_UNUSED SIT_Test_Result_T Is_Valid_Interface(uint32_t interface_number)
{
   bool is_valid = false;

   /* Check if interface number is in valid list */
   switch (interface_number)
   {
   #define DCS_X(name, value) case value:
      INTERFACE_ENUM_LIST
   #undef DCS_X
      is_valid = true;
      break;
      default:
         is_valid = false;
         break;
   }

   /* Handle result initialization based on interface validity and state */
   if (!is_valid)
   {
      DSP_Res               = TEST_INTERFACE_INVALID;
      last_interface_number = interface_number;
      Clear_Shared_Ptrs();
   }
   else if (((last_interface_number != interface_number) || (last_stub_value != DSP_Stub_Val)) && (interface_number != 0U))
   {
      /* New interface OR new stub value - marks a new test, reset everything */
      last_interface_number     = interface_number;
      last_stub_value           = DSP_Stub_Val;
      DSP_Res                   = TEST_PASSED;
      DSP_Prov_Stub             = false; /* Reset provider stub flag for new test */
      DSP_Prov_Stub_From_Master = false; /* Reset master provider stub validation flag for new test */
      Clear_Shared_Ptrs();
   }
   else
   {
      /* Same interface and stub value - keep existing result and stub flags (sticky failure) */
   }

   return DSP_Res;
}

/*===========================================================================*
 * IPC Transfer Functions - Transfer test data between R52/Master and BBE32/DSP cores via IPC
 *===========================================================================*/

/******************************************************************************
 * Name:  SIT_IPC_Transfer_M2D_Receive
 *   Receive SIT test data from M2D IPC buffer.
 *
 * Shared Variables: DSP_Test_Iface_Num, DSP_Stub_Val, DSP_Stub_Len
 *
 * Parameters: m2d_payload_ptr - Pointer to M2D payload structure
 *
 * Return Value: none
 *
 * Design Information:
 *  - Called from ipc_dsp.c when M2D data is received
 *
 *  Change References:
 *  - Initial implementation
 *
 ******************************************************************************/
SRAM0_TEXT void SIT_IPC_Transfer_M2D_Receive(const M2D_Payload_T *m2d_payload_ptr)
{
   if (m2d_payload_ptr != NULL)
   {
      /* Receive test parameters from R52 via IPC */
      DSP_Test_Iface_Num        = m2d_payload_ptr->sit_data.test_interface_number;
      DSP_Stub_Val              = m2d_payload_ptr->sit_data.stub_value;
      DSP_Stub_Len              = m2d_payload_ptr->sit_data.no_of_elements_in_stub_array;
      DSP_Prov_Stub_From_Master = m2d_payload_ptr->sit_data.stub_success;
   }
}

/******************************************************************************
 * Name:  SIT_IPC_Transfer_D2M_Send
 *   Send SIT test data back to R52 via D2M IPC buffer.
 *
 * Shared Variables: DSP_Test_Iface_Num, DSP_Stub_Val, DSP_Stub_Len, DSP_Res
 *
 * Parameters: d2m_payload_ptr - Pointer to D2M payload structure
 *
 * Return Value: none
 *
 * Design Information:
 *  - Called from ipc_dsp.c before D2M header update
 *
 *  Change References:
 *  - Initial implementation
 *
 ******************************************************************************/
SRAM0_TEXT void SIT_IPC_Transfer_D2M_Send(D2M_Payload_T *d2m_payload_ptr)
{
   if (d2m_payload_ptr != NULL)
   {
      d2m_payload_ptr->sit_data.test_interface_number        = DSP_Test_Iface_Num;
      d2m_payload_ptr->sit_data.stub_value                   = DSP_Stub_Val;
      d2m_payload_ptr->sit_data.no_of_elements_in_stub_array = DSP_Stub_Len;
      d2m_payload_ptr->sit_data.test_result                  = DSP_Res;
      d2m_payload_ptr->sit_data.stub_success                 = DSP_Prov_Stub;
   }
}

/*===========================================================================*
 * Stub Functions
 *===========================================================================*/

/******************************************************************************
 * Name:  Stub_Scalar_Values
 *   Stub a scalar value based on data type.
 *
 * Shared Variables: none
 *
 * Parameters: dstb_ptr - Pointer to destination variable
 *             data_type - Data type enumeration
 *             stub_value - Value to write
 *
 * Return Value: none
 *
 * Design Information:
 *  - Type-safe stubbing based on data type enumeration
 *
 *  Change References:
 *  - Initial implementation
 *
 ******************************************************************************/
static SRAM0_TEXT ATTR_UNUSED void Stub_Scalar_Values(void *dstb_ptr, DataType_T data_type, double stub_value)
{
   switch (data_type)
   {
      case DATATYPE_UINT8:
         *(uint8_t *)dstb_ptr = (uint8_t)stub_value;
         break;
      case DATATYPE_UINT16:
         *(uint16_t *)dstb_ptr = (uint16_t)stub_value;
         break;
      case DATATYPE_UINT32:
         *(uint32_t *)dstb_ptr = (uint32_t)stub_value;
         break;
      case DATATYPE_INT16:
         *(int16_t *)dstb_ptr = (int16_t)stub_value;
         break;
      case DATATYPE_INT32:
         *(int32_t *)dstb_ptr = (int32_t)stub_value;
         break;
      case DATATYPE_FLOAT32:
         *(float *)dstb_ptr = (float)stub_value;
         break;
      case DATATYPE_ENUM:
         *(uint8_t *)dstb_ptr = (uint8_t)stub_value;
         break;
      default:
         break;
   }
}

/******************************************************************************
 * Name:  Stub_1D_Array_Values
 *   Stub a 1D array.
 *
 * Shared Variables: none
 *
 * Parameters: dstb_ptr - Pointer to destination array
 *             data_type - Data type enumeration
 *             stub_value - Value to write to all elements
 *             num_elements - Number of elements to stub
 *
 * Return Value: none
 *
 * Design Information:
 *  - Type-safe array stubbing based on data type enumeration
 *
 *  Change References:
 *  - Initial implementation
 *
 ******************************************************************************/
static SRAM0_TEXT ATTR_UNUSED void Stub_1D_Array_Values(void *dstb_ptr, DataType_T data_type, double stub_value,
                                                        uint32_t num_elements)
{
   uint32_t i;
   uint8_t *p_u8;
   uint16_t *p_u16;
   uint32_t *p_u32;
   int16_t *p_i16;
   int32_t *p_i32;
   float *p_f32;
   uint8_t *p_enum;

   switch (data_type)
   {
      case DATATYPE_UINT8:
         p_u8 = (uint8_t *)dstb_ptr;
         for (i = 0U; i < num_elements; i++)
         {
            p_u8[i] = (uint8_t)stub_value;
         }
         break;
      case DATATYPE_UINT16:
         p_u16 = (uint16_t *)dstb_ptr;
         for (i = 0U; i < num_elements; i++)
         {
            p_u16[i] = (uint16_t)stub_value;
         }
         break;
      case DATATYPE_UINT32:
         p_u32 = (uint32_t *)dstb_ptr;
         for (i = 0U; i < num_elements; i++)
         {
            p_u32[i] = (uint32_t)stub_value;
         }
         break;
      case DATATYPE_INT16:
         p_i16 = (int16_t *)dstb_ptr;
         for (i = 0U; i < num_elements; i++)
         {
            p_i16[i] = (int16_t)stub_value;
         }
         break;
      case DATATYPE_INT32:
         p_i32 = (int32_t *)dstb_ptr;
         for (i = 0U; i < num_elements; i++)
         {
            p_i32[i] = (int32_t)stub_value;
         }
         break;
      case DATATYPE_FLOAT32:
         p_f32 = (float *)dstb_ptr;
         for (i = 0U; i < num_elements; i++)
         {
            p_f32[i] = (float)stub_value;
         }
         break;
      case DATATYPE_ENUM:
         p_enum = (uint8_t *)dstb_ptr;
         for (i = 0U; i < num_elements; i++)
         {
            p_enum[i] = (uint8_t)stub_value;
         }
         break;
      default:
         break;
   }
}

/******************************************************************************
 * Name:  Stub_3D_Array_Values
 *   Stub a 3D array.
 *
 * Shared Variables: none
 *
 * Parameters: dstb_ptr - Pointer to destination array
 *             data_type - Data type enumeration
 *             stub_value - Value to write to all elements
 *             dim1 - First dimension size
 *             dim2 - Second dimension size
 *             dim3 - Third dimension size
 *
 * Return Value: none
 *
 * Design Information:
 *  - For simplicity, stubs only first dimension elements
 *
 *  Change References:
 *  - Initial implementation
 *
 ******************************************************************************/
static SRAM0_TEXT ATTR_UNUSED void Stub_3D_Array_Values(void *dstb_ptr, DataType_T data_type, double stub_value, uint32_t dim1,
                                                        uint32_t dim2, uint32_t dim3)
{
   (void)dim2;
   (void)dim3;
   Stub_1D_Array_Values(dstb_ptr, data_type, stub_value, dim1);
}

/*===========================================================================*
 * Validation Functions
 *===========================================================================*/

/******************************************************************************
 * Name:  Validate_Scalar_Values
 *   Validate a scalar value.
 *
 * Shared Variables: none
 *
 * Parameters: dvld_ptr - Pointer to source variable
 *             data_type - Data type enumeration
 *             expected_value - Expected value
 *
 * Return Value: true if value matches (within tolerance), false otherwise
 *
 * Design Information:
 *  - Uses SWE5_VALIDATION_TOLERANCE for floating point comparison
 *
 *  Change References:
 *  - Initial implementation
 *
 ******************************************************************************/
static SRAM0_TEXT ATTR_UNUSED bool Validate_Scalar_Values(const void *dvld_ptr, DataType_T data_type, double expected_value)
{
   bool is_valid       = false;
   double actual_value = 0.0;

   switch (data_type)
   {
      case DATATYPE_UINT8:
         actual_value = (double)(*(const uint8_t *)dvld_ptr);
         break;
      case DATATYPE_UINT16:
         actual_value = (double)(*(const uint16_t *)dvld_ptr);
         break;
      case DATATYPE_UINT32:
         actual_value = (double)(*(const uint32_t *)dvld_ptr);
         break;
      case DATATYPE_INT16:
         actual_value = (double)(*(const int16_t *)dvld_ptr);
         break;
      case DATATYPE_INT32:
         actual_value = (double)(*(const int32_t *)dvld_ptr);
         break;
      case DATATYPE_FLOAT32:
         actual_value = (double)(*(const float *)dvld_ptr);
         break;
      case DATATYPE_ENUM:
         actual_value = (double)(*(const uint8_t *)dvld_ptr);
         break;
      default:
         is_valid = false;
   }

   if (fabs(actual_value - expected_value) <= (SWE5_VALIDATION_TOLERANCE)*fabs(expected_value))
   {
      is_valid = true;
   }

   return is_valid;
}

/******************************************************************************
 * Name:  Validate_1D_Array_Values
 *   Validate a 1D array.
 *
 * Shared Variables: none
 *
 * Parameters: dvld_ptr - Pointer to source array
 *             data_type - Data type enumeration
 *             expected_value - Expected value for all elements
 *             num_elements - Number of elements to validate
 *
 * Return Value: true if any value matches (within tolerance), false otherwise
 *
 * Design Information:
 *  - Uses "any-match" logic: returns true if any element matches
 *
 *  Change References:
 *  - Initial implementation
 *
 ******************************************************************************/
static SRAM0_TEXT ATTR_UNUSED bool Validate_1D_Array_Values(const void *dvld_ptr, DataType_T data_type, double expected_value,
                                                            uint32_t num_elements)
{
   uint32_t i;
   const uint8_t *p_u8;
   const uint16_t *p_u16;
   const uint32_t *p_u32;
   const int16_t *p_i16;
   const int32_t *p_i32;
   const float *p_f32;
   const uint8_t *p_enum;
   double actual_value;
   bool found_match = false;

   switch (data_type)
   {
      case DATATYPE_UINT8:
         p_u8 = (const uint8_t *)dvld_ptr;
         for (i = 0U; i < num_elements; i++)
         {
            actual_value = (double)p_u8[i];
            if (fabs(actual_value - expected_value) <= (SWE5_VALIDATION_TOLERANCE)*fabs(expected_value))
            {
               found_match = true;
               break;
            }
         }
         break;
      case DATATYPE_UINT16:
         p_u16 = (const uint16_t *)dvld_ptr;
         for (i = 0U; i < num_elements; i++)
         {
            actual_value = (double)p_u16[i];
            if (fabs(actual_value - expected_value) <= (SWE5_VALIDATION_TOLERANCE)*fabs(expected_value))
            {
               found_match = true;
               break;
            }
         }
         break;
      case DATATYPE_UINT32:
         p_u32 = (const uint32_t *)dvld_ptr;
         for (i = 0U; i < num_elements; i++)
         {
            actual_value = (double)p_u32[i];
            if (fabs(actual_value - expected_value) <= (SWE5_VALIDATION_TOLERANCE)*fabs(expected_value))
            {
               found_match = true;
               break;
            }
         }
         break;
      case DATATYPE_INT16:
         p_i16 = (const int16_t *)dvld_ptr;
         for (i = 0U; i < num_elements; i++)
         {
            actual_value = (double)p_i16[i];
            if (fabs(actual_value - expected_value) <= (SWE5_VALIDATION_TOLERANCE)*fabs(expected_value))
            {
               found_match = true;
               break;
            }
         }
         break;
      case DATATYPE_INT32:
         p_i32 = (const int32_t *)dvld_ptr;
         for (i = 0U; i < num_elements; i++)
         {
            actual_value = (double)p_i32[i];
            if (fabs(actual_value - expected_value) <= (SWE5_VALIDATION_TOLERANCE)*fabs(expected_value))
            {
               found_match = true;
               break;
            }
         }
         break;
      case DATATYPE_FLOAT32:
         p_f32 = (const float *)dvld_ptr;
         for (i = 0U; i < num_elements; i++)
         {
            actual_value = (double)p_f32[i];
            if (fabs(actual_value - expected_value) <= (SWE5_VALIDATION_TOLERANCE)*fabs(expected_value))
            {
               found_match = true;
               break;
            }
         }
         break;
      case DATATYPE_ENUM:
         p_enum = (const uint8_t *)dvld_ptr;
         for (i = 0U; i < num_elements; i++)
         {
            actual_value = (double)p_enum[i];
            if (fabs(actual_value - expected_value) <= (SWE5_VALIDATION_TOLERANCE)*fabs(expected_value))
            {
               found_match = true;
               break;
            }
         }
         break;
      default:
         found_match = false;
   }

   return found_match;
}

/******************************************************************************
 * Name:  Validate_3D_Array_Values
 *   Validate a 3D array.
 *
 * Shared Variables: none
 *
 * Parameters: dvld_ptr - Pointer to source array
 *             data_type - Data type enumeration
 *             expected_value - Expected value for all elements
 *             dim1 - First dimension size
 *             dim2 - Second dimension size
 *             dim3 - Third dimension size
 *
 * Return Value: true if any value matches (within tolerance), false otherwise
 *
 * Design Information:
 *  - For simplicity, validates only first dimension elements
 *
 *  Change References:
 *  - Initial implementation
 *
 ******************************************************************************/
static SRAM0_TEXT_USED bool Validate_3D_Array_Values(const void *dvld_ptr, DataType_T data_type, double expected_value,
                                                     uint32_t dim1, uint32_t dim2, uint32_t dim3)
{
   (void)dim2;
   (void)dim3;
   return Validate_1D_Array_Values(dvld_ptr, data_type, expected_value, dim1);
}

   /*===========================================================================*
    * Module-Specific Stub and Validate Functions - Angle Finding
    *===========================================================================*/
   #if defined(Anglefinding_IT) || defined(Radar_capability_IT)

/******************************************************************************
 * Name:  SIT_D2M_Msg_Buffer_Provider
 *   Provider stub function - injects test values into RDD data.
 *
 * Shared Variables: DSP_Test_Iface_Num, DSP_Stub_Val, DSP_Stub_Len
 *
 * Parameters: d2m_msg_ptr - Pointer to D2M message buffer
 *
 * Return Value: none
 *
 * Design Information:
 *  - Call at end of Appl_Doppler_Rdd_Processing()
 *  - Stubs RDD data that will be consumed by Angle Finding module
 *
 *  Change References:
 *  - Initial implementation based on Gen7_V2 SWE5 framework
 *
 ******************************************************************************/
SRAM0_TEXT void SIT_D2M_Msg_Buffer_Provider(D2M_Msg_T *d2m_msg_ptr)
{
   RDD_Data_T *p_rdd;
   Look_Data_T *p_look;
   uint32_t num_elem;

   p_rdd    = &d2m_msg_ptr->payload.rdd_stream_data.rdd_data;
   p_look   = &d2m_msg_ptr->payload.rdd_stream_data.look_data;
   num_elem = DSP_Stub_Len;

   switch (DSP_Test_Iface_Num)
   {
      #if defined(Anglefinding_IT)
      case Ri_beam_vector: /* WI-379775: rdd1_bv[detect][TX][RX] */
      {
         bool stub_validation_result;
         if (num_elem > MAX_DETS_FIRST_PASS * NUM_TX_CHANNELS * NUM_RX_ANTENNAS)
         {
            num_elem = MAX_DETS_FIRST_PASS * NUM_TX_CHANNELS * NUM_RX_ANTENNAS;
         }
         Set_Shared_Ptr(&DSP_Shared_Pi, p_rdd->rdd1_bv, sizeof(uint16_t), num_elem, Ri_beam_vector, DATATYPE_UINT16);
         Stub_1D_Array_Values(p_rdd->rdd1_bv, DATATYPE_UINT16, DSP_Stub_Val, num_elem);
         stub_validation_result = Validate_1D_Array_Values(p_rdd->rdd1_bv, DATATYPE_UINT16, DSP_Stub_Val, num_elem);
         DSP_Prov_Stub          = stub_validation_result;
      }
      break;

      case Ri_rdd_snr: /* WI-362404: rdd2_snr[detect] */
      {
         bool stub_validation_result;
         if (num_elem > MAX_DETS_FIRST_PASS)
         {
            num_elem = MAX_DETS_FIRST_PASS;
         }
         Set_Shared_Ptr(&DSP_Shared_Pi, p_rdd->rdd2_snr, sizeof(s8p23_T), num_elem, Ri_rdd_snr, DATATYPE_INT32);
         Stub_1D_Array_Values(p_rdd->rdd2_snr, DATATYPE_INT32, DSP_Stub_Val, num_elem);
         stub_validation_result = Validate_1D_Array_Values(p_rdd->rdd2_snr, DATATYPE_INT32, DSP_Stub_Val, num_elem);
         DSP_Prov_Stub          = stub_validation_result;
      }
      break;

      case Ri_range_rate: /* WI-362403: rdd2_range_rate[detect] */
      {
         bool stub_validation_result;
         if (num_elem > MAX_DETS_FIRST_PASS)
         {
            num_elem = MAX_DETS_FIRST_PASS;
         }
         Set_Shared_Ptr(&DSP_Shared_Pi, p_rdd->rdd2_range_rate, sizeof(s10p21_T), num_elem, Ri_range_rate, DATATYPE_INT32);
         Stub_1D_Array_Values(p_rdd->rdd2_range_rate, DATATYPE_INT32, DSP_Stub_Val, num_elem);
         stub_validation_result = Validate_1D_Array_Values(p_rdd->rdd2_range_rate, DATATYPE_INT32, DSP_Stub_Val, num_elem);
         DSP_Prov_Stub          = stub_validation_result;
      }
      break;

      case Ri_range: /* WI-362402: rdd2_range[detect] */
      {
         bool stub_validation_result;
         if (num_elem > MAX_DETS_FIRST_PASS)
         {
            num_elem = MAX_DETS_FIRST_PASS;
         }
         Set_Shared_Ptr(&DSP_Shared_Pi, p_rdd->rdd2_range, sizeof(s10p21_T), num_elem, Ri_range, DATATYPE_INT32);
         Stub_1D_Array_Values(p_rdd->rdd2_range, DATATYPE_INT32, DSP_Stub_Val, num_elem);
         stub_validation_result = Validate_1D_Array_Values(p_rdd->rdd2_range, DATATYPE_INT32, DSP_Stub_Val, num_elem);
         DSP_Prov_Stub          = stub_validation_result;
      }
      break;

      case Ri_scan_index: /* WI-362399: scan_index (scalar pointer) */
      {
         bool stub_validation_result;
         Set_Shared_Ptr(&DSP_Shared_Pi, &p_look->scan_index, sizeof(uint16_t), 1, Ri_scan_index, DATATYPE_UINT16);
         Stub_Scalar_Values(&p_look->scan_index, DATATYPE_UINT16, DSP_Stub_Val);
         stub_validation_result = Validate_Scalar_Values(&p_look->scan_index, DATATYPE_UINT16, DSP_Stub_Val);
         DSP_Prov_Stub          = stub_validation_result;
      }
      break;

      case Ri_look_type: /* WI-362398: look_id (scalar pointer) */
      {
         bool stub_validation_result;
         Set_Shared_Ptr(&DSP_Shared_Pi, &p_look->look_id, sizeof(uint16_t), 1, Ri_look_type, DATATYPE_UINT16);
         Stub_Scalar_Values(&p_look->look_id, DATATYPE_UINT16, DSP_Stub_Val);
         stub_validation_result = Validate_Scalar_Values(&p_look->look_id, DATATYPE_UINT16, DSP_Stub_Val);
         DSP_Prov_Stub          = stub_validation_result;
      }
      break;

      case Ri_sp_fail_flag: /* WI-294068: rdd2_sp_fail_flag[detect] */
      {
         bool stub_validation_result;
         if (num_elem > MAX_DETS_FIRST_PASS)
         {
            num_elem = MAX_DETS_FIRST_PASS;
         }
         Set_Shared_Ptr(&DSP_Shared_Pi, p_rdd->rdd2_sp_fail_flag, sizeof(uint8_t), num_elem, Ri_sp_fail_flag, DATATYPE_UINT8);
         Stub_1D_Array_Values(p_rdd->rdd2_sp_fail_flag, DATATYPE_UINT8, DSP_Stub_Val, num_elem);
         stub_validation_result = Validate_1D_Array_Values(p_rdd->rdd2_sp_fail_flag, DATATYPE_UINT8, DSP_Stub_Val, num_elem);
         DSP_Prov_Stub          = stub_validation_result;
      }
      break;

      case Ri_sp_num_detections: /* WI-294066: rdd2_num_detect (scalar) */
      {
         bool stub_validation_result;
         Set_Shared_Ptr(&DSP_Shared_Pi, &p_rdd->rdd2_num_detect, sizeof(uint16_t), 1, Ri_sp_num_detections, DATATYPE_UINT16);
         Stub_Scalar_Values(&p_rdd->rdd2_num_detect, DATATYPE_UINT16, DSP_Stub_Val);
         stub_validation_result = Validate_Scalar_Values(&p_rdd->rdd2_num_detect, DATATYPE_UINT16, DSP_Stub_Val);
         DSP_Prov_Stub          = stub_validation_result;
      }
      break;

      case Ri_fp_num_detections: /* WI-294052: rdd1_num_detect (scalar) */
      {
         bool stub_validation_result;
         Set_Shared_Ptr(&DSP_Shared_Pi, &p_rdd->rdd1_num_detect, sizeof(uint16_t), 1, Ri_fp_num_detections, DATATYPE_UINT16);
         Stub_Scalar_Values(&p_rdd->rdd1_num_detect, DATATYPE_UINT16, DSP_Stub_Val);
         stub_validation_result = Validate_Scalar_Values(&p_rdd->rdd1_num_detect, DATATYPE_UINT16, DSP_Stub_Val);
         DSP_Prov_Stub          = stub_validation_result;
      }
      break;

      case Ri_range_doppler_amplitude: /* WI-294048: rdd1_rdop_amp[detect] */
      {
         bool stub_validation_result;
         if (num_elem > MAX_DETS_FIRST_PASS)
         {
            num_elem = MAX_DETS_FIRST_PASS;
         }
         Set_Shared_Ptr(&DSP_Shared_Pi, p_rdd->rdd1_rdop_amp, sizeof(uint16_t), num_elem, Ri_range_doppler_amplitude,
                        DATATYPE_UINT16);
         Stub_1D_Array_Values(p_rdd->rdd1_rdop_amp, DATATYPE_UINT16, DSP_Stub_Val, num_elem);
         stub_validation_result = Validate_1D_Array_Values(p_rdd->rdd1_rdop_amp, DATATYPE_UINT16, DSP_Stub_Val, num_elem);
         DSP_Prov_Stub          = stub_validation_result;
      }
      break;

      case Ri_CR_response: /* WI-294047: bwdep_cr_resp[rbin] */
      {
         bool stub_validation_result;
         if (num_elem > MAX_RANGE_BINS)
         {
            num_elem = MAX_RANGE_BINS;
         }
         Set_Shared_Ptr(&DSP_Shared_Pi, p_rdd->bwdep_cr_resp, sizeof(uint32_t), num_elem, Ri_CR_response, DATATYPE_UINT32);
         Stub_1D_Array_Values(p_rdd->bwdep_cr_resp, DATATYPE_UINT32, DSP_Stub_Val, num_elem);
         stub_validation_result = Validate_1D_Array_Values(p_rdd->bwdep_cr_resp, DATATYPE_UINT32, DSP_Stub_Val, num_elem);
         DSP_Prov_Stub          = stub_validation_result;
      }
      break;

      case Ri_range_bin_index: /* WI-294049: rdd1_rindx[detect] */
      {
         bool stub_validation_result;
         if (num_elem > MAX_DETS_FIRST_PASS)
         {
            num_elem = MAX_DETS_FIRST_PASS;
         }
         Set_Shared_Ptr(&DSP_Shared_Pi, p_rdd->rdd1_rindx, sizeof(uint16_t), num_elem, Ri_range_bin_index, DATATYPE_UINT16);
         Stub_1D_Array_Values(p_rdd->rdd1_rindx, DATATYPE_UINT16, DSP_Stub_Val, num_elem);
         stub_validation_result = Validate_1D_Array_Values(p_rdd->rdd1_rindx, DATATYPE_UINT16, DSP_Stub_Val, num_elem);
         DSP_Prov_Stub          = stub_validation_result;
      }
      break;

      case Ri_nci_bexp: /* WI-399434: nci_bexp[rbin] */
      {
         bool stub_validation_result;
         if (num_elem > MAX_RANGE_BINS)
         {
            num_elem = MAX_RANGE_BINS;
         }
         Set_Shared_Ptr(&DSP_Shared_Pi, p_rdd->nci_bexp, sizeof(uint16_t), num_elem, Ri_nci_bexp, DATATYPE_UINT16);
         Stub_1D_Array_Values(p_rdd->nci_bexp, DATATYPE_UINT16, DSP_Stub_Val, num_elem);
         stub_validation_result = Validate_1D_Array_Values(p_rdd->nci_bexp, DATATYPE_UINT16, DSP_Stub_Val, num_elem);
         DSP_Prov_Stub          = stub_validation_result;
      }
      break;

      case Ri_look_index: /* WI-399606: look_index (scalar pointer) */
      {
         bool stub_validation_result;
         Set_Shared_Ptr(&DSP_Shared_Pi, &p_look->look_index, sizeof(uint16_t), 1, Ri_look_index, DATATYPE_UINT16);
         Stub_Scalar_Values(&p_look->look_index, DATATYPE_UINT16, DSP_Stub_Val);
         stub_validation_result = Validate_Scalar_Values(&p_look->look_index, DATATYPE_UINT16, DSP_Stub_Val);
         DSP_Prov_Stub          = stub_validation_result;
      }
      break;

      #endif /* Anglefinding_IT */

      #if defined(Radar_capability_IT)
      case Ri_min_chirp_scaling: /* WI-370573 */
      {
         bool stub_validation_result;
         Set_Shared_Ptr(&DSP_Shared_Pi, &p_rdd->min_chirp_scaling, sizeof(uint8_t), 1, Ri_min_chirp_scaling, DATATYPE_UINT8);
         Stub_Scalar_Values(&p_rdd->min_chirp_scaling, DATATYPE_UINT8, DSP_Stub_Val);
         stub_validation_result = Validate_Scalar_Values(&p_rdd->min_chirp_scaling, DATATYPE_UINT8, DSP_Stub_Val);
         DSP_Prov_Stub          = stub_validation_result;
      }
      break;

      case Ri_cfar_nf_est: /* WI-370570 */
      {
         bool stub_validation_result;
         if (num_elem > MAX_RANGE_BINS)
         {
            num_elem = MAX_RANGE_BINS;
         }
         Set_Shared_Ptr(&DSP_Shared_Pi, p_rdd->cfar_nf_est, sizeof(uint16_t), num_elem, Ri_cfar_nf_est, DATATYPE_UINT16);
         Stub_1D_Array_Values(p_rdd->cfar_nf_est, DATATYPE_UINT16, DSP_Stub_Val, num_elem);
         stub_validation_result = Validate_1D_Array_Values(p_rdd->cfar_nf_est, DATATYPE_UINT16, DSP_Stub_Val, num_elem);
         DSP_Prov_Stub          = stub_validation_result;
      }
      break;

      case Ri_rdd_max_per_range_bin: /* WI-370568 */
      {
         bool stub_validation_result;
         if (num_elem > MAX_RANGE_BINS)
         {
            num_elem = MAX_RANGE_BINS;
         }
         Set_Shared_Ptr(&DSP_Shared_Pi, p_rdd->rdd1_max_per_range_bin, sizeof(uint16_t), num_elem, Ri_rdd_max_per_range_bin,
                        DATATYPE_UINT16);
         Stub_1D_Array_Values(p_rdd->rdd1_max_per_range_bin, DATATYPE_UINT16, DSP_Stub_Val, num_elem);
         stub_validation_result = Validate_1D_Array_Values(p_rdd->rdd1_max_per_range_bin, DATATYPE_UINT16, DSP_Stub_Val, num_elem);
         DSP_Prov_Stub          = stub_validation_result;
      }
      break;

      #endif /* Radar_capability_IT */

      #if defined(Anglefinding_IT)
      case Ri_range_coverage: /* WI-379779: range_coverage (currently not in Gen8 Look_Data_T - skip) */
         /* Note: Gen8 Look_Data_T may not have range_coverage - check and add if needed */
         break;

      case Ri_doppler_coverage: /* WI-379778: doppler_coverage (currently not in Gen8 Look_Data_T - skip) */
         /* Note: Gen8 Look_Data_T may not have doppler_coverage - check and add if needed */
         break;

      #endif /* Anglefinding_IT */

      default:
         /* Invalid interface number - do nothing */
         break;
   }
} /* end SIT_D2M_Msg_Buffer_Provider */
   #endif /*End of Anglefinding_IT and Radar_capability_IT */
   #if defined(Anglefinding_IT)
/******************************************************************************
 * Name:  SIT_Dwell_Timestamps_Provider
 *   Provider function to inject test values into dwell timestamp data.
 *
 * Shared Variables: DSP_Test_Iface_Num, DSP_Stub_Val
 *
 * Parameters: d2m_msg_ptr - Pointer to D2M message structure
 *
 * Return Value: none
 *
 * Design Information:
 *  - Called from Doppler_Handler after dwell timestamp calculation
 *  - Stubs timestamp/dwell fields in Look_Data_T for validation
 *  - Separated from main D2M provider for clarity
 *
 *  Change References:
 *  - Initial implementation
 *
 ******************************************************************************/
SRAM0_TEXT void SIT_Dwell_Timestamps_Provider(D2M_Msg_T *d2m_msg_ptr)
{
   Look_Data_T *p_look;

   p_look = &d2m_msg_ptr->payload.rdd_stream_data.look_data;

   switch (DSP_Test_Iface_Num)
   {
      case Ri_ts_start_dwell_nanosec: /* WI-385403: start_dwell_nanosec */
      {
         bool stub_validation_result;
         Set_Shared_Ptr(&DSP_Shared_Pi, &p_look->start_dwell_nanosec, sizeof(uint32_t), 1, Ri_ts_start_dwell_nanosec,
                        DATATYPE_UINT32);
         Stub_Scalar_Values(&p_look->start_dwell_nanosec, DATATYPE_UINT32, DSP_Stub_Val);
         stub_validation_result = Validate_Scalar_Values(&p_look->start_dwell_nanosec, DATATYPE_UINT32, DSP_Stub_Val);
         DSP_Prov_Stub          = stub_validation_result;
      }
      break;

      case Ri_ts_start_dwell_sec: /* WI-385404: start_dwell_sec */
      {
         bool stub_validation_result;
         Set_Shared_Ptr(&DSP_Shared_Pi, &p_look->start_dwell_sec, sizeof(uint32_t), 1, Ri_ts_start_dwell_sec, DATATYPE_UINT32);
         Stub_Scalar_Values(&p_look->start_dwell_sec, DATATYPE_UINT32, DSP_Stub_Val);
         stub_validation_result = Validate_Scalar_Values(&p_look->start_dwell_sec, DATATYPE_UINT32, DSP_Stub_Val);
         DSP_Prov_Stub          = stub_validation_result;
      }
      break;

      case Ri_ts_start_dwell_status: /* WI-385397: start_dwell_status */
      {
         bool stub_validation_result;
         Set_Shared_Ptr(&DSP_Shared_Pi, &p_look->start_dwell_status, sizeof(uint8_t), 1, Ri_ts_start_dwell_status, DATATYPE_UINT8);
         Stub_Scalar_Values(&p_look->start_dwell_status, DATATYPE_UINT8, DSP_Stub_Val);
         stub_validation_result = Validate_Scalar_Values(&p_look->start_dwell_status, DATATYPE_UINT8, DSP_Stub_Val);
         DSP_Prov_Stub          = stub_validation_result;
      }
      break;

      case Ri_ts_end_dwell_nanosec: /* WI-385408: end_dwell_nanosec */
      {
         bool stub_validation_result;
         Set_Shared_Ptr(&DSP_Shared_Pi, &p_look->end_dwell_nanosec, sizeof(uint32_t), 1, Ri_ts_end_dwell_nanosec, DATATYPE_UINT32);
         Stub_Scalar_Values(&p_look->end_dwell_nanosec, DATATYPE_UINT32, DSP_Stub_Val);
         stub_validation_result = Validate_Scalar_Values(&p_look->end_dwell_nanosec, DATATYPE_UINT32, DSP_Stub_Val);
         DSP_Prov_Stub          = stub_validation_result;
      }
      break;

      case Ri_ts_end_dwell_sec: /* WI-385406: end_dwell_sec */
      {
         bool stub_validation_result;
         Set_Shared_Ptr(&DSP_Shared_Pi, &p_look->end_dwell_sec, sizeof(uint32_t), 1, Ri_ts_end_dwell_sec, DATATYPE_UINT32);
         Stub_Scalar_Values(&p_look->end_dwell_sec, DATATYPE_UINT32, DSP_Stub_Val);
         stub_validation_result = Validate_Scalar_Values(&p_look->end_dwell_sec, DATATYPE_UINT32, DSP_Stub_Val);
         DSP_Prov_Stub          = stub_validation_result;
      }
      break;

      case Ri_ts_end_dwell_status: /* WI-385405: end_dwell_status */
      {
         bool stub_validation_result;
         Set_Shared_Ptr(&DSP_Shared_Pi, &p_look->end_dwell_status, sizeof(uint8_t), 1, Ri_ts_end_dwell_status, DATATYPE_UINT8);
         Stub_Scalar_Values(&p_look->end_dwell_status, DATATYPE_UINT8, DSP_Stub_Val);
         stub_validation_result = Validate_Scalar_Values(&p_look->end_dwell_status, DATATYPE_UINT8, DSP_Stub_Val);
         DSP_Prov_Stub          = stub_validation_result;
      }
      break;

      case Ri_ts_mid_dwell_nanosec: /* WI-385409: mid_dwell_nanosec */
      {
         bool stub_validation_result;
         Set_Shared_Ptr(&DSP_Shared_Pi, &p_look->mid_dwell_nanosec, sizeof(uint32_t), 1, Ri_ts_mid_dwell_nanosec, DATATYPE_UINT32);
         Stub_Scalar_Values(&p_look->mid_dwell_nanosec, DATATYPE_UINT32, DSP_Stub_Val);
         stub_validation_result = Validate_Scalar_Values(&p_look->mid_dwell_nanosec, DATATYPE_UINT32, DSP_Stub_Val);
         DSP_Prov_Stub          = stub_validation_result;
      }
      break;

      case Ri_ts_mid_dwell_sec: /* WI-385410: mid_dwell_sec */
      {
         bool stub_validation_result;
         Set_Shared_Ptr(&DSP_Shared_Pi, &p_look->mid_dwell_sec, sizeof(uint32_t), 1, Ri_ts_mid_dwell_sec, DATATYPE_UINT32);
         Stub_Scalar_Values(&p_look->mid_dwell_sec, DATATYPE_UINT32, DSP_Stub_Val);
         stub_validation_result = Validate_Scalar_Values(&p_look->mid_dwell_sec, DATATYPE_UINT32, DSP_Stub_Val);
         DSP_Prov_Stub          = stub_validation_result;
      }
      break;

      case Ri_ts_mid_dwell_status: /* WI-385407: mid_dwell_status */
      {
         bool stub_validation_result;
         Set_Shared_Ptr(&DSP_Shared_Pi, &p_look->mid_dwell_status, sizeof(uint8_t), 1, Ri_ts_mid_dwell_status, DATATYPE_UINT8);
         Stub_Scalar_Values(&p_look->mid_dwell_status, DATATYPE_UINT8, DSP_Stub_Val);
         stub_validation_result = Validate_Scalar_Values(&p_look->mid_dwell_status, DATATYPE_UINT8, DSP_Stub_Val);
         DSP_Prov_Stub          = stub_validation_result;
      }
      break;

      default:
         /* Invalid interface number - do nothing */
         break;
   }
} /* end SIT_Dwell_Timestamps_Provider */

/******************************************************************************
 * Name:  SIT_AF_Input_Receiver
 *   Receiver function for Anglefinding input data validation.
 *
 * Shared Variables: DSP_Test_Iface_Num, DSP_Stub_Val, DSP_Res
 *
 * Parameters: af_input_ptr - Pointer to Anglefinding input structure
 *             appl_out_ptr - Pointer to AF_Appl_Output_T structure
 *
 * Return Value: none
 *
 * Design Information:
 *  - Called after Anglefinding input copy in anglefinding_project_interface.c
 *  - Validates that stubbed values from R52 provider were correctly received
 *
 *  Change References:
 *  - Initial implementation
 *
 ******************************************************************************/
SRAM0_TEXT void SIT_AF_Input_Receiver(const Angle_Finding_Input_T *af_input_ptr, const AF_Appl_Output_T *appl_out_ptr)
{
   bool validation_result = false;
   uint32_t num_elem      = DSP_Stub_Len;

   /* Validate interface number and initialize result */
   DSP_Res = Is_Valid_Interface(DSP_Test_Iface_Num);

   switch (DSP_Test_Iface_Num)
   {
      case Ri_beam_vector: /* WI-379775: rdd1_bv[detect][TX][RX] */
      {
         CHECK_PROVIDER_STUB(DSP_Prov_Stub);
         if (num_elem > (MAX_DETS_FIRST_PASS * NUM_TX_CHANNELS * NUM_RX_ANTENNAS))
         {
            num_elem = MAX_DETS_FIRST_PASS * NUM_TX_CHANNELS * NUM_RX_ANTENNAS;
         }
         Set_Shared_Ptr(&DSP_Shared_Ri, af_input_ptr->p_rdd1_bv, sizeof(uint16_t), num_elem, Ri_beam_vector, DATATYPE_UINT16);
         validation_result = Validate_1D_Array_Values(af_input_ptr->p_rdd1_bv, DATATYPE_UINT16, DSP_Stub_Val, num_elem);
         DSP_Res = ((DSP_Res == TEST_PASSED || DSP_Res == TEST_STUB_INVALID) && validation_result) ? TEST_PASSED : TEST_FAILED;
         Clear_Prov_Stub_Flags();
      }
      break;

      case Ri_rdd_snr: /* WI-362404: rdd2_snr[detect] */
      {
         CHECK_PROVIDER_STUB(DSP_Prov_Stub);
         if (num_elem > MAX_DETS_FIRST_PASS)
         {
            num_elem = MAX_DETS_FIRST_PASS;
         }
         Set_Shared_Ptr(&DSP_Shared_Ri, af_input_ptr->p_rdd2_snr, sizeof(s8p23_T), num_elem, Ri_rdd_snr, DATATYPE_INT32);
         validation_result = Validate_1D_Array_Values(af_input_ptr->p_rdd2_snr, DATATYPE_INT32, DSP_Stub_Val, num_elem);
         DSP_Res = ((DSP_Res == TEST_PASSED || DSP_Res == TEST_STUB_INVALID) && validation_result) ? TEST_PASSED : TEST_FAILED;
         Clear_Prov_Stub_Flags();
      }
      break;

      case Ri_range_rate: /* WI-362403: rdd2_range_rate[detect] */
      {
         CHECK_PROVIDER_STUB(DSP_Prov_Stub);
         if (num_elem > MAX_DETS_FIRST_PASS)
         {
            num_elem = MAX_DETS_FIRST_PASS;
         }
         Set_Shared_Ptr(&DSP_Shared_Ri, af_input_ptr->p_rdd2_range_rate, sizeof(s10p21_T), num_elem, Ri_range_rate,
                        DATATYPE_INT32);
         validation_result = Validate_1D_Array_Values(af_input_ptr->p_rdd2_range_rate, DATATYPE_INT32, DSP_Stub_Val, num_elem);
         DSP_Res = ((DSP_Res == TEST_PASSED || DSP_Res == TEST_STUB_INVALID) && validation_result) ? TEST_PASSED : TEST_FAILED;
         Clear_Prov_Stub_Flags();
      }
      break;

      case Ri_range: /* WI-362402: rdd2_range[detect] */
      {
         CHECK_PROVIDER_STUB(DSP_Prov_Stub);
         if (num_elem > MAX_DETS_FIRST_PASS)
         {
            num_elem = MAX_DETS_FIRST_PASS;
         }
         Set_Shared_Ptr(&DSP_Shared_Ri, af_input_ptr->p_rdd2_range, sizeof(s10p21_T), num_elem, Ri_range, DATATYPE_INT32);
         validation_result = Validate_1D_Array_Values(af_input_ptr->p_rdd2_range, DATATYPE_INT32, DSP_Stub_Val, num_elem);
         DSP_Res = ((DSP_Res == TEST_PASSED || DSP_Res == TEST_STUB_INVALID) && validation_result) ? TEST_PASSED : TEST_FAILED;
         Clear_Prov_Stub_Flags();
      }
      break;

      case Ri_look_type: /* WI-362398: look_id */
      {
         CHECK_PROVIDER_STUB(DSP_Prov_Stub);
         Set_Shared_Ptr(&DSP_Shared_Ri, af_input_ptr->p_look_id, sizeof(uint16_t), 1, Ri_look_type, DATATYPE_UINT16);
         validation_result = Validate_Scalar_Values(af_input_ptr->p_look_id, DATATYPE_UINT16, DSP_Stub_Val);
         DSP_Res = ((DSP_Res == TEST_PASSED || DSP_Res == TEST_STUB_INVALID) && validation_result) ? TEST_PASSED : TEST_FAILED;
         Clear_Prov_Stub_Flags();
      }
      break;

      case Ri_sp_fail_flag: /* WI-294068: rdd2_sp_fail_flag[detect] */
      {
         CHECK_PROVIDER_STUB(DSP_Prov_Stub);
         if (num_elem > MAX_DETS_FIRST_PASS)
         {
            num_elem = MAX_DETS_FIRST_PASS;
         }
         Set_Shared_Ptr(&DSP_Shared_Ri, af_input_ptr->p_rdd2_sp_fail_flag, sizeof(uint8_t), num_elem, Ri_sp_fail_flag,
                        DATATYPE_UINT8);
         validation_result = Validate_1D_Array_Values(af_input_ptr->p_rdd2_sp_fail_flag, DATATYPE_UINT8, DSP_Stub_Val, num_elem);
         DSP_Res = ((DSP_Res == TEST_PASSED || DSP_Res == TEST_STUB_INVALID) && validation_result) ? TEST_PASSED : TEST_FAILED;
         Clear_Prov_Stub_Flags();
      }
      break;

      case Ri_sp_num_detections: /* WI-294066: rdd2_num_detect (scalar) */
      {
         CHECK_PROVIDER_STUB(DSP_Prov_Stub);
         Set_Shared_Ptr(&DSP_Shared_Ri, af_input_ptr->p_rdd2_num_detect, sizeof(uint16_t), 1, Ri_sp_num_detections,
                        DATATYPE_UINT16);
         validation_result = Validate_Scalar_Values(af_input_ptr->p_rdd2_num_detect, DATATYPE_UINT16, DSP_Stub_Val);
         DSP_Res = ((DSP_Res == TEST_PASSED || DSP_Res == TEST_STUB_INVALID) && validation_result) ? TEST_PASSED : TEST_FAILED;
         Clear_Prov_Stub_Flags();
      }
      break;

      case Ri_fp_num_detections: /* WI-294052: rdd1_num_detect (scalar) */
      {
         CHECK_PROVIDER_STUB(DSP_Prov_Stub);
         Set_Shared_Ptr(&DSP_Shared_Ri, af_input_ptr->p_rdd1_num_detect, sizeof(uint16_t), 1, Ri_fp_num_detections,
                        DATATYPE_UINT16);
         validation_result = Validate_Scalar_Values(af_input_ptr->p_rdd1_num_detect, DATATYPE_UINT16, DSP_Stub_Val);
         DSP_Res = ((DSP_Res == TEST_PASSED || DSP_Res == TEST_STUB_INVALID) && validation_result) ? TEST_PASSED : TEST_FAILED;
         Clear_Prov_Stub_Flags();
      }
      break;

      case Ri_range_doppler_amplitude: /* WI-294048: rdd1_rdop_amp[detect] */
      {
         CHECK_PROVIDER_STUB(DSP_Prov_Stub);
         if (num_elem > MAX_DETS_FIRST_PASS)
         {
            num_elem = MAX_DETS_FIRST_PASS;
         }
         Set_Shared_Ptr(&DSP_Shared_Ri, af_input_ptr->p_rdd1_rdop_amp, sizeof(uint16_t), num_elem, Ri_range_doppler_amplitude,
                        DATATYPE_UINT16);
         validation_result = Validate_1D_Array_Values(af_input_ptr->p_rdd1_rdop_amp, DATATYPE_UINT16, DSP_Stub_Val, num_elem);
         DSP_Res = ((DSP_Res == TEST_PASSED || DSP_Res == TEST_STUB_INVALID) && validation_result) ? TEST_PASSED : TEST_FAILED;
         Clear_Prov_Stub_Flags();
      }
      break;

      case Ri_CR_response: /* WI-294047: bwdep_cr_resp[rbin] */
      {
         CHECK_PROVIDER_STUB(DSP_Prov_Stub);
         if (num_elem > MAX_RANGE_BINS)
         {
            num_elem = MAX_RANGE_BINS;
         }
         Set_Shared_Ptr(&DSP_Shared_Ri, af_input_ptr->p_bwdep_cr_resp, sizeof(uint32_t), num_elem, Ri_CR_response,
                        DATATYPE_UINT32);
         validation_result = Validate_1D_Array_Values(af_input_ptr->p_bwdep_cr_resp, DATATYPE_UINT32, DSP_Stub_Val, num_elem);
         DSP_Res = ((DSP_Res == TEST_PASSED || DSP_Res == TEST_STUB_INVALID) && validation_result) ? TEST_PASSED : TEST_FAILED;
         Clear_Prov_Stub_Flags();
      }
      break;

      case Ri_range_bin_index: /* WI-294049: rdd1_rindx[detect] */
      {
         CHECK_PROVIDER_STUB(DSP_Prov_Stub);
         if (num_elem > MAX_DETS_FIRST_PASS)
         {
            num_elem = MAX_DETS_FIRST_PASS;
         }
         Set_Shared_Ptr(&DSP_Shared_Ri, af_input_ptr->p_rdd1_rindx, sizeof(uint16_t), num_elem, Ri_range_bin_index,
                        DATATYPE_UINT16);
         validation_result = Validate_1D_Array_Values(af_input_ptr->p_rdd1_rindx, DATATYPE_UINT16, DSP_Stub_Val, num_elem);
         DSP_Res = ((DSP_Res == TEST_PASSED || DSP_Res == TEST_STUB_INVALID) && validation_result) ? TEST_PASSED : TEST_FAILED;
         Clear_Prov_Stub_Flags();
      }
      break;

      case Ri_nci_bexp: /* WI-399434: nci_bexp[rbin] */
      {
         CHECK_PROVIDER_STUB(DSP_Prov_Stub);
         if (num_elem > MAX_RANGE_BINS)
         {
            num_elem = MAX_RANGE_BINS;
         }
         Set_Shared_Ptr(&DSP_Shared_Ri, af_input_ptr->p_nci_bexp, sizeof(uint16_t), num_elem, Ri_nci_bexp, DATATYPE_UINT16);
         validation_result = Validate_1D_Array_Values(af_input_ptr->p_nci_bexp, DATATYPE_UINT16, DSP_Stub_Val, num_elem);
         DSP_Res = ((DSP_Res == TEST_PASSED || DSP_Res == TEST_STUB_INVALID) && validation_result) ? TEST_PASSED : TEST_FAILED;
         Clear_Prov_Stub_Flags();
      }
      break;

      case Ri_look_index: /* WI-399606: look_index */
      {
         CHECK_PROVIDER_STUB(DSP_Prov_Stub);
         Set_Shared_Ptr(&DSP_Shared_Ri, &appl_out_ptr->appl_detection_stream_data_ptr->det_list_property.lookindex,
                        sizeof(uint16_t), 1, Ri_look_index, DATATYPE_UINT16);
         validation_result = Validate_Scalar_Values(&appl_out_ptr->appl_detection_stream_data_ptr->det_list_property.lookindex,
                                                    DATATYPE_UINT16, DSP_Stub_Val);
         DSP_Res = ((DSP_Res == TEST_PASSED || DSP_Res == TEST_STUB_INVALID) && validation_result) ? TEST_PASSED : TEST_FAILED;
         Clear_Prov_Stub_Flags();
      }
      break;

      case Ri_scan_index: /* WI-362399: scan_index */
      {
         CHECK_PROVIDER_STUB(DSP_Prov_Stub);
         Set_Shared_Ptr(&DSP_Shared_Ri, &appl_out_ptr->appl_detection_stream_data_ptr->stream_hdr.scan_index, sizeof(uint16_t), 1,
                        Ri_scan_index, DATATYPE_UINT16);
         validation_result = Validate_Scalar_Values(&appl_out_ptr->appl_detection_stream_data_ptr->stream_hdr.scan_index,
                                                    DATATYPE_UINT16, DSP_Stub_Val);
         DSP_Res = ((DSP_Res == TEST_PASSED || DSP_Res == TEST_STUB_INVALID) && validation_result) ? TEST_PASSED : TEST_FAILED;
         Clear_Prov_Stub_Flags();
      }
      break;

      case Ri_range_coverage: /* WI-379779: range_coverage - Not in Gen8 Look_Data_T / AF Input */
         /* Note: Gen8 Look_Data_T does not have range_coverage field */
         DSP_Res = TEST_SKIPPED;
         Clear_Prov_Stub_Flags();
         break;

      case Ri_doppler_coverage: /* WI-379778: doppler_coverage - Not in Gen8 Look_Data_T / AF Input */
         /* Note: Gen8 Look_Data_T does not have doppler_coverage field */
         DSP_Res = TEST_SKIPPED;
         Clear_Prov_Stub_Flags();
         break;

      case Ri_host_vehicle_speed: /* WI-362349: veh_speed */
      {
         CHECK_PROVIDER_STUB(DSP_Prov_Stub_From_Master);
         Set_Shared_Ptr(&DSP_Shared_Ri, af_input_ptr->p_veh_speed, sizeof(float), 1, Ri_host_vehicle_speed, DATATYPE_FLOAT32);
         validation_result = Validate_Scalar_Values(af_input_ptr->p_veh_speed, DATATYPE_FLOAT32, DSP_Stub_Val);
         DSP_Res = ((DSP_Res == TEST_PASSED || DSP_Res == TEST_STUB_INVALID) && validation_result) ? TEST_PASSED : TEST_FAILED;
         Clear_Prov_Stub_Flags();
      }
      break;

      case Ri_radar_position: /* WI-362359: radar_position */
      {
         CHECK_PROVIDER_STUB(DSP_Prov_Stub_From_Master);
         Set_Shared_Ptr(&DSP_Shared_Ri, af_input_ptr->p_radar_position, sizeof(uint8_t), 1, Ri_radar_position, DATATYPE_UINT8);
         validation_result = Validate_Scalar_Values(af_input_ptr->p_radar_position, DATATYPE_UINT8, DSP_Stub_Val);
         DSP_Res = ((DSP_Res == TEST_PASSED || DSP_Res == TEST_STUB_INVALID) && validation_result) ? TEST_PASSED : TEST_FAILED;
         Clear_Prov_Stub_Flags();
      }
      break;

      /* Timestamp/Dwell Interfaces - Validated from Detection Stream */
      case Ri_ts_mid_dwell_nanosec: /* WI-385409: mid_dwell_nanosec */
      {
         CHECK_PROVIDER_STUB(DSP_Prov_Stub);
         Set_Shared_Ptr(&DSP_Shared_Ri, &appl_out_ptr->appl_detection_stream_data_ptr->det_list_property.detection_timestamp_ns,
                        sizeof(uint32_t), 1, Ri_ts_mid_dwell_nanosec, DATATYPE_UINT32);
         validation_result =
            Validate_Scalar_Values(&appl_out_ptr->appl_detection_stream_data_ptr->det_list_property.detection_timestamp_ns,
                                   DATATYPE_UINT32, DSP_Stub_Val);
         DSP_Res = ((DSP_Res == TEST_PASSED || DSP_Res == TEST_STUB_INVALID) && validation_result) ? TEST_PASSED : TEST_FAILED;
         Clear_Prov_Stub_Flags();
      }
      break;

      case Ri_ts_mid_dwell_sec: /* WI-385410: mid_dwell_sec */
      {
         CHECK_PROVIDER_STUB(DSP_Prov_Stub);
         Set_Shared_Ptr(&DSP_Shared_Ri, &appl_out_ptr->appl_detection_stream_data_ptr->det_list_property.detection_timestamp_sec,
                        sizeof(uint32_t), 1, Ri_ts_mid_dwell_sec, DATATYPE_UINT32);
         validation_result =
            Validate_Scalar_Values(&appl_out_ptr->appl_detection_stream_data_ptr->det_list_property.detection_timestamp_sec,
                                   DATATYPE_UINT32, DSP_Stub_Val);
         DSP_Res = ((DSP_Res == TEST_PASSED || DSP_Res == TEST_STUB_INVALID) && validation_result) ? TEST_PASSED : TEST_FAILED;
         Clear_Prov_Stub_Flags();
      }
      break;

      case Ri_ts_mid_dwell_status: /* WI-385407: mid_dwell_status */
      {
         CHECK_PROVIDER_STUB(DSP_Prov_Stub);
         Set_Shared_Ptr(&DSP_Shared_Ri, &appl_out_ptr->appl_detection_stream_data_ptr->det_list_property.timestamp_status,
                        sizeof(uint8_t), 1, Ri_ts_mid_dwell_status, DATATYPE_UINT8);
         validation_result = Validate_Scalar_Values(
            &appl_out_ptr->appl_detection_stream_data_ptr->det_list_property.timestamp_status, DATATYPE_UINT8, DSP_Stub_Val);
         DSP_Res = ((DSP_Res == TEST_PASSED || DSP_Res == TEST_STUB_INVALID) && validation_result) ? TEST_PASSED : TEST_FAILED;
         Clear_Prov_Stub_Flags();
      }
      break;

      case Ri_ts_start_dwell_nanosec: /* WI-385403: start_dwell_nanosec */
      case Ri_ts_start_dwell_sec:     /* WI-385404: start_dwell_sec */
      case Ri_ts_start_dwell_status:  /* WI-385397: start_dwell_status */
      case Ri_ts_end_dwell_nanosec:   /* WI-385408: end_dwell_nanosec */
      case Ri_ts_end_dwell_sec:       /* WI-385406: end_dwell_sec */
      case Ri_ts_end_dwell_status:    /* WI-385405: end_dwell_status */
         /* Note: These timestamp fields are not currently mapped to AF Input structure in Gen8.
          * They exist in Look_Data_T (D2M buffer) and Detection_Stream_T output,
          * but are not exposed as separate pointers in Angle_Finding_Input_T.
          * Validation occurs through D2M provider stubbing only.
          * Test Result: TEST_SKIPPED (interface valid but not accessible in AF Input) */
         DSP_Res = TEST_SKIPPED;
         Clear_Prov_Stub_Flags();
         break;

      default:
         return;
   }
}

   /******************************************************************************
    * Name:  SIT_AF_USC_Receiver
    *   USC calibration validation function for Angle Finding module.
    *
    * Shared Variables: DSP_Test_Iface_Num, DSP_Stub_Val, DSP_Stub_Len, DSP_Res
    *
    * Parameters: af_usc_ptr - Pointer to AF_USC_T calibration structure
    *
    * Return Value: none
    *
    * Design Information:
    *  - Validates USC calibration parameters for Angle Finding
    *  - Checks lookup tables, calibration matrices, and angle ranges
    *  - Updates DSP_Res with validation result
    *
    *  Change References:
    *  - Initial implementation based on Gen7_V2 SWE5 framework
    *
    ******************************************************************************/

      #if 0  /* Disabled - AF_USC_T_Temp not yet available in Gen8 once available will uncomment this function */
SRAM0_TEXT void SIT_AF_USC_Receiver(void *af_usc_void_ptr)
{
   bool validation_result    = false;
   uint32_t num_elem         = DSP_Stub_Len;
   AF_USC_T_Temp *af_usc_ptr = (AF_USC_T_Temp *)af_usc_void_ptr;

   /* Validate interface number and initialize result */
   DSP_Res = Is_Valid_Interface(DSP_Test_Iface_Num);

   switch (DSP_Test_Iface_Num)
   {
      case Ri_usc_af_tx_cal_matrix: /* WI-294040001: usc_af_tx_cal_matrix */
         /* AF_USC_T.p_tx_cal_matrix[0] <- USC_Cal_T.k_calmat1_ctx[4][8] as creal32_T* = 16 complex */
         {
            uint32_t max_elem = 16U; /* 4x8 / 2 = 16 complex values */
            if (num_elem > max_elem)
            {
               num_elem = max_elem;
            }
            Set_Shared_Ptr(&DSP_Shared_Ri, af_usc_ptr->p_tx_cal_matrix[0], sizeof(creal32_T), num_elem,
                           Ri_usc_af_tx_cal_matrix, DATATYPE_FLOAT32);
            validation_result = Validate_1D_Array_Values(af_usc_ptr->p_tx_cal_matrix[0], DATATYPE_FLOAT32,
                                                         DSP_Stub_Val, num_elem);
            DSP_Res = ((DSP_Res == TEST_PASSED || DSP_Res == TEST_STUB_INVALID) && validation_result)
                         ? TEST_PASSED : TEST_FAILED;
         }
         break;

      case Ri_usc_af_rx_cal_matrix: /* WI-294040002: usc_af_rx_cal_matrix */
         /* AF_USC_T.p_rx_cal_matrix[0] <- USC_Cal_T.k_calmat1_crx[8][16] as creal32_T* = 64 complex */
         {
            uint32_t max_elem = 64U; /* 8x16 / 2 = 64 complex values */
            if (num_elem > max_elem)
            {
               num_elem = max_elem;
            }
            Set_Shared_Ptr(&DSP_Shared_Ri, af_usc_ptr->p_rx_cal_matrix[0], sizeof(creal32_T), num_elem,
                           Ri_usc_af_rx_cal_matrix, DATATYPE_FLOAT32);
            validation_result = Validate_1D_Array_Values(af_usc_ptr->p_rx_cal_matrix[0], DATATYPE_FLOAT32,
                                                         DSP_Stub_Val, num_elem);
            DSP_Res = ((DSP_Res == TEST_PASSED || DSP_Res == TEST_STUB_INVALID) && validation_result)
                         ? TEST_PASSED : TEST_FAILED;
         }
         break;

      case Ri_usc_af_cal_matrix: /* WI-294040003: usc_af_cal_matrix */
         /* AF_USC_T.p_cal_matrix[0] <- USC_Cal_T.k_calmat1_c1[32][64] as creal32_T* = 1024 complex */
         {
            uint32_t max_elem = 1024U; /* 32x64 / 2 = 1024 complex values */
            if (num_elem > max_elem)
            {
               num_elem = max_elem;
            }
            Set_Shared_Ptr(&DSP_Shared_Ri, af_usc_ptr->p_cal_matrix[0], sizeof(creal32_T), num_elem,
                           Ri_usc_af_cal_matrix, DATATYPE_FLOAT32);
            validation_result = Validate_1D_Array_Values(af_usc_ptr->p_cal_matrix[0], DATATYPE_FLOAT32,
                                                         DSP_Stub_Val, num_elem);
            DSP_Res = ((DSP_Res == TEST_PASSED || DSP_Res == TEST_STUB_INVALID) && validation_result)
                         ? TEST_PASSED : TEST_FAILED;
         }
         break;

      default:
         /* Interface not handled by this function - do NOT modify result */
         break;
   }
} /* end SIT_AF_USC_Receiver */
      #endif /* #if 0 */

/******************************************************************************
 * Name:  SIT_AF_Downselection_Receiver
 *   Downselection calibration receiver - validates downselection parameters.
 *
 * Shared Variables: DSP_Test_Iface_Num, DSP_Stub_Val, DSP_Res
 *
 * Parameters: p_af_ds_inout_param - Pointer to AF downselection params structure
 *
 * Return Value: none
 *
 * Design Information:
 *  - Called from af_downselection.c to validate downselection params
 *  - Validates individual scalar fields of AF_DownSelection_In_Out_Params_T
 *
 *  Change References:
 *  - Ported from Gen7_V2 SWE5 framework
 *
 ******************************************************************************/
SRAM0_TEXT void SIT_AF_Downselection_Receiver(AF_DownSelection_In_Out_Params_T *af_ds_init_params)
{
   bool validation_result = false;
   DSP_Res                = Is_Valid_Interface(DSP_Test_Iface_Num);

   switch (DSP_Test_Iface_Num)
   {
      case Ri_smc_ds_enable_aa_az: /* WI-345643001 */
         CHECK_PROVIDER_STUB(DSP_Prov_Stub_From_Master);
         Set_Shared_Ptr(&DSP_Shared_Ri, af_ds_init_params->ds_enable_aa_az_ptr, sizeof(uint8_t), 1, Ri_smc_ds_enable_aa_az,
                        DATATYPE_UINT8);
         validation_result = Validate_Scalar_Values(af_ds_init_params->ds_enable_aa_az_ptr, DATATYPE_UINT8, DSP_Stub_Val);
         DSP_Res = ((DSP_Res == TEST_PASSED || DSP_Res == TEST_STUB_INVALID) && validation_result) ? TEST_PASSED : TEST_FAILED;
         Clear_Prov_Stub_Flags();
         break;
      case Ri_smc_ds_enable_aa_el: /* WI-345643002 */
         CHECK_PROVIDER_STUB(DSP_Prov_Stub_From_Master);
         Set_Shared_Ptr(&DSP_Shared_Ri, af_ds_init_params->ds_enable_aa_el_ptr, sizeof(uint8_t), 1, Ri_smc_ds_enable_aa_el,
                        DATATYPE_UINT8);
         validation_result = Validate_Scalar_Values(af_ds_init_params->ds_enable_aa_el_ptr, DATATYPE_UINT8, DSP_Stub_Val);
         DSP_Res = ((DSP_Res == TEST_PASSED || DSP_Res == TEST_STUB_INVALID) && validation_result) ? TEST_PASSED : TEST_FAILED;
         Clear_Prov_Stub_Flags();
         break;
      case Ri_smc_ds_enable_az_proj: /* WI-345643003 */
         CHECK_PROVIDER_STUB(DSP_Prov_Stub_From_Master);
         Set_Shared_Ptr(&DSP_Shared_Ri, af_ds_init_params->ds_enable_az_proj_ptr, sizeof(uint8_t), 1, Ri_smc_ds_enable_az_proj,
                        DATATYPE_UINT8);
         validation_result = Validate_Scalar_Values(af_ds_init_params->ds_enable_az_proj_ptr, DATATYPE_UINT8, DSP_Stub_Val);
         DSP_Res = ((DSP_Res == TEST_PASSED || DSP_Res == TEST_STUB_INVALID) && validation_result) ? TEST_PASSED : TEST_FAILED;
         Clear_Prov_Stub_Flags();
         break;
      case Ri_smc_ds_enable_el_proj: /* WI-345643004 */
         CHECK_PROVIDER_STUB(DSP_Prov_Stub_From_Master);
         Set_Shared_Ptr(&DSP_Shared_Ri, af_ds_init_params->ds_enable_el_proj_ptr, sizeof(uint8_t), 1, Ri_smc_ds_enable_el_proj,
                        DATATYPE_UINT8);
         validation_result = Validate_Scalar_Values(af_ds_init_params->ds_enable_el_proj_ptr, DATATYPE_UINT8, DSP_Stub_Val);
         DSP_Res = ((DSP_Res == TEST_PASSED || DSP_Res == TEST_STUB_INVALID) && validation_result) ? TEST_PASSED : TEST_FAILED;
         Clear_Prov_Stub_Flags();
         break;
      case Ri_smc_ds_num_unfolding_intervals: /* WI-345643005 */
         CHECK_PROVIDER_STUB(DSP_Prov_Stub_From_Master);
         Set_Shared_Ptr(&DSP_Shared_Ri, af_ds_init_params->ds_num_unfolding_intervals_ptr, sizeof(uint8_t), 1,
                        Ri_smc_ds_num_unfolding_intervals, DATATYPE_UINT8);
         validation_result =
            Validate_Scalar_Values(af_ds_init_params->ds_num_unfolding_intervals_ptr, DATATYPE_UINT8, DSP_Stub_Val);
         DSP_Res = ((DSP_Res == TEST_PASSED || DSP_Res == TEST_STUB_INVALID) && validation_result) ? TEST_PASSED : TEST_FAILED;
         Clear_Prov_Stub_Flags();
         break;
      case Ri_smc_ds_score_selection: /* WI-345643006 */
         CHECK_PROVIDER_STUB(DSP_Prov_Stub_From_Master);
         Set_Shared_Ptr(&DSP_Shared_Ri, af_ds_init_params->ds_score_selection_ptr, sizeof(uint8_t), 1, Ri_smc_ds_score_selection,
                        DATATYPE_UINT8);
         validation_result = Validate_Scalar_Values(af_ds_init_params->ds_score_selection_ptr, DATATYPE_UINT8, DSP_Stub_Val);
         DSP_Res = ((DSP_Res == TEST_PASSED || DSP_Res == TEST_STUB_INVALID) && validation_result) ? TEST_PASSED : TEST_FAILED;
         Clear_Prov_Stub_Flags();
         break;
      case Ri_smc_ds_flag_enable_ds: /* WI-345643008 */
         CHECK_PROVIDER_STUB(DSP_Prov_Stub_From_Master);
         Set_Shared_Ptr(&DSP_Shared_Ri, af_ds_init_params->enable_downselection_ptr, sizeof(uint8_t), 1, Ri_smc_ds_flag_enable_ds,
                        DATATYPE_UINT8);
         validation_result = Validate_Scalar_Values(af_ds_init_params->enable_downselection_ptr, DATATYPE_UINT8, DSP_Stub_Val);
         DSP_Res = ((DSP_Res == TEST_PASSED || DSP_Res == TEST_STUB_INVALID) && validation_result) ? TEST_PASSED : TEST_FAILED;
         Clear_Prov_Stub_Flags();
         break;
      case Ri_smc_ds_max_target_reports: /* WI-345643009 */
         CHECK_PROVIDER_STUB(DSP_Prov_Stub_From_Master);
         Set_Shared_Ptr(&DSP_Shared_Ri, af_ds_init_params->ds_max_target_reports_ptr, sizeof(uint32_t), 1,
                        Ri_smc_ds_max_target_reports, DATATYPE_UINT32);
         validation_result = Validate_Scalar_Values(af_ds_init_params->ds_max_target_reports_ptr, DATATYPE_UINT32, DSP_Stub_Val);
         DSP_Res = ((DSP_Res == TEST_PASSED || DSP_Res == TEST_STUB_INVALID) && validation_result) ? TEST_PASSED : TEST_FAILED;
         Clear_Prov_Stub_Flags();
         break;
      case Ri_smc_ds_moving_thold: /* WI-345643007 */
         CHECK_PROVIDER_STUB(DSP_Prov_Stub_From_Master);
         Set_Shared_Ptr(&DSP_Shared_Ri, af_ds_init_params->ds_moving_thold_ptr, sizeof(float32_t), 1, Ri_smc_ds_moving_thold,
                        DATATYPE_FLOAT32);
         validation_result = Validate_Scalar_Values(af_ds_init_params->ds_moving_thold_ptr, DATATYPE_FLOAT32, DSP_Stub_Val);
         DSP_Res = ((DSP_Res == TEST_PASSED || DSP_Res == TEST_STUB_INVALID) && validation_result) ? TEST_PASSED : TEST_FAILED;
         Clear_Prov_Stub_Flags();
         break;
      case Ri_unambiguous_velocity: /* WI-399436 */
         CHECK_PROVIDER_STUB(DSP_Prov_Stub_From_Master);
         Set_Shared_Ptr(&DSP_Shared_Ri, af_ds_init_params->vua_ptr, sizeof(int32_t), 1, Ri_unambiguous_velocity, DATATYPE_INT32);
         validation_result = Validate_Scalar_Values(af_ds_init_params->vua_ptr, DATATYPE_INT32, DSP_Stub_Val);
         DSP_Res = ((DSP_Res == TEST_PASSED || DSP_Res == TEST_STUB_INVALID) && validation_result) ? TEST_PASSED : TEST_FAILED;
         Clear_Prov_Stub_Flags();
         break;
      case Ri_sensor_mount_pos_x: /* WI-294037001 */
         CHECK_PROVIDER_STUB(DSP_Prov_Stub_From_Master);
         Set_Shared_Ptr(&DSP_Shared_Ri, af_ds_init_params->sensor_mount_pos_x_ptr, sizeof(float32_t), 1, Ri_sensor_mount_pos_x,
                        DATATYPE_FLOAT32);
         validation_result = Validate_Scalar_Values(af_ds_init_params->sensor_mount_pos_x_ptr, DATATYPE_FLOAT32, DSP_Stub_Val);
         DSP_Res = ((DSP_Res == TEST_PASSED || DSP_Res == TEST_STUB_INVALID) && validation_result) ? TEST_PASSED : TEST_FAILED;
         Clear_Prov_Stub_Flags();
         break;
      case Ri_sensor_mount_pos_y: /* WI-294037002 */
         CHECK_PROVIDER_STUB(DSP_Prov_Stub_From_Master);
         Set_Shared_Ptr(&DSP_Shared_Ri, af_ds_init_params->sensor_mount_pos_y_ptr, sizeof(float32_t), 1, Ri_sensor_mount_pos_y,
                        DATATYPE_FLOAT32);
         validation_result = Validate_Scalar_Values(af_ds_init_params->sensor_mount_pos_y_ptr, DATATYPE_FLOAT32, DSP_Stub_Val);
         DSP_Res = ((DSP_Res == TEST_PASSED || DSP_Res == TEST_STUB_INVALID) && validation_result) ? TEST_PASSED : TEST_FAILED;
         Clear_Prov_Stub_Flags();
         break;
      case Ri_sensor_mount_pos_z: /* WI-294037003 */
         CHECK_PROVIDER_STUB(DSP_Prov_Stub_From_Master);
         Set_Shared_Ptr(&DSP_Shared_Ri, af_ds_init_params->sensor_mount_pos_z_ptr, sizeof(float32_t), 1, Ri_sensor_mount_pos_z,
                        DATATYPE_FLOAT32);
         validation_result = Validate_Scalar_Values(af_ds_init_params->sensor_mount_pos_z_ptr, DATATYPE_FLOAT32, DSP_Stub_Val);
         DSP_Res = ((DSP_Res == TEST_PASSED || DSP_Res == TEST_STUB_INVALID) && validation_result) ? TEST_PASSED : TEST_FAILED;
         Clear_Prov_Stub_Flags();
         break;
      case Ri_sensor_mount_ornt_roll: /* WI-294037004 */
         CHECK_PROVIDER_STUB(DSP_Prov_Stub_From_Master);
         Set_Shared_Ptr(&DSP_Shared_Ri, af_ds_init_params->sensor_mount_ornt_roll_ptr, sizeof(float32_t), 1,
                        Ri_sensor_mount_ornt_roll, DATATYPE_FLOAT32);
         validation_result = Validate_Scalar_Values(af_ds_init_params->sensor_mount_ornt_roll_ptr, DATATYPE_FLOAT32, DSP_Stub_Val);
         DSP_Res = ((DSP_Res == TEST_PASSED || DSP_Res == TEST_STUB_INVALID) && validation_result) ? TEST_PASSED : TEST_FAILED;
         Clear_Prov_Stub_Flags();
         break;
      case Ri_sensor_mount_ornt_pitch: /* WI-294037005 */
         CHECK_PROVIDER_STUB(DSP_Prov_Stub_From_Master);
         Set_Shared_Ptr(&DSP_Shared_Ri, af_ds_init_params->sensor_mount_ornt_pitch_ptr, sizeof(float32_t), 1,
                        Ri_sensor_mount_ornt_pitch, DATATYPE_FLOAT32);
         validation_result =
            Validate_Scalar_Values(af_ds_init_params->sensor_mount_ornt_pitch_ptr, DATATYPE_FLOAT32, DSP_Stub_Val);
         DSP_Res = ((DSP_Res == TEST_PASSED || DSP_Res == TEST_STUB_INVALID) && validation_result) ? TEST_PASSED : TEST_FAILED;
         Clear_Prov_Stub_Flags();
         break;
      case Ri_sensor_mount_ornt_yaw: /* WI-294037006 */
         CHECK_PROVIDER_STUB(DSP_Prov_Stub_From_Master);
         Set_Shared_Ptr(&DSP_Shared_Ri, af_ds_init_params->sensor_mount_ornt_yaw_ptr, sizeof(float32_t), 1,
                        Ri_sensor_mount_ornt_yaw, DATATYPE_FLOAT32);
         validation_result = Validate_Scalar_Values(af_ds_init_params->sensor_mount_ornt_yaw_ptr, DATATYPE_FLOAT32, DSP_Stub_Val);
         DSP_Res = ((DSP_Res == TEST_PASSED || DSP_Res == TEST_STUB_INVALID) && validation_result) ? TEST_PASSED : TEST_FAILED;
         Clear_Prov_Stub_Flags();
         break;
      default:
         return;
   }

   /* Reset flags after validation complete */
   DSP_Prov_Stub             = false;
   DSP_Prov_Stub_From_Master = false;
} /* end SIT_AF_Downselection_Receiver */

      /******************************************************************************
       * Name:  SIT_Compute_RCS_Receiver
       *   RCS rolloff limit receiver - validates RCS calibration parameters.
       *
       * Shared Variables: DSP_Test_Iface_Num, DSP_Stub_Val, DSP_Res
       *
       * Parameters: k_rcs_az_rolloff - Pointer to azimuth RCS rolloff limit array [2]
       *             k_rcs_el_rolloff - Pointer to elevation RCS rolloff limit array [2]
       *
       * Return Value: none
       *
       * Design Information:
       *  - Called from compute_rcs.c to validate RCS rolloff limit params
       *  - Each rolloff limit has 2 elements (one per calibration section)
       *
       *  Change References:
       *  - Ported from Gen7_V2 SWE5 framework
       *
       ******************************************************************************/
      #if 0
SRAM0_DATA float k_rcs_az_rolloff_limit_0_read = 0.0f;
SRAM0_DATA float k_rcs_az_rolloff_limit_1_read = 0.0f;
SRAM0_DATA float k_rcs_el_rolloff_limit_0_read = 0.0f;
SRAM0_DATA float k_rcs_el_rolloff_limit_1_read = 0.0f;
SRAM0_TEXT void SIT_Compute_RCS_Receiver(float32_t *k_rcs_az_rolloff, float32_t *k_rcs_el_rolloff)
{
   bool validation_result = false;

   /* Validate interface number and initialize result */
   DSP_Res = Is_Valid_Interface(DSP_Test_Iface_Num);
   switch (DSP_Test_Iface_Num)
   {
      case Ri_k_rcs_az_rolloff_limit_str_0: /* WI-399439001 */
         CHECK_PROVIDER_STUB(DSP_Prov_Stub_From_Master);
         k_rcs_az_rolloff_limit_0_read = (*(&k_rcs_az_rolloff[0])) / ((1.220703125e-04f) * ((57.2957795130823069f)));
         Set_Shared_Ptr(&DSP_Shared_Ri, &k_rcs_az_rolloff_limit_0_read, sizeof(float32_t), 1, Ri_k_rcs_az_rolloff_limit_str_0,
                        DATATYPE_FLOAT32);
         validation_result = Validate_Scalar_Values(&k_rcs_az_rolloff_limit_0_read, DATATYPE_FLOAT32, DSP_Stub_Val);
         DSP_Res = ((DSP_Res == TEST_PASSED || DSP_Res == TEST_STUB_INVALID) && validation_result) ? TEST_PASSED : TEST_FAILED;
         Clear_Prov_Stub_Flags();
         break;
      case Ri_k_rcs_az_rolloff_limit_str_1: /* WI-399439002 */
         CHECK_PROVIDER_STUB(DSP_Prov_Stub_From_Master);
         k_rcs_az_rolloff_limit_1_read = (*(&k_rcs_az_rolloff[1])) / ((1.220703125e-04f) * ((57.2957795130823069f)));
         Set_Shared_Ptr(&DSP_Shared_Ri, &k_rcs_az_rolloff_limit_1_read, sizeof(float32_t), 1, Ri_k_rcs_az_rolloff_limit_str_1,
                        DATATYPE_FLOAT32);
         validation_result = Validate_Scalar_Values(&k_rcs_az_rolloff_limit_1_read, DATATYPE_FLOAT32, DSP_Stub_Val);
         DSP_Res = ((DSP_Res == TEST_PASSED || DSP_Res == TEST_STUB_INVALID) && validation_result) ? TEST_PASSED : TEST_FAILED;
         Clear_Prov_Stub_Flags();
         break;
      case Ri_k_rcs_el_rolloff_limit_str_0: /* WI-399439003 */
         CHECK_PROVIDER_STUB(DSP_Prov_Stub_From_Master);
         k_rcs_el_rolloff_limit_0_read = (*(&k_rcs_el_rolloff[0])) / ((1.220703125e-04f) * ((57.2957795130823069f)));
         Set_Shared_Ptr(&DSP_Shared_Ri, &k_rcs_el_rolloff_limit_0_read, sizeof(float32_t), 1, Ri_k_rcs_el_rolloff_limit_str_0,
                        DATATYPE_FLOAT32);
         validation_result = Validate_Scalar_Values(&k_rcs_el_rolloff_limit_0_read, DATATYPE_FLOAT32, DSP_Stub_Val);
         DSP_Res = ((DSP_Res == TEST_PASSED || DSP_Res == TEST_STUB_INVALID) && validation_result) ? TEST_PASSED : TEST_FAILED;
         Clear_Prov_Stub_Flags();
         break;
      case Ri_k_rcs_el_rolloff_limit_str_1: /* WI-399439004 */
         CHECK_PROVIDER_STUB(DSP_Prov_Stub_From_Master);
         k_rcs_el_rolloff_limit_1_read = (*(&k_rcs_el_rolloff[1])) / ((1.220703125e-04f) * ((57.2957795130823069f)));
         Set_Shared_Ptr(&DSP_Shared_Ri, &k_rcs_el_rolloff_limit_1_read, sizeof(float32_t), 1, Ri_k_rcs_el_rolloff_limit_str_1,
                        DATATYPE_FLOAT32);
         validation_result = Validate_Scalar_Values(&k_rcs_el_rolloff_limit_1_read, DATATYPE_FLOAT32, DSP_Stub_Val);
         DSP_Res = ((DSP_Res == TEST_PASSED || DSP_Res == TEST_STUB_INVALID) && validation_result) ? TEST_PASSED : TEST_FAILED;
         Clear_Prov_Stub_Flags();
         break;
      default:
         return;
   }
} /* end SIT_Compute_RCS_Receiver */
      #endif
   #endif /* Anglefinding_IT || Radar_capability_IT */

   #if defined(Radar_capability_IT)

SRAM0_TEXT void SIT_ALIGNMENT_LOG_DATA_Provider(Dynamic_Alignment_Log_Stream_T *alignment_log_ptr)
{
   bool stub_validation_result = false;

   switch (DSP_Test_Iface_Num)
   {
      case Ri_vacs_boresight_el_estimated: /* WI-380006: vacs_boresight_el_estimated */
      {
         Stub_Scalar_Values(&alignment_log_ptr->dra_core_data.vacs_boresight_el_estimated, DATATYPE_FLOAT32, DSP_Stub_Val);
         Set_Shared_Ptr(&DSP_Shared_Pi, &alignment_log_ptr->dra_core_data.vacs_boresight_el_estimated, sizeof(float32_t), 1,
                        Ri_vacs_boresight_el_estimated, DATATYPE_FLOAT32);
         /* Validate that stub was successful */
         stub_validation_result =
            Validate_Scalar_Values(&alignment_log_ptr->dra_core_data.vacs_boresight_el_estimated, DATATYPE_FLOAT32, DSP_Stub_Val);
         DSP_Prov_Stub = stub_validation_result;
      }
      break;

      case Ri_vacs_boresight_el_nominal: /* WI-370541: vacs_boresight_el_nominal */
      {
         Stub_Scalar_Values(&alignment_log_ptr->dra_core_data.vacs_boresight_el_nominal, DATATYPE_FLOAT32, DSP_Stub_Val);
         Set_Shared_Ptr(&DSP_Shared_Pi, &alignment_log_ptr->dra_core_data.vacs_boresight_el_nominal, sizeof(float32_t), 1,
                        Ri_vacs_boresight_el_nominal, DATATYPE_FLOAT32);
         /* Validate that stub was successful */
         stub_validation_result =
            Validate_Scalar_Values(&alignment_log_ptr->dra_core_data.vacs_boresight_el_nominal, DATATYPE_FLOAT32, DSP_Stub_Val);
         DSP_Prov_Stub = stub_validation_result;
      }
      break;

      case Ri_vacs_boresight_az_nominal: /* WI-398900 : vacs_boresight_az_nominal */
      {
         Stub_Scalar_Values(&alignment_log_ptr->dra_core_data.vacs_boresight_az_nominal, DATATYPE_FLOAT32, DSP_Stub_Val);
         Set_Shared_Ptr(&DSP_Shared_Pi, &alignment_log_ptr->dra_core_data.vacs_boresight_az_nominal, sizeof(float32_t), 1,
                        Ri_vacs_boresight_az_nominal, DATATYPE_FLOAT32);
         /* Validate that stub was successful */
         stub_validation_result =
            Validate_Scalar_Values(&alignment_log_ptr->dra_core_data.vacs_boresight_az_nominal, DATATYPE_FLOAT32, DSP_Stub_Val);
         DSP_Prov_Stub = stub_validation_result;
      }
      break;

      case Ri_vacs_boresight_az_estimated: /* WI-398901 : vacs_boresight_az_estimated */
      {
         Stub_Scalar_Values(&alignment_log_ptr->dra_core_data.vacs_boresight_az_estimated, DATATYPE_FLOAT32, DSP_Stub_Val);
         Set_Shared_Ptr(&DSP_Shared_Pi, &alignment_log_ptr->dra_core_data.vacs_boresight_az_estimated, sizeof(float32_t), 1,
                        Ri_vacs_boresight_az_estimated, DATATYPE_FLOAT32);
         /* Validate that stub was successful */
         stub_validation_result =
            Validate_Scalar_Values(&alignment_log_ptr->dra_core_data.vacs_boresight_az_estimated, DATATYPE_FLOAT32, DSP_Stub_Val);
         DSP_Prov_Stub = stub_validation_result;
      }
      break;

      case Ri_error_status_el_est_out_of_bounds: /* WI-380005: error_status_el_est_out_of_bounds */
      {
         Stub_Scalar_Values(&alignment_log_ptr->dra_core_data.error_status_el_est_out_of_bounds, DATATYPE_UINT8, DSP_Stub_Val);
         Set_Shared_Ptr(&DSP_Shared_Pi, &alignment_log_ptr->dra_core_data.error_status_el_est_out_of_bounds, sizeof(uint8_t), 1,
                        Ri_error_status_el_est_out_of_bounds, DATATYPE_UINT8);
         /* Validate that stub was successful */
         stub_validation_result = Validate_Scalar_Values(&alignment_log_ptr->dra_core_data.error_status_el_est_out_of_bounds,
                                                         DATATYPE_UINT8, DSP_Stub_Val);
         DSP_Prov_Stub          = stub_validation_result;
      }
      break;

      case Ri_error_status_az_est_out_of_bounds: /* WI-398902: error_status_az_est_out_of_bounds */
      {
         Stub_Scalar_Values(&alignment_log_ptr->dra_core_data.error_status_az_est_out_of_bounds, DATATYPE_UINT8, DSP_Stub_Val);
         Set_Shared_Ptr(&DSP_Shared_Pi, &alignment_log_ptr->dra_core_data.error_status_az_est_out_of_bounds, sizeof(uint8_t), 1,
                        Ri_error_status_az_est_out_of_bounds, DATATYPE_UINT8);
         /* Validate that stub was successful */
         stub_validation_result = Validate_Scalar_Values(&alignment_log_ptr->dra_core_data.error_status_az_est_out_of_bounds,
                                                         DATATYPE_UINT8, DSP_Stub_Val);
         DSP_Prov_Stub          = stub_validation_result;
      }
      break;

      case Ri_elevation_estimation_qf: /* WI-370553: elevation_estimation_qf */
      {
         Stub_Scalar_Values(&alignment_log_ptr->dra_core_data.elevation_estimation_qf, DATATYPE_UINT8, DSP_Stub_Val);
         Set_Shared_Ptr(&DSP_Shared_Pi, &alignment_log_ptr->dra_core_data.elevation_estimation_qf, sizeof(uint8_t), 1,
                        Ri_elevation_estimation_qf, DATATYPE_UINT8);
         /* Validate that stub was successful */
         stub_validation_result =
            Validate_Scalar_Values(&alignment_log_ptr->dra_core_data.elevation_estimation_qf, DATATYPE_UINT8, DSP_Stub_Val);
         DSP_Prov_Stub = stub_validation_result;
      }
      break;

      case Ri_azimuth_estimation_qf: /* WI-398903: azimuth_estimation_qf */
      {
         Stub_Scalar_Values(&alignment_log_ptr->dra_core_data.azimuth_estimation_qf, DATATYPE_UINT8, DSP_Stub_Val);
         Set_Shared_Ptr(&DSP_Shared_Pi, &alignment_log_ptr->dra_core_data.azimuth_estimation_qf, sizeof(uint8_t), 1,
                        Ri_azimuth_estimation_qf, DATATYPE_UINT8);
         /* Validate that stub was successful */
         stub_validation_result =
            Validate_Scalar_Values(&alignment_log_ptr->dra_core_data.azimuth_estimation_qf, DATATYPE_UINT8, DSP_Stub_Val);
         DSP_Prov_Stub = stub_validation_result;
      }
      break;

      default:
         /* Interface not handled by this function - do NOT modify result */
         break;
   }
}

SRAM0_TEXT void SIT_DYNAMIC_ALIGN_DATA_Receiver(RC_Input_T *rc_input)
{
   bool validation_result = false;

   DSP_Res = Is_Valid_Interface(DSP_Test_Iface_Num);

   switch (DSP_Test_Iface_Num)
   {
      case Ri_vacs_boresight_el_estimated: /* WI-380006: vacs_boresight_el_estimated */
      {
         CHECK_PROVIDER_STUB(DSP_Prov_Stub);
         Set_Shared_Ptr(&DSP_Shared_Ri, &rc_input->p_dyn_align_data.vacs_boresight_el_estimated, sizeof(float32_t), 1,
                        Ri_vacs_boresight_el_estimated, DATATYPE_FLOAT32);
         validation_result =
            Validate_Scalar_Values(&rc_input->p_dyn_align_data.vacs_boresight_el_estimated, DATATYPE_FLOAT32, DSP_Stub_Val);
         DSP_Res = ((DSP_Res == TEST_PASSED || DSP_Res == TEST_STUB_INVALID) && validation_result) ? TEST_PASSED : TEST_FAILED;
         Clear_Prov_Stub_Flags();
      }
      break;

      case Ri_vacs_boresight_el_nominal: /* WI-370541: vacs_boresight_el_nominal */
      {
         CHECK_PROVIDER_STUB(DSP_Prov_Stub);
         Set_Shared_Ptr(&DSP_Shared_Ri, &rc_input->p_dyn_align_data.vacs_boresight_el_nominal, sizeof(float32_t), 1,
                        Ri_vacs_boresight_el_nominal, DATATYPE_FLOAT32);
         validation_result =
            Validate_Scalar_Values(&rc_input->p_dyn_align_data.vacs_boresight_el_nominal, DATATYPE_FLOAT32, DSP_Stub_Val);
         DSP_Res = ((DSP_Res == TEST_PASSED || DSP_Res == TEST_STUB_INVALID) && validation_result) ? TEST_PASSED : TEST_FAILED;
         Clear_Prov_Stub_Flags();
      }
      break;

      case Ri_vacs_boresight_az_nominal: /* WI-398900 : vacs_boresight_az_nominal */
      {
         CHECK_PROVIDER_STUB(DSP_Prov_Stub);
         Set_Shared_Ptr(&DSP_Shared_Ri, &rc_input->p_dyn_align_data.vacs_boresight_az_nominal, sizeof(float32_t), 1,
                        Ri_vacs_boresight_az_nominal, DATATYPE_FLOAT32);
         validation_result =
            Validate_Scalar_Values(&rc_input->p_dyn_align_data.vacs_boresight_az_nominal, DATATYPE_FLOAT32, DSP_Stub_Val);
         DSP_Res = ((DSP_Res == TEST_PASSED || DSP_Res == TEST_STUB_INVALID) && validation_result) ? TEST_PASSED : TEST_FAILED;
         Clear_Prov_Stub_Flags();
      }
      break;

      case Ri_vacs_boresight_az_estimated: /* WI-398901 : vacs_boresight_az_estimated */
      {
         CHECK_PROVIDER_STUB(DSP_Prov_Stub);
         Set_Shared_Ptr(&DSP_Shared_Ri, &rc_input->p_dyn_align_data.vacs_boresight_az_estimated, sizeof(float), 1,
                        Ri_vacs_boresight_az_estimated, DATATYPE_FLOAT32);
         validation_result =
            Validate_Scalar_Values(&rc_input->p_dyn_align_data.vacs_boresight_az_estimated, DATATYPE_FLOAT32, DSP_Stub_Val);
         DSP_Res = ((DSP_Res == TEST_PASSED || DSP_Res == TEST_STUB_INVALID) && validation_result) ? TEST_PASSED : TEST_FAILED;
         Clear_Prov_Stub_Flags();
      }
      break;

      case Ri_error_status_el_est_out_of_bounds: /* WI-380005: error_status_el_est_out_of_bounds */
      {
         CHECK_PROVIDER_STUB(DSP_Prov_Stub);
         Set_Shared_Ptr(&DSP_Shared_Ri, &rc_input->p_dyn_align_data.error_status_el_est_out_of_bounds, sizeof(uint8_t), 1,
                        Ri_error_status_el_est_out_of_bounds, DATATYPE_UINT8);
         validation_result =
            Validate_Scalar_Values(&rc_input->p_dyn_align_data.error_status_el_est_out_of_bounds, DATATYPE_UINT8, DSP_Stub_Val);
         DSP_Res = ((DSP_Res == TEST_PASSED || DSP_Res == TEST_STUB_INVALID) && validation_result) ? TEST_PASSED : TEST_FAILED;
         Clear_Prov_Stub_Flags();
      }
      break;

      case Ri_error_status_az_est_out_of_bounds: /* WI-398902: error_status_az_est_out_of_bounds */
      {
         CHECK_PROVIDER_STUB(DSP_Prov_Stub);
         Set_Shared_Ptr(&DSP_Shared_Ri, &rc_input->p_dyn_align_data.error_status_az_est_out_of_bounds, sizeof(uint8_t), 1,
                        Ri_error_status_az_est_out_of_bounds, DATATYPE_UINT8);
         validation_result =
            Validate_Scalar_Values(&rc_input->p_dyn_align_data.error_status_az_est_out_of_bounds, DATATYPE_UINT8, DSP_Stub_Val);
         DSP_Res = ((DSP_Res == TEST_PASSED || DSP_Res == TEST_STUB_INVALID) && validation_result) ? TEST_PASSED : TEST_FAILED;
         Clear_Prov_Stub_Flags();
      }
      break;

      case Ri_elevation_estimation_qf: /* WI-370553: elevation_estimation_qf */
      {
         CHECK_PROVIDER_STUB(DSP_Prov_Stub);
         Set_Shared_Ptr(&DSP_Shared_Ri, &rc_input->p_dyn_align_data.elevation_estimation_qf, sizeof(uint8_t), 1,
                        Ri_elevation_estimation_qf, DATATYPE_UINT8);
         validation_result =
            Validate_Scalar_Values(&rc_input->p_dyn_align_data.elevation_estimation_qf, DATATYPE_UINT8, DSP_Stub_Val);
         DSP_Res = ((DSP_Res == TEST_PASSED || DSP_Res == TEST_STUB_INVALID) && validation_result) ? TEST_PASSED : TEST_FAILED;
         Clear_Prov_Stub_Flags();
      }
      break;

      case Ri_azimuth_estimation_qf: /* WI-398903: azimuth_estimation_qf */
      {
         CHECK_PROVIDER_STUB(DSP_Prov_Stub);
         Set_Shared_Ptr(&DSP_Shared_Ri, &rc_input->p_dyn_align_data.azimuth_estimation_qf, sizeof(uint8_t), 1,
                        Ri_azimuth_estimation_qf, DATATYPE_UINT8);
         validation_result =
            Validate_Scalar_Values(&rc_input->p_dyn_align_data.azimuth_estimation_qf, DATATYPE_UINT8, DSP_Stub_Val);
         DSP_Res = ((DSP_Res == TEST_PASSED || DSP_Res == TEST_STUB_INVALID) && validation_result) ? TEST_PASSED : TEST_FAILED;
         Clear_Prov_Stub_Flags();
      }
      break;

      default:
         return;
   }
}

SRAM0_TEXT void SIT_AVG_MMIC_ONCHIP_TEMP_DATA_Receiver(RC_Input_T *rc_input)
{
   bool validation_result = false;

   DSP_Res = Is_Valid_Interface(DSP_Test_Iface_Num);

   switch (DSP_Test_Iface_Num)
   {
      case Ri_avg_mmic_onchip_temp: /* WI-370545: avg_mmic_onchip_temp_data */
      {
         CHECK_PROVIDER_STUB(DSP_Prov_Stub_From_Master);
         Set_Shared_Ptr(&DSP_Shared_Ri, &rc_input->avg_mmic_onchip_temp, sizeof(int16_t), 1, Ri_avg_mmic_onchip_temp,
                        DATATYPE_INT16);
         validation_result = Validate_Scalar_Values(&rc_input->avg_mmic_onchip_temp, DATATYPE_INT16, DSP_Stub_Val);
         DSP_Res = ((DSP_Res == TEST_PASSED || DSP_Res == TEST_STUB_INVALID) && validation_result) ? TEST_PASSED : TEST_FAILED;
         Clear_Prov_Stub_Flags();
      }
      break;

      case Ri_host_speed: /* WI-370537: host_speed */
      {
         CHECK_PROVIDER_STUB(DSP_Prov_Stub_From_Master);
         Set_Shared_Ptr(&DSP_Shared_Ri, &rc_input->p_veh_data.veh_speed, sizeof(float32_t), 1, Ri_host_speed, DATATYPE_FLOAT32);
         validation_result = Validate_Scalar_Values(&rc_input->p_veh_data.veh_speed, DATATYPE_FLOAT32, DSP_Stub_Val);
         DSP_Res = ((DSP_Res == TEST_PASSED || DSP_Res == TEST_STUB_INVALID) && validation_result) ? TEST_PASSED : TEST_FAILED;
         Clear_Prov_Stub_Flags();
      }
      break;

      case Ri_host_yawrate: /* WI-370539: host_yaw_rate */
      {
         CHECK_PROVIDER_STUB(DSP_Prov_Stub_From_Master);
         Set_Shared_Ptr(&DSP_Shared_Ri, &rc_input->p_veh_data.veh_yaw, sizeof(float32_t), 1, Ri_host_yawrate, DATATYPE_FLOAT32);
         validation_result = Validate_Scalar_Values(&rc_input->p_veh_data.veh_yaw, DATATYPE_FLOAT32, DSP_Stub_Val);
         DSP_Res = ((DSP_Res == TEST_PASSED || DSP_Res == TEST_STUB_INVALID) && validation_result) ? TEST_PASSED : TEST_FAILED;
         Clear_Prov_Stub_Flags();
      }
      break;

      case Ri_min_chirp_scaling: /* WI-370573: min_chirp_scaling */
      {
         CHECK_PROVIDER_STUB(DSP_Prov_Stub);
         Set_Shared_Ptr(&DSP_Shared_Ri, &rc_input->p_rdd_stream_data.rdd_data.min_chirp_scaling, sizeof(uint8_t), 1,
                        Ri_min_chirp_scaling, DATATYPE_UINT8);
         validation_result =
            Validate_Scalar_Values(&rc_input->p_rdd_stream_data.rdd_data.min_chirp_scaling, DATATYPE_UINT8, DSP_Stub_Val);
         DSP_Res = ((DSP_Res == TEST_PASSED || DSP_Res == TEST_STUB_INVALID) && validation_result) ? TEST_PASSED : TEST_FAILED;
         Clear_Prov_Stub_Flags();
      }
      break;

      case Ri_cfar_nf_est: /* WI-370570: cfar_nf_est */
      {
         CHECK_PROVIDER_STUB(DSP_Prov_Stub);
         Set_Shared_Ptr(&DSP_Shared_Ri, rc_input->p_rdd_stream_data.rdd_data.cfar_nf_est, sizeof(uint16_t), 1, Ri_cfar_nf_est,
                        DATATYPE_UINT16);
         validation_result =
            Validate_1D_Array_Values(rc_input->p_rdd_stream_data.rdd_data.cfar_nf_est, DATATYPE_UINT16, DSP_Stub_Val, 1);
         DSP_Res = ((DSP_Res == TEST_PASSED || DSP_Res == TEST_STUB_INVALID) && validation_result) ? TEST_PASSED : TEST_FAILED;
         Clear_Prov_Stub_Flags();
      }
      break;

      case Ri_rdd_max_per_range_bin: /* WI-370568: rdd_max_per_range_bin */
      {
         CHECK_PROVIDER_STUB(DSP_Prov_Stub);
         Set_Shared_Ptr(&DSP_Shared_Ri, rc_input->p_rdd_stream_data.rdd_data.rdd1_max_per_range_bin, sizeof(uint16_t), 1,
                        Ri_rdd_max_per_range_bin, DATATYPE_UINT16);
         validation_result = Validate_1D_Array_Values(rc_input->p_rdd_stream_data.rdd_data.rdd1_max_per_range_bin, DATATYPE_UINT16,
                                                      DSP_Stub_Val, 1);
         DSP_Res = ((DSP_Res == TEST_PASSED || DSP_Res == TEST_STUB_INVALID) && validation_result) ? TEST_PASSED : TEST_FAILED;
         Clear_Prov_Stub_Flags();
      }
      break;

      case Ri_look_data_0: /* WI-370549001: look_data_0 */
      {
         CHECK_PROVIDER_STUB(DSP_Prov_Stub_From_Master);
         Set_Shared_Ptr(&DSP_Shared_Ri, &rc_input->p_rdd_stream_data.look_data.look_id, sizeof(uint16_t), 1, Ri_look_data_0,
                        DATATYPE_UINT16);
         validation_result = Validate_Scalar_Values(&rc_input->p_rdd_stream_data.look_data.look_id, DATATYPE_UINT16, DSP_Stub_Val);
         DSP_Res = ((DSP_Res == TEST_PASSED || DSP_Res == TEST_STUB_INVALID) && validation_result) ? TEST_PASSED : TEST_FAILED;
         Clear_Prov_Stub_Flags();
      }
      break;

      case Ri_look_data_1: /* WI-370549002: look_data_1 */
      {
         CHECK_PROVIDER_STUB(DSP_Prov_Stub_From_Master);
         Set_Shared_Ptr(&DSP_Shared_Ri, &rc_input->p_rdd_stream_data.look_data.scan_index, sizeof(uint16_t), 1, Ri_look_data_1,
                        DATATYPE_UINT16);
         validation_result =
            Validate_Scalar_Values(&rc_input->p_rdd_stream_data.look_data.scan_index, DATATYPE_UINT16, DSP_Stub_Val);
         DSP_Res = ((DSP_Res == TEST_PASSED || DSP_Res == TEST_STUB_INVALID) && validation_result) ? TEST_PASSED : TEST_FAILED;
         Clear_Prov_Stub_Flags();
      }
      break;

      default:
         /* Interface not handled by this function - do NOT modify result */
         break;
   }
}

   #endif /* Radar_capability_IT */
   #if defined(FirstPass_IT)
/******************************************************************************
 * Module Name: First Pass
 ******************************************************************************/

/******************************************************************************
 * Name:  SIT_FP_Output_Data_Provider
 *   Provider function for First Pass WI-365501/WI-365503/WI-365505 Pi flows.
 *
 * Shared Variables: DSP_Test_Iface_Num, DSP_Stub_Val, DSP_Stub_Len
 *
 * Parameters: rdop_data_ptr - Pointer array to circular NCI buffers
 *
 * Return Value: none
 *
 * Design Information:
 *  - Stubs NCI circular buffer data (prev/curr/next) for First Pass input
 *  - Validates stub operation and sets DSP_Prov_Stub flag
 *  - Clamps element count to buffer capacity (MAX_DOPPLER_FFT_SIZE * MAP_NUM_ANGLES)
 *
 *  Change References:
 *  - Initial implementation
 *
 ******************************************************************************/
SRAM0_TEXT void SIT_FP_Output_Data_Provider(uint16_t **rdop_data_ptr)
{
   bool stub_validation_result = false;
   uint32_t num_elem           = DSP_Stub_Len;

   switch (DSP_Test_Iface_Num)
   {
      case Ri_NCI_prev_rdop_avg: /* WI-365501: rdop_avg_data_ptr[NCI_PREV_BUFFER_DEPTH] */
      {
         if (num_elem > (uint32_t)(MAX_DOPPLER_FFT_SIZE * MAP_NUM_ANGLES))
         {
            num_elem = (uint32_t)(MAX_DOPPLER_FFT_SIZE * MAP_NUM_ANGLES);
         }
         Stub_1D_Array_Values(rdop_data_ptr[NCI_PREV_BUFFER_DEPTH], DATATYPE_UINT16, DSP_Stub_Val, num_elem);
         Set_Shared_Ptr(&DSP_Shared_Pi, rdop_data_ptr[NCI_PREV_BUFFER_DEPTH], sizeof(uint16_t), num_elem, Ri_NCI_prev_rdop_avg,
                        DATATYPE_UINT16);
         stub_validation_result =
            Validate_1D_Array_Values(rdop_data_ptr[NCI_PREV_BUFFER_DEPTH], DATATYPE_UINT16, DSP_Stub_Val, num_elem);
         DSP_Prov_Stub       = stub_validation_result;
         FP_Provider_Stubbed = true;
      }
      break;

      case Ri_NCI_curr_rdop_avg: /* WI-365503: rdop_avg_data_ptr[NCI_CURRENT_BUFFER_DEPTH] */
      {
         if (num_elem > (uint32_t)(MAX_DOPPLER_FFT_SIZE * MAP_NUM_ANGLES))
         {
            num_elem = (uint32_t)(MAX_DOPPLER_FFT_SIZE * MAP_NUM_ANGLES);
         }
         Stub_1D_Array_Values(rdop_data_ptr[NCI_CURRENT_BUFFER_DEPTH], DATATYPE_UINT16, DSP_Stub_Val, num_elem);
         Set_Shared_Ptr(&DSP_Shared_Pi, rdop_data_ptr[NCI_CURRENT_BUFFER_DEPTH], sizeof(uint16_t), num_elem, Ri_NCI_curr_rdop_avg,
                        DATATYPE_UINT16);
         stub_validation_result =
            Validate_1D_Array_Values(rdop_data_ptr[NCI_CURRENT_BUFFER_DEPTH], DATATYPE_UINT16, DSP_Stub_Val, num_elem);
         DSP_Prov_Stub       = stub_validation_result;
         FP_Provider_Stubbed = true;
      }
      break;

      case Ri_NCI_next_rdop_avg: /* WI-365505: rdop_avg_data_ptr[NCI_NEXT_BUFFER_DEPTH] */
      {
         if (num_elem > (uint32_t)(MAX_DOPPLER_FFT_SIZE * MAP_NUM_ANGLES))
         {
            num_elem = (uint32_t)(MAX_DOPPLER_FFT_SIZE * MAP_NUM_ANGLES);
         }
         Stub_1D_Array_Values(rdop_data_ptr[NCI_NEXT_BUFFER_DEPTH], DATATYPE_UINT16, DSP_Stub_Val, num_elem);
         Set_Shared_Ptr(&DSP_Shared_Pi, rdop_data_ptr[NCI_NEXT_BUFFER_DEPTH], sizeof(uint16_t), num_elem, Ri_NCI_next_rdop_avg,
                        DATATYPE_UINT16);
         stub_validation_result =
            Validate_1D_Array_Values(rdop_data_ptr[NCI_NEXT_BUFFER_DEPTH], DATATYPE_UINT16, DSP_Stub_Val, num_elem);
         DSP_Prov_Stub       = stub_validation_result;
         FP_Provider_Stubbed = true;
      }
      break;

      default:
         break;
   }
}

/******************************************************************************
 * Name:  SIT_FP_Input_Receiver
 *   Receiver function for First Pass WI-365501/WI-365503/WI-365505 Ri flows.
 *
 * Shared Variables: DSP_Test_Iface_Num, DSP_Stub_Val, DSP_Stub_Len, DSP_Res
 *
 * Parameters: rdd_fp_input - Pointer to First Pass input structure
 *
 * Return Value: none
 *
 * Design Information:
 *  - Validates First Pass input data received from provider
 *  - Checks provider stub flag before validation
 *  - Updates DSP_Res based on validation result
 *  - Resets stub flags after validation
 *
 *  Change References:
 *  - Initial implementation
 *
 ******************************************************************************/
SRAM0_TEXT void SIT_FP_Input_Receiver(const Rdd_First_Pass_Input_T *rdd_fp_input)
{
   if (FP_Provider_Stubbed == true)
   {
      bool validation_result = false;

      DSP_Res = Is_Valid_Interface(DSP_Test_Iface_Num);

      switch (DSP_Test_Iface_Num)
      {
         case Ri_NCI_prev_rdop_avg: /* WI-365501: rdd_fp_input->prev_ptr */
         {
            CHECK_PROVIDER_STUB(DSP_Prov_Stub);
            Set_Shared_Ptr(&DSP_Shared_Ri, rdd_fp_input->prev_ptr, sizeof(uint16_t), DSP_Stub_Len, Ri_NCI_prev_rdop_avg,
                           DATATYPE_UINT16);
            validation_result = Validate_1D_Array_Values(rdd_fp_input->prev_ptr, DATATYPE_UINT16, DSP_Stub_Val, DSP_Stub_Len);
            DSP_Res = ((DSP_Res == TEST_PASSED || DSP_Res == TEST_STUB_INVALID) && validation_result) ? TEST_PASSED : TEST_FAILED;
            Clear_Prov_Stub_Flags();
            FP_Provider_Stubbed = false;
         }
         break;

         case Ri_NCI_curr_rdop_avg: /* WI-365503: rdd_fp_input->curr_ptr */
         {
            CHECK_PROVIDER_STUB(DSP_Prov_Stub);
            Set_Shared_Ptr(&DSP_Shared_Ri, rdd_fp_input->curr_ptr, sizeof(uint16_t), DSP_Stub_Len, Ri_NCI_curr_rdop_avg,
                           DATATYPE_UINT16);
            validation_result = Validate_1D_Array_Values(rdd_fp_input->curr_ptr, DATATYPE_UINT16, DSP_Stub_Val, DSP_Stub_Len);
            DSP_Res = ((DSP_Res == TEST_PASSED || DSP_Res == TEST_STUB_INVALID) && validation_result) ? TEST_PASSED : TEST_FAILED;
            Clear_Prov_Stub_Flags();
            FP_Provider_Stubbed = false;
         }
         break;

         case Ri_NCI_next_rdop_avg: /* WI-365505: rdd_fp_input->next_ptr */
         {
            CHECK_PROVIDER_STUB(DSP_Prov_Stub);
            Set_Shared_Ptr(&DSP_Shared_Ri, rdd_fp_input->next_ptr, sizeof(uint16_t), DSP_Stub_Len, Ri_NCI_next_rdop_avg,
                           DATATYPE_UINT16);
            validation_result = Validate_1D_Array_Values(rdd_fp_input->next_ptr, DATATYPE_UINT16, DSP_Stub_Val, DSP_Stub_Len);
            DSP_Res = ((DSP_Res == TEST_PASSED || DSP_Res == TEST_STUB_INVALID) && validation_result) ? TEST_PASSED : TEST_FAILED;
            Clear_Prov_Stub_Flags();
            FP_Provider_Stubbed = false;
         }
         break;

         default:
            break;
      }
   }
}
   #endif /* First_Pass_IT */
#endif    /* Integration_Testing */

/** @} doxygen end group */

/*============================================================================*\
 * AUTHOR(S) IDENTITY (AID)
 *-----------------------------------------------------------------------------
 *
 *  AID         NAME
 *  ---------------------------------------------------------------------------
 *  DC          Dinesh ch
\*============================================================================*/

/*============================================================================*\
 * FILE REVISION HISTORY
 *-----------------------------------------------------------------------------
 *
 *  DATE          REVISION         AID          JIRA Ticket ID
 *      SUMMARY OF CHANGES
 *  ---------------------------------------------------------------------------
 *  26-02-10      1.0              DC           EAH-7658
 *      Created initial SWE5 automation framework
 *  ---------------------------------------------------------------------------
\*============================================================================*/

/* END OF FILE -------------------------------------------------------------- */
