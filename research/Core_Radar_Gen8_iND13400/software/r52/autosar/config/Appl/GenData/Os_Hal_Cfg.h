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
 *            Module: Os
 *           Program: 
 *          Customer: 
 *       Expiry Date: Not restricted
 *    License Scope : The usage is restricted to PAI19494
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Os_Hal_Cfg.h
 *   Generation Time: 2026-09-14 17:36:14
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
 * The generated code contains features that are not licensed and thus serial production is not allowed. The code may include errors.
 * 
 * [Warning] Cfg00033 - No valid license file. Serial production is not allowed! 
 * - No license file (.veplc) found in the BSW package. Please contact the Vector support to obtain valid licenses.
 *********************************************************************************************************************/

                                                                                                                        /* PRQA S 0388  EOF */ /* MD_MSR_Dir1.1 */

#ifndef OS_HAL_CFG_H
# define OS_HAL_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/*! HAL configuration major version identification. */
# define OS_CFG_HAL_MAJOR_VERSION                (4u)

/*! HAL configuration minor version identification. */
# define OS_CFG_HAL_MINOR_VERSION                (8u)

/* ISR core and level definitions */
# define OS_ISR_AA0_FUSA_IRQ_HANDLER_CORE      (0)
# define OS_ISR_AA0_FUSA_IRQ_HANDLER_LEVEL     (0)
# define OS_ISR_AA1_FUSA_IRQ_HANDLER_CORE      (0)
# define OS_ISR_AA1_FUSA_IRQ_HANDLER_LEVEL     (0)
# define OS_ISR_ANOC_LATENT_FUSA_HANDLER_CORE      (0)
# define OS_ISR_ANOC_LATENT_FUSA_HANDLER_LEVEL     (0)
# define OS_ISR_ARTIE_MEM_FUSA_HANDLER_CORE      (0)
# define OS_ISR_ARTIE_MEM_FUSA_HANDLER_LEVEL     (1)
# define OS_ISR_BBE_SP_FUSA_IRQ_HANDLER_CORE      (0)
# define OS_ISR_BBE_SP_FUSA_IRQ_HANDLER_LEVEL     (4)
# define OS_ISR_BBE_SP_GPIO0_HANDLER_CORE      (0)
# define OS_ISR_BBE_SP_GPIO0_HANDLER_LEVEL     (4)
# define OS_ISR_CANFD0_HANDLER_ISR_CORE      (0)
# define OS_ISR_CANFD0_HANDLER_ISR_LEVEL     (6)
# define OS_ISR_CANFD1_HANDLER_ISR_CORE      (0)
# define OS_ISR_CANFD1_HANDLER_ISR_LEVEL     (6)
# define OS_ISR_CMRT_ISR_CORE      (0)
# define OS_ISR_CMRT_ISR_LEVEL     (0)
# define OS_ISR_CNOC_LATENT_FUSA_HANDLER_CORE      (0)
# define OS_ISR_CNOC_LATENT_FUSA_HANDLER_LEVEL     (0)
# define OS_ISR_CRG_RMON_SWS_IRQ_HANDLER_CORE      (0)
# define OS_ISR_CRG_RMON_SWS_IRQ_HANDLER_LEVEL     (0)
# define OS_ISR_COUNTERISR_OSCOUNTER_CORE      (0)
# define OS_ISR_COUNTERISR_OSCOUNTER_LEVEL     (1)
# define OS_ISR_DMA_HANDLER_ISR_CORE      (0)
# define OS_ISR_DMA_HANDLER_ISR_LEVEL     (0)
# define OS_ISR_DSP_CLOCK_MONITOR_HANDLER_CORE      (0)
# define OS_ISR_DSP_CLOCK_MONITOR_HANDLER_LEVEL     (1)
# define OS_ISR_DATAABORT_EXCEPTION_CORE      (0)
# define OS_ISR_DATAABORT_EXCEPTION_LEVEL     (0)
# define OS_ISR_ETHERNET0_IRQ_CORE      (0)
# define OS_ISR_ETHERNET0_IRQ_LEVEL     (7)
# define OS_ISR_ETHERNET1_IRQ_CORE      (0)
# define OS_ISR_ETHERNET1_IRQ_LEVEL     (7)
# define OS_ISR_ETHERNET2_IRQ_CORE      (0)
# define OS_ISR_ETHERNET2_IRQ_LEVEL     (7)
# define OS_ISR_ETHERNET3_IRQ_CORE      (0)
# define OS_ISR_ETHERNET3_IRQ_LEVEL     (7)
# define OS_ISR_ETHERNET4_IRQ_CORE      (0)
# define OS_ISR_ETHERNET4_IRQ_LEVEL     (7)
# define OS_ISR_ETHERNET5_IRQ_CORE      (0)
# define OS_ISR_ETHERNET5_IRQ_LEVEL     (7)
# define OS_ISR_ETHERNET6_IRQ_CORE      (0)
# define OS_ISR_ETHERNET6_IRQ_LEVEL     (7)
# define OS_ISR_ETHERNET7_IRQ_CORE      (0)
# define OS_ISR_ETHERNET7_IRQ_LEVEL     (7)
# define OS_ISR_GPADC_HANDLER_ISR_CORE      (0)
# define OS_ISR_GPADC_HANDLER_ISR_LEVEL     (10)
# define OS_ISR_HSM_DMB_ISR_CORE      (0)
# define OS_ISR_HSM_DMB_ISR_LEVEL     (0)
# define OS_ISR_HSM_FUSA_ALARM_ISR_CORE      (0)
# define OS_ISR_HSM_FUSA_ALARM_ISR_LEVEL     (0)
# define OS_ISR_I2C_HANDLER_ISR_CORE      (0)
# define OS_ISR_I2C_HANDLER_ISR_LEVEL     (2)
# define OS_ISR_ILLEGAL_INSTRUCTION_EXCEPTION_CORE      (0)
# define OS_ISR_ILLEGAL_INSTRUCTION_EXCEPTION_LEVEL     (0)
# define OS_ISR_MIPI_CHP_END_HANDLER_CORE      (0)
# define OS_ISR_MIPI_CHP_END_HANDLER_LEVEL     (10)
# define OS_ISR_MIPI_CHP_FUSA_HANDLER_CORE      (0)
# define OS_ISR_MIPI_CHP_FUSA_HANDLER_LEVEL     (10)
# define OS_ISR_MIPI_CHP_START_HANDLER_CORE      (0)
# define OS_ISR_MIPI_CHP_START_HANDLER_LEVEL     (10)
# define OS_ISR_MIPI_CLOCK_MONITOR_HANDLER_CORE      (0)
# define OS_ISR_MIPI_CLOCK_MONITOR_HANDLER_LEVEL     (1)
# define OS_ISR_MIPI_FRM_END_HANDLER_CORE      (0)
# define OS_ISR_MIPI_FRM_END_HANDLER_LEVEL     (10)
# define OS_ISR_MIPI_FRM_START_HANDLER_CORE      (0)
# define OS_ISR_MIPI_FRM_START_HANDLER_LEVEL     (10)
# define OS_ISR_MM_INTF0_HANDLER_CORE      (0)
# define OS_ISR_MM_INTF0_HANDLER_LEVEL     (9)
# define OS_ISR_PREFETCHABORT_EXCEPTION_CORE      (0)
# define OS_ISR_PREFETCHABORT_EXCEPTION_LEVEL     (0)
# define OS_ISR_RA_CLOCK_MONITOR_HANDLER_CORE      (0)
# define OS_ISR_RA_CLOCK_MONITOR_HANDLER_LEVEL     (4)
# define OS_ISR_RA_ERROR_IRQ_HANDLER_CORE      (0)
# define OS_ISR_RA_ERROR_IRQ_HANDLER_LEVEL     (4)
# define OS_ISR_RA_FUSA_IRQ_HANDLER_CORE      (0)
# define OS_ISR_RA_FUSA_IRQ_HANDLER_LEVEL     (4)
# define OS_ISR_SNOC_LATENT_FUSA_HANDLER_CORE      (0)
# define OS_ISR_SNOC_LATENT_FUSA_HANDLER_LEVEL     (0)
# define OS_ISR_SERIAL_CLOCK_MONITOR_HANDLER_CORE      (0)
# define OS_ISR_SERIAL_CLOCK_MONITOR_HANDLER_LEVEL     (1)
# define OS_ISR_SYSMEM0_FUSA_HANDLER_CORE      (0)
# define OS_ISR_SYSMEM0_FUSA_HANDLER_LEVEL     (1)
# define OS_ISR_SYSMEM1_FUSA_HANDLER_CORE      (0)
# define OS_ISR_SYSMEM1_FUSA_HANDLER_LEVEL     (1)
# define OS_ISR_TIMER1_HANDLER_ISR_CORE      (0)
# define OS_ISR_TIMER1_HANDLER_ISR_LEVEL     (5)
# define OS_ISR_TIMER2_HANDLER_ISR_CORE      (0)
# define OS_ISR_TIMER2_HANDLER_ISR_LEVEL     (3)
# define OS_ISR_TIMER3_HANDLER_ISR_CORE      (0)
# define OS_ISR_TIMER3_HANDLER_ISR_LEVEL     (6)
# define OS_ISR_TIMER4_HANDLER_ISR_CORE      (0)
# define OS_ISR_TIMER4_HANDLER_ISR_LEVEL     (9)
# define OS_ISR_TIMER5_HANDLER_ISR_CORE      (0)
# define OS_ISR_TIMER5_HANDLER_ISR_LEVEL     (0)
# define OS_ISR_WATCHDOG_HANDLER_ISR_CORE      (0)
# define OS_ISR_WATCHDOG_HANDLER_ISR_LEVEL     (2)
# define OS_ISR_DSP_CTRL_ERR_FUSA_IRQ_HANDLER_CORE      (0)
# define OS_ISR_DSP_CTRL_ERR_FUSA_IRQ_HANDLER_LEVEL     (4)
# define OS_ISR_MIPI_ERR_FUSA_HANDLER_CORE      (0)
# define OS_ISR_MIPI_ERR_FUSA_HANDLER_LEVEL     (0)

