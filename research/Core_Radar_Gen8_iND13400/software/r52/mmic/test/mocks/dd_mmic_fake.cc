#include "dd_mmic_fake.h"

/*Gen8 Fake Functions for MMIC_Interface Usage*/
DEFINE_FAKE_VOID_FUNC(MARS_Metadata_Read);
DEFINE_FAKE_VALUE_FUNC(MMIC_Result_T, Mars_Init);
DEFINE_FAKE_VALUE_FUNC(MMIC_Result_T, MARS_Look_Config);
DEFINE_FAKE_VALUE_FUNC(MMIC_Result_T, MARS_Reset);
DEFINE_FAKE_VALUE_FUNC(MMIC_Result_T, MARS_Look_Trigger);
DEFINE_FAKE_VALUE_FUNC(MMIC_Result_T, MARS_Look_Complete);

MMIC_Result_T RFE_Init(void)
{
   return Mars_Init();
}

MMIC_Result_T RFE_Look_Configure(void)
{
   return MARS_Look_Config();
}

MMIC_Result_T RFE_Trigger(void)
{
   return MARS_Look_Trigger();
}

MMIC_Result_T RFE_Look_Complete(void)
{
   return MARS_Look_Complete();
}
DEFINE_FAKE_VOID_FUNC(Update_Usc_Mmic_Id, uint8_t *, const uint8_t *, uint8_t);
/* Fake global variables from dd_mmic.c */
uint8_t Is_Error_Pin_Asserted = 0;

DEFINE_FAKE_VALUE_FUNC(int16_t, Compute_MMIC_On_Chip_Temperature);

// Fakes for test pattern and LUT reload APIs used in MARS_Look_Config
// DEFINE_FAKE_VALUE_FUNC(Mars_ReturnType, MARS_Start_Test_Pattern_Mode);
// DEFINE_FAKE_VALUE_FUNC(Mars_ReturnType, MARS_Stop_Test_Pattern_Mode);
// DEFINE_FAKE_VALUE_FUNC(Mars_ReturnType, MARS_Startup_Config);
