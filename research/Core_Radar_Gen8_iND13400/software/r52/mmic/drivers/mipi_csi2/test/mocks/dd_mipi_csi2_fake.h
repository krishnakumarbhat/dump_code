#ifndef MIPI_CSI2_FAKE_H_
#define MIPI_CSI2_FAKE_H_

#include "fff.h"
extern "C"
{
//#include "mmic_interface.h" /* gave error on CSI build*/
#include "dd_mipi.h"
   DECLARE_FAKE_VOID_FUNC(ensureInterruptsNotMasked);
   DECLARE_FAKE_VALUE_FUNC(bool, MIPI_Init, const volatile MIPI_Config_T *);
   DECLARE_FAKE_VALUE_FUNC(bool, MIPI_Enable);
   DECLARE_FAKE_VALUE_FUNC(bool, MIPI_Disable);
}

#endif /* MIPI_CSI2_FAKE_H_ */
