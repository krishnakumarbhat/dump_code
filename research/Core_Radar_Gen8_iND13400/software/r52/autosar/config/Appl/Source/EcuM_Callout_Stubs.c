/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                 Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                 All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  LICENSE
 *  -------------------------------------------------------------------------------------------------------------------
 *            Module: EcuM
 *           Program:
 *          Customer:
 *       Expiry Date: Not restricted
 *    License Scope : The usage is restricted to PAI19494
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: EcuM_Callout_Stubs.c
 *   Generation Time: 2026-08-27 16:48:47
 *           Project: Gen8_iND13400 - Version 1.0
 *          Delivery: PAI19494
 *      Tool Version: DaVinci Configurator Classic (beta) 5.31.55 SP5
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 ! BETA VERSION                                                                                                       !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 ! This version of DaVinci Configurator Classic and/or the related Basic Software Package is BETA software.               !
 ! BETA Software is basically operable, but not sufficiently tested, verified and/or qualified for use in series      !
 ! production and/or in vehicles operating on public or non-public roads.                                             !
 ! In particular, without limitation, BETA Software may cause unpredictable ECU behavior, may not provide all         !
 ! functions necessary for use in series production and/or may not comply with quality requirements which are         !
 ! necessary according to the state of the art. BETA Software must not be used in series production.                  !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
**********************************************************************************************************************/

/**********************************************************************************************************************
 * The generated code contains features that are not licensed and thus serial production is not allowed. The code may include
 *errors.
 *
 * [Warning] Cfg00033 - No valid license file. Serial production is not allowed!
 * - No license file (.veplc) found in the BSW package. Please contact the Vector support to obtain valid licenses.
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK User Version>                           DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#pragma clang optimize off
/* SW execution was going into OS protection Hook error due LTO optimization. In Rte_MemClr(), R52 was changing from thumb Mode  to
Arm Mode due to branch inst. Added Pragma clang optimize off to tackle this issue. This is temporary solution. Need to work with
Windriver team for a permanent fix. */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/*********************************************************************************************************************
    INCLUDES
 *********************************************************************************************************************/
#define ECUM_CALLOUT_STUBS_SOURCE
#include "EcuM.h"

#define ECUM_PRIVATE_CFG_INCLUDE
#include "EcuM_PrivateCfg.h"
#undef ECUM_PRIVATE_CFG_INCLUDE /* PRQA S 0841 */ /* MD_EcuM_0841 */

/**********************************************************************************************************************
 *  All configured EcuM Wakeup Sources (as bitmasks) for usage in Callouts
 *********************************************************************************************************************/
/*
 * ECUM_WKSOURCE_NONE                      (EcuM_WakeupSourceType)(0x00000000u)
 * ECUM_WKSOURCE_ALL_SOURCES               (EcuM_WakeupSourceType)(~((EcuM_WakeupSourceType)0x00UL))
 * ECUM_WKSOURCE_POWER                     (EcuM_WakeupSourceType)(1u)
 * ECUM_WKSOURCE_RESET                     (EcuM_WakeupSourceType)(2u)
 * ECUM_WKSOURCE_INTERNAL_RESET            (EcuM_WakeupSourceType)(4u)
 * ECUM_WKSOURCE_INTERNAL_WDG              (EcuM_WakeupSourceType)(8u)
 * ECUM_WKSOURCE_EXTERNAL_WDG              (EcuM_WakeupSourceType)(16u)
 * ECUM_WKSOURCE_CN_PCAN_RADAR_458ff0f1    (EcuM_WakeupSourceType)(32u)
 * ECUM_WKSOURCE_CN_VCAN_RADAR_489180b6    (EcuM_WakeupSourceType)(64u)
 * ECUM_WKSOURCE_cnctr_RDR_RdrNet_5172a59b (EcuM_WakeupSourceType)(128u)
 */

/**********************************************************************************************************************
 *  Additional configured User includes
 *********************************************************************************************************************/
#include "BswM.h"
#include "CanIf.h"
#include "CanSM_EcuM.h"
#include "CanTp.h"
#include "Com.h"
#include "ComM.h"
#include "Dcm.h"
#include "Det.h"
#include "Driver_Port.h"
#include "EthIf.h"
#include "EthSM.h"
#include "EthTrcv_30_Rtl9010.h"
#include "Eth_30_Wrapper.h"
#include "PduR.h"
#include "Rte_Main.h"
#include "SchM_Fls.h"
#include "SoAd.h"
#include "TcpIp.h"
#include "TcpIpXcp.h"
#include "Xcp.h"
#include "calibration_if.h"
#include "reuse.h"
#include "sensor_position.h"

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK User Includes>                          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#include "mcal_init.h"
#include <cstring>
/* Below functionality isfor providing interface between RAM and FLASH for reading the SPC data address. */
#define ECUM_START_SEC_CODE
#include "EcuM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if defined(VEH_AL_CAN_STANDALONE)
   #define ADC_PIN_THRESHOLD                (100U)
   #define SENSOR_POSITION_MAX_POSITIONS    (8U)
   #define SENSOR_POSITION_DEFAULT_POSITION (1U)
   #define SENSOR_POSITION_MAX_HW_PINS      (3U)
