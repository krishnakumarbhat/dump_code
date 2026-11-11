/*===========================================================================*
 * Header Files
 *===========================================================================*/
#include "dd_mipi.h"
#include "Std_Types.h"
#include "dd_mmic.h"
#include "mipi_interrupt.h"
#include <string.h>
/*===========================================================================*
 * Local Preprocessor defined Constants
 *===========================================================================*/
#define NUM_OF_VECTOR_SAMPLES_PER_CHANNEL 4U
#define NUM_OF_VECTOR_SAMPLES             (MIPI_MAX_INPUT_CHANNELS * NUM_OF_VECTOR_SAMPLES_PER_CHANNEL)
#ifndef UNIT_TEST
   #define MIPI_OCP_MEMORY   (volatile void *)OCP_MEM
   #define MIPI_OCP_MEM_SIZE sizeof(OCP_MEM)
#else
   #define MIPI_OCP_MEMORY   (volatile uint16x16 *)ptrMIPI_OCP_MEM
   #define MIPI_OCP_MEM_SIZE sizeof(MIPI_OCP_MEM_SFRS_t)
#endif

/*===========================================================================*
 * Exported Const Object Definitions
 *===========================================================================*/

/*===========================================================================*
 * Local Function Prototypes
 *===========================================================================*/

/*===========================================================================*
 * Local Datatypes and Structures
 *===========================================================================*/
typedef __attribute__((ext_vector_type(NUM_OF_VECTOR_SAMPLES))) uint16_t uint16x16;
typedef __attribute__((aligned(32))) union Mipi_4ch_4samples_Vector_Tag
{ /* polyspace MISRA-C3:19.2 "used for the write re" */
   int16_t samples_data[NUM_OF_VECTOR_SAMPLES];
   uint16x16 vec_sample_data; /* vector of 4 channels of 4 samples of MIPI output data (256 bits) */
} Mipi_4ch_4samples_Vector_T;

/*===========================================================================*
 * Global Data
 *===========================================================================*/
volatile MIPI_OCP_MEM_SFRS_t *const ptrMIPI_OCP_MEM     = PTR_MIPI_OCP_MEM;
volatile MIPI_SFRS_t *const ptrMIPI                     = PTR_MIPI;
volatile CSI_SFRS_t *const ptrCSI                       = PTR_CSI;
MIPI_FuSa_IRQ0_Faults_Union_t MIPI_FuSa_IRQ0_Mon_Status = {0};
MIPI_FuSa_IRQ1_Faults_Union_t MIPI_FuSa_IRQ1_Mon_Status = {0};
MIPI_FuSa_IRQ2_Faults_Union_t MIPI_FuSa_IRQ2_Mon_Status = {0};

/*===========================================================================*
 * Local Data
 *===========================================================================*/
volatile bool MIPI_Initialized = false;
static MIPI_Config_T MIPI_Configuration;

static volatile MIPI_CSI2_Rx_Settings_T MIPI_CSI2_Rx_Config = {.shrtpacket_startVCId  = 0,
                                                               .shrtpacket_startDtype = 0,
                                                               .shrtpacket_endVCId    = 0,
                                                               .shrtpacket_endDtype   = 1,
                                                               .longpacket_VCId       = 0,
                                                               .longpacket_dtype      = 0x2D, // RAW14
                                                               .num_lanes             = 4};

/*===========================================================================*
 * Local Function Prototypes
 *===========================================================================*/
static inline int16_t Data_Rescale(const int16_t input_data);
static inline bool CSI2_Config(uint8_t data_lanes);
static inline bool MIPI_Config(const volatile MIPI_CSI2_Rx_Settings_T *mipi_csi2_rx_settings);

/*===========================================================================*
 * Local Function Definitions
 *===========================================================================*/

/**
 * @name        Data_Rescale
 * @brief       rescale ADC input 12-bit or 14-bit samples to 16-bit
 * @param[in]   input_data 12-bit or 14-bit signed fixed-point integer
 * @return      16-bit signed fixed-point integer
 */
