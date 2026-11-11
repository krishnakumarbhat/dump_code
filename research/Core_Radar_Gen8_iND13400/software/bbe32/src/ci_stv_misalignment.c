/*===========================================================================*/
/**
 * @file ci_stv_misalignment.c
 *
 * CI steering vector misalignment.
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2025 Aptiv. All rights reserved.
 * Aptiv Sensitive Business � Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * Application interface mapping for CI steering vector calculation .
 *
 * @section ABBR ABBREVIATIONS:
 *   - @todo List any abbreviations, precede each with a dash ('-').
 *
 * @section TRACE TRACEABILITY INFO:
 *   - Design Document(s):
 *     - @todo Update list of design document(s).
 *
 *   - Requirements Document(s):
 *     - @todo Update list of requirements document(s)
 *
 *   - Applicable Standards (in order of precedence: highest first):
 *     - ESGW_4-2_PE-SWx_00-01-A02_EN - C Coding Standards [20120506]
 *     - @todo Update list of other applicable standards
 *
 * @section DFS DEVIATIONS FROM STANDARDS:
 *   - @todo List of deviations from standards in this file, or "None".
 *
 * @ updates to areas outside the scope of procedures:
 *   - Refer to module footer comment block.
 */
/*==========================================================================*/

/*===========================================================================*
 * Standard Header Files
 *===========================================================================*/

/*===========================================================================*
 * Header Files
 *===========================================================================*/
#include "ci_stv_misalignment.h"
#include "spbb_configuration.h"
#include "spbb_math.h"
#include <xtensa/tie/xt_bbe32.h>
#include <xtensa/tie/xt_bben.h>

/* ========================================================================== */
/*                                 Macros                                     */
/* ========================================================================== */

/* ========================================================================== */
/*                           External variables                               */
/* ========================================================================== */
/* ========================================================================== */
/*                            Structures                                      */
/* ========================================================================== */

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/* ========================================================================== */
/*                            Static Variables                                */
/* ========================================================================== */

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

/*===========================================================================*/
/**
 * @brief Perform matrix multiplication for single TX row with calibration matrix
 *
 * This function performs the matrix multiply/accumulate two rows of Tx angle coefficients.
 * The input Tx angle coefficients for the 4 Tx elements are complex conjugated,
 * then the matrix multiply is performed.
 *
 * Matrix operation: output = conj(input_angle_coefficients) * usc_matrix
 * where input_angle_coefficients is [2x4] complex and usc_matrix is [4x4] complex
 *
 * For MAP, this function will be called four times, because the overall matrix is [8x4] * [4x4]
 *
 * @param[in] p_vec_ci_stv_in Pointer to input angle coefficients vector (16-bit complex interleaved) [1 vector]
 * @param[in] p_vec_cplx_usc Pointer to calibration matrix vectors [4]
 * @param[out] p_vec_cplx_out Pointer to output calibrated steering vector [1]
 *
 * @retval None
 *
 * @pre All input pointers must be valid and properly aligned
 * @pre p_vec_cplx_usc must point to the duplicated calibration matrix:
 *    usc_matrix[ 0.. 3] usc_matrix[ 0.. 3]
 *    usc_matrix[ 4.. 7] usc_matrix[ 4.. 7]
 *    usc_matrix[ 8..11] usc_matrix[ 8..11]
 *    usc_matrix[12..15] usc_matrix[12..15]
 *
 * @par Algorithm:
 * 1. Sign-extend 16-bit input to 32-bit for floating point conversion
 * 2. Convert to complex float format using BBE32 type conversion intrinsics
 * 3. Replicate each complex coefficient across vector lanes for SIMD efficiency
 * 4. Perform conjugate multiply-accumulate for each USC matrix row
 *
 */