#else
   #define ADC_PIN_THRESHOLD                (100U)
   #define SENSOR_POSITION_MAX_POSITIONS    (5U)
   #define SENSOR_POSITION_DEFAULT_POSITION (1U)
   #define SENSOR_POSITION_MAX_HW_PINS      (2U)
#endif

#define AL_A3_VARIANT                                                                                                             \
   ((Get_Board_Revision() == BOARD_REV_A3P0) || (Get_Board_Revision() == BOARD_REV_B0CVAL) ||                                     \
    (Get_Board_Revision() == BOARD_REV_B0CVAL_ETH))

#define POSITION_PIN_THRESHOLD_BY_BOARD_REV(AL_A3_THRESHOLD, A2_THRESHOLD) ((AL_A3_VARIANT) ? (AL_A3_THRESHOLD) : (A2_THRESHOLD))

#define POSITION_PIN_THRESHOLD POSITION_PIN_THRESHOLD_BY_BOARD_REV(200U, 100U)

/* function pointer for function to read data from flash memory */
// typedef void *(*FlashRead_API_T)(void *dest, const void *src, uintptr_t size);

/* Accessing the Driver Flash Variable from Chandra drivers */
extern const uint32_t __SPC_FLASH_START_ADDRESS[];
volatile uint16_t SPC_load_fail = 0;
/** SPT init failure fault status flag  */
volatile uint32_t Spt_Init_Fault_Status = CODED_FALSE;
// volatile uint8_t PMIC_MCU_Comm_Fault    = CODED_FALSE;

/**
 * FUNCTION: Sensor_Pos_SPC_Flash_Read_Wrapper.
 *    This function takes destination ptr as address of read buffer
 *    ,source ptr as Flash address & length of data to be copied
 *    from flash to RAM.
 * \param[in]      void
 * \return         void
 *
 * \remark
 * \Reentrancy     non-reentrant
 * \Synchronism    synchronous
 * \Precondition   none
 * \Caveats        none
 * \Requirements
 *
 */
void *Sensor_Pos_SPC_Flash_Read_Wrapper(void *dst, const void *src, uintptr_t length)
{
   MemIf_JobResultType status;
   uint8_t ReadData_result = 0U;
   uint8_t read_buffer[64] __attribute__((aligned(16)));
   static int16_t SPC_timeout_counter;
   while (length)
   {
      const uint32_t read_size = length > sizeof(read_buffer) ? sizeof(read_buffer) : length;
      SPC_timeout_counter      = 1000;
      ReadData_result          = Fls_Read((uint32_t)src, read_buffer, read_size);
      if (E_OK == ReadData_result)
      {
         do
         {
            Fls_MainFunction();
            status = Fls_GetJobResult();
            SPC_timeout_counter--;
         } while ((status != MEMIF_JOB_OK) && SPC_timeout_counter);
         if (0 == SPC_timeout_counter)
         {
            SPC_load_fail = 1;
         }
         memcpy(dst, read_buffer, read_size);
         dst = ((uint8_t *)dst) + read_size;
         src = ((uint8_t *)src) + read_size;
         length -= read_size;
      }
      else
      {
         // do nothing
      }
   }
   return NULL;
}

/**
 * FUNCTION: Sensor_Position_Init_Hw_Wrapper.
 *    function to initialize hardware for reading sensor position pins
 *    from flash to RAM.
 * \param[in]      void
 * \return         bool
 *
 * \remark
 * \Reentrancy     non-reentrant
 * \Synchronism    synchronous
 * \Precondition   none
 * \Caveats        none
 * \Requirements
 *
 */
bool Sensor_Position_Init_Hw_Wrapper(void)
{
   Read_Sensor_Position_Pins();
   return true;
}

/**
 * FUNCTION: Sensor_Position_Read_Hw_Pin_Wrapper.
 *    function to read sensor position pins status
 * \param[in]      uint32_t pinid
 * \return         bool
 *
 * \remark
 * \Reentrancy     non-reentrant
 * \Synchronism    synchronous
 * \Precondition   none
 * \Caveats        none
 * \Requirements
 *
 */
bool Sensor_Position_Read_Hw_Pin_Wrapper(uint32_t pinid)
{
   Position_Pins_T *Pins = Get_Last_Sensor_Position_Pins();
   return Pins->pos_gnd_a2d_cnt[pinid] < POSITION_PIN_THRESHOLD;
}

