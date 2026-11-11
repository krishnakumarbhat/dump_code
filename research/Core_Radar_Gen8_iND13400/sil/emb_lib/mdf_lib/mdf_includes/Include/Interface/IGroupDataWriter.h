/*-----------------------------------------------------------------------------
Module: MDF4Lib
Interfaces: IGroupDataWriter
-------------------------------------------------------------------------------
MDF4Lib public unmanaged C++ interface
See API documentation for details
-------------------------------------------------------------------------------
Copyright (c) Vector Informatik GmbH. All rights reserved.
-----------------------------------------------------------------------------*/
#pragma once

#include "MDF4LibDataTypes.h"

///////////////////////////////////////////////////
//! \file
//! \brief Definition of IGroupDataWriter

///////////////////////////////////////////////////
//! \brief Object for writing signal data for multiple channel groups belonging to the same logical group (see also IDataWriter)
//!
//! A group data writer can be created for a logical group formed around a master channel group (by
//! IChannelGroup::CreateGroupDataWriter). There can be only one data writer (IDataWriter/IGroupDataWriter) object at one time. It
//! must be released before opening a data writer for another group. <br><br> The group data writer allows writing to multiple
//! channel groups of a logical group at the same time helping to insure the same record count across all channel groups. <br><br>
//! Using the Write/SetTime methods, the signal value(s) for a specific channel can be written to the record for the respective
//! channel group.
interface IGroupDataWriter
{
 public:
   ///////////////////////////////////////////////////
   //! Get a new reference to this object
   //!
   //! \return interface pointer for this object
   //! <br><br>Please remember to call Release() for the returned object or use a smart pointer (see \ref ref_counting).
   virtual IGroupDataWriter *MDFLIBCALL GetSelf() = 0;

   ///////////////////////////////////////////////////
   //! Release reference to this object
   //!
   //! See also description for \ref ref_counting.
   //! \return = 0 if this was the last reference<br>
   //! > 0 if the object still is referenced by some other object<br>
   //! < 0 on error
   virtual INT32 MDFLIBCALL Release() = 0;

   ///////////////////////////////////////////////////
   //! Adds a channel group to the IGroupDataWriter
   //!
   //! Adds a channel group to the internal array of channel groups.
   //! \note Only channel groups of the same logical group can be added to the same IGroupDataWriter.
   //! \note It is not allowed to add a channel group from a different file, nor to add it a second time.
   //! \note Adding a new channel group after writing has started is not allowed (return value will be
   //! ::eGroupSampleCountDoesNotMatch). \param[in]  pChannelGroup channel group to be added. Note that the channel group will not
   //! be released before IGroupDataWriter::Release(). \param[out] pErrorCode if not NULL the error code of the operation will be
   //! returned \return zero-based index of added channel group, or -1 on error
   virtual INT32 MDFLIBCALL AddChannelGroup(IChannelGroup *pChannelGroup, ErrorCode *pErrorCode = NULL) = 0;

   ///////////////////////////////////////////////////
   //! Get number of channel groups added successfully to the IGroupDataWriter
   //! \see AddChannelGroup, GetChannelGroup
   //! \param[out] pErrorCode if not NULL the error code of the operation will be returned
   //! \return number of channel groups (0 on error)
   virtual UINT64 MDFLIBCALL GetChannelGroupCount(ErrorCode *pErrorCode = NULL) = 0;

   ///////////////////////////////////////////////////
   //! Get channel group for given index
   //! \see AddChannelGroup, GetChannelGroupCount
   //! \param[in]  index zero-based index of channel group in IGroupDataWriter
   //! \param[out] pErrorCode if not NULL the error code of the operation will be returned
   //! \return pointer to IChannelGroup object, NULL on error
   //! <br><br>Please remember to call Release for the returned object or use a smart pointer (see \ref ref_counting).
   virtual IChannelGroup *MDFLIBCALL GetChannelGroup(UINT64 index, ErrorCode *pErrorCode = NULL) = 0;

   ///////////////////////////////////////////////////
   //! Attach this object to the current thread
   //!
   //! This method can be used in case IFile was opened with allowMultiThreading = true
   //! <br>to improve performance when using the IGroupDataWriter object in current thread only.
   //! <br>After calling the method, the object cannot be used in any other thread any longer
   //! <br>(except when calling AttachToCurrentThread again within the new thread!).
   //! \see IFileManager::CreateFile or IFileManager::OpenFile
   //! \return error code of the operation
   virtual ErrorCode MDFLIBCALL AttachToCurrentThread() = 0;

   ///////////////////////////////////////////////////
   //! Get the number of records already written
   //! \param[out] pErrorCode if not NULL the error code of the operation will be returned
   //! \return the number of records, on error 0 will be returned (check pErrorCode)
   virtual UINT64 MDFLIBCALL GetRecordCount(ErrorCode *pErrorCode = NULL) = 0;

