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
 *             File:  SomeIpXf.c
 *           Config:  Gen8_iND13400.dpa
 *      ECU-Project:  Gen8_iND13400
 *
 *        Generator:  MICROSAR SomeIpXf Generator Version 4.40.00
 *                    RTE Core Version 4.40.00
 *          License:  PAI19494
 *
 *      Description:  MICROSAR SomeIpXf implementation file
 *********************************************************************************************************************/

/* PRQA S 0777, 0779, 0857, 0715 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_MSR_Dir1.1, MD_MSR_Dir1.1 */

#include "SomeIpXf.h" /* PRQA S 0828, 0810 */ /* MD_MSR_Dir1.1, MD_MSR_Dir1.1 */

#if !defined (SOMEIPXF_LOCAL)
# define SOMEIPXF_LOCAL static
#endif

#if !defined(SOMEIPXF_LOCAL_INLINE)
# define SOMEIPXF_LOCAL_INLINE LOCAL_INLINE
#endif

/* Message Types */
#define SOMEIPXF_MSG_REQUEST (0x00U)
#define SOMEIPXF_MSG_REQUEST_NO_RETURN (0x01U)
#define SOMEIPXF_MSG_NOTIFICATION (0x02U)
#define SOMEIPXF_MSG_RESPONSE (0x80U)
#define SOMEIPXF_MSG_ERROR (0x81U)

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

#define SOMEIPXF_START_SEC_VAR_INIT_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "SomeIpXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

SOMEIPXF_LOCAL VAR(uint16, SOMEIPXF_VAR_INIT) SomeIpXf_SequenceCounter_SR_SWC_PLT_Appl_Communication_Pp_RDR_DetectionList_Event_DetectionList_Event = 1U;
SOMEIPXF_LOCAL VAR(uint16, SOMEIPXF_VAR_INIT) SomeIpXf_SequenceCounter_SR_SWC_PLT_Appl_Communication_Pp_RDR_Radar_SW_Info_RDR_SW_Info = 1U;
SOMEIPXF_LOCAL VAR(uint16, SOMEIPXF_VAR_INIT) SomeIpXf_SequenceCounter_SR_SWC_PLT_Appl_Communication_Pp_RDR_Radar_Status_RDR_Status = 1U;

#define SOMEIPXF_STOP_SEC_VAR_INIT_OsCore0_ASIL_ASIL_B_LOCAL_UNSPECIFIED
#include "SomeIpXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

#ifndef SOMEIPXF_DUMMY_STATEMENT
# define SOMEIPXF_DUMMY_STATEMENT(v) (v)=(v)
#endif
#ifndef SOMEIPXF_DUMMY_STATEMENT_CONST
# define SOMEIPXF_DUMMY_STATEMENT_CONST(v) (void)(v)
#endif

#define SOMEIPXF_START_SEC_CODE_ASIL_B
#include "SomeIpXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

SOMEIPXF_LOCAL_INLINE FUNC(void, SOMEIPXF_CODE) SomeIpXf_Copy16Bit(P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR) dst, P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA) src);

SOMEIPXF_LOCAL_INLINE FUNC(void, SOMEIPXF_CODE) SomeIpXf_Copy32Bit(P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR) dst, P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA) src);

SOMEIPXF_LOCAL_INLINE FUNC(void, SOMEIPXF_CODE) SomeIpXf_Copy64Bit(P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR) dst, P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA) src);

SOMEIPXF_LOCAL_INLINE FUNC(void, SOMEIPXF_CODE) SomeIpXf_Copy16BitEndConv(P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR) dst, P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA) src);

SOMEIPXF_LOCAL_INLINE FUNC(void, SOMEIPXF_CODE) SomeIpXf_Copy32BitEndConv(P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR) dst, P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA) src);

SOMEIPXF_LOCAL_INLINE FUNC(void, SOMEIPXF_CODE) SomeIpXf_Copy64BitEndConv(P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR) dst, P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA) src);


/**********************************************************************************************************************
 * SOME/IP copy functions
 *********************************************************************************************************************/

SOMEIPXF_LOCAL_INLINE FUNC(void, SOMEIPXF_CODE) SomeIpXf_Copy16Bit(P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR) dst, P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA) src) /* PRQA S 3219 */ /* MD_MSR_Unreachable */
{
  dst[0] = src[0];
  dst[1] = src[1];
}

SOMEIPXF_LOCAL_INLINE FUNC(void, SOMEIPXF_CODE) SomeIpXf_Copy32Bit(P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR) dst, P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA) src) /* PRQA S 3219 */ /* MD_MSR_Unreachable */
{
  dst[0] = src[0];
  dst[1] = src[1];
  dst[2] = src[2];
  dst[3] = src[3];
}

SOMEIPXF_LOCAL_INLINE FUNC(void, SOMEIPXF_CODE) SomeIpXf_Copy64Bit(P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR) dst, P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA) src) /* PRQA S 3219 */ /* MD_MSR_Unreachable */
{
  dst[0] = src[0];
  dst[1] = src[1];
  dst[2] = src[2];
  dst[3] = src[3];
  dst[4] = src[4];
  dst[5] = src[5];
  dst[6] = src[6];
  dst[7] = src[7];
}

SOMEIPXF_LOCAL_INLINE FUNC(void, SOMEIPXF_CODE) SomeIpXf_Copy16BitEndConv(P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR) dst, P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA) src) /* PRQA S 3219 */ /* MD_MSR_Unreachable */
{
  dst[0] = src[1];
  dst[1] = src[0];
}

SOMEIPXF_LOCAL_INLINE FUNC(void, SOMEIPXF_CODE) SomeIpXf_Copy32BitEndConv(P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR) dst, P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA) src) /* PRQA S 3219 */ /* MD_MSR_Unreachable */
{
  dst[0] = src[3];
  dst[1] = src[2];
  dst[2] = src[1];
  dst[3] = src[0];
}

SOMEIPXF_LOCAL_INLINE FUNC(void, SOMEIPXF_CODE) SomeIpXf_Copy64BitEndConv(P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR) dst, P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA) src) /* PRQA S 3219 */ /* MD_MSR_Unreachable */
{
  dst[0] = src[7];
  dst[1] = src[6];
  dst[2] = src[5];
  dst[3] = src[4];
  dst[4] = src[3];
  dst[5] = src[2];
  dst[6] = src[1];
  dst[7] = src[0];
}

FUNC(void, SOMEIPXF_CODE) SomeIpXf_MemCpyEndConv32(P2VAR(void, AUTOMATIC, SOMEIPXF_APPL_VAR) destination, P2CONST(void, AUTOMATIC, SOMEIPXF_APPL_DATA) source, uint32_least num); /* PRQA S 1505 */ /* MD_MSR_Rule8.7 */

/**********************************************************************************************************************
 * SOME/IP memcpy functions
 *********************************************************************************************************************/

#define SOMEIPXF_MEMCPY32ALIGN (sizeof(uint32) - 1U)

FUNC(void, SOMEIPXF_CODE) SomeIpXf_MemCpyEndConv32(P2VAR(void, AUTOMATIC, SOMEIPXF_APPL_VAR) destination, P2CONST(void, AUTOMATIC, SOMEIPXF_APPL_DATA) source, uint32_least num) /* PRQA S 1505 */ /* MD_MSR_Rule8.7 */
{
  P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA) src = (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) source; /* PRQA S 0316 */ /* MD_SomeIpXf_0316 */
  P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR) dst = (P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) destination; /* PRQA S 0316 */ /* MD_SomeIpXf_0316 */
  uint32_least i;
  for (i = 0; (i + 3U) < num ; i += 4U) /* FETA_SOMEIPXF_MEMCPYENDCONV */
  {
    SomeIpXf_Copy32BitEndConv(&dst[i], &src[i]);
  }
}

/**********************************************************************************************************************
 * SOME/IP basic transformers
 *********************************************************************************************************************/

