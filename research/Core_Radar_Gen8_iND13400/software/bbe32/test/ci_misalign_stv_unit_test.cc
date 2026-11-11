/*===========================================================================*/
/**
 * @file ci_misalign_stv_unit_test.cc
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2025 Aptiv. All rights reserved.
 * Aptiv Sensitive Business � Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * Unit test suite for the checking the ci_stv_misalignment.c file
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
 * Google Test Header Files
 *===========================================================================*/

#include <gtest/gtest.h>
#include <math.h>
#include <stdio.h>
#include <xtensa/tie/xt_bben.h>

/*===========================================================================*
 * Macros for test debugging
 *===========================================================================*/
#define ENABLE_DEBUG_PRINTS (0U)
/*===========================================================================*
 * Unit Test Header Files
 *===========================================================================*/
#include "ci_misalign_stv_ut_data.h"
extern "C"
{
#include "ci_stv_misalignment.c"
}

/*===========================================================================*
 * Test Data - Generated using write_output_test_data_file.m
 *===========================================================================*/
// clang-format off
/**
 *  Used for all tests related to the calibration matrix
 *
 * NOTE: See https://jiraprod.aptiv.com/browse/GHW-2860 for scripts used to generate data related to these unit tests.
 **/
float32_t usc_matrix[4][8] = {
   {1.000000000, 0.000000000, -0.006877326, 0.013927820, 0.006372470, -0.004817084, 0.010085607, -0.013818305, },
   {-0.017566380, -0.004892618, -0.252634645, 0.922179485, -0.002455359, 0.002177319, -0.003029179, 0.006897243, },
   {-0.000427177, 0.002959369, 0.007287367, 0.015849113, 0.940415664, 0.243422374, -0.001871684, 0.014200448, },
   {0.005389879, 0.003391095, 0.013369577, 0.020982402, 0.002278572, -0.011987800, -0.069428705, -1.004154413, },
};

/**
 *  NOTE: This data does not consider any reordering based on the k_mmic_to_af_tx_order or k_af_to_mmic_tx_order.
 *  It is in the order of the SMC real and imaginary arrays.
 **/
int16_t __attribute__((aligned(32))) input_tx_coeffs_dsp_order[4][16] = {
   { 32767,      0,  32767,      0,  32767,      0,  32767,      0, -32767,      0,  32767,      0, -32767,      0,  32767,      0, },
   {-23170,  23170,      0,  32767,  23170,  23170,  32767,      0,  23170, -23170,      0,  32767, -23170, -23170,  32767,      0, },
   {     0, -32767, -32767,      0,      0,  32767,  32767,      0,      0,  32767, -32767,      0,      0, -32767,  32767,      0, },
   { 23170,  23170,      0, -32767, -23170,  23170,  32767,      0, -23170, -23170,      0, -32767,  23170, -23170,  32767,      0, },
};
// clang-format on

/*===========================================================================*
 * Test Suite Definition
 *===========================================================================*/
class CI_Misalignment_Stv_Unit_Test_Suite : public testing::Test
{
   /**
    *  @b Description
    *  @n
    *      Method run before each individual test case.
    */
   void SetUp()
   {
   }

   /**
    * @b Description
    * @n
    *    Method run after each individual test case.
    */
   void TearDown()
   {
   }
};

/*===========================================================================*
 * Test Cases
 *===========================================================================*/

/**
 *  @b Prep_Angle_Coefficients_Test
 *  @n
 */