   ///////////////////////////////////////////////////
   //! Get the current write mode
   //! \see SetWriteMode
   //! \return current read mode, see ::DataWriteModeEnum
   virtual DataWriteMode MDFLIBCALL GetWriteMode() = 0;

   ///////////////////////////////////////////////////
   //! Set the current write mode to use
   //! \note the write mode influences all Write methods
   //! \param[in]  mode write mode to set, see ::DataWriteModeEnum
   //! \return error code of the operation
   virtual ErrorCode MDFLIBCALL SetWriteMode(DataWriteMode mode) = 0;

   ///////////////////////////////////////////////////
   //! Flush the current record for each channel group to file
   //!
   //! \note the method also prepares the new record, i.e. record filled with zeros and all invalidation bits are set.
   //! \note when the IGroupDataWriter is created with ::eGroupDataWriterRetainRecordAfterFlush, the last signal values are kept
   //! and only the invalidation bits are set.
   //!
   //! Depending on the configured FlushCheckMode (see SetFlushCheckMode), the method may detect that not all channel values were
   //! set and return ::eFlushNotAllValuesWritten, but the record will be written nevertheless! Depending on the configured
   //! TimeCheckMode (see SetTimeCheckMode), the method may detect reverse time stamps and return ::eReverseTimeStamp, but the
   //! record will be written nevertheless! \return error code of the operation
   virtual ErrorCode MDFLIBCALL FlushRecord() = 0;

   ///////////////////////////////////////////////////
   //! Set time stamp in nanoseconds in current record
   //! \note the time stamp should be larger than time stamp of previous record!
   //! Depending on the configured TimeCheckMode (see SetTimeCheckMode), the method may detect reverse time stamps and return
   //! ::eReverseTimeStamp, but the time stamp will be set nevertheless! Not possible in case a virtual time channel is used.
   //! \param[in] timeStampNs time stamp in nanoseconds
   //! \return error code of the operation
   virtual ErrorCode MDFLIBCALL SetTimeNs(INT64 timeStampNs) = 0;

   ///////////////////////////////////////////////////
   //! Set time stamp in seconds in current record
   //! \note the time stamp should be larger than time stamp of previous record!
   //! Depending on the configured TimeCheckMode (see SetTimeCheckMode), the method may detect reverse time stamps and return
   //! ::eReverseTimeStamp, but the time stamp will be set nevertheless! Not possible in case a virtual time channel is used.
   //! \param[in] timeStampSec time stamp in seconds
   //! \return error code of the operation
   virtual ErrorCode MDFLIBCALL SetTimeSec(REAL timeStampSec) = 0;

   ///////////////////////////////////////////////////
   //! Write the raw value (given as double value) for the given channel
   //! \param[in]  pChannel channel to use for this operation
   //! \param[in]  value value to write
   //! \param[in]  isValid in case MDF4 invalidation bit is used for this channel,
   //!             the invalidation bit will be set for isValid = false, or reset if isValid = true (default).
   //! \return error code of the operation
   virtual ErrorCode MDFLIBCALL WriteRawValue(IChannel *pChannel, REAL value, bool isValid = true) = 0;

   ///////////////////////////////////////////////////
   //! Write the raw value (given as Integer value) for the given channel
   //!
   //! \param[in]  pChannel channel to use for this operation
   //! \param[in]  value value to write
   //! \param[in]  isValid in case MDF4 invalidation bit is used for this channel,
   //!             the invalidation bit will be set for isValid = false, or reset if isValid = true (default).
   //! \return error code of the operation
   virtual ErrorCode MDFLIBCALL WriteRawValue(IChannel *pChannel, INT64 value, bool isValid = true) = 0;

   ///////////////////////////////////////////////////
   //! Write the raw value (given as BYTE array) for the given channel
   //!
   //! \note for numeric values, the value bytes will be written!
   //! \param[in]  pChannel channel to use for this operation
   //! \param[in]  pByteArray buffer for the Byte array to write (must not be NULL)
   //! \param[in]  arraySize size of the input buffer in Bytes (can be 0 in order to set the data size for MDF4 MSLD/VLSD
   //! channels!) \param[in]  isValid in case MDF4 invalidation bit is used for this channel,
   //!             the invalidation bit will be set for isValid = false, or reset if isValid = true (default).
   //! \return error code of the operation
   virtual ErrorCode MDFLIBCALL WriteRawValue(IChannel *pChannel, BYTE *pByteArray, UINT32 arraySize, bool isValid = true) = 0;