/* Hardware counter timing macros */

/* Counter timing macros and constants: OsCounter */
# define OSMAXALLOWEDVALUE_OsCounter     (2147483647u) /* 0x7FFFFFFFu */
# define OSMINCYCLE_OsCounter            (1u)
# define OSTICKSPERBASE_OsCounter        (499999u)
# define OSTICKDURATION_OsCounter        (1000000u)

/*! Macro OS_NS2TICKS_OsCounter was approximated with a deviation of 0.0ppm. */
# define OS_NS2TICKS_OsCounter(x)     ( (TickType) (((((uint32)(x)) * 1) + 500000) / 1000000) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/*! Macro OS_TICKS2NS_OsCounter was approximated with a deviation of 0.0ppm. */
# define OS_TICKS2NS_OsCounter(x)     ( (PhysicalTimeType) (((((uint32)(x)) * 1000000) + 0) / 1) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/*! Macro OS_US2TICKS_OsCounter was approximated with a deviation of 0.0ppm. */
# define OS_US2TICKS_OsCounter(x)     ( (TickType) (((((uint32)(x)) * 1) + 500) / 1000) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/*! Macro OS_TICKS2US_OsCounter was approximated with a deviation of 1.1102230246251565E-10ppm. */
# define OS_TICKS2US_OsCounter(x)     ( (PhysicalTimeType) (((((uint32)(x)) * 1000) + 0) / 1) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/*! Macro OS_MS2TICKS_OsCounter was approximated with a deviation of 0.0ppm. */
# define OS_MS2TICKS_OsCounter(x)     ( (TickType) (((((uint32)(x)) * 1) + 0) / 1) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/*! Macro OS_TICKS2MS_OsCounter was approximated with a deviation of 0.0ppm. */
# define OS_TICKS2MS_OsCounter(x)     ( (PhysicalTimeType) (((((uint32)(x)) * 1) + 0) / 1) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/*! Macro OS_SEC2TICKS_OsCounter was approximated with a deviation of 0.0ppm. */
# define OS_SEC2TICKS_OsCounter(x)     ( (TickType) (((((uint32)(x)) * 1000) + 0) / 1) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
/*! Macro OS_TICKS2SEC_OsCounter was approximated with a deviation of 0.0ppm. */
# define OS_TICKS2SEC_OsCounter(x)     ( (PhysicalTimeType) (((((uint32)(x)) * 1) + 500) / 1000) ) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */




/*! Master core phyiscal core Id. */
# define OS_HAL_MASTERCORE_PHYISCALCOREID    (0uL)




/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


#endif /* OS_HAL_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_Cfg.h
 *********************************************************************************************************************/