static inline int16_t Data_Rescale(const int16_t input_data)
{
   int16_t output_data = 0;
   switch (MIPI_Configuration.data_bits_size)
   {
      case MIPI_INPUT_DATA_0x0_14_BITS:
         /*!< rescale input from 14 bits to 16 bits */
         output_data = (int16_t)(uint16_t)((((uint16_t)input_data) & 0x3FFFU /* 14 bits */) * 4U);
         break;
      case MIPI_INPUT_DATA_0x1_12_BITS:
         /*!< rescale input from 12 bits to 16 bits */
         output_data = (int16_t)(uint16_t)((((uint16_t)input_data) & 0x0FFFU /* 12 bits */) * 16U);
         break;
      default:
         output_data = input_data; /* bypass rescaling */
         break;
   }
   return output_data;
}

/*===========================================================================*\
 * FUNCTION: CSI2_Config
 *===========================================================================
 * RETURN VALUE:
 *    bool - true when CSI2 lane configuration completes successfully
 *
 * PARAMETERS:
 *    uint8_t data_lanes - number of CSI2 data lanes to enable
 * --------------------------------------------------------------------------
 * ABSTRACT:
 *    Program lane selection and enablement within the CSI2 controller
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
static inline bool CSI2_Config(uint8_t data_lanes)
{
   bool ret_val = false;
   switch (data_lanes)
   {
      case 1:
      {
         /* Not implemented */
         break;
      }
      case 2:
      {
         /* Not implemented */
         break;
      }
      case 3:
      {
         /* Not implemented */
         break;
      }
      case 4:
      {
         ptrCSI->CFG_MODE.f.CFG_NUM_LANES      = data_lanes;
         ptrCSI->LANE_0.f.CFG_RX_LANE0_SEL     = 0;
         ptrCSI->LANE_1.f.CFG_RX_LANE1_SEL     = 1;
         ptrCSI->LANE_2.f.CFG_RX_LANE2_SEL     = 2;
         ptrCSI->LANE_3.f.CFG_RX_LANE3_SEL     = 3;
         ptrCSI->LANE_0.f.CFG_DATA_LANE_EN_LN0 = 1;
         ptrCSI->LANE_1.f.CFG_DATA_LANE_EN_LN1 = 1;
         ptrCSI->LANE_2.f.CFG_DATA_LANE_EN_LN2 = 1;
         ptrCSI->LANE_3.f.CFG_DATA_LANE_EN_LN3 = 1;
         ptrCSI->CLOCK_LANE.f.CFG_CLK_LANE_EN  = 1;
         ret_val                               = true;
         break;
      }
      default:
      {
         ret_val = false;
         break;
      }
   }
   return ret_val;
}

/*===========================================================================*\
 * FUNCTION: MIPI_Config
 *===========================================================================
 * RETURN VALUE:
 *    bool - true when MIPI packet framing registers are set
 *
 * PARAMETERS:
 *    const volatile MIPI_CSI2_Rx_Settings_T *mipi_csi2_rx_settings - RX configuration structure
 * --------------------------------------------------------------------------
 * ABSTRACT:
 *    Configure packet headers and PHY resets for the MIPI CSI2 receiver
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
static inline bool MIPI_Config(const volatile MIPI_CSI2_Rx_Settings_T *mipi_csi2_rx_settings)
{
   bool ret_val = false;
   switch (mipi_csi2_rx_settings->num_lanes)
   {
      case 1:
      {
         break;
      }
      case 2:
      {
         break;
      }
      case 3:
      {
         break;
      }
      case 4:
      {
         ptrMIPI->CSI2_RESET.f.CSR_CSI2_RX_PHY_RESET_N                   = 1;
         ptrMIPI->CSI2_RESET.f.CSR_CSI2_RX_BYTE_CLK_LN0_RESET_N          = 1;
         ptrMIPI->CSI2_RESET.f.CSR_CSI2_RX_BYTE_CLK_LN1_RESET_N          = 1;
         ptrMIPI->CSI2_RESET.f.CSR_CSI2_RX_BYTE_CLK_LN2_RESET_N          = 1;
         ptrMIPI->CSI2_RESET.f.CSR_CSI2_RX_BYTE_CLK_LN3_RESET_N          = 1;
         ptrMIPI->CSI2_SHORT_PKT_HEADER.f.CSI2_SHORT_PKT_START_VC        = mipi_csi2_rx_settings->shrtpacket_startVCId;
         ptrMIPI->CSI2_SHORT_PKT_HEADER.f.CSI2_SHORT_PKT_START_DATA_TYPE = mipi_csi2_rx_settings->shrtpacket_startDtype;
         ptrMIPI->CSI2_SHORT_PKT_HEADER.f.CSI2_SHORT_PKT_END_VC          = mipi_csi2_rx_settings->shrtpacket_endVCId;
         ptrMIPI->CSI2_SHORT_PKT_HEADER.f.CSI2_SHORT_PKT_END_DATA_TYPE   = mipi_csi2_rx_settings->shrtpacket_endDtype;
         ptrMIPI->CSI2_LONG_PKT_HEADER.f.CSI2_LONG_PKT_VC                = mipi_csi2_rx_settings->longpacket_VCId;
         ptrMIPI->CSI2_LONG_PKT_HEADER.f.CSI2_LONG_PKT_DATA_TYPE         = mipi_csi2_rx_settings->longpacket_dtype;
#ifndef RESI_MODE_ENABLE
         ptrMIPI->CSI2_LONG_PKT_HEADER.f.CSI2_META_PKT_DATA_TYPE = 0x2A; // default raw8 value for the metadata packet type
#endif
         ptrMIPI->MIPI_CTRL_0.f.D1_PNCH            = 1;
         ptrMIPI->MIPI_CTRL_1.f.UC_PRG_RXHS_SETTLE = 16;
         ptrMIPI->MIPI_CTRL_1.f.U_PRG_RXHS_SETTLE  = 0x0A; /* 0xA 1Gbps 0x08 500 Mbps 0x06 256 Mbps*/
         ret_val                                   = true;
         break;
      }
      default:
      {
         ret_val = false;
         break;
      }
   }
   return ret_val;
}

