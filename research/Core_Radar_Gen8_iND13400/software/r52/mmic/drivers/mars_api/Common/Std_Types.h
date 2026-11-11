/*===========================================================================*/
/*
 * @file Std_Types.h
 *------------------------------------------------------------------------------
 *
 * Copyright 2023 Indie Semiconductor. All rights reserved.
 * Confidential Restricted information. Do not disclose.
 *
 *----------------------------------------------------------------------------*/

#ifndef STD_TYPES_H
#define STD_TYPES_H

/*===========================================================================*
 * Header Files
 *===========================================================================*/

#include "Platform_Types.h"

/*===========================================================================*
 * Exported Preprocessor #define Constants
 *===========================================================================*/

/*===========================================================================*
 * Exported Preprocessor #define MACROS
 *===========================================================================*/
#ifndef NULL
#define NULL 0
#endif

#ifndef NULL_PTR
#define NULL_PTR ((void *)0)
#endif

typedef uint8 Std_ReturnType;
typedef uint32 Mars_ReturnType;

#define E_OK (Std_ReturnType)0
#define E_NOT_OK (Std_ReturnType)1

#define STD_HIGH 0x01
#define STD_LOW 0x00

#define STD_ACTIVE 0x01
#define STD_IDLE 0x00

#define STD_ON 0x01
#define STD_OFF 0x00

#endif /* STD_TYPES_H*/