#define ECUM_STOP_SEC_CODE
#include "EcuM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Above functionality isfor providing interface between RAM and FLASH for reading the SPC data address. */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  CALLOUT FUNCTIONS
 *********************************************************************************************************************/
#define ECUM_START_SEC_CALLOUT_CODE_ASIL_D
#include "EcuM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GENERIC CALLOUTS
 *********************************************************************************************************************/

FUNC(void, ECUM_CODE) EcuM_ErrorHook(Std_ReturnType reason) /* COV_ECUM_CALLOUT */ /* PRQA S 3206 */ /* MD_EcuM_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_ErrorHook>                         DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#if (ECUM_USE_DUMMY_STATEMENT == STD_ON)
   /* dummy assignment to prevent compiler warnings on most of the compilers. */
   (void)reason; /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif
   /* Add implementation of EcuM_ErrorHook() */

   /* In case of an inconsistent configuration data, abort initialization here */
   if (reason == ECUM_E_HOOK_CONFIGURATION_DATA_INCONSISTENT)
   {
#ifndef UNIT_TEST
      while (1)
      {
      }
#endif
   }

#if (ECUM_NUMBER_OF_CORES > 1)
   /* In case of an invalid coreId, returned by the OS */
   if (reason == ECUM_E_HOOK_INVALID_COREID)
   {
   #ifndef UNIT_TEST
      while (1)
      {
      }
   #endif
   }
#endif

   return;
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
} /* End of EcuM_ErrorHook() */

/**********************************************************************************************************************
 *  CALLOUTS FROM THE SHUTDOWN PHASE
 *********************************************************************************************************************/

FUNC(void, ECUM_CODE) EcuM_OnGoOffOne(void)
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_OnGoOffOne>                        DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
   /* Add implementation of EcuM_OnGoOffOne() */

   return;
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
} /* End of EcuM_OnGoOffOne() */

FUNC(void, ECUM_CODE) EcuM_ShutdownOS(Std_ReturnType ErrCode)
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_ShutdownOS>                        DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
   /* Add implementation of EcuM_ShutdownOS() */
#if (ECUM_NUMBER_OF_CORES > 1)
   ShutdownAllCores(ErrCode);
#else
   ShutdownOS(ErrCode);
#endif

   return;
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
} /* End of EcuM_ShutdownOS() */

FUNC(void, ECUM_CODE) EcuM_OnGoOffTwo(void)
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_OnGoOffTwo>                        DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
   /* Add implementation of EcuM_OnGoOffTwo() */

   return;
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
} /* End of EcuM_OnGoOffTwo() */

FUNC(void, ECUM_CODE) EcuM_AL_SwitchOff(void)
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_AL_SwitchOff>                      DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
   /* Add implementation of EcuM_AL_SwitchOff() */

   return;
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
} /* End of EcuM_AL_SwitchOff() */

FUNC(void, ECUM_CODE) EcuM_AL_Reset(EcuM_ResetType Reset) /* PRQA S 3206 */ /* MD_EcuM_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_AL_Reset>                          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#if (ECUM_USE_DUMMY_STATEMENT == STD_ON)
   /* dummy assignment to prevent compiler warnings on most of the compilers. */
   (void)Reset; /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif
   /* Add implementation of EcuM_AL_Reset() */

   return;
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
} /* End of EcuM_AL_Reset() */

/**********************************************************************************************************************
 *  CALLOUTS FROM THE STARTUP PHASE
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * EcuM_AL_DriverInitZero
 **********************************************************************************************************************/
