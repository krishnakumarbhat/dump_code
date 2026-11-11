#ifndef MIPI_INTERRUPT_H
#define MIPI_INTERRUPT_H

/*===========================================================================*
 * Includes
 *===========================================================================*/
#include "Std_Types.h"
#include "csi_sfrs.h"
#include "mipi_ocp_mem_sfrs.h"
#include "mipi_sfrs.h"
#include "mipi_stat_mem_sfrs.h"

#ifdef __cplusplus
extern "C"
{      /* Inclusion of header files should NOT be inside the extern "C" block */
#endif /* __cplusplus */
       /*===========================================================================*\
          * Exported preprocessor #define constants (object-like macros)
      \*===========================================================================*/
#define MIPI_FUSA_IRQ0_ENABLE_MASK 0x00001FDFUL
/* TODO : currently amsked csr_meta_read_err_flag and csr_meta_fifo_empty_flag(IRQ1), reason : Fault Triggered without any Fault
 * Injection */
#define MIPI_FUSA_IRQ1_ENABLE_MASK         0x7FBF2000UL
#define MIPI_FUSA_IRQ2_ENABLE_MASK         0x0FFEBFF0UL
#define MIPI_FUSA_IRQ_CLEAR_ALL_FLAGS_MASK 0xFFFFFFFFUL
   /*===========================================================================*
    * Global Constants
    *===========================================================================*/

   /*===========================================================================*
    * Global Function Macros
    *===========================================================================*/

   /*===========================================================================*
    * Global Datatypes and Structures
    *===========================================================================*/
   typedef void (*mipi_ithandler)(void);

   /*===========================================================================*
    * Global Data
    *===========================================================================*/

   /*===========================================================================*
    * Global Function Prototypes
    *===========================================================================*/

   /**
    * @brief       Configure interrupt handlers for MIPI
    * @param [in]  frm_start_handler handler for frame start IT or 0
    * @param [in]  frm_end_handler handler for frame end IT or 0
    * @param [in]  chp_start_handler handler for chirp start IT or 0
    * @param [in]  chp_end_handler handler for chirp end IT or 0
    * @return      E_OK if successful E_NOT_OK if failed
    */
   Std_ReturnType MIPI_Irq_Setup(const mipi_ithandler frm_start_handler, const mipi_ithandler frm_end_handler,
                                 const mipi_ithandler chp_start_handler, const mipi_ithandler chp_end_handler,
                                 const mipi_ithandler MIPI_FuSa_IRQ_handler);

   /**
    * MIPI_Get_Frm_End_Flag
    * @brief         Get the the MIPI FRM END Flag
    * @param [out]   flag pointer to the flag
    * @return        E_OK if successful E_NOT_OK if failed
    */
   Std_ReturnType MIPI_Get_Frm_End_Flag(volatile bool *flag);

   /**
    * MIPI_Clear_Frm_End_Flag
    * @brief         Clear the the MIPI FRM END Flag
    * @return        E_OK if successful E_NOT_OK if failed
    */
   Std_ReturnType MIPI_Clear_Frm_End_Flag(void);

   /**
    * MIPI_Get_Frm_Start_Flag
    * @brief         Get the the MIPI FRM START Flag
    * @param [out]   flag pointer to the flag
    * @return        E_OK if successful E_NOT_OK if failed
    */
   Std_ReturnType MIPI_Get_Frm_Start_Flag(volatile bool *flag);

   /**
    * MIPI_Clear_Frm_Start_Flag
    * @brief         Clear the the MIPI FRM START Flag
    * @return        E_OK if successful E_NOT_OK if failed
    */
   Std_ReturnType MIPI_Clear_Frm_Start_Flag(void);

   /**
    * MIPI_Get_Chp_Start_Flag
    * @brief         Get the the MIPI CHIRP START Flag
    * @param [out]   flag pointer to the flag
    * @return        E_OK if successful E_NOT_OK if failed
    */
   Std_ReturnType MIPI_Get_Chp_Start_Flag(volatile bool *flag);

   /**
    * MIPI_Clear_Chp_Start_Flag
    * @brief         Clear the the MIPI CHIRP START Flag
    * @return        E_OK if successful E_NOT_OK if failed
    */
   Std_ReturnType MIPI_Clear_Chp_Start_Flag(void);

   /**
    * MIPI_Get_Chp_End_Flag
    * @brief         Get the the MIPI CHIRP END Flag
    * @param [out]   flag pointer to the flag
    * @return        E_OK if successful E_NOT_OK if failed
    */
   Std_ReturnType MIPI_Get_Chp_End_Flag(volatile bool *flag);

   /**
    * MIPI_Clear_Chp_End_Flag
    * @brief         Clear the the MIPI CHIRP END Flag
    * @return        E_OK if successful E_NOT_OK if failed
    */
   Std_ReturnType MIPI_Clear_Chp_End_Flag(void);

   extern void Start_MIPI_Chirp(void);
   extern void End_MIPI_Chirp(void);
   extern void Start_MIPI_Frame(void);
   extern void End_MIPI_Frame(void);
   extern void MIPI_FuSa_IRQ(void);
   extern void MIPI_Chirp_Start_Handler(void);
   extern void MIPI_Chirp_End_Handler(void);
   extern void MIPI_Frame_Start_Handler(void);
   extern void MIPI_Frame_End_Handler(void);
   extern void MIPI_FuSa_Irq_Handler(void);
   /*===========================================================================*
    * Global Inline Functions
    *===========================================================================*/

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif /* MIPI_INTERRUPT_H */
