/*===========================================================================*\
 * FILE: reuse.h (Mock for Unit Test)
 *===========================================================================
 * Copyright (C) 2023 Aptiv. All Rights Reserved.
 * Aptiv Confidential
 *---------------------------------------------------------------------------
 * Minimal stub of reuse.h needed by dd_cmu.c during unit testing.
\*===========================================================================*/

#ifndef REUSE_H
#define REUSE_H

#include <stdint.h>

#define NUM_ELEMS(arr)  ((sizeof(arr)) / (sizeof((arr)[0])))
#define UNUSED_PARAM(x) ((void)(x))

#endif /* REUSE_H */