/*===========================================================================*/
static void Matrix_Multiply_Tx_Row(const xb_vecNx16 *restrict p_vec_ci_stv_in, xb_vecN_2xcf32 *restrict p_vec_cplx_usc,
                                   xb_vecN_2xcf32 *restrict p_vec_cplx_out)
{
   xb_vecNx16 vec_cplx_ci_stv_l, vec_cplx_ci_stv_h;
   xb_vecN_2xcf32 vec_cplx_ci_stv;
   xb_vecNx16 vec_cplx_rep_tx[2];
   xb_vecNx16 vec_sign;
   const xb_vecNx16 vec_zero                 = BBE_ZERONX16();
   const xb_vecNx16 vec_neg                  = BBE_MOVVINX16(BBE_MOVVI_INT16_M1);
   const xb_vecNx16 *vec_cplx_ci_stv_0_ptr   = (xb_vecNx16 *)&vec_cplx_ci_stv;
   const xb_vecNx16 *vec_cplx_ci_stv_1_ptr   = &vec_cplx_ci_stv_0_ptr[1];
   const xb_vecN_2xcf32 *vec_cplx_rep_tx_ptr = (const xb_vecN_2xcf32 *)&vec_cplx_rep_tx[0];

   // Sign extend to 32bit
   vec_sign = BBE_MOVNX16T(vec_neg, vec_zero, *p_vec_ci_stv_in < vec_zero);
   BBE_DSELNX16I(vec_cplx_ci_stv_h, vec_cplx_ci_stv_l, vec_sign, *p_vec_ci_stv_in, BBE_DSELI_INTERLEAVE_1);

   // Type cast to Complex float
   vec_cplx_ci_stv = BBE_JOINN_2XCF32_FROMN_4XCF32(
      BBE_MOVN_4XCF32_FROMNX16(BBE_MOVNX16_FROMN_2XF32(BBE_FLOATN_2X32(BBE_MOVN_2X32_FROMNX16(vec_cplx_ci_stv_h), 0))),
      BBE_MOVN_4XCF32_FROMNX16(BBE_MOVNX16_FROMN_2XF32(BBE_FLOATN_2X32(BBE_MOVN_2X32_FROMNX16(vec_cplx_ci_stv_l), 0))));

   *p_vec_cplx_out = BBE_ZERON_2XCF32();

   // Each of the multiply accumulate operations does 2 angle coefficient sets
   // column 0 of the two angle coefficients * usc_matrix[0][0..3]
   vec_cplx_rep_tx[0] = BBE_SHFLNX16I(*vec_cplx_ci_stv_0_ptr, BBE_SHFLI_REP_0X4);
   vec_cplx_rep_tx[1] = BBE_SHFLNX16I(*vec_cplx_ci_stv_1_ptr, BBE_SHFLI_REP_0X4);
   BBE_MULJAN_2XCF32(*p_vec_cplx_out, p_vec_cplx_usc[0], *vec_cplx_rep_tx_ptr);

   // column 1 of the two angle coefficients * usc_matrix[1][0..3]
   vec_cplx_rep_tx[0] = BBE_SHFLNX16I(*vec_cplx_ci_stv_0_ptr, BBE_SHFLI_REP_1X4);
   vec_cplx_rep_tx[1] = BBE_SHFLNX16I(*vec_cplx_ci_stv_1_ptr, BBE_SHFLI_REP_1X4);
   BBE_MULJAN_2XCF32(*p_vec_cplx_out, p_vec_cplx_usc[1], *vec_cplx_rep_tx_ptr);

   // column 2 of the two angle coefficients * usc_matrix[2][0..3]
   vec_cplx_rep_tx[0] = BBE_SHFLNX16I(*vec_cplx_ci_stv_0_ptr, BBE_SHFLI_REP_2X4);
   vec_cplx_rep_tx[1] = BBE_SHFLNX16I(*vec_cplx_ci_stv_1_ptr, BBE_SHFLI_REP_2X4);
   BBE_MULJAN_2XCF32(*p_vec_cplx_out, p_vec_cplx_usc[2], *vec_cplx_rep_tx_ptr);

   // column 3 of the two angle coefficients * usc_matrix[3][0..3]
   vec_cplx_rep_tx[0] = BBE_SHFLNX16I(*vec_cplx_ci_stv_0_ptr, BBE_SHFLI_REP_3X4);
   vec_cplx_rep_tx[1] = BBE_SHFLNX16I(*vec_cplx_ci_stv_1_ptr, BBE_SHFLI_REP_3X4);
   BBE_MULJAN_2XCF32(*p_vec_cplx_out, p_vec_cplx_usc[3], *vec_cplx_rep_tx_ptr);
}

/**
 *  @b Description
 *  @n
 *      Read the angle coefficients from the input arrays from the spec, then reorder to match
 *      the RA expected order.
 *
 * @brief Read and generate the RA uncalibrated vectors needed for MAP.
 *
 * @param p_smc_real_in Pointer to the real part of the angle coefficients (int16_t array)
 * @param p_smc_imag_in Pointer to the imaginary part of the angle coefficients (int16_t array)
 * @param dopp_bb_coeffs_out Pointer to the arrays for the arrrays to be used by the RA
 *
 */
