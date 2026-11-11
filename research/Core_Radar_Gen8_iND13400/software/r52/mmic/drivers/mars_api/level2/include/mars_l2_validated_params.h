/* @copyright 2023 indie Semiconductor.
 * This item is considered confidential and shall not be used, modified,
 * or distributed without prior written consent from Indie Semiconductor. */

#ifndef MARS_L2_VALIDATED_PARAMS_H
#define MARS_L2_VALIDATED_PARAMS_H

/* Layer 2 indie-controlled timing and transfer parameters.
 *
 * These defaults are part of the validated library configuration. Override hooks
 * exist for indie-approved integration or test builds only; changing these values
 * can invalidate tested behavior, leave features unverified, or violate timing and
 * safety assumptions.
 *
 * Each macro below documents units, affected APIs, and the effect of increasing
 * or decreasing the value. */

#include "mars_cfg.h"

/* *******************************
 * INTEGRATION TIMING — DIAGNOSTICS
 * ********************************/

/* MARS_DIAG_READ_CHUNK_SIZE — Number of diagnostic words read per SPI memory transfer.
 * Unit: 32-bit words
 * Used by: mars_read_diag (Layer 2); internal diag sampling in mars_l2_actions
 * Increase: Fewer SPI transactions per full diag sweep; larger stack arrays in
 *           mars_api.c and mars_l2_actions.c (chunk_count-sized locals).
 * Decrease: More SPI round-trips; smaller stack footprint per read iteration.
 * Override, if approved: -DMARS_DIAG_READ_CHUNK_SIZE=<words> or #define before include
 * Constraint: Must be > 0; affects stack usage in callers that declare fixed arrays.
 */
#ifndef MARS_DIAG_READ_CHUNK_SIZE
#define MARS_DIAG_READ_CHUNK_SIZE (8u)
#endif

/* *******************************
 * INTEGRATION TIMING — MAF ACTIVATION POLL
 * ********************************/

/* MARS_ACTIVATE_RDY_POLL_MSEC — Delay between RDY GPIO polls after MAF activation.
 * Unit: milliseconds
 * Used by: mars_action_activate_firmware (mars_l2_actions.c) post-activation wait loop
 * Increase: Slower detection of MAF ready; longer total wait for same poll count.
 * Decrease: Faster polling; higher CPU/GPIO load during activation wait.
 * Override, if approved: -DMARS_ACTIVATE_RDY_POLL_MSEC=<ms> or #define before include
 */
#ifndef MARS_ACTIVATE_RDY_POLL_MSEC
#define MARS_ACTIVATE_RDY_POLL_MSEC 10u
#endif

/* MARS_ACTIVATE_RDY_POLL_CNT — Maximum RDY poll iterations after MAF activation.
 * Unit: count (each iteration waits MARS_ACTIVATE_RDY_POLL_MSEC)
 * Used by: mars_action_activate_firmware activation ready wait
 * Increase: Longer total timeout before activation is reported failed (default 500 x 10 ms = 5 s).
 * Decrease: Earlier timeout if MAF never asserts ready; may fail on slow firmware boot.
 * Override, if approved: -DMARS_ACTIVATE_RDY_POLL_CNT=<count> or #define before include
 */
#ifndef MARS_ACTIVATE_RDY_POLL_CNT
#define MARS_ACTIVATE_RDY_POLL_CNT 500u
#endif

/* *******************************
 * INTEGRATION TIMING — MAILBOX EXCHANGE
 * ********************************/

/* MARS_MLBX_INIT_TIMEOUT_US — Wait for first mailbox response during MMIC init.
 * Unit: microseconds
 * Used by: mars_action_init (mars_l2_actions.c) after reset/boot handshake
 * Increase: Tolerates slower MBL boot before init reports mailbox timeout.
 * Decrease: Init may fail earlier if bootloader responds slowly.
 * Override, if approved: -DMARS_MLBX_INIT_TIMEOUT_US=<us> or #define before include
 */
#ifndef MARS_MLBX_INIT_TIMEOUT_US
#define MARS_MLBX_INIT_TIMEOUT_US 25000u
#endif

/* MARS_MAF_ACTIVATE_TIMEOUT_US — Wait for mailbox completion during MAF activation command.
 * Unit: microseconds
 * Used by: mars_action_activate_firmware (mars_l2_actions.c)
 * Increase: Allows longer firmware activation handshake before timeout error.
 * Decrease: Activation fails sooner if MAF activate command runs long.
 * Override, if approved: -DMARS_MAF_ACTIVATE_TIMEOUT_US=<us> or #define before include
 */
#ifndef MARS_MAF_ACTIVATE_TIMEOUT_US
#define MARS_MAF_ACTIVATE_TIMEOUT_US 200000u
#endif

