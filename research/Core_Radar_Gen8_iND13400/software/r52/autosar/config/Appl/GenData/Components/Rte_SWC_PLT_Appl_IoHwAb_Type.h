/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *             File:  Rte_SWC_PLT_Appl_IoHwAb_Type.h
 *           Config:  Gen8_iND13400.dpa
 *      ECU-Project:  Gen8_iND13400
 *
 *        Generator:  MICROSAR RTE Generator Version 4.40.00
 *                    RTE Core Version 4.40.00
 *          License:  PAI19494
 *
 *      Description:  Application types header file for SW-C <SWC_PLT_Appl_IoHwAb>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_SWC_PLT_APPL_IOHWAB_TYPE_H
# define RTE_SWC_PLT_APPL_IOHWAB_TYPE_H

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

# include "Rte_Type.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * Range, Invalidation, Enumeration and Bit Field Definitions
 *********************************************************************************************************************/

#  ifndef FRONT_LEFT_VALUE
#   define FRONT_LEFT_VALUE (0U)
#  endif

#  ifndef REAR_LEFT_VALUE
#   define REAR_LEFT_VALUE (1U)
#  endif

#  ifndef FRONT_RIGHT_VALUE
#   define FRONT_RIGHT_VALUE (2U)
#  endif

#  ifndef REAR_RIGHT_VALUE
#   define REAR_RIGHT_VALUE (3U)
#  endif

#  ifndef INVALID_POS_VALUE
#   define INVALID_POS_VALUE (255U)
#  endif
#  ifndef LO_V2_FROM_LO_Vtemp
#   define LO_V2_FROM_LO_Vtemp (0U)
#  endif

#  ifndef LO_V1_FROM_LO_Vtemp
#   define LO_V1_FROM_LO_Vtemp (1U)
#  endif

#  ifndef LO_V2_FROM_LO_V1
#   define LO_V2_FROM_LO_V1 (2U)
#  endif

#  ifndef NORMV_FROM_LO_VTEMP_TONORM
#   define NORMV_FROM_LO_VTEMP_TONORM (3U)
#  endif

#  ifndef NORMV_FROM_LO_V1_TONORM
#   define NORMV_FROM_LO_V1_TONORM (4U)
#  endif

#  ifndef NORMV_FROM_LO_V2_TONORM
#   define NORMV_FROM_LO_V2_TONORM (5U)
#  endif

#  ifndef HI_V2_FROM_HI_Vtemp
#   define HI_V2_FROM_HI_Vtemp (6U)
#  endif

#  ifndef HI_V1_FROM_HI_Vtemp
#   define HI_V1_FROM_HI_Vtemp (7U)
#  endif

#  ifndef HI_V2_FROM_HI_V1
#   define HI_V2_FROM_HI_V1 (8U)
#  endif

#  ifndef NORMV_FROM_HI_VTEMP_TONORM
#   define NORMV_FROM_HI_VTEMP_TONORM (9U)
#  endif

#  ifndef NORMV_FROM_HI_V1_TONORM
#   define NORMV_FROM_HI_V1_TONORM (10U)
#  endif

#  ifndef NORMV_FROM_HI_V2_TONORM
#   define NORMV_FROM_HI_V2_TONORM (11U)
#  endif
#  ifndef IMMEDIATE_TEMPERATURES_KELVIN
#   define IMMEDIATE_TEMPERATURES_KELVIN (0U)
#  endif

#  ifndef AVERAGE_TEMPERATURES_KELVIN
#   define AVERAGE_TEMPERATURES_KELVIN (1U)
#  endif

#  ifndef IMMEDIATE_TEMPERATURES_CELCIUS
#   define IMMEDIATE_TEMPERATURES_CELCIUS (2U)
#  endif

#  ifndef AVERAGE_TEMPERATURES_CELCIUS
#   define AVERAGE_TEMPERATURES_CELCIUS (3U)
#  endif

#  ifndef IMMEDIATE_TEMPERATURES_FAHRENHEIT
#   define IMMEDIATE_TEMPERATURES_FAHRENHEIT (4U)
#  endif

#  ifndef AVERAGE_TEMPERATURES_FAHRENHEIT
#   define AVERAGE_TEMPERATURES_FAHRENHEIT (5U)
#  endif
#  ifndef PowerON
#   define PowerON (0U)
#  endif

#  ifndef NORMV
#   define NORMV (1U)
#  endif

#  ifndef LO_V1
#   define LO_V1 (2U)
#  endif

#  ifndef HI_V1
#   define HI_V1 (3U)
#  endif

#  ifndef LO_V2
#   define LO_V2 (4U)
#  endif

#  ifndef HI_V2
#   define HI_V2 (5U)
#  endif

#  ifndef LO_Vtemp
#   define LO_Vtemp (6U)
#  endif

#  ifndef LO_VTEMP_TONORM
#   define LO_VTEMP_TONORM (7U)
#  endif

#  ifndef LO_V1_TONORM
#   define LO_V1_TONORM (8U)
#  endif

#  ifndef LO_V2_TONORM
#   define LO_V2_TONORM (9U)
#  endif

#  ifndef HI_VTEMP_TONORM
#   define HI_VTEMP_TONORM (10U)
#  endif

#  ifndef HI_V1_TONORM
#   define HI_V1_TONORM (11U)
#  endif

#  ifndef HI_V2_TONORM
#   define HI_V2_TONORM (12U)
#  endif

#  ifndef HI_Vtemp
#   define HI_Vtemp (13U)
#  endif
# endif /* RTE_CORE */


/**********************************************************************************************************************
 * Definitions for Mode Management
 *********************************************************************************************************************/
