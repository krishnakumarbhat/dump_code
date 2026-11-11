/**
 * @file mipi_interrupt_fake.h
 *
 *------------------------------------------------------------------------------
 *
 * Copyright (C) 2025 Aptiv. All rights reserved.
 * Aptiv Sensitive Business – Restricted Aptiv information. Do not disclose
 *
 *------------------------------------------------------------------------------
 *
 * @section DESC DESCRIPTION:
 *
 * Mocks of the functions in mipi_interrupt.c file.
 *
 * @section ABBR ABBREVIATIONS:
 *   - MIPI: Mobile Industry Processor Interface
 *
 * @section TRACE TRACEABILITY INFO:
 *   - Design Document(s):
 *     - Design_Doc_RDD_SIL.md
 *
 *   - Requirements Document(s):
 *     - MIPI Driver Requirements
 *
 * @section DFS DEVIATIONS FROM STANDARDS:
 *   - None
 */
#ifndef MIPI_INTERRUPT_FAKE_H_
#define MIPI_INTERRUPT_FAKE_H_

#include "fff.h"

extern "C"
{
#include "mipi_interrupt.h"

   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, MIPI_Irq_Setup, mipi_ithandler, mipi_ithandler, mipi_ithandler, mipi_ithandler,
                           mipi_ithandler);
   DECLARE_FAKE_VOID_FUNC(Start_MIPI_Frame);
   DECLARE_FAKE_VOID_FUNC(End_MIPI_Frame);
   DECLARE_FAKE_VOID_FUNC(Start_MIPI_Chirp);
   DECLARE_FAKE_VOID_FUNC(End_MIPI_Chirp);
   DECLARE_FAKE_VOID_FUNC(MIPI_FuSa_IRQ);
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, MIPI_Get_Frm_End_Flag, volatile bool *);
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, MIPI_Clear_Frm_End_Flag);
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, MIPI_Get_Frm_Start_Flag, volatile bool *);
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, MIPI_Clear_Frm_Start_Flag);
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, MIPI_Get_Chp_Start_Flag, volatile bool *);
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, MIPI_Clear_Chp_Start_Flag);
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, MIPI_Get_Chp_End_Flag, volatile bool *);
   DECLARE_FAKE_VALUE_FUNC(Std_ReturnType, MIPI_Clear_Chp_End_Flag);
   DECLARE_FAKE_VOID_FUNC(MIPI_Chirp_Start_Handler);
   DECLARE_FAKE_VOID_FUNC(MIPI_Chirp_End_Handler);
   DECLARE_FAKE_VOID_FUNC(MIPI_Frame_Start_Handler);
   DECLARE_FAKE_VOID_FUNC(MIPI_Frame_End_Handler);
}

#endif /* MIPI_INTERRUPT_FAKE_H_ */