/* PRQA S 6010, 6030, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STMIF */
FUNC(Std_ReturnType, SOMEIPXF_CODE) SomeIpXf_SR_SWC_PLT_Appl_Communication_Pp_RDR_DetectionList_Event_DetectionList_Event(P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, SOMEIPXF_APPL_VAR) bufferLength, P2CONST(SR_DETECTIONS_RECORD, AUTOMATIC, SOMEIPXF_APPL_DATA) dataElement) /* PRQA S 3673 */ /* MD_SomeIpXf_Qac */
{
  Std_ReturnType ret = E_OK;
  uint32 index = 0;

  buffer[0] = 0x00U;
  buffer[1] = 0x00U;
  SomeIpXf_Copy16BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[2], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &SomeIpXf_SequenceCounter_SR_SWC_PLT_Appl_Communication_Pp_RDR_DetectionList_Event_DetectionList_Event); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
  index += 4U;
  buffer[index] = 0x01U;
  buffer[index+1U] = 0x01U;
  buffer[index+2U] = SOMEIPXF_MSG_NOTIFICATION;
  buffer[index+3U] = E_OK;
  index += 4U;

  SomeIpXf_Copy32BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->DET_HEADER_STRUCT.HED_SENSOR_COVERAGE.HED_DET_RANGE_MAX)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
  index += 4U;
  SomeIpXf_Copy32BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->DET_HEADER_STRUCT.HED_SENSOR_COVERAGE.HED_DET_RANGE_MIN)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
  index += 4U;
  SomeIpXf_Copy32BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->DET_HEADER_STRUCT.HED_SENSOR_COVERAGE.HED_DET_SPEED_RANGE_MAX)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
  index += 4U;
  SomeIpXf_Copy32BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->DET_HEADER_STRUCT.HED_SENSOR_COVERAGE.HED_DET_SPEED_RANGE_MIN)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
  index += 4U;
  SomeIpXf_Copy32BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->DET_HEADER_STRUCT.HED_SENSOR_COVERAGE.HED_FOV_HOR_MAX)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
  index += 4U;
  SomeIpXf_Copy32BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->DET_HEADER_STRUCT.HED_SENSOR_COVERAGE.HED_FOV_HOR_MIN)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
  index += 4U;
  SomeIpXf_Copy32BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->DET_HEADER_STRUCT.HED_SENSOR_COVERAGE.HED_FOV_VER_MAX)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
  index += 4U;
  SomeIpXf_Copy32BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->DET_HEADER_STRUCT.HED_SENSOR_COVERAGE.HED_FOV_VER_MIN)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
  index += 4U;
  buffer[index] = dataElement->DET_HEADER_STRUCT.HED_RADAR_STATE.HED_DATA_QUALIFIER; /* PRQA S 2985, 4404, 4440 */ /* MD_SomeIpXf_2985, MD_MSR_AutosarBoolean, MD_SomeIpXf_4440 */
  index += 1U;
  buffer[index] = dataElement->DET_HEADER_STRUCT.HED_RADAR_STATE.HED_LOOK_ID; /* PRQA S 2985, 4404, 4440 */ /* MD_SomeIpXf_2985, MD_MSR_AutosarBoolean, MD_SomeIpXf_4440 */
  index += 1U;
  SomeIpXf_Copy16BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->DET_HEADER_STRUCT.HED_RADAR_STATE.HED_LOOK_INDEX)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
  index += 2U;
  SomeIpXf_Copy16BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->DET_HEADER_STRUCT.HED_RADAR_STATE.HED_NUM_OF_VALID_DETECTIONS)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
  index += 2U;
  SomeIpXf_Copy16BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->DET_HEADER_STRUCT.HED_RADAR_STATE.HED_SCAN_INDEX)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
  index += 2U;
  buffer[index] = dataElement->DET_HEADER_STRUCT.HED_ALIGNMENT.HED_ALIGN_HOR_QF; /* PRQA S 2985, 4404, 4440 */ /* MD_SomeIpXf_2985, MD_MSR_AutosarBoolean, MD_SomeIpXf_4440 */
  index += 1U;
  SomeIpXf_Copy32BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->DET_HEADER_STRUCT.HED_ALIGNMENT.HED_ALIGN_HOR_REF)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
  index += 4U;
  buffer[index] = dataElement->DET_HEADER_STRUCT.HED_ALIGNMENT.HED_ALIGN_VER_QF; /* PRQA S 2985, 4404, 4440 */ /* MD_SomeIpXf_2985, MD_MSR_AutosarBoolean, MD_SomeIpXf_4440 */
  index += 1U;
  SomeIpXf_Copy32BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->DET_HEADER_STRUCT.HED_ALIGNMENT.HED_ALIGN_VER_REF)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
  index += 4U;
  SomeIpXf_Copy32BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->DET_HEADER_STRUCT.HED_TIMING_PROFILES.HED_AF_TIME_INST)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
  index += 4U;
  SomeIpXf_Copy32BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->DET_HEADER_STRUCT.HED_TIMING_PROFILES.HED_AF_TIME_PEAK)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
  index += 4U;
  SomeIpXf_Copy32BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->DET_HEADER_STRUCT.HED_TIMING_PROFILES.HED_MAIN_CORE_TIME_INST)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
  index += 4U;
  SomeIpXf_Copy32BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->DET_HEADER_STRUCT.HED_TIMING_PROFILES.HED_MAIN_CORE_TIME_PEAK)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
  index += 4U;
  SomeIpXf_Copy32BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->DET_HEADER_STRUCT.HED_TIMING_PROFILES.HED_RDD_CORE_TIME_INST)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
  index += 4U;
  SomeIpXf_Copy32BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->DET_HEADER_STRUCT.HED_TIMING_PROFILES.HED_RDD_CORE_TIME_PEAK)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
  index += 4U;
  SomeIpXf_Copy32BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->DET_HEADER_STRUCT.HED_TIMING_PROFILES.HED_SP_CORE_TIME_INST)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
  index += 4U;
  SomeIpXf_Copy32BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->DET_HEADER_STRUCT.HED_TIMING_PROFILES.HED_SP_CORE_TIME_PEAK)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
  index += 4U;
  SomeIpXf_Copy32BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->DET_HEADER_STRUCT.HED_TIMESTAMP.HED_SENSOR_TIME_STAMP_NS)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
  index += 4U;
  SomeIpXf_Copy32BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->DET_HEADER_STRUCT.HED_TIMESTAMP.HED_SENSOR_TIME_STAMP_SEC)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
  index += 4U;
  buffer[index] = dataElement->DET_HEADER_STRUCT.HED_TIMESTAMP.HED_TIME_SYNC_SRC_MASTER; /* PRQA S 2985, 4404, 4440 */ /* MD_SomeIpXf_2985, MD_MSR_AutosarBoolean, MD_SomeIpXf_4440 */
  index += 1U;
  buffer[index] = dataElement->DET_HEADER_STRUCT.HED_TIMESTAMP.HED_TIME_SYNC_VALIDITY_FLAG; /* PRQA S 2985, 4404, 4440 */ /* MD_SomeIpXf_2985, MD_MSR_AutosarBoolean, MD_SomeIpXf_4440 */
  index += 1U;
  SomeIpXf_Copy32BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->DET_HEADER_STRUCT.HED_TIMESTAMP.HED_TRIGGER_TIME)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
  index += 4U;
  buffer[index] = dataElement->DET_HEADER_STRUCT.HED_DETECTION_INFO.HED_DET_BI_STATIC_COUNT; /* PRQA S 2985, 4404, 4440 */ /* MD_SomeIpXf_2985, MD_MSR_AutosarBoolean, MD_SomeIpXf_4440 */
  index += 1U;
  SomeIpXf_Copy16BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->DET_HEADER_STRUCT.HED_DETECTION_INFO.HED_DET_NUM_OF_1PASS)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
  index += 2U;
  SomeIpXf_Copy16BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->DET_HEADER_STRUCT.HED_DETECTION_INFO.HED_DET_NUM_OF_2PASS)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
  index += 2U;
  SomeIpXf_Copy16BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->DET_HEADER_STRUCT.HED_DETECTION_INFO.HED_MAX_NUM_OF_DETECTIONS)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
  index += 2U;
  SomeIpXf_Copy16BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->DET_HEADER_STRUCT.HED_DETECTION_INFO.HED_NUM_OF_RESTBINS_USED)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
  index += 2U;
  buffer[index] = dataElement->DET_HEADER_STRUCT.HED_DETECTION_INFO.HED_OPERATION_MODE; /* PRQA S 2985, 4404, 4440 */ /* MD_SomeIpXf_2985, MD_MSR_AutosarBoolean, MD_SomeIpXf_4440 */
  index += 1U;
  SomeIpXf_Copy16BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->DET_HEADER_STRUCT.HED_DETECTION_INFO.HED_PROCESSED_RANGE)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
  index += 2U;
  buffer[index] = dataElement->DET_HEADER_STRUCT.HED_DETECTION_INFO.HED_SLOPE_CORR_EXECUTIONFLAG; /* PRQA S 2985, 4404, 4440 */ /* MD_SomeIpXf_2985, MD_MSR_AutosarBoolean, MD_SomeIpXf_4440 */
  index += 1U;
  buffer[index] = dataElement->DET_HEADER_STRUCT.HED_INTERFACE_VERSION.HED_INTRFC_VERSION_ID_MAJOR; /* PRQA S 2985, 4404, 4440 */ /* MD_SomeIpXf_2985, MD_MSR_AutosarBoolean, MD_SomeIpXf_4440 */
  index += 1U;
  buffer[index] = dataElement->DET_HEADER_STRUCT.HED_INTERFACE_VERSION.HED_INTRFC_VERSION_ID_MINOR; /* PRQA S 2985, 4404, 4440 */ /* MD_SomeIpXf_2985, MD_MSR_AutosarBoolean, MD_SomeIpXf_4440 */
  index += 1U;
  buffer[index] = dataElement->DET_HEADER_STRUCT.HED_INTERFACE_VERSION.HED_INTRFC_VERSION_ID_PATCH; /* PRQA S 2985, 4404, 4440 */ /* MD_SomeIpXf_2985, MD_MSR_AutosarBoolean, MD_SomeIpXf_4440 */
  index += 1U;
  SomeIpXf_Copy64BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->DET_EtoE_HDR.EtoE_CRC)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
  index += 8U;
  SomeIpXf_Copy32BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->DET_EtoE_HDR.EtoE_COUNTER)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
  index += 4U;
  SomeIpXf_Copy32BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->DET_EtoE_HDR.EtoE_DATA_ID)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
  index += 4U;
  SomeIpXf_Copy32BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->DET_EtoE_HDR.EtoE_LENGTH)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
  index += 4U;
  {
    uint16_least cnt1;
    for (cnt1 = 0; cnt1 < 400U; cnt1++)
    {
      SomeIpXf_Copy32BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->DETECTIONS_ARRAY[cnt1].DET_AZIMUTH)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
      index += 4U;
      SomeIpXf_Copy32BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->DETECTIONS_ARRAY[cnt1].DET_AZIMUTH_ERR)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
      index += 4U;
      buffer[index] = dataElement->DETECTIONS_ARRAY[cnt1].DET_BI_STATIC_FLAG; /* PRQA S 2985, 4404, 4440 */ /* MD_SomeIpXf_2985, MD_MSR_AutosarBoolean, MD_SomeIpXf_4440 */
      index += 1U;
      buffer[index] = dataElement->DETECTIONS_ARRAY[cnt1].DET_CONFD_AZIMUTH; /* PRQA S 2985, 4404, 4440 */ /* MD_SomeIpXf_2985, MD_MSR_AutosarBoolean, MD_SomeIpXf_4440 */
      index += 1U;
      buffer[index] = dataElement->DETECTIONS_ARRAY[cnt1].DET_CONFD_ELEVATION; /* PRQA S 2985, 4404, 4440 */ /* MD_SomeIpXf_2985, MD_MSR_AutosarBoolean, MD_SomeIpXf_4440 */
      index += 1U;
      SomeIpXf_Copy32BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->DETECTIONS_ARRAY[cnt1].DET_ELEVATION)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
      index += 4U;
      SomeIpXf_Copy32BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->DETECTIONS_ARRAY[cnt1].DET_ELEVATION_ERR)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
      index += 4U;
      SomeIpXf_Copy32BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->DETECTIONS_ARRAY[cnt1].DET_EXISTENCE_PROB)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
      index += 4U;
      buffer[index] = dataElement->DETECTIONS_ARRAY[cnt1].DET_HVC_FLAG; /* PRQA S 2985, 4404, 4440 */ /* MD_SomeIpXf_2985, MD_MSR_AutosarBoolean, MD_SomeIpXf_4440 */
      index += 1U;
      buffer[index] = dataElement->DETECTIONS_ARRAY[cnt1].DET_OUTSIDE_SECTOR; /* PRQA S 2985, 4404, 4440 */ /* MD_SomeIpXf_2985, MD_MSR_AutosarBoolean, MD_SomeIpXf_4440 */
      index += 1U;
      SomeIpXf_Copy32BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->DETECTIONS_ARRAY[cnt1].DET_POINT_TARGET_PROB)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
      index += 4U;
      SomeIpXf_Copy32BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->DETECTIONS_ARRAY[cnt1].DET_RANGE)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
      index += 4U;
      SomeIpXf_Copy32BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->DETECTIONS_ARRAY[cnt1].DET_RANGE_ERR)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
      index += 4U;
      SomeIpXf_Copy32BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->DETECTIONS_ARRAY[cnt1].DET_RANGE_VELOCITY)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
      index += 4U;
      SomeIpXf_Copy32BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->DETECTIONS_ARRAY[cnt1].DET_RANGE_VELOCITY_ERR)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
      index += 4U;
      SomeIpXf_Copy32BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->DETECTIONS_ARRAY[cnt1].DET_RCS)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
      index += 4U;
      SomeIpXf_Copy32BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->DETECTIONS_ARRAY[cnt1].DET_SNR)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
      index += 4U;
      buffer[index] = dataElement->DETECTIONS_ARRAY[cnt1].DET_SUPER_RES_TARGET; /* PRQA S 2985, 4404, 4440 */ /* MD_SomeIpXf_2985, MD_MSR_AutosarBoolean, MD_SomeIpXf_4440 */
      index += 1U;
      buffer[index] = dataElement->DETECTIONS_ARRAY[cnt1].DET_VALID_FLAG; /* PRQA S 2985, 4404, 4440 */ /* MD_SomeIpXf_2985, MD_MSR_AutosarBoolean, MD_SomeIpXf_4440 */
      index += 1U;
    }
  }

  *bufferLength = index;
  if (SomeIpXf_SequenceCounter_SR_SWC_PLT_Appl_Communication_Pp_RDR_DetectionList_Event_DetectionList_Event == 65535U)
  {
    SomeIpXf_SequenceCounter_SR_SWC_PLT_Appl_Communication_Pp_RDR_DetectionList_Event_DetectionList_Event = 1U;
  }
  else
  {
    ++SomeIpXf_SequenceCounter_SR_SWC_PLT_Appl_Communication_Pp_RDR_DetectionList_Event_DetectionList_Event;
  }
  return ret;
} /* PRQA S 6010, 6030, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STMIF */
FUNC(Std_ReturnType, SOMEIPXF_CODE) SomeIpXf_SR_SWC_PLT_Appl_Communication_Pp_RDR_Radar_SW_Info_RDR_SW_Info(P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, SOMEIPXF_APPL_VAR) bufferLength, P2CONST(SR_RADAR_SW_INFO_RECORD, AUTOMATIC, SOMEIPXF_APPL_DATA) dataElement) /* PRQA S 3673 */ /* MD_SomeIpXf_Qac */
{
  Std_ReturnType ret = E_OK;
  uint32 index = 0;

  buffer[0] = 0x00U;
  buffer[1] = 0x00U;
  SomeIpXf_Copy16BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[2], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &SomeIpXf_SequenceCounter_SR_SWC_PLT_Appl_Communication_Pp_RDR_Radar_SW_Info_RDR_SW_Info); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
  index += 4U;
  buffer[index] = 0x01U;
  buffer[index+1U] = 0x01U;
  buffer[index+2U] = SOMEIPXF_MSG_NOTIFICATION;
  buffer[index+3U] = E_OK;
  index += 4U;

  SomeIpXf_Copy16BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->INFO_CALIBRATION_VERSION.STS_SMC_CAL_VER_MAJOR)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
  index += 2U;
  SomeIpXf_Copy16BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->INFO_CALIBRATION_VERSION.STS_SMC_CAL_VER_MINOR)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
  index += 2U;
  buffer[index] = dataElement->INFO_CALIBRATION_VERSION.STS_SMC_PLATFROM_VERSION; /* PRQA S 2985, 4404, 4440 */ /* MD_SomeIpXf_2985, MD_MSR_AutosarBoolean, MD_SomeIpXf_4440 */
  index += 1U;
  SomeIpXf_Copy16BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->INFO_CALIBRATION_VERSION.STS_SMC_SECTION_COMPTBLITY)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
  index += 2U;
  SomeIpXf_Copy16BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->INFO_CALIBRATION_VERSION.STS_USC_CAL_VER_MAJOR)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
  index += 2U;
  SomeIpXf_Copy16BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->INFO_CALIBRATION_VERSION.STS_USC_CAL_VER_MINOR)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
  index += 2U;
  SomeIpXf_Copy16BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->INFO_CALIBRATION_VERSION.STS_USC_SECTION_COMPTBLITY)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
  index += 2U;
  SomeIpXf_Copy32BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->INFO_MOUNTING_POS.STS_SENSOR_HEIGHT)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
  index += 4U;
  buffer[index] = dataElement->INFO_MOUNTING_POS.STS_SENSOR_MOUNT_LOCATION; /* PRQA S 2985, 4404, 4440 */ /* MD_SomeIpXf_2985, MD_MSR_AutosarBoolean, MD_SomeIpXf_4440 */
  index += 1U;
  SomeIpXf_Copy32BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->INFO_MOUNTING_POS.STS_SENSOR_MOUNT_ORNT_PITCH)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
  index += 4U;
  SomeIpXf_Copy32BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->INFO_MOUNTING_POS.STS_SENSOR_MOUNT_ORNT_ROLL)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
  index += 4U;
  SomeIpXf_Copy32BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->INFO_MOUNTING_POS.STS_SENSOR_MOUNT_ORNT_YAW)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
  index += 4U;
  SomeIpXf_Copy32BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->INFO_MOUNTING_POS.STS_SENSOR_MOUNT_POS_X)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
  index += 4U;
  SomeIpXf_Copy32BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->INFO_MOUNTING_POS.STS_SENSOR_MOUNT_POS_Y)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
  index += 4U;
  SomeIpXf_Copy32BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->INFO_MOUNTING_POS.STS_SENSOR_MOUNT_POS_Z)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
  index += 4U;
  buffer[index] = dataElement->INFO_MOUNTING_POS.STS_SENSOR_POSITION; /* PRQA S 2985, 4404, 4440 */ /* MD_SomeIpXf_2985, MD_MSR_AutosarBoolean, MD_SomeIpXf_4440 */
  index += 1U;
  buffer[index] = dataElement->INFO_SW_VERSION.STS_PBL_VERSION_FIELD1; /* PRQA S 2985, 4404, 4440 */ /* MD_SomeIpXf_2985, MD_MSR_AutosarBoolean, MD_SomeIpXf_4440 */
  index += 1U;
  buffer[index] = dataElement->INFO_SW_VERSION.STS_PBL_VERSION_FIELD2; /* PRQA S 2985, 4404, 4440 */ /* MD_SomeIpXf_2985, MD_MSR_AutosarBoolean, MD_SomeIpXf_4440 */
  index += 1U;
  buffer[index] = dataElement->INFO_SW_VERSION.STS_PBL_VERSION_FIELD3; /* PRQA S 2985, 4404, 4440 */ /* MD_SomeIpXf_2985, MD_MSR_AutosarBoolean, MD_SomeIpXf_4440 */
  index += 1U;
  buffer[index] = dataElement->INFO_SW_VERSION.STS_PBL_VERSION_FIELD4; /* PRQA S 2985, 4404, 4440 */ /* MD_SomeIpXf_2985, MD_MSR_AutosarBoolean, MD_SomeIpXf_4440 */
  index += 1U;
  buffer[index] = dataElement->INFO_SW_VERSION.STS_SW_VERSION_FIELD1; /* PRQA S 2985, 4404, 4440 */ /* MD_SomeIpXf_2985, MD_MSR_AutosarBoolean, MD_SomeIpXf_4440 */
  index += 1U;
  buffer[index] = dataElement->INFO_SW_VERSION.STS_SW_VERSION_FIELD2; /* PRQA S 2985, 4404, 4440 */ /* MD_SomeIpXf_2985, MD_MSR_AutosarBoolean, MD_SomeIpXf_4440 */
  index += 1U;
  buffer[index] = dataElement->INFO_SW_VERSION.STS_SW_VERSION_FIELD3; /* PRQA S 2985, 4404, 4440 */ /* MD_SomeIpXf_2985, MD_MSR_AutosarBoolean, MD_SomeIpXf_4440 */
  index += 1U;
  buffer[index] = dataElement->INFO_SW_VERSION.STS_SW_VERSION_FIELD4; /* PRQA S 2985, 4404, 4440 */ /* MD_SomeIpXf_2985, MD_MSR_AutosarBoolean, MD_SomeIpXf_4440 */
  index += 1U;
  buffer[index] = dataElement->INFO_HW_CAN_VERSION.STS_DET_DBC_BASE_VER_MAJOR; /* PRQA S 2985, 4404, 4440 */ /* MD_SomeIpXf_2985, MD_MSR_AutosarBoolean, MD_SomeIpXf_4440 */
  index += 1U;
  buffer[index] = dataElement->INFO_HW_CAN_VERSION.STS_DET_DBC_BASE_VER_MINOR; /* PRQA S 2985, 4404, 4440 */ /* MD_SomeIpXf_2985, MD_MSR_AutosarBoolean, MD_SomeIpXf_4440 */
  index += 1U;
  buffer[index] = dataElement->INFO_HW_CAN_VERSION.STS_HARDWARE_VERSION; /* PRQA S 2985, 4404, 4440 */ /* MD_SomeIpXf_2985, MD_MSR_AutosarBoolean, MD_SomeIpXf_4440 */
  index += 1U;
  buffer[index] = dataElement->INFO_HW_CAN_VERSION.STS_PCAN_PROTOCOL_VER_MAJOR; /* PRQA S 2985, 4404, 4440 */ /* MD_SomeIpXf_2985, MD_MSR_AutosarBoolean, MD_SomeIpXf_4440 */
  index += 1U;
  buffer[index] = dataElement->INFO_HW_CAN_VERSION.STS_PCAN_PROTOCOL_VER_MINOR; /* PRQA S 2985, 4404, 4440 */ /* MD_SomeIpXf_2985, MD_MSR_AutosarBoolean, MD_SomeIpXf_4440 */
  index += 1U;
  buffer[index] = dataElement->INFO_HW_CAN_VERSION.STS_PLATFORM_VARIANT; /* PRQA S 2985, 4404, 4440 */ /* MD_SomeIpXf_2985, MD_MSR_AutosarBoolean, MD_SomeIpXf_4440 */
  index += 1U;
  SomeIpXf_Copy16BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->INFO_HW_CAN_VERSION.STS_SERIAL_NUM_JULIAN_DAY)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
  index += 2U;
  buffer[index] = dataElement->INFO_HW_CAN_VERSION.STS_SERIAL_NUM_JULIAN_YEAR; /* PRQA S 2985, 4404, 4440 */ /* MD_SomeIpXf_2985, MD_MSR_AutosarBoolean, MD_SomeIpXf_4440 */
  index += 1U;
  SomeIpXf_Copy16BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->INFO_HW_CAN_VERSION.STS_SERIAL_NUMBER_SEQUENCE)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
  index += 2U;
  SomeIpXf_Copy64BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->INFO_EtoE_HDR.EtoE_CRC)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
  index += 8U;
  SomeIpXf_Copy32BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->INFO_EtoE_HDR.EtoE_COUNTER)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
  index += 4U;
  SomeIpXf_Copy32BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->INFO_EtoE_HDR.EtoE_DATA_ID)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
  index += 4U;
  SomeIpXf_Copy32BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->INFO_EtoE_HDR.EtoE_LENGTH)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
  index += 4U;

  *bufferLength = index;
  if (SomeIpXf_SequenceCounter_SR_SWC_PLT_Appl_Communication_Pp_RDR_Radar_SW_Info_RDR_SW_Info == 65535U)
  {
    SomeIpXf_SequenceCounter_SR_SWC_PLT_Appl_Communication_Pp_RDR_Radar_SW_Info_RDR_SW_Info = 1U;
  }
  else
  {
    ++SomeIpXf_SequenceCounter_SR_SWC_PLT_Appl_Communication_Pp_RDR_Radar_SW_Info_RDR_SW_Info;
  }
  return ret;
} /* PRQA S 6010, 6030, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STMIF */