TEST_F(CI_Misalignment_Stv_Unit_Test_Suite, Prep_Angle_Coefficients_Test)
{
   /* Angle coefficients are in SMC as a real array and imaginary array.
      Need to reorder to match the angles for the RA.
      This test validates that the reorder operation matches to the expected
      doppler input.
   */
   int16_t real_data_local[4][8] = {{0, 1, 2, 3, 4, 5, 6, 7},
                                    {8, 9, 10, 11, 12, 13, 14, 15},
                                    {16, 17, 18, 19, 20, 21, 22, 23},
                                    {24, 25, 26, 27, 28, 29, 30, 31}};
   int16_t imag_data_local[4][8] = {{32, 33, 34, 35, 36, 37, 38, 39},
                                    {40, 41, 42, 43, 44, 45, 46, 47},
                                    {48, 49, 50, 51, 52, 53, 54, 55},
                                    {56, 57, 58, 59, 60, 61, 62, 63}};

   int16_t __attribute__((aligned(32))) transposed_data[4][16] = {0};
   int16_t exp_transposed_data_local[4][16]                    = {{0, 32, 8, 40, 16, 48, 24, 56, 4, 36, 12, 44, 20, 52, 28, 60},
                                               {1, 33, 9, 41, 17, 49, 25, 57, 5, 37, 13, 45, 21, 53, 29, 61},
                                               {2, 34, 10, 42, 18, 50, 26, 58, 6, 38, 14, 46, 22, 54, 30, 62},
                                               {3, 35, 11, 43, 19, 51, 27, 59, 7, 39, 15, 47, 23, 55, 31, 63}};

   Prep_Angle_Coefficients(&real_data_local[0][0], &imag_data_local[0][0], (xb_vecNx16 *)&transposed_data[0]);

#if ENABLE_DEBUG_PRINTS
   for (uint32_t i = 0; i < 4; i++)
   {
      printf("\nTransposed Data [%d][0]: ", i);
      for (size_t j = 0; j < 16; j++)
      {
         if (j % 8 == 0)
         {
            printf("\n");
         }

         printf(" %d", transposed_data[i][j]);
      }
   }
#endif

   for (uint32_t i = 0; i < 4; i++)
   {
      for (uint32_t j = 0; j < 16; j++)
      {
         EXPECT_EQ(transposed_data[i][j], exp_transposed_data_local[i][j]);
      }
   }
}

TEST_F(CI_Misalignment_Stv_Unit_Test_Suite, Prep_Angle_Coefficients_Test_1)
{
   /* Angle coefficients are in SMC as a real array and imaginary array.
      Need to reorder to match the angles for the RA.
      This test validates that the reorder operation matches to the expected
      doppler input.
   */
   // clang-format off
   /**
    *  The real and imaginary data here correspond to the uncalibrated data
    *  with the Tx coefficients exchanged according to k_mmic_to_af_tx_order
    *  This allows testing the intermediate steps of applying the calibration matrix
    **/
   int16_t __attribute__((aligned(32))) real_data[4][8] = {
      { 32767, -23170,      0,  23170, -32767,  23170,      0, -23170, },
      { 32767,      0, -32767,      0,  32767,      0, -32767,      0, },
      { 32767,  23170,      0, -23170, -32767, -23170,      0,  23170, },
      { 32767,  32767,  32767,  32767,  32767,  32767,  32767,  32767, },
   };
   int16_t __attribute__((aligned(32))) imag_data[4][8] = {
      {     0,  23170, -32767,  23170,      0, -23170,  32767, -23170, },
      {     0,  32767,      0, -32767,      0,  32767,      0, -32767, },
      {     0,  23170,  32767,  23170,      0, -23170, -32767, -23170, },
      {     0,      0,      0,      0,      0,      0,      0,      0, },
   };
   // clang-format on
   int16_t __attribute__((aligned(32))) transposed_data[4][16] = {0};

   Prep_Angle_Coefficients(&real_data[0][0], &imag_data[0][0], (xb_vecNx16 *)&transposed_data[0]);

#if ENABLE_DEBUG_PRINTS
   for (uint32_t i = 0; i < 4; i++)
   {
      printf("\nTransposed Data [%d][0]: ", i);

      for (size_t j = 0; j < 16; j++)
      {
         if (j % 8 == 0)
         {
            printf("\n");
         }

         printf(" %d", transposed_data[i][j]);

         EXPECT_EQ(transposed_data[i][j], input_tx_coeffs_dsp_order[i][j]);
      }
   }
#endif

   for (uint32_t i = 0; i < 4; i++)
   {
      for (size_t j = 0; j < 16; j++)
      {
         EXPECT_EQ(transposed_data[i][j], input_tx_coeffs_dsp_order[i][j]);
      }
   }
}

/**
 *  @b Prep_Angle_Coefficients_Test
 *  @n
 */