/*===========================================================================*
 * Global Function Definitions
 *===========================================================================*/
/*===========================================================================*\
 * FUNCTION: MIPI_Enable
 *===========================================================================
 * RETURN VALUE:
 *    bool - true when the controller acknowledges enable
 *
 * PARAMETERS:
 *    void
 * --------------------------------------------------------------------------
 * ABSTRACT:
 *    Set the MIPI enable bit and verify it latches in hardware
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
bool MIPI_Enable(void)
{
   bool ret_val = false;

   ptrMIPI->CTRL.f.ENA = TRUE;
   if (FALSE != ptrMIPI->CTRL.f.ENA)
   {
      ret_val = true;
   }
   return ret_val;
}

/*===========================================================================*\
 * FUNCTION: MIPI_Disable
 *===========================================================================
 * RETURN VALUE:
 *    bool - true when the controller reports disabled state
 *
 * PARAMETERS:
 *    void
 * --------------------------------------------------------------------------
 * ABSTRACT:
 *    Clear the MIPI enable bit and confirm the hardware status
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
bool MIPI_Disable(void)
{
   bool ret_val = false;

   ptrMIPI->CTRL.f.ENA = FALSE;
   if (FALSE == ptrMIPI->CTRL.f.ENA)
   {
      ret_val = true;
   }
   return ret_val;
}

/*===========================================================================*\
 * FUNCTION: MIPI_Debugmode_Enable
 *===========================================================================
 * RETURN VALUE:
 *    bool - true when debug mode enable flag is set
 *
 * PARAMETERS:
 *    void
 * --------------------------------------------------------------------------
 * ABSTRACT:
 *    Enable MIPI debug mode when the interface is initialized
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
bool MIPI_Debugmode_Enable(void)
{
   bool ret_val = false;
   if (FALSE != MIPI_Initialized)
   {
      ptrMIPI->CTRL.f.DEBUG_ENA = (uint8_t)TRUE; /*!< Enable MIPI debug mode */
      if ((uint8_t)TRUE == ptrMIPI->CTRL.f.DEBUG_ENA)
      {
         ret_val = true;
      }
   }
   return ret_val;
}

/*===========================================================================*\
 * FUNCTION: MIPI_Debugmode_Disable
 *===========================================================================
 * RETURN VALUE:
 *    bool - true when debug mode is disabled
 *
 * PARAMETERS:
 *    void
 * --------------------------------------------------------------------------
 * ABSTRACT:
 *    Disable MIPI debug mode regardless of prior initialization state
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
bool MIPI_Debugmode_Disable(void)
{
   bool ret_val              = false;
   ptrMIPI->CTRL.f.DEBUG_ENA = (uint8_t)FALSE; /*!< Disable MIPI debug mode */
   if ((uint8_t)FALSE == ptrMIPI->CTRL.f.DEBUG_ENA)
   {
      ret_val = true;
   }
   return ret_val;
}

