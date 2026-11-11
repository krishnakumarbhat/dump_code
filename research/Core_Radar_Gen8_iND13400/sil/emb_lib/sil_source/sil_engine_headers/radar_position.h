#ifndef RADAR_POSITION_H
#define RADAR_POSITION_H

#include <cstdint>

enum Radar_Position : uint8_t
{
   UNKNOWN_POSITION = 0U,
   REAR_LEFT        = 1U,
   REAR_RIGHT       = 2U,
   FRONT_RIGHT      = 3U,
   FRONT_LEFT       = 4U,
   FRONT_CENTER     = 5U,
   REAR_CENTER      = 6U,
   RIGHT_CENTER     = 7U,
   LEFT_CENTER      = 8U,
   INVALID_POSITION = 9U,
   MAX_SENSORS      = 20U,
};

#endif // RADAR_POSITION_H
