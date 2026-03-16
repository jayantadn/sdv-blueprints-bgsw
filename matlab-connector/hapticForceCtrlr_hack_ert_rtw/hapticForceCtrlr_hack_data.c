/*
 * hapticForceCtrlr_hack_data.c
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

/* Block parameters (default storage) */
P_hapticForceCtrlr_hack_T hapticForceCtrlr_hack_P = {
  /* Mask Parameter: PID_Controller_2DOF_Motor_Right
   * Referenced by: '<S94>/Derivative Gain'
   */
  0.0001,

  /* Mask Parameter: PID_Controller_2DOF_Motor_Left_
   * Referenced by: '<S36>/Derivative Gain'
   */
  0.0001,

  /* Mask Parameter: PID_Controller_2DOF_Motor_Lef_c
   * Referenced by: '<S40>/Integral Gain'
   */
  0.04,

  /* Mask Parameter: PID_Controller_2DOF_Motor_Rig_h
   * Referenced by: '<S98>/Integral Gain'
   */
  0.04,

  /* Mask Parameter: PID_Controller_2DOF_Motor_Rig_n
   * Referenced by: '<S96>/Filter'
   */
  0.0,

  /* Mask Parameter: PID_Controller_2DOF_Motor_Lef_l
   * Referenced by: '<S38>/Filter'
   */
  0.0,

  /* Mask Parameter: PID_Controller_2DOF_Motor_Rig_g
   * Referenced by: '<S101>/Integrator'
   */
  0.0,

  /* Mask Parameter: PID_Controller_2DOF_Motor_Lef_d
   * Referenced by: '<S43>/Integrator'
   */
  0.0,

  /* Mask Parameter: PID_Controller_2DOF_Motor_Rig_f
   * Referenced by:
   *   '<S108>/Saturation'
   *   '<S93>/DeadZone'
   */
  -10.0,

  /* Mask Parameter: PID_Controller_2DOF_Motor_Lef_k
   * Referenced by:
   *   '<S50>/Saturation'
   *   '<S35>/DeadZone'
   */
  -10.0,

  /* Mask Parameter: PID_Controller_2DOF_Motor_Rig_m
   * Referenced by: '<S104>/Filter Coefficient'
   */
  10.0,

  /* Mask Parameter: PID_Controller_2DOF_Motor_Lef_f
   * Referenced by: '<S46>/Filter Coefficient'
   */
  10.0,

  /* Mask Parameter: PID_Controller_2DOF_Motor_Ri_ff
   * Referenced by:
   *   '<S99>/Proportional Gain'
   *   '<S105>/P Copy'
   */
  0.03,

  /* Mask Parameter: PID_Controller_2DOF_Motor_Lef_b
   * Referenced by:
   *   '<S41>/Proportional Gain'
   *   '<S47>/P Copy'
   */
  0.03,

  /* Mask Parameter: PID_Controller_2DOF_Motor_Rig_b
   * Referenced by:
   *   '<S108>/Saturation'
   *   '<S93>/DeadZone'
   */
  10.0,

  /* Mask Parameter: PID_Controller_2DOF_Motor_Le_lx
   * Referenced by:
   *   '<S50>/Saturation'
   *   '<S35>/DeadZone'
   */
  10.0,

  /* Mask Parameter: PID_Controller_2DOF_Motor_Rig_i
   * Referenced by: '<S116>/Setpoint Weighting (Proportional)'
   */
  1.0,

  /* Mask Parameter: PID_Controller_2DOF_Motor_Lef_i
   * Referenced by: '<S58>/Setpoint Weighting (Proportional)'
   */
  1.0,

  /* Mask Parameter: PID_Controller_2DOF_Motor_Ri_hu
   * Referenced by: '<S117>/Setpoint Weighting (Derivative)'
   */
  0.8,

  /* Mask Parameter: PID_Controller_2DOF_Motor_Lef_e
   * Referenced by: '<S59>/Setpoint Weighting (Derivative)'
   */
  0.8,

  /* Expression: -1
   * Referenced by: '<Root>/Gain1'
   */
  -1.0,

  /* Expression: -1
   * Referenced by: '<Root>/Gain'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<S33>/Constant1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S91>/Constant1'
   */
  0.0,

  /* Expression: 1000.0
   * Referenced by: '<Root>/Limiter_angle_setpoint'
   */
  1000.0,

  /* Expression: -1000.0
   * Referenced by: '<Root>/Limiter_angle_setpoint'
   */
  -1000.0,

  /* Computed Parameter: Integrator_gainval
   * Referenced by: '<S101>/Integrator'
   */
  0.1,

  /* Computed Parameter: Filter_gainval
   * Referenced by: '<S96>/Filter'
   */
  0.1,

  /* Computed Parameter: Integrator_gainval_l
   * Referenced by: '<S43>/Integrator'
   */
  0.1,

  /* Computed Parameter: Filter_gainval_d
   * Referenced by: '<S38>/Filter'
   */
  0.1,

  /* Expression: 0
   * Referenced by: '<S33>/Clamping_zero'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S91>/Clamping_zero'
   */
  0.0,

  /* Computed Parameter: torque_manual_Value
   * Referenced by: '<Root>/torque_manual'
   */
  0.0F,

  /* Computed Parameter: Limiter_torque_right_UpperSat
   * Referenced by: '<Root>/Limiter_torque_right'
   */
  10.0F,

  /* Computed Parameter: Limiter_torque_right_LowerSat
   * Referenced by: '<Root>/Limiter_torque_right'
   */
  -10.0F,

  /* Computed Parameter: Limiter_torque_left_UpperSat
   * Referenced by: '<Root>/Limiter_torque_left'
   */
  10.0F,

  /* Computed Parameter: Limiter_torque_left_LowerSat
   * Referenced by: '<Root>/Limiter_torque_left'
   */
  -10.0F,

  /* Computed Parameter: flag_enable_controller_Value
   * Referenced by: '<Root>/flag_enable_controller'
   */
  true,

  /* Computed Parameter: Constant4_Value
   * Referenced by: '<S33>/Constant4'
   */
  1,

  /* Computed Parameter: Constant5_Value
   * Referenced by: '<S33>/Constant5'
   */
  -1,

  /* Computed Parameter: Constant6_Value
   * Referenced by: '<S33>/Constant6'
   */
  1,

  /* Computed Parameter: Constant7_Value
   * Referenced by: '<S33>/Constant7'
   */
  -1,

  /* Computed Parameter: Constant4_Value_e
   * Referenced by: '<S91>/Constant4'
   */
  1,

  /* Computed Parameter: Constant5_Value_b
   * Referenced by: '<S91>/Constant5'
   */
  -1,

  /* Computed Parameter: Constant6_Value_h
   * Referenced by: '<S91>/Constant6'
   */
  1,

  /* Computed Parameter: Constant7_Value_i
   * Referenced by: '<S91>/Constant7'
   */
  -1
};