/*===========================================================================*\
 * FUNCTION: MIPI_CSI2_Config
 *===========================================================================
 * RETURN VALUE:
 *    bool - true when CSI2 lane and packet configuration succeeds
 *
 * PARAMETERS:
 *    const volatile MIPI_CSI2_Rx_Settings_T *ptr2mipi_csi2_config - configuration structure
 * --------------------------------------------------------------------------
 * ABSTRACT:
 *    Program CSI2 lane selection and packet framing prior to enabling MIPI data flow
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
bool MIPI_CSI2_Config(const volatile MIPI_CSI2_Rx_Settings_T *ptr2mipi_csi2_config)
{ // TODO: a bool needs to be added to identify that this function is called only for real MIPI data
   bool ret_val = false;

   ret_val = CSI2_Config(ptr2mipi_csi2_config->num_lanes);
   ret_val &= MIPI_Config(ptr2mipi_csi2_config);
   return ret_val;
}

/*===========================================================================*\
 * FUNCTION: Mipi_Init
 *===========================================================================
 * RETURN VALUE:
 *    bool - true when configuration succeeds, false otherwise
 *
 * PARAMETERS:
 *    const volatile MIPI_Config_T *const ptr2config - pointer to initialization settings
 * --------------------------------------------------------------------------
 * ABSTRACT:
 *    Configure the CSI2/MIPI subsystem and enable the interface when settings are valid
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
bool MIPI_Init(const volatile MIPI_Config_T *const ptr2config)
{
   bool ret_val        = false;
   MIPI_Initialized    = false;
   ptrMIPI->CTRL.f.ENA = FALSE; /*!< Explicit disable for MIPI */
   /* Clear IRQ flags */
   ptrMIPI->FRAME_IRQ_FLAG.r = MIPI_FRAME_IRQ_FLAG_FRAME_START_FLAG_msk | MIPI_FRAME_IRQ_FLAG_FRAME_END_FLAG_msk;
   ptrMIPI->CHIRP_IRQ_FLAG.r = MIPI_CHIRP_IRQ_EN_CHIRP_START_EN_msk | MIPI_CHIRP_IRQ_EN_CHIRP_END_EN_msk;

   if (ptr2config != NULL_PTR)
   {
      // MIPI_Configuration        = *ptr2config;
      // UT failed: commented and used below memcpy
      /* Use memcpy for const volatile compatibility with C++ compilation */
      memcpy((void *)&MIPI_Configuration, (const void *)ptr2config, sizeof(MIPI_Config_T));
      ptrMIPI->CTRL.f.DEBUG_ENA = ptr2config->enable_debug_mode;

      if ((MIPI_Configuration.symbols_per_chirp >= MIPI_MIN_SYMBOLS_PER_CHIRP) &&
          (MIPI_Configuration.symbols_per_chirp <= MIPI_MAX_SYMBOLS_PER_CHIRP) &&
          (MIPI_Configuration.num_of_chirps_per_frame >= MIPI_MIN_CHIRPS_PER_FRAME) &&
          ((MIPI_Configuration.num_of_active_adc_channels == NUM_ADC_CHANNELS_0x2_TWO_CHANNELS) ||
           (MIPI_Configuration.num_of_active_adc_channels == NUM_ADC_CHANNELS_0x4_FOUR_CHANNELS)))
      {
         ptrMIPI->CSI2_PKT_INFO.f.CSR_SYMB_PER_CHIRP =
            MIPI_Configuration.symbols_per_chirp - 1U; /*!< number of symbols per chirp - 1 */
         if (MIPI_Configuration.data_bits_size < 2U)
         {
            ptrMIPI->CSI2_PKT_INFO.f.CSR_SYMB_12_14_BIT_N =
               MIPI_Configuration.data_bits_size; /*!< adc resolution in bits 0 for 14 bits and 1 for 12 bits */
         }
         else
         {
            ptrMIPI->CSI2_PKT_INFO.f.CSR_SYMB_12_14_BIT_N = 0U; /*!< adc resolution in bits 0 for 14 bits and 1 for 12 bits */
         }

         ptrMIPI->CSI2_PKT_INFO.f.CSR_CHIRP_PER_FRAME =
            MIPI_Configuration.num_of_chirps_per_frame - 1U; /*!< number of chirps per frame - 1 */
         ptrMIPI->CSI2_PKT_INFO.f.CSR_NUM_ACTIVE_ADC_CHANNELS =
            MIPI_Configuration.num_of_active_adc_channels - 1U; /*!< number of ADC channels -1 */
#ifndef RESI_MODE_ENABLE
         ptrMIPI->CSI2_LONG_PKT_HEADER.f.CSI2_META_PKT_VC = 0x1;
#endif
         ret_val = MIPI_CSI2_Config(&MIPI_CSI2_Rx_Config);
         MIPI_Irq_Setup(Start_MIPI_Frame, End_MIPI_Frame, NULL_PTR, NULL_PTR, MIPI_FuSa_IRQ);

         if (ret_val)
         {
            MIPI_Initialized = true;
            ret_val          = true;
         }
      }
   }
   return ret_val;
}

