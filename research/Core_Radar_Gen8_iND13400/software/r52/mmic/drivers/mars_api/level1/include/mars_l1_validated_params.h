/* @copyright 2023 indie Semiconductor.
 * This item is considered confidential and shall not be used, modified,
 * or distributed without prior written consent from Indie Semiconductor. */

#ifndef MARS_L1_VALIDATED_PARAMS_H
#define MARS_L1_VALIDATED_PARAMS_H

/* Layer 1 indie-controlled mailbox timeout parameters.
 *
 * These defaults are part of the validated library configuration. Override hooks
 * exist for indie-approved integration or test builds only; changing these values
 * can invalidate tested behavior, leave features unverified, or violate timing and
 * safety assumptions.
 *
 * Each macro below documents units, affected APIs, and the effect of increasing
 * or decreasing the value. */

/* *******************************
 * MAILBOX EXCHANGE TIMEOUT
 * ********************************/

/* MARS_MLBX_TIMEOUT_US — Maximum wait for a mailbox exchange to complete.
 * Unit: microseconds
 * Used by: mars_write_mlbx, mars_read_mlbx, mars_exchange_mlbx (Layer 1); most Layer 2
 *          command paths (activate, diag, SCP, frame control, memory CRC check, etc.)
 * Increase: Reduces spurious timeouts on slow SPI links or under CPU load; API calls
 *           block longer before returning error on a stuck MMIC.
 * Decrease: Faster failure on hung mailbox; may cause false timeouts on marginal links.
 * Override, if approved: -DMARS_MLBX_TIMEOUT_US=<us> or #define before include
 */
#ifndef MARS_MLBX_TIMEOUT_US
#define MARS_MLBX_TIMEOUT_US 5000u
#endif

/* *******************************
 * MAILBOX SPIN TIMEOUTS (Layer 1)
 * ********************************/

/* MARS_MLBX_WRITE_TIMEOUT — Busy-spin budget when waiting for mailbox slot to accept a write.
 * Unit: microseconds
 * Used by: mars_l1_mailbox_write_prv (mars_l1_mlbx.c)
 * Increase: Waits longer for a busy mailbox before write failure.
 * Decrease: Write fails faster when mailbox stays busy; may false-fail under contention.
 * Override, if approved: -DMARS_MLBX_WRITE_TIMEOUT=<us> or #define before include
 */
#ifndef MARS_MLBX_WRITE_TIMEOUT
#define MARS_MLBX_WRITE_TIMEOUT 100u
#endif

/* MARS_MLBX_READ_TIMEOUT — Wait for mailbox response after a request.
 * Unit: microseconds
 * Used by: mars_l1_mailbox_read_prv (mars_l1_mlbx.c); scaled by MARS_MLBX_TIME_OUT_SCALEING_FACTOR
 * Increase: Longer wait for MMIC response at Layer 1 before read timeout.
 * Decrease: Earlier Layer 1 read timeout; distinct from MARS_MLBX_TIMEOUT_US (Layer 1 API param).
 * Override, if approved: -DMARS_MLBX_READ_TIMEOUT=<us> or #define before include
 */
#ifndef MARS_MLBX_READ_TIMEOUT
#define MARS_MLBX_READ_TIMEOUT 5000u
#endif

#endif /* MARS_L1_VALIDATED_PARAMS_H */