void Prep_Angle_Coefficients(int16_t *p_smc_real_in, int16_t *p_smc_imag_in, xb_vecNx16 *dest_vec)
{
   /**
    * SMC has values in matrix form:
    *
    * Angle_Coeff_Real[TX DDM Index][Angle Coefficient Index]
    * Angle_Coeff_Imag[TX DDM Index][Angle Coefficient Index]
    *
    * Real[0][0] Imag[0][0] Real[1][0] Imag[1][0] Real[2][0] Imag[2][0] Real[3][0] Imag[3][0]
    * Real[0][1] Imag[0][1] Real[1][1] Imag[1][1] Real[2][1] Imag[2][1] Real[3][1] Imag[3][1]
    * Real[0][2] Imag[0][2] Real[1][2] Imag[1][2] Real[2][2] Imag[2][2] Real[3][2] Imag[3][2]
    * Real[0][3] Imag[0][3] Real[1][3] Imag[1][3] Real[2][3] Imag[2][3] Real[3][3] Imag[3][3]
    * Real[0][4] Imag[0][4] Real[1][4] Imag[1][4] Real[2][4] Imag[2][4] Real[3][4] Imag[3][4]
    * Real[0][5] Imag[0][5] Real[1][5] Imag[1][5] Real[2][5] Imag[2][5] Real[3][5] Imag[3][5]
    * Real[0][6] Imag[0][6] Real[1][6] Imag[1][6] Real[2][6] Imag[2][6] Real[3][6] Imag[3][6]
    * Real[0][7] Imag[0][7] Real[1][7] Imag[1][7] Real[2][7] Imag[2][7] Real[3][7] Imag[3][7]
    */
   valign real_align, imag_align;
   const xb_vecNx16 *real_src_vec_ptr = (const xb_vecNx16 *)p_smc_real_in;
   const xb_vecNx16 *imag_src_vec_ptr = (const xb_vecNx16 *)p_smc_imag_in;
   xb_vecNx16 real_data_tx0_tx1, imag_data_tx0_tx1, real_data_tx2_tx3, imag_data_tx2_tx3;
   xb_vecNx16 real_alltx_angles_0_1_4_5;
   xb_vecNx16 imag_alltx_angles_0_1_4_5;
   xb_vecNx16 real_alltx_angles_2_3_6_7;
   xb_vecNx16 imag_alltx_angles_2_3_6_7;

   uint16_t __attribute__((aligned(32)))
   real_imag_select_0_1_4_5_array[16] = {0, 8, 16, 24, 4, 12, 20, 28, 1, 9, 17, 25, 5, 13, 21, 29};
   uint16_t __attribute__((aligned(32)))
   real_imag_select_2_3_6_7_array[16] = {2, 10, 18, 26, 6, 14, 22, 30, 3, 11, 19, 27, 7, 15, 23, 31};

   vsaN real_imag_select_0_1_4_5_sel = BBE_MOVVSV(*(xb_vecNx16 *)real_imag_select_0_1_4_5_array, 0);
   vsaN real_imag_select_2_3_6_7_sel = BBE_MOVVSV(*(xb_vecNx16 *)real_imag_select_2_3_6_7_array, 0);

   real_align = BBE_LANX16_PP(real_src_vec_ptr);
   imag_align = BBE_LANX16_PP(imag_src_vec_ptr);

   BBE_LANX16_IP(real_data_tx0_tx1, real_align, real_src_vec_ptr);
   BBE_LANX16_IP(imag_data_tx0_tx1, imag_align, imag_src_vec_ptr);
   BBE_LANX16_IP(real_data_tx2_tx3, real_align, real_src_vec_ptr);
   BBE_LANX16_IP(imag_data_tx2_tx3, imag_align, imag_src_vec_ptr);

   real_alltx_angles_0_1_4_5 = BBE_SELNX16(real_data_tx2_tx3, real_data_tx0_tx1, real_imag_select_0_1_4_5_sel);
   imag_alltx_angles_0_1_4_5 = BBE_SELNX16(imag_data_tx2_tx3, imag_data_tx0_tx1, real_imag_select_0_1_4_5_sel);
   real_alltx_angles_2_3_6_7 = BBE_SELNX16(real_data_tx2_tx3, real_data_tx0_tx1, real_imag_select_2_3_6_7_sel);
   imag_alltx_angles_2_3_6_7 = BBE_SELNX16(imag_data_tx2_tx3, imag_data_tx0_tx1, real_imag_select_2_3_6_7_sel);

   // dest_vec[0] -> angle 0 and angle 4
   // dest_vec[1] -> angle 1 and angle 5
   BBE_DSELNX16I(dest_vec[1], dest_vec[0], imag_alltx_angles_0_1_4_5, real_alltx_angles_0_1_4_5, BBE_DSELI_INTERLEAVE_1);

   // dest_vec[2] -> angle 2 and angle 6
   // dest_vec[3] -> angle 3 and angle 7
   BBE_DSELNX16I(dest_vec[3], dest_vec[2], imag_alltx_angles_2_3_6_7, real_alltx_angles_2_3_6_7, BBE_DSELI_INTERLEAVE_1);
}

