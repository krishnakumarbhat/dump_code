#ifndef PLP_IFACE_H
#define PLP_IFACE_H

#include "plp_driver.h"
//#include "someip_plp_driver.h"

void PLP_OpenVigemFile(void);
void PLP_ProcessOutput(Can_FD_ID_Struct_T *can_fd_data);

// void PLP_OpenVigemEthFile(void);
// void PLP_ProcessSOMEIPOutput(SOMEIP_ID_Struct_T *someip_data);

#endif // PLP_IFACE_H