/* PRQA S 6010, 6030, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STMIF */
FUNC(Std_ReturnType, SOMEIPXF_CODE) SomeIpXf_SR_SWC_PLT_Appl_Communication_Pp_RDR_Radar_Status_RDR_Status(P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR) buffer, P2VAR(uint32, AUTOMATIC, SOMEIPXF_APPL_VAR) bufferLength, P2CONST(SR_RADAR_STATUS_RECORD, AUTOMATIC, SOMEIPXF_APPL_DATA) dataElement) /* PRQA S 3673 */ /* MD_SomeIpXf_Qac */
{
  Std_ReturnType ret = E_OK;
  uint32 index = 0;

  buffer[0] = 0x00U;
  buffer[1] = 0x00U;
  SomeIpXf_Copy16BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[2], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &SomeIpXf_SequenceCounter_SR_SWC_PLT_Appl_Communication_Pp_RDR_Radar_Status_RDR_Status); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
  index += 4U;
  buffer[index] = 0x01U;
  buffer[index+1U] = 0x01U;
  buffer[index+2U] = SOMEIPXF_MSG_NOTIFICATION;
  buffer[index+3U] = E_OK;
  index += 4U;

  SomeIpXf_Copy32BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->STS_ALIGNMENT_HANDLER.STS_AlignmentAzimuth)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
  index += 4U;
  SomeIpXf_Copy32BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->STS_ALIGNMENT_HANDLER.STS_AlignmentElevation)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
  index += 4U;
  buffer[index] = dataElement->STS_ALIGNMENT_HANDLER.STS_AlignmentError; /* PRQA S 2985, 4404, 4440 */ /* MD_SomeIpXf_2985, MD_MSR_AutosarBoolean, MD_SomeIpXf_4440 */
  index += 1U;
  buffer[index] = dataElement->STS_ALIGNMENT_HANDLER.STS_AlignmentModeIn; /* PRQA S 2985, 4404, 4440 */ /* MD_SomeIpXf_2985, MD_MSR_AutosarBoolean, MD_SomeIpXf_4440 */
  index += 1U;
  buffer[index] = dataElement->STS_ALIGNMENT_HANDLER.STS_AlignmentModeOut; /* PRQA S 2985, 4404, 4440 */ /* MD_SomeIpXf_2985, MD_MSR_AutosarBoolean, MD_SomeIpXf_4440 */
  index += 1U;
  SomeIpXf_Copy32BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->STS_ALIGNMENT_HANDLER.STS_AzimuthStd)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
  index += 4U;
  buffer[index] = dataElement->STS_ALIGNMENT_HANDLER.STS_CalDisplay; /* PRQA S 2985, 4404, 4440 */ /* MD_SomeIpXf_2985, MD_MSR_AutosarBoolean, MD_SomeIpXf_4440 */
  index += 1U;
  SomeIpXf_Copy32BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->STS_ALIGNMENT_HANDLER.STS_CalTime)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
  index += 4U;
  buffer[index] = dataElement->STS_ALIGNMENT_HANDLER.STS_CoordinateSystemInput; /* PRQA S 2985, 4404, 4440 */ /* MD_SomeIpXf_2985, MD_MSR_AutosarBoolean, MD_SomeIpXf_4440 */
  index += 1U;
  SomeIpXf_Copy32BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->STS_ALIGNMENT_HANDLER.STS_ElevationStd)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
  index += 4U;
  SomeIpXf_Copy32BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->STS_ALIGNMENT_HANDLER.STS_InitAlignmentResultAzimuth)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
  index += 4U;
  SomeIpXf_Copy32BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->STS_ALIGNMENT_HANDLER.STS_InitAlignmentResultElevation)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
  index += 4U;
  SomeIpXf_Copy32BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->STS_ALIGNMENT_HANDLER.STS_InitAlignResultAzimuthUpdate)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
  index += 4U;
  SomeIpXf_Copy32BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->STS_ALIGNMENT_HANDLER.STS_InitAlignRsltElevationUpdate)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
  index += 4U;
  SomeIpXf_Copy32BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->STS_ALIGNMENT_HANDLER.STS_InitAlignRsltHostSpdCompFac)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
  index += 4U;
  buffer[index] = dataElement->STS_ALIGNMENT_HANDLER.STS_InitLastSuccessfulAlignMode; /* PRQA S 2985, 4404, 4440 */ /* MD_SomeIpXf_2985, MD_MSR_AutosarBoolean, MD_SomeIpXf_4440 */
  index += 1U;
  SomeIpXf_Copy32BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->STS_ALIGNMENT_HANDLER.STS_ProgressPercent)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
  index += 4U;
  buffer[index] = dataElement->STS_ALIGNMENT_HANDLER.STS_RadarTypeInput; /* PRQA S 2985, 4404, 4440 */ /* MD_SomeIpXf_2985, MD_MSR_AutosarBoolean, MD_SomeIpXf_4440 */
  index += 1U;
  buffer[index] = dataElement->STS_ALIGNMENT_AUTO.STS_AAAzimuthStd; /* PRQA S 2985, 4404, 4440 */ /* MD_SomeIpXf_2985, MD_MSR_AutosarBoolean, MD_SomeIpXf_4440 */
  index += 1U;
  SomeIpXf_Copy32BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->STS_ALIGNMENT_AUTO.STS_AACurrentAzimuth)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
  index += 4U;
  SomeIpXf_Copy16BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->STS_ALIGNMENT_AUTO.STS_AACurrentElevation)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
  index += 2U;
  buffer[index] = dataElement->STS_ALIGNMENT_AUTO.STS_AAElevationStd; /* PRQA S 2985, 4404, 4440 */ /* MD_SomeIpXf_2985, MD_MSR_AutosarBoolean, MD_SomeIpXf_4440 */
  index += 1U;
  buffer[index] = dataElement->STS_ALIGNMENT_AUTO.STS_AlignmentAutoStatus; /* PRQA S 2985, 4404, 4440 */ /* MD_SomeIpXf_2985, MD_MSR_AutosarBoolean, MD_SomeIpXf_4440 */
  index += 1U;
  buffer[index] = dataElement->STS_ALIGNMENT_AUTO.STS_AutoAlignmentFailRootCause; /* PRQA S 2985, 4404, 4440 */ /* MD_SomeIpXf_2985, MD_MSR_AutosarBoolean, MD_SomeIpXf_4440 */
  index += 1U;
  SomeIpXf_Copy16BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->STS_ALIGNMENT_AUTO.STS_AzimuthErrorNegative)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
  index += 2U;
  SomeIpXf_Copy16BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->STS_ALIGNMENT_AUTO.STS_AzimuthErrorPositive)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
  index += 2U;
  SomeIpXf_Copy32BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->STS_ALIGNMENT_AUTO.STS_AzimuthUpdates)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
  index += 4U;
  buffer[index] = (uint8)(dataElement->STS_ALIGNMENT_AUTO.STS_ElevationErrorNegative); /* PRQA S 2985, 4404, 4440 */ /* MD_SomeIpXf_2985, MD_MSR_AutosarBoolean, MD_SomeIpXf_4440 */
  index += 1U;
  buffer[index] = dataElement->STS_ALIGNMENT_AUTO.STS_ElevationErrorPositive; /* PRQA S 2985, 4404, 4440 */ /* MD_SomeIpXf_2985, MD_MSR_AutosarBoolean, MD_SomeIpXf_4440 */
  index += 1U;
  SomeIpXf_Copy32BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->STS_ALIGNMENT_AUTO.STS_ElevationUpdates)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
  index += 4U;
  buffer[index] = dataElement->STS_ALIGNMENT_AUTO.STS_HostSpdCompensationFactorQF; /* PRQA S 2985, 4404, 4440 */ /* MD_SomeIpXf_2985, MD_MSR_AutosarBoolean, MD_SomeIpXf_4440 */
  index += 1U;
  buffer[index] = dataElement->STS_ALIGNMENT_AUTO.STS_HostSpeedCompensationFactor; /* PRQA S 2985, 4404, 4440 */ /* MD_SomeIpXf_2985, MD_MSR_AutosarBoolean, MD_SomeIpXf_4440 */
  index += 1U;
  SomeIpXf_Copy16BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->STS_ALIGNMENT_AUTO.STS_RollErrorPositive)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
  index += 2U;
  SomeIpXf_Copy16BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->STS_ALIGNMENT_AUTO.STS_StartAzimuth)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
  index += 2U;
  SomeIpXf_Copy16BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->STS_ALIGNMENT_AUTO.STS_StartElevation)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
  index += 2U;
  buffer[index] = dataElement->STS_ALIGNMENT_STATIC.STS_AlignmentStaticStatus; /* PRQA S 2985, 4404, 4440 */ /* MD_SomeIpXf_2985, MD_MSR_AutosarBoolean, MD_SomeIpXf_4440 */
  index += 1U;
  buffer[index] = dataElement->STS_ALIGNMENT_STATIC.STS_ImpactByInterference; /* PRQA S 2985, 4404, 4440 */ /* MD_SomeIpXf_2985, MD_MSR_AutosarBoolean, MD_SomeIpXf_4440 */
  index += 1U;
  SomeIpXf_Copy32BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->STS_ALIGNMENT_STATIC.STS_Measured_Range)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
  index += 4U;
  SomeIpXf_Copy32BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->STS_ALIGNMENT_STATIC.STS_MeasuredRangeRate)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
  index += 4U;
  SomeIpXf_Copy32BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->STS_ALIGNMENT_STATIC.STS_MeasuredRangeRateStd)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
  index += 4U;
  SomeIpXf_Copy32BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->STS_ALIGNMENT_STATIC.STS_MeasuredRangeStd)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
  index += 4U;
  SomeIpXf_Copy32BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->STS_ALIGNMENT_STATIC.STS_MeasuredRCS)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
  index += 4U;
  SomeIpXf_Copy32BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->STS_ALIGNMENT_STATIC.STS_MeasuredRCSStd)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
  index += 4U;
  buffer[index] = dataElement->STS_ALIGNMENT_SERVICE.STS_AlignmentServiceStatus; /* PRQA S 2985, 4404, 4440 */ /* MD_SomeIpXf_2985, MD_MSR_AutosarBoolean, MD_SomeIpXf_4440 */
  index += 1U;
  SomeIpXf_Copy32BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->STS_ALIGNMENT_SERVICE.STS_AverageNumberOfDetections)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
  index += 4U;
  SomeIpXf_Copy16BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->STS_ALIGNMENT_SERVICE.STS_AverageSpeed)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
  index += 2U;
  SomeIpXf_Copy32BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->STS_ALIGNMENT_SERVICE.STS_DistanceAbsolute)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
  index += 4U;
  SomeIpXf_Copy32BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->STS_ALIGNMENT_SERVICE.STS_DistanceEffective)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
  index += 4U;
  SomeIpXf_Copy32BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->STS_ALIGNMENT_SERVICE.STS_DurationAbsolute)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
  index += 4U;
  SomeIpXf_Copy32BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->STS_ALIGNMENT_SERVICE.STS_DurationEffective)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
  index += 4U;
  buffer[index] = dataElement->STS_ALIGNMENT_SERVICE.STS_VehicleCondition; /* PRQA S 2985, 4404, 4440 */ /* MD_SomeIpXf_2985, MD_MSR_AutosarBoolean, MD_SomeIpXf_4440 */
  index += 1U;
  buffer[index] = dataElement->STS_ALIGN_SHORT_TRACK.STS_AlignmentShortTrackStatus; /* PRQA S 2985, 4404, 4440 */ /* MD_SomeIpXf_2985, MD_MSR_AutosarBoolean, MD_SomeIpXf_4440 */
  index += 1U;
  buffer[index] = dataElement->STS_CAPAB_RDR_PERF.CAP_BlockageActive; /* PRQA S 2985, 4404, 4440 */ /* MD_SomeIpXf_2985, MD_MSR_AutosarBoolean, MD_SomeIpXf_4440 */
  index += 1U;
  buffer[index] = dataElement->STS_CAPAB_RDR_PERF.CAP_BlockageProbability; /* PRQA S 2985, 4404, 4440 */ /* MD_SomeIpXf_2985, MD_MSR_AutosarBoolean, MD_SomeIpXf_4440 */
  index += 1U;
  buffer[index] = dataElement->STS_CAPAB_RDR_PERF.CAP_BlockageSensitivity; /* PRQA S 2985, 4404, 4440 */ /* MD_SomeIpXf_2985, MD_MSR_AutosarBoolean, MD_SomeIpXf_4440 */
  index += 1U;
  buffer[index] = dataElement->STS_CAPAB_RDR_PERF.CAP_BlockageStatus; /* PRQA S 2985, 4404, 4440 */ /* MD_SomeIpXf_2985, MD_MSR_AutosarBoolean, MD_SomeIpXf_4440 */
  index += 1U;
  buffer[index] = dataElement->STS_CAPAB_RDR_PERF.CAP_BlockageValue; /* PRQA S 2985, 4404, 4440 */ /* MD_SomeIpXf_2985, MD_MSR_AutosarBoolean, MD_SomeIpXf_4440 */
  index += 1U;
  buffer[index] = dataElement->STS_CAPAB_RDR_PERF.CAP_FreeSightCheckActive; /* PRQA S 2985, 4404, 4440 */ /* MD_SomeIpXf_2985, MD_MSR_AutosarBoolean, MD_SomeIpXf_4440 */
  index += 1U;
  buffer[index] = dataElement->STS_CAPAB_RDR_PERF.CAP_FreeSightCheckStatus; /* PRQA S 2985, 4404, 4440 */ /* MD_SomeIpXf_2985, MD_MSR_AutosarBoolean, MD_SomeIpXf_4440 */
  index += 1U;
  buffer[index] = dataElement->STS_CAPAB_RDR_PERF.CAP_SLBlockageFilterValue; /* PRQA S 2985, 4404, 4440 */ /* MD_SomeIpXf_2985, MD_MSR_AutosarBoolean, MD_SomeIpXf_4440 */
  index += 1U;
  buffer[index] = dataElement->STS_CAPAB_RDR_PERF.CAP_SLBlockageFlag; /* PRQA S 2985, 4404, 4440 */ /* MD_SomeIpXf_2985, MD_MSR_AutosarBoolean, MD_SomeIpXf_4440 */
  index += 1U;
  buffer[index] = dataElement->STS_CAPAB_DAMPING.CAP_DampingActive; /* PRQA S 2985, 4404, 4440 */ /* MD_SomeIpXf_2985, MD_MSR_AutosarBoolean, MD_SomeIpXf_4440 */
  index += 1U;
  SomeIpXf_Copy16BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->STS_CAPAB_DAMPING.CAP_DampingCurrent)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
  index += 2U;
  buffer[index] = dataElement->STS_CAPAB_DAMPING.CAP_DampingStandardDeviation; /* PRQA S 2985, 4404, 4440 */ /* MD_SomeIpXf_2985, MD_MSR_AutosarBoolean, MD_SomeIpXf_4440 */
  index += 1U;
  buffer[index] = dataElement->STS_CAPAB_DAMPING.CAP_DampingStatus; /* PRQA S 2985, 4404, 4440 */ /* MD_SomeIpXf_2985, MD_MSR_AutosarBoolean, MD_SomeIpXf_4440 */
  index += 1U;
  SomeIpXf_Copy16BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->STS_CAPAB_RANGE_DET.CAP_AngleAzimuthRangeEnd)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
  index += 2U;
  SomeIpXf_Copy16BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->STS_CAPAB_RANGE_DET.CAP_AngleAzimuthRangeStart)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
  index += 2U;
  SomeIpXf_MemCpyEndConv32(&buffer[index], dataElement->STS_CAPAB_RANGE_DET.CAP_MaxDetectionRangeCar, 12); /* PRQA S 0314, 0315, 0316 */ /* MD_SomeIpXf_0314, MD_SomeIpXf_0315, MD_SomeIpXf_0316 */
  index += 12U;
  SomeIpXf_MemCpyEndConv32(&buffer[index], dataElement->STS_CAPAB_RANGE_DET.CAP_MaxDetRangeMotorbike, 12); /* PRQA S 0314, 0315, 0316 */ /* MD_SomeIpXf_0314, MD_SomeIpXf_0315, MD_SomeIpXf_0316 */
  index += 12U;
  SomeIpXf_MemCpyEndConv32(&buffer[index], dataElement->STS_CAPAB_RANGE_DET.CAP_MaxDetRangePedestrian, 12); /* PRQA S 0314, 0315, 0316 */ /* MD_SomeIpXf_0314, MD_SomeIpXf_0315, MD_SomeIpXf_0316 */
  index += 12U;
  buffer[index] = dataElement->STS_CAPAB_RANGE_DET.CAP_RangeEstimationActive; /* PRQA S 2985, 4404, 4440 */ /* MD_SomeIpXf_2985, MD_MSR_AutosarBoolean, MD_SomeIpXf_4440 */
  index += 1U;
  buffer[index] = dataElement->STS_CAPAB_RANGE_DET.CAP_RangeEstimationStatus; /* PRQA S 2985, 4404, 4440 */ /* MD_SomeIpXf_2985, MD_MSR_AutosarBoolean, MD_SomeIpXf_4440 */
  index += 1U;
  buffer[index] = dataElement->STS_CAPAB_SLL_MONITOR.CAP_SideLobeLevelBeamformer; /* PRQA S 2985, 4404, 4440 */ /* MD_SomeIpXf_2985, MD_MSR_AutosarBoolean, MD_SomeIpXf_4440 */
  index += 1U;
  buffer[index] = dataElement->STS_CAPAB_SLL_MONITOR.CAP_SLLMonitoringActive; /* PRQA S 2985, 4404, 4440 */ /* MD_SomeIpXf_2985, MD_MSR_AutosarBoolean, MD_SomeIpXf_4440 */
  index += 1U;
  buffer[index] = dataElement->STS_CAPAB_SLL_MONITOR.CAP_SLLMonitoringStatus; /* PRQA S 2985, 4404, 4440 */ /* MD_SomeIpXf_2985, MD_MSR_AutosarBoolean, MD_SomeIpXf_4440 */
  index += 1U;
  buffer[index] = dataElement->STS_TIMESYNC_STATUS.STS_NO_TSYN_ERROR; /* PRQA S 2985, 4404, 4440 */ /* MD_SomeIpXf_2985, MD_MSR_AutosarBoolean, MD_SomeIpXf_4440 */
  index += 1U;
  SomeIpXf_Copy32BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->STS_TIMESYNC_STATUS.STS_POINT_OF_TRIGGER)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
  index += 4U;
  SomeIpXf_Copy16BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->STS_TIMESYNC_STATUS.STS_TIME_SYNC_OFFSET)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
  index += 2U;
  buffer[index] = dataElement->STS_SENSOR_PERF.STS_BRR_STATUS; /* PRQA S 2985, 4404, 4440 */ /* MD_SomeIpXf_2985, MD_MSR_AutosarBoolean, MD_SomeIpXf_4440 */
  index += 1U;
  SomeIpXf_Copy16BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->STS_TEMPERATURE.STS_MCU_TEMP)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
  index += 2U;
  SomeIpXf_Copy16BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->STS_TEMPERATURE.STS_MMIC_TEMP_RX)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
  index += 2U;
  SomeIpXf_Copy16BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->STS_TEMPERATURE.STS_MMIC_TEMP_TX0)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
  index += 2U;
  SomeIpXf_Copy16BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->STS_TEMPERATURE.STS_MMIC_TEMP_TX1_2)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
  index += 2U;
  SomeIpXf_Copy16BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->STS_TEMPERATURE.STS_MMIC_TEMP_TX3_4)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
  index += 2U;
  SomeIpXf_Copy32BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->STS_FAULTS.STS_CORE_ACTIVE_FAULTS)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
  index += 4U;
  SomeIpXf_Copy32BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->STS_RADAR_PROFILE.STS_AF_CORE_THROUGHPUT)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
  index += 4U;
  buffer[index] = dataElement->STS_RADAR_PROFILE.STS_MMIC_RE_INIT_COUNT; /* PRQA S 2985, 4404, 4440 */ /* MD_SomeIpXf_2985, MD_MSR_AutosarBoolean, MD_SomeIpXf_4440 */
  index += 1U;
  SomeIpXf_Copy32BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->STS_RADAR_PROFILE.STS_RDD_CORE_THROUGHPUT)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
  index += 4U;
  buffer[index] = dataElement->STS_RADAR_PROFILE.STS_SCAN_TYPE; /* PRQA S 2985, 4404, 4440 */ /* MD_SomeIpXf_2985, MD_MSR_AutosarBoolean, MD_SomeIpXf_4440 */
  index += 1U;
  buffer[index] = dataElement->STS_RADAR_PROFILE.STS_XCVR_OPERATIONAL; /* PRQA S 2985, 4404, 4440 */ /* MD_SomeIpXf_2985, MD_MSR_AutosarBoolean, MD_SomeIpXf_4440 */
  index += 1U;
  SomeIpXf_Copy32BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->STS_VEHICLE.STS_STEERING_ANGLE)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
  index += 4U;
  buffer[index] = dataElement->STS_VEHICLE.STS_STEERING_ANGLE_SIGN; /* PRQA S 2985, 4404, 4440 */ /* MD_SomeIpXf_2985, MD_MSR_AutosarBoolean, MD_SomeIpXf_4440 */
  index += 1U;
  buffer[index] = dataElement->STS_VEHICLE.STS_VEH_SPEED_DIRECTION; /* PRQA S 2985, 4404, 4440 */ /* MD_SomeIpXf_2985, MD_MSR_AutosarBoolean, MD_SomeIpXf_4440 */
  index += 1U;
  SomeIpXf_Copy32BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->STS_VEHICLE.STS_VEHICLE_SPEED_CALC)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
  index += 4U;
  buffer[index] = dataElement->STS_VEHICLE.STS_VEHICLE_SUPPLY_VOLTAGE; /* PRQA S 2985, 4404, 4440 */ /* MD_SomeIpXf_2985, MD_MSR_AutosarBoolean, MD_SomeIpXf_4440 */
  index += 1U;
  SomeIpXf_Copy32BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->STS_VEHICLE.STS_YAW_RATE_BIAS)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
  index += 4U;
  SomeIpXf_Copy64BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->STS_EtoE_HDR.EtoE_CRC)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
  index += 8U;
  SomeIpXf_Copy32BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->STS_EtoE_HDR.EtoE_COUNTER)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
  index += 4U;
  SomeIpXf_Copy32BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->STS_EtoE_HDR.EtoE_DATA_ID)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
  index += 4U;
  SomeIpXf_Copy32BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &buffer[index], (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &(dataElement->STS_EtoE_HDR.EtoE_LENGTH)); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
  index += 4U;

  *bufferLength = index;
  if (SomeIpXf_SequenceCounter_SR_SWC_PLT_Appl_Communication_Pp_RDR_Radar_Status_RDR_Status == 65535U)
  {
    SomeIpXf_SequenceCounter_SR_SWC_PLT_Appl_Communication_Pp_RDR_Radar_Status_RDR_Status = 1U;
  }
  else
  {
    ++SomeIpXf_SequenceCounter_SR_SWC_PLT_Appl_Communication_Pp_RDR_Radar_Status_RDR_Status;
  }
  return ret;
} /* PRQA S 6010, 6030, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STMIF */

