/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: On.h
 *
 * Code generated for Simulink model 'On'.
 *
 * Model version                  : 1.25
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Nov 28 13:42:30 2018
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_On_h_
#define RTW_HEADER_On_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef On_COMMON_INCLUDES_
# define On_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* On_COMMON_INCLUDES_ */

#include "On_types.h"
#include "MW_target_hardware_resources.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  real_T dv0[12];
  real_T Diff_p[9];                    /* '<S12>/Diff' */
  real_T A_LN[9];                      /* '<S14>/MATLAB Function' */
  real_T TSamp[9];                     /* '<S12>/TSamp' */
  real_T rtb_Product_n_tmp[9];
  real_T dv1[9];
  real_T Gain2[4];                     /* '<S27>/Gain2' */
  real_T o_1[3];
  real_T VectorConcatenate1[3];        /* '<S27>/Vector Concatenate1' */
  real_T R[3];
  real_T R_m;
  real_T qnorm;
  real_T scale;
  real_T t;
  real_T y_a;                          /* '<S2>/MATLAB Function1' */
  real_T Saturation1;                  /* '<S26>/Saturation1' */
  real_T o_3_idx_0;
  real_T o_3_idx_2;
  real_T c_tmp;
} B_On_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T DiscreteTimeIntegrator_DSTATE[9];/* '<S11>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator1_DSTATE[3];/* '<S15>/Discrete-Time Integrator1' */
  real_T DiscreteTimeIntegrator_DSTATE_e[3];/* '<S15>/Discrete-Time Integrator' */
  real_T UD_DSTATE[9];                 /* '<S12>/UD' */
  real_T DiscreteTimeIntegrator_DSTATE_k[4];/* '<S24>/Discrete-Time Integrator' */
  real_T UD_DSTATE_a[3];               /* '<S6>/UD' */
  uint8_T DiscreteTimeIntegrator1_IC_LOAD;/* '<S15>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator_IC_LOADI;/* '<S15>/Discrete-Time Integrator' */
} DW_On_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T _bn[3];                       /* '<Root>/Gyroscope Measure' */
  real_T MagnetometerMeasure[3];       /* '<Root>/Magnetometer Measure' */
} ExtU_On_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T CommandedRWTorque[3];         /* '<Root>/Commanded RW Torque' */
  real_T CommandedDipoleMoment[3];     /* '<Root>/Commanded Dipole Moment' */
} ExtY_On_T;

