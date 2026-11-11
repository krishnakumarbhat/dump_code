/*===========================================================================*\
 * FILE: boot_interface.h (Mock for Unit Test)
 *===========================================================================
 * Copyright (C) 2023 Aptiv. All Rights Reserved.
 * Aptiv Confidential
 *---------------------------------------------------------------------------
 * Mock boot interface header for unit testing.
\*===========================================================================*/

#ifndef BOOT_INTERFACE_H
#define BOOT_INTERFACE_H

#include <stdint.h>

typedef struct
{
   uint32_t reset_type;
   uint32_t retain_reg_backup;
} Boot_Shared_Data_T;

extern Boot_Shared_Data_T Boot_Shared_Data;

#endif /* BOOT_INTERFACE_H */
