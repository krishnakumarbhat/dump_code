#ifndef SWC_PLT_CDD_XCP_H
#define SWC_PLT_CDD_XCP_H

#include "Std_Types.h"
#include "XcpAppl.h"

#define SYSMEM0_DATA_START 0x80000000
#define SYSMEM0_DATA_END   0x80200000

#define SYSMEM1_ADDR_START 0x82000000
#define SYSMEM1_ADDR_END   0x82200000

#define ARTIE_ADDR_START 0x91800000
#define ARTIE_ADDR_END   0x91820000

#define R52TCM_ADDR_START 0x7FFE0000
#define R52TCM_ADDR_END   0x80000000

#define BBE32_DRAM_START 0x84020000
#define BBE32_DRAM_END   0x84040000

#define R52TCMA_ADDR_START 0x00000000
#define R52TCMA_ADDR_END   0x00010000

#define R52TCMA_ADDR_START_WRITE 0x00000040

#define XCP_MM1_FCRU_FAULT_COUNT ((uint8_t)0x40) /* FCRU has 64 different failure types (0-63) */

/* <Domain Handler>, <Domain>, <No. of Faults in Domain> */
#define XCP_FAULT_INJECTION_ELEMENT(x)                                                                                            \
   {                                                                                                                              \
      x##_FaultHandlers, XCP_INJECT_SYS_DOMAIN_##x, NUM_ELEMS(x##_FaultHandlers)                                                  \
   }

#define XCP_INTERNAL_WATCHDOG_FAULT ((uint8_t)0x00) /* Internal Watchdog Fault */
#define XCP_EXTERNAL_WATCHDOG_FAULT ((uint8_t)0x01) /* External Watchdog Fault */

/*Fault Injection Configuration for MM1 FCRU Faults*/
#define XCP_MM1_FAULT_ENTRY                                                                                                       \
   {                                                                                                                              \
      CS_FCRU_Fault_Injection, XCP_MM1_FCRU_0_3F, 0x00, 0x3F, 0x00, 0x01                                                          \
   }                                                                                                                              \
   /*FCRU Fault Injection with 64 different failure types (0-63) and 2 different injection control types (0-1)*/
#define XCP_MM1_FAULT_ENTRY_8                                                                                                     \
   XCP_MM1_FAULT_ENTRY, XCP_MM1_FAULT_ENTRY, XCP_MM1_FAULT_ENTRY, XCP_MM1_FAULT_ENTRY, XCP_MM1_FAULT_ENTRY, XCP_MM1_FAULT_ENTRY,  \
      XCP_MM1_FAULT_ENTRY, XCP_MM1_FAULT_ENTRY
#define XCP_MM1_FAULT_ENTRY_16 XCP_MM1_FAULT_ENTRY_8, XCP_MM1_FAULT_ENTRY_8
#define XCP_MM1_FAULT_ENTRY_32 XCP_MM1_FAULT_ENTRY_16, XCP_MM1_FAULT_ENTRY_16
#define XCP_MM1_FAULT_ENTRY_64 XCP_MM1_FAULT_ENTRY_32, XCP_MM1_FAULT_ENTRY_32
#define XCP_FLASH_ADDRESS_MASK (0xFFFFFFFFU)

extern const uint32_t __USC_FLASH_START_ADDRESS[];
extern const uint32_t __USC_FLASH_BLOCK_SIZE;
extern const uint32_t __SMC_FLASH_START_ADDRESS[];
extern const uint32_t __SMC_FLASH_BLOCK_SIZE;

/* SMC FLASH MEMORY SECTIONS */
#define SMC_CAL_PTP_START_ADDR   ((uint32_t)(&__SMC_FLASH_START_ADDRESS))
#define SMC_CAL_FLASH_BLOCK_SIZE ((uint32_t)(&(__SMC_FLASH_BLOCK_SIZE)))
#define SMC_CAL_PTP_END_ADDR     (SMC_CAL_PTP_START_ADDR + (SMC_CAL_FLASH_BLOCK_SIZE - 1))
/* USC FLASH MEMORY SECTIONS */
#define USC_CAL_PTP_START_ADDR            (((uint32_t)(&__USC_FLASH_START_ADDRESS)))
#define USC_CAL_FLASH_BLOCK_SIZE          ((uint32_t)(&__USC_FLASH_BLOCK_SIZE))
#define USC_CAL_PTP_END_ADDR              (USC_CAL_PTP_START_ADDR + (USC_CAL_FLASH_BLOCK_SIZE - 1))
#define XCP_PROGRAM_CMD_MAX_SIZE(channel) ((uint8_t)(Xcp_ChannelInfo[(channel)].MaxCto - 2U))
#define XCP_FLASH_PAGE_SIZE               (256U)
#define XCP_USC_SMC_PGM_IDLE              (0x00U)
#define XCP_USC_SMC_PGM_CLEAR             (0x01U)
#define XCP_USC_SMC_PGM_WRITE             (0x02U)
/* OTP memory sections */
#define OTP_MCU_ID_ADDR1 (0x8B000EECU)
#define OTP_MCU_ID_ADDR2 (0x8B000EF0U)
#define OTP_MCU_ID_ADDR3 (0x8B000EF4U)

#define XCP_RFBIST_DEBUG_CMD_SUPPORT (11U)

typedef enum XCP_ModeManger1_Faults_Tag
{
   XCP_MM1_FCRU_0_3F,
   XCP_MM1_MAX_FAULT
} XCP_ModeManger1_Faults_T;

