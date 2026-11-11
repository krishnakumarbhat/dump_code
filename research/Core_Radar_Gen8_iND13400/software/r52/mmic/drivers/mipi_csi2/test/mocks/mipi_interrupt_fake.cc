/**
 * @file mipi_interrupt_fake.cc
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
#include "mipi_interrupt_fake.h"

DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, MIPI_Irq_Setup, mipi_ithandler, mipi_ithandler, mipi_ithandler, mipi_ithandler,
                       mipi_ithandler);
DEFINE_FAKE_VOID_FUNC(Start_MIPI_Frame);
DEFINE_FAKE_VOID_FUNC(End_MIPI_Frame);
DEFINE_FAKE_VOID_FUNC(Start_MIPI_Chirp);
DEFINE_FAKE_VOID_FUNC(End_MIPI_Chirp);
DEFINE_FAKE_VOID_FUNC(MIPI_FuSa_IRQ);
DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, MIPI_Get_Frm_End_Flag, volatile bool *);
DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, MIPI_Clear_Frm_End_Flag);
DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, MIPI_Get_Frm_Start_Flag, volatile bool *);
DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, MIPI_Clear_Frm_Start_Flag);
DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, MIPI_Get_Chp_Start_Flag, volatile bool *);
DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, MIPI_Clear_Chp_Start_Flag);
DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, MIPI_Get_Chp_End_Flag, volatile bool *);
DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, MIPI_Clear_Chp_End_Flag);
DEFINE_FAKE_VOID_FUNC(MIPI_Chirp_Start_Handler);
DEFINE_FAKE_VOID_FUNC(MIPI_Chirp_End_Handler);
DEFINE_FAKE_VOID_FUNC(MIPI_Frame_Start_Handler);
DEFINE_FAKE_VOID_FUNC(MIPI_Frame_End_Handler);
