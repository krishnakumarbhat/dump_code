/* Stub J1939Rm_Types.h - provided per J1939Dcm TechRef section 6.4
 * Self-contained: does NOT include Rte_J1939Rm_Type.h.
 * Used when J1939Dcm is operated without MICROSAR J1939Rm. */

#if !defined(J1939RM_TYPES_H)
   #define J1939RM_TYPES_H

   #include "ComStack_Types.h"

   /* Constants */
   #define J1939RM_MAX_PDU_SIZE (8u)
   #define J1939RM_EXTID_UNUSED (0xFFu)

   /* J1939Rm_AckCode values */
   #define J1939RM_ACK_POSITIVE       (0x00u)
   #define J1939RM_ACK_NEGATIVE       (0x01u)
   #define J1939RM_ACK_ACCESS_DENIED  (0x02u)
   #define J1939RM_ACK_CANNOT_RESPOND (0x03u)

   /* J1939Rm_ExtIdInfoType ExtIdType values */
   #define J1939RM_EXTID_NONE  (0x00u)
   #define J1939RM_EXTID_ONE   (0x01u)
   #define J1939RM_EXTID_TWO   (0x02u)
   #define J1939RM_EXTID_THREE (0x03u)

/* J1939Rm acknowledgement code type */
typedef uint8 J1939Rm_AckCode;

/* J1939Rm extended identifier info type */
typedef struct
{
   uint8 ExtIdType;
   uint8 ExtId1;
   uint8 ExtId2;
   uint8 ExtId3;
} J1939Rm_ExtIdInfoType;

#endif /* J1939RM_TYPES_H */