typedef enum XCP_ModeManger2_Faults_Tag
{
   XCP_MM2_RESERVED_0,
   XCP_MM2_MAX_FAULT
} XCP_ModeManger2_Faults_T;

typedef enum XCP_ModeManger3_Faults_Tag
{
   XCP_MM3_MCU_STARTUP_FAULT,            /*MCU Startup Failure Type :0*/
   XCP_MM3_REPETITIVE_RESET_FAULT,       /*Repetitive Resets Failute Type :1*/
   XCP_MM3_SIGNAL_INTIGRITY_FAULT,       /*Signal Intigrity Failute Type : 2*/
   XCP_MM3_IPC_FAULT,                    /*IPC Fault Failure Type:3*/
   XCP_MM3_PMIC_MCU_COMMUNICATION_FAULT, /*PMIC-MCU Communication Fault Type:4*/
   XCP_MM3_EXT_WATCHDOG_FAULT,           /*External Watchdog Fault Type:5*/
   XCP_MM3_MAX_FAULT
} XCP_ModeManger3_Faults_T;

typedef enum XCP_ModeManger4_Faults_Tag
{
   XCP_MM4_WATCHDOG_FAULT, /*Watchdog Handler Failure Type:0*/
   XCP_MM4_RESERVED_1,
   XCP_MM4_RESERVED_2,
   XCP_MM4_RESERVED_3,
   XCP_MM4_RESERVED_4,
   XCP_MM4_OPRTN_TRANSITIONS_FAULT,   /*Test OperationMode transitions (startup and shutdown transitions) :5*/
   XCP_MM4_EXTERNAL_INTERFACES_FAULT, /*Modify external interfaces from integrator :6*/
   XCP_MM4_MAX_FAULT
} XCP_ModeManger4_Faults_T;

typedef enum XCP_RSV_Faults_Tag
{
   XCP_RSV_RESERVED_0,
   XCP_RSV_MAX_FAULT
} XCP_RSV_Faults_T;

typedef enum XCP_RC1_Faults_Tag
{
   XCP_RC1_RESERVED_0,
   XCP_RC1_RESERVED_1,
   XCP_RC1_RESERVED_2,
   XCP_RC1_SENSOR_DEAD_FAULT,      /*Sensor Dead Fault 0X03*/
   XCP_RC1_SAFETY_INTIGRITY_FAULT, /*Safety Integrity  Fault 0X04*/
   XCP_RC1_SAFE_STARTUP_FAULT,     /*Safe Startup Fault 0X05*/
   XCP_RC1_RESERVED_6,
   XCP_RC1_MMIC_UNDER_TEMP_FAULT, /*MMIC Under Temperature Fault 0X07*/
   XCP_RC1_MMIC_OVER_TEMP_FAULT,  /*MMIC Over Temperature Fault 0X08*/
   XCP_RC1_MMIC_ID_FAULT,         /*MMIC ID Fault 0X09*/
   XCP_RC1_LOOKINDEX_STALE,       /*Look Index Stale Fault 0X0A*/
   XCP_RC1_RESERVED_11,
   XCP_RC1_DETECTION_PROCESSING_LOOP_OVERRUN_FAULT, /*Detection processing loop overrun Fault 0X0C*/
   XCP_RC1_SMC_CHECKSUM_FAULT,                      /*SMC Checksum Fault 0X0D*/
   XCP_RC1_USC_VALIDATION_FAULT,                    /*USC Validation Fault 0X0E*/
   XCP_RC1_LOOPBACK_TEST_FAULT,                     /*Loopback Fault 0X0F*/
   XCP_RC1_FUNCTIONAL_CONFIGURATION_FAULT,          /*Functional Configuration Fault 0X10*/
   XCP_RC1_MAX_FAULT
} XCP_RC1_Faults_T;

typedef enum XCP_RC2_Faults_Tag
{
   XCP_RC2_RESERVED_0,
   XCP_RC2_ACQUISITION_OVERFLOW_FAULT, /*Acquisition Overflow Fault*/
   XCP_RC2_MMIC_TEMP_SET_FAULT,        /* MMIC temperature set Fault*/
   XCP_RC2_MAX_FAULT
} XCP_RC2_Faults_T;

typedef enum XCP_RC3_Faults_Tag
{
   XCP_RC3_RESERVED_0,
   XCP_RC3_MAX_FAULT
} XCP_RC3_Faults_T;

typedef enum XCP_RC4_Faults_Tag
{
   XCP_RC4_RESERVED_0,
   XCP_RC4_MAX_FAULT
} XCP_RC4_Faults_T;

typedef enum XCP_PT1_Faults_Tag
{
   XCP_PT1_PLATFORM_TIME_FAULT, /* Platform Time Fault*/
   XCP_PT1_MAX_FAULT
} XCP_PT1_Faults_T;

extern uint8_t XCP_Static_Align_Enabled;
extern uint8_t Stream_Handler_En_XCP;
extern FUNC(uint8, XCP_CODE) Xcp_Connect_Status(void);
extern FUNC(Std_ReturnType, SWC_PLT_CDD_XCP_CODE) Trigger_Periodic_XCP_Event(void);
extern FUNC(Std_ReturnType, SWC_PLT_CDD_XCP_CODE) Trigger_Look_Select_XCP_Event(uint8_t EventID);

#endif