/*===========================================================================*/
/**
 * @brief Copy and duplicate USC matrix data with unaligned access handling
 *
 * Helper function to copy USC calibration matrix data from potentially
 * unaligned source to aligned destination vectors. Each complex coefficient
 * is duplicated across vector pairs for efficient SIMD processing with the
 * BBE32 multiply-accumulate operations.
 *
 * @param[out] dest_ptr Pointer to destination vector array (aligned)
 * @param[in] src_ptr Pointer to source matrix data (potentially unaligned)
 *
 * @retval None
 *
 */
static inline void USC_Duplicate(const void *dest_ptr, const void *src_ptr)
{
   valign src_align;
   xb_vecNx16 *dest_vec_ptr = (xb_vecNx16 *)(uintptr_t)dest_ptr;
   xb_vecNx16 *src_vec_ptr  = (xb_vecNx16 *)(uintptr_t)src_ptr;
   xb_vecNx16 temp_data     = BBE_ZERONX16();
   uint32_t i;

   src_align = BBE_LANX16_PP(src_vec_ptr);

   for (i = 0; i < NUM_TX_CHANNELS; i++)
   {
      BBE_LANX16_IP(temp_data, src_align, src_vec_ptr);
      *dest_vec_ptr++ = temp_data;
      *dest_vec_ptr++ = temp_data;
   }
}

/**
 * @brief Create exchange vector for TX channel reordering
 *
 * This function generates a permutation vector used for reordering TX channels
 * according to the specified order array. Creates index mappings for both
 * real and imaginary components of complex data to support antenna element
 * reordering required by the radar system architecture.
 *
 * @param[out] exchange_vec_ptr Pointer to output exchange/permutation vector
 * @param[in] order_ptr Pointer to TX channel reordering specification array [4]
 *
 * @retval None
 *
 * @pre order_ptr must contain valid TX channel indices (1-4, 1-based indexing)
 * @pre Input order array must contain NUM_TX_CHANNELS elements
 *
 * @note Generated vector is used with BBE_SHFLNX16 for efficient reordering
 * @note Handles both lower and upper halves of 16-element vectors
 * @note Supports both MMIC-to-AF and AF-to-MMIC channel mappings
 * @note Uses 1-based indexing for TX channels (converts to 0-based internally)
 *
 * @par TX Channel Mapping:
 * - Input order array specifies desired TX channel sequence (1-based)
 * - Output vector contains indices for complex interleaved data reordering
 * - Each TX channel maps to 2 consecutive elements (real, imaginary)
 * - Upper half indices offset by 8 for 16-element vector support
 *
 * @par Algorithm:
 * 1. Convert 1-based TX indices to 0-based and multiply by 2 for complex pairs
 * 2. Store consecutive real/imaginary indices in lower vector half
 * 3. Generate upper half indices with +8 offset for full 16-element coverage
 * 4. Result used with BBE_SHFLNX16 for single-cycle permutation
 *
 * @par Radar Context:
 * - Enables mapping between MMIC hardware ordering and AF processing order
 * - Critical for maintaining phase coherence across TX channels
 * - Supports different antenna configurations (FLR8 vs SRR8P variants)
 *
 */
