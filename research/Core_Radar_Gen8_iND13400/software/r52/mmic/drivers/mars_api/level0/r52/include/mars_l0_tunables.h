/* @copyright 2023 indie Semiconductor.
 * This item is considered confidential and shall not be used, modified,
 * or distributed without prior written consent from Indie Semiconductor. */

#ifndef MARS_L0_TUNABLES_H
#define MARS_L0_TUNABLES_H

/* Chandra r52 Layer 0 integrator-facing timer calibration and SSI platform parameters.
 *
 * Override any symbol by defining it before #include "mars_l0_tunables.h", or pass
 * -D<MACRO_NAME>=<value> on the compiler command line.
 *
 * Each macro below documents units, affected APIs, and the effect of increasing
 * or decreasing the value. */

/* *******************************
 * TIMER CALIBRATION (Chandra r52 Layer 0)
 * ********************************/

/* MARS_TMR_SW_CYCLE_INSTR — Assumed CPU instructions consumed per busy-wait loop iteration.
 * Unit: instruction count (approximate)
 * Used by: mars_l0_tmr_wait_time (r52_l0_tmr.c) software delay loop
 * Increase: Underestimates loop cost; mars_wait_us / mars_wait_ms return early (shorter delays).
 * Decrease: Overestimates loop cost; waits longer than requested.
 * Override: -DMARS_TMR_SW_CYCLE_INSTR=<count> or #define before include
 * Constraint: CPU and compiler optimization specific; recalibrate when changing compiler or comp. optimization.
 */
#ifndef MARS_TMR_SW_CYCLE_INSTR
#define MARS_TMR_SW_CYCLE_INSTR 9u
#endif


/* *******************************
 * SSI PLATFORM (Chandra r52 Layer 0)
 * ********************************/

/* SSI_CLOCK_SPEED_LO — SPI bus clock for low-speed SSI mode.
 * Unit: Hz
 * Used by: mars_l0_ssi_set_ssi_speed, ARM_SPI_SET_BUS_SPEED (r52_l0_ssi.c)
 * Increase: Faster low-speed transfers; may violate Mars SPI speed before PLL is locked
 * Decrease: Slower boot/MBL and low-speed register access; more reliable on marginal HW.
 * Override: -DSSI_CLOCK_SPEED_LO=<hz> or #define before include
 */
#ifndef SSI_CLOCK_SPEED_LO
#define SSI_CLOCK_SPEED_LO 10000000uL
#endif

/* SSI_CLOCK_SPEED_HI — SPI bus clock for high-speed SSI mode.
 * Unit: Hz
 * Used by: mars_l0_ssi_set_ssi_speed, ARM_SPI_SET_BUS_SPEED (r52_l0_ssi.c)
 * Increase: Faster MAF/data transfers; higher Singal Integrity risk; ensure RX delay tuning matches.
 * Decrease: Slower throughput after MBL; often more stable on longer wiring.
 * Override: -DSSI_CLOCK_SPEED_HI=<hz> or #define before include
 */
#ifndef SSI_CLOCK_SPEED_HI
#define SSI_CLOCK_SPEED_HI 50000000uL
#endif

/* RX_DELAY_TIME_EVB_HI — CMSIS SPI RX delay field when Chandra EVB uses high SSI speed.
 * Unit: driver-specific delay code (ARM SPI RX delay)
 * Used by: mars_l0_ssi_init_chandra_evb (r52_l0_ssi.c) when CHANDRA_EVB_BOARD is defined
 * Increase: More receive settling time; may fix CRC/read errors at high speed.
 * Decrease: Faster sampling edge; may increase bit errors on EVB interconnect.
 * Override: -DRX_DELAY_TIME_EVB_HI=<code> or #define before include
 */
#ifndef RX_DELAY_TIME_EVB_HI
#define RX_DELAY_TIME_EVB_HI 0x02u
#endif

/* RX_DELAY_TIME_EVB_LO — CMSIS SPI RX delay field when Chandra EVB uses low SSI speed.
 * Unit: driver-specific delay code
 * Used by: mars_l0_ssi_init_chandra_evb (r52_l0_ssi.c) when CHANDRA_EVB_BOARD is defined
 * Increase: More RX margin at low speed (rarely needed).
 * Decrease: Tighter sampling; possible read instability.
 * Override: -DRX_DELAY_TIME_EVB_LO=<code> or #define before include
 */
#ifndef RX_DELAY_TIME_EVB_LO
#define RX_DELAY_TIME_EVB_LO 0x02u
#endif

/* RX_DELAY_TIME_EDU_HI — CMSIS SPI RX delay when EDU board uses high SSI speed.
 * Unit: driver-specific delay code
 * Used by: mars_l0_ssi_init_edu (r52_l0_ssi.c) when EDU_BOARD is defined
 * Increase: More receive settling on EDU host wiring at high speed.
 * Decrease: Aggressive sampling; may cause CRC/memory read failures.
 * Override: -DRX_DELAY_TIME_EDU_HI=<code> or #define before include
 */
#ifndef RX_DELAY_TIME_EDU_HI
#define RX_DELAY_TIME_EDU_HI 0x00u
#endif

/* RX_DELAY_TIME_EDU_LO — CMSIS SPI RX delay when EDU board uses low SSI speed.
 * Unit: driver-specific delay code
 * Used by: mars_l0_ssi_init_edu (r52_l0_ssi.c) when EDU_BOARD is defined
 * Increase: Additional low-speed RX margin.
 * Decrease: May narrow timing margin on EDU SPI link.
 * Override: -DRX_DELAY_TIME_EDU_LO=<code> or #define before include
 */
#ifndef RX_DELAY_TIME_EDU_LO
#define RX_DELAY_TIME_EDU_LO 0x00u
#endif

/* RX_WAIT_CYCLES_QSPI — QSPI receive wait cycles passed to Driver_SPI0.Receive.
 * Unit: wait cycles (CMSIS SPI driver)
 * Used by: mars_l0_ssi_receive (r52_l0_ssi.c) in QSPI mode
 * Increase: Longer wait before sample; can improve QSPI read reliability.
 * Decrease: Shorter wait; faster reads but possible data capture errors.
 * Override: -DRX_WAIT_CYCLES_QSPI=<cycles> or #define before include
 */
#ifndef RX_WAIT_CYCLES_QSPI
#define RX_WAIT_CYCLES_QSPI 8u
#endif

#endif /* MARS_L0_TUNABLES_H */
