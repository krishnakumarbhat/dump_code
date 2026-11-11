/* @copyright 2023 indie Semiconductor.
 * This item is considered confidential and shall not be used, modified,
 * or distributed without prior written consent from Indie Semiconductor. */

#ifndef MARS_L1_H
#define MARS_L1_H

#ifndef DOXYGEN_SHOULD_SKIP_THIS

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
/* polyspace-begin CERT-C:PRE08-C [No action planned:Low] "Modules named based on the architecture design" */
#include "mars_l1_error.h"
/* polyspace-end CERT-C:PRE08-C [No action planned:Low] "Modules named based on the architecture design" */
#include "mars_regs_gen.h"
#include "mars_types.h"


/**********************************************************************************************************************
 * GLOBAL MACROS
 ********************************************************************************************************************/
/* polyspace-begin CERT-C:PRE00-C [No action planned:Low] "Macro required to pass mutable driver_data through const-qualified mars_self" */
/* polyspace-begin MISRA-C-2023:D4.9 [No action planned:Low] "Macro required to pass mutable driver_data through const-qualified mars_self" */
/** L0 driver_data argument when mars_self is const at L1/L2; buffer storage remains mutable in the instance. */
#define MARS_L0_DRIVER_DATA(mars_inst) ((mars_inst)->Mars_Data.Mars_Buffer.driver_data)
/* polyspace-end MISRA-C-2023:D4.9 [No action planned:Low] "Macro required to pass mutable driver_data through const-qualified mars_self" */
/* polyspace-end CERT-C:PRE00-C [No action planned:Low] "Macro required to pass mutable driver_data through const-qualified mars_self" */


/**********************************************************************************************************************
 * GLOBAL TYPEDEFS
 ********************************************************************************************************************/
/* polyspace-begin MISRA-C-2023:D4.8 [No action planned:Low] "Structure definition is required by the layer public interface" */
/* polyspace-begin CERT-C:DCL12-C [No action planned:Low] "Structure definition is required by the layer public interface" */
 typedef struct
{
    uint32 command;   /*!< Mailbox Command, 9 bits, Index identifying the specific request */
    uint32 slot;      /*!< Message Request Slot, 3 bits, The message slot the message request is written to */
    uint32 var_l;     /*!< Mailbox variable L, 28 bits, Request specific data sent by Host to MMIC */
    uint32 var_h;     /*!< Mailbox variable H, 16 bits, Request specific data sent by Host to MMIC */
} mars_mailbox_req_t; /*!< Mailbox request message structure for Layer 1 data exchange GID-349525  */
/* polyspace-end MISRA-C-2023:D4.8 [No action planned:Low] "Structure definition is required by the layer public interface" */
/* polyspace-end CERT-C:DCL12-C [No action planned:Low] "Structure definition is required by the layer public interface" */

/* polyspace-begin MISRA-C-2023:D4.8 [No action planned:Low] "Structure definition is required by the layer public interface" */
/* polyspace-begin CERT-C:DCL12-C [No action planned:Low] "Structure definition is required by the layer public interface" */
typedef struct
{
    uint32 response; /*!< Mailbox Response, 5 bits, Message processing status information */
    uint32 slot;     /*!< Index, 4 bits, The message slot the message response was read from */
    uint32 var_l;    /*!< Mailbox variable L, 28 bits, Request specific data sent by Host to MMIC */
    uint32 var_h;    /*!< Mailbox variable H, 16 bits, Request specific data sent by Host to MMIC */
} mars_mailbox_resp_t; /*!< Mailbox response message structure for Layer 1 data exchange GID-349525  */
/* polyspace-end MISRA-C-2023:D4.8 [No action planned:Low] "Structure definition is required by the layer public interface" */
/* polyspace-end CERT-C:DCL12-C [No action planned:Low] "Structure definition is required by the layer public interface" */

typedef enum
{
    MARS_OPERATION_READ = 0x0u, /* Read operation */
    MARS_OPERATION_WRITE = 0x1u, /* Write operation */
} mars_operation_en; /* Operation enumeration for memory access APIs */

