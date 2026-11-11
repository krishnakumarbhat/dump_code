/*
 * Copyright (C) 2026 Aptiv. All rights reserved.
 *
 * File:    emb_tracker_stubs.h
 * Purpose: Embedded tracker stub function declarations
 * Abbrev:  List any abbreviations used in this file
 * Trace:   Traceability ID (requirement, work item, etc.)
 */
/*==========================================================================*/
#ifndef EMB_TRACKER_STUBS_H
#define EMB_TRACKER_STUBS_H

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include "ipc_data.h"

/* ========================================================================== */
/*                              Macros                                        */
/* ========================================================================== */
#define DEFAULT_TRACKER_TEST_CASE 0

#ifndef DEG2RADF
   #define DEG2RADF ((float)0.0174532925199433)
   #define RAD2DEGF ((float)1 / DEG2RAD)
#endif

#ifndef NEG_FLOAT
   #define NEG_FLOAT (-1.0f)
#endif

/* ========================================================================== */
/*                      Function Declarations                                 */
/* ========================================================================== */
#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

   /* Test hook: set false to force invalid partner recvd_flags for validity-check branch coverage */
   extern bool stub_force_partner_flags_valid;

   /* Set IPC pointers so stub functions can access D2M/M2D data */
   void Set_Stub_IPC_Ptrs(D2M_Msg_T *p_d2m, M2D_Msg_T *p_m2d);
   void Set_Onetime_Stub_IPC_Ptrs(volatile M2D_One_Time_Msg_T *p_ipc_m2d_one_time);

   /* Tracker stub functions called from wrapper when stub flag is passed in build command */
   void Populate_Ipc_Data_For_Init_Stub_Sensors(volatile M2D_One_Time_Msg_T *p_ipc_m2d_one_time, M2D_Msg_T *p_ipc_m2d);
   void Populate_Ipc_Data_For_Stub_Host(D2M_Msg_T *p_ipc_d2m, M2D_Msg_T *p_ipc_m2d);
   void Populate_Ipc_Data_For_Stub_Dets();

   void Bsis_Tos_TP_Test_Case();
   void Bsis_Tos_TN_Test_Case();
   void Bsis_Sot_TP_Test_Case();
   void Bsis_Sot_TN_Test_Case();
   void Bsis_Object_Enters_And_Stay_In_Zone();
   void Mois_Close_Proxi_TP_L_to_R_Test_Case();
   void Mois_Close_Proxi_TP_R_to_L_Test_Case();
   void Mois_Normal_Proxi_TP_L_to_R_Test_Case();
   void Mois_Normal_Proxi_TP_R_to_L_Test_Case();
   void Mois_Far_Proxi_TN_L_to_R_Test_Case();
   void Mois_Far_Proxi_TN_R_to_L_Test_Case();
   void Mois_Object_Drive_Front();
   typedef struct Stub_Sensor_Pose_Tag
   {
      float x_m;
      float y_m;
      float yaw_rad;
      float roll_rad;
   } Stub_Sensor_Pose_T;

   typedef enum Stub_Env_Mode_Tag
   {
      STUB_ENV         = 0,
      STUB_ENV_BSIS_AL = 1,
      STUB_ENV_MOIS_AL = 2,
   } Stub_Env_Mode_T;

   typedef enum Mois_Test_Case_Selection_Tag
   {
      MOIS_CLOSE_PROXI_TP_L_TO_R_TEST_CASE = 1,
      MOIS_CLOSE_PROXI_TP_R_TO_L_TEST_CASE,
      MOIS_NORMAL_PROXI_TP_L_TO_R_TEST_CASE,
      MOIS_NORMAL_PROXI_TP_R_TO_L_TEST_CASE,
      MOIS_FAR_PROXI_TN_L_TO_R_TEST_CASE,
      MOIS_FAR_PROXI_TN_R_TO_L_TEST_CASE,
      MOIS_OBJECT_DRIVE_FRONT,
   } Mois_Test_Case_Selection_T;

   typedef enum Bsis_Test_Case_Selection_Tag
   {
      BSIS_TOS_TP_TEST_CASE = 1,
      BSIS_SOT_TP_TEST_CASE,
      BSIS_TOS_TN_TEST_CASE,
      BSIS_SOT_TN_TEST_CASE,
      BSIS_OBJECT_ENTERS_AND_STAY_IN_ZONE,
   } Bsis_Test_Case_Selection_T;

   typedef struct Simulation_Target_Params_Tag
   {
      float tgt_xpos;
      float tgt_ypos;
      float tgt_xvel;
      float tgt_yvel;
   } Simulation_Target_Params_T;
#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif /* EMB_TRACKER_STUBS_H */
