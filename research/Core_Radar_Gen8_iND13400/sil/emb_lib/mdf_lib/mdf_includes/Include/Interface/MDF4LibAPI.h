/*-----------------------------------------------------------------------------
Module: MDF4Lib
Interfaces:
-------------------------------------------------------------------------------
MDF4Lib public unmanaged C++ interface
-------------------------------------------------------------------------------
Copyright (c) Vector Informatik GmbH. All rights reserved.
-----------------------------------------------------------------------------*/

///////////////////////////////////////////////////
//! \file
//! \brief Main include file
//! This is the main include file for using the MDF4Lib API.

#ifndef _MDF4LIB_API_H_
#define _MDF4LIB_API_H_

// interface version
#define MDF4LIB_INTERFACE_MAJOR_VERSION_NO 1
#define MDF4LIB_INTERFACE_MINOR_VERSION_NO 9
#ifdef _WIN32
   #define MDF4LIB_INTERFACE_REVISON_NO 0
#else

   #define MDF4LIB_INTERFACE_REVISON_NO 100
#endif

// Used to avoid errors during resources compilation.
#ifndef _RESOURCE_COMPILE_
   #ifdef __WIN32
      // DLL file name
      #ifdef _UNICODE
         #ifdef _WIN64
            #define MDF4LIB_BASE_NAME "Mdf4Libu_x64"
         #else
            #define MDF4LIB_BASE_NAME "Mdf4Libu"
         #endif
      #else
         #ifdef _WIN64
            #define MDF4LIB_BASE_NAME "Mdf4Lib_x64"
         #else
            #define MDF4LIB_BASE_NAME "Mdf4Lib"
         #endif
      #endif
      #define MDF4LIB_DLL_NAME _T(MDF4LIB_BASE_NAME) _T(".dll")
   #else
      #define MDF4LIB_BASE_NAME "libmdf4"
      #define MDF4LIB_DLL_NAME  _T(MDF4LIB_BASE_NAME) _T(".so")
   #endif

   #ifndef IS_UNICODE
      #ifdef UNICODE
         #define IS_UNICODE true
      #else
         #define IS_UNICODE false
      #endif
   #endif

   #include "GeneralDataTypes.h"

namespace MDF4Lib
{
   #include "MDF4LibForwardDecl.h"
   #include "MDF4LibTypeDefs.h"
} // namespace MDF4Lib

namespace MDF4Lib
{
   #include "IFactory.h"
   #include "IFile.h"
   #include "IFileManager.h"
   #include "IFileSizeObserver.h"

   #include "IArrayInfo.h"
   #include "IChannel.h"
   #include "IChannelGroup.h"
   #include "IChannelSet.h"

   #include "IEvent.h"
   #include "IEventSet.h"

   #include "IDataPointer.h"
   #include "IDataWriter.h"
   #include "IGroupDataPointer.h"
   #include "IGroupDataWriter.h"

   #include "IAttachment.h"
   #include "ICreatorInfo.h"

   #include "IConversion.h"
   #include "ISourceInfo.h"

   #include "IFormatInfo.h"
   #include "ITimeStamp.h"

   #include "ICommentField.h"
   #include "ICommentFieldSet.h"

   #include "IComment.h"
   #include "IUnit.h"

   // other
   #include "IAssertCallback.h"
   #include "IConvertCallback.h"
   #include "ILogSink.h"
   #include "IProgressCallback.h"
   #include "IUnloadDllCallback.h"
   #include "IValidateFileCallback.h"

   #include "ExportedFunctions.h"
} // namespace MDF4Lib
#endif // _RESOURCE_COMPILE_

#endif // _MDF4LIB_API_H_
