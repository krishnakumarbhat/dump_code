#ifndef DD_MMIC_FAKE_H_
#define DD_MMIC_FAKE_H_

#include "fff.h"
extern "C"
{
#include "mmic_interface.h"
#include <stdint.h>
   /*Gen8 Fake Functions for MMIC_Interface Usage*/
   DECLARE_FAKE_VOID_FUNC(MARS_Metadata_Read);
   DECLARE_FAKE_VALUE_FUNC(MMIC_Result_T, Mars_Init);
   DECLARE_FAKE_VALUE_FUNC(MMIC_Result_T, MARS_Look_Config);
   DECLARE_FAKE_VALUE_FUNC(MMIC_Result_T, MARS_Reset);
   DECLARE_FAKE_VALUE_FUNC(MMIC_Result_T, MARS_Look_Trigger);
   DECLARE_FAKE_VALUE_FUNC(MMIC_Result_T, MARS_Look_Complete);

   MMIC_Result_T RFE_Init(void);
   MMIC_Result_T RFE_Look_Configure(void);
   MMIC_Result_T RFE_Trigger(void);
   MMIC_Result_T RFE_Look_Complete(void);

   /* Compatibility aliases for fake objects when API names are macro-mapped to RFE_* */
#define Mars_Init_fake          RFE_Init_fake
#define MARS_Look_Config_fake   RFE_Look_Configure_fake
#define MARS_Look_Trigger_fake  RFE_Trigger_fake
#define MARS_Look_Complete_fake RFE_Look_Complete_fake
   DECLARE_FAKE_VOID_FUNC(Update_Usc_Mmic_Id, uint8_t *, const uint8_t *, uint8_t);
   /* Fake global variables from dd_mmic.c */
   extern uint8_t Is_Error_Pin_Asserted;

   DECLARE_FAKE_VALUE_FUNC(int16_t, Compute_MMIC_On_Chip_Temperature);

   // Fakes for test pattern and LUT reload APIs used in MARS_Look_Config
   // DECLARE_FAKE_VALUE_FUNC(Mars_ReturnType, MARS_Start_Test_Pattern_Mode);
   // DECLARE_FAKE_VALUE_FUNC(Mars_ReturnType, MARS_Stop_Test_Pattern_Mode);
   // DECLARE_FAKE_VALUE_FUNC(Mars_ReturnType, MARS_Startup_Config);
}

/* Reset fake functions */
#define FFF_FAKES_MMIC_STUB_FUNCTION(FAKE)

#endif /* _DD_MMIC_FAKE_H_ */