TEST_F(CI_Misalignment_Stv_Unit_Test_Suite, Matrix_Multiply_Tx_Row_Test)
{
   // clang-format off
   int16_t __attribute__((aligned(32))) input_tx_coeffs_data[8][8] = {
      { 32767,      0,  32767,      0,  32767,      0,  32767,      0, },
      {-23170,  23170,      0,  32767,  23170,  23170,  32767,      0, },
      {     0, -32767, -32767,      0,      0,  32767,  32767,      0, },
      { 23170,  23170,      0, -32767, -23170,  23170,  32767,      0, },
      {-32767,      0,  32767,      0, -32767,      0,  32767,      0, },
      { 23170, -23170,      0,  32767, -23170, -23170,  32767,      0, },
      {     0,  32767, -32767,      0,      0, -32767,  32767,      0, },
      {-23170, -23170,      0, -32767,  23170, -23170,  32767,      0, },
   };

   float32_t __attribute__((aligned(32))) exp_transposed_data[8][8] = {
      {32354.015310352, 47.769229904, -7826.562700442, 31880.286324896, 31017.614011395, 7496.919511040, -2105.081873911, -32664.603980597, },
      {-23095.035353908, -22404.820170232, 31673.263580503, 9000.625475294, 27316.271575341, -16497.722311940, -2317.164567918, -32344.992610484, },
      {849.177370498, 33052.429728514, 8779.115319026, -29993.659321880, 8289.179032851, -31069.941814389, -1257.622771648, -32737.325042455, },
      {23585.392854639, -23693.152435652, -29417.238669737, -7644.566048794, -16109.978506764, -28162.048275866, -2215.067616032, -33841.895848289, },
      {-33151.990075041, -146.170044335, -7853.434309563, 29928.884789859, -31029.199549678, -8139.839539681, -2643.373082385, -32689.647383999, },
      {23127.622876516, 23778.247299950, 29637.008650401, 8930.594078604, -27024.259189863, 15873.023330197, -1780.772236299, -33262.748437021, },
      {655.238096260, -32509.564886093, 8653.205351021, -29065.390365131, -7978.945600475, 30141.644908884, -3093.803715477, -33520.934157129, },
      {-22911.539675178, 22764.189333923, -30140.709901126, -7536.532077359, 16116.614015378, 27215.530323464, -2786.877023174, -32162.873668387, },
   };
   // clang-format on
   float32_t __attribute__((aligned(32))) transposed_data[8][8] = {0};
   xb_vecN_2xcf32 usc_matrix_vec[4]; // Hold the complex values of the USC matrix - duplicated across rows from input usc matrix

   USC_Duplicate((void *)&usc_matrix_vec[0], (void *)&usc_matrix[0][0]);

   Matrix_Multiply_Tx_Row((xb_vecNx16 *)&input_tx_coeffs_data[0], &usc_matrix_vec[0], (xb_vecN_2xcf32 *)&transposed_data[0]);
   Matrix_Multiply_Tx_Row((xb_vecNx16 *)&input_tx_coeffs_data[2], &usc_matrix_vec[0], (xb_vecN_2xcf32 *)&transposed_data[2]);
   Matrix_Multiply_Tx_Row((xb_vecNx16 *)&input_tx_coeffs_data[4], &usc_matrix_vec[0], (xb_vecN_2xcf32 *)&transposed_data[4]);
   Matrix_Multiply_Tx_Row((xb_vecNx16 *)&input_tx_coeffs_data[6], &usc_matrix_vec[0], (xb_vecN_2xcf32 *)&transposed_data[6]);

#if ENABLE_DEBUG_PRINTS
   for (uint32_t i = 0; i < 8; i++)
   {
      uint32_t error_found = 0;
      printf("\nTransposed Data [%d][0]: ", i);

      for (size_t j = 0; j < 8; j++)
      {
         printf("%f ", transposed_data[i][j]);

         if (fabs(transposed_data[i][j] - exp_transposed_data[i][j]) > 0.01f)
         {
            error_found = 1;
         }
      }

      if (error_found)
      {
         printf("Error", i);
      }

      printf("\n");
   }
#endif

   for (uint32_t i = 0; i < 8; i++)
   {
      for (size_t j = 0; j < 8; j++)
      {
         EXPECT_NEAR(transposed_data[i][j], exp_transposed_data[i][j], 0.01f);
      }
   }
}

/**
 *  @b TC_Matrix_Multiply_Tx_Row_Test_Dsp_Order
 *  @n
 */
