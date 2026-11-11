#ifndef DD_MIPI_H
#define DD_MIPI_H

/*===========================================================================*
 * Includes
 *===========================================================================*/
#include "Std_Types.h"
#include "chandra_sfrs_base.h"
#include "crg_sfrs.h"
#include "csi_sfrs.h"
#include "ioctrl_sfrs.h"
#include "mipi_ocp_mem_sfrs.h"
#include "mipi_sfrs.h"
#include "mipi_stat_mem_sfrs.h"
#include "sysctrl_sfrs.h"

#ifdef __cplusplus
extern "C"
{      /* Inclusion of header files should NOT be inside the extern "C" block */
#endif /* __cplusplus */

   /*===========================================================================*
    * Global Constants
    *===========================================================================*/
   // #if !defined MIPI_base
   //    #define MIPI_base 0x84480000UL
   // #endif
   // #if !defined MIPI_STAT_MEM_base
   //    #define MIPI_STAT_MEM_base 0x844A0000UL
   // #endif
   // #if !defined MIPI_OCP_MEM_base
   //    #define MIPI_OCP_MEM_base 0x84100000UL
   // #endif
   // #if !defined CSI_base
   //    #define CSI_base 0x84410000UL
   // #endif

#define NUM_ADC_CHANNELS_0x2_TWO_CHANNELS  2U /* Two ADC channels */
#define NUM_ADC_CHANNELS_0x4_FOUR_CHANNELS 4U /* Four ADC channels */

#define MIPI_MIN_CHIRPS_PER_FRAME  1U
#define MIPI_MIN_SYMBOLS_PER_CHIRP 1U
#define MIPI_MAX_SYMBOLS_PER_CHIRP 2048U
#define MIPI_MAX_INPUT_CHANNELS    4U

#define MIPI_INPUT_DATA_0x0_14_BITS 0U /* 14 bits ADC samples */
#define MIPI_INPUT_DATA_0x1_12_BITS 1U /* 12 bits ADC samples */

#if !defined PTR_MIPI
   #define PTR_MIPI ((volatile MIPI_SFRS_t *const)MIPI_base)
#endif
#if !defined PTR_MIPI_OCP_MEM
   #define PTR_MIPI_OCP_MEM ((volatile MIPI_OCP_MEM_SFRS_t *const)MIPI_OCP_MEM_base)
#endif
#if !defined PTR_MIPI_STAT_MEM
   #define PTR_MIPI_STAT_MEM ((volatile MIPI_STAT_MEM_SFRS_t *const)MIPI_STAT_MEM_base)
#endif
#if !defined PTR_CSI
   #define PTR_CSI ((volatile CSI_SFRS_t *const)CSI_base)
#endif

/* Pointer macros for direct register access */
#if !defined OCP_MEM
   #define OCP_MEM ((volatile MIPI_OCP_MEM_SFRS_t *)MIPI_OCP_MEM_base)
#endif
#if !defined IOCTRL
   #define IOCTRL ((volatile IOCTRL_SFRS_t *)IOCTRL_base)
#endif
#if !defined SYSCTRL
   #define SYSCTRL ((volatile SYSCTRL_SFRS_t *)SYSCTRL_base)
#endif

#define MIPI_OCP_MEM_BASEADDR          ((uint32_t)MIPI_OCP_MEM_base)
#define MIPI_IDM_MAX_POLLUTION_WEIGHTS 7U

#define SYMBOLS_PER_CHIRP 1024U
   /*===========================================================================*
    * Global Function Macros
    *===========================================================================*/

   /*===========================================================================*
    * Global Datatypes and Structures
    *===========================================================================*/
   typedef enum Mipi_Test_Pattern_Selector_Tag
   {
      MIPI_TEST_PATTERN_0x0_PULSE = 0,
      MIPI_TEST_PATTERN_0x1_SINUSOID,
      MIPI_TEST_PATTERN_0x2_RAMP
   } Mipi_Test_Pattern_Selector_T;
   typedef struct MIPI_Config_Tag
   {
      Mipi_Test_Pattern_Selector_T test_pattern_waveform_sel[MIPI_MAX_INPUT_CHANNELS];
      uint16_t test_pattern_step[MIPI_MAX_INPUT_CHANNELS];
      uint16_t test_pattern_offset[MIPI_MAX_INPUT_CHANNELS];
      uint16_t test_pattern_threshold[MIPI_MAX_INPUT_CHANNELS];
      uint8_t test_pattern_shift1_val[MIPI_MAX_INPUT_CHANNELS];
      uint8_t test_pattern_shift2_val[MIPI_MAX_INPUT_CHANNELS];
      uint16_t symbols_per_chirp;
      uint16_t num_of_chirps_per_frame;
      uint16_t test_pattern_inter_chirp_delay;
      uint8_t num_of_active_adc_channels;
      uint8_t data_bits_size;
      uint8_t enable_debug_mode;
      bool transpose_bypass;
   } MIPI_Config_T;
   typedef struct MIPI_CSI2_Rx_Settings_Tag
   {
      uint8_t shrtpacket_startVCId;
      uint8_t shrtpacket_startDtype;
      uint8_t shrtpacket_endVCId;
      uint8_t shrtpacket_endDtype;
      uint8_t longpacket_VCId;
      uint8_t longpacket_dtype;
      uint8_t num_lanes;
   } MIPI_CSI2_Rx_Settings_T;
   /*===========================================================================*
    * Global Data
    *===========================================================================*/
   extern volatile MIPI_OCP_MEM_SFRS_t *const ptrMIPI_OCP_MEM;
   extern volatile MIPI_SFRS_t *const ptrMIPI;
   extern volatile CSI_SFRS_t *const ptrCSI;
   /*===========================================================================*
    * Global Function Prototypes
    *===========================================================================*/

   /**
    * @brief         Enable the MIPI interface
    * @return        E_OK if successful E_NOT_OK if failed
    */
   bool MIPI_Enable(void);

   /**
    * @brief         Disable the MIPI interface
    * @return        E_OK if successful E_NOT_OK if failed
    */
   bool MIPI_Disable(void);

   /**
    * @brief         Enable MIPI debug mode
    * @return        E_OK if successful E_NOT_OK if failed
    */
   bool MIPI_Debugmode_Enable(void);

   /**
    * @brief         Disable MIPI debug mode
    * @return        E_OK if successful E_NOT_OK if failed
    */
   bool MIPI_Debugmode_Disable(void);
   /**
    * @brief         Initialize MIPI CSI unit
    * @param [in]    ptr2mipi_csi_config pointer to mipi and csi configuration structure for real data reception
    * @return        E_OK if successful E_NOT_OK if failed
    */
   bool MIPI_CSI2_Config(const volatile MIPI_CSI2_Rx_Settings_T *ptr2mipi_csi2_config);

   /**
    * @brief         Initialize MIPI
    * @param [in]    ptr2config pointer to mipi configuration structure
    * @return        E_OK if successful E_NOT_OK if failed
    */
   bool MIPI_Init(const volatile MIPI_Config_T *const ptr2config);

   /**
    * @brief       Load data onto the OCP memory of the MIPI
    * @param [in]  data pointer to the data
    * @param [in]  size data input size
    * @param [in]  symbols_per_chirp symbols per chirp in data
    * @param [in]  num_of_input_adc_channels number of input channels
    * @return      E_OK if successful E_NOT_OK if failed
    */
   bool MIPI_Debugmode_Write_Chirp(const volatile int16_t *data, const uint16_t size, const uint16_t symbols_per_chirp,
                                   const uint8_t num_of_input_adc_channels);
   /**
    * @brief       Disable test pattern
    * @return      E_OK if successful E_NOT_OK if failed
    */
   bool MIPI_Test_Pattern_Disable(void);

   /**
    * @brief       Enable test pattern for the specified channels
    * @param [in]  num_of_channels number of channels
    * @return      E_OK if successful E_NOT_OK if failed
    */
   bool MIPI_Test_Pattern_Enable(const uint8_t num_of_channels);
   /**
    * @brief       Enable test pattern for the specified channels
    * @param [in]  num_of_channels number of channels
    * @return      E_OK if successful E_NOT_OK if failed
    */
   bool MIPI_Test_Pattern_Config(const uint8_t num_of_channels);

   void Initialize_Frame_Start_Output_Gpio(void);

   void Trigger_Frame_Start_To_Resi(void);
   /*===========================================================================*
    * Global Inline Functions
    *===========================================================================*/

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif /* DD_MIPI_H */
