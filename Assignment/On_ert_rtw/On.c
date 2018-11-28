/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: On.c
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

/* Block signals (default storage) */
B_On_T On_B;

/* Block states (default storage) */
DW_On_T On_DW;

/* External inputs (root inport signals with default storage) */
ExtU_On_T On_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_On_T On_Y;

/* Real-time model */
RT_MODEL_On_T On_M_;
RT_MODEL_On_T *const On_M = &On_M_;

/* Forward declaration for local functions */
static real_T On_norm(const real_T x[3]);

/*
 * Output and update for atomic system:
 *    '<S2>/MATLAB Function1'
 *    '<S5>/MATLAB Function1'
 */
void On_MATLABFunction1(const real_T rtu_u[3], real_T *rty_y)
{
  real_T scale;
  real_T absxk;
  real_T t;
  *rty_y = 0.0;
  scale = 3.3121686421112381E-170;
  absxk = fabs(rtu_u[0]);
  if (absxk > 3.3121686421112381E-170) {
    t = 3.3121686421112381E-170 / absxk;
    *rty_y = *rty_y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    *rty_y += t * t;
  }

  absxk = fabs(rtu_u[1]);
  if (absxk > scale) {
    t = scale / absxk;
    *rty_y = *rty_y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    *rty_y += t * t;
  }

  absxk = fabs(rtu_u[2]);
  if (absxk > scale) {
    t = scale / absxk;
    *rty_y = *rty_y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    *rty_y += t * t;
  }

  *rty_y = scale * sqrt(*rty_y);
}

