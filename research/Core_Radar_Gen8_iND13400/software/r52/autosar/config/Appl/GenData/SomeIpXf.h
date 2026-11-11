/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *             File:  SomeIpXf.h
 *           Config:  Gen8_iND13400.dpa
 *      ECU-Project:  Gen8_iND13400
 *
 *        Generator:  MICROSAR SomeIpXf Generator Version 4.40.00
 *                    RTE Core Version 4.40.00
 *          License:  PAI19494
 *
 *      Description:  MICROSAR SomeIpXf header file
 *********************************************************************************************************************/

/* double include prevention */
#ifndef SOMEIPXF_H
# define SOMEIPXF_H

/* PRQA S 0777, 0779 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

# include "SchM_SomeIpXf_Type.h"

# define SOMEIPXF_SW_MAJOR_VERSION (0x04U)
# define SOMEIPXF_SW_MINOR_VERSION (0x28U)
# define SOMEIPXF_SW_PATCH_VERSION (0x00U)

# define SOMEIPXF_VENDOR_ID (0x1EU)
# define SOMEIPXF_MODULE_ID (0xAEU)

# define SOMEIPXF_AR_RELEASE_MAJOR_VERSION     (0x04U)
# define SOMEIPXF_AR_RELEASE_MINOR_VERSION     (0x02U)
# define SOMEIPXF_AR_RELEASE_REVISION_VERSION  (0x02U)

/* Return Codes */
# define SOMEIPXF_E_SER_GENERIC_ERROR (0x81U)
# define SOMEIPXF_E_SER_WRONG_PROTOCOL_VERSION (0x87U)
# define SOMEIPXF_E_SER_WRONG_INTERFACE_VERSION (0x88U)
# define SOMEIPXF_E_SER_MALFORMED_MESSAGE (0x89U)
# define SOMEIPXF_E_SER_WRONG_MESSAGE_TYPE (0x8AU)

# define SOMEIPXF_START_SEC_CODE_ASIL_B
# include "SomeIpXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * SOME/IP basic transformers
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SOMEIPXF_CODE) SomeIpXf_SR_SWC_PLT_Appl_Communication_Pp_RDR_DetectionList_Event_DetectionList_Event(P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, SOMEIPXF_APPL_VAR) bufferLength, P2CONST(SR_DETECTIONS_RECORD, AUTOMATIC, SOMEIPXF_APPL_DATA) dataElement);
FUNC(Std_ReturnType, SOMEIPXF_CODE) SomeIpXf_SR_SWC_PLT_Appl_Communication_Pp_RDR_Radar_SW_Info_RDR_SW_Info(P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, SOMEIPXF_APPL_VAR) bufferLength, P2CONST(SR_RADAR_SW_INFO_RECORD, AUTOMATIC, SOMEIPXF_APPL_DATA) dataElement);
FUNC(Std_ReturnType, SOMEIPXF_CODE) SomeIpXf_SR_SWC_PLT_Appl_Communication_Pp_RDR_Radar_Status_RDR_Status(P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, SOMEIPXF_APPL_VAR) bufferLength, P2CONST(SR_RADAR_STATUS_RECORD, AUTOMATIC, SOMEIPXF_APPL_DATA) dataElement);

/**********************************************************************************************************************
 * SOME/IP basic retransformers
 *********************************************************************************************************************/

FUNC(Std_ReturnType, SOMEIPXF_CODE) SomeIpXf_Inv_SC_SR_VEHICLE_STATUS_RECORD_IV1_000UU(P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(SR_VEHICLE_STATUS_RECORD, AUTOMATIC, SOMEIPXF_APPL_VAR) dataElement);


# define SOMEIPXF_STOP_SEC_CODE_ASIL_B
# include "SomeIpXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * SOME/IP transformers
 *********************************************************************************************************************/

# define SomeIpXf_LdCom_signalPdu_RDR_1_Detections_52b391ee_Tx SomeIpXf_SR_SWC_PLT_Appl_Communication_Pp_RDR_DetectionList_Event_DetectionList_Event
# define SomeIpXf_LdCom_signalPdu_RDR_1_SW_Info_b4e751e3_Tx SomeIpXf_SR_SWC_PLT_Appl_Communication_Pp_RDR_Radar_SW_Info_RDR_SW_Info
# define SomeIpXf_LdCom_signalPdu_RDR_1_Status_9d482741_Tx SomeIpXf_SR_SWC_PLT_Appl_Communication_Pp_RDR_Radar_Status_RDR_Status

/**********************************************************************************************************************
 * SOME/IP retransformers
 *********************************************************************************************************************/

# define SomeIpXf_Inv_LdCom_signalPdu_ADAS_Vehicle_Status_638dcd82_Rx SomeIpXf_Inv_SC_SR_VEHICLE_STATUS_RECORD_IV1_000UU

# define SOMEIPXF_START_SEC_CODE_ASIL_B
# include "SomeIpXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * SomeIpXf Init/DeInit API
 *********************************************************************************************************************/

typedef uint8 SomeIpXf_ConfigType;
FUNC(void, SOMEIPXF_CODE) SomeIpXf_InitMemory(void);
FUNC(void, SOMEIPXF_CODE) SomeIpXf_Init(P2CONST(SomeIpXf_ConfigType, AUTOMATIC, SOMEIPXF_APPL_DATA) config);
FUNC(void, SOMEIPXF_CODE) SomeIpXf_DeInit(void);

# define SOMEIPXF_STOP_SEC_CODE_ASIL_B
# include "SomeIpXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* SOMEIPXF_H */
