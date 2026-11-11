#ifndef DYN_ALIGN_WRAPPER_FAKE_H
#define DYN_ALIGN_WRAPPER_FAKE_H

#include "fff.h"

#ifdef __cplusplus
extern "C"
{
#endif

   DECLARE_FAKE_VALUE_FUNC(float, rm_fabsf, float);

#ifdef __cplusplus
}
#endif

#define FFF_FAKE_BUFFER_FUNCTION(FAKE) FAKE(rm_fabsf)

#endif
