/*===========================================================================*/
/**
 * @file master_integration_test.c
 *
 * SWE5 Integration Test Implementation for R52/Master Core
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2026 Aptiv. All rights reserved.
 * Aptiv Sensitive Business - Restricted Aptiv information. Do not disclose.
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *   Implements stubbing and validation functions for the R52/Master core
 *   integration test (SWE5) framework. Provides Set_Shared_Ptr, stub/validate
 *   helpers, IPC transfer, and module-specific test functions.
 *
 * @section ABBR ABBREVIATIONS:
 *   - IPC  - Inter-Processor Communication
 *   - SWE5 - Software Engineering Level 5 (Integration Testing)
 *   - SIT  - Software Integration Testing
 *   - D2M  - DSP to Master
 *   - M2D  - Master to DSP
 *   - USC  - Unit Specific Calibration
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
 * @defgroup master_integration_test_impl Master Integration Test Implementation
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
   #include "master_integration_test.h"

/*===========================================================================*
 * Local Preprocessor #define Constants
 *===========================================================================*/

/*===========================================================================*
 * Local Preprocessor #define MACROS
 *===========================================================================*/

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
/* Common Provider Pointer for Master Core - shows provider test data */
volatile __attribute__((used)) G_Pointer_T Master_Shared_Pi;

/* Common Receiver Pointer for Master Core - shows receiver test data */
volatile __attribute__((used)) G_Pointer_T Master_Shared_Ri;

volatile uint32_t __attribute__((used)) Test_Iface_Num = 0U;  /* Global Test Interface Number User Input */
volatile double __attribute__((used)) Stub_Val         = 0.0; /* Global Test Stub Value User Input */
volatile uint32_t __attribute__((used)) Stub_Len       = 1U;  /* Global Test Stub Length User Input */
volatile SIT_Test_Result_T __attribute__((used)) Master_Final_Res =
   TEST_NOT_PERFORMED;                                                               /* Final Test Result Output for Master Core */
volatile SIT_Test_Result_T __attribute__((used)) DSP_Final_Res = TEST_NOT_PERFORMED; /* Final Test Result Output for DSP Core */

/* Variables for integration testing in Master core */
/* Test interface number identifying which interface is being tested */
static uint32_t Master_Test_Iface_Num = 0U;

/* Stub value to be injected into test data for validation */
static double Master_Stub_Val = 0.0;

/* Number of elements in the stub array for batch operations */
static uint32_t Master_Stub_Len = 1U;

/* Result status of the current SIT test execution */
static SIT_Test_Result_T Master_Res = TEST_NOT_PERFORMED;

/* Last interface number processed - used to detect interface changes */
static uint32_t last_interface_number = 0U;

/* Last stub value processed - used to detect stub value changes */
static double last_stub_value = 0.0;

/* Provider stub validation success flag - indicates if provider successfully stubbed and validated the value */
static bool Master_Prov_Stub          = false;
static bool Master_Prov_Stub_From_DSP = false; /* Received from DSP via IPC */

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
static inline void __attribute__((unused)) Set_Shared_Ptr(volatile G_Pointer_T *dst_ptr, const void *src_ptr, size_t elem_size,
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
 * Name:  Clear_Shared_Ptrs
 *   Helper function to clear/reset shared pointer structures.
 *
 * Shared Variables: Master_Shared_Pi, Master_Shared_Ri (volatile global)
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
static inline void __attribute__((unused)) Clear_Shared_Ptrs(void)
{
   /* Clear provider shared pointer structure */
   Master_Shared_Pi.data.ptr       = NULL;
   Master_Shared_Pi.elem_size      = 0U;
   Master_Shared_Pi.no_of_elements = 0U;
   Master_Shared_Pi.name           = Test_Interface_None;
   Master_Shared_Pi.data_type      = DATATYPE_UINT8;

   /* Clear receiver shared pointer structure */
   Master_Shared_Ri.data.ptr       = NULL;
   Master_Shared_Ri.elem_size      = 0U;
   Master_Shared_Ri.no_of_elements = 0U;
   Master_Shared_Ri.name           = Test_Interface_None;
   Master_Shared_Ri.data_type      = DATATYPE_UINT8;
}

/*===========================================================================*
 * Function Definitions
 *===========================================================================*/

/******************************************************************************
 * Name:  Is_Valid_Interface
 *   Validates interface number and initializes test result.
 *
 * Shared Variables: Master_Res, last_interface_number (static)
 *
 * Parameters: interface_number - Interface number to validate
 *
 * Return Value: Test result status (TEST_PASSED, TEST_FAILED, TEST_INTERFACE_INVALID, TEST_NOT_PERFORMED)
 *
 * Design Information:
 *  - Uses DCS_X-macro expansion to validate against INTERFACE_ENUM_LIST
 *  - Initializes Master_Res on new interface (TEST_PASSED)
 *  - Marks invalid interface with TEST_INTERFACE_INVALID result
 *  - Prevents re-initialization on duplicate interface calls
 *  - Returns result status for caller verification
 *
 *  Change References:
 *  - Initial implementation
 *
 ******************************************************************************/
static SIT_Test_Result_T __attribute__((unused)) Is_Valid_Interface(uint32_t interface_number)
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
      Master_Res            = TEST_INTERFACE_INVALID;
      last_interface_number = interface_number;
      Clear_Shared_Ptrs();
   }
   else if (((last_interface_number != interface_number) || (last_stub_value != Master_Stub_Val)) && (interface_number != 0U))
   {
      /* New interface OR new stub value - marks a new test, reset everything */
      last_interface_number     = interface_number;
      last_stub_value           = Master_Stub_Val;
      Master_Res                = TEST_PASSED;
      Master_Prov_Stub          = false; /* Reset provider stub flag for new test */
      Master_Prov_Stub_From_DSP = false; /* Reset DSP provider stub validation flag for new test */
      Clear_Shared_Ptrs();
   }
   else
   {
      /* Same interface and stub value - keep existing result and stub flags (sticky failure) */
   }

   return Master_Res;
}