/**********************************************************************************************************************
 * SOME/IP basic retransformers
 *********************************************************************************************************************/

/* PRQA S 6010, 6030, 6080 1 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STMIF */
FUNC(Std_ReturnType, SOMEIPXF_CODE) SomeIpXf_Inv_SC_SR_VEHICLE_STATUS_RECORD_IV1_000UU(P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA) buffer, uint32 bufferLength, P2VAR(SR_VEHICLE_STATUS_RECORD, AUTOMATIC, SOMEIPXF_APPL_VAR) dataElement) /* PRQA S 3673, 3206 */ /* MD_SomeIpXf_Qac, MD_SomeIpXf_3206 */
{
  Std_ReturnType ret = E_OK;
  uint32 index = 0;

  if (bufferLength >= 79U)
  {
    if (buffer[4] != 0x01U)
    {
      /* Invalid version */
      ret = SOMEIPXF_E_SER_WRONG_PROTOCOL_VERSION;
    }
    else if (buffer[5] != 0x01U)
    {
      /* Invalid version */
      ret = SOMEIPXF_E_SER_WRONG_INTERFACE_VERSION;
    }
    else if (buffer[6] != SOMEIPXF_MSG_NOTIFICATION)
    {
      /* Invalid message type */
      ret = SOMEIPXF_E_SER_WRONG_MESSAGE_TYPE;
    }
    else
    {
      index += 8U;

      SomeIpXf_Copy32BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &(dataElement->System_Status_Vehicle.SSTS_STEERING_ANGLE), (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &buffer[index]); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
      index += 4U;
      dataElement->System_Status_Vehicle.SSTS_STEERING_ANGLE_SIGN = buffer[index]; /* PRQA S 2985, 4404, 4440 */ /* MD_SomeIpXf_2985, MD_MSR_AutosarBoolean, MD_SomeIpXf_4440 */
      index += 1U;
      SomeIpXf_Copy32BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &(dataElement->System_Status_Vehicle.SSTS_VEH_ODOMETER), (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &buffer[index]); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
      index += 4U;
      dataElement->System_Status_Vehicle.SSTS_VEH_POWER_MODE_STATUS = buffer[index]; /* PRQA S 2985, 4404, 4440 */ /* MD_SomeIpXf_2985, MD_MSR_AutosarBoolean, MD_SomeIpXf_4440 */
      index += 1U;
      SomeIpXf_Copy32BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &(dataElement->System_Status_Vehicle.SSTS_VEH_SPD_COMP_FACTOR), (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &buffer[index]); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
      index += 4U;
      SomeIpXf_Copy32BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &(dataElement->System_Status_Vehicle.SSTS_VEH_SYSTEM_VOLTAGE), (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &buffer[index]); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
      index += 4U;
      SomeIpXf_Copy32BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &(dataElement->System_Status_Vehicle.SSTS_VEHICLE_SPEED_CALC), (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &buffer[index]); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
      index += 4U;
      dataElement->System_Status_Vehicle.SSTS_VEHICLE_SPEED_CALC_QF = buffer[index]; /* PRQA S 2985, 4404, 4440 */ /* MD_SomeIpXf_2985, MD_MSR_AutosarBoolean, MD_SomeIpXf_4440 */
      index += 1U;
      dataElement->System_Status_Vehicle.SSTS_VEHICLE_STATE = buffer[index]; /* PRQA S 2985, 4404, 4440 */ /* MD_SomeIpXf_2985, MD_MSR_AutosarBoolean, MD_SomeIpXf_4440 */
      index += 1U;
      SomeIpXf_Copy32BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &(dataElement->System_Status_Vehicle.SSTS_YAW_RATE_BIAS), (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &buffer[index]); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
      index += 4U;
      SomeIpXf_Copy32BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &(dataElement->System_Status_Vehicle.SSTS_YAW_RATE_CALC), (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &buffer[index]); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
      index += 4U;
      dataElement->System_Status_Vehicle.SSTS_YAW_RATE_CALC_QF = buffer[index]; /* PRQA S 2985, 4404, 4440 */ /* MD_SomeIpXf_2985, MD_MSR_AutosarBoolean, MD_SomeIpXf_4440 */
      index += 1U;
      dataElement->System_Status_Vehicle_State.SSTS_DRIVE_DIR = buffer[index]; /* PRQA S 2985, 4404, 4440 */ /* MD_SomeIpXf_2985, MD_MSR_AutosarBoolean, MD_SomeIpXf_4440 */
      index += 1U;
      dataElement->System_Status_Vehicle_State.SSTS_DRIVE_REVERSE = buffer[index]; /* PRQA S 2985, 4404, 4440 */ /* MD_SomeIpXf_2985, MD_MSR_AutosarBoolean, MD_SomeIpXf_4440 */
      index += 1U;
      dataElement->System_Status_Vehicle_State.SSTS_GEAR_POSITION = buffer[index]; /* PRQA S 2985, 4404, 4440 */ /* MD_SomeIpXf_2985, MD_MSR_AutosarBoolean, MD_SomeIpXf_4440 */
      index += 1U;
      dataElement->System_Status_Vehicle_State.SSTS_IGN_STATUS = buffer[index]; /* PRQA S 2985, 4404, 4440 */ /* MD_SomeIpXf_2985, MD_MSR_AutosarBoolean, MD_SomeIpXf_4440 */
      index += 1U;
      dataElement->System_Status_Vehicle_State.SSTS_LROS_DRIVE_DIR = buffer[index]; /* PRQA S 2985, 4404, 4440 */ /* MD_SomeIpXf_2985, MD_MSR_AutosarBoolean, MD_SomeIpXf_4440 */
      index += 1U;
      dataElement->System_Status_Vehicle_State.SSTS_LROS_DRIVE_REVERSE = buffer[index]; /* PRQA S 2985, 4404, 4440 */ /* MD_SomeIpXf_2985, MD_MSR_AutosarBoolean, MD_SomeIpXf_4440 */
      index += 1U;
      dataElement->System_Status_ADAS_Version.SSTS_CAN_PCAN_MINOR_ADAS = buffer[index]; /* PRQA S 2985, 4404, 4440 */ /* MD_SomeIpXf_2985, MD_MSR_AutosarBoolean, MD_SomeIpXf_4440 */
      index += 1U;
      dataElement->System_Status_ADAS_Version.SSTS_CAN_PCAN_MAJOR_ADAS = buffer[index]; /* PRQA S 2985, 4404, 4440 */ /* MD_SomeIpXf_2985, MD_MSR_AutosarBoolean, MD_SomeIpXf_4440 */
      index += 1U;
      SomeIpXf_Copy32BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &(dataElement->System_Status_ADAS_Version.SSTS_SW_VERSION_ADAS), (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &buffer[index]); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
      index += 4U;
      dataElement->System_Status_Absolute_Time.SSTS_VEH_AbsoluteTime_Day = buffer[index]; /* PRQA S 2985, 4404, 4440 */ /* MD_SomeIpXf_2985, MD_MSR_AutosarBoolean, MD_SomeIpXf_4440 */
      index += 1U;
      dataElement->System_Status_Absolute_Time.SSTS_VEH_AbsoluteTime_Hour = buffer[index]; /* PRQA S 2985, 4404, 4440 */ /* MD_SomeIpXf_2985, MD_MSR_AutosarBoolean, MD_SomeIpXf_4440 */
      index += 1U;
      dataElement->System_Status_Absolute_Time.SSTS_VEH_AbsoluteTime_Minute = buffer[index]; /* PRQA S 2985, 4404, 4440 */ /* MD_SomeIpXf_2985, MD_MSR_AutosarBoolean, MD_SomeIpXf_4440 */
      index += 1U;
      dataElement->System_Status_Absolute_Time.SSTS_VEH_AbsoluteTime_Month = buffer[index]; /* PRQA S 2985, 4404, 4440 */ /* MD_SomeIpXf_2985, MD_MSR_AutosarBoolean, MD_SomeIpXf_4440 */
      index += 1U;
      dataElement->System_Status_Absolute_Time.SSTS_VEH_AbsoluteTime_Second = buffer[index]; /* PRQA S 2985, 4404, 4440 */ /* MD_SomeIpXf_2985, MD_MSR_AutosarBoolean, MD_SomeIpXf_4440 */
      index += 1U;
      dataElement->System_Status_Absolute_Time.SSTS_VEH_AbsoluteTime_Year = buffer[index]; /* PRQA S 2985, 4404, 4440 */ /* MD_SomeIpXf_2985, MD_MSR_AutosarBoolean, MD_SomeIpXf_4440 */
      index += 1U;
      SomeIpXf_Copy64BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &(dataElement->SSTS_EtoE_HDR.EtoE_CRC), (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &buffer[index]); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
      index += 8U;
      SomeIpXf_Copy32BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &(dataElement->SSTS_EtoE_HDR.EtoE_COUNTER), (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &buffer[index]); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
      index += 4U;
      SomeIpXf_Copy32BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &(dataElement->SSTS_EtoE_HDR.EtoE_DATA_ID), (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &buffer[index]); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
      index += 4U;
      SomeIpXf_Copy32BitEndConv((P2VAR(uint8, AUTOMATIC, SOMEIPXF_APPL_VAR)) &(dataElement->SSTS_EtoE_HDR.EtoE_LENGTH), (P2CONST(uint8, AUTOMATIC, SOMEIPXF_APPL_DATA)) &buffer[index]); /* PRQA S 2985 */ /* MD_SomeIpXf_2985 */
    }
  }
  else
  {
    ret = SOMEIPXF_E_SER_MALFORMED_MESSAGE;
  }

  return ret;
} /* PRQA S 6010, 6030, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STMIF */