/* Function for MATLAB Function: '<S14>/MATLAB Function' */
static real_T On_norm(const real_T x[3])
{
  real_T y;
  real_T scale;
  real_T absxk;
  real_T t;
  scale = 3.3121686421112381E-170;
  absxk = fabs(x[0]);
  if (absxk > 3.3121686421112381E-170) {
    y = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    y = t * t;
  }

  absxk = fabs(x[1]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  absxk = fabs(x[2]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  return scale * sqrt(y);
}

real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T tmp;
  real_T tmp_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    tmp = fabs(u0);
    tmp_0 = fabs(u1);
    if (rtIsInf(u1)) {
      if (tmp == 1.0) {
        y = 1.0;
      } else if (tmp > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (tmp_0 == 0.0) {
      y = 1.0;
    } else if (tmp_0 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = (rtNaN);
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

/* Model step function */
void On_step(void)
{
  int32_T i;
  int32_T i_0;
  int32_T rtb_A_LN_tmp;
  int32_T rtb_A_LN_tmp_0;

  /* MATLAB Function: '<S17>/MATLAB Function2' incorporates:
   *  Constant: '<S10>/Initial Conditions (KEP)'
   *  MATLAB Function: '<S18>/MATLAB Function1'
   */
  On_B.o_3_idx_0 = fabs(On_P.InitialConditionsKEP_Value[1]);
  On_B.o_3_idx_2 = cos(On_P.InitialConditionsKEP_Value[5]);
  On_B.R_m = (1.0 - On_B.o_3_idx_0 * On_B.o_3_idx_0) *
    On_P.InitialConditionsKEP_Value[0] / (On_B.o_3_idx_0 * On_B.o_3_idx_2 + 1.0);

  /* DiscreteIntegrator: '<S15>/Discrete-Time Integrator1' incorporates:
   *  MATLAB Function: '<S17>/MATLAB Function2'
   */
  if (On_DW.DiscreteTimeIntegrator1_IC_LOAD != 0) {
    /* MATLAB Function: '<S17>/MATLAB Function2' incorporates:
     *  Constant: '<S10>/Initial Conditions (KEP)'
     */
    On_B.qnorm = cos(On_P.InitialConditionsKEP_Value[3]);
    On_B.Diff_p[0] = On_B.qnorm;
    On_B.c_tmp = sin(On_P.InitialConditionsKEP_Value[3]);
    On_B.Diff_p[1] = On_B.c_tmp;
    On_B.Diff_p[2] = 0.0;
    On_B.Diff_p[3] = -On_B.c_tmp;
    On_B.Diff_p[4] = On_B.qnorm;
    On_B.Diff_p[5] = 0.0;
    On_B.Diff_p[6] = 0.0;
    On_B.TSamp[0] = 1.0;
    On_B.o_1[0] = 0.0;

    /* MATLAB Function: '<S17>/MATLAB Function2' */
    On_B.Diff_p[7] = 0.0;
    On_B.TSamp[1] = 0.0;
    On_B.o_1[1] = 0.0;

    /* MATLAB Function: '<S17>/MATLAB Function2' */
    On_B.Diff_p[8] = 1.0;
    On_B.TSamp[2] = 0.0;
    On_B.o_1[2] = 1.0;

    /* MATLAB Function: '<S17>/MATLAB Function2' incorporates:
     *  Constant: '<S10>/Initial Conditions (KEP)'
     */
    On_B.TSamp[3] = 0.0;
    On_B.qnorm = cos(On_P.InitialConditionsKEP_Value[2]);
    On_B.TSamp[4] = On_B.qnorm;
    On_B.c_tmp = sin(On_P.InitialConditionsKEP_Value[2]);
    On_B.TSamp[5] = On_B.c_tmp;
    On_B.TSamp[6] = 0.0;
    On_B.TSamp[7] = -On_B.c_tmp;
    On_B.TSamp[8] = On_B.qnorm;
    On_B.qnorm = cos(On_P.InitialConditionsKEP_Value[4]);
    On_B.dv1[0] = On_B.qnorm;
    On_B.c_tmp = sin(On_P.InitialConditionsKEP_Value[4]);
    On_B.dv1[1] = On_B.c_tmp;
    On_B.dv1[2] = 0.0;
    On_B.dv1[3] = -On_B.c_tmp;
    On_B.dv1[4] = On_B.qnorm;
    On_B.dv1[5] = 0.0;
    for (i = 0; i < 3; i++) {
      for (i_0 = 0; i_0 < 3; i_0++) {
        rtb_A_LN_tmp = i + 3 * i_0;
        On_B.rtb_Product_n_tmp[rtb_A_LN_tmp] = 0.0;
        rtb_A_LN_tmp_0 = 3 * i_0 + i;
        On_B.rtb_Product_n_tmp[rtb_A_LN_tmp] =
          On_B.rtb_Product_n_tmp[rtb_A_LN_tmp_0] + On_B.TSamp[3 * i_0] *
          On_B.Diff_p[i];
        On_B.rtb_Product_n_tmp[rtb_A_LN_tmp] = On_B.TSamp[3 * i_0 + 1] *
          On_B.Diff_p[i + 3] + On_B.rtb_Product_n_tmp[rtb_A_LN_tmp_0];
        On_B.rtb_Product_n_tmp[rtb_A_LN_tmp] = On_B.TSamp[3 * i_0 + 2] *
          On_B.Diff_p[i + 6] + On_B.rtb_Product_n_tmp[rtb_A_LN_tmp_0];
      }

      On_B.dv1[6 + i] = On_B.o_1[i];
    }

    On_B.R[0] = On_B.R_m * On_B.o_3_idx_2;
    On_B.R[1] = On_B.R_m * sin(On_P.InitialConditionsKEP_Value[5]);
    On_B.R[2] = 0.0;
    for (i = 0; i < 3; i++) {
      On_DW.DiscreteTimeIntegrator1_DSTATE[i] = 0.0;
      for (i_0 = 0; i_0 < 3; i_0++) {
        rtb_A_LN_tmp = i + 3 * i_0;
        On_B.Diff_p[rtb_A_LN_tmp] = 0.0;
        rtb_A_LN_tmp_0 = 3 * i_0 + i;
        On_B.Diff_p[rtb_A_LN_tmp] = On_B.Diff_p[rtb_A_LN_tmp_0] + On_B.dv1[3 *
          i_0] * On_B.rtb_Product_n_tmp[i];
        On_B.Diff_p[rtb_A_LN_tmp] = On_B.dv1[3 * i_0 + 1] *
          On_B.rtb_Product_n_tmp[i + 3] + On_B.Diff_p[rtb_A_LN_tmp_0];
        On_B.Diff_p[rtb_A_LN_tmp] = On_B.dv1[3 * i_0 + 2] *
          On_B.rtb_Product_n_tmp[i + 6] + On_B.Diff_p[rtb_A_LN_tmp_0];
        On_DW.DiscreteTimeIntegrator1_DSTATE[i] += On_B.Diff_p[rtb_A_LN_tmp_0] *
          On_B.R[i_0];
      }
    }
  }

  /* DiscreteIntegrator: '<S15>/Discrete-Time Integrator' incorporates:
   *  MATLAB Function: '<S18>/MATLAB Function1'
   */
  if (On_DW.DiscreteTimeIntegrator_IC_LOADI != 0) {
    /* MATLAB Function: '<S18>/MATLAB Function1' incorporates:
     *  Constant: '<S10>/Initial Conditions (KEP)'
     */
    On_B.Diff_p[0] = cos(On_P.InitialConditionsKEP_Value[3]);
    On_B.Diff_p[1] = sin(On_P.InitialConditionsKEP_Value[3]);
    On_B.Diff_p[2] = 0.0;
    On_B.Diff_p[3] = -sin(On_P.InitialConditionsKEP_Value[3]);
    On_B.Diff_p[4] = cos(On_P.InitialConditionsKEP_Value[3]);
    On_B.Diff_p[5] = 0.0;
    On_B.Diff_p[6] = 0.0;
    On_B.TSamp[0] = 1.0;
    On_B.o_1[0] = 0.0;

    /* MATLAB Function: '<S18>/MATLAB Function1' */
    On_B.Diff_p[7] = 0.0;
    On_B.TSamp[1] = 0.0;
    On_B.o_1[1] = 0.0;

    /* MATLAB Function: '<S18>/MATLAB Function1' */
    On_B.Diff_p[8] = 1.0;
    On_B.TSamp[2] = 0.0;
    On_B.o_1[2] = 1.0;

    /* MATLAB Function: '<S18>/MATLAB Function1' incorporates:
     *  Constant: '<S10>/Initial Conditions (KEP)'
     *  Constant: '<S10>/Planetary Constant'
     */
    On_B.TSamp[3] = 0.0;
    On_B.TSamp[4] = cos(On_P.InitialConditionsKEP_Value[2]);
    On_B.TSamp[5] = sin(On_P.InitialConditionsKEP_Value[2]);
    On_B.TSamp[6] = 0.0;
    On_B.TSamp[7] = -sin(On_P.InitialConditionsKEP_Value[2]);
    On_B.TSamp[8] = cos(On_P.InitialConditionsKEP_Value[2]);
    On_B.dv1[0] = cos(On_P.InitialConditionsKEP_Value[4]);
    On_B.dv1[1] = sin(On_P.InitialConditionsKEP_Value[4]);
    On_B.dv1[2] = 0.0;
    On_B.dv1[3] = -sin(On_P.InitialConditionsKEP_Value[4]);
    On_B.dv1[4] = cos(On_P.InitialConditionsKEP_Value[4]);
    On_B.dv1[5] = 0.0;
    for (i = 0; i < 3; i++) {
      for (i_0 = 0; i_0 < 3; i_0++) {
        rtb_A_LN_tmp = i + 3 * i_0;
        On_B.rtb_Product_n_tmp[rtb_A_LN_tmp] = 0.0;
        rtb_A_LN_tmp_0 = 3 * i_0 + i;
        On_B.rtb_Product_n_tmp[rtb_A_LN_tmp] =
          On_B.rtb_Product_n_tmp[rtb_A_LN_tmp_0] + On_B.TSamp[3 * i_0] *
          On_B.Diff_p[i];
        On_B.rtb_Product_n_tmp[rtb_A_LN_tmp] = On_B.TSamp[3 * i_0 + 1] *
          On_B.Diff_p[i + 3] + On_B.rtb_Product_n_tmp[rtb_A_LN_tmp_0];
        On_B.rtb_Product_n_tmp[rtb_A_LN_tmp] = On_B.TSamp[3 * i_0 + 2] *
          On_B.Diff_p[i + 6] + On_B.rtb_Product_n_tmp[rtb_A_LN_tmp_0];
      }

      On_B.dv1[6 + i] = On_B.o_1[i];
    }

    On_B.qnorm = sqrt(On_P.mu / ((1.0 - On_B.o_3_idx_0 * On_B.o_3_idx_0) *
      On_P.InitialConditionsKEP_Value[0]));
    On_B.R[0] = -On_B.qnorm * sin(On_P.InitialConditionsKEP_Value[5]);
    On_B.R[1] = On_B.qnorm * (On_B.o_3_idx_0 + On_B.o_3_idx_2);
    On_B.R[2] = 0.0;
    for (i = 0; i < 3; i++) {
      On_DW.DiscreteTimeIntegrator_DSTATE_e[i] = 0.0;
      for (i_0 = 0; i_0 < 3; i_0++) {
        rtb_A_LN_tmp = i + 3 * i_0;
        On_B.Diff_p[rtb_A_LN_tmp] = 0.0;
        rtb_A_LN_tmp_0 = 3 * i_0 + i;
        On_B.Diff_p[rtb_A_LN_tmp] = On_B.Diff_p[rtb_A_LN_tmp_0] + On_B.dv1[3 *
          i_0] * On_B.rtb_Product_n_tmp[i];
        On_B.Diff_p[rtb_A_LN_tmp] = On_B.dv1[3 * i_0 + 1] *
          On_B.rtb_Product_n_tmp[i + 3] + On_B.Diff_p[rtb_A_LN_tmp_0];
        On_B.Diff_p[rtb_A_LN_tmp] = On_B.dv1[3 * i_0 + 2] *
          On_B.rtb_Product_n_tmp[i + 6] + On_B.Diff_p[rtb_A_LN_tmp_0];
        On_DW.DiscreteTimeIntegrator_DSTATE_e[i] += On_B.Diff_p[rtb_A_LN_tmp_0] *
          On_B.R[i_0];
      }
    }
  }

  /* MATLAB Function: '<S14>/MATLAB Function' incorporates:
   *  DiscreteIntegrator: '<S15>/Discrete-Time Integrator'
   *  DiscreteIntegrator: '<S15>/Discrete-Time Integrator1'
   */
  On_B.qnorm = On_norm(On_DW.DiscreteTimeIntegrator1_DSTATE);
  On_B.o_3_idx_0 = On_DW.DiscreteTimeIntegrator1_DSTATE[1] *
    On_DW.DiscreteTimeIntegrator_DSTATE_e[2] -
    On_DW.DiscreteTimeIntegrator1_DSTATE[2] *
    On_DW.DiscreteTimeIntegrator_DSTATE_e[1];
  On_B.VectorConcatenate1[0] = On_B.o_3_idx_0;
  On_B.R_m = On_DW.DiscreteTimeIntegrator1_DSTATE[2] *
    On_DW.DiscreteTimeIntegrator_DSTATE_e[0] -
    On_DW.DiscreteTimeIntegrator1_DSTATE[0] *
    On_DW.DiscreteTimeIntegrator_DSTATE_e[2];
  On_B.VectorConcatenate1[1] = On_B.R_m;
  On_B.o_3_idx_2 = On_DW.DiscreteTimeIntegrator1_DSTATE[0] *
    On_DW.DiscreteTimeIntegrator_DSTATE_e[1] -
    On_DW.DiscreteTimeIntegrator1_DSTATE[1] *
    On_DW.DiscreteTimeIntegrator_DSTATE_e[0];
  On_B.VectorConcatenate1[2] = On_B.o_3_idx_2;
  On_B.c_tmp = On_norm(On_B.VectorConcatenate1);
  On_B.o_3_idx_0 = -On_B.o_3_idx_0 / On_B.c_tmp;
  On_B.R_m = -On_B.R_m / On_B.c_tmp;
  On_B.o_3_idx_2 = -On_B.o_3_idx_2 / On_B.c_tmp;
  On_B.c_tmp = -On_DW.DiscreteTimeIntegrator1_DSTATE[0] / On_B.qnorm;
  On_B.A_LN[0] = On_B.c_tmp;
  On_B.A_LN[2] = On_B.o_3_idx_0;
  On_B.o_1[0] = On_B.c_tmp;
  On_B.c_tmp = -On_DW.DiscreteTimeIntegrator1_DSTATE[1] / On_B.qnorm;
  On_B.A_LN[3] = On_B.c_tmp;
  On_B.A_LN[5] = On_B.R_m;
  On_B.o_1[1] = On_B.c_tmp;
  On_B.c_tmp = -On_DW.DiscreteTimeIntegrator1_DSTATE[2] / On_B.qnorm;
  On_B.A_LN[6] = On_B.c_tmp;
  On_B.A_LN[8] = On_B.o_3_idx_2;
  On_B.A_LN[1] = On_B.R_m * On_B.c_tmp - On_B.o_3_idx_2 * On_B.o_1[1];
  On_B.A_LN[4] = On_B.o_3_idx_2 * On_B.o_1[0] - On_B.o_3_idx_0 * On_B.c_tmp;
  On_B.A_LN[7] = On_B.o_3_idx_0 * On_B.o_1[1] - On_B.R_m * On_B.o_1[0];
  for (i = 0; i < 9; i++) {
    /* Gain: '<S8>/Gain' */
    On_B.qnorm = On_P.Gain_Gain_m * On_B.A_LN[i];

    /* SampleTimeMath: '<S12>/TSamp'
     *
     * About '<S12>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     *  Multiplication by K = weightedTsampQuantized is being
     *  done implicitly by changing the scaling of the input signal.
     *  No work needs to be done here.  Downstream blocks may need
     *  to do work to handle the scaling of the output; this happens
     *  automatically.
     */
    On_B.TSamp[i] = On_B.qnorm;

    /* Gain: '<S8>/Gain' incorporates:
     *  SampleTimeMath: '<S12>/TSamp'
     *  Sum: '<S12>/Diff'
     *  UnitDelay: '<S12>/UD'
     *
     * About '<S12>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     *  Multiplication by K = weightedTsampQuantized is being
     *  done implicitly by changing the scaling of the input signal.
     *  No work needs to be done here.  Downstream blocks may need
     *  to do work to handle the scaling of the output; this happens
     *  automatically.
     *
     * Block description for '<S12>/Diff':
     *
     *  Add in CPU
     *
     * Block description for '<S12>/UD':
     *
     *  Store in Global RAM
     */
    On_B.Diff_p[i] = On_B.qnorm - On_DW.UD_DSTATE[i];
  }

  for (i = 0; i < 3; i++) {
    /* Math: '<S8>/Math Function' incorporates:
     *  Math: '<S9>/Math Function1'
     */
    On_B.rtb_Product_n_tmp[3 * i] = On_B.A_LN[i];
    On_B.rtb_Product_n_tmp[1 + 3 * i] = On_B.A_LN[i + 3];
    On_B.rtb_Product_n_tmp[2 + 3 * i] = On_B.A_LN[i + 6];
  }

  /* Product: '<S8>/Product' incorporates:
   *  Math: '<S8>/Math Function'
   */
  for (i = 0; i < 3; i++) {
    for (i_0 = 0; i_0 < 3; i_0++) {
      rtb_A_LN_tmp = i_0 + 3 * i;
      On_B.A_LN[rtb_A_LN_tmp] = 0.0;
      rtb_A_LN_tmp_0 = 3 * i + i_0;
      On_B.A_LN[rtb_A_LN_tmp] = On_B.A_LN[rtb_A_LN_tmp_0] +
        On_B.rtb_Product_n_tmp[3 * i] * On_B.Diff_p[i_0];
      On_B.A_LN[rtb_A_LN_tmp] = On_B.rtb_Product_n_tmp[3 * i + 1] *
        On_B.Diff_p[i_0 + 3] + On_B.A_LN[rtb_A_LN_tmp_0];
      On_B.A_LN[rtb_A_LN_tmp] = On_B.rtb_Product_n_tmp[3 * i + 2] *
        On_B.Diff_p[i_0 + 6] + On_B.A_LN[rtb_A_LN_tmp_0];
    }
  }

  /* End of Product: '<S8>/Product' */

  /* Gain: '<S27>/Gain2' incorporates:
   *  DiscreteIntegrator: '<S24>/Discrete-Time Integrator'
   */
  for (i = 0; i < 4; i++) {
    On_B.qnorm = On_P.Q_C[i + 12] * On_DW.DiscreteTimeIntegrator_DSTATE_k[3] +
      (On_P.Q_C[i + 8] * On_DW.DiscreteTimeIntegrator_DSTATE_k[2] + (On_P.Q_C[i
        + 4] * On_DW.DiscreteTimeIntegrator_DSTATE_k[1] + On_P.Q_C[i] *
        On_DW.DiscreteTimeIntegrator_DSTATE_k[0]));
    On_B.Gain2[i] = On_B.qnorm;
  }

  /* End of Gain: '<S27>/Gain2' */

  /* SignalConversion: '<S27>/ConcatBufferAtVector Concatenate1In1' */
  On_B.VectorConcatenate1[0] = On_B.Gain2[0];

  /* SignalConversion: '<S27>/ConcatBufferAtVector Concatenate1In2' */
  On_B.VectorConcatenate1[1] = On_B.Gain2[1];

  /* SignalConversion: '<S27>/ConcatBufferAtVector Concatenate1In3' */
  On_B.VectorConcatenate1[2] = On_B.Gain2[2];

  /* MATLAB Function: '<S24>/Quaternion Kinematics' incorporates:
   *  DiscreteIntegrator: '<S24>/Discrete-Time Integrator'
   */
  On_B.qnorm = sqrt(((On_DW.DiscreteTimeIntegrator_DSTATE_k[0] *
                      On_DW.DiscreteTimeIntegrator_DSTATE_k[0] +
                      On_DW.DiscreteTimeIntegrator_DSTATE_k[1] *
                      On_DW.DiscreteTimeIntegrator_DSTATE_k[1]) +
                     On_DW.DiscreteTimeIntegrator_DSTATE_k[2] *
                     On_DW.DiscreteTimeIntegrator_DSTATE_k[2]) +
                    On_DW.DiscreteTimeIntegrator_DSTATE_k[3] *
                    On_DW.DiscreteTimeIntegrator_DSTATE_k[3]);
  On_B.o_3_idx_0 = On_DW.DiscreteTimeIntegrator_DSTATE_k[0] / On_B.qnorm;
  On_B.o_3_idx_2 = On_DW.DiscreteTimeIntegrator_DSTATE_k[1] / On_B.qnorm;
  On_B.c_tmp = On_DW.DiscreteTimeIntegrator_DSTATE_k[2] / On_B.qnorm;
  On_B.R_m = On_DW.DiscreteTimeIntegrator_DSTATE_k[3] / On_B.qnorm;

  /* Signum: '<S27>/Sign' */
  if (On_B.Gain2[3] < 0.0) {
    On_B.y_a = -1.0;
  } else if (On_B.Gain2[3] > 0.0) {
    On_B.y_a = 1.0;
  } else if (On_B.Gain2[3] == 0.0) {
    On_B.y_a = 0.0;
  } else {
    On_B.y_a = (rtNaN);
  }

  /* End of Signum: '<S27>/Sign' */

  /* MATLAB Function: '<S8>/MATLAB Function' */
  On_B.R[0] = On_B.A_LN[5];
  On_B.R[1] = On_B.A_LN[6];
  On_B.R[2] = On_B.A_LN[1];

  /* MATLAB Function: '<S15>/Orbital Dynamics' */
  On_B.Saturation1 = 0.0;
  On_B.scale = 3.3121686421112381E-170;
  for (rtb_A_LN_tmp_0 = 0; rtb_A_LN_tmp_0 < 3; rtb_A_LN_tmp_0++) {
    /* Sum: '<S9>/Subtract' */
    On_B.qnorm = 0.0;
    for (i = 0; i < 3; i++) {
      /* Product: '<S9>/Product1' incorporates:
       *  DiscreteIntegrator: '<S11>/Discrete-Time Integrator'
       *  Math: '<S9>/Math Function1'
       *  Product: '<S9>/Product'
       */
      i_0 = rtb_A_LN_tmp_0 + 3 * i;
      On_B.Diff_p[i_0] = 0.0;
      rtb_A_LN_tmp = 3 * i + rtb_A_LN_tmp_0;
      On_B.Diff_p[i_0] = On_B.Diff_p[rtb_A_LN_tmp] + On_B.rtb_Product_n_tmp[3 *
        i] * On_DW.DiscreteTimeIntegrator_DSTATE[rtb_A_LN_tmp_0];
      On_B.Diff_p[i_0] = On_B.rtb_Product_n_tmp[3 * i + 1] *
        On_DW.DiscreteTimeIntegrator_DSTATE[rtb_A_LN_tmp_0 + 3] +
        On_B.Diff_p[rtb_A_LN_tmp];
      On_B.Diff_p[i_0] = On_B.rtb_Product_n_tmp[3 * i + 2] *
        On_DW.DiscreteTimeIntegrator_DSTATE[rtb_A_LN_tmp_0 + 6] +
        On_B.Diff_p[rtb_A_LN_tmp];

      /* Sum: '<S9>/Subtract' incorporates:
       *  Product: '<S9>/Product'
       */
      On_B.qnorm += On_B.Diff_p[rtb_A_LN_tmp] * On_B.R[i];
    }

    /* Sum: '<S27>/Add' incorporates:
     *  Gain: '<S27>/Gain'
     *  Gain: '<S27>/Gain1'
     *  Inport: '<Root>/Gyroscope Measure'
     *  Product: '<S27>/Product2'
     *  Product: '<S9>/Product'
     *  Sum: '<S9>/Subtract'
     */
    On_B.o_1[rtb_A_LN_tmp_0] = (On_U._bn[rtb_A_LN_tmp_0] - On_B.qnorm) *
      On_P.k_d + On_P.k_p * On_B.VectorConcatenate1[rtb_A_LN_tmp_0] * On_B.y_a;

    /* MATLAB Function: '<S15>/Orbital Dynamics' incorporates:
     *  DiscreteIntegrator: '<S15>/Discrete-Time Integrator1'
     */
    On_B.qnorm = fabs(On_DW.DiscreteTimeIntegrator1_DSTATE[rtb_A_LN_tmp_0]);
    if (On_B.qnorm > On_B.scale) {
      On_B.t = On_B.scale / On_B.qnorm;
      On_B.Saturation1 = On_B.Saturation1 * On_B.t * On_B.t + 1.0;
      On_B.scale = On_B.qnorm;
    } else {
      On_B.t = On_B.qnorm / On_B.scale;
      On_B.Saturation1 += On_B.t * On_B.t;
    }
  }

  /* MATLAB Function: '<S15>/Orbital Dynamics' incorporates:
   *  Constant: '<S10>/Planetary Constant'
   *  DiscreteIntegrator: '<S15>/Discrete-Time Integrator1'
   */
  On_B.Saturation1 = On_B.scale * sqrt(On_B.Saturation1);
  On_B.qnorm = -(On_P.mu / rt_powd_snf(On_B.Saturation1, 3.0));
  On_B.VectorConcatenate1[0] = On_B.qnorm *
    On_DW.DiscreteTimeIntegrator1_DSTATE[0];
  On_B.VectorConcatenate1[1] = On_B.qnorm *
    On_DW.DiscreteTimeIntegrator1_DSTATE[1];
  On_B.VectorConcatenate1[2] = On_B.qnorm *
    On_DW.DiscreteTimeIntegrator1_DSTATE[2];

  /* MATLAB Function: '<S5>/MATLAB Function1' incorporates:
   *  Inport: '<Root>/Gyroscope Measure'
   */
  On_MATLABFunction1(On_U._bn, &On_B.qnorm);

  /* Product: '<S26>/Divide1' incorporates:
   *  Inport: '<Root>/Magnetometer Measure'
   */
  On_B.Saturation1 = On_B.o_1[0] / On_U.MagnetometerMeasure[2];

  /* Saturate: '<S26>/Saturation1' */
  if (On_B.Saturation1 > On_P.m_max) {
    On_B.Saturation1 = On_P.m_max;
  } else {
    if (On_B.Saturation1 < -On_P.m_max) {
      On_B.Saturation1 = -On_P.m_max;
    }
  }

  /* End of Saturate: '<S26>/Saturation1' */

  /* Product: '<S26>/Divide' incorporates:
   *  Gain: '<S26>/Gain'
   *  Inport: '<Root>/Magnetometer Measure'
   */
  On_B.y_a = On_P.Gain_Gain_a * On_B.o_1[1] / On_U.MagnetometerMeasure[2];

  /* Saturate: '<S26>/Saturation' */
  if (On_B.y_a > On_P.m_max) {
    On_B.scale = On_P.m_max;
  } else if (On_B.y_a < -On_P.m_max) {
    On_B.scale = -On_P.m_max;
  } else {
    On_B.scale = On_B.y_a;
  }

  /* End of Saturate: '<S26>/Saturation' */

  /* Switch: '<S1>/Switch1' */
  if (On_B.qnorm > On_P.Switch1_Threshold) {
    /* Outport: '<Root>/Commanded RW Torque' incorporates:
     *  Constant: '<S1>/Constant1'
     */
    On_Y.CommandedRWTorque[0] = On_P.Constant1_Value[0];
    On_Y.CommandedRWTorque[1] = On_P.Constant1_Value[1];
    On_Y.CommandedRWTorque[2] = On_P.Constant1_Value[2];
  } else {
    /* Outport: '<Root>/Commanded RW Torque' incorporates:
     *  Constant: '<S26>/Constant'
     *  Inport: '<Root>/Magnetometer Measure'
     *  Product: '<S26>/Multiply'
     *  Product: '<S26>/Multiply1'
     *  Sum: '<S26>/Sum'
     */
    On_Y.CommandedRWTorque[0] = On_P.Constant_Value_o;
    On_Y.CommandedRWTorque[1] = On_P.Constant_Value_o;
    On_Y.CommandedRWTorque[2] = (On_B.Saturation1 * On_U.MagnetometerMeasure[0]
      - On_U.MagnetometerMeasure[1] * On_B.scale) + On_B.o_1[2];
  }

  /* End of Switch: '<S1>/Switch1' */

  /* MATLAB Function: '<S2>/MATLAB Function1' incorporates:
   *  Inport: '<Root>/Magnetometer Measure'
   */
  On_MATLABFunction1(On_U.MagnetometerMeasure, &On_B.y_a);

  /* Switch: '<S1>/Switch' */
  if (On_B.qnorm > On_P.Switch_Threshold) {
    /* Outport: '<Root>/Commanded Dipole Moment' incorporates:
     *  Gain: '<S2>/Gain1'
     *  Inport: '<Root>/Magnetometer Measure'
     *  Product: '<S2>/Divide'
     *  SampleTimeMath: '<S6>/TSamp'
     *  Sum: '<S6>/Diff'
     *  UnitDelay: '<S6>/UD'
     *
     * About '<S6>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     *  Multiplication by K = weightedTsampQuantized is being
     *  done implicitly by changing the scaling of the input signal.
     *  No work needs to be done here.  Downstream blocks may need
     *  to do work to handle the scaling of the output; this happens
     *  automatically.
     *
     * Block description for '<S6>/Diff':
     *
     *  Add in CPU
     *
     * Block description for '<S6>/UD':
     *
     *  Store in Global RAM
     */
    On_Y.CommandedDipoleMoment[0] = (On_U.MagnetometerMeasure[0] -
      On_DW.UD_DSTATE_a[0]) * On_P.k_bdot / On_B.y_a;
    On_Y.CommandedDipoleMoment[1] = (On_U.MagnetometerMeasure[1] -
      On_DW.UD_DSTATE_a[1]) * On_P.k_bdot / On_B.y_a;
    On_Y.CommandedDipoleMoment[2] = (On_U.MagnetometerMeasure[2] -
      On_DW.UD_DSTATE_a[2]) * On_P.k_bdot / On_B.y_a;
  } else {
    /* Outport: '<Root>/Commanded Dipole Moment' incorporates:
     *  Constant: '<S26>/Constant'
     */
    On_Y.CommandedDipoleMoment[0] = On_B.scale;
    On_Y.CommandedDipoleMoment[1] = On_B.Saturation1;
    On_Y.CommandedDipoleMoment[2] = On_P.Constant_Value_o;
  }

  /* End of Switch: '<S1>/Switch' */

  /* Gain: '<S11>/Gain' incorporates:
   *  Inport: '<Root>/Gyroscope Measure'
   *  MATLAB Function: '<S11>/MATLAB Function'
   */
  On_B.Diff_p[0] = On_P.Gain_Gain * 0.0;
  On_B.Diff_p[3] = On_P.Gain_Gain * -On_U._bn[2];
  On_B.Diff_p[6] = On_P.Gain_Gain * On_U._bn[1];
  On_B.Diff_p[1] = On_P.Gain_Gain * On_U._bn[2];
  On_B.Diff_p[4] = On_P.Gain_Gain * 0.0;
  On_B.Diff_p[7] = On_P.Gain_Gain * -On_U._bn[0];
  On_B.Diff_p[2] = On_P.Gain_Gain * -On_U._bn[1];
  On_B.Diff_p[5] = On_P.Gain_Gain * On_U._bn[0];
  On_B.Diff_p[8] = On_P.Gain_Gain * 0.0;

  /* Product: '<S11>/Product' incorporates:
   *  DiscreteIntegrator: '<S11>/Discrete-Time Integrator'
   */
  for (i = 0; i < 3; i++) {
    for (i_0 = 0; i_0 < 3; i_0++) {
      rtb_A_LN_tmp = i_0 + 3 * i;
      On_B.rtb_Product_n_tmp[rtb_A_LN_tmp] = 0.0;
      rtb_A_LN_tmp_0 = 3 * i + i_0;
      On_B.rtb_Product_n_tmp[rtb_A_LN_tmp] =
        On_B.rtb_Product_n_tmp[rtb_A_LN_tmp_0] +
        On_DW.DiscreteTimeIntegrator_DSTATE[3 * i] * On_B.Diff_p[i_0];
      On_B.rtb_Product_n_tmp[rtb_A_LN_tmp] =
        On_DW.DiscreteTimeIntegrator_DSTATE[3 * i + 1] * On_B.Diff_p[i_0 + 3] +
        On_B.rtb_Product_n_tmp[rtb_A_LN_tmp_0];
      On_B.rtb_Product_n_tmp[rtb_A_LN_tmp] =
        On_DW.DiscreteTimeIntegrator_DSTATE[3 * i + 2] * On_B.Diff_p[i_0 + 6] +
        On_B.rtb_Product_n_tmp[rtb_A_LN_tmp_0];
    }
  }

  /* End of Product: '<S11>/Product' */

  /* Update for DiscreteIntegrator: '<S15>/Discrete-Time Integrator1' */
  On_DW.DiscreteTimeIntegrator1_IC_LOAD = 0U;

  /* Update for DiscreteIntegrator: '<S15>/Discrete-Time Integrator' */
  On_DW.DiscreteTimeIntegrator_IC_LOADI = 0U;

  /* Update for DiscreteIntegrator: '<S15>/Discrete-Time Integrator1' incorporates:
   *  DiscreteIntegrator: '<S15>/Discrete-Time Integrator'
   */
  On_DW.DiscreteTimeIntegrator1_DSTATE[0] +=
    On_P.DiscreteTimeIntegrator1_gainval *
    On_DW.DiscreteTimeIntegrator_DSTATE_e[0];

  /* Update for DiscreteIntegrator: '<S15>/Discrete-Time Integrator' */
  On_DW.DiscreteTimeIntegrator_DSTATE_e[0] +=
    On_P.DiscreteTimeIntegrator_gainva_l * On_B.VectorConcatenate1[0];

  /* Update for DiscreteIntegrator: '<S15>/Discrete-Time Integrator1' incorporates:
   *  DiscreteIntegrator: '<S15>/Discrete-Time Integrator'
   */
  On_DW.DiscreteTimeIntegrator1_DSTATE[1] +=
    On_P.DiscreteTimeIntegrator1_gainval *
    On_DW.DiscreteTimeIntegrator_DSTATE_e[1];

  /* Update for DiscreteIntegrator: '<S15>/Discrete-Time Integrator' */
  On_DW.DiscreteTimeIntegrator_DSTATE_e[1] +=
    On_P.DiscreteTimeIntegrator_gainva_l * On_B.VectorConcatenate1[1];

  /* Update for DiscreteIntegrator: '<S15>/Discrete-Time Integrator1' incorporates:
   *  DiscreteIntegrator: '<S15>/Discrete-Time Integrator'
   */
  On_DW.DiscreteTimeIntegrator1_DSTATE[2] +=
    On_P.DiscreteTimeIntegrator1_gainval *
    On_DW.DiscreteTimeIntegrator_DSTATE_e[2];

  /* Update for DiscreteIntegrator: '<S15>/Discrete-Time Integrator' */
  On_DW.DiscreteTimeIntegrator_DSTATE_e[2] +=
    On_P.DiscreteTimeIntegrator_gainva_l * On_B.VectorConcatenate1[2];
  for (i = 0; i < 9; i++) {
    /* Update for DiscreteIntegrator: '<S11>/Discrete-Time Integrator' */
    On_DW.DiscreteTimeIntegrator_DSTATE[i] +=
      On_P.DiscreteTimeIntegrator_gainval * On_B.rtb_Product_n_tmp[i];

    /* Update for UnitDelay: '<S12>/UD'
     *
     * Block description for '<S12>/UD':
     *
     *  Store in Global RAM
     */
    On_DW.UD_DSTATE[i] = On_B.TSamp[i];
  }

  /* MATLAB Function: '<S24>/Quaternion Kinematics' */
  On_B.dv0[0] = 0.5 * On_B.R_m;
  On_B.qnorm = 0.5 * -On_B.c_tmp;
  On_B.dv0[4] = On_B.qnorm;
  On_B.dv0[8] = 0.5 * On_B.o_3_idx_2;
  On_B.dv0[1] = 0.5 * On_B.c_tmp;
  On_B.dv0[5] = 0.5 * On_B.R_m;
  On_B.c_tmp = 0.5 * -On_B.o_3_idx_0;
  On_B.dv0[9] = On_B.c_tmp;
  On_B.o_3_idx_2 = 0.5 * -On_B.o_3_idx_2;
  On_B.dv0[2] = On_B.o_3_idx_2;
  On_B.dv0[6] = 0.5 * On_B.o_3_idx_0;
  On_B.dv0[10] = 0.5 * On_B.R_m;
  On_B.dv0[3] = On_B.c_tmp;
  On_B.dv0[7] = On_B.o_3_idx_2;
  On_B.dv0[11] = On_B.qnorm;
  for (i = 0; i < 4; i++) {
    /* Update for DiscreteIntegrator: '<S24>/Discrete-Time Integrator' incorporates:
     *  Inport: '<Root>/Gyroscope Measure'
     */
    On_DW.DiscreteTimeIntegrator_DSTATE_k[i] +=
      On_P.DiscreteTimeIntegrator_gainva_c * (On_B.dv0[i + 8] * On_U._bn[2] +
      (On_B.dv0[i + 4] * On_U._bn[1] + On_B.dv0[i] * On_U._bn[0]));
  }

  /* Update for UnitDelay: '<S6>/UD' incorporates:
   *  Inport: '<Root>/Magnetometer Measure'
   *  SampleTimeMath: '<S6>/TSamp'
   *
   * About '<S6>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   *  Multiplication by K = weightedTsampQuantized is being
   *  done implicitly by changing the scaling of the input signal.
   *  No work needs to be done here.  Downstream blocks may need
   *  to do work to handle the scaling of the output; this happens
   *  automatically.
   *
   * Block description for '<S6>/UD':
   *
   *  Store in Global RAM
   */
  On_DW.UD_DSTATE_a[0] = On_U.MagnetometerMeasure[0];
  On_DW.UD_DSTATE_a[1] = On_U.MagnetometerMeasure[1];
  On_DW.UD_DSTATE_a[2] = On_U.MagnetometerMeasure[2];
}

/* Model initialize function */
void On_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize error status */
  rtmSetErrorStatus(On_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&On_DW, 0,
                sizeof(DW_On_T));

  /* external inputs */
  (void)memset(&On_U, 0, sizeof(ExtU_On_T));

  /* external outputs */
  (void) memset((void *)&On_Y, 0,
                sizeof(ExtY_On_T));

  {
    int32_T i;

    /* InitializeConditions for DiscreteIntegrator: '<S15>/Discrete-Time Integrator1' */
    On_DW.DiscreteTimeIntegrator1_IC_LOAD = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S15>/Discrete-Time Integrator' */
    On_DW.DiscreteTimeIntegrator_IC_LOADI = 1U;
    for (i = 0; i < 9; i++) {
      /* InitializeConditions for DiscreteIntegrator: '<S11>/Discrete-Time Integrator' */
      On_DW.DiscreteTimeIntegrator_DSTATE[i] = On_P.A_BN_0[i];

      /* InitializeConditions for UnitDelay: '<S12>/UD'
       *
       * Block description for '<S12>/UD':
       *
       *  Store in Global RAM
       */
      On_DW.UD_DSTATE[i] = On_P.DiscreteDerivative_ICPrevScaled;
    }

    /* InitializeConditions for DiscreteIntegrator: '<S24>/Discrete-Time Integrator' incorporates:
     *  Constant: '<S11>/Constant'
     */
    On_DW.DiscreteTimeIntegrator_DSTATE_k[0] = On_P.Constant_Value[0];
    On_DW.DiscreteTimeIntegrator_DSTATE_k[1] = On_P.Constant_Value[1];
    On_DW.DiscreteTimeIntegrator_DSTATE_k[2] = On_P.Constant_Value[2];
    On_DW.DiscreteTimeIntegrator_DSTATE_k[3] = On_P.Constant_Value[3];

    /* InitializeConditions for UnitDelay: '<S6>/UD'
     *
     * Block description for '<S6>/UD':
     *
     *  Store in Global RAM
     */
    On_DW.UD_DSTATE_a[0] = On_P.DiscreteDerivative1_ICPrevScale;
    On_DW.UD_DSTATE_a[1] = On_P.DiscreteDerivative1_ICPrevScale;
    On_DW.UD_DSTATE_a[2] = On_P.DiscreteDerivative1_ICPrevScale;
  }
}

/* Model terminate function */
void On_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