TEST_F(CI_Misalignment_Stv_Unit_Test_Suite, TC_Matrix_Multiply_Tx_Row_Test_Dsp_Order)
{
   // 8 angle bins and 4 complex tx coefficients
   // No reordering applied to this data
   // Just taking complex matrices: [8x4] * [4x4] -> [8x4] matrix
   // exp_transposed_data is not reordered for angle bins
   // clang-format off
   float32_t __attribute__((aligned(32))) exp_transposed_data[8][8] = {
      {32354.015310352, 47.769229904, -7826.562700442, 31880.286324896, 31017.614011395, 7496.919511040, -2105.081873911, -32664.603980597, },
      {-33151.990075041, -146.170044335, -7853.434309563, 29928.884789859, -31029.199549678, -8139.839539681, -2643.373082385, -32689.647383999, },
      {-23095.035353908, -22404.820170232, 31673.263580503, 9000.625475294, 27316.271575341, -16497.722311940, -2317.164567918, -32344.992610484, },
      {23127.622876516, 23778.247299950, 29637.008650401, 8930.594078604, -27024.259189863, 15873.023330197, -1780.772236299, -33262.748437021, },
      {849.177370498, 33052.429728514, 8779.115319026, -29993.659321880, 8289.179032851, -31069.941814389, -1257.622771648, -32737.325042455, },
      {655.238096260, -32509.564886093, 8653.205351021, -29065.390365131, -7978.945600475, 30141.644908884, -3093.803715477, -33520.934157129, },
      {23585.392854639, -23693.152435652, -29417.238669737, -7644.566048794, -16109.978506764, -28162.048275866, -2215.067616032, -33841.895848289, },
      {-22911.539675178, 22764.189333923, -30140.709901126, -7536.532077359, 16116.614015378, 27215.530323464, -2786.877023174, -32162.873668387, },
   };
   // clang-format on

   float32_t __attribute__((aligned(32))) transposed_data[8][8] = {0};
   xb_vecN_2xcf32 usc_matrix_vec[4]; // Hold the complex values of the USC matrix - duplicated across rows from input usc matrix

   USC_Duplicate((void *)&usc_matrix_vec[0], (void *)&usc_matrix[0][0]);

   Matrix_Multiply_Tx_Row((xb_vecNx16 *)&input_tx_coeffs_dsp_order[0], &usc_matrix_vec[0], (xb_vecN_2xcf32 *)&transposed_data[0]);
   Matrix_Multiply_Tx_Row((xb_vecNx16 *)&input_tx_coeffs_dsp_order[1], &usc_matrix_vec[0], (xb_vecN_2xcf32 *)&transposed_data[2]);
   Matrix_Multiply_Tx_Row((xb_vecNx16 *)&input_tx_coeffs_dsp_order[2], &usc_matrix_vec[0], (xb_vecN_2xcf32 *)&transposed_data[4]);
   Matrix_Multiply_Tx_Row((xb_vecNx16 *)&input_tx_coeffs_dsp_order[3], &usc_matrix_vec[0], (xb_vecN_2xcf32 *)&transposed_data[6]);

#if ENABLE_DEBUG_PRINTS
   for (uint32_t i = 0; i < 8; i++)
   {
      uint32_t error_found = 0;
      printf("\nTransposed Data [%d][0]: ", i);
      for (size_t j = 0; j < 8; j++)
      {
         printf("%f ", transposed_data[i][j]);

         if (fabs(transposed_data[i][j] - exp_transposed_data[i][j]) > 0.01f)
         {
            error_found = 1;
         }
      }

      if (error_found)
      {
         printf("Error", i);
      }

      printf("\n");
   }
#endif

   for (uint32_t i = 0; i < 8; i++)
   {
      for (size_t j = 0; j < 8; j++)
      {
         EXPECT_NEAR(transposed_data[i][j], exp_transposed_data[i][j], 0.01f);
      }
   }
}

/**
 *  @b TC_Create_Exchange_Vectors
 *  @n
 */
TEST_F(CI_Misalignment_Stv_Unit_Test_Suite, TC_Create_Exchange_Vectors)
{
   uint8_t k_mmic_to_af_tx_order[] = {4, 3, 2, 1};
   uint8_t k_af_to_mmic_tx_order[] = {4, 3, 2, 1};

   const uint16_t expected_vec_exchange[16]     = {6, 7, 4, 5, 2, 3, 0, 1, 14, 15, 12, 13, 10, 11, 8, 9};
   const uint16_t expected_inv_vec_exchange[16] = {6, 7, 4, 5, 2, 3, 0, 1, 14, 15, 12, 13, 10, 11, 8, 9};
   int16_t vec_exchange_vec[16]                 = {0};
   int16_t vec_inv_exchange_vec[16]             = {0};
   int16_t i;

   Create_Exchange_Vector((xb_vecNx16 *)&vec_exchange_vec, k_mmic_to_af_tx_order);
   Create_Exchange_Vector((xb_vecNx16 *)&vec_inv_exchange_vec, k_af_to_mmic_tx_order);

   for (i = 0; i < 16U; i++)
   {
      ASSERT_EQ(expected_vec_exchange[i], vec_exchange_vec[i]);
      ASSERT_EQ(expected_inv_vec_exchange[i], vec_inv_exchange_vec[i]);
   }
}