/**********************************************************************************************************************
 * SomeIpXf Init/DeInit API
 *********************************************************************************************************************/
FUNC(void, SOMEIPXF_CODE) SomeIpXf_InitMemory(void)
{
  SomeIpXf_SequenceCounter_SR_SWC_PLT_Appl_Communication_Pp_RDR_DetectionList_Event_DetectionList_Event = 1U;
  SomeIpXf_SequenceCounter_SR_SWC_PLT_Appl_Communication_Pp_RDR_Radar_SW_Info_RDR_SW_Info = 1U;
  SomeIpXf_SequenceCounter_SR_SWC_PLT_Appl_Communication_Pp_RDR_Radar_Status_RDR_Status = 1U;
}

FUNC(void, SOMEIPXF_CODE) SomeIpXf_Init(P2CONST(SomeIpXf_ConfigType, AUTOMATIC, SOMEIPXF_APPL_DATA) config) /* PRQA S 3206 */ /* MD_SomeIpXf_3206 */
{
  SOMEIPXF_DUMMY_STATEMENT(config); /* PRQA S 1338, 2983 */ /* MD_MSR_DummyStmt, MD_MSR_DummyStmt */
}

FUNC(void, SOMEIPXF_CODE) SomeIpXf_DeInit(void)
{
}

