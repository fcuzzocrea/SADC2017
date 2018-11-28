/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: On_data.c
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

#include "On.h"
#include "On_private.h"

/* Block parameters (default storage) */
P_On_T On_P = {
  /* Variable: A_BN_0
   * Referenced by: '<S11>/Discrete-Time Integrator'
   */
  { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 },

  /* Variable: Q_C
   * Referenced by: '<S27>/Gain2'
   */
  { 0.0, -0.988, -0.1542, 0.0, 0.988, 0.0, -0.0, -0.1542, 0.1542, 0.0, 0.0,
    0.988, -0.0, 0.1542, -0.988, 0.0 },

  /* Variable: k_bdot
   * Referenced by: '<S2>/Gain1'
   */
  -20.621319695904774,

  /* Variable: k_d
   * Referenced by: '<S27>/Gain'
   */
  -0.08,

  /* Variable: k_p
   * Referenced by: '<S27>/Gain1'
   */
  -0.0003,

  /* Variable: m_max
   * Referenced by:
   *   '<S26>/Saturation'
   *   '<S26>/Saturation1'
   */
  1.2,

  /* Variable: mu
   * Referenced by: '<S10>/Planetary Constant'
   */
  398600.0,

  /* Mask Parameter: DiscreteDerivative_ICPrevScaled
   * Referenced by: '<S12>/UD'
   */
  0.0,

  /* Mask Parameter: DiscreteDerivative1_ICPrevScale
   * Referenced by: '<S6>/UD'
   */
  0.0,

  /* Expression: [0;0;0]
   * Referenced by: '<S1>/Constant1'
   */
  { 0.0, 0.0, 0.0 },

  /* Computed Parameter: DiscreteTimeIntegrator_gainval
   * Referenced by: '<S11>/Discrete-Time Integrator'
   */
  1.0,

  /* Expression: -1
   * Referenced by: '<S11>/Gain'
   */
  -1.0,

  /* Expression: [a, e, i, OMG, omg, theta]
   * Referenced by: '<S10>/Initial Conditions (KEP)'
   */
  { 7178.0, 0.0, 60.0, 0.0, 0.0, 0.0 },

  /* Computed Parameter: DiscreteTimeIntegrator1_gainval
   * Referenced by: '<S15>/Discrete-Time Integrator1'
   */
  1.0,

  /* Computed Parameter: DiscreteTimeIntegrator_gainva_l
   * Referenced by: '<S15>/Discrete-Time Integrator'
   */
  1.0,

  /* Expression: -1
   * Referenced by: '<S8>/Gain'
   */
  -1.0,

  /* Expression: [0;0;0;1]
   * Referenced by: '<S11>/Constant'
   */
  { 0.0, 0.0, 0.0, 1.0 },

  /* Computed Parameter: DiscreteTimeIntegrator_gainva_c
   * Referenced by: '<S24>/Discrete-Time Integrator'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S26>/Constant'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S26>/Gain'
   */
  -1.0,

  /* Expression: 0.01
   * Referenced by: '<S1>/Switch1'
   */
  0.01,

  /* Expression: 0.01
   * Referenced by: '<S1>/Switch'
   */
  0.01
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
