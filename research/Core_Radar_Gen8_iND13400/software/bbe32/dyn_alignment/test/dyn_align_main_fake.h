#ifndef DYN_ALIGN_MAIN_FAKE_H
#define DYN_ALIGN_MAIN_FAKE_H

#include "fff.h"
#include "ipc_data.h"

#ifdef __cplusplus
extern "C"
{
#endif

   DECLARE_FAKE_VOID_FUNC(dyn_align_wrapper, M2D_Msg_T *, D2M_Msg_T *);

#ifdef __cplusplus
}
#endif

/* Reset fake functions */

#define FFF_FAKES_DYN_LIST(FAKE) FAKE(dyn_align_wrapper)

#endif /* DYN_ALIGN_MAIN_FAKE_H */