volatile uint8_t Test_Var = 0;
FUNC(void, ECUM_CODE) EcuM_AL_DriverInitZero(void)
{
   Test_Var++;
   BswM_InitMemory();
   ComM_InitMemory();
   Com_InitMemory();
   Det_InitMemory();
   EthIf_InitMemory();
   EthSM_InitMemory();
   PduR_InitMemory();
   Rte_InitMemory();
   SoAd_InitMemory();
   TcpIp_InitMemory();
   EthTrcv_30_Rtl9010_InitMemory();
   Det_Init(Det_Config_Ptr);
   Xcp_InitMemory();
   TcpIpXcp_InitMemory();
   CanIf_InitMemory();
   CanSM_InitMemory();
   Dcm_InitMemory();
   CanTp_InitMemory();
   BswM_PreInit(EcuM_GlobalPCConfig_Ptr->CfgPtr_BswM_PreInit);

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_AL_DriverInitZero>                 DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
   /* Add implementation of EcuM_AL_DriverInitZero  */
   MCAL_Init();

   /* Read Sensor Position and Initialize*/
#if defined(VEH_AL_CAN_STANDALONE)
   const uint8_t ashok_layland_position_map[] = {
      1U, /* Index 0: Not used (GPO POS starts at 1)          */
      1U, /* GPO POS 1 (REAR LEFT)     -> Not defined in AL   */
      5U, /* GPO POS 2 (OPEN,OPEN,GND) -> AL POS 5 (FRONT CENTER)                   */
      1U, /* GPO POS 3 (FRONT RIGHT)   -> Not defined in AL   */
      1U, /* GPO POS 4 (FRONT LEFT)    -> Not defined in AL   */
      1U, /* GPO POS 5 (FRONT CENTER)  -> Not defined in AL   */
      1U, /* GPO POS 6 (REAR CENTER)   -> Not defined in AL   */
      4U, /* GPO POS 7 (GND,GND,OPEN)  -> AL POS 4 (FRONT LEFT)                     */
      1U  /* GPO POS 8 (GND,GND,GND)   -> AL POS 1 (REAR LEFT)                      */
   };
   Sensor_Position_Config_T config             = Get_Default_Sensor_Position_Config();
   config.spc_config.spc_start_address         = __SPC_FLASH_START_ADDRESS;
   config.spc_config.flash_read                = Sensor_Pos_SPC_Flash_Read_Wrapper;
   config.spc_config.max_pin_position          = SENSOR_POSITION_MAX_POSITIONS;
   config.spc_config.customer_max_pin_position = SENSOR_POSITION_MAX_POSITIONS;
   config.default_sensor_position              = SENSOR_POSITION_DEFAULT_POSITION;
   config.hw_config.read_pin                   = Sensor_Position_Read_Hw_Pin_Wrapper;
   config.hw_config.init_hw                    = Sensor_Position_Init_Hw_Wrapper;
   config.hw_config.no_of_pins                 = SENSOR_POSITION_MAX_HW_PINS;
   config.use_customer_position                = true;
   memcpy(config.spc_config.customer_position_map, ashok_layland_position_map,
          MIN(sizeof(ashok_layland_position_map), sizeof(config.spc_config.customer_position_map)));

#else
   Sensor_Position_Config_T config     = Get_Default_Sensor_Position_Config();
   config.spc_config.spc_start_address = __SPC_FLASH_START_ADDRESS;
   config.spc_config.flash_read        = Sensor_Pos_SPC_Flash_Read_Wrapper;
   config.spc_config.max_pin_position  = SENSOR_POSITION_MAX_POSITIONS;
   config.default_sensor_position      = SENSOR_POSITION_DEFAULT_POSITION;
   config.hw_config.read_pin           = Sensor_Position_Read_Hw_Pin_Wrapper;
   config.hw_config.init_hw            = Sensor_Position_Init_Hw_Wrapper;
   config.use_customer_position        = false;
   config.hw_config.no_of_pins         = SENSOR_POSITION_MAX_HW_PINS;
#endif
   Init_Sensor_Position(&config);
   return;
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 * EcuM_AL_DriverInitOne_RDR_01
 **********************************************************************************************************************/
FUNC(void, ECUM_CODE) EcuM_AL_DriverInitOne_RDR_01(void)
{
   ComM_PreInit(ComM_Config_Ptr);
   PduR_PreInit(EcuM_GlobalPCConfig_Ptr->CfgPtr_PduR_PreInit);
   SoAd_PreInit(SoAd_Config_Ptr);
   Eth_30_Wrapper_Init(Eth_30_Wrapper_Config_Ptr);

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_AL_DriverInitOne_RDR_01>           DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
   /* Add implementation of EcuM_AL_DriverInitOne_RDR_01  */

   return;
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 * EcuM_AL_DriverRestartList_RDR_01
 **********************************************************************************************************************/
FUNC(void, ECUM_CODE) EcuM_AL_DriverRestartList_RDR_01(void)
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_AL_DriverRestartList_RDR_01>       DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
   /* Add implementation of EcuM_AL_DriverRestartList_RDR_01  */

   return;
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 * EcuM_AL_DriverInitOne_RDR_02
 **********************************************************************************************************************/
FUNC(void, ECUM_CODE) EcuM_AL_DriverInitOne_RDR_02(void)
{
   ComM_PreInit(ComM_Config_Ptr);
   PduR_PreInit(EcuM_GlobalPCConfig_Ptr->CfgPtr_PduR_PreInit);
   SoAd_PreInit(SoAd_Config_Ptr);
   Eth_30_Wrapper_Init(Eth_30_Wrapper_Config_Ptr);

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_AL_DriverInitOne_RDR_02>           DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
   /* Add implementation of EcuM_AL_DriverInitOne_RDR_02  */

   return;
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 * EcuM_AL_DriverRestartList_RDR_02
 **********************************************************************************************************************/
FUNC(void, ECUM_CODE) EcuM_AL_DriverRestartList_RDR_02(void)
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_AL_DriverRestartList_RDR_02>       DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
   /* Add implementation of EcuM_AL_DriverRestartList_RDR_02  */

   return;
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 * EcuM_AL_DriverInitOne_RDR_03
 **********************************************************************************************************************/
FUNC(void, ECUM_CODE) EcuM_AL_DriverInitOne_RDR_03(void)
{
   ComM_PreInit(ComM_Config_Ptr);
   PduR_PreInit(EcuM_GlobalPCConfig_Ptr->CfgPtr_PduR_PreInit);
   SoAd_PreInit(SoAd_Config_Ptr);
   Eth_30_Wrapper_Init(Eth_30_Wrapper_Config_Ptr);

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_AL_DriverInitOne_RDR_03>           DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
   /* Add implementation of EcuM_AL_DriverInitOne_RDR_03  */

   return;
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 * EcuM_AL_DriverRestartList_RDR_03
 **********************************************************************************************************************/
FUNC(void, ECUM_CODE) EcuM_AL_DriverRestartList_RDR_03(void)
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_AL_DriverRestartList_RDR_03>       DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
   /* Add implementation of EcuM_AL_DriverRestartList_RDR_03  */

   return;
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 * EcuM_AL_DriverInitOne_RDR_04
 **********************************************************************************************************************/
FUNC(void, ECUM_CODE) EcuM_AL_DriverInitOne_RDR_04(void)
{
   ComM_PreInit(ComM_Config_Ptr);
   PduR_PreInit(EcuM_GlobalPCConfig_Ptr->CfgPtr_PduR_PreInit);
   SoAd_PreInit(SoAd_Config_Ptr);
   Eth_30_Wrapper_Init(Eth_30_Wrapper_Config_Ptr);

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_AL_DriverInitOne_RDR_04>           DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
   /* Add implementation of EcuM_AL_DriverInitOne_RDR_04  */

   return;
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 * EcuM_AL_DriverRestartList_RDR_04
 **********************************************************************************************************************/
FUNC(void, ECUM_CODE) EcuM_AL_DriverRestartList_RDR_04(void)
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_AL_DriverRestartList_RDR_04>       DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
   /* Add implementation of EcuM_AL_DriverRestartList_RDR_04  */

   return;
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 * EcuM_AL_DriverInitOne_RDR_05
 **********************************************************************************************************************/
FUNC(void, ECUM_CODE) EcuM_AL_DriverInitOne_RDR_05(void)
{
   ComM_PreInit(ComM_Config_Ptr);
   PduR_PreInit(EcuM_GlobalPCConfig_Ptr->CfgPtr_PduR_PreInit);
   SoAd_PreInit(SoAd_Config_Ptr);
   Eth_30_Wrapper_Init(Eth_30_Wrapper_Config_Ptr);

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_AL_DriverInitOne_RDR_05>           DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
   /* Add implementation of EcuM_AL_DriverInitOne_RDR_05  */

   return;
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 * EcuM_AL_DriverRestartList_RDR_05
 **********************************************************************************************************************/
FUNC(void, ECUM_CODE) EcuM_AL_DriverRestartList_RDR_05(void)
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_AL_DriverRestartList_RDR_05>       DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
   /* Add implementation of EcuM_AL_DriverRestartList_RDR_05  */

   return;
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 * EcuM_AL_DriverInitOne_RDR_06
 **********************************************************************************************************************/
FUNC(void, ECUM_CODE) EcuM_AL_DriverInitOne_RDR_06(void)
{
   ComM_PreInit(ComM_Config_Ptr);
   PduR_PreInit(EcuM_GlobalPCConfig_Ptr->CfgPtr_PduR_PreInit);
   SoAd_PreInit(SoAd_Config_Ptr);
   Eth_30_Wrapper_Init(Eth_30_Wrapper_Config_Ptr);

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_AL_DriverInitOne_RDR_06>           DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
   /* Add implementation of EcuM_AL_DriverInitOne_RDR_06  */

   return;
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 * EcuM_AL_DriverRestartList_RDR_06
 **********************************************************************************************************************/
FUNC(void, ECUM_CODE) EcuM_AL_DriverRestartList_RDR_06(void)
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_AL_DriverRestartList_RDR_06>       DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
   /* Add implementation of EcuM_AL_DriverRestartList_RDR_06  */

   return;
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 * EcuM_AL_DriverInitOne_RDR_07
 **********************************************************************************************************************/
FUNC(void, ECUM_CODE) EcuM_AL_DriverInitOne_RDR_07(void)
{
   ComM_PreInit(ComM_Config_Ptr);
   PduR_PreInit(EcuM_GlobalPCConfig_Ptr->CfgPtr_PduR_PreInit);
   SoAd_PreInit(SoAd_Config_Ptr);
   Eth_30_Wrapper_Init(Eth_30_Wrapper_Config_Ptr);

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_AL_DriverInitOne_RDR_07>           DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
   /* Add implementation of EcuM_AL_DriverInitOne_RDR_07  */

   return;
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 * EcuM_AL_DriverRestartList_RDR_07
 **********************************************************************************************************************/
FUNC(void, ECUM_CODE) EcuM_AL_DriverRestartList_RDR_07(void)
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_AL_DriverRestartList_RDR_07>       DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
   /* Add implementation of EcuM_AL_DriverRestartList_RDR_07  */

   return;
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 * EcuM_AL_DriverInitOne_RDR_08
 **********************************************************************************************************************/
FUNC(void, ECUM_CODE) EcuM_AL_DriverInitOne_RDR_08(void)
{
   ComM_PreInit(ComM_Config_Ptr);
   PduR_PreInit(EcuM_GlobalPCConfig_Ptr->CfgPtr_PduR_PreInit);
   SoAd_PreInit(SoAd_Config_Ptr);
   Eth_30_Wrapper_Init(Eth_30_Wrapper_Config_Ptr);

   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_AL_DriverInitOne_RDR_08>           DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
   /* Add implementation of EcuM_AL_DriverInitOne_RDR_08  */

   return;
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

/**********************************************************************************************************************
 * EcuM_AL_DriverRestartList_RDR_08
 **********************************************************************************************************************/
FUNC(void, ECUM_CODE) EcuM_AL_DriverRestartList_RDR_08(void)
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_AL_DriverRestartList_RDR_08>       DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
   /* Add implementation of EcuM_AL_DriverRestartList_RDR_08  */

   return;
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
}

FUNC(void, ECUM_CODE) EcuM_StartOS(AppModeType appMode)
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_StartOS>                           DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
   /* Add implementation of EcuM_StartOS() */
#if (ECUM_NUMBER_OF_CORES > 1)
   uint8 coreId;
   StatusType status;
   if (GetCoreID() == ECUM_CORE_ID_STARTUP)
   {
      for (coreId = 0; coreId < ECUM_NUMBER_OF_CORES; coreId++)
      {
         if (coreId != ECUM_CORE_ID_STARTUP)
         {
            StartCore(coreId, &status); /* SBSW_ECUM_ADRESSPARAMETER_TOOS */
         }
      }
   }
#endif

   /* Start OS must be called for each core */
   StartOS(appMode);

   return;
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
} /* End of EcuM_StartOS() */

FUNC(void, ECUM_CODE) EcuM_AL_SetProgrammableInterrupts(void)
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_AL_SetProgrammableInterrupts>      DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
   /* Add implementation of EcuM_AL_SetProgrammableInterrupts() */

   return;
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
} /* End of EcuM_AL_SetProgrammableInterrupts() */

#if ((ECUM_CONFIGURATION_VARIANT == ECUM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE) || (ECUM_POSTBUILD_VARIANT_SUPPORT == STD_ON))
FUNC(EcuM_GlobalConfigRefType, ECUM_CODE) EcuM_DeterminePbConfiguration(void)
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_DeterminePbConfiguration>          DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
   /* Add implementation of EcuM_DeterminePbConfiguration() */
   EcuM_GlobalConfigRefType RetVal;
   uint8 ecu_position;

   /*
    * Disable_Interrupts at the beginning of EcuM_Callout_User_DeterminePbConfiguration
    */
   DisableAllInterrupts();

   ecu_position = Get_Radar_Position();

   /* TODO: Match DaVinci Variant names to Positions to avoid confusion */
   switch (ecu_position)
   {
      case 1: /* ECU_POS_VARIANT_RDR01 */
      {
         RetVal = &EcuM_GlobalConfigRoot.RDR_01;
         break;
      }
      case 2: /* ECU_POS_VARIANT_RDR02 */
      {
         RetVal = &EcuM_GlobalConfigRoot.RDR_02;
         break;
      }
      case 3: /* ECU_POS_VARIANT_RDR03 */
      {
         RetVal = &EcuM_GlobalConfigRoot.RDR_03;
         break;
      }
      case 4: /* ECU_POS_VARIANT_RDR04 */
      {
         RetVal = &EcuM_GlobalConfigRoot.RDR_04;
         break;
      }
      case 5: /* ECU_POS_VARIANT_RDR05 */
      {
         RetVal = &EcuM_GlobalConfigRoot.RDR_05;
         break;
      }
      case 6: /* ECU_POS_VARIANT_RDR06 */
      {
         RetVal = &EcuM_GlobalConfigRoot.RDR_06;
         break;
      }
      case 7: /* ECU_POS_VARIANT_RDR07 */
      {
         RetVal = &EcuM_GlobalConfigRoot.RDR_07;
         break;
      }
      case 8: /* ECU_POS_VARIANT_RDR08 */
      {
         RetVal = &EcuM_GlobalConfigRoot.RDR_08;
         break;
      }
      default:
      {
         RetVal = &EcuM_GlobalConfigRoot.RDR_01;
         break;
      }
   }

   EnableAllInterrupts();

   return RetVal;
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
} /* End of EcuM_DeterminePbConfiguration() */
#endif

#if (ECUM_ALARM_CLOCK_PRESENT == STD_ON)
FUNC(void, ECUM_CODE) EcuM_GptStartClock(Gpt_ChannelType GptChannel, Gpt_ModeType Mode, Gpt_ValueType Value)
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_GptStartClock>                     DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
   /* Add implementation of EcuM_GptStartClock() */

   Gpt_EnableNotification(GptChannel);
   Gpt_StartTimer(GptChannel, Value);
   Gpt_SetMode(Mode);

   return;
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
} /* End of EcuM_GptStartClock() */
#endif

/**********************************************************************************************************************
 *  CALLOUTS FROM THE SLEEP PHASE
 *********************************************************************************************************************/

#if (ECUM_SLAVE_CORE_HANDLING == STD_ON)
FUNC(void, ECUM_CODE) EcuM_WaitForSlaveCores(void)
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_WaitForSlaveCores>                 DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
   /* Add implementation of EcuM_WaitForSlaveCores() */

   return;
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
} /* End of EcuM_WaitForSlaveCores() */
#endif

#if (ECUM_SLEEPMODELIST == STD_ON)

FUNC(void, ECUM_CODE) EcuM_GenerateRamHash(void)
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_GenerateRamHash>                   DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
   /* Add implementation of EcuM_GenerateRamHash() */

   return;
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
} /* End of EcuM_GenerateRamHash() */

FUNC(uint8, ECUM_CODE) EcuM_CheckRamHash(void)
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_CheckRamHash>                      DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
   /* Add implementation of EcuM_CheckRamHash() */

   return (1u);
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
} /* End of EcuM_CheckRamHash() */

FUNC(void, ECUM_CODE) EcuM_McuSetMode(Mcu_ModeType McuMode)
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_McuSetMode>                        DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
   /* Add implementation of EcuM_McuSetMode() */
   Mcu_SetMode(McuMode);

   return;
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
} /* End of EcuM_McuSetMode() */

   #if (ECUM_POLLINGOFSLEEPMODELIST == STD_ON)