#define SOMEIPXF_STOP_SEC_CODE_ASIL_B
#include "SomeIpXf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 MISRA 2012 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_SomeIpXf_0314:  MISRA rule: Dir1.1
     Reason:          Pointer cast to void because a direct byte access is necessary.
     Risk:            No functional risk. Only a cast to void is performed.
     Prevention:      Not required.

   MD_SomeIpXf_0315:  MISRA rule: Dir1.1
     Reason:          Pointer cast to void because generic access is necessary.
     Risk:            No functional risk. Only a cast to uint8* is performed.
     Prevention:      Not required.

   MD_SomeIpXf_0316:  MISRA rule: Dir1.1
     Reason:          Pointer cast to uint8* because a direct byte access is necessary.
     Risk:            No functional risk. Only a cast to uint8* is performed.
     Prevention:      Not required.

   MD_SomeIpXf_2985:  MISRA rule: Rule2.2
     Reason:          For loops produce 0 in additions or 1 in multiplications.
     Risk:            No functional risk. There is no side effect.
     Prevention:      Not required.

   MD_SomeIpXf_3206:  MISRA rule: Rule2.7
     Reason:          The parameters are not used by the code in all possible code variants.
     Risk:            No functional risk.
     Prevention:      Not required.

   MD_SomeIpXf_4440:  MISRA rule: 10.3
     Reason:          Necessary for transformation of boolean type.
     Risk:            No functional risk. There is no side effect.
     Prevention:      Not required.

   MD_SomeIpXf_Qac:
     Reason:          This justification is used as summary justification for all deviations caused by wrong analysis tool results.
                      The used analysis tool QAC 9.0 sometimes creates wrong messages. Those deviations are no issues in the RTE code.
     Risk:            No functional risk.
     Prevention:      Not required.

*/

/**********************************************************************************************************************
  Finite Execution Time Analysis justifications
 *********************************************************************************************************************/

/* COV_JUSTIFICATION_BEGIN

  \ID FETA_SOMEIPXF_MEMCPYENDCONV
  \DESCRIPTION    Iterations to copy data from source to destination.
  \COUNTERMEASURE \S SMI-105507

COV_JUSTIFICATION_END */