/*===========================================================================*\
 * FUNCTION: MIPI_Debugmode_Write_Chirp
 *===========================================================================
 * RETURN VALUE:
 *    bool - true when debug buffer programming succeeds
 *
 * PARAMETERS:
 *    const volatile int16_t *data - pointer to chirp sample buffer
 *    const uint16_t size - size of the input buffer in bytes
 *    const uint16_t symbols_per_chirp - expected symbol count per chirp
 *    const uint8_t num_of_input_adc_channels - number of active ADC channels
 * --------------------------------------------------------------------------
 * ABSTRACT:
 *    Write rescaled chirp samples into the MIPI debug OCP memory for playback
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/

bool MIPI_Debugmode_Write_Chirp(const volatile int16_t *data, const uint16_t size, const uint16_t symbols_per_chirp,
                                const uint8_t num_of_input_adc_channels)
{
   bool ret_val = false;

   volatile uint16x16 *const ptr2mipi_ocp_mem = MIPI_OCP_MEMORY;
   const uint32_t ra_ocp_mem_size             = MIPI_OCP_MEM_SIZE;

   if ((TRUE == ptrMIPI->CTRL.f.DEBUG_ENA) && (data != NULL_PTR) &&
       (num_of_input_adc_channels <= MIPI_Configuration.num_of_active_adc_channels) &&
       (symbols_per_chirp == MIPI_Configuration.symbols_per_chirp) &&
       (((uint32_t)symbols_per_chirp * sizeof(uint64_t)) <= ra_ocp_mem_size) &&
       (size == (uint16_t)(symbols_per_chirp * num_of_input_adc_channels * 2U /* bytes */)) && MIPI_Initialized)
   {
      Mipi_4ch_4samples_Vector_T mipi_4samples_vector;

      const uint32_t frame_irq_save = ptrMIPI->FRAME_IRQ_EN.r;
      const uint32_t chirp_irq_save = ptrMIPI->CHIRP_IRQ_EN.r;

      ptrMIPI->FRAME_IRQ_EN.r = 0UL;
      ptrMIPI->CHIRP_IRQ_EN.r = 0UL;

      /* Process 4 samples per channel for maximum number of channels (4) utilizing vector operations
       * Each vector has 16 samples 4 samples (NUM_OF_VECTOR_SAMPLES_PER_CHANNEL) for 4 channels (MIPI_MAX_INPUT_CHANNELS)
       */
      for (uint32_t v_idx = 0; v_idx < ((uint32_t)symbols_per_chirp / NUM_OF_VECTOR_SAMPLES_PER_CHANNEL); v_idx++)
      {
         mipi_4samples_vector.vec_sample_data = 0;

         for (uint32_t s_idx = 0; s_idx < NUM_OF_VECTOR_SAMPLES_PER_CHANNEL; s_idx++)
         {
            for (uint8_t i = 0; i < num_of_input_adc_channels; i++)
            {
               mipi_4samples_vector.samples_data[(MIPI_MAX_INPUT_CHANNELS * s_idx) + i] =
                  Data_Rescale(data[(i * symbols_per_chirp) + (uint16_t)((4U * v_idx) + s_idx)]);
            }
         }

         ptr2mipi_ocp_mem[v_idx] = mipi_4samples_vector.vec_sample_data;
      }

      ptrMIPI->FRAME_IRQ_EN.r = frame_irq_save;
      ptrMIPI->CHIRP_IRQ_EN.r = chirp_irq_save;
      ret_val                 = true;
   }
   return ret_val;
}
/*===========================================================================*\
 * FUNCTION: Mipi_Test_Pattern_Enable
 *===========================================================================
 * RETURN VALUE:
 *    bool - true when requested channels are enabled
 *
 * PARAMETERS:
 *    const uint8_t num_of_channels - test pattern channel count to enable
 * --------------------------------------------------------------------------
 * ABSTRACT:
 *    Enable MIPI CSI2 test pattern generators for the specified channels
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
bool MIPI_Test_Pattern_Enable(const uint8_t num_of_channels)
{
   /* Enable test patterns */
   if (num_of_channels > 0)
   {
      ptrMIPI->CSR_TEST_PATTERN0_0.f.CSR_TEST_PATTERN_EN_0 = TRUE;
   }

   if (num_of_channels > 1)
   {
      ptrMIPI->CSR_TEST_PATTERN0_1.f.CSR_TEST_PATTERN_EN_1 = TRUE;
   }

   if (num_of_channels > 2)
   {
      ptrMIPI->CSR_TEST_PATTERN0_2.f.CSR_TEST_PATTERN_EN_2 = TRUE;
   }

   if (num_of_channels > 3)
   {
      ptrMIPI->CSR_TEST_PATTERN0_3.f.CSR_TEST_PATTERN_EN_3 = TRUE;
   }
   return true;
}