/**
 *  @b TC_Do_Matrix_Multiply
 *  @n This test verifies the update of the angle coefficients based on
 * the input SMC data, USC data (Tx calibration matrix), k_mmic_to_af_tx_order, and k_af_to_mmic_tx_order
 * The output Tx coefficients should be ordered:
 * Angle 0 coefficients | Angle 4 Coefficients | 32 0's
 * Angle 1 coefficients | Angle 5 Coefficients | 32 0's
 * Angle 2 coefficients | Angle 6 Coefficients | 32 0's
 * Angle 3 coefficients | Angle 7 Coefficients | 32 0's
 */
TEST_F(CI_Misalignment_Stv_Unit_Test_Suite, TC_Do_Matrix_Multiply)
{
   uint8_t k_mmic_to_af_tx_order[] = {4, 3, 2, 1};
   uint8_t k_af_to_mmic_tx_order[] = {4, 3, 2, 1};

   // clang-format off
   int16_t __attribute__((aligned(32))) real_data_smc[4][8] = {
      { 32767,  32767,  32767,  32767,  32767,  32767,  32767,  32767, },
      { 32767,  23170,      0, -23170, -32767, -23170,      0,  23170, },
      { 32767,      0, -32767,      0,  32767,      0, -32767,      0, },
      { 32767, -23170,      0,  23170, -32767,  23170,      0, -23170, },
   };
   int16_t __attribute__((aligned(32))) imag_data_smc[4][8] = {
      {     0,      0,      0,      0,      0,      0,      0,      0, },
      {     0,  23170,  32767,  23170,      0, -23170, -32767, -23170, },
      {     0,  32767,      0, -32767,      0,  32767,      0, -32767, },
      {     0,  23170, -32767,  23170,      0, -23170,  32767, -23170, },
   };

   int16_t __attribute__((aligned(32))) exp_output_tx_coeffs_data[4][32] = {
      { -2038, -31627,  30032,   7259,  -7578,  30868,  31326,     46,  -2559, -31651, -30044,  -7881,  -7604,  28978, -32099,   -142, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      { -2244, -31318,  26448, -15974,  30667,   8715, -22361, -21693,  -1724, -32206, -26166,  15369,  28696,   8647,  22393,  23023, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      { -1218, -31698,   8026, -30083,   8500, -29041,    822,  32003,  -2996, -32456,  -7726,  29184,   8378, -28142,    634, -31477, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      { -2145, -32767, -15598, -27267, -28483,  -7402,  22836, -22940,  -2698, -31141,  15605,  26351, -29183,  -7297, -22184,  22041, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
   };
   // clang-format on

   int16_t __attribute__((aligned(32))) output_tx_coeffs_data[4][32] = {0};

   Do_Matrix_Multiply(&real_data_smc[0][0], &imag_data_smc[0][0], &usc_matrix, k_mmic_to_af_tx_order, k_af_to_mmic_tx_order,
                      &output_tx_coeffs_data[0]);

#if ENABLE_DEBUG_PRINTS
   uint16_t max_error = 0U;
   uint16_t max_i     = 0U;
   uint16_t max_j     = 0U;

   for (uint32_t i = 0; i < 4; i++)
   {
      uint32_t error_found = 0;
      printf("\nTransposed Data [%d][0]: ", i);

      for (size_t j = 0; j < 32; j++)
      {
         printf("%d ", output_tx_coeffs_data[i][j]);

         if (output_tx_coeffs_data[i][j] != exp_output_tx_coeffs_data[i][j])
         {
            uint16_t error = abs(output_tx_coeffs_data[i][j] - exp_output_tx_coeffs_data[i][j]);
            if (error > max_error)
            {
               max_error = error;
               max_i     = i;
               max_j     = j;
            }

            if (max_error > 1)
            {
               error_found = 1;
            }
         }
      }
      printf("\nExpected Data [%d][0]   : ", i);
      for (size_t j = 0; j < 32; j++)
      {
         printf("%d ", exp_output_tx_coeffs_data[i][j]);
      }

      if (error_found)
      {
         printf("Error - max error = %d, i = %d, j = %d\n", max_error, max_i, max_j);
      }

      printf("\n");
   }
#endif
   for (uint32_t i = 0; i < 4; i++)
   {
      for (size_t j = 0; j < 32; j++)
      {
         EXPECT_NEAR(output_tx_coeffs_data[i][j], exp_output_tx_coeffs_data[i][j], 1U);
      }
   }
}