typedef mars_l0_ssi_mode_en mars_ssi_mode_en; /* GID-349524 */
typedef mars_l0_ssi_speed_en mars_ssi_speed_en; /* GID-349524 */

/**********************************************************************************************************************
 * GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * GPIO FUNCTION PROTOTYPES
 *********************************************************************************************************************/
extern Mars_ReturnType mars_gpio_mlbx_read(mars_instance_t *const mars_self, mars_gpio_level_en *const level);
extern Mars_ReturnType mars_gpio_gp0_read(mars_instance_t *const mars_self, mars_gpio_level_en *const level);
extern Mars_ReturnType mars_gpio_sft_read(mars_instance_t *const mars_self, mars_gpio_level_en *const level);
extern Mars_ReturnType mars_gpio_reset_write(mars_instance_t *const mars_self, const mars_gpio_level_en level);
extern Mars_ReturnType mars_gpio_frm_en_write(mars_instance_t *const mars_self, const mars_gpio_level_en level);
extern Mars_ReturnType mars_oc_frm_en_set(mars_instance_t *const mars_self, const uint64 timestamp);
#ifndef MARS_DEBUG_SUPPORT_DISABLED
extern Mars_ReturnType mars_gpio_te_write(mars_instance_t *const mars_self, const mars_gpio_level_en level);
#endif
/**********************************************************************************************************************
 * INIT FUNCTION PROTOTYPES
 *********************************************************************************************************************/
extern Mars_ReturnType mars_layer1_init( mars_instance_t *const mars_self);

/**********************************************************************************************************************
 * TIMER FUNCTION PROTOTYPES
 *********************************************************************************************************************/
extern Mars_ReturnType mars_wait_us(mars_instance_t *const mars_self, const uint32 wait_time);
extern Mars_ReturnType mars_wait_ms(mars_instance_t *const mars_self, const uint32 wait_time);

/**********************************************************************************************************************
 * REGISTER FUNCTION PROTOTYPES
 *********************************************************************************************************************/
extern Mars_ReturnType mars_write_reg_safe( mars_instance_t *const mars_self, const uint32 reg_id, uint32 const value);
extern Mars_ReturnType mars_read_reg_safe( mars_instance_t *const mars_self, const uint32 reg_id, uint32 *const value);

/**********************************************************************************************************************
 * MAILBOX FUNCTION PROTOTYPES
 *********************************************************************************************************************/
extern Mars_ReturnType mars_write_mlbx( mars_instance_t *const mars_self, const mars_mailbox_req_t *const mlbx, const uint32 timeout);
extern Mars_ReturnType mars_read_mlbx( mars_instance_t *const mars_self, mars_mailbox_resp_t *const mlbx, const uint32 timeout);
extern Mars_ReturnType mars_exchange_mlbx( mars_instance_t *const mars_self, const mars_mailbox_req_t *const mlbx_w, mars_mailbox_resp_t *const mlbx_r, const uint32 timeout);

/**********************************************************************************************************************
 * SSI CONTROL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
extern Mars_ReturnType mars_ssi_set_mode( mars_instance_t *const mars_self, const mars_ssi_mode_en mode);
extern Mars_ReturnType mars_ssi_set_speed( mars_instance_t *const mars_self, const mars_ssi_speed_en speed);

/**********************************************************************************************************************
 * MEMORY ACCESS FUNCTION PROTOTYPES
 *********************************************************************************************************************/
extern Mars_ReturnType mars_read_mem_safe( mars_instance_t *const mars_self, uint32 const src, uint32 *const dst, const uint32 r_size);
extern Mars_ReturnType mars_write_mem_safe( mars_instance_t *const mars_self, const uint32 *const src, uint32 dst, const uint32 w_size);

/**********************************************************************************************************************
 * CRC FUNCTION PROTOTYPES
 *********************************************************************************************************************/
extern Mars_ReturnType mars_configure_crc( mars_instance_t *const mars_self);
extern Mars_ReturnType mars_calculate_crc( mars_instance_t *const mars_self, const uint32 *const data, const uint32 size, uint32 *const crc);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

#endif /* MARS_L1_H */
