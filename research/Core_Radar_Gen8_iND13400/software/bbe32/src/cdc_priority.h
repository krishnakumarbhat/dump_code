/* A-PRISM priority-ranked CDC packing (F5 saturation mitigation).
 * Score s = SNR / r^2 keeps near strong returns, drops far weak clutter
 * when the record cap binds. Bounded insertion selection, zero heap.
 */
#ifndef CDC_PRIORITY_H
#define CDC_PRIORITY_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define CDC_PRIO_MAXREC (5016)

/* Score one record: snr_db and range_m inputs. Higher = keep first. */
float CdcPriorityScore(float snr_db, float range_m);

/* Stable selection of top-k indices by score (insertion into caller idx).
 * score[0..n), idx[0..n) scratch/output. Returns kept count. */
int32_t CdcSelectTopK(const float *score, int32_t n, int32_t k, int32_t *idx);

#ifdef __cplusplus
}
#endif

#endif /* CDC_PRIORITY_H */