/*===========================================================================*\
 * FUNCTION: MIPI_Test_Pattern_Disable
 *===========================================================================
 * RETURN VALUE:
 *    bool - true once all test pattern generators are cleared
 *
 * PARAMETERS:
 *    void
 * --------------------------------------------------------------------------
 * ABSTRACT:
 *    Disable every MIPI CSI2 test pattern channel
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
bool MIPI_Test_Pattern_Disable(void)
{
   /* Enable test patterns */
   ptrMIPI->CSR_TEST_PATTERN0_0.f.CSR_TEST_PATTERN_EN_0 = FALSE;
   ptrMIPI->CSR_TEST_PATTERN0_1.f.CSR_TEST_PATTERN_EN_1 = FALSE;
   ptrMIPI->CSR_TEST_PATTERN0_2.f.CSR_TEST_PATTERN_EN_2 = FALSE;
   ptrMIPI->CSR_TEST_PATTERN0_3.f.CSR_TEST_PATTERN_EN_3 = FALSE;
   return true;
}

/*===========================================================================*\
 * FUNCTION: Mipi_Test_Pattern_Config
 *===========================================================================
 * RETURN VALUE:
 *    bool - true when configuration registers are updated for all channels
 *
 * PARAMETERS:
 *    const uint8_t num_of_channels - number of channels to configure
 * --------------------------------------------------------------------------
 * ABSTRACT:
 *    Configure waveform parameters and thresholds for MIPI test patterns
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
bool MIPI_Test_Pattern_Config(const uint8_t num_of_channels)
{
   bool ret_val = false;

   if ((num_of_channels > 0U) && (num_of_channels <= (uint8_t)NUM_ADC_CHANNELS_0x4_FOUR_CHANNELS))
   {
      /* DIsable test pattern generation */
      ret_val = MIPI_Test_Pattern_Disable();

      /* Inter chirp delay timer */
      ptrMIPI->CSR_TEST_PATTERN_INTER_CHIRP_IDLE = MIPI_Configuration.test_pattern_inter_chirp_delay;

      /* test pattern channel 0 */
      ptrMIPI->CSR_TEST_PATTERN0_0.f.CSR_TEST_PATTERN_WAVEFORM_SEL_0 =
         (uint8_t)((uint32_t)MIPI_Configuration.test_pattern_waveform_sel[0] & 0x3UL);
      ptrMIPI->CSR_TEST_PATTERN1_0.f.CSR_TEST_PATTERN_THR_0 = (uint16_t)(MIPI_Configuration.test_pattern_threshold[0] & 0x7FFUL);
      ptrMIPI->CSR_TEST_PATTERN1_0.f.CSR_TEST_PATTERN_SHIFT1_VALUE_0 =
         (uint8_t)(MIPI_Configuration.test_pattern_shift1_val[0] & 0x1FUL);
      ptrMIPI->CSR_TEST_PATTERN1_0.f.CSR_TEST_PATTERN_SHIFT2_VALUE_0 =
         (uint8_t)(MIPI_Configuration.test_pattern_shift2_val[0] & 0x1FUL);
      ptrMIPI->CSR_TEST_PATTERN2_0.f.CSR_TEST_PATTERN_STEP_0   = MIPI_Configuration.test_pattern_step[0];
      ptrMIPI->CSR_TEST_PATTERN2_0.f.CSR_TEST_PATTERN_OFFSET_0 = MIPI_Configuration.test_pattern_offset[0];

      /* test pattern channel 1 */
      if (num_of_channels > 1)
      {
         ptrMIPI->CSR_TEST_PATTERN0_1.f.CSR_TEST_PATTERN_WAVEFORM_SEL_1 =
            (uint8_t)((uint32_t)MIPI_Configuration.test_pattern_waveform_sel[1] & 0x3UL);
         ptrMIPI->CSR_TEST_PATTERN1_1.f.CSR_TEST_PATTERN_THR_1 =
            (uint16_t)(MIPI_Configuration.test_pattern_threshold[1] & 0x7FFUL);
         ptrMIPI->CSR_TEST_PATTERN1_1.f.CSR_TEST_PATTERN_SHIFT1_VALUE_1 =
            (uint8_t)(MIPI_Configuration.test_pattern_shift1_val[1] & 0x1FUL);
         ptrMIPI->CSR_TEST_PATTERN1_1.f.CSR_TEST_PATTERN_SHIFT2_VALUE_1 =
            (uint8_t)(MIPI_Configuration.test_pattern_shift2_val[1] & 0x1FUL);
         ptrMIPI->CSR_TEST_PATTERN2_1.f.CSR_TEST_PATTERN_STEP_1   = MIPI_Configuration.test_pattern_step[1];
         ptrMIPI->CSR_TEST_PATTERN2_1.f.CSR_TEST_PATTERN_OFFSET_1 = MIPI_Configuration.test_pattern_offset[1];
      }
      /* test pattern channel 2 */
      if (num_of_channels > 2)
      {
         ptrMIPI->CSR_TEST_PATTERN0_2.f.CSR_TEST_PATTERN_WAVEFORM_SEL_2 =
            (uint8_t)((uint32_t)MIPI_Configuration.test_pattern_waveform_sel[2] & 0x3UL);
         ptrMIPI->CSR_TEST_PATTERN1_2.f.CSR_TEST_PATTERN_THR_2 =
            (uint16_t)(MIPI_Configuration.test_pattern_threshold[2] & 0x7FFUL);
         ptrMIPI->CSR_TEST_PATTERN1_2.f.CSR_TEST_PATTERN_SHIFT1_VALUE_2 =
            (uint8_t)(MIPI_Configuration.test_pattern_shift1_val[2] & 0x1FUL);
         ptrMIPI->CSR_TEST_PATTERN1_2.f.CSR_TEST_PATTERN_SHIFT2_VALUE_2 =
            (uint8_t)(MIPI_Configuration.test_pattern_shift2_val[2] & 0x1FUL);
         ptrMIPI->CSR_TEST_PATTERN2_2.f.CSR_TEST_PATTERN_STEP_2   = MIPI_Configuration.test_pattern_step[2];
         ptrMIPI->CSR_TEST_PATTERN2_2.f.CSR_TEST_PATTERN_OFFSET_2 = MIPI_Configuration.test_pattern_offset[2];
      }

      /* test pattern channel 3 */
      if (num_of_channels > 3)
      {
         ptrMIPI->CSR_TEST_PATTERN0_3.f.CSR_TEST_PATTERN_WAVEFORM_SEL_3 =
            (uint8_t)((uint32_t)MIPI_Configuration.test_pattern_waveform_sel[3] & 0x3UL);
         ptrMIPI->CSR_TEST_PATTERN1_3.f.CSR_TEST_PATTERN_THR_3 =
            (uint16_t)(MIPI_Configuration.test_pattern_threshold[3] & 0x7FFUL);
         ptrMIPI->CSR_TEST_PATTERN1_3.f.CSR_TEST_PATTERN_SHIFT1_VALUE_3 =
            (uint8_t)(MIPI_Configuration.test_pattern_shift1_val[3] & 0x1FUL);
         ptrMIPI->CSR_TEST_PATTERN1_3.f.CSR_TEST_PATTERN_SHIFT2_VALUE_3 =
            (uint8_t)(MIPI_Configuration.test_pattern_shift2_val[3] & 0x1FUL);
         ptrMIPI->CSR_TEST_PATTERN2_3.f.CSR_TEST_PATTERN_STEP_3   = MIPI_Configuration.test_pattern_step[3];
         ptrMIPI->CSR_TEST_PATTERN2_3.f.CSR_TEST_PATTERN_OFFSET_3 = MIPI_Configuration.test_pattern_offset[3];
      }
   }
   return ret_val;
}