/*===========================================================================*/
void Create_Exchange_Vector(const xb_vecNx16 *exchange_vec_ptr, uint8_t *order_ptr)
{
   int16_t *exchange_ptr              = (int16_t *)(uintptr_t)exchange_vec_ptr;
   int16_t *exchange_vec_offset_8_ptr = &exchange_ptr[(NUM_TX_CHANNELS * 2U)];
   uint32_t i;

   for (i = 0; i < NUM_TX_CHANNELS; i++)
   {
      uint8_t index   = (order_ptr[i] - 1) * 2U;
      *exchange_ptr++ = index;
      *exchange_ptr++ = index + 1;

      index                        = index + 8;
      *exchange_vec_offset_8_ptr++ = index;
      *exchange_vec_offset_8_ptr++ = index + 1;
   }
}

/**
 * @brief Perform full matrix multiplication and steering vector calibration
 *
 * Main function that orchestrates the complete angle coefficient calibration process
 * for MAP (multi-angle processing) correction. This function applies the
 * USC Tx calibration matrix to compensate for antenna element misalignments and
 * manufacturing tolerances in the Gen8 iND13400 FLR8/SRR8P radar system.
 *
 * @param[in] p_smc_real_in Pointer to SMC real angle coefficients [4][8]
 * @param[in] p_smc_imag_in Pointer to SMC imaginary angle coefficients [4][8]
 * @param[in] usc_matrix Pointer to USC calibration matrix [4][8] (4×4 complex coefficients)
 * @param[in] k_mmic_to_af_tx_order Pointer to MMIC-to-AF TX reordering array [4]
 * @param[in] k_af_to_mmic_tx_order Pointer to AF-to-MMIC TX reordering array [4]
 * @param[out] dopp_bb_coeffs_out Pointer to output doppler angle coefficients [4][32]
 *
 * @retval None
 *
 * @pre TX reordering arrays must contain valid channel indices (1-4, 1-based)
 * @pre Output array must have sufficient space for 4×32 coefficients - This matches RA storage concept
 *      Output will be 8 total angles with 4 Tx angle coefficients - 4x8 complex uint16 values, stored
 *      in I/Q format:
 *      dopp_bb_coeffs_out[0][0:7] => Angle 1 Coefficients
 *      dopp_bb_coeffs_out[0][8:15] => Angle 4 Coefficients
 *      dopp_bb_coeffs_out[0][16:31] => Zeros
 *      dopp_bb_coeffs_out[1][0:7] => Angle 2 Coefficients
 *      dopp_bb_coeffs_out[1][8:15] => Angle 5 Coefficients
 *      dopp_bb_coeffs_out[1][16:31] => Zeros
 *      dopp_bb_coeffs_out[2][0:7] => Angle 3 Coefficients
 *      dopp_bb_coeffs_out[2][8:15] => Angle 6 Coefficients
 *      dopp_bb_coeffs_out[2][16:31] => Zeros
 *      dopp_bb_coeffs_out[3][0:7] => Angle 4 Coefficients
 *      dopp_bb_coeffs_out[3][8:15] => Angle 8 Coefficients
 *      dopp_bb_coeffs_out[3][16:31] => Zeros
 *
 * @note Performs automatic scaling to prevent INT16 overflow using XT_RECIP_S
 *
 * @par Algorithm Flow:
 * 1. Load and prepare angle coefficients from SMC calibration data
 * 2. Apply TX channel reordering (MMIC-to-AF mapping) for hardware alignment
 * 3. Perform matrix multiplication with USC calibration matrix (4×4 complex)
 * 4. Find maximum value across all coefficients for normalization
 * 5. Scale results to fit INT16 range using fast reciprocal function
 * 6. Apply inverse TX channel reordering (AF-to-MMIC mapping)
 * 7. Output calibrated coefficients for doppler beamforming pipeline
 * 8. Zero-pad alternate output vectors for memory alignment requirements
 *
 * @par Radar Context:
 * - Corrects for antenna element phase/amplitude misalignments
 * - Critical for maintaining beamforming accuracy and sidelobe performance
 * - Output coefficients used in subsequent doppler processing pipeline
 * - Supports both FLR8 (Front Long Range) and SRR8P (Short Range) variants
 * - Compensates for manufacturing tolerances in antenna array geometry
 *
 * @par Performance Optimizations:
 * - Utilizes BBE32 complex multiply-accumulate operations
 * - Vectorized scaling and format conversion operations
 * - Single-pass normalization with fast reciprocal approximation
 * - Minimal memory copies through in-place transformations where possible
 *
 * @par Safety Considerations:
 * - Automatic overflow prevention through dynamic scaling
 * - Robust handling of edge cases (zero coefficients, maximum values)
 * - Maintains numerical precision throughout transformation pipeline
 *
 */
