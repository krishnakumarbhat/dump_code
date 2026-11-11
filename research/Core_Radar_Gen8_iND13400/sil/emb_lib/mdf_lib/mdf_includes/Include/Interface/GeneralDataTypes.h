/*-----------------------------------------------------------------------------
Module: MDF4Lib
Interfaces: all
-------------------------------------------------------------------------------
MDF4Lib public unmanaged C++ interface: general data types
-------------------------------------------------------------------------------
Copyright (c) Vector Informatik GmbH. All rights reserved.
-----------------------------------------------------------------------------*/
#pragma once

//! \file
//! \brief General data types for MDF4Lib

#ifndef MDFLIBCALL
   #define MDFLIBCALL //__cdecl
#endif

#ifdef __WIN32
   #include <BaseTsd.h>
   #include <tchar.h>
#else
   #include <cstdint>
   #ifndef TCHAR
      #define TCHAR char
   #endif
   #ifndef _T
      #define _T(x) x
   #endif
   #include "Backward.h"
#endif

#if !defined(CINTERFACE) && !defined(_OBJBASE_H_)
   #define interface struct
   #define CINTERFACE
#endif

#ifndef REAL_DEFINED
typedef double REAL;
   #define REAL_DEFINED
#endif

#ifndef BYTE_DEFINED
typedef unsigned char BYTE;
   #define BYTE_DEFINED
#endif

// #ifndef _BASETSD_H_
//

// #ifndef UINT8_DEFINED
// typedef unsigned char UINT8;
// #define UINT8_DEFINED
// #endif
//
// #ifndef UINT16_DEFINED
// typedef unsigned short UINT16;
// #define UINT16_DEFINED
// #endif
//
// #ifndef UINT32_DEFINED
// typedef unsigned long UINT32;
// #define UINT32_DEFINED
// #endif
//
// #ifndef UINT64_DEFINED
// typedef unsigned __int64 UINT64;
// #define UINT64_DEFINED
// #endif
//
// #ifndef INT8_DEFINED
// typedef signed char INT8;
// #define INT8_DEFINED
// #endif
//
// #ifndef INT16_DEFINED
// typedef signed short INT16;
// #define INT16_DEFINED
// #endif
//
// #ifndef INT32_DEFINED
// typedef signed long INT32;
// #define INT32_DEFINED
// #endif
//
// #ifndef INT64_DEFINED
// typedef signed __int64 INT64;
// #define INT64_DEFINED
// #endif
//
// #endif // #ifndef _BASETSD_H_

#include "LPCTSTR.h"
