/*
 * hapticForceCtrlr_hack.c
 *
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * Code generation for model "hapticForceCtrlr_hack".
 *
 * Model version              : 1.15
 * Simulink Coder version : 25.2 (R2025b) 28-Jul-2025
 * C source code generated on : Mon Mar 16 17:03:19 2026
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex-A (64-bit)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "hapticForceCtrlr_hack.h"
#include "rtwtypes.h"
#include <string.h>

/* Block signals (default storage) */
B_hapticForceCtrlr_hack_T hapticForceCtrlr_hack_B;

/* Block states (default storage) */
DW_hapticForceCtrlr_hack_T hapticForceCtrlr_hack_DW;

/* Real-time model */
static RT_MODEL_hapticForceCtrlr_hac_T hapticForceCtrlr_hack_M_;
RT_MODEL_hapticForceCtrlr_hac_T *const hapticForceCtrlr_hack_M =
  &hapticForceCtrlr_hack_M_;

/* Model step function */
void hapticForceCtrlr_hack_step(void)
{
  real_T rtb_DeadZone;
  real_T rtb_DeadZone_h;
  real_T rtb_FilterCoefficient;
  real_T rtb_FilterCoefficient_n;
  real_T rtb_IntegralGain;
  real_T rtb_IntegralGain_m;
  real32_T rtb_setpoint_torque_left;
  real32_T rtb_setpoint_torque_right;
  int8_T tmp;
  int8_T tmp_0;
  boolean_T rtb_AND1;
  boolean_T rtb_AND2;
  boolean_T rtb_Equal1;
  boolean_T rtb_RelationalOperator1;

  /* CCaller: '<Root>/C Caller' */
  hapticForceCtrlr_hack_B.CCaller = da_connector();

  /* Saturate: '<Root>/Limiter_angle_setpoint' */
  if (hapticForceCtrlr_hack_B.CCaller >
      hapticForceCtrlr_hack_P.Limiter_angle_setpoint_UpperSat) {
    rtb_IntegralGain_m = hapticForceCtrlr_hack_P.Limiter_angle_setpoint_UpperSat;
  } else if (hapticForceCtrlr_hack_B.CCaller <
             hapticForceCtrlr_hack_P.Limiter_angle_setpoint_LowerSat) {
    rtb_IntegralGain_m = hapticForceCtrlr_hack_P.Limiter_angle_setpoint_LowerSat;
  } else {
    rtb_IntegralGain_m = hapticForceCtrlr_hack_B.CCaller;
  }

  /* End of Saturate: '<Root>/Limiter_angle_setpoint' */

  /* Gain: '<S104>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S96>/Filter'
   *  Gain: '<S117>/Setpoint Weighting (Derivative)'
   *  Gain: '<S94>/Derivative Gain'
   *  Sum: '<S96>/SumD'
   */
  rtb_FilterCoefficient =
    (hapticForceCtrlr_hack_P.PID_Controller_2DOF_Motor_Ri_hu *
     rtb_IntegralGain_m *
     hapticForceCtrlr_hack_P.PID_Controller_2DOF_Motor_Right -
     hapticForceCtrlr_hack_DW.Filter_DSTATE) *
    hapticForceCtrlr_hack_P.PID_Controller_2DOF_Motor_Rig_m;

  /* Gain: '<S99>/Proportional Gain' incorporates:
   *  DiscreteIntegrator: '<S101>/Integrator'
   *  Gain: '<S116>/Setpoint Weighting (Proportional)'
   *  Sum: '<S110>/Sum'
   */
  rtb_DeadZone = ((hapticForceCtrlr_hack_P.PID_Controller_2DOF_Motor_Rig_i *
                   rtb_IntegralGain_m +
                   hapticForceCtrlr_hack_DW.Integrator_DSTATE) +
                  rtb_FilterCoefficient) *
    hapticForceCtrlr_hack_P.PID_Controller_2DOF_Motor_Ri_ff;

  /* Switch: '<Root>/Switch' incorporates:
   *  Constant: '<Root>/flag_enable_controller'
   *  Constant: '<Root>/torque_manual'
   *  Gain: '<Root>/Gain'
   *  Saturate: '<S108>/Saturation'
   */
  if (hapticForceCtrlr_hack_P.flag_enable_controller_Value) {
    /* Saturate: '<S108>/Saturation' */
    if (rtb_DeadZone > hapticForceCtrlr_hack_P.PID_Controller_2DOF_Motor_Rig_b)
    {
      rtb_IntegralGain = hapticForceCtrlr_hack_P.PID_Controller_2DOF_Motor_Rig_b;
    } else if (rtb_DeadZone <
               hapticForceCtrlr_hack_P.PID_Controller_2DOF_Motor_Rig_f) {
      rtb_IntegralGain = hapticForceCtrlr_hack_P.PID_Controller_2DOF_Motor_Rig_f;
    } else {
      rtb_IntegralGain = rtb_DeadZone;
    }

    rtb_setpoint_torque_right = (real32_T)(hapticForceCtrlr_hack_P.Gain_Gain *
      rtb_IntegralGain);
  } else {
    rtb_setpoint_torque_right = hapticForceCtrlr_hack_P.torque_manual_Value;
  }

  /* End of Switch: '<Root>/Switch' */

  /* Saturate: '<Root>/Limiter_torque_right' */
  if (rtb_setpoint_torque_right >
      hapticForceCtrlr_hack_P.Limiter_torque_right_UpperSat) {
    rtb_setpoint_torque_right =
      hapticForceCtrlr_hack_P.Limiter_torque_right_UpperSat;
  } else if (rtb_setpoint_torque_right <
             hapticForceCtrlr_hack_P.Limiter_torque_right_LowerSat) {
    rtb_setpoint_torque_right =
      hapticForceCtrlr_hack_P.Limiter_torque_right_LowerSat;
  }

  /* End of Saturate: '<Root>/Limiter_torque_right' */

  /* Gain: '<S46>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S38>/Filter'
   *  Gain: '<S36>/Derivative Gain'
   *  Gain: '<S59>/Setpoint Weighting (Derivative)'
   *  Sum: '<S38>/SumD'
   */
  rtb_FilterCoefficient_n =
    (hapticForceCtrlr_hack_P.PID_Controller_2DOF_Motor_Lef_e * 0.0 *
     hapticForceCtrlr_hack_P.PID_Controller_2DOF_Motor_Left_ -
     hapticForceCtrlr_hack_DW.Filter_DSTATE_e) *
    hapticForceCtrlr_hack_P.PID_Controller_2DOF_Motor_Lef_f;

  /* Gain: '<S41>/Proportional Gain' incorporates:
   *  DiscreteIntegrator: '<S43>/Integrator'
   *  Gain: '<S58>/Setpoint Weighting (Proportional)'
   *  Sum: '<S52>/Sum'
   */
  rtb_DeadZone_h = ((hapticForceCtrlr_hack_P.PID_Controller_2DOF_Motor_Lef_i *
                     0.0 + hapticForceCtrlr_hack_DW.Integrator_DSTATE_h) +
                    rtb_FilterCoefficient_n) *
    hapticForceCtrlr_hack_P.PID_Controller_2DOF_Motor_Lef_b;

  /* Switch: '<Root>/Switch1' incorporates:
   *  Constant: '<Root>/flag_enable_controller'
   *  Constant: '<Root>/torque_manual'
   *  Gain: '<Root>/Gain1'
   *  Saturate: '<S50>/Saturation'
   */
  if (hapticForceCtrlr_hack_P.flag_enable_controller_Value) {
    /* Saturate: '<S50>/Saturation' */
    if (rtb_DeadZone_h > hapticForceCtrlr_hack_P.PID_Controller_2DOF_Motor_Le_lx)
    {
      rtb_IntegralGain = hapticForceCtrlr_hack_P.PID_Controller_2DOF_Motor_Le_lx;
    } else if (rtb_DeadZone_h <
               hapticForceCtrlr_hack_P.PID_Controller_2DOF_Motor_Lef_k) {
      rtb_IntegralGain = hapticForceCtrlr_hack_P.PID_Controller_2DOF_Motor_Lef_k;
    } else {
      rtb_IntegralGain = rtb_DeadZone_h;
    }

    rtb_setpoint_torque_left = (real32_T)(hapticForceCtrlr_hack_P.Gain1_Gain *
      rtb_IntegralGain);
  } else {
    rtb_setpoint_torque_left = hapticForceCtrlr_hack_P.torque_manual_Value;
  }

  /* End of Switch: '<Root>/Switch1' */

  /* Saturate: '<Root>/Limiter_torque_left' */
  if (rtb_setpoint_torque_left >
      hapticForceCtrlr_hack_P.Limiter_torque_left_UpperSat) {
    rtb_setpoint_torque_left =
      hapticForceCtrlr_hack_P.Limiter_torque_left_UpperSat;
  } else if (rtb_setpoint_torque_left <
             hapticForceCtrlr_hack_P.Limiter_torque_left_LowerSat) {
    rtb_setpoint_torque_left =
      hapticForceCtrlr_hack_P.Limiter_torque_left_LowerSat;
  }

  /* End of Saturate: '<Root>/Limiter_torque_left' */
  /* DeadZone: '<S35>/DeadZone' */
  if (rtb_DeadZone_h > hapticForceCtrlr_hack_P.PID_Controller_2DOF_Motor_Le_lx)
  {
    rtb_DeadZone_h -= hapticForceCtrlr_hack_P.PID_Controller_2DOF_Motor_Le_lx;
  } else if (rtb_DeadZone_h >=
             hapticForceCtrlr_hack_P.PID_Controller_2DOF_Motor_Lef_k) {
    rtb_DeadZone_h = 0.0;
  } else {
    rtb_DeadZone_h -= hapticForceCtrlr_hack_P.PID_Controller_2DOF_Motor_Lef_k;
  }

  /* End of DeadZone: '<S35>/DeadZone' */

  /* Gain: '<S40>/Integral Gain' incorporates:
   *  Sum: '<S1>/Sum2'
   */
  rtb_IntegralGain = hapticForceCtrlr_hack_P.PID_Controller_2DOF_Motor_Lef_c *
    0.0;

  /* Switch: '<S33>/Switch3' incorporates:
   *  Constant: '<S33>/Clamping_zero'
   *  Constant: '<S33>/Constant6'
   *  Constant: '<S33>/Constant7'
   *  RelationalOperator: '<S33>/fix for DT propagation issue'
   */
  if (rtb_DeadZone_h > hapticForceCtrlr_hack_P.Clamping_zero_Value) {
    tmp = hapticForceCtrlr_hack_P.Constant6_Value;
  } else {
    tmp = hapticForceCtrlr_hack_P.Constant7_Value;
  }

  /* Switch: '<S33>/Switch2' incorporates:
   *  Constant: '<S33>/Clamping_zero'
   *  Constant: '<S33>/Constant4'
   *  Constant: '<S33>/Constant5'
   *  RelationalOperator: '<S33>/fix for DT propagation issue1'
   */
  if (rtb_IntegralGain > hapticForceCtrlr_hack_P.Clamping_zero_Value) {
    tmp_0 = hapticForceCtrlr_hack_P.Constant4_Value;
  } else {
    tmp_0 = hapticForceCtrlr_hack_P.Constant5_Value;
  }

  /* RelationalOperator: '<S33>/Equal1' incorporates:
   *  Switch: '<S33>/Switch2'
   *  Switch: '<S33>/Switch3'
   */
  rtb_RelationalOperator1 = (tmp == tmp_0);

  /* RelationalOperator: '<S33>/Relational Operator1' incorporates:
   *  Constant: '<S33>/Clamping_zero'
   *  Constant: '<S47>/P Copy'
   */
  rtb_Equal1 = (hapticForceCtrlr_hack_P.PID_Controller_2DOF_Motor_Lef_b >
                hapticForceCtrlr_hack_P.Clamping_zero_Value);

  /* Logic: '<S33>/AND1' */
  rtb_AND1 = (rtb_RelationalOperator1 && rtb_Equal1);

  /* Logic: '<S33>/AND2' incorporates:
   *  Logic: '<S33>/NOT1'
   *  Logic: '<S33>/NOT2'
   */
  rtb_AND2 = ((!rtb_RelationalOperator1) && (!rtb_Equal1));

  /* DeadZone: '<S93>/DeadZone' */
  if (rtb_DeadZone > hapticForceCtrlr_hack_P.PID_Controller_2DOF_Motor_Rig_b) {
    rtb_DeadZone -= hapticForceCtrlr_hack_P.PID_Controller_2DOF_Motor_Rig_b;
  } else if (rtb_DeadZone >=
             hapticForceCtrlr_hack_P.PID_Controller_2DOF_Motor_Rig_f) {
    rtb_DeadZone = 0.0;
  } else {
    rtb_DeadZone -= hapticForceCtrlr_hack_P.PID_Controller_2DOF_Motor_Rig_f;
  }

  /* End of DeadZone: '<S93>/DeadZone' */

  /* Gain: '<S98>/Integral Gain' incorporates:
   *  Sum: '<S2>/Sum2'
   */
  rtb_IntegralGain_m *= hapticForceCtrlr_hack_P.PID_Controller_2DOF_Motor_Rig_h;

  /* Switch: '<S91>/Switch3' incorporates:
   *  Constant: '<S91>/Clamping_zero'
   *  Constant: '<S91>/Constant6'
   *  Constant: '<S91>/Constant7'
   *  RelationalOperator: '<S91>/fix for DT propagation issue'
   */
  if (rtb_DeadZone > hapticForceCtrlr_hack_P.Clamping_zero_Value_m) {
    tmp = hapticForceCtrlr_hack_P.Constant6_Value_h;
  } else {
    tmp = hapticForceCtrlr_hack_P.Constant7_Value_i;
  }

  /* Switch: '<S91>/Switch2' incorporates:
   *  Constant: '<S91>/Clamping_zero'
   *  Constant: '<S91>/Constant4'
   *  Constant: '<S91>/Constant5'
   *  RelationalOperator: '<S91>/fix for DT propagation issue1'
   */
  if (rtb_IntegralGain_m > hapticForceCtrlr_hack_P.Clamping_zero_Value_m) {
    tmp_0 = hapticForceCtrlr_hack_P.Constant4_Value_e;
  } else {
    tmp_0 = hapticForceCtrlr_hack_P.Constant5_Value_b;
  }

  /* RelationalOperator: '<S91>/Equal1' incorporates:
   *  Switch: '<S91>/Switch2'
   *  Switch: '<S91>/Switch3'
   */
  rtb_Equal1 = (tmp == tmp_0);

  /* RelationalOperator: '<S91>/Relational Operator1' incorporates:
   *  Constant: '<S105>/P Copy'
   *  Constant: '<S91>/Clamping_zero'
   */
  rtb_RelationalOperator1 =
    (hapticForceCtrlr_hack_P.PID_Controller_2DOF_Motor_Ri_ff >
     hapticForceCtrlr_hack_P.Clamping_zero_Value_m);

  /* Switch: '<S91>/Switch' incorporates:
   *  Constant: '<S91>/Clamping_zero'
   *  Constant: '<S91>/Constant1'
   *  Logic: '<S91>/AND1'
   *  Logic: '<S91>/AND2'
   *  Logic: '<S91>/AND3'
   *  Logic: '<S91>/NOT1'
   *  Logic: '<S91>/NOT2'
   *  Logic: '<S91>/OR1'
   *  RelationalOperator: '<S91>/Relational Operator'
   */
  if ((hapticForceCtrlr_hack_P.Clamping_zero_Value_m != rtb_DeadZone) &&
      ((rtb_Equal1 && rtb_RelationalOperator1) || ((!rtb_Equal1) &&
        (!rtb_RelationalOperator1)))) {
    rtb_IntegralGain_m = hapticForceCtrlr_hack_P.Constant1_Value_f;
  }

  /* Update for DiscreteIntegrator: '<S101>/Integrator' incorporates:
   *  Switch: '<S91>/Switch'
   */
  hapticForceCtrlr_hack_DW.Integrator_DSTATE +=
    hapticForceCtrlr_hack_P.Integrator_gainval * rtb_IntegralGain_m;

  /* Update for DiscreteIntegrator: '<S96>/Filter' */
  hapticForceCtrlr_hack_DW.Filter_DSTATE +=
    hapticForceCtrlr_hack_P.Filter_gainval * rtb_FilterCoefficient;

  /* Switch: '<S33>/Switch' incorporates:
   *  Constant: '<S33>/Clamping_zero'
   *  Constant: '<S33>/Constant1'
   *  Logic: '<S33>/AND3'
   *  Logic: '<S33>/OR1'
   *  RelationalOperator: '<S33>/Relational Operator'
   */
  if ((hapticForceCtrlr_hack_P.Clamping_zero_Value != rtb_DeadZone_h) &&
      (rtb_AND1 || rtb_AND2)) {
    rtb_IntegralGain = hapticForceCtrlr_hack_P.Constant1_Value;
  }

  /* Update for DiscreteIntegrator: '<S43>/Integrator' incorporates:
   *  Switch: '<S33>/Switch'
   */
  hapticForceCtrlr_hack_DW.Integrator_DSTATE_h +=
    hapticForceCtrlr_hack_P.Integrator_gainval_l * rtb_IntegralGain;

  /* Update for DiscreteIntegrator: '<S38>/Filter' */
  hapticForceCtrlr_hack_DW.Filter_DSTATE_e +=
    hapticForceCtrlr_hack_P.Filter_gainval_d * rtb_FilterCoefficient_n;
}

