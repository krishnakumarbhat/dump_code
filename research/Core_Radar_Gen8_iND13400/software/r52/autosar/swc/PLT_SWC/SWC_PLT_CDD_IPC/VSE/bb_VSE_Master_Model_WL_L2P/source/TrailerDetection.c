/*
 * File: TrailerDetection.c
 *
 * Code generated for Simulink model 'TrailerDetection'.
 *
 * Model version                  : 1.1004
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Mar 18 16:07:15 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives:
 *    1. RAM efficiency
 *    2. ROM efficiency
 *    3. Safety precaution
 *    4. Execution efficiency
 *    5. MISRA C:2012 guidelines
 *    6. Traceability
 *    7. Debugging
 * Validation result: Not run
 */

#include "TrailerDetection.h"
#include "TrailerDetection_private.h"

/* Output and update for referenced model: 'TrailerDetection' */
void TrailerDetection(const uint8_T *rtu_VsVCAN_TrlrConnectionSts, const uint8_T *rtu_VsVCAN_ITBM_TrlrStat,
                      const boolean_T *rtu_VsPROXI_CANNode63_TTM, const boolean_T *rtu_VsPROXI_CANNode95_ITBM_ITCM,
                      const uint8_T *rtu_VsTracker_TrlrDetect, const uint8_T *rtu_VeTracker_TrlrDetectConfLvl,
                      const uint8_T *rtu_VeTracker_TrlrLenConfLvl, const uint8_T *rtu_VeTracker_TrlrWidthConfLvl,
                      const real32_T *rtu_VsTracker_m_TrlrLen, const real32_T *rtu_VsTracker_m_TrlrWidth,
                      const uint8_T *rtu_VsTracker_RadarDetectionSts, const int32_T *rtu_VsTracker_RadarDetectionTimer,
                      const int32_T *rtu_VsTracker_StationaryTimer, enum_Presence_Status *rty_VsVSE_TrlrDetectSts,
                      uint8_T *rty_VeVSE_TrlrDetectStsConfLvl, real32_T *rty_VsVSE_m_TrlrLen, uint8_T *rty_VeVSE_TrlrLenConfLvl,
                      real32_T *rty_VsVSE_m_TrlrWidth, uint8_T *rty_VeVSE_TrlrWidthConfLvl, boolean_T *rty_VeVSE_RadarDetectionSts,
                      real32_T *rty_VsVSE_s_RadarDetectionTimer, real32_T *rty_VsVSE_s_StationaryTimer)
{
   uint8_T rtb_DataTypeConversion;
   uint8_T rtb_Merge2;
   enum_TrackerTrailerPresence_Status rtb_y_d;
   enum_TrailerConnection27_Status rtb_y;
   enum_ITBMTrlrStat29_Status rtb_y_n;
   boolean_T guard1 = false;

   /* MATLAB Function: '<S1>/MATLAB Function1' */
   guard1 = false;
   switch (*rtu_VsTracker_TrlrDetect)
   {
      case 0:
         rtb_y_d = No_Trailer;
         guard1  = true;
         break;

      case 1:
         /* Outputs for IfAction SubSystem: '<S7>/If Action Subsystem2' incorporates:
          *  ActionPort: '<S9>/Action Port'
          */
         /* If: '<S7>/If1' incorporates:
          *  Constant: '<S7>/HW_Connection_True1'
          *  Inport: '<S9>/In1'
          */
         rtb_Merge2 = 1U;

         /* End of Outputs for SubSystem: '<S7>/If Action Subsystem2' */
         break;

      case 2:
         rtb_y_d = Unknown;
         guard1  = true;
         break;

      default:
         rtb_y_d = Unknown;
         guard1  = true;
         break;
   }

   if (guard1)
   {
      /* If: '<S7>/If1' incorporates:
       *  Constant: '<S12>/Constant'
       *  Constant: '<S7>/HW_Connection_False1'
       *  Constant: '<S7>/HW_Connection_False3'
       *  Inport: '<S10>/In1'
       *  Inport: '<S11>/In1'
       *  RelationalOperator: '<S12>/Compare'
       */
      if (((uint32_T)rtb_y_d) == No_Trailer)
      {
         /* Outputs for IfAction SubSystem: '<S7>/If Action Subsystem3' incorporates:
          *  ActionPort: '<S10>/Action Port'
          */
         rtb_Merge2 = 0U;

         /* End of Outputs for SubSystem: '<S7>/If Action Subsystem3' */
      }
      else
      {
         /* Outputs for IfAction SubSystem: '<S7>/If Action Subsystem4' incorporates:
          *  ActionPort: '<S11>/Action Port'
          */
         rtb_Merge2 = 2U;

         /* End of Outputs for SubSystem: '<S7>/If Action Subsystem4' */
      }
   }

   /* End of MATLAB Function: '<S1>/MATLAB Function1' */

   /* MATLAB Function: '<S1>/MATLAB Function7' */
   switch (*rtu_VsVCAN_TrlrConnectionSts)
   {
      case 0:
         rtb_y = Not_Connected;
         break;

      case 1:
         rtb_y = Connected;
         break;

      case 2:
         rtb_y = Not_Used;
         break;

      case 3:
         rtb_y = SNA2;
         break;

      default:
         rtb_y = Not_Connected;
         break;
   }

   /* End of MATLAB Function: '<S1>/MATLAB Function7' */

   /* MATLAB Function: '<S1>/MATLAB Function8' */
   switch (*rtu_VsVCAN_ITBM_TrlrStat)
   {
      case 0:
         rtb_y_n = No_TRLR;
         break;

      case 1:
         rtb_y_n = TRLR_PRSNT;
         break;

      case 2:
         rtb_y_n = TRLR_DCONN;
         break;

      case 3:
         rtb_y_n = SNA1;
         break;

      default:
         rtb_y_n = No_TRLR;
         break;
   }

   /* End of MATLAB Function: '<S1>/MATLAB Function8' */

   /* DataTypeConversion: '<S8>/Data Type Conversion' incorporates:
    *  Constant: '<S14>/Constant'
    *  Constant: '<S17>/Constant'
    *  Logic: '<S8>/Logical Operator'
    *  Logic: '<S8>/Logical Operator3'
    *  Logic: '<S8>/Logical Operator4'
    *  Logic: '<S8>/Logical Operator5'
    *  RelationalOperator: '<S14>/Compare'
    *  RelationalOperator: '<S17>/Compare'
    */
   rtb_DataTypeConversion =
      (uint8_T)((((((uint32_T)rtb_y_n) == TRLR_PRSNT) && (*rtu_VsPROXI_CANNode95_ITBM_ITCM)) ||
                 (((*rtu_VsPROXI_CANNode95_ITBM_ITCM) || (*rtu_VsPROXI_CANNode63_TTM)) && (((uint32_T)rtb_y) == Connected))) ?
                   1 :
                   0);

   /* If: '<S6>/If' incorporates:
    *  Constant: '<S18>/Constant'
    *  Constant: '<S19>/Constant'
    *  Constant: '<S20>/Constant'
    *  Constant: '<S21>/Constant'
    *  Constant: '<S22>/Constant'
    *  Constant: '<S23>/Constant'
    *  Constant: '<S6>/Constant1'
    *  Constant: '<S6>/Constant2'
    *  Constant: '<S6>/Constant3'
    *  Constant: '<S6>/Constant4'
    *  Inport: '<S24>/In1'
    *  Inport: '<S25>/In1'
    *  Inport: '<S26>/In1'
    *  Inport: '<S27>/In1'
    *  Logic: '<S6>/AND'
    *  Logic: '<S6>/AND1'
    *  Logic: '<S6>/AND2'
    *  RelationalOperator: '<S18>/Compare'
    *  RelationalOperator: '<S19>/Compare'
    *  RelationalOperator: '<S20>/Compare'
    *  RelationalOperator: '<S21>/Compare'
    *  RelationalOperator: '<S22>/Compare'
    *  RelationalOperator: '<S23>/Compare'
    */
   if ((((int32_T)rtb_DataTypeConversion) == 1) && (((int32_T)rtb_Merge2) == 1))
   {
      /* Outputs for IfAction SubSystem: '<S6>/If Action Subsystem3' incorporates:
       *  ActionPort: '<S27>/Action Port'
       */
      *rty_VsVSE_TrlrDetectSts = Both_Connected;

      /* End of Outputs for SubSystem: '<S6>/If Action Subsystem3' */
   }
   else if ((((int32_T)rtb_DataTypeConversion) == 0) && (((int32_T)rtb_Merge2) == 1))
   {
      /* Outputs for IfAction SubSystem: '<S6>/If Action Subsystem2' incorporates:
       *  ActionPort: '<S26>/Action Port'
       */
      *rty_VsVSE_TrlrDetectSts = RADAR_Connected_Only;

      /* End of Outputs for SubSystem: '<S6>/If Action Subsystem2' */
   }
   else if ((((int32_T)rtb_DataTypeConversion) == 1) && (((int32_T)rtb_Merge2) != 1))
   {
      /* Outputs for IfAction SubSystem: '<S6>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S25>/Action Port'
       */
      *rty_VsVSE_TrlrDetectSts = HW_Connected_Only;

      /* End of Outputs for SubSystem: '<S6>/If Action Subsystem1' */
   }
   else
   {
      /* Outputs for IfAction SubSystem: '<S6>/If Action Subsystem' incorporates:
       *  ActionPort: '<S24>/Action Port'
       */
      *rty_VsVSE_TrlrDetectSts = Neither_Connected;

      /* End of Outputs for SubSystem: '<S6>/If Action Subsystem' */
   }

   /* End of If: '<S6>/If' */

   /* DataTypeConversion: '<S1>/Data Type Conversion2' */
   *rty_VeVSE_RadarDetectionSts = (((int32_T)(*rtu_VsTracker_RadarDetectionSts)) != 0);

   /* DataTypeConversion: '<S1>/Data Type Conversion3' */
   *rty_VsVSE_s_RadarDetectionTimer = (real32_T)(*rtu_VsTracker_RadarDetectionTimer);

   /* DataTypeConversion: '<S1>/Data Type Conversion1' */
   *rty_VsVSE_s_StationaryTimer = (real32_T)(*rtu_VsTracker_StationaryTimer);

   /* Inport: '<Root>/VeTracker_TrlrDetectConfLvl' */
   *rty_VeVSE_TrlrDetectStsConfLvl = *rtu_VeTracker_TrlrDetectConfLvl;

   /* Inport: '<Root>/VeTracker_TrlrLenConfLvl' */
   *rty_VeVSE_TrlrLenConfLvl = *rtu_VeTracker_TrlrLenConfLvl;

   /* Inport: '<Root>/VeTracker_TrlrWidthConfLvl' */
   *rty_VeVSE_TrlrWidthConfLvl = *rtu_VeTracker_TrlrWidthConfLvl;

   /* Inport: '<Root>/VsTracker_m_TrlrLen' */
   *rty_VsVSE_m_TrlrLen = *rtu_VsTracker_m_TrlrLen;

   /* Inport: '<Root>/VsTracker_m_TrlrWidth' */
   *rty_VsVSE_m_TrlrWidth = *rtu_VsTracker_m_TrlrWidth;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