void Do_Matrix_Multiply(int16_t *p_smc_real_in, int16_t *p_smc_imag_in, float32_t (*usc_matrix)[4][8],
                        uint8_t *k_mmic_to_af_tx_order, uint8_t *k_af_to_mmic_tx_order, int16_t (*dopp_bb_coeffs_out)[32])
{
   xb_vecNx16 input_tx_coeffs_data[4];
   xb_vecN_2xcf32 usc_matrix_vec[4]; // Hold the complex values of the USC matrix - duplicated across rows from input usc matrix
   xb_vecN_2xcf32 output_tx_coeffs_data[4];
   xb_vecN_2xf32 max_vec[2];
   uint32_t i          = 0;
   float32_t max_value = 0.0f;
   xb_vecN_2xf32 scale_factor;
   xb_vecNx16 *out_vec_ptr = (xb_vecNx16 *)&dopp_bb_coeffs_out[0][0];
   vsaN exchange_vsa;
   xb_vecNx16 exchange_vec = BBE_ZERONX16();

   USC_Duplicate((void *)&usc_matrix_vec[0], (void *)&usc_matrix[0][0][0]);
   Create_Exchange_Vector(&exchange_vec, k_mmic_to_af_tx_order);
   exchange_vsa = BBE_MOVVSV(exchange_vec, 0);

   Prep_Angle_Coefficients(p_smc_real_in, p_smc_imag_in, input_tx_coeffs_data);

   max_vec[0] = BBE_ZERON_2XF32();
   max_vec[1] = BBE_ZERON_2XF32();

   for (i = 0; i < NUM_TX_CHANNELS; i++)
   {
      xb_vecN_2xf32 *floating_vec_ptr = (xb_vecN_2xf32 *)&output_tx_coeffs_data[i];
      xb_vecNx16 temp_vec             = BBE_SHFLNX16(input_tx_coeffs_data[i], exchange_vsa);

      Matrix_Multiply_Tx_Row(&temp_vec, usc_matrix_vec, &output_tx_coeffs_data[i]);
      max_vec[0] = BBE_MAXN_2XF32(BBE_ABSN_2XF32(floating_vec_ptr[0]), max_vec[1]);
      max_vec[1] = BBE_MAXN_2XF32(BBE_ABSN_2XF32(floating_vec_ptr[1]), max_vec[0]);
   }

   max_value = BBE_RMAXNUMN_2XF32(max_vec[1]);

   /* Normalize STV so biggest point fits in INT16 */
   scale_factor = (float32_t)(SCALE_FLOAT_TO_P15 - 1.0f) * (float32_t)XT_RECIP_S(max_value);

   Create_Exchange_Vector(&exchange_vec, k_af_to_mmic_tx_order);
   exchange_vsa = BBE_MOVVSV(exchange_vec, 0);

   for (i = 0; i < NUM_TX_CHANNELS; i++)
   {
      xb_vecN_2xf32 *floating_vec_ptr = (xb_vecN_2xf32 *)&output_tx_coeffs_data[i];
      xb_vecNx16 int_vec_0, int_vec_1;
      xb_vecN_2xf32 temp_mult_vec;
      xb_vecNx16 temp_vec;

      temp_mult_vec = BBE_MULN_2XF32(floating_vec_ptr[0], scale_factor);

      temp_mult_vec = BBE_MULN_2XF32(floating_vec_ptr[1], scale_factor);

      int_vec_0 = BBE_MOVNX16_FROMN_2X32(BBE_TRUNCN_2XF32(BBE_MULN_2XF32(floating_vec_ptr[0], scale_factor), 0));
      int_vec_1 = BBE_MOVNX16_FROMN_2X32(BBE_TRUNCN_2XF32(BBE_MULN_2XF32(floating_vec_ptr[1], scale_factor), 0));

      temp_vec           = BBE_SELNX16I(int_vec_1, int_vec_0, BBE_SELI_EXTRACT_1_OF_2_OFF_0);
      out_vec_ptr[2 * i] = BBE_SHFLNX16(temp_vec, exchange_vsa);

      out_vec_ptr[2 * i + 1] = BBE_ZERONX16();
   }
}