FUNC(void, ECUM_CODE) EcuM_SleepActivity(void)
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_SleepActivity>                     DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
   /* Add implementation of EcuM_SleepActivity() */

   return;
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
} /* End of EcuM_SleepActivity() */
   #endif

FUNC(void, ECUM_CODE) EcuM_EnableWakeupSources(EcuM_WakeupSourceType wakeupSource) /* PRQA S 3206 */ /* MD_EcuM_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_EnableWakeupSources>               DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
   #if (ECUM_USE_DUMMY_STATEMENT == STD_ON)
   /* dummy assignment to prevent compiler warnings on most of the compilers. */
   (void)wakeupSource; /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
   #endif
   /* Add implementation of EcuM_EnableWakeupSources() */

   return;
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
} /* End of EcuM_EnableWakeupSources() */

FUNC(void, ECUM_CODE) EcuM_DisableWakeupSources(EcuM_WakeupSourceType wakeupSource) /* PRQA S 3206 */ /* MD_EcuM_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_DisableWakeupSources>              DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
   #if (ECUM_USE_DUMMY_STATEMENT == STD_ON)
   /* dummy assignment to prevent compiler warnings on most of the compilers. */
   (void)wakeupSource; /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
   #endif
   /* Add implementation of EcuM_DisableWakeupSources() */

   return;
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
} /* End of EcuM_DisableWakeupSources() */
#endif

