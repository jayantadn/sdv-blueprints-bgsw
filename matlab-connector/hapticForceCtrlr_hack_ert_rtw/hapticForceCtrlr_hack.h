/*
 * hapticForceCtrlr_hack.h
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

#ifndef hapticForceCtrlr_hack_h_
#define hapticForceCtrlr_hack_h_
#ifndef hapticForceCtrlr_hack_COMMON_INCLUDES_
#define hapticForceCtrlr_hack_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                              /* hapticForceCtrlr_hack_COMMON_INCLUDES_ */

#include "hapticForceCtrlr_hack_types.h"
#include <stddef.h>
#include <string.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* user code (top of header file) */
#include "da_connector.h"

/* Block signals (default storage) */
typedef struct {
  real_T CCaller;                      /* '<Root>/C Caller' */
} B_hapticForceCtrlr_hack_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Integrator_DSTATE;            /* '<S101>/Integrator' */
  real_T Filter_DSTATE;                /* '<S96>/Filter' */
  real_T Integrator_DSTATE_h;          /* '<S43>/Integrator' */
  real_T Filter_DSTATE_e;              /* '<S38>/Filter' */
  struct {
    void *LoggedData[4];
  } Scope_PWORK;                       /* '<Root>/Scope' */
} DW_hapticForceCtrlr_hack_T;

