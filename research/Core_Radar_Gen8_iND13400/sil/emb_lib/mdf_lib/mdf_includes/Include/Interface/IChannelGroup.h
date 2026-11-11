/*-----------------------------------------------------------------------------
Module: MDF4Lib
Interfaces: IChannelGroup
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
//! \brief Definition of IChannelGroup

///////////////////////////////////////////////////
//! \brief Description of a channel group
//!
//! The IChannelGroup object describes a channel group (CG block) and also holds some information of the data group (DG block).
//! A channel group contains a collection of channels which are stored in one record, i.e. which have equal sampling.
interface IChannelGroup
{
 public:
   ///////////////////////////////////////////////////
   //! Get a new reference to this object
   //!
   //! \return interface pointer for this object
   //! <br><br>Please remember to call Release() for the returned object or use a smart pointer (see \ref ref_counting).
   virtual IChannelGroup *MDFLIBCALL GetSelf() = 0;

   ///////////////////////////////////////////////////
   //! Release reference to this object
   //!
   //! See also description for \ref ref_counting.
   //! \return = 0 if this was the last reference<br>
   //! > 0 if the object still is referenced by some other object<br>
   //! < 0 on error
   virtual INT32 MDFLIBCALL Release() = 0;

   ///////////////////////////////////////////////////
   //! Get reference to parent file
   //! \return pointer to IFile object, NULL on error
   //! <br><br>Please remember to call Release for the returned object or use a smart pointer (see \ref ref_counting).
   virtual IFile *MDFLIBCALL GetFile() = 0;

   ///////////////////////////////////////////////////
   //! Get number of samples
   //! \return number of samples, 0 on error
   virtual UINT64 MDFLIBCALL GetSampleCount() = 0;

   ///////////////////////////////////////////////////
   //! Get number of data bytes in record
   //! \note this does not contain the bytes for the record ID nor invalidation bytes
   //! \see GetInvalByteCount
   //! \return number of data bytes, 0 on error
   virtual UINT32 MDFLIBCALL GetDataByteCount() = 0;

   ///////////////////////////////////////////////////
   //! Get number of invalidation bytes in record
   //! \note invalidation bytes are optional and are not available for MDF3
   //! \return number of invalidation bytes, 0 on error or if not available
   virtual UINT32 MDFLIBCALL GetInvalByteCount() = 0;

   ///////////////////////////////////////////////////
   //! Get comment of channel group
   //! \param[out] pErrorCode if not NULL the error code of the operation will be returned
   //! \return pointer to IComment object, NULL on error
   //! <br><br>Please remember to call Release for the returned object or use a smart pointer (see \ref ref_counting).
   virtual IComment *MDFLIBCALL GetComment(ErrorCode *pErrorCode = NULL) = 0;

   ///////////////////////////////////////////////////
   //! Get comment of parent data group
   //! \param[out] pErrorCode if not NULL the error code of the operation will be returned
   //! \return pointer to IComment object, NULL on error or for MDF3
   //! <br><br>Please remember to call Release for the returned object or use a smart pointer (see \ref ref_counting).
   virtual IComment *MDFLIBCALL GetDataGroupComment(ErrorCode *pErrorCode = NULL) = 0;

   ///////////////////////////////////////////////////
   //! Get acquisition name
   //! \param[out] pErrorCode if not NULL the error code of the operation will be returned
   //! \return pointer to string with acquisition name, NULL on error or for MDF3
   virtual LPCTSTR MDFLIBCALL GetAcquisitionName(ErrorCode *pErrorCode = NULL) = 0;

   ///////////////////////////////////////////////////
   //! Get source information of channel group
   //! \param[out] pErrorCode if not NULL the error code of the operation will be returned
   //! \return pointer to ISourceInfo object, NULL on error or for MDF3
   //! <br><br>Please remember to call Release for the returned object or use a smart pointer (see \ref ref_counting).
   virtual ISourceInfo *MDFLIBCALL GetSourceInfo(ErrorCode *pErrorCode = NULL) = 0;

   ///////////////////////////////////////////////////
   //! Get master channel of channel group for specified sync type
   //! \param[in] masterSyncType sync type of master channel (usually ::eTimeSync)
   //! \param[out] pErrorCode if not NULL the error code of the operation will be returned
   //! \return pointer to IChannel object, NULL on error or if requested master channel type is not available
   //! <br><br>Please remember to call Release for the returned object or use a smart pointer (see \ref ref_counting).
   virtual IChannel *MDFLIBCALL GetMasterChannel(SyncType masterSyncType = eTimeSync, ErrorCode *pErrorCode = NULL) = 0;

   ///////////////////////////////////////////////////
   //! Get channel set of channel group
   //! \param[in] filterFlags flags for filtering, value is a bit combination of ::ChannelFilterFlagsEnum
   //! \param[out] pErrorCode if not NULL the error code of the operation will be returned
   //! \return pointer to IChannelSet object, NULL on error
   //! <br><br>Please remember to call Release for the returned object or use a smart pointer (see \ref ref_counting).
   virtual IChannelSet *MDFLIBCALL GetChannelSet(UINT32 filterFlags = 0, ErrorCode *pErrorCode = NULL) = 0;

   ///////////////////////////////////////////////////
   //! Check if parent data group is sorted, i.e. data block cannot contain records of other channel groups
   //! \param[out] pErrorCode if not NULL the error code of the operation will be returned
   //! \return true if sorted, false otherwise or on error
   virtual bool MDFLIBCALL IsSorted(ErrorCode *pErrorCode = NULL) = 0;

   ///////////////////////////////////////////////////
   //! Create a data pointer object to navigate and read signal data
   //! \note the extended method IChannelGroup::CreateDataPointerEx allows to specify options for the created IDataPointer
   //! \param[out] pErrorCode if not NULL the error code of the operation will be returned
   //! \return pointer to IDataPointer object, NULL on error
   //! <br><br>Please remember to call Release for the returned object or use a smart pointer (see \ref ref_counting).
   virtual IDataPointer *MDFLIBCALL CreateDataPointer(ErrorCode *pErrorCode = NULL) = 0;

   ///////////////////////////////////////////////////
   //! Check if channel group contains a bus event (bus logging for MDF 4.1)
   //! \note for MDF version >= 4.1 only a flag is checked, for earlier versions this is not supported
   //! \param[out] pErrorCode if not NULL the error code of the operation will be returned
   //! \return true if the channel group contains a bus event, false otherwise or on error
   virtual bool MDFLIBCALL ContainsBusEvent(ErrorCode *pErrorCode = NULL) = 0;

   ///////////////////////////////////////////////////
   //! Get the type of bus event contained in the channel group
   //! \note for MDF version >= 4.1 only flags are checked, for earlier versions this is not supported yet.
   //! \param[out] pErrorCode if not NULL the error code of the operation will be returned
   //! \return type of the contained bus event (see ::BusEventTypeEnum), or ::eBusEventUnspec in case of an error or if not
   //! supported.
   virtual BusEventType MDFLIBCALL GetBusEventType(ErrorCode *pErrorCode = NULL) = 0;

   ///////////////////////////////////////////////////
   //! Set comment of channel group
   //! \note only available for newly created or writable file, not possible for channel groups using a remote master group
   //! (MDF 4.2 column-oriented storage) \param[in] pComment pointer to IComment object, NULL to remove reference to a comment
   //! object.
   //!            <br>Note: object must be in same file and if comment is XML for MDF4, it should match the respective XML schema
   //!            (cg_comment.XSD).
   //! \return error code for the operation
   virtual ErrorCode MDFLIBCALL SetComment(IComment *pComment) = 0;

   ///////////////////////////////////////////////////
   //! Set comment of parent data group
   //! \note only available for newly created or writable file, not available for MDF3, not possible for channel groups using a
   //! remote master group (MDF 4.2 column-oriented storage) \param[in] pComment pointer to IComment object, NULL to remove
   //! reference to a comment object.
   //!            <br>Note: object must be in same file and if comment is XML for MDF4, it should match the respective XML schema
   //!            (dg_comment.XSD).
   //! \return error code for the operation
   virtual ErrorCode MDFLIBCALL SetDataGroupComment(IComment *pComment) = 0;

   ///////////////////////////////////////////////////
   //! Set (acquisition) source information of channel group
   //! \note only available for newly created or writable file, not available for MDF3, not possible for channel groups using a
   //! remote master group (MDF 4.2 column-oriented storage) \param[in] pSourceInfo pointer to ISourceInfo object, NULL to remove
   //! reference to a source info object.
   //!            <br>Note: object must be in same file.
   //! \return error code for the operation
   virtual ErrorCode MDFLIBCALL SetSourceInfo(ISourceInfo *pSourceInfo) = 0;

   ///////////////////////////////////////////////////
   //! Create a master channel in this channel group
   //!
   //! The given channel will be appended to the channel list of this channel group.
   //! \note There can be at most one master channel (real or virtual) per sync type per channel group.
   //! Adding a second master channel with the same sync type will fail with error code ::eNoUniqueMasterChannel.
   //! For the created master channel automatically a IUnit will be added with name "s", "m" or "rad", depending on the sync type.
   //!
   //! Please pay attention that the added channel can be identified uniquely within the channel group, otherwise the method might
   //! fail with ::eNoUniqueIdentification. For MDF4 the combination of channel name (cn), source name (cs) and source path (cp)
   //! (see GetSourceInfo) must be unique.
   //!
   //! Adding a channel, the range of data Bytes and possibly invalidation Bytes (MDF4) will be extended considering the range of
   //! Bytes used by the added channel. Hence, adding a channel that exceeds the current record length of the channel group is only
   //! possible as long as the channel group has no records (GetSampleCount() must be 0) and no IDataWriter for the channel group
   //! is open. \note only available for newly created or writable file. \param[in]  name name for the master channel.
   //!             <br>If NULL, depending on the sync type automatically the name "time", "angle" or "distance" will be set.
   //! \param[in]  byteOffset byte offset of the channel value in the record data bytes.
   //! \param[in]  conversionFactor factor for a linear conversion (offset 0) of the master channel. Must be >= 0.
   //!             <br>If conversionFactor is different to 1, the method automatically creates or assigns a respective IConversion.
   //! \param[in]  bitCount number of bits used for the channel value in the record data bytes.
   //!             <br>if 0, a virtual master channel will be created.
   //! \param[in]  dataType data type of the channel, see ::ChannelDataTypeEnum. For this channel type, only numeric data types are
   //! allowed.
   //!             <br>If number of bits does not match the data type, the method will fail with error code ::eInvalidDataTypeSize.
   //! \param[in]  syncType synchronization type of the master channel, see ::SyncTypeEnum. Only values ::eTimeSync, ::eAngleSync,
   //! and ::eDistanceSync are allowed. \param[in]  pComment pointer to IComment object to set for the channel.
   //!             <br>Note: object must be in same file and if comment is XML for MDF4, it should match the respective XML schema
   //!             (cn_comment.XSD).
   //! \param[out] pErrorCode if not NULL the error code of the operation will be returned
   //! \return     on success the IChannel interface of the created master channel, otherwise NULL
   //! <br><br>Please remember to call Release for the returned object or use a smart pointer (see \ref ref_counting).
   virtual IChannel *MDFLIBCALL CreateMasterChannel(LPCTSTR name = NULL, UINT32 byteOffset = 0, REAL conversionFactor = 1.0,
                                                    UINT32 bitCount = 64, ChannelDataType dataType = eReal_LE,
                                                    SyncType syncType = eTimeSync, IComment *pComment = NULL,
                                                    ErrorCode *pErrorCode = NULL) = 0;

   ///////////////////////////////////////////////////
   //! Create a master channel in this channel group
   //!
   //! The given channel will be appended to the channel list of this channel group.
   //! \note There can be at most one master channel (real or virtual) per sync type per channel group.
   //! Adding a second master channel with the same sync type will fail with error code ::eNoUniqueMasterChannel.
   //! For the created master channel automatically a IUnit will be added with name "s", "m" or "rad", depending on the sync type.
   //!
   //! Please pay attention that the added channel can be identified uniquely within the channel group, otherwise the method might
   //! fail with ::eNoUniqueIdentification. For MDF4 the combination of channel name (cn), source name (cs) and source path (cp)
   //! (see GetSourceInfo) must be unique.
   //!
   //! Adding a channel, the range of data Bytes and possibly invalidation Bytes (MDF4) will be extended considering the range of
   //! Bytes used by the added channel. Hence, adding a channel that exceeds the current record length of the channel group is only
   //! possible as long as the channel group has no records (GetSampleCount() must be 0) and no IDataWriter for the channel group
   //! is open. \note only available for newly created or writable file. \param[in]  name name for the master channel.
   //!             <br>If NULL, depending on the sync type automatically the name "time", "angle" or "distance" will be set.
   //! \param[in]  byteOffset byte offset of the channel value in the record data bytes.
   //! \param[in]  bitCount number of bits used for the channel value in the record data bytes.
   //!             <br>if 0, a virtual master channel will be created.
   //! \param[in]  dataType data type of the channel, see ::ChannelDataTypeEnum. For this channel type, only numeric data types are
   //! allowed.
   //!             <br>If number of bits does not match the data type, the method will fail with error code ::eInvalidDataTypeSize.
   //! \param[in]  syncType synchronization type of the master channel, see ::SyncTypeEnum. Only values ::eTimeSync, ::eAngleSync,
   //! and ::eDistanceSync are allowed. \param[in]  pComment pointer to IComment object to set for the channel.
   //!             <br>Note: object must be in same file and if comment is XML for MDF4, it should match the respective XML schema
   //!             (cn_comment.XSD).
   //! \param[in]  pUnit pointer to IUnit object to set for the channel.
   //!             <br>Note: object must be in same file and if unit is XML for MDF4, it should match the respective XML schema
   //!             (cn_unit.XSD).
   //! \param[in]  pConversion pointer to IConversion object to set for the channel.
   //!             <br>Note: object must be in same file and the conversion type must match the channel data type.
   //! \param[in]  pChannelSource pointer to ISourceInfo object to set for the channel.
   //!             <br>Note: object must be in same file.
   //! \param[out] pErrorCode if not NULL the error code of the operation will be returned
   //! \return     on success the IChannel interface of the created master channel, otherwise NULL
   //! <br><br>Please remember to call Release for the returned object or use a smart pointer (see \ref ref_counting).
   virtual IChannel *MDFLIBCALL CreateMasterChannel(LPCTSTR name, UINT32 byteOffset, UINT32 bitCount, ChannelDataType dataType,
                                                    SyncType syncType = eTimeSync, IComment *pComment = NULL, IUnit *pUnit = NULL,
                                                    IConversion *pConversion = NULL, ISourceInfo *pChannelSource = NULL,
                                                    ErrorCode *pErrorCode = NULL) = 0;

   ///////////////////////////////////////////////////
   //! Create a fixed length data channel in this channel group
   //!
   //! The given channel will be appended to the channel list of this channel group.
   //!
   //! Please pay attention that the added channel can be identified uniquely within the channel group, otherwise the method might
   //! fail with ::eNoUniqueIdentification. For MDF4 the combination of channel name (cn), source name (cs) and source path (cp)
   //! (see GetSourceInfo) must be unique.
   //!
   //! Adding a channel, the range of data Bytes and possibly invalidation Bytes (MDF4) will be extended considering the range of
   //! Bytes used by the added channel. Hence, adding a channel that exceeds the current record length of the channel group is only
   //! possible as long as the channel group has no records (GetSampleCount() must be 0) and no IDataWriter for the channel group
   //! is open. \note only available for newly created or writable file. \param[in]  name name for the channel. \param[in]
   //! byteOffset byte offset of the channel value in the record data bytes. \param[in]  bitCount number of bits used for the
   //! channel value in the record data bytes.
   //!             <br>if 0 and dataType is ::eInteger_Unsigned_LE, a virtual data channel will be created (MDF 4.1)
   //! \param[in]  dataType data type of the channel, see ::ChannelDataTypeEnum.
   //!             <br>If number of bits does not match the data type, the method will fail with error code ::eInvalidDataTypeSize.
   //! \param[in]  pComment pointer to IComment object to set for the channel.
   //!             <br>Note: object must be in same file and if comment is XML for MDF4, it should match the respective XML schema
   //!             (cn_comment.XSD).
   //! \param[in]  pUnit pointer to IUnit object to set for the channel.
   //!             <br>Note: object must be in same file and if unit is XML for MDF4, it should match the respective XML schema
   //!             (cn_unit.XSD).
   //! \param[in]  pConversion pointer to IConversion object to set for the channel.
   //!             <br>Note: object must be in same file and the conversion type must match the channel data type.
   //! \param[in]  pChannelSource pointer to ISourceInfo object to set for the channel.
   //!             <br>Note: object must be in same file.
   //! \param[in]  flags bit flags to set for the channel, see ::ChannelFlagsEnum.
   //!             <br>Note: flags ::eFlagPrecisionValid, ::eFlagValueRangeValid, ::eFlagLimitRangeValid, ::eFlagLimitExtRangeValid
   //!             and ::eFlagDefaultX will be ignored (reset) use the respective Set methods instead to set the information.
   //! \param[in]  invalBitPos position of invalidation bit. Will only be considered for MDF4 and if ::eFlagInvalBitUsed flag is
   //! set in flags. \param[in]  bitOffset bit offset of the channel value in the data bytes of the parent channel. 0-7, must be 0
   //! for all data types >= eReal_LE. \param[out] pErrorCode if not NULL the error code of the operation will be returned \return
   //! on success the IChannel interface of the created master channel, otherwise NULL <br><br>Please remember to call Release for
   //! the returned object or use a smart pointer (see \ref ref_counting).
   virtual IChannel *MDFLIBCALL CreateDataChannel(LPCTSTR name, UINT32 byteOffset, UINT32 bitCount = 64,
                                                  ChannelDataType dataType = eReal_LE, IComment *pComment = NULL,
                                                  IUnit *pUnit = NULL, IConversion *pConversion = NULL,
                                                  ISourceInfo *pChannelSource = NULL, UINT32 flags = 0, UINT32 invalBitPos = 0,
                                                  UINT8 bitOffset = 0, ErrorCode *pErrorCode = NULL) = 0;

   ///////////////////////////////////////////////////
   //! Create a variable length data channel in this channel group
   //!
   //! The given channel will be appended to the channel list of this channel group.
   //!
   //! Please pay attention that the added channel can be identified uniquely within the channel group, otherwise the method might
   //! fail with ::eNoUniqueIdentification. For MDF4 the combination of channel name (cn), source name (cs) and source path (cp)
   //! (see GetSourceInfo) must be unique.
   //!
   //! Adding a channel, the range of data Bytes and possibly invalidation Bytes (MDF4) will be extended considering the range of
   //! Bytes used by the added channel (here 8 Bytes always). Hence, adding a channel that exceeds the current record length of the
   //! channel group is only possible as long as the channel group has no records (GetSampleCount() must be 0) and no IDataWriter
   //! for the channel group is open. \note only available for newly created or writable file, not available for MDF3 \param[in]
   //! name name for the channel. \param[in]  byteOffset byte offset of the channel value in the record data bytes. \param[in]
   //! vlsdDataType data type of the channel, see ::ChannelDataTypeEnum.
   //!             <br>For VLSD channels, the data type specifies the type of the VLSD values. Typically only string or complex
   //!             data types are used for VLSD channels.
   //! \param[in]  pComment pointer to IComment object to set for the channel.
   //!             <br>Note: object must be in same file and if comment is XML for MDF4, it should match the respective XML schema
   //!             (cn_comment.XSD).
   //! \param[in]  pUnit pointer to IUnit object to set for the channel.
   //!             <br>Note: object must be in same file and if unit is XML for MDF4, it should match the respective XML schema
   //!             (cn_unit.XSD).
   //! \param[in]  pConversion pointer to IConversion object to set for the channel.
   //!             <br>Note: object must be in same file and the conversion type must match the channel data type.
   //! \param[in]  pChannelSource pointer to ISourceInfo object to set for the channel.
   //!             <br>Note: object must be in same file.
   //! \param[in]  flags bit flags to set for the channel, see ::ChannelFlagsEnum.
   //!             <br>Note: flags ::eFlagPrecisionValid, ::eFlagValueRangeValid, ::eFlagLimitRangeValid, ::eFlagLimitExtRangeValid
   //!             and ::eFlagDefaultX will be ignored (reset) use the respective Set methods instead to set the information.
   //! \param[in]  invalBitPos position of invalidation bit. Will only be considered for MDF4 and if ::eFlagInvalBitUsed flag is
   //! set in flags. \param[out] pErrorCode if not NULL the error code of the operation will be returned \return     on success the
   //! IChannel interface of the created channel, otherwise NULL <br><br>Please remember to call Release for the returned object or
   //! use a smart pointer (see \ref ref_counting).
   virtual IChannel *MDFLIBCALL CreateVLSDChannel(LPCTSTR name, UINT32 byteOffset, ChannelDataType vlsdDataType = eByteArray,
                                                  IComment *pComment = NULL, IUnit *pUnit = NULL, IConversion *pConversion = NULL,
                                                  ISourceInfo *pChannelSource = NULL, UINT32 flags = 0, UINT32 invalBitPos = 0,
                                                  ErrorCode *pErrorCode = NULL) = 0;

   ///////////////////////////////////////////////////
   //! Create a maximum length data channel in this channel group
   //!
   //! The given channel will be appended to the channel list of this channel group.
   //!
   //! Please pay attention that the added channel can be identified uniquely within the channel group, otherwise the method might
   //! fail with ::eNoUniqueIdentification. For MDF4 the combination of channel name (cn), source name (cs) and source path (cp)
   //! (see GetSourceInfo) must be unique.
   //!
   //! Adding a channel, the range of data Bytes and possibly invalidation Bytes (MDF4) will be extended considering the range of
   //! Bytes used by the added channel. Hence, adding a channel that exceeds the current record length of the channel group is only
   //! possible as long as the channel group has no records (GetSampleCount() must be 0) and no IDataWriter for the channel group
   //! is open. \note only available for newly created or writable file, not available for MDF3 \param[in]  name name for the
   //! channel. \param[in]  byteOffset byte offset of the channel value in the record data bytes. \param[in]  pSizeChannel pointer
   //! to IChannel object for the size signal of the MLSD channel.
   //!             <br>Note: object must be in same file and channel group and should return as physical values only integer values
   //!             <= maxByteCount.
   //! \param[in]  maxByteCount maximum number of Bytes for MLSD channel value, i.e. number of Bytes used for the channel value in
   //! the record data bytes. \param[in]  dataType data type of the channel, see ::ChannelDataTypeEnum.
   //!             <br>Typically only string or complex data types are used for MLSD channels.
   //!             If number of bits does not match the data type, the method will fail with error code ::eInvalidDataTypeSize.
   //! \param[in]  pComment pointer to IComment object to set for the channel.
   //!             <br>Note: object must be in same file and if comment is XML for MDF4, it should match the respective XML schema
   //!             (cn_comment.XSD).
   //! \param[in]  pUnit pointer to IUnit object to set for the channel.
   //!             <br>Note: object must be in same file and if unit is XML for MDF4, it should match the respective XML schema
   //!             (cn_unit.XSD).
   //! \param[in]  pConversion pointer to IConversion object to set for the channel.
   //!             <br>Note: object must be in same file and the conversion type must match the channel data type.
   //! \param[in]  pChannelSource pointer to ISourceInfo object to set for the channel.
   //!             <br>Note: object must be in same file.
   //! \param[in]  flags bit flags to set for the channel, see ::ChannelFlagsEnum.
   //!             <br>Note: flags ::eFlagPrecisionValid, ::eFlagValueRangeValid, ::eFlagLimitRangeValid, ::eFlagLimitExtRangeValid
   //!             and ::eFlagDefaultX will be ignored (reset) use the respective Set methods instead to set the information.
   //! \param[in]  invalBitPos position of invalidation bit. Will only be considered for MDF4 and if ::eFlagInvalBitUsed flag is
   //! set in flags. \param[out] pErrorCode if not NULL the error code of the operation will be returned \return     on success the
   //! IChannel interface of the created channel, otherwise NULL <br><br>Please remember to call Release for the returned object or
   //! use a smart pointer (see \ref ref_counting).
   virtual IChannel *MDFLIBCALL CreateMLSDChannel(LPCTSTR name, UINT32 byteOffset, IChannel *pSizeChannel, UINT32 maxByteCount,
                                                  ChannelDataType dataType = eByteArray, IComment *pComment = NULL,
                                                  IUnit *pUnit = NULL, IConversion *pConversion = NULL,
                                                  ISourceInfo *pChannelSource = NULL, UINT32 flags = 0, UINT32 invalBitPos = 0,
                                                  ErrorCode *pErrorCode = NULL) = 0;

   ///////////////////////////////////////////////////
   //! Create a stream synchronization channel in this channel group
   //!
   //! The given channel will be appended to the channel list of this channel group.
   //!
   //! Please pay attention that the added channel can be identified uniquely within the channel group, otherwise the method might
   //! fail with ::eNoUniqueIdentification. For MDF4 the combination of channel name (cn), source name (cs) and source path (cp)
   //! (see GetSourceInfo) must be unique.
   //!
   //! Adding a channel, the range of data Bytes and possibly invalidation Bytes (MDF4) will be extended considering the range of
   //! Bytes used by the added channel. Hence, adding a channel that exceeds the current record length of the channel group is only
   //! possible as long as the channel group has no records (GetSampleCount() must be 0) and no IDataWriter for the channel group
   //! is open. \note only available for newly created or writable file. \param[in]  name name for the channel. \param[in]
   //! byteOffset byte offset of the channel value in the record data bytes. \param[in]  pStreamAttachment pointer to IAttachment
   //! object with stream to be synchronized (must not be NULL).
   //!             <br>Note: attachment object must be in same file and in global list of attachments.
   //! \param[in]  syncType type of synchronization with the stream in attachment, see ::SyncTypeEnum. Only values ::eTimeSync,
   //! ::eAngleSync, ::eDistanceSync, and ::eIndexSync are allowed.
   //!             <br>Note:  Physical values of this channel must return the unit of the respective synchronization domain,
   //!            i.e. seconds for syncType = ::eTimeSync, or an index value for syncType = ::eIndexSync.
   //!            These values are used for synchronization with the stream.
   //! \param[in]  bitCount number of bits used for the channel value in the record data bytes.
   //! \param[in]  dataType data type of the channel, see ::ChannelDataTypeEnum. For this channel type, only numeric data types are
   //! allowed.
   //!             <br>If number of bits does not match the data type, the method will fail with error code ::eInvalidDataTypeSize.
   //! \param[in]  pComment pointer to IComment object to set for the channel.
   //!             <br>Note: object must be in same file and if comment is XML for MDF4, it should match the respective XML schema
   //!             (cn_comment.XSD).
   //! \param[in]  pUnit pointer to IUnit object to set for the channel.
   //!             <br>Note: object must be in same file and if unit is XML for MDF4, it should match the respective XML schema
   //!             (cn_unit.XSD).
   //! \param[in]  pConversion pointer to IConversion object to set for the channel.
   //!             <br>Note: object must be in same file and the conversion type must match the channel data type.
   //! \param[in]  pChannelSource pointer to ISourceInfo object to set for the channel.
   //!             <br>Note: object must be in same file.
   //! \param[in]  flags bit flags to set for the channel, see ::ChannelFlagsEnum.
   //!             <br>Note: flags ::eFlagPrecisionValid, ::eFlagValueRangeValid, ::eFlagLimitRangeValid, ::eFlagLimitExtRangeValid
   //!             and ::eFlagDefaultX will be ignored (reset) use the respective Set methods instead to set the information.
   //! \param[in]  invalBitPos position of invalidation bit. Will only be considered for MDF4 and if ::eFlagInvalBitUsed flag is
   //! set in flags. \param[out] pErrorCode if not NULL the error code of the operation will be returned \return     on success the
   //! IChannel interface of the created master channel, otherwise NULL <br><br>Please remember to call Release for the returned
   //! object or use a smart pointer (see \ref ref_counting).
   virtual IChannel *MDFLIBCALL CreateStreamSyncChannel(LPCTSTR name, UINT32 byteOffset, IAttachment *pStreamAttachment,
                                                        SyncType syncType = eIndexSync, UINT32 bitCount = 32,
                                                        ChannelDataType dataType = eInteger_Unsigned_LE, IComment *pComment = NULL,
                                                        IUnit *pUnit = NULL, IConversion *pConversion = NULL,
                                                        ISourceInfo *pChannelSource = NULL, UINT32 flags = 0,
                                                        UINT32 invalBitPos = 0, ErrorCode *pErrorCode = NULL) = 0;

   ///////////////////////////////////////////////////
   //! Create a data writer object to write signal values for this channel group
   //!
   //! \note for MDF3, any other operation that creates a new object and writes it to file (e.g. IFactory::CreateComment or
   //! IFile::CreateChannelGroup) is only allowed after the IDataWriter has been released! Only one IDataWriter can be open per
   //! file, i.e. creating a new IDataWriter will fail as long as another one is open and has not been released yet. It is also not
   //! allowed to create an IDataWriter as long as there is an open data pointer (IDataPointer/IGroupDataPointer) using this
   //! channel group. \note the extended method IChannelGroup::CreateDataWriterEx allows to specify options for the created
   //! IDataWriter \param[out] pErrorCode if given the variable returns the error code for the operation. Default: NULL \param[in]
   //! recordCountForWriteBuffer number of records to store in internal write buffer before flushing to file (MDF4 only, will be
   //! ignored for MDF3).
   //!             <br>Special cases:
   //!             <br>If 0, the number of records to buffer will be determined internally (default)
   //!             <br>If 1, each single record will be written to file immediately (bad performance, should only be used for large
   //!             or VLSD records).
   //! \param[in]  zipTypeAndLevel type and level of compression algorithm to use, see ::ZipTypeAndLevelEnum. Must be
   //! ::eNoCompression for MDF < 4.1. \return     on success the IDataWriter interface of the created data writer, otherwise NULL
   //! <br><br>Please remember to call Release for the returned object or use a smart pointer (see \ref ref_counting).
   virtual IDataWriter *MDFLIBCALL CreateDataWriter(ErrorCode *pErrorCode = NULL, UINT32 recordCountForWriteBuffer = 0,
                                                    ZipTypeAndLevel zipTypeAndLevel = eNoCompression) = 0;

   ///////////////////////////////////////////////////
   //! Get the path separator specified for this channel group as character
   //! \note optional feature available for MDF >= 4.1
   //! \param[out] pErrorCode if not NULL the error code of the operation will be returned
   //! \return     on success the character to be used as path separator, 0 on error or if not available/not defined
   virtual TCHAR MDFLIBCALL GetPathSeparatorChar(ErrorCode *pErrorCode = NULL) = 0;

   ///////////////////////////////////////////////////
   //! Set the path separator for this channel group
   //! \note optional feature, only available for newly created or writable file, not available for MDF < 4.1.
   //! \param[in]  pathSeparatorChar character to be used as path separator, 0 if path separator is not defined
   //! \return error code for the operation
   virtual ErrorCode MDFLIBCALL SetPathSeparatorChar(TCHAR pathSeparatorChar) = 0;

   ///////////////////////////////////////////////////
   //! Set the acquisition name for this channel group
   //! \note only available for newly created or writable file, not available for MDF3, not possible for channel groups using a
   //! remote master group (MDF 4.2 column-oriented storage) \param[in] acquisitionName string to be used as acquisition name, 0 or
   //! empty to delete the name \return error code for the operation
   virtual ErrorCode MDFLIBCALL SetAcquisitionName(LPCTSTR acquisitionName) = 0;

   ///////////////////////////////////////////////////
   //! Change the type of bus event contained in the channel group
   //! Usually the bus event type is set automatically when creating the respective channels in the channel group.
   //! For rare cases, however, it may be necessary to manually change the bus event type of the channel group.
   //! \note only available for newly created or writable file, not available for MDF < 4.1.
   //! \param[in] busEventType of the contained bus event (see ::BusEventTypeEnum).
   //! \return error code for the operation
   virtual ErrorCode MDFLIBCALL SetBusEventType(BusEventType busEventType) = 0;

   ///////////////////////////////////////////////////
   //! Create a data pointer object to navigate and read signal data
   //! \param[in]  options bit combination of option flags, see ::DataPointerOptionsFlagsEnum
   //! \param[out] pErrorCode if not NULL the error code of the operation will be returned
   //! \return pointer to IDataPointer object, NULL on error
   //! <br><br>Please remember to call Release for the returned object or use a smart pointer (see \ref ref_counting).
   virtual IDataPointer *MDFLIBCALL CreateDataPointerEx(UINT32 options, ErrorCode *pErrorCode = NULL) = 0;

   ///////////////////////////////////////////////////
   //! Get event set for events for this channel group
   //! \note The resulting IEventSet object offers further filtering of the events.
   //! \param[in]  filterFlags flags for filtering, value is a bit combination of ::EventFilterFlagsEnum
   //! \param[out] pErrorCode if not NULL the error code of the operation will be returned
   //! \return pointer to IEventSet object, NULL on error
   //! <br><br>Please remember to call Release for the returned object or use a smart pointer (see \ref ref_counting).
   virtual IEventSet *MDFLIBCALL GetEventSet(UINT32 filterFlags = 0, ErrorCode *pErrorCode = NULL) = 0;

   ///////////////////////////////////////////////////
   //! Get start addresses of CG block
   //! \return returns start address of CG block for this channel group, -1 on error or for virtual channel groups.
   virtual INT64 MDFLIBCALL GetBlockStartAddress() = 0;

   ///////////////////////////////////////////////////
   //! Get start addresses of parent DG block
   //! \return returns start address of parent DG block for this channel group, -1 on error or for virtual channel groups.
   virtual INT64 MDFLIBCALL GetParentDataGroupStartAddress() = 0;

   ///////////////////////////////////////////////////
   //! Check if channel group contains an event signal (introduced in MDF 4.2)
   //! \note for MDF version >= 4.2 only a flag is checked, for earlier versions this is not supported
   //! \param[out] pErrorCode if not NULL the error code of the operation will be returned
   //! \return true if the channel group contains a event signal, false otherwise or on error
   virtual bool MDFLIBCALL ContainsEventSignal(ErrorCode *pErrorCode = NULL) = 0;

   ///////////////////////////////////////////////////
   //! Check if channel group uses a master channel group (introduced in MDF 4.2)
   //! \note for MDF version >= 4.2 only a flag is checked, for earlier versions this is not supported
   //! \param[out] pErrorCode if not NULL the error code of the operation will be returned
   //! \return true if the channel group refers to a master channel group, false otherwise or on error
   virtual bool MDFLIBCALL UsesMasterChannelGroup(ErrorCode *pErrorCode = NULL) = 0;

   ///////////////////////////////////////////////////
   //! Get master channel group of this channel group for specified sync type
   //! \note Master channel groups have been introduced in MDF 4.2 and can be used for column-oriented storage
   //! or adding signals to existing channel group without re-writing the records.
   //! Both channel groups must have equal number of samples (see GetSampleCount()).
   //! If this channel group already contains a master channel of the specified sync type
   //! (e.g. the channel group is a master channel group, or no master channel group used like for earlier MDF versions)
   //! the channel group itself will be returned. This is indicated by error code ::eObjectIsSelf.
   //! \param[in] masterSyncType sync type of master channel (usually ::eTimeSync)
   //! \param[out] pErrorCode if not NULL the error code of the operation will be returned
   //! \return pointer to IChannelGroup object, NULL on error or if requested master channel type is not available.
   //! The returned channel group pointer may be the channel group itself in case it contains the desired master channel. In this
   //! case error code will be ::eObjectIsSelf. <br><br>Please remember to call Release for the returned object or use a smart
   //! pointer (see \ref ref_counting).
   virtual IChannelGroup *MDFLIBCALL GetMasterChannelGroup(SyncType masterSyncType = eTimeSync, ErrorCode *pErrorCode = NULL) = 0;

   ///////////////////////////////////////////////////
   //! Get master channel for this channel group for specified sync type
   //! \note Starting with MDF 4.2, a master channel may be contained in another channel group (so-called master channel group).
   //! In contrast to GetMasterChannel(), this method optionally returns the master channel also if it is contained in another
   //! channel group (i.e. a "master channel group"). This will be indicated by error code ::eFromOtherChannelGroup. See also
   //! GetMasterChannelGroup(). \param[in] masterSyncType sync type of master channel (usually ::eTimeSync) \param[in]
   //! considerMasterChannelGroup if true, master channel groups are considered, otherwise not (default: true) \param[out]
   //! pErrorCode if not NULL the error code of the operation will be returned \return pointer to IChannel object, NULL on error or
   //! if requested master channel type is not available <br><br>Please remember to call Release for the returned object or use a
   //! smart pointer (see \ref ref_counting).
   virtual IChannel *MDFLIBCALL GetMasterChannelEx(SyncType masterSyncType = eTimeSync, bool considerMasterChannelGroup = true,
                                                   ErrorCode *pErrorCode = NULL) = 0;

   ///////////////////////////////////////////////////
   //! Create a data writer object to write signal values for this channel group
   //!
   //! \note for MDF3, any other operation that creates a new object and writes it to file (e.g. IFactory::CreateComment or
   //! IFile::CreateChannelGroup) is only allowed after the IDataWriter has been released! Only one IDataWriter can be open per
   //! file, i.e. creating a new IDataWriter will fail as long as there is an open data writer (IDataWriter/IGroupDataWriter) has
   //! not been released yet. It is also not allowed to create an IDataWriter as long as there is an open data pointer
   //! (IDataPointer/IGroupDataPointer) using this channel group. \param[in]  options bit combination of option flags, see
   //! ::DataWriterOptionsFlagsEnum \param[out] pErrorCode if given the variable returns the error code for the operation. Default:
   //! NULL \param[in]  recordCountForWriteBuffer number of records to store in internal write buffer before flushing to file (MDF4
   //! only, will be ignored for MDF3).
   //!             <br>Special cases:
   //!             <br>If 0, the number of records to buffer will be determined internally (default)
   //!             <br>If 1, each single record will be written to file immediately (bad performance, should only be used for large
   //!             or VLSD records).
   //! \param[in]  zipTypeAndLevel type and level of compression algorithm to use, see ::ZipTypeAndLevelEnum. Must be
   //! ::eNoCompression for MDF < 4.1. \return     on success the IDataWriter interface of the created data writer, otherwise NULL
   //! <br><br>Please remember to call Release for the returned object or use a smart pointer (see \ref ref_counting).
   virtual IDataWriter *MDFLIBCALL CreateDataWriterEx(UINT32 options, ErrorCode *pErrorCode = NULL,
                                                      UINT32 recordCountForWriteBuffer = 0,
                                                      ZipTypeAndLevel zipTypeAndLevel  = eNoCompression) = 0;

   ///////////////////////////////////////////////////
   //! Reset all samples in this channel group.
   //! Resetting data is only possible if no IDataWriter for the channel group or data pointer (IDataPointer/IGroupDataPointer)
   //! using this channel group is open.
   //!
   //! \note Only available for newly created or writable file.
   //! Not supported for unsorted channel groups (see IsSorted()).
   //! \param[in] options bit combination of option flags, see ::ResetDataOptionsFlagsEnum
   //! \return error code for the operation
   virtual ErrorCode MDFLIBCALL ResetData(UINT32 options = 0) = 0;

   ///////////////////////////////////////////////////
   //! Get record ID specified for channel group
   //!
   //! The record ID is necessary for unsorted groups, but may also occur in records of sorted groups (unusual and not recommended
   //! because it blows up the record size unnecessarily). \note For sorted groups the ID specified in CG block is returned even if
   //! no record ID is used (see GetSizeOfRecordIdentifier): this may not be unique or can be simply 0. Therefore, the error code
   //! will be eNotAvailable in case no record ID is used. \param[out] pErrorCode if not NULL the error code of the operation will
   //! be returned \return record ID specified in CG block, 0 on error (note: 0 can also be a valid record ID, although it is
   //! recommended to avoid this)
   virtual UINT64 MDFLIBCALL GetRecordIdentifier(ErrorCode *pErrorCode = NULL) = 0;

   ///////////////////////////////////////////////////
   //! Get number of bytes used for record ID for this channel group
   //!
   //! The record ID is necessary for unsorted groups, but may also occur in records of sorted groups (unusual and not recommended
   //! because it blows up the record size unnecessarily). If no record ID is used in the record the methods returns 0, otherwise
   //! the number of bytes for the record ID, which can be 1 for MDF3 and 1, 2, 4, or 8 for MDF4. <br><br>For MDF3, it also is
   //! allowed that the record ID is repeated at the end of the record (intended to allow reverse reading of the records). This
   //! very unusual MDF3 feature can be requested via output parameter pRepeatedAtEndOfRecord. \param[out] pRepeatedAtEndOfRecord
   //! if not NULL this parameter returns true in case the record ID is repeated at end of record (only possible for MDF3).
   //! \param[out] pErrorCode if not NULL the error code of the operation will be returned
   //! \return number of bytes used for record ID, 0 on error or if no record ID is used
   virtual UINT8 MDFLIBCALL GetSizeOfRecordIdentifier(bool *pRepeatedAtEndOfRecord = NULL, ErrorCode *pErrorCode = NULL) = 0;

   ///////////////////////////////////////////////////
   //! Determine if this channel group contains a VLSD channel
   //!
   //! \param[out] pErrorCode if not NULL the error code of the operation will be returned
   //! \return true if any channel in this channel group has type ::eVariableLength, otherwise false
   virtual bool MDFLIBCALL ContainsVLSD(ErrorCode *pErrorCode = NULL) = 0;

   ///////////////////////////////////////////////////
   //! Create a data writer object to write signal values for this channel group and the logical group it belongs to
   //!
   //! For channel groups using a remote master (see UsesMasterChannelGroup) the remote master group will be added to the
   //! IGroupDataWriter object on creation. Further groups can be added later, or use option ::eGroupDataWriterAddLogicalGroup to
   //! immediately add all groups of the "logical" group, i.e. all groups sharing the same remote master group. Only one data
   //! writer can be open per file, i.e. creating a new IGroupDataWriter will fail as long as another one is open and has not been
   //! released yet. It is also not allowed to create an IGroupDataWriter as long as there is an open data pointer
   //! (IDataPointer/IGroupDataPointer) using this channel group. \note only available for newly created or writable file
   //! \param[in]  options bit combination of option flags, see ::GroupDataWriterOptionsFlagsEnum
   //! \param[out] pErrorCode if given the variable returns the error code for the operation. Default: NULL
   //! \param[in]  recordCountForWriteBuffer number of records to store in internal write buffer before flushing to file.
   //!             <br>Special cases:
   //!             <br>If 0, the number of records to buffer will be determined internally (default)
   //!             <br>If 1, each single record will be written to file immediately (bad performance, should only be used for large
   //!             or VLSD records).
   //! \param[in]  zipTypeAndLevel type and level of compression algorithm to use, see ::ZipTypeAndLevelEnum. Must be
   //! ::eNoCompression for MDF < 4.1. \return     on success the IGroupDataWriter interface of the created data writer, otherwise
   //! NULL <br><br>Please remember to call Release for the returned object or use a smart pointer (see \ref ref_counting).
   virtual IGroupDataWriter *MDFLIBCALL CreateGroupDataWriter(UINT32 options, ErrorCode *pErrorCode = NULL,
                                                              UINT32 recordCountForWriteBuffer = 0,
                                                              ZipTypeAndLevel zipTypeAndLevel  = eNoCompression) = 0;
};