FUNC(void, ECUM_CODE) EcuM_CheckWakeup(EcuM_WakeupSourceType wakeupSource) /* COV_ECUM_CALLOUT */
{
#if (ECUM_CHECKWAKEUPTIMEOFWAKEUPSOURCELIST == STD_ON)
   /* Do not remove the following function call. It is necessary for the CheckWakeup timeout mechanism */
   EcuM_StartCheckWakeup(wakeupSource);
#endif

#if (ECUM_ALARM_CLOCK_PRESENT == STD_ON)
   if ((ECUM_ALARM_WKSOURCE & wakeupSource) != 0u)
   {
      EcuM_AlarmCheckWakeup();
   }
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_CheckWakeup>                       DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
#if (ECUM_USE_DUMMY_STATEMENT == STD_ON)
   /* dummy assignment to prevent compiler warnings on most of the compilers. */
   (void)wakeupSource; /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif
   /* Add implementation of EcuM_CheckWakeup() */

   return;
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
} /* End of EcuM_CheckWakeup() */

#if ((ECUM_ALARM_CLOCK_PRESENT == STD_ON) && (ECUM_SLEEPMODELIST == STD_ON))
FUNC(void, ECUM_CODE) EcuM_GptSetNormal(Gpt_ChannelType GptChannel, Gpt_ModeType Mode)
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_GptSetNormal>                      DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
   /* Add implementation of EcuM_GptSetNormal() */

   Gpt_EnableNotification(GptChannel);
   Gpt_SetMode(Mode);

   return;
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
} /* End of EcuM_GptSetNormal() */