/* Model initialize function */
void hapticForceCtrlr_hack_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(hapticForceCtrlr_hack_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &hapticForceCtrlr_hack_B), 0,
                sizeof(B_hapticForceCtrlr_hack_T));

  /* states (dwork) */
  (void) memset((void *)&hapticForceCtrlr_hack_DW, 0,
                sizeof(DW_hapticForceCtrlr_hack_T));

  /* InitializeConditions for DiscreteIntegrator: '<S101>/Integrator' */
  hapticForceCtrlr_hack_DW.Integrator_DSTATE =
    hapticForceCtrlr_hack_P.PID_Controller_2DOF_Motor_Rig_g;

  /* InitializeConditions for DiscreteIntegrator: '<S96>/Filter' */
  hapticForceCtrlr_hack_DW.Filter_DSTATE =
    hapticForceCtrlr_hack_P.PID_Controller_2DOF_Motor_Rig_n;

  /* InitializeConditions for DiscreteIntegrator: '<S43>/Integrator' */
  hapticForceCtrlr_hack_DW.Integrator_DSTATE_h =
    hapticForceCtrlr_hack_P.PID_Controller_2DOF_Motor_Lef_d;

  /* InitializeConditions for DiscreteIntegrator: '<S38>/Filter' */
  hapticForceCtrlr_hack_DW.Filter_DSTATE_e =
    hapticForceCtrlr_hack_P.PID_Controller_2DOF_Motor_Lef_l;
}

/* Model terminate function */
void hapticForceCtrlr_hack_terminate(void)
{
  /* (no terminate code required) */
}