/* Parameters (default storage) */
struct P_On_T_ {
  real_T A_BN_0[9];                    /* Variable: A_BN_0
                                        * Referenced by: '<S11>/Discrete-Time Integrator'
                                        */
  real_T Q_C[16];                      /* Variable: Q_C
                                        * Referenced by: '<S27>/Gain2'
                                        */
  real_T k_bdot;                       /* Variable: k_bdot
                                        * Referenced by: '<S2>/Gain1'
                                        */
  real_T k_d;                          /* Variable: k_d
                                        * Referenced by: '<S27>/Gain'
                                        */
  real_T k_p;                          /* Variable: k_p
                                        * Referenced by: '<S27>/Gain1'
                                        */
  real_T m_max;                        /* Variable: m_max
                                        * Referenced by:
                                        *   '<S26>/Saturation'
                                        *   '<S26>/Saturation1'
                                        */
  real_T mu;                           /* Variable: mu
                                        * Referenced by: '<S10>/Planetary Constant'
                                        */
  real_T DiscreteDerivative_ICPrevScaled;/* Mask Parameter: DiscreteDerivative_ICPrevScaled
                                          * Referenced by: '<S12>/UD'
                                          */
  real_T DiscreteDerivative1_ICPrevScale;/* Mask Parameter: DiscreteDerivative1_ICPrevScale
                                          * Referenced by: '<S6>/UD'
                                          */
  real_T Constant1_Value[3];           /* Expression: [0;0;0]
                                        * Referenced by: '<S1>/Constant1'
                                        */
  real_T DiscreteTimeIntegrator_gainval;/* Computed Parameter: DiscreteTimeIntegrator_gainval
                                         * Referenced by: '<S11>/Discrete-Time Integrator'
                                         */
  real_T Gain_Gain;                    /* Expression: -1
                                        * Referenced by: '<S11>/Gain'
                                        */
  real_T InitialConditionsKEP_Value[6];/* Expression: [a, e, i, OMG, omg, theta]
                                        * Referenced by: '<S10>/Initial Conditions (KEP)'
                                        */
  real_T DiscreteTimeIntegrator1_gainval;/* Computed Parameter: DiscreteTimeIntegrator1_gainval
                                          * Referenced by: '<S15>/Discrete-Time Integrator1'
                                          */
  real_T DiscreteTimeIntegrator_gainva_l;/* Computed Parameter: DiscreteTimeIntegrator_gainva_l
                                          * Referenced by: '<S15>/Discrete-Time Integrator'
                                          */
  real_T Gain_Gain_m;                  /* Expression: -1
                                        * Referenced by: '<S8>/Gain'
                                        */
  real_T Constant_Value[4];            /* Expression: [0;0;0;1]
                                        * Referenced by: '<S11>/Constant'
                                        */
  real_T DiscreteTimeIntegrator_gainva_c;/* Computed Parameter: DiscreteTimeIntegrator_gainva_c
                                          * Referenced by: '<S24>/Discrete-Time Integrator'
                                          */
  real_T Constant_Value_o;             /* Expression: 0
                                        * Referenced by: '<S26>/Constant'
                                        */
  real_T Gain_Gain_a;                  /* Expression: -1
                                        * Referenced by: '<S26>/Gain'
                                        */
  real_T Switch1_Threshold;            /* Expression: 0.01
                                        * Referenced by: '<S1>/Switch1'
                                        */
  real_T Switch_Threshold;             /* Expression: 0.01
                                        * Referenced by: '<S1>/Switch'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_On_T {
  const char_T *errorStatus;
};

/* Block parameters (default storage) */
extern P_On_T On_P;

/* Block signals (default storage) */
extern B_On_T On_B;

/* Block states (default storage) */
extern DW_On_T On_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_On_T On_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_On_T On_Y;

/* Model entry point functions */
extern void On_initialize(void);
extern void On_step(void);
extern void On_terminate(void);

/* Real-time Model object */
extern RT_MODEL_On_T *const On_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S6>/Data Type Duplicate' : Unused code path elimination
 * Block '<S12>/Data Type Duplicate' : Unused code path elimination
 * Block '<S27>/Scope' : Unused code path elimination
 * Block '<S27>/Scope1' : Unused code path elimination
 * Block '<S27>/Scope2' : Unused code path elimination
 * Block '<S1>/|ω|' : Unused code path elimination
 * Block '<S1>/ω_bl' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('assignment_pil/On-Board Computer')    - opens subsystem assignment_pil/On-Board Computer
 * hilite_system('assignment_pil/On-Board Computer/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'assignment_pil'
 * '<S1>'   : 'assignment_pil/On-Board Computer'
 * '<S2>'   : 'assignment_pil/On-Board Computer/De-Tumbling Control'
 * '<S3>'   : 'assignment_pil/On-Board Computer/Kinematics'
 * '<S4>'   : 'assignment_pil/On-Board Computer/Pointing Control'
 * '<S5>'   : 'assignment_pil/On-Board Computer/ω norm'
 * '<S6>'   : 'assignment_pil/On-Board Computer/De-Tumbling Control/Discrete Derivative1'
 * '<S7>'   : 'assignment_pil/On-Board Computer/De-Tumbling Control/MATLAB Function1'
 * '<S8>'   : 'assignment_pil/On-Board Computer/Kinematics/ '
 * '<S9>'   : 'assignment_pil/On-Board Computer/Kinematics/Error on ω '
 * '<S10>'  : 'assignment_pil/On-Board Computer/Kinematics/LVLH'
 * '<S11>'  : 'assignment_pil/On-Board Computer/Kinematics/Quaternions'
 * '<S12>'  : 'assignment_pil/On-Board Computer/Kinematics/ /Discrete Derivative'
 * '<S13>'  : 'assignment_pil/On-Board Computer/Kinematics/ /MATLAB Function'
 * '<S14>'  : 'assignment_pil/On-Board Computer/Kinematics/LVLH/Full Orbital Dynamics'
 * '<S15>'  : 'assignment_pil/On-Board Computer/Kinematics/LVLH/Full Orbital Dynamics/Compute R and V of reference orbit'
 * '<S16>'  : 'assignment_pil/On-Board Computer/Kinematics/LVLH/Full Orbital Dynamics/MATLAB Function'
 * '<S17>'  : 'assignment_pil/On-Board Computer/Kinematics/LVLH/Full Orbital Dynamics/Compute R and V of reference orbit/Initial Position'
 * '<S18>'  : 'assignment_pil/On-Board Computer/Kinematics/LVLH/Full Orbital Dynamics/Compute R and V of reference orbit/Initial Velocity'
 * '<S19>'  : 'assignment_pil/On-Board Computer/Kinematics/LVLH/Full Orbital Dynamics/Compute R and V of reference orbit/Orbital Dynamics'
 * '<S20>'  : 'assignment_pil/On-Board Computer/Kinematics/LVLH/Full Orbital Dynamics/Compute R and V of reference orbit/Initial Position/MATLAB Function2'
 * '<S21>'  : 'assignment_pil/On-Board Computer/Kinematics/LVLH/Full Orbital Dynamics/Compute R and V of reference orbit/Initial Velocity/MATLAB Function1'
 * '<S22>'  : 'assignment_pil/On-Board Computer/Kinematics/Quaternions/MATLAB Function'
 * '<S23>'  : 'assignment_pil/On-Board Computer/Kinematics/Quaternions/MATLAB Function1'
 * '<S24>'  : 'assignment_pil/On-Board Computer/Kinematics/Quaternions/Quaternions'
 * '<S25>'  : 'assignment_pil/On-Board Computer/Kinematics/Quaternions/Quaternions/Quaternion Kinematics'
 * '<S26>'  : 'assignment_pil/On-Board Computer/Pointing Control/Mixer'
 * '<S27>'  : 'assignment_pil/On-Board Computer/Pointing Control/Quaternion Feedback Control'
 * '<S28>'  : 'assignment_pil/On-Board Computer/ω norm/MATLAB Function1'
 */
#endif                                 /* RTW_HEADER_On_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
