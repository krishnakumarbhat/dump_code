#ifndef SWC_PLT_CDD_LOGGING_H
#define SWC_PLT_CDD_LOGGING_H

#include "Std_Types.h"

#include "header_stream.h"
#include "sh_types.h"
#include "status_stream.h"
/*===========================================================================*
 * Exported Function Prototypes
 *===========================================================================*/
Header_Stream_T *Get_Header_Stream_Ptr(void);
Status_Stream_T *Get_Status_Stream_Ptr(void);
uint8_t *Get_Req_En_Dis_CDC_Stream(void);
bool Get_XCP_Over_ETH_Status(void);
void Udp_Rx_Callback(const uint8_t *udp_rx_ptr);
bool Get_Status_Calibration_Disable_CDC_Logging(void);

#ifdef TRACKER_ENABLED
uint32_t Get_Tracker_Ref_Index(void);
#endif
#ifdef UNIT_TEST
uint8_t UT_SoAd_Frame_Transmit(Tx_Frame_Param_T *tx_frame_param_ptr);
void UT_Config_CDC_Stream(void);
#endif
/* void Calculate_Checksum(uint8_t *ptr, uint32_t len); */

/*===========================================================================*
 * Import function prototypes
 *===========================================================================*/
#endif /* SWC_PLT_CDD_LOGGING_H */