FUNC(void, ECUM_CODE) EcuM_GptSetSleep(Gpt_ChannelType GptChannel, Gpt_ModeType Mode)
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_GptSetSleep>                       DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
   /* Add implementation of EcuM_GptSetSleep() */

   Gpt_EnableWakeup(GptChannel);
   Gpt_SetMode(Mode);

   return;
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
} /* End of EcuM_GptSetSleep() */
#endif

/**********************************************************************************************************************
 *  CALLOUTS FROM THE UP PHASE
 *********************************************************************************************************************/

#if (ECUM_VALIDATIONTIMEOFWAKEUPSOURCELIST == STD_ON)

FUNC(void, ECUM_CODE) EcuM_StartWakeupSources(EcuM_WakeupSourceType wakeupSource) /* PRQA S 3206 */ /* MD_EcuM_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_StartWakeupSources>                DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
   #if (ECUM_USE_DUMMY_STATEMENT == STD_ON)
   /* dummy assignment to prevent compiler warnings on most of the compilers. */
   (void)wakeupSource; /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
   #endif
   /* Add implementation of EcuM_StartWakeupSources() */

   return;
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
} /* End of EcuM_StartWakeupSources() */

FUNC(void, ECUM_CODE) EcuM_StopWakeupSources(EcuM_WakeupSourceType wakeupSource) /* PRQA S 3206 */ /* MD_EcuM_3206 */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_StopWakeupSources>                 DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
   #if (ECUM_USE_DUMMY_STATEMENT == STD_ON)
   /* dummy assignment to prevent compiler warnings on most of the compilers. */
   (void)wakeupSource; /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
   #endif
   /* Add implementation of EcuM_StopWakeupSources() */

   return;
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
} /* End of EcuM_StopWakeupSources() */