/* MARS_RDY_TIMEOUT_US — Wait budget for MAF ready-state check via mailbox/GPIO.
 * Unit: microseconds
 * Used by: mars_action_check_maf_state; mars_start_frame, mars_stop_frame, and related APIs
 * Increase: More tolerance for MAF state transitions before reporting not-ready.
 * Decrease: Frame and state APIs may fail ready-check sooner under load.
 * Override, if approved: -DMARS_RDY_TIMEOUT_US=<us> or #define before include
 */
#ifndef MARS_RDY_TIMEOUT_US
#define MARS_RDY_TIMEOUT_US 50u
#endif

/* *******************************
 * INTEGRATION TIMING — CHIP INIT
 * ********************************/

/* MARS_INIT_RESET_LOW_TIME — Duration the reset GPIO is held low during mars_init.
 * Unit: milliseconds
 * Used by: mars_action_init (mars_l2_actions.c)
 * Increase: Longer hardware reset pulse; may help marginal power/reset timing.
 * Decrease: Shorter reset; may be insufficient for some boards if below HW minimum.
 * Override, if approved: -DMARS_INIT_RESET_LOW_TIME=<ms> or #define before include
 */
#ifndef MARS_INIT_RESET_LOW_TIME
#define MARS_INIT_RESET_LOW_TIME 1u
#endif

/* MARS_INIT_DEBUG_SEQ_DELAY — Delay between debug-mode GPIO sequencing steps in mars_init_debug.
 * Unit: microseconds
 * Used by: mars_action_init_debug (mars_l2_actions.c), repeated between TE/GPIO toggles
 * Increase: Slower debug init sequence; more margin for GPIO and MMIC state settling.
 * Decrease: Faster debug init; may race hardware if set too low.
 * Override, if approved: -DMARS_INIT_DEBUG_SEQ_DELAY=<us> or #define before include
 */
#ifndef MARS_INIT_DEBUG_SEQ_DELAY
#define MARS_INIT_DEBUG_SEQ_DELAY 5u
#endif

/* MARS_INIT_WAIT_AFTER_RESET — Wait after releasing reset before continuing init.
 * Unit: milliseconds
 * Used by: mars_action_init and mars_action_init_debug (mars_l2_actions.c)
 * Increase: More time for MMIC boot ROM / MBL before mailbox traffic.
 * Decrease: Init may proceed before chip is ready; mailbox or boot errors possible.
 * Override, if approved: -DMARS_INIT_WAIT_AFTER_RESET=<ms> or #define before include
 */
#ifndef MARS_INIT_WAIT_AFTER_RESET
#define MARS_INIT_WAIT_AFTER_RESET 5u
#endif

/* *******************************
 * PHASE LUT TRANSFER
 * ********************************/

/* MARS_PHASE_LUT_TRANSFER_CHUNK_SIZE — Words per mars_write_mem_safe / read when uploading phase LUT.
 * Unit: 32-bit words
 * Used by: mars_action_write_phase_lut, mars_action_read_phase_lut (mars_l2_actions.c)
 * Increase: Fewer SPI transactions per full LUT; larger mars_phase_lut_buffer[] on stack.
 * Decrease: More transactions; smaller stack buffer per chunk.
 * Override, if approved: -DMARS_PHASE_LUT_TRANSFER_CHUNK_SIZE=<words> or #define before include
 * Constraint: Must divide MARS_PHASE_LUT_NO_OF_ELEMENTS (mars_cfg.h); compile fails if not.
 */
#ifndef MARS_PHASE_LUT_TRANSFER_CHUNK_SIZE
#define MARS_PHASE_LUT_TRANSFER_CHUNK_SIZE 32u
#endif

#if (MARS_PHASE_LUT_NO_OF_ELEMENTS % MARS_PHASE_LUT_TRANSFER_CHUNK_SIZE)
#error MARS_PHASE_LUT_NO_OF_ELEMENTS is not an integer multiple of MARS_PHASE_LUT_TRANSFER_CHUNK_SIZE
#endif

/* *******************************
 * ZHV TIMING (Layer 2)
 * ********************************/

/* MARS_ZHV_RDY_TIMEOUT_1000_US — Ready-state wait when generating or applying ZHV table.
 * Unit: microseconds
 * Used by: mars_action_zhv_generate (mars_l2_actions.c) via mars_action_check_maf_state
 * Increase: More time for MAF to reach idle/ready during ZHV operations.
 * Decrease: ZHV flow may fail ready-check sooner.
 * Override, if approved: -DMARS_ZHV_RDY_TIMEOUT_1000_US=<us> or #define before include
 */
#ifndef MARS_ZHV_RDY_TIMEOUT_1000_US
#define MARS_ZHV_RDY_TIMEOUT_1000_US 1000u
#endif

#endif /* MARS_L2_VALIDATED_PARAMS_H */
