/* include files */
#include <cstdint>

/*===========================================================================*\
 * Preprocessor #define MACROS
\*===========================================================================*/
#define RTE_E_OK                (0U)
#define PI                      3.14159265359
#define RAD2DEG                 (180.00 / PI)
#define DEG2RAD                 (1 / RAD2DEG)
#define US_2_MS                 (0.001f)
#define FUNC(rettype, memclass) rettype
#define SWC_PLT_CDD_Logging_CODE
#define XCP_CODE
#define TS_GLOBAL_TIME_BASE (0x08u)
typedef uint8_t Std_ReturnType;

bool Get_XCP_Over_ETH_Status(void);
void Udp_Rx_Callback(const uint8_t *udp_rx_ptr);
bool Get_Status_Calibration_Disable_CDC_Logging(void);

#ifdef TRACKER_ENABLED
uint32_t Get_Tracker_Ref_Index(void);
#endif

FUNC(Std_ReturnType, SWC_PLT_CDD_Logging_CODE)
PostRadarProcessing_Debug_Populate_Debug_Stream(void); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

FUNC(Std_ReturnType, SWC_PLT_CDD_Logging_CODE) PostRadarProcessing_Detection_Populate_Detection_Stream(void);
/* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

FUNC(Std_ReturnType, SWC_PLT_CDD_Logging_CODE) PostRadarProcessing_Header_Populate_Header_Stream(void);
/* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

FUNC(Std_ReturnType, SWC_PLT_CDD_Logging_CODE) PostRadarProcessing_MMIC_Populate_MMIC_Stream(void);
/* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

FUNC(Std_ReturnType, SWC_PLT_CDD_Logging_CODE) PostRadarProcessing_Radar_Capability_Populate_Radar_Capability_Stream(void);
/* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

FUNC(Std_ReturnType, SWC_PLT_CDD_Logging_CODE) PostRadarProcessing_Status_Populate_Status_Stream(void);
/* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

FUNC(Std_ReturnType, SWC_PLT_CDD_Logging_CODE)
PostRadarProcessing_RDD_Populate_RDD_Stream(void); /* PRQA S 0786, 3449, 0624 */ /* MD_Rte_0786, MD_Rte_3449, MD_Rte_0624 */

FUNC(void, SWC_PLT_CDD_Logging_CODE)
RE_Logging_50ms(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */

FUNC(void, SWC_PLT_CDD_Logging_CODE)
RE_Logging_Init(void); /* PRQA S 3451, 0786, 3449 */ /* MD_Rte_3451, MD_Rte_0786, MD_Rte_3449 */
FUNC(void, SWC_PLT_CDD_Logging_CODE) transmit_udp_data(void);