/* Parameters (default storage) */
struct P_hapticForceCtrlr_hack_T_ {
  real_T PID_Controller_2DOF_Motor_Right;
                              /* Mask Parameter: PID_Controller_2DOF_Motor_Right
                               * Referenced by: '<S94>/Derivative Gain'
                               */
  real_T PID_Controller_2DOF_Motor_Left_;
                              /* Mask Parameter: PID_Controller_2DOF_Motor_Left_
                               * Referenced by: '<S36>/Derivative Gain'
                               */
  real_T PID_Controller_2DOF_Motor_Lef_c;
                              /* Mask Parameter: PID_Controller_2DOF_Motor_Lef_c
                               * Referenced by: '<S40>/Integral Gain'
                               */
  real_T PID_Controller_2DOF_Motor_Rig_h;
                              /* Mask Parameter: PID_Controller_2DOF_Motor_Rig_h
                               * Referenced by: '<S98>/Integral Gain'
                               */
  real_T PID_Controller_2DOF_Motor_Rig_n;
                              /* Mask Parameter: PID_Controller_2DOF_Motor_Rig_n
                               * Referenced by: '<S96>/Filter'
                               */
  real_T PID_Controller_2DOF_Motor_Lef_l;
                              /* Mask Parameter: PID_Controller_2DOF_Motor_Lef_l
                               * Referenced by: '<S38>/Filter'
                               */
  real_T PID_Controller_2DOF_Motor_Rig_g;
                              /* Mask Parameter: PID_Controller_2DOF_Motor_Rig_g
                               * Referenced by: '<S101>/Integrator'
                               */
  real_T PID_Controller_2DOF_Motor_Lef_d;
                              /* Mask Parameter: PID_Controller_2DOF_Motor_Lef_d
                               * Referenced by: '<S43>/Integrator'
                               */
  real_T PID_Controller_2DOF_Motor_Rig_f;
                              /* Mask Parameter: PID_Controller_2DOF_Motor_Rig_f
                               * Referenced by:
                               *   '<S108>/Saturation'
                               *   '<S93>/DeadZone'
                               */
  real_T PID_Controller_2DOF_Motor_Lef_k;
                              /* Mask Parameter: PID_Controller_2DOF_Motor_Lef_k
                               * Referenced by:
                               *   '<S50>/Saturation'
                               *   '<S35>/DeadZone'
                               */
  real_T PID_Controller_2DOF_Motor_Rig_m;
                              /* Mask Parameter: PID_Controller_2DOF_Motor_Rig_m
                               * Referenced by: '<S104>/Filter Coefficient'
                               */
  real_T PID_Controller_2DOF_Motor_Lef_f;
                              /* Mask Parameter: PID_Controller_2DOF_Motor_Lef_f
                               * Referenced by: '<S46>/Filter Coefficient'
                               */
  real_T PID_Controller_2DOF_Motor_Ri_ff;
                              /* Mask Parameter: PID_Controller_2DOF_Motor_Ri_ff
                               * Referenced by:
                               *   '<S99>/Proportional Gain'
                               *   '<S105>/P Copy'
                               */
  real_T PID_Controller_2DOF_Motor_Lef_b;
                              /* Mask Parameter: PID_Controller_2DOF_Motor_Lef_b
                               * Referenced by:
                               *   '<S41>/Proportional Gain'
                               *   '<S47>/P Copy'
                               */
  real_T PID_Controller_2DOF_Motor_Rig_b;
                              /* Mask Parameter: PID_Controller_2DOF_Motor_Rig_b
                               * Referenced by:
                               *   '<S108>/Saturation'
                               *   '<S93>/DeadZone'
                               */
  real_T PID_Controller_2DOF_Motor_Le_lx;
                              /* Mask Parameter: PID_Controller_2DOF_Motor_Le_lx
                               * Referenced by:
                               *   '<S50>/Saturation'
                               *   '<S35>/DeadZone'
                               */
  real_T PID_Controller_2DOF_Motor_Rig_i;
                              /* Mask Parameter: PID_Controller_2DOF_Motor_Rig_i
                               * Referenced by: '<S116>/Setpoint Weighting (Proportional)'
                               */
  real_T PID_Controller_2DOF_Motor_Lef_i;
                              /* Mask Parameter: PID_Controller_2DOF_Motor_Lef_i
                               * Referenced by: '<S58>/Setpoint Weighting (Proportional)'
                               */
  real_T PID_Controller_2DOF_Motor_Ri_hu;
                              /* Mask Parameter: PID_Controller_2DOF_Motor_Ri_hu
                               * Referenced by: '<S117>/Setpoint Weighting (Derivative)'
                               */
  real_T PID_Controller_2DOF_Motor_Lef_e;
                              /* Mask Parameter: PID_Controller_2DOF_Motor_Lef_e
                               * Referenced by: '<S59>/Setpoint Weighting (Derivative)'
                               */
  real_T Gain1_Gain;                   /* Expression: -1
                                        * Referenced by: '<Root>/Gain1'
                                        */
  real_T Gain_Gain;                    /* Expression: -1
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S33>/Constant1'
                                        */
  real_T Constant1_Value_f;            /* Expression: 0
                                        * Referenced by: '<S91>/Constant1'
                                        */
  real_T Limiter_angle_setpoint_UpperSat;/* Expression: 1000.0
                                          * Referenced by: '<Root>/Limiter_angle_setpoint'
                                          */
  real_T Limiter_angle_setpoint_LowerSat;/* Expression: -1000.0
                                          * Referenced by: '<Root>/Limiter_angle_setpoint'
                                          */
  real_T Integrator_gainval;           /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S101>/Integrator'
                                        */
  real_T Filter_gainval;               /* Computed Parameter: Filter_gainval
                                        * Referenced by: '<S96>/Filter'
                                        */
  real_T Integrator_gainval_l;       /* Computed Parameter: Integrator_gainval_l
                                      * Referenced by: '<S43>/Integrator'
                                      */
  real_T Filter_gainval_d;             /* Computed Parameter: Filter_gainval_d
                                        * Referenced by: '<S38>/Filter'
                                        */
  real_T Clamping_zero_Value;          /* Expression: 0
                                        * Referenced by: '<S33>/Clamping_zero'
                                        */
  real_T Clamping_zero_Value_m;        /* Expression: 0
                                        * Referenced by: '<S91>/Clamping_zero'
                                        */
  real32_T torque_manual_Value;       /* Computed Parameter: torque_manual_Value
                                       * Referenced by: '<Root>/torque_manual'
                                       */
  real32_T Limiter_torque_right_UpperSat;
                            /* Computed Parameter: Limiter_torque_right_UpperSat
                             * Referenced by: '<Root>/Limiter_torque_right'
                             */
  real32_T Limiter_torque_right_LowerSat;
                            /* Computed Parameter: Limiter_torque_right_LowerSat
                             * Referenced by: '<Root>/Limiter_torque_right'
                             */
  real32_T Limiter_torque_left_UpperSat;
                             /* Computed Parameter: Limiter_torque_left_UpperSat
                              * Referenced by: '<Root>/Limiter_torque_left'
                              */
  real32_T Limiter_torque_left_LowerSat;
                             /* Computed Parameter: Limiter_torque_left_LowerSat
                              * Referenced by: '<Root>/Limiter_torque_left'
                              */
  boolean_T flag_enable_controller_Value;
                             /* Computed Parameter: flag_enable_controller_Value
                              * Referenced by: '<Root>/flag_enable_controller'
                              */
  int8_T Constant4_Value;              /* Computed Parameter: Constant4_Value
                                        * Referenced by: '<S33>/Constant4'
                                        */
  int8_T Constant5_Value;              /* Computed Parameter: Constant5_Value
                                        * Referenced by: '<S33>/Constant5'
                                        */
  int8_T Constant6_Value;              /* Computed Parameter: Constant6_Value
                                        * Referenced by: '<S33>/Constant6'
                                        */
  int8_T Constant7_Value;              /* Computed Parameter: Constant7_Value
                                        * Referenced by: '<S33>/Constant7'
                                        */
  int8_T Constant4_Value_e;            /* Computed Parameter: Constant4_Value_e
                                        * Referenced by: '<S91>/Constant4'
                                        */
  int8_T Constant5_Value_b;            /* Computed Parameter: Constant5_Value_b
                                        * Referenced by: '<S91>/Constant5'
                                        */
  int8_T Constant6_Value_h;            /* Computed Parameter: Constant6_Value_h
                                        * Referenced by: '<S91>/Constant6'
                                        */
  int8_T Constant7_Value_i;            /* Computed Parameter: Constant7_Value_i
                                        * Referenced by: '<S91>/Constant7'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_hapticForceCtrlr_hack_T {
  const char_T *errorStatus;
};

/* Block parameters (default storage) */
extern P_hapticForceCtrlr_hack_T hapticForceCtrlr_hack_P;

/* Block signals (default storage) */
extern B_hapticForceCtrlr_hack_T hapticForceCtrlr_hack_B;

/* Block states (default storage) */
extern DW_hapticForceCtrlr_hack_T hapticForceCtrlr_hack_DW;

/* Model entry point functions */
extern void hapticForceCtrlr_hack_initialize(void);
extern void hapticForceCtrlr_hack_step(void);
extern void hapticForceCtrlr_hack_terminate(void);

/* Real-time Model object */
extern RT_MODEL_hapticForceCtrlr_hac_T *const hapticForceCtrlr_hack_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S3>/Constant' : Unused code path elimination
 * Block '<S3>/Constant1' : Unused code path elimination
 * Block '<S4>/Constant' : Unused code path elimination
 * Block '<S4>/Constant1' : Unused code path elimination
 * Block '<Root>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<Root>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<Root>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<Root>/Data Type Conversion3' : Eliminate redundant data type conversion
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'hapticForceCtrlr_hack'
 * '<S1>'   : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Left'
 * '<S2>'   : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Right'
 * '<S3>'   : 'hapticForceCtrlr_hack/receive_angle_from_zone_left'
 * '<S4>'   : 'hapticForceCtrlr_hack/receive_angle_from_zone_right'
 * '<S5>'   : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Left/Anti-windup'
 * '<S6>'   : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Left/D Gain'
 * '<S7>'   : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Left/External Derivative'
 * '<S8>'   : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Left/Filter'
 * '<S9>'   : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Left/Filter ICs'
 * '<S10>'  : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Left/I Gain'
 * '<S11>'  : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Left/Ideal P Gain'
 * '<S12>'  : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Left/Ideal P Gain Fdbk'
 * '<S13>'  : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Left/Integrator'
 * '<S14>'  : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Left/Integrator ICs'
 * '<S15>'  : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Left/N Copy'
 * '<S16>'  : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Left/N Gain'
 * '<S17>'  : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Left/P Copy'
 * '<S18>'  : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Left/Parallel P Gain'
 * '<S19>'  : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Left/Reset Signal'
 * '<S20>'  : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Left/Saturation'
 * '<S21>'  : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Left/Saturation Fdbk'
 * '<S22>'  : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Left/Sum'
 * '<S23>'  : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Left/Sum Fdbk'
 * '<S24>'  : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Left/Tracking Mode'
 * '<S25>'  : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Left/Tracking Mode Sum'
 * '<S26>'  : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Left/Tsamp - Integral'
 * '<S27>'  : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Left/Tsamp - Ngain'
 * '<S28>'  : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Left/b Gain'
 * '<S29>'  : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Left/c Gain'
 * '<S30>'  : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Left/postSat Signal'
 * '<S31>'  : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Left/preInt Signal'
 * '<S32>'  : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Left/preSat Signal'
 * '<S33>'  : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Left/Anti-windup/Disc. Clamping Ideal'
 * '<S34>'  : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Left/Anti-windup/Disc. Clamping Ideal/Dead Zone'
 * '<S35>'  : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Left/Anti-windup/Disc. Clamping Ideal/Dead Zone/Enabled'
 * '<S36>'  : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Left/D Gain/Internal Parameters'
 * '<S37>'  : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Left/External Derivative/Error'
 * '<S38>'  : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Left/Filter/Disc. Forward Euler Filter'
 * '<S39>'  : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Left/Filter ICs/Internal IC - Filter'
 * '<S40>'  : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Left/I Gain/Internal Parameters'
 * '<S41>'  : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Left/Ideal P Gain/Internal Parameters'
 * '<S42>'  : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Left/Ideal P Gain Fdbk/Disabled'
 * '<S43>'  : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Left/Integrator/Discrete'
 * '<S44>'  : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Left/Integrator ICs/Internal IC'
 * '<S45>'  : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Left/N Copy/Disabled'
 * '<S46>'  : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Left/N Gain/Internal Parameters'
 * '<S47>'  : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Left/P Copy/Internal Parameters Ideal'
 * '<S48>'  : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Left/Parallel P Gain/Passthrough'
 * '<S49>'  : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Left/Reset Signal/Disabled'
 * '<S50>'  : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Left/Saturation/Enabled'
 * '<S51>'  : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Left/Saturation Fdbk/Disabled'
 * '<S52>'  : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Left/Sum/Sum_PID'
 * '<S53>'  : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Left/Sum Fdbk/Disabled'
 * '<S54>'  : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Left/Tracking Mode/Disabled'
 * '<S55>'  : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Left/Tracking Mode Sum/Passthrough'
 * '<S56>'  : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Left/Tsamp - Integral/TsSignalSpecification'
 * '<S57>'  : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Left/Tsamp - Ngain/Passthrough'
 * '<S58>'  : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Left/b Gain/Internal Parameters'
 * '<S59>'  : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Left/c Gain/Internal Parameters'
 * '<S60>'  : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Left/postSat Signal/Forward_Path'
 * '<S61>'  : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Left/preInt Signal/Internal PreInt'
 * '<S62>'  : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Left/preSat Signal/Forward_Path'
 * '<S63>'  : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Right/Anti-windup'
 * '<S64>'  : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Right/D Gain'
 * '<S65>'  : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Right/External Derivative'
 * '<S66>'  : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Right/Filter'
 * '<S67>'  : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Right/Filter ICs'
 * '<S68>'  : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Right/I Gain'
 * '<S69>'  : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Right/Ideal P Gain'
 * '<S70>'  : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Right/Ideal P Gain Fdbk'
 * '<S71>'  : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Right/Integrator'
 * '<S72>'  : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Right/Integrator ICs'
 * '<S73>'  : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Right/N Copy'
 * '<S74>'  : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Right/N Gain'
 * '<S75>'  : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Right/P Copy'
 * '<S76>'  : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Right/Parallel P Gain'
 * '<S77>'  : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Right/Reset Signal'
 * '<S78>'  : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Right/Saturation'
 * '<S79>'  : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Right/Saturation Fdbk'
 * '<S80>'  : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Right/Sum'
 * '<S81>'  : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Right/Sum Fdbk'
 * '<S82>'  : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Right/Tracking Mode'
 * '<S83>'  : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Right/Tracking Mode Sum'
 * '<S84>'  : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Right/Tsamp - Integral'
 * '<S85>'  : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Right/Tsamp - Ngain'
 * '<S86>'  : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Right/b Gain'
 * '<S87>'  : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Right/c Gain'
 * '<S88>'  : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Right/postSat Signal'
 * '<S89>'  : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Right/preInt Signal'
 * '<S90>'  : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Right/preSat Signal'
 * '<S91>'  : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Right/Anti-windup/Disc. Clamping Ideal'
 * '<S92>'  : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Right/Anti-windup/Disc. Clamping Ideal/Dead Zone'
 * '<S93>'  : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Right/Anti-windup/Disc. Clamping Ideal/Dead Zone/Enabled'
 * '<S94>'  : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Right/D Gain/Internal Parameters'
 * '<S95>'  : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Right/External Derivative/Error'
 * '<S96>'  : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Right/Filter/Disc. Forward Euler Filter'
 * '<S97>'  : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Right/Filter ICs/Internal IC - Filter'
 * '<S98>'  : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Right/I Gain/Internal Parameters'
 * '<S99>'  : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Right/Ideal P Gain/Internal Parameters'
 * '<S100>' : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Right/Ideal P Gain Fdbk/Disabled'
 * '<S101>' : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Right/Integrator/Discrete'
 * '<S102>' : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Right/Integrator ICs/Internal IC'
 * '<S103>' : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Right/N Copy/Disabled'
 * '<S104>' : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Right/N Gain/Internal Parameters'
 * '<S105>' : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Right/P Copy/Internal Parameters Ideal'
 * '<S106>' : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Right/Parallel P Gain/Passthrough'
 * '<S107>' : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Right/Reset Signal/Disabled'
 * '<S108>' : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Right/Saturation/Enabled'
 * '<S109>' : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Right/Saturation Fdbk/Disabled'
 * '<S110>' : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Right/Sum/Sum_PID'
 * '<S111>' : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Right/Sum Fdbk/Disabled'
 * '<S112>' : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Right/Tracking Mode/Disabled'
 * '<S113>' : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Right/Tracking Mode Sum/Passthrough'
 * '<S114>' : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Right/Tsamp - Integral/TsSignalSpecification'
 * '<S115>' : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Right/Tsamp - Ngain/Passthrough'
 * '<S116>' : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Right/b Gain/Internal Parameters'
 * '<S117>' : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Right/c Gain/Internal Parameters'
 * '<S118>' : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Right/postSat Signal/Forward_Path'
 * '<S119>' : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Right/preInt Signal/Internal PreInt'
 * '<S120>' : 'hapticForceCtrlr_hack/PID_Controller_2DOF_Motor_Right/preSat Signal/Forward_Path'
 */
#endif                                 /* hapticForceCtrlr_hack_h_ */