/*===========================================================================*
 * IPC Transfer Functions - Transfer test data between R52/Master and BBE32/DSP cores via IPC
 *===========================================================================*/

/******************************************************************************
 * Name:  SIT_IPC_Transfer_M2D_Send
 *   Send test inputs from R52 to BBE32 via M2D IPC buffer.
 *
 * Shared Variables: Test_Iface_Num, Stub_Val,
 *                   Stub_Len, Master_Res
 *
 * Parameters: m2d_payload_ptr - Pointer to M2D payload structure
 *
 * Return Value: none
 *
 * Design Information:
 *  - Called from dsp_setup.c before M2D header update
 *
 *  Change References:
 *  - Initial implementation
 *
 ******************************************************************************/
void SIT_IPC_Transfer_M2D_Send(M2D_Payload_T *m2d_payload_ptr)
{
   if (m2d_payload_ptr != NULL)
   {
      Master_Test_Iface_Num = Test_Iface_Num;
      Master_Stub_Val       = Stub_Val;
      Master_Stub_Len       = Stub_Len;

      m2d_payload_ptr->sit_data.test_interface_number        = Master_Test_Iface_Num;
      m2d_payload_ptr->sit_data.stub_value                   = Master_Stub_Val;
      m2d_payload_ptr->sit_data.no_of_elements_in_stub_array = Master_Stub_Len;
      m2d_payload_ptr->sit_data.stub_success                 = Master_Prov_Stub;

      Master_Final_Res = Master_Res;
   }
}

/******************************************************************************
 * Name:  SIT_IPC_Transfer_D2M_Receive
 *   Receive BBE32 result from D2M IPC buffer.
 *
 * Shared Variables: DSP_Final_Res
 *
 * Parameters: d2m_payload_ptr - Pointer to D2M payload structure
 *
 * Return Value: none
 *
 * Design Information:
 *  - Called from dsp_setup.c when DSP_RANGE_PROCESSING_COMPLETE received
 *
 *  Change References:
 *  - Initial implementation
 *
 ******************************************************************************/
