#include "dd_mipi_csi2_fake.h"

DEFINE_FAKE_VALUE_FUNC(bool, MIPI_Init, const volatile MIPI_Config_T *);
DEFINE_FAKE_VOID_FUNC(ensureInterruptsNotMasked);
DEFINE_FAKE_VALUE_FUNC(bool, MIPI_Enable);
DEFINE_FAKE_VALUE_FUNC(bool, MIPI_Disable);