/*=========================================================*
 * RESI board trigger functions - not required for Aptv EDU setup
 *==========================================================*/
/*===========================================================================*\
 * FUNCTION: Initialize_Frame_Start_Output_Gpio
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    void
 * --------------------------------------------------------------------------
 * ABSTRACT:
 *    Configure the GPIO and system control registers for frame start output
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
void Initialize_Frame_Start_Output_Gpio(void)
{
#ifdef UNIT_TEST
   #undef IOCTRL_base
   #undef SYSCTRL_base
   #undef IOCTRL
   #undef SYSCTRL

   IOCTRL_SFRS_t *IOCTRL_local   = (IOCTRL_SFRS_t *)malloc(sizeof(IOCTRL_SFRS_t));
   SYSCTRL_SFRS_t *SYSCTRL_local = (SYSCTRL_SFRS_t *)malloc(sizeof(SYSCTRL_SFRS_t));
   #define IOCTRL  ((IOCTRL_SFRS_t *)IOCTRL_local)
   #define SYSCTRL ((SYSCTRL_SFRS_t *)SYSCTRL_local)
   memset((void *)IOCTRL_local, 0, sizeof(IOCTRL_SFRS_t));
   memset((void *)SYSCTRL_local, 0, sizeof(SYSCTRL_SFRS_t));

#endif
   IOCTRL->GPIO_03.f.FUNC_SEL                       = 1;       // select function 1: FRAME_START
   IOCTRL->GPIO_03.f.DS                             = 0;       // drive strength normal
   IOCTRL->GPIO_03.f.PE                             = 0;       // disable pull-up/down resistor
   SYSCTRL->FRAME_START_CTRL0.f.CTL_STC_FSTRT_ENA   = 0U;      // disable frame start via clock
   SYSCTRL->FRAME_START_CTRL0.f.CTL_MMINTF_FSTRT_SW = 0U;      // reset frame start software trigger
   SYSCTRL->FRAME_START_CTRL0.f.CTL_MMINTF_FS_DUR   = 0xFFFFU; // set trigger pulse duration in 2ns increments
}

/*===========================================================================*\
 * FUNCTION: Trigger_Frame_Start_To_Resi
 *===========================================================================
 * RETURN VALUE:
 *    void
 *
 * PARAMETERS:
 *    void
 * --------------------------------------------------------------------------
 * ABSTRACT:
 *    Generate a single frame start pulse towards the RESI hardware
 * --------------------------------------------------------------------------
 *
\*===========================================================================*/
void Trigger_Frame_Start_To_Resi(void)
{
   // trigger FRAME_START pulse

#ifdef UNIT_TEST
   #undef IOCTRL_base
   #undef SYSCTRL_base
   #undef IOCTRL
   #undef SYSCTRL

   IOCTRL_SFRS_t *IOCTRL_local   = (IOCTRL_SFRS_t *)malloc(sizeof(IOCTRL_SFRS_t));
   SYSCTRL_SFRS_t *SYSCTRL_local = (SYSCTRL_SFRS_t *)malloc(sizeof(SYSCTRL_SFRS_t));
   #define IOCTRL  ((IOCTRL_SFRS_t *)IOCTRL_local)
   #define SYSCTRL ((SYSCTRL_SFRS_t *)SYSCTRL_local)
   memset((void *)IOCTRL_local, 0, sizeof(IOCTRL_SFRS_t));
   memset((void *)SYSCTRL_local, 0, sizeof(SYSCTRL_SFRS_t));

#endif
   SYSCTRL->FRAME_START_CTRL0.f.CTL_MMINTF_FSTRT_SW = 1U;
   SYSCTRL->FRAME_START_CTRL0.f.CTL_MMINTF_FSTRT_SW = 0U;
}