void SIT_IPC_Transfer_D2M_Receive(const D2M_Payload_T *d2m_payload_ptr)
{
   if (d2m_payload_ptr != NULL)
   {
      DSP_Final_Res             = d2m_payload_ptr->sit_data.test_result;
      Master_Prov_Stub_From_DSP = d2m_payload_ptr->sit_data.stub_success;
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
static void __attribute__((unused)) Stub_Scalar_Values(void *dstb_ptr, DataType_T data_type, double stub_value)
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
static void __attribute__((unused))
Stub_1D_Array_Values(void *dstb_ptr, DataType_T data_type, double stub_value, uint32_t num_elements)
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
static void __attribute__((unused))
Stub_3D_Array_Values(void *dstb_ptr, DataType_T data_type, double stub_value, uint32_t dim1, uint32_t dim2, uint32_t dim3)
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
static bool __attribute__((unused)) Validate_Scalar_Values(const void *dvld_ptr, DataType_T data_type, double expected_value)
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
static bool __attribute__((unused))
Validate_1D_Array_Values(const void *dvld_ptr, DataType_T data_type, double expected_value, uint32_t num_elements)
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
static bool __attribute__((used)) Validate_3D_Array_Values(const void *dvld_ptr, DataType_T data_type, double expected_value,
                                                           uint32_t dim1, uint32_t dim2, uint32_t dim3)
{
   (void)dim2;
   (void)dim3;
   return Validate_1D_Array_Values(dvld_ptr, data_type, expected_value, dim1);
}

   /*===========================================================================*
    * Module-Specific Stub and Validate Functions - Angle Finding
    *===========================================================================*/
   #if defined(Anglefinding_IT)
/******************************************************************************
 * Name:  SIT_M2D_Onetime_Provider
 *   Provider stub function - injects test values into M2D onetime message.
 *
 * Shared Variables: Master_Stub_Len, Master_Stub_Val,
 *                   Master_Test_Iface_Num
 *
 * Parameters: msg_ptr - Pointer to M2D_One_Time_Msg_T buffer
 *
 * Return Value: none
 *
 * Design Information:
 *  - Called at end of DSP_Processing_Onetime_Init() in dsp_setup.c
 *
 *  Change References:
 *  - Initial implementation
 *
 ******************************************************************************/
void SIT_M2D_Onetime_Provider(M2D_One_Time_Msg_T *msg_ptr)
{
   Master_Stub_Len       = Stub_Len;
   Master_Stub_Val       = Stub_Val;
   Master_Test_Iface_Num = Test_Iface_Num;

   switch (Master_Test_Iface_Num)
   {
      case Ri_radar_position: /* WI-362359 */
      {
         bool stub_validation_result;
         Stub_Scalar_Values(&msg_ptr->radar_position, DATATYPE_UINT8, Master_Stub_Val);
         Set_Shared_Ptr(&Master_Shared_Pi, &msg_ptr->radar_position, sizeof(uint8_t), 1, Ri_radar_position, DATATYPE_UINT8);
         stub_validation_result = Validate_Scalar_Values(&msg_ptr->radar_position, DATATYPE_UINT8, Master_Stub_Val);
         Master_Prov_Stub       = stub_validation_result;
      }
      break;

      default:
         break;
   }
}

/******************************************************************************
 * Name:  SIT_M2D_Perlook_Provider
 *   Provider for M2D per-look message.
 *
 * Shared Variables: Master_Stub_Len, Master_Stub_Val,
 *                   Master_Test_Iface_Num
 *
 * Parameters: m2d_payload_ptr - Pointer to M2D payload buffer
 *
 * Return Value: none
 *
 * Design Information:
 *  - Called at each look during runtime processing
 *
 *  Change References:
 *  - Initial implementation
 *
 ******************************************************************************/
void SIT_M2D_Perlook_Provider(M2D_Payload_T *m2d_payload_ptr)
{
   Master_Stub_Len       = Stub_Len;
   Master_Stub_Val       = Stub_Val;
   Master_Test_Iface_Num = Test_Iface_Num;

   if (m2d_payload_ptr != NULL)
   {
      switch (Master_Test_Iface_Num)
      {
         case Ri_host_vehicle_speed: /* WI-362349 */
         {
            bool stub_validation_result;
            Stub_Scalar_Values(&m2d_payload_ptr->veh_data.vse_output.raw_speed_mps, DATATYPE_FLOAT32, Master_Stub_Val);
            Set_Shared_Ptr(&Master_Shared_Pi, &m2d_payload_ptr->veh_data.vse_output.raw_speed_mps, sizeof(float), 1,
                           Ri_host_vehicle_speed, DATATYPE_FLOAT32);
            stub_validation_result =
               Validate_Scalar_Values(&m2d_payload_ptr->veh_data.vse_output.raw_speed_mps, DATATYPE_FLOAT32, Master_Stub_Val);
            Master_Prov_Stub = stub_validation_result;
         }
         break;

         default:
            break;
      }
   }
}
   #endif /* Anglefinding_IT */

/******************************************************************************
 * Name:  SIT_Calibration_Data_Provider
 *   Provider for SMC/calibration data stub injection.
 *   Stubs SMC AF calibration (FLR8/SRR8P), downselection params,
 *   RCS rolloff limits, sensor mounting, and unambiguous velocity
 *   into calibration structures during Validate_Load_All_Calib_Data().
 *
 * Shared Variables: Master_Stub_Len, Master_Stub_Val,
 *                   Master_Test_Iface_Num, Master_Res
 *
 * Parameters: none (operates on global SMC_Cal_Data_Ptr)
 *
 * Return Value: none
 *
 * Design Information:
 *  - Called from Validate_Load_All_Calib_Data() in CalibHandler via
 *    SIT_Calibration_Data() macro hook
 *  - Dwell timestamp fields do not exist in Gen8 Look_Data_T → TEST_SKIPPED
 *  - Downselection fields not present in SMC Downselection_Cal_T → TEST_SKIPPED
 *  - SMC data is shared with BBE32 via SRAM address (not copied via IPC)
 *
 *  Change References:
 *  - Initial implementation
 *
 ******************************************************************************/
void SIT_Calibration_Data_Provider(void)
{
   __attribute__((unused)) uint32_t num_elem;
   __attribute__((unused)) SMC_Cal_T *p_smc = Get_SMC_Cal_Data();
   __attribute__((unused)) USC_Cal_T *p_usc = Get_USC_Cal_Data();

   Master_Stub_Len       = Stub_Len;
   Master_Stub_Val       = Stub_Val;
   Master_Test_Iface_Num = Test_Iface_Num;
   num_elem              = Master_Stub_Len;

   switch (Master_Test_Iface_Num)
   {
   #if defined(Anglefinding_IT)
      #if 0
         /*============================================================*
          * USC AF Calibration Interfaces
          * Stubs into USC_AF_Cal sub-section of USC_Cal_Data
          *============================================================*/
      case Ri_usc_af_tx_cal_matrix: /* WI-294040001 */
      {
         bool stub_validation_result;
         /* USC_AF_Cal_T has k_calmat1_ctx[4][8] float array = 32 floats = 16 creal32_T */
         uint32_t max_elem = 16U; /* 4x8 / 2 = 16 complex values */
         if (num_elem > max_elem)
         {
            num_elem = max_elem;
         }
         /* Stub as float array, will be interpreted as creal32_T on BBE32 side */
         Stub_1D_Array_Values((float *)p_usc->USC_AF_Cal.k_calmat1_ctx, DATATYPE_FLOAT32, Master_Stub_Val, num_elem * 2U);
         Set_Shared_Ptr(&Master_Shared_Pi, (float *)p_usc->USC_AF_Cal.k_calmat1_ctx, sizeof(DATATYPE_FLOAT32), num_elem,
                        Ri_usc_af_tx_cal_matrix, DATATYPE_FLOAT32);
         stub_validation_result =
            Validate_1D_Array_Values((float *)p_usc->USC_AF_Cal.k_calmat1_ctx, DATATYPE_FLOAT32, Master_Stub_Val, num_elem * 2U);
         Master_Prov_Stub = stub_validation_result;
      }
      break;

      case Ri_usc_af_rx_cal_matrix: /* WI-294040002 */
      {
         bool stub_validation_result;
         /* USC_AF_Cal_T has k_calmat1_crx[8][16] float array = 128 floats = 64 creal32_T */
         uint32_t max_elem = 64U; /* 8x16 / 2 = 64 complex values */
         if (num_elem > max_elem)
         {
            num_elem = max_elem;
         }
         /* Stub as float array, will be interpreted as creal32_T on BBE32 side */
         Stub_1D_Array_Values((float *)p_usc->USC_AF_Cal.k_calmat1_crx, DATATYPE_FLOAT32, Master_Stub_Val, num_elem * 2U);
         Set_Shared_Ptr(&Master_Shared_Pi, (float *)p_usc->USC_AF_Cal.k_calmat1_crx, sizeof(DATATYPE_FLOAT32), num_elem,
                        Ri_usc_af_rx_cal_matrix, DATATYPE_FLOAT32);
         stub_validation_result =
            Validate_1D_Array_Values((float *)p_usc->USC_AF_Cal.k_calmat1_crx, DATATYPE_FLOAT32, Master_Stub_Val, num_elem * 2U);
         Master_Prov_Stub = stub_validation_result;
      }
      break;

      case Ri_usc_af_cal_matrix: /* WI-294040003 */
      {
         bool stub_validation_result;
         /* USC_AF_Cal_T has k_calmat1_c1[32][64] float array = 2048 floats = 1024 creal32_T */
         uint32_t max_elem = 1024U; /* 32x64 / 2 = 1024 complex values */
         if (num_elem > max_elem)
         {
            num_elem = max_elem;
         }
         /* Stub as float array, will be interpreted as creal32_T on BBE32 side */
         Stub_1D_Array_Values((float *)p_usc->USC_AF_Cal.k_calmat1_c1, DATATYPE_FLOAT32, Master_Stub_Val, num_elem * 2U);
         Set_Shared_Ptr(&Master_Shared_Pi, (float *)p_usc->USC_AF_Cal.k_calmat1_c1, sizeof(DATATYPE_FLOAT32), num_elem,
                        Ri_usc_af_cal_matrix, DATATYPE_FLOAT32);
         stub_validation_result =
            Validate_1D_Array_Values((float *)p_usc->USC_AF_Cal.k_calmat1_c1, DATATYPE_FLOAT32, Master_Stub_Val, num_elem * 2U);
         Master_Prov_Stub = stub_validation_result;
      }
      break;
      #endif
      /*============================================================*
       * AF Downselection Calibration
       * Fields present in SMC Downselection_Cal_T
       *============================================================*/
      case Ri_smc_ds_enable_aa_az: /* WI-345643001 */
      {
         bool stub_validation_result;
         Stub_Scalar_Values(&p_smc->Downselection_Cal.k_ds_enable_aa_az, DATATYPE_UINT8, Master_Stub_Val);
         Set_Shared_Ptr(&Master_Shared_Pi, &p_smc->Downselection_Cal.k_ds_enable_aa_az, sizeof(uint8_t), 1, Ri_smc_ds_enable_aa_az,
                        DATATYPE_UINT8);
         stub_validation_result =
            Validate_Scalar_Values(&p_smc->Downselection_Cal.k_ds_enable_aa_az, DATATYPE_UINT8, Master_Stub_Val);
         Master_Prov_Stub = stub_validation_result;
      }
      break;

      case Ri_smc_ds_enable_aa_el: /* WI-345643002 */
      {
         bool stub_validation_result;
         Stub_Scalar_Values(&p_smc->Downselection_Cal.k_ds_enable_aa_el, DATATYPE_UINT8, Master_Stub_Val);
         Set_Shared_Ptr(&Master_Shared_Pi, &p_smc->Downselection_Cal.k_ds_enable_aa_el, sizeof(uint8_t), 1, Ri_smc_ds_enable_aa_el,
                        DATATYPE_UINT8);
         stub_validation_result =
            Validate_Scalar_Values(&p_smc->Downselection_Cal.k_ds_enable_aa_el, DATATYPE_UINT8, Master_Stub_Val);
         Master_Prov_Stub = stub_validation_result;
      }
      break;

      case Ri_smc_ds_enable_az_proj: /* WI-345643003 */
      {
         bool stub_validation_result;
         Stub_Scalar_Values(&p_smc->Downselection_Cal.k_ds_enable_az_proj, DATATYPE_UINT8, Master_Stub_Val);
         Set_Shared_Ptr(&Master_Shared_Pi, &p_smc->Downselection_Cal.k_ds_enable_az_proj, sizeof(uint8_t), 1,
                        Ri_smc_ds_enable_az_proj, DATATYPE_UINT8);
         stub_validation_result =
            Validate_Scalar_Values(&p_smc->Downselection_Cal.k_ds_enable_az_proj, DATATYPE_UINT8, Master_Stub_Val);
         Master_Prov_Stub = stub_validation_result;
      }
      break;

      case Ri_smc_ds_enable_el_proj: /* WI-345643004 */
      {
         bool stub_validation_result;
         Stub_Scalar_Values(&p_smc->Downselection_Cal.k_ds_enable_el_proj, DATATYPE_UINT8, Master_Stub_Val);
         Set_Shared_Ptr(&Master_Shared_Pi, &p_smc->Downselection_Cal.k_ds_enable_el_proj, sizeof(uint8_t), 1,
                        Ri_smc_ds_enable_el_proj, DATATYPE_UINT8);
         stub_validation_result =
            Validate_Scalar_Values(&p_smc->Downselection_Cal.k_ds_enable_el_proj, DATATYPE_UINT8, Master_Stub_Val);
         Master_Prov_Stub = stub_validation_result;
      }
      break;

      case Ri_smc_ds_num_unfolding_intervals: /* WI-345643005 */
      {
         bool stub_validation_result;
         Stub_Scalar_Values(&p_smc->Downselection_Cal.k_ds_num_unfolding_intervals, DATATYPE_UINT8, Master_Stub_Val);
         Set_Shared_Ptr(&Master_Shared_Pi, &p_smc->Downselection_Cal.k_ds_num_unfolding_intervals, sizeof(uint8_t), 1,
                        Ri_smc_ds_num_unfolding_intervals, DATATYPE_UINT8);
         stub_validation_result =
            Validate_Scalar_Values(&p_smc->Downselection_Cal.k_ds_num_unfolding_intervals, DATATYPE_UINT8, Master_Stub_Val);
         Master_Prov_Stub = stub_validation_result;
      }
      break;

      case Ri_smc_ds_score_selection: /* WI-345643006 */
      {
         bool stub_validation_result;
         Stub_Scalar_Values(&p_smc->Downselection_Cal.k_ds_score_selection, DATATYPE_UINT8, Master_Stub_Val);
         Set_Shared_Ptr(&Master_Shared_Pi, &p_smc->Downselection_Cal.k_ds_score_selection, sizeof(uint8_t), 1,
                        Ri_smc_ds_score_selection, DATATYPE_UINT8);
         stub_validation_result =
            Validate_Scalar_Values(&p_smc->Downselection_Cal.k_ds_score_selection, DATATYPE_UINT8, Master_Stub_Val);
         Master_Prov_Stub = stub_validation_result;
      }
      break;

      case Ri_smc_ds_moving_thold: /* WI-345643007 */
      {
         bool stub_validation_result;
         Stub_Scalar_Values(&p_smc->Downselection_Cal.k_ds_moving_thold, DATATYPE_FLOAT32, Master_Stub_Val);
         Set_Shared_Ptr(&Master_Shared_Pi, &p_smc->Downselection_Cal.k_ds_moving_thold, sizeof(float), 1, Ri_smc_ds_moving_thold,
                        DATATYPE_FLOAT32);
         stub_validation_result =
            Validate_Scalar_Values(&p_smc->Downselection_Cal.k_ds_moving_thold, DATATYPE_FLOAT32, Master_Stub_Val);
         Master_Prov_Stub = stub_validation_result;
      }
      break;

      case Ri_smc_ds_flag_enable_ds: /* WI-345643008 */
      {
         bool stub_validation_result;
         Stub_Scalar_Values(&p_smc->Downselection_Cal.k_enable_downselection, DATATYPE_UINT8, Master_Stub_Val);
         Set_Shared_Ptr(&Master_Shared_Pi, &p_smc->Downselection_Cal.k_enable_downselection, sizeof(uint8_t), 1,
                        Ri_smc_ds_flag_enable_ds, DATATYPE_UINT8);
         stub_validation_result =
            Validate_Scalar_Values(&p_smc->Downselection_Cal.k_enable_downselection, DATATYPE_UINT8, Master_Stub_Val);
         Master_Prov_Stub = stub_validation_result;
      }
      break;

      case Ri_smc_ds_max_target_reports: /* WI-345643009 */
      {
         bool stub_validation_result;
         Stub_Scalar_Values(&p_smc->Downselection_Cal.k_ds_max_target_reports, DATATYPE_UINT32, Master_Stub_Val);
         Set_Shared_Ptr(&Master_Shared_Pi, &p_smc->Downselection_Cal.k_ds_max_target_reports, sizeof(uint32_t), 1,
                        Ri_smc_ds_max_target_reports, DATATYPE_UINT32);
         stub_validation_result =
            Validate_Scalar_Values(&p_smc->Downselection_Cal.k_ds_max_target_reports, DATATYPE_UINT32, Master_Stub_Val);
         Master_Prov_Stub = stub_validation_result;
      }
      break;
      #if 0
      /*============================================================*
       * RCS Rolloff Limit Interfaces
       * Stubs into SMC RCS_Cal sub-section (s2p13_T = int16_t)
       *============================================================*/
      case Ri_k_rcs_az_rolloff_limit_str_0: /* WI-399439001 */
      {
         bool stub_validation_result;
         Stub_Scalar_Values(&p_smc->RCS_Cal.k_rcs_az_rolloff_limit[0], DATATYPE_INT16, Master_Stub_Val);
         Set_Shared_Ptr(&Master_Shared_Pi, &p_smc->RCS_Cal.k_rcs_az_rolloff_limit[0], sizeof(int16_t), 1,
                        Ri_k_rcs_az_rolloff_limit_str_0, DATATYPE_INT16);
         stub_validation_result =
            Validate_Scalar_Values(&p_smc->RCS_Cal.k_rcs_az_rolloff_limit[0], DATATYPE_INT16, Master_Stub_Val);
         Master_Prov_Stub = stub_validation_result;
      }
      break;

      case Ri_k_rcs_az_rolloff_limit_str_1: /* WI-399439002 */
      {
         bool stub_validation_result;
         Stub_Scalar_Values(&p_smc->RCS_Cal.k_rcs_az_rolloff_limit[1], DATATYPE_INT16, Master_Stub_Val);
         Set_Shared_Ptr(&Master_Shared_Pi, &p_smc->RCS_Cal.k_rcs_az_rolloff_limit[1], sizeof(int16_t), 1,
                        Ri_k_rcs_az_rolloff_limit_str_1, DATATYPE_INT16);
         stub_validation_result =
            Validate_Scalar_Values(&p_smc->RCS_Cal.k_rcs_az_rolloff_limit[1], DATATYPE_INT16, Master_Stub_Val);
         Master_Prov_Stub = stub_validation_result;
      }
      break;

      case Ri_k_rcs_el_rolloff_limit_str_0: /* WI-399439003 */
      {
         bool stub_validation_result;
         Stub_Scalar_Values(&p_smc->RCS_Cal.k_rcs_el_rolloff_limit[0], DATATYPE_INT16, Master_Stub_Val);
         Set_Shared_Ptr(&Master_Shared_Pi, &p_smc->RCS_Cal.k_rcs_el_rolloff_limit[0], sizeof(int16_t), 1,
                        Ri_k_rcs_el_rolloff_limit_str_0, DATATYPE_INT16);
         stub_validation_result =
            Validate_Scalar_Values(&p_smc->RCS_Cal.k_rcs_el_rolloff_limit[0], DATATYPE_INT16, Master_Stub_Val);
         Master_Prov_Stub = stub_validation_result;
      }
      break;

      case Ri_k_rcs_el_rolloff_limit_str_1: /* WI-399439004 */
      {
         bool stub_validation_result;
         Stub_Scalar_Values(&p_smc->RCS_Cal.k_rcs_el_rolloff_limit[1], DATATYPE_INT16, Master_Stub_Val);
         Set_Shared_Ptr(&Master_Shared_Pi, &p_smc->RCS_Cal.k_rcs_el_rolloff_limit[1], sizeof(int16_t), 1,
                        Ri_k_rcs_el_rolloff_limit_str_1, DATATYPE_INT16);
         stub_validation_result =
            Validate_Scalar_Values(&p_smc->RCS_Cal.k_rcs_el_rolloff_limit[1], DATATYPE_INT16, Master_Stub_Val);
         Master_Prov_Stub = stub_validation_result;
      }
      break;
      #endif
      /*============================================================*
       * Sensor Mounting Position Interfaces
       * Stubs into Vehicle_Configuration_Cal sub-section
       * Arrays of 14 (one per sensor position) - stub element[0]
       *============================================================*/
      case Ri_sensor_mount_pos_x: /* WI-294037001 */
      {
         bool stub_validation_result;
         if (num_elem > 14U)
         {
            num_elem = 14U;
         }
         Stub_1D_Array_Values(p_smc->Vehicle_Configuration_Cal.k_sensor_mount_pos_x_list, DATATYPE_FLOAT32, Master_Stub_Val,
                              num_elem);
         Set_Shared_Ptr(&Master_Shared_Pi, p_smc->Vehicle_Configuration_Cal.k_sensor_mount_pos_x_list, sizeof(float), num_elem,
                        Ri_sensor_mount_pos_x, DATATYPE_FLOAT32);
         stub_validation_result = Validate_1D_Array_Values(p_smc->Vehicle_Configuration_Cal.k_sensor_mount_pos_x_list,
                                                           DATATYPE_FLOAT32, Master_Stub_Val, num_elem);
         Master_Prov_Stub       = stub_validation_result;
      }
      break;

      case Ri_sensor_mount_pos_y: /* WI-294037002 */
      {
         bool stub_validation_result;
         if (num_elem > 14U)
         {
            num_elem = 14U;
         }
         Stub_1D_Array_Values(p_smc->Vehicle_Configuration_Cal.k_sensor_mount_pos_y_list, DATATYPE_FLOAT32, Master_Stub_Val,
                              num_elem);
         Set_Shared_Ptr(&Master_Shared_Pi, p_smc->Vehicle_Configuration_Cal.k_sensor_mount_pos_y_list, sizeof(float), num_elem,
                        Ri_sensor_mount_pos_y, DATATYPE_FLOAT32);
         stub_validation_result = Validate_1D_Array_Values(p_smc->Vehicle_Configuration_Cal.k_sensor_mount_pos_y_list,
                                                           DATATYPE_FLOAT32, Master_Stub_Val, num_elem);
         Master_Prov_Stub       = stub_validation_result;
      }
      break;

      case Ri_sensor_mount_pos_z: /* WI-294037003 */
      {
         bool stub_validation_result;
         if (num_elem > 14U)
         {
            num_elem = 14U;
         }
         Stub_1D_Array_Values(p_smc->Vehicle_Configuration_Cal.k_sensor_mount_pos_z_list, DATATYPE_FLOAT32, Master_Stub_Val,
                              num_elem);
         Set_Shared_Ptr(&Master_Shared_Pi, p_smc->Vehicle_Configuration_Cal.k_sensor_mount_pos_z_list, sizeof(float), num_elem,
                        Ri_sensor_mount_pos_z, DATATYPE_FLOAT32);
         stub_validation_result = Validate_1D_Array_Values(p_smc->Vehicle_Configuration_Cal.k_sensor_mount_pos_z_list,
                                                           DATATYPE_FLOAT32, Master_Stub_Val, num_elem);
         Master_Prov_Stub       = stub_validation_result;
      }
      break;

      case Ri_sensor_mount_ornt_roll: /* WI-294037004 */
      {
         bool stub_validation_result;
         if (num_elem > 14U)
         {
            num_elem = 14U;
         }
         Stub_1D_Array_Values(p_smc->Vehicle_Configuration_Cal.k_sensor_mount_ornt_roll_list, DATATYPE_FLOAT32, Master_Stub_Val,
                              num_elem);
         Set_Shared_Ptr(&Master_Shared_Pi, p_smc->Vehicle_Configuration_Cal.k_sensor_mount_ornt_roll_list, sizeof(float), num_elem,
                        Ri_sensor_mount_ornt_roll, DATATYPE_FLOAT32);
         stub_validation_result = Validate_1D_Array_Values(p_smc->Vehicle_Configuration_Cal.k_sensor_mount_ornt_roll_list,
                                                           DATATYPE_FLOAT32, Master_Stub_Val, num_elem);
         Master_Prov_Stub       = stub_validation_result;
      }
      break;

      case Ri_sensor_mount_ornt_pitch: /* WI-294037005 */
      {
         bool stub_validation_result;
         if (num_elem > 14U)
         {
            num_elem = 14U;
         }
         Stub_1D_Array_Values(p_smc->Vehicle_Configuration_Cal.k_sensor_mount_ornt_pitch_list, DATATYPE_FLOAT32, Master_Stub_Val,
                              num_elem);
         Set_Shared_Ptr(&Master_Shared_Pi, p_smc->Vehicle_Configuration_Cal.k_sensor_mount_ornt_pitch_list, sizeof(float),
                        num_elem, Ri_sensor_mount_ornt_pitch, DATATYPE_FLOAT32);
         stub_validation_result = Validate_1D_Array_Values(p_smc->Vehicle_Configuration_Cal.k_sensor_mount_ornt_pitch_list,
                                                           DATATYPE_FLOAT32, Master_Stub_Val, num_elem);
         Master_Prov_Stub       = stub_validation_result;
      }
      break;

      case Ri_sensor_mount_ornt_yaw: /* WI-294037006 */
      {
         bool stub_validation_result;
         if (num_elem > 14U)
         {
            num_elem = 14U;
         }
         Stub_1D_Array_Values(p_smc->Vehicle_Configuration_Cal.k_sensor_mount_ornt_yaw_list, DATATYPE_FLOAT32, Master_Stub_Val,
                              num_elem);
         Set_Shared_Ptr(&Master_Shared_Pi, p_smc->Vehicle_Configuration_Cal.k_sensor_mount_ornt_yaw_list, sizeof(float), num_elem,
                        Ri_sensor_mount_ornt_yaw, DATATYPE_FLOAT32);
         stub_validation_result = Validate_1D_Array_Values(p_smc->Vehicle_Configuration_Cal.k_sensor_mount_ornt_yaw_list,
                                                           DATATYPE_FLOAT32, Master_Stub_Val, num_elem);
         Master_Prov_Stub       = stub_validation_result;
      }
      break;

      /*============================================================*
       * Unambiguous Velocity Interface
       * Stubs into SMC Secondpass_Threshold_Cal sub-section
       * k_vua[4] is s10p21_T (int32_t), one per look
       *============================================================*/
      case Ri_unambiguous_velocity: /* WI-399436 */
      {
         bool stub_validation_result = false;
         if (num_elem > 4U)
         {
            num_elem = 4U;
         }
         if (p_smc != NULL)
         {
            // Stub_1D_Array_Values(p_smc->Secondpass_Threshold_Cal.k_vua, DATATYPE_INT32, Master_Stub_Val, num_elem);
            // Set_Shared_Ptr(&Master_Shared_Pi, p_smc->Secondpass_Threshold_Cal.k_vua, sizeof(int32_t), num_elem,
            //                Ri_unambiguous_velocity, DATATYPE_INT32);
            // stub_validation_result = Validate_1D_Array_Values(p_smc->Secondpass_Threshold_Cal.k_vua, DATATYPE_INT32,
            //                                                    Master_Stub_Val, num_elem);
         }

         Master_Prov_Stub = stub_validation_result;
      }
      break;
   #endif /* Anglefinding_IT */
      default:
         break;
   }
}

   #if defined(Radar_capability_IT)

void SIT_MMIC_ONCHIP_DATA_Provider(M2D_Msg_T *m2d_msg_ptr)
{
   Master_Stub_Len       = Stub_Len;
   Master_Stub_Val       = Stub_Val;
   Master_Test_Iface_Num = Test_Iface_Num;

   if (m2d_msg_ptr != NULL)
   {
      switch (Master_Test_Iface_Num)
      {
         case Ri_avg_mmic_onchip_temp: /* WI-370545 */
         {
            bool stub_validation_result;
            Stub_Scalar_Values(&m2d_msg_ptr->payload.avg_mmic_onchip_temp, DATATYPE_INT16, Master_Stub_Val);
            Set_Shared_Ptr(&Master_Shared_Pi, &m2d_msg_ptr->payload.avg_mmic_onchip_temp, sizeof(int16_t), 1,
                           Ri_avg_mmic_onchip_temp, DATATYPE_INT16);
            /* Validate that stub was successful */
            stub_validation_result =
               Validate_Scalar_Values(&m2d_msg_ptr->payload.avg_mmic_onchip_temp, DATATYPE_INT16, Master_Stub_Val);
            Master_Prov_Stub = stub_validation_result;
         }
         break;

         case Ri_host_speed: /* WI-370537 - already stubbed in M2D per-look provider, but stub here as well since value is also
                                sent in on-chip message */
         {
            bool stub_validation_result;
            Stub_Scalar_Values(
               &m2d_msg_ptr->payload.veh_data.veh_raw_data[m2d_msg_ptr->payload.veh_data.latest_raw_index].ego_vehicle_speed,
               DATATYPE_FLOAT32, Master_Stub_Val);
            Set_Shared_Ptr(
               &Master_Shared_Pi,
               &m2d_msg_ptr->payload.veh_data.veh_raw_data[m2d_msg_ptr->payload.veh_data.latest_raw_index].ego_vehicle_speed,
               sizeof(float32_t), 1, Ri_host_speed, DATATYPE_FLOAT32);
            /* Validate that stub was successful */
            stub_validation_result = Validate_Scalar_Values(
               &m2d_msg_ptr->payload.veh_data.veh_raw_data[m2d_msg_ptr->payload.veh_data.latest_raw_index].ego_vehicle_speed,
               DATATYPE_FLOAT32, Master_Stub_Val);
            Master_Prov_Stub = stub_validation_result;
         }
         break;

         case Ri_host_yawrate: /* WI-370539 */
         {
            bool stub_validation_result;
            Stub_Scalar_Values(
               &m2d_msg_ptr->payload.veh_data.veh_raw_data[m2d_msg_ptr->payload.veh_data.latest_raw_index].ego_yaw_rate,
               DATATYPE_FLOAT32, Master_Stub_Val);
            Set_Shared_Ptr(
               &Master_Shared_Pi,
               &m2d_msg_ptr->payload.veh_data.veh_raw_data[m2d_msg_ptr->payload.veh_data.latest_raw_index].ego_yaw_rate,
               sizeof(float32_t), 1, Ri_host_yawrate, DATATYPE_FLOAT32);
            /* Validate that stub was successful */
            stub_validation_result = Validate_Scalar_Values(
               &m2d_msg_ptr->payload.veh_data.veh_raw_data[m2d_msg_ptr->payload.veh_data.latest_raw_index].ego_yaw_rate,
               DATATYPE_FLOAT32, Master_Stub_Val);
            Master_Prov_Stub = stub_validation_result;
         }
         break;

         case Ri_look_data_0: /*WI-370549001*/
         {
            bool stub_validation_result;
            /* look_data_0 = look_id on BBE32, which comes from M2D look_Info.look_type */
            Stub_Scalar_Values(&m2d_msg_ptr->payload.look_Info.look_type, DATATYPE_UINT16, Master_Stub_Val);
            Set_Shared_Ptr(&Master_Shared_Pi, &m2d_msg_ptr->payload.look_Info.look_type, sizeof(uint16_t), 1, Ri_look_data_0,
                           DATATYPE_UINT16);
            /* Validate that stub was successful */
            stub_validation_result =
               Validate_Scalar_Values(&m2d_msg_ptr->payload.look_Info.look_type, DATATYPE_UINT16, Master_Stub_Val);
            Master_Prov_Stub = stub_validation_result;
         }
         break;

         case Ri_look_data_1: /*WI-370549002*/
         {
            bool stub_validation_result;
            /* look_data_1 = scan_index on BBE32, which comes from M2D look_Info.scan_index */
            Stub_Scalar_Values(&m2d_msg_ptr->payload.look_Info.scan_index, DATATYPE_UINT16, Master_Stub_Val);
            Set_Shared_Ptr(&Master_Shared_Pi, &m2d_msg_ptr->payload.look_Info.scan_index, sizeof(uint16_t), 1, Ri_look_data_1,
                           DATATYPE_UINT16);
            /* Validate that stub was successful */
            stub_validation_result =
               Validate_Scalar_Values(&m2d_msg_ptr->payload.look_Info.scan_index, DATATYPE_UINT16, Master_Stub_Val);
            Master_Prov_Stub = stub_validation_result;
         }
         break;

         default:
            break;
      }
   }
}
   #endif /* Radar_capability_IT */

#endif /* Integration_Testing */

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