   ///////////////////////////////////////////////////
   //! Write the raw value (given as string) for the given channel
   //!
   //! \note
   //! <ul>
   //!   <li>Only possible for string data types.
   //!   <li>The written string will be transformed from the Unicode or MBCS input string, depending on the library.
   //!   <li>The written string always will be zero terminated. In case it is too long, it will be truncated.
   //! </ul>
   //! \param[in]  pChannel channel to use for this operation
   //! \param[in]  value string value to write (must not be NULL)
   //! \param[in]  isValid in case MDF4 invalidation bit is used for this channel,
   //!             the invalidation bit will be set for isValid = false, or reset if isValid = true (default).
   //! \return error code of the operation
   virtual ErrorCode MDFLIBCALL WriteRawValue(IChannel *pChannel, LPCTSTR value, bool isValid = true) = 0;

   ///////////////////////////////////////////////////
   //! Write the physical value (given as double value) for the given channel
   //! \note in case there is no conversion rule, the value will be written as raw value (1:1 conversion).
   //! If there is a conversion rule of other type than eLinear, an inverse conversion must be specified!
   //! \param[in]  pChannel channel to use for this operation
   //! \param[in]  value value to write
   //! \param[in]  isValid in case MDF4 invalidation bit is used for this channel,
   //!             the invalidation bit will be set for isValid = false, or reset if isValid = true (default).
   //! \return error code of the operation
   virtual ErrorCode MDFLIBCALL WritePhysValue(IChannel *pChannel, REAL value, bool isValid = true) = 0;

   ///////////////////////////////////////////////////
   //! Write the physical value (given as string) for the given channel
   //!
   //! \note
   //! <ul>
   //!   <li>Only possible if conversion returns a string or 1:1 conversion for string data types.
   //!   <li>The written string will be transformed from the Unicode or MBCS input string, depending on the library.
   //!   <li>The written string always will be zero terminated. In case it is too long, it will be truncated.
   //! </ul>
   //! \param[in]  pChannel channel to use for this operation
   //! \param[in]  value string value to write (must not be NULL)
   //! \param[in]  isValid in case MDF4 invalidation bit is used for this channel,
   //!             the invalidation bit will be set for isValid = false, or reset if isValid = true (default).
   //! \return error code of the operation
   virtual ErrorCode MDFLIBCALL WritePhysValue(IChannel *pChannel, LPCTSTR value, bool isValid = true) = 0;

   ///////////////////////////////////////////////////
   //! Get the currently active time check mode
   //! \see SetTimeCheckMode
   //! \note the default time check mode may be changed by configuration file
   //! \return current time check mode, see ::TimeCheckModeEnum
   virtual TimeCheckMode MDFLIBCALL GetTimeCheckMode() = 0;

   ///////////////////////////////////////////////////
   //! Change the time check mode
   //! \note the time check mode influences performance and return values of Flush/Write methods
   //! The initial time check mode can be changed via config file. By default it is ::eTimeCheckDisabled.
   //! \param mode time check mode to set, see ::TimeCheckModeEnum
   //! \return error code of the operation
   virtual ErrorCode MDFLIBCALL SetTimeCheckMode(TimeCheckMode mode) = 0;

   ///////////////////////////////////////////////////
   //! Get the currently active flush check mode
   //! \see SetFlushCheckMode
   //! \note the default flush check mode may be changed by configuration file
   //! \return current flush check mode, see ::FlushCheckModeEnum
   virtual FlushCheckMode MDFLIBCALL GetFlushCheckMode() = 0;

   ///////////////////////////////////////////////////
   //! Change the flush check mode
   //! \note the flush check mode influences performance and return values of Flush/Write methods
   //! The initial flush check mode can be changed via config file. By default it is ::eFlushCheckDisabled.
   //! \param mode flush check mode to set, see ::FlushCheckModeEnum
   //! \return error code of the operation
   virtual ErrorCode MDFLIBCALL SetFlushCheckMode(FlushCheckMode mode) = 0;

   ///////////////////////////////////////////////////
   //! Write the complex number value (given as real and imaginary part) for the given channel
   //!
   //! \note
   //! <ul>
   //!   <li>Only possible for channels with data type ::eComplexReal_LE or ::eComplexReal_BE (MDF 4.2 or later)
   //!   <li>Complex number data type channels cannot have a conversion, therefore phys and raw values are equal
   //!   <li>The real and imaginary part values are stored in the number of bytes reserved in the channel (may reduce resolution!)
   //! </ul>
   //! \param[in]  pChannel channel to use for this operation
   //! \param[in]  re real part of the complex number
   //! \param[in]  im imaginary part of the complex number
   //! \param[in]  isValid in case MDF4 invalidation bit is used for this channel,
   //!             the invalidation bit will be set for isValid = false, or reset if isValid = true (default).
   //! \return error code of the operation
   virtual ErrorCode MDFLIBCALL WriteComplexValueDouble(IChannel *pChannel, REAL re, REAL im, bool isValid = true) = 0;
};