# ifndef RTE_MODETYPE_DcmSessionPrecondition_Mode
#  define RTE_MODETYPE_DcmSessionPrecondition_Mode
typedef uint8 Rte_ModeType_DcmSessionPrecondition_Mode;
# endif

# define RTE_MODE_SWC_PLT_Appl_IoHwAb_DcmSessionPrecondition_Mode_PowerON (0U)
# ifndef RTE_MODE_DcmSessionPrecondition_Mode_PowerON
#  define RTE_MODE_DcmSessionPrecondition_Mode_PowerON (0U)
# endif
# define RTE_MODE_SWC_PLT_Appl_IoHwAb_DcmSessionPrecondition_Mode_NORMV (1U)
# ifndef RTE_MODE_DcmSessionPrecondition_Mode_NORMV
#  define RTE_MODE_DcmSessionPrecondition_Mode_NORMV (1U)
# endif
# define RTE_MODE_SWC_PLT_Appl_IoHwAb_DcmSessionPrecondition_Mode_LO_V1 (2U)
# ifndef RTE_MODE_DcmSessionPrecondition_Mode_LO_V1
#  define RTE_MODE_DcmSessionPrecondition_Mode_LO_V1 (2U)
# endif
# define RTE_MODE_SWC_PLT_Appl_IoHwAb_DcmSessionPrecondition_Mode_HI_V1 (3U)
# ifndef RTE_MODE_DcmSessionPrecondition_Mode_HI_V1
#  define RTE_MODE_DcmSessionPrecondition_Mode_HI_V1 (3U)
# endif
# define RTE_MODE_SWC_PLT_Appl_IoHwAb_DcmSessionPrecondition_Mode_LO_V2 (4U)
# ifndef RTE_MODE_DcmSessionPrecondition_Mode_LO_V2
#  define RTE_MODE_DcmSessionPrecondition_Mode_LO_V2 (4U)
# endif
# define RTE_MODE_SWC_PLT_Appl_IoHwAb_DcmSessionPrecondition_Mode_HI_V2 (5U)
# ifndef RTE_MODE_DcmSessionPrecondition_Mode_HI_V2
#  define RTE_MODE_DcmSessionPrecondition_Mode_HI_V2 (5U)
# endif
# define RTE_MODE_SWC_PLT_Appl_IoHwAb_DcmSessionPrecondition_Mode_LO_Vtemp (6U)
# ifndef RTE_MODE_DcmSessionPrecondition_Mode_LO_Vtemp
#  define RTE_MODE_DcmSessionPrecondition_Mode_LO_Vtemp (6U)
# endif
# define RTE_MODE_SWC_PLT_Appl_IoHwAb_DcmSessionPrecondition_Mode_LO_VTEMP_TONORM (7U)
# ifndef RTE_MODE_DcmSessionPrecondition_Mode_LO_VTEMP_TONORM
#  define RTE_MODE_DcmSessionPrecondition_Mode_LO_VTEMP_TONORM (7U)
# endif
# define RTE_MODE_SWC_PLT_Appl_IoHwAb_DcmSessionPrecondition_Mode_LO_V1_TONORM (8U)
# ifndef RTE_MODE_DcmSessionPrecondition_Mode_LO_V1_TONORM
#  define RTE_MODE_DcmSessionPrecondition_Mode_LO_V1_TONORM (8U)
# endif
# define RTE_MODE_SWC_PLT_Appl_IoHwAb_DcmSessionPrecondition_Mode_LO_V2_TONORM (9U)
# ifndef RTE_MODE_DcmSessionPrecondition_Mode_LO_V2_TONORM
#  define RTE_MODE_DcmSessionPrecondition_Mode_LO_V2_TONORM (9U)
# endif
# define RTE_MODE_SWC_PLT_Appl_IoHwAb_DcmSessionPrecondition_Mode_HI_VTEMP_TONORM (10U)
# ifndef RTE_MODE_DcmSessionPrecondition_Mode_HI_VTEMP_TONORM
#  define RTE_MODE_DcmSessionPrecondition_Mode_HI_VTEMP_TONORM (10U)
# endif
# define RTE_MODE_SWC_PLT_Appl_IoHwAb_DcmSessionPrecondition_Mode_HI_V1_TONORM (11U)
# ifndef RTE_MODE_DcmSessionPrecondition_Mode_HI_V1_TONORM
#  define RTE_MODE_DcmSessionPrecondition_Mode_HI_V1_TONORM (11U)
# endif
# define RTE_MODE_SWC_PLT_Appl_IoHwAb_DcmSessionPrecondition_Mode_HI_V2_TONORM (12U)
# ifndef RTE_MODE_DcmSessionPrecondition_Mode_HI_V2_TONORM
#  define RTE_MODE_DcmSessionPrecondition_Mode_HI_V2_TONORM (12U)
# endif
# define RTE_MODE_SWC_PLT_Appl_IoHwAb_DcmSessionPrecondition_Mode_HI_Vtemp (13U)
# ifndef RTE_MODE_DcmSessionPrecondition_Mode_HI_Vtemp
#  define RTE_MODE_DcmSessionPrecondition_Mode_HI_Vtemp (13U)
# endif
# define RTE_TRANSITION_SWC_PLT_Appl_IoHwAb_DcmSessionPrecondition_Mode (14U)
# ifndef RTE_TRANSITION_DcmSessionPrecondition_Mode
#  define RTE_TRANSITION_DcmSessionPrecondition_Mode (14U)
# endif

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_SWC_PLT_APPL_IOHWAB_TYPE_H */
