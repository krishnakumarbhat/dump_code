#ifndef RADAR_SIL_VERSION_H
#define RADAR_SIL_VERSION_H

#include "RR_ADAS_SYMBOL_Enum.h"
#include <cstdint>

#pragma pack(push, 2)

#ifndef _RADAR_Version_Info_Tag_
   #define _RADAR_Version_Info_Tag_
typedef struct RADAR_Version_Info_Tag
{
   // Radar SW version
   uint8_t Release_Revision; // Ascii of X/Y
   uint8_t Promote_Revision; // Ascii of Major
   uint8_t Field_Revision;   // Ascii of Minor
   uint32_t hw_Version;      // Radar HW Version
   // Various version for each stream(avail in MUDP stream header)
   uint8_t strm_version[MAX_RADAR_LOGGING_SOURCE];

} RADAR_Version_Info_T;

#endif // _RADAR_Version_Info_Tag_
#pragma pack(pop)
#endif // RADAR_SIL_VERSION_H