FUNC(void, ECUM_CODE) EcuM_CheckValidation(EcuM_WakeupSourceType wakeupSource)
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_CheckValidation>                   DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
   #if (ECUM_USE_DUMMY_STATEMENT == STD_ON)
   /* dummy assignment to prevent compiler warnings on most of the compilers. */
   (void)wakeupSource; /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
   #endif
   /* Add implementation of EcuM_CheckValidation() */

   return;
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
} /* End of EcuM_CheckValidation() */

#endif

#if (ECUM_BSW_ERROR_HOOK == STD_ON)
/**********************************************************************************************************************
 *  Errorhook for BSW errors during initialization
 *********************************************************************************************************************/
FUNC(void, ECUM_CODE)
EcuM_BswErrorHook(uint16 BswModuleId, uint8 ErrorId) /* PRQA S 3206 */ /* MD_EcuM_3206 */ /* COV_ECUM_CALLOUT */
{
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_BswErrorHook>                      DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/

   #if (ECUM_USE_DUMMY_STATEMENT == STD_ON)
   /* dummy assignment to prevent compiler warnings on most of the compilers. */
   (void)BswModuleId; /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
   (void)ErrorId; /* PRQA S 1338, 2983, 3112 */     /* MD_MSR_DummyStmt */
   #endif
   /* Add implementation of EcuM_BswErrorHook() */

   if (BswModuleId == ECUM_MODULE_ID)
   {
      /* Abort initialization per default if the EcuM has reported an BswError */
   #ifndef UNIT_TEST
      while (1)
      {
      }
   #endif
   }

   return;
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
} /* End of EcuM_BswErrorHook() */
#endif

#define ECUM_STOP_SEC_CALLOUT_CODE_ASIL_D
#include "EcuM_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if 0
/**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_AL_DriverInitOne>                  DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
   /* Add implementation of EcuM_AL_DriverInitOne  */
   Sensor_Position_Config_T sensor_position_config = Get_Default_Sensor_Position_Config();
   sensor_position_config.flash_read               = Sensor_Pos_SPC_Flash_Read_Wrapper;
   Init_Sensor_Position(&sensor_position_config);

   return;
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/

/**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           <USERBLOCK EcuM_AL_DriverRestartList>              DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/
   /* Add implementation of EcuM_AL_DriverRestartList  */

   return;
   /**********************************************************************************************************************
    * DO NOT CHANGE THIS COMMENT!           </USERBLOCK>                                       DO NOT CHANGE THIS COMMENT!
    *********************************************************************************************************************/

#endif
#pragma clang optimize on

/**********************************************************************************************************************
 *  END OF FILE: ECUM_CALLOUT_STUBS.C
 *********************************************************************************************************************/
