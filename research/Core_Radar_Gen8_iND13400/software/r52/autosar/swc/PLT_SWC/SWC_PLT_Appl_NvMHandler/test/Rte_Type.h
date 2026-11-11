#ifndef RTE_TYPE_H
#define RTE_TYPE_H

#include <stdint.h>

typedef uint8_t boolean;
typedef uint8_t uint8;
typedef uint16_t uint16;
typedef uint32_t uint32;
typedef int8_t sint8;
typedef int16_t sint16;
typedef int32_t sint32;
typedef float float32;

#ifndef TRUE
   #define TRUE ((boolean)1U)
#endif
#ifndef FALSE
   #define FALSE ((boolean)0U)
#endif

#endif
