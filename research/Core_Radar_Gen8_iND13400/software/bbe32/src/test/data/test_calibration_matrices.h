/*===========================================================================*/
/**
 * @file test_calibration_matrices.h
 *
 * Test data for calibration matrices used in anglefinding unit tests.
 * These pre-initialized matrices are used for validation testing.
 */
/*===========================================================================*/

#ifndef TEST_CALIBRATION_MATRICES_H
#define TEST_CALIBRATION_MATRICES_H

#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

   /* Test calibration matrix data for UWB */
   extern const float test_k_calmat1_ctx_UWB_usc[4][8];
   extern const float test_k_calmat1_crx_UWB_usc[8][16];
   extern const float test_k_calmat1_c1_UWB_usc[32][64];
   extern const float test_k_calmat2_ctx_UWB_usc[4][8];
   extern const float test_k_calmat2_crx_UWB_usc[8][16];
   extern const float test_k_calmat2_c1_UWB_usc[32][64];

   /* Test calibration matrix data for USC */
   extern const float test_k_calmat1_ctx_USC[4][8];
   extern const float test_k_calmat1_crx_USC[8][16];
   extern const float test_k_calmat1_c1_USC[32][64];
   extern const float test_k_calmat2_ctx_USC[4][8];
   extern const float test_k_calmat2_crx_USC[8][16];
   extern const float test_k_calmat2_c1_USC[32][64];

#ifdef __cplusplus
}
#endif

#endif /* TEST_CALIBRATION_MATRICES_H */
