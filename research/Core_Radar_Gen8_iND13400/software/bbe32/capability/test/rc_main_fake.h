#ifndef RC_MAIN_FAKE_H
#define RC_MAIN_FAKE_H

#include "fff.h"
#include "ipc_data.h"

#ifdef __cplusplus
extern "C"
{
#endif

   DECLARE_FAKE_VOID_FUNC(rc_wrapper, D2M_Msg_T *, M2D_Msg_T *);

#ifdef __cplusplus
}
#endif

/* Reset fake functions */

#define FFF_FAKES_RC_LIST(FAKE) FAKE(rc_wrapper)

#endif /* RC_MAIN_FAKE_H */
