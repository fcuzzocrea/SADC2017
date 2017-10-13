/* Include files */

#include "euler_works_sfun.h"
#include "c6_euler_works.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "euler_works_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c_with_debugger(S, sfGlobalDebugInstanceStruct);

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization);
static void chart_debug_initialize_data_addresses(SimStruct *S);
static const mxArray* sf_opaque_get_hover_data_for_msg(void *chartInstance,
  int32_T msgSSID);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c6_debug_family_names[8] = { "r_1", "r_2", "r_3", "xp",
  "xp_dot", "nargin", "nargout", "A_LN" };

/* Function Declarations */
static void initialize_c6_euler_works(SFc6_euler_worksInstanceStruct
  *chartInstance);
static void initialize_params_c6_euler_works(SFc6_euler_worksInstanceStruct
  *chartInstance);
static void enable_c6_euler_works(SFc6_euler_worksInstanceStruct *chartInstance);
static void disable_c6_euler_works(SFc6_euler_worksInstanceStruct *chartInstance);
static void c6_update_debugger_state_c6_euler_works
  (SFc6_euler_worksInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c6_euler_works
  (SFc6_euler_worksInstanceStruct *chartInstance);
static void set_sim_state_c6_euler_works(SFc6_euler_worksInstanceStruct
  *chartInstance, const mxArray *c6_st);
static void finalize_c6_euler_works(SFc6_euler_worksInstanceStruct
  *chartInstance);
static void sf_gateway_c6_euler_works(SFc6_euler_worksInstanceStruct
  *chartInstance);
static void mdl_start_c6_euler_works(SFc6_euler_worksInstanceStruct
  *chartInstance);
static void initSimStructsc6_euler_works(SFc6_euler_worksInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c6_machineNumber, uint32_T
  c6_chartNumber, uint32_T c6_instanceNumber);
static const mxArray *c6_sf_marshallOut(void *chartInstanceVoid, void *c6_inData);
static void c6_emlrt_marshallIn(SFc6_euler_worksInstanceStruct *chartInstance,
  const mxArray *c6_b_A_LN, const char_T *c6_identifier, real_T c6_y[9]);
static void c6_b_emlrt_marshallIn(SFc6_euler_worksInstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId, real_T c6_y[9]);
static void c6_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static const mxArray *c6_b_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static const mxArray *c6_c_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static real_T c6_c_emlrt_marshallIn(SFc6_euler_worksInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static const mxArray *c6_d_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static void c6_d_emlrt_marshallIn(SFc6_euler_worksInstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId, real_T c6_y[3]);
static void c6_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static const mxArray *c6_e_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static int32_T c6_e_emlrt_marshallIn(SFc6_euler_worksInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static uint8_T c6_f_emlrt_marshallIn(SFc6_euler_worksInstanceStruct
  *chartInstance, const mxArray *c6_b_is_active_c6_euler_works, const char_T
  *c6_identifier);
static uint8_T c6_g_emlrt_marshallIn(SFc6_euler_worksInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void init_dsm_address_info(SFc6_euler_worksInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc6_euler_worksInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c6_euler_works(SFc6_euler_worksInstanceStruct
  *chartInstance)
{
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc6_euler_works(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c6_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c6_is_active_c6_euler_works = 0U;
}

static void initialize_params_c6_euler_works(SFc6_euler_worksInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void enable_c6_euler_works(SFc6_euler_worksInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c6_euler_works(SFc6_euler_worksInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c6_update_debugger_state_c6_euler_works
  (SFc6_euler_worksInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c6_euler_works
  (SFc6_euler_worksInstanceStruct *chartInstance)
{
  const mxArray *c6_st;
  const mxArray *c6_y = NULL;
  const mxArray *c6_b_y = NULL;
  uint8_T c6_hoistedGlobal;
  const mxArray *c6_c_y = NULL;
  c6_st = NULL;
  c6_st = NULL;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_createcellmatrix(2, 1), false);
  c6_b_y = NULL;
  sf_mex_assign(&c6_b_y, sf_mex_create("y", *chartInstance->c6_A_LN, 0, 0U, 1U,
    0U, 2, 3, 3), false);
  sf_mex_setcell(c6_y, 0, c6_b_y);
  c6_hoistedGlobal = chartInstance->c6_is_active_c6_euler_works;
  c6_c_y = NULL;
  sf_mex_assign(&c6_c_y, sf_mex_create("y", &c6_hoistedGlobal, 3, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c6_y, 1, c6_c_y);
  sf_mex_assign(&c6_st, c6_y, false);
  return c6_st;
}

static void set_sim_state_c6_euler_works(SFc6_euler_worksInstanceStruct
  *chartInstance, const mxArray *c6_st)
{
  const mxArray *c6_u;
  real_T c6_dv0[9];
  int32_T c6_i0;
  chartInstance->c6_doneDoubleBufferReInit = true;
  c6_u = sf_mex_dup(c6_st);
  c6_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c6_u, 0)), "A_LN",
                      c6_dv0);
  for (c6_i0 = 0; c6_i0 < 9; c6_i0++) {
    (*chartInstance->c6_A_LN)[c6_i0] = c6_dv0[c6_i0];
  }

  chartInstance->c6_is_active_c6_euler_works = c6_f_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c6_u, 1)),
     "is_active_c6_euler_works");
  sf_mex_destroy(&c6_u);
  c6_update_debugger_state_c6_euler_works(chartInstance);
  sf_mex_destroy(&c6_st);
}

static void finalize_c6_euler_works(SFc6_euler_worksInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c6_euler_works(SFc6_euler_worksInstanceStruct
  *chartInstance)
{
  int32_T c6_i1;
  int32_T c6_i2;
  int32_T c6_i3;
  int32_T c6_i4;
  real_T c6_b_xp[3];
  uint32_T c6_debug_family_var_map[8];
  real_T c6_b_xp_dot[3];
  real_T c6_r_1[3];
  real_T c6_r_2[3];
  real_T c6_r_3[3];
  real_T c6_c_xp[3];
  real_T c6_c_xp_dot[3];
  real_T c6_nargin = 2.0;
  real_T c6_nargout = 1.0;
  real_T c6_b_A_LN[9];
  int32_T c6_i5;
  int32_T c6_i6;
  int32_T c6_i7;
  int32_T c6_i8;
  int32_T c6_i9;
  real_T c6_a[3];
  int32_T c6_i10;
  real_T c6_b[3];
  int32_T c6_i11;
  real_T c6_b_a[3];
  real_T c6_c[3];
  real_T c6_b_b[3];
  real_T c6_y;
  real_T c6_scale;
  int32_T c6_k;
  real_T c6_absxk;
  real_T c6_t;
  int32_T c6_i12;
  int32_T c6_i13;
  int32_T c6_i14;
  int32_T c6_i15;
  int32_T c6_i16;
  int32_T c6_i17;
  int32_T c6_i18;
  int32_T c6_i19;
  int32_T c6_i20;
  int32_T c6_i21;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 5U, chartInstance->c6_sfEvent);
  for (c6_i1 = 0; c6_i1 < 3; c6_i1++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c6_xp_dot)[c6_i1], 1U);
  }

  for (c6_i2 = 0; c6_i2 < 3; c6_i2++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c6_xp)[c6_i2], 0U);
  }

  chartInstance->c6_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 5U, chartInstance->c6_sfEvent);
  for (c6_i3 = 0; c6_i3 < 3; c6_i3++) {
    c6_b_xp[c6_i3] = (*chartInstance->c6_xp)[c6_i3];
  }

  for (c6_i4 = 0; c6_i4 < 3; c6_i4++) {
    c6_b_xp_dot[c6_i4] = (*chartInstance->c6_xp_dot)[c6_i4];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 8U, 10U, c6_debug_family_names,
    c6_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_r_1, 0U, c6_d_sf_marshallOut,
    c6_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_r_2, 1U, c6_d_sf_marshallOut,
    c6_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_r_3, 2U, c6_d_sf_marshallOut,
    c6_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_c_xp, MAX_uint32_T,
    c6_d_sf_marshallOut, c6_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_c_xp_dot, MAX_uint32_T,
    c6_d_sf_marshallOut, c6_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargin, 5U, c6_c_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargout, 6U, c6_c_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c6_b_xp, 3U, c6_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c6_b_xp_dot, 4U, c6_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c6_b_A_LN, 7U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 3);
  for (c6_i5 = 0; c6_i5 < 3; c6_i5++) {
    c6_c_xp[c6_i5] = c6_b_xp[c6_i5];
  }

  _SFD_SYMBOL_SWITCH(3U, 3U);
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 4);
  for (c6_i6 = 0; c6_i6 < 3; c6_i6++) {
    c6_c_xp_dot[c6_i6] = c6_b_xp_dot[c6_i6];
  }

  _SFD_SYMBOL_SWITCH(4U, 4U);
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 6);
  for (c6_i7 = 0; c6_i7 < 3; c6_i7++) {
    c6_r_1[c6_i7] = c6_c_xp[c6_i7];
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 7);
  for (c6_i8 = 0; c6_i8 < 3; c6_i8++) {
    c6_a[c6_i8] = c6_c_xp_dot[c6_i8];
  }

  for (c6_i9 = 0; c6_i9 < 3; c6_i9++) {
    c6_b[c6_i9] = c6_c_xp[c6_i9];
  }

  for (c6_i10 = 0; c6_i10 < 3; c6_i10++) {
    c6_b_a[c6_i10] = c6_c_xp_dot[c6_i10];
  }

  for (c6_i11 = 0; c6_i11 < 3; c6_i11++) {
    c6_b_b[c6_i11] = c6_c_xp[c6_i11];
  }

  c6_c[0] = c6_b_a[1] * c6_b_b[2] - c6_b_a[2] * c6_b_b[1];
  c6_c[1] = c6_b_a[2] * c6_b_b[0] - c6_b_a[0] * c6_b_b[2];
  c6_c[2] = c6_b_a[0] * c6_b_b[1] - c6_b_a[1] * c6_b_b[0];
  c6_y = 0.0;
  c6_scale = 3.3121686421112381E-170;
  for (c6_k = 0; c6_k < 3; c6_k++) {
    c6_absxk = muDoubleScalarAbs(c6_c[c6_k]);
    if (c6_absxk > c6_scale) {
      c6_t = c6_scale / c6_absxk;
      c6_y = 1.0 + c6_y * c6_t * c6_t;
      c6_scale = c6_absxk;
    } else {
      c6_t = c6_absxk / c6_scale;
      c6_y += c6_t * c6_t;
    }
  }

  c6_y = c6_scale * muDoubleScalarSqrt(c6_y);
  c6_r_2[0] = (c6_a[1] * c6_b[2] - c6_a[2] * c6_b[1]) / c6_y;
  c6_r_2[1] = (c6_a[2] * c6_b[0] - c6_a[0] * c6_b[2]) / c6_y;
  c6_r_2[2] = (c6_a[0] * c6_b[1] - c6_a[1] * c6_b[0]) / c6_y;
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 8);
  for (c6_i12 = 0; c6_i12 < 3; c6_i12++) {
    c6_a[c6_i12] = c6_r_1[c6_i12];
  }

  for (c6_i13 = 0; c6_i13 < 3; c6_i13++) {
    c6_b[c6_i13] = c6_r_2[c6_i13];
  }

  c6_r_3[0] = c6_a[1] * c6_b[2] - c6_a[2] * c6_b[1];
  c6_r_3[1] = c6_a[2] * c6_b[0] - c6_a[0] * c6_b[2];
  c6_r_3[2] = c6_a[0] * c6_b[1] - c6_a[1] * c6_b[0];
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 10);
  c6_i14 = 0;
  for (c6_i15 = 0; c6_i15 < 3; c6_i15++) {
    c6_b_A_LN[c6_i14] = c6_r_1[c6_i15];
    c6_i14 += 3;
  }

  c6_i16 = 0;
  for (c6_i17 = 0; c6_i17 < 3; c6_i17++) {
    c6_b_A_LN[c6_i16 + 1] = c6_r_2[c6_i17];
    c6_i16 += 3;
  }

  c6_i18 = 0;
  for (c6_i19 = 0; c6_i19 < 3; c6_i19++) {
    c6_b_A_LN[c6_i18 + 2] = c6_r_3[c6_i19];
    c6_i18 += 3;
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, -10);
  _SFD_SYMBOL_SCOPE_POP();
  for (c6_i20 = 0; c6_i20 < 9; c6_i20++) {
    (*chartInstance->c6_A_LN)[c6_i20] = c6_b_A_LN[c6_i20];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c6_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_euler_worksMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c6_i21 = 0; c6_i21 < 9; c6_i21++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c6_A_LN)[c6_i21], 2U);
  }
}

static void mdl_start_c6_euler_works(SFc6_euler_worksInstanceStruct
  *chartInstance)
{
  sim_mode_is_external(chartInstance->S);
}

static void initSimStructsc6_euler_works(SFc6_euler_worksInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c6_machineNumber, uint32_T
  c6_chartNumber, uint32_T c6_instanceNumber)
{
  (void)(c6_machineNumber);
  (void)(c6_chartNumber);
  (void)(c6_instanceNumber);
}

static const mxArray *c6_sf_marshallOut(void *chartInstanceVoid, void *c6_inData)
{
  const mxArray *c6_mxArrayOutData;
  int32_T c6_i22;
  int32_T c6_i23;
  const mxArray *c6_y = NULL;
  int32_T c6_i24;
  real_T c6_u[9];
  SFc6_euler_worksInstanceStruct *chartInstance;
  chartInstance = (SFc6_euler_worksInstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_mxArrayOutData = NULL;
  c6_i22 = 0;
  for (c6_i23 = 0; c6_i23 < 3; c6_i23++) {
    for (c6_i24 = 0; c6_i24 < 3; c6_i24++) {
      c6_u[c6_i24 + c6_i22] = (*(real_T (*)[9])c6_inData)[c6_i24 + c6_i22];
    }

    c6_i22 += 3;
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 2, 3, 3), false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static void c6_emlrt_marshallIn(SFc6_euler_worksInstanceStruct *chartInstance,
  const mxArray *c6_b_A_LN, const char_T *c6_identifier, real_T c6_y[9])
{
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = (const char *)c6_identifier;
  c6_thisId.fParent = NULL;
  c6_thisId.bParentIsCell = false;
  c6_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_A_LN), &c6_thisId, c6_y);
  sf_mex_destroy(&c6_b_A_LN);
}

static void c6_b_emlrt_marshallIn(SFc6_euler_worksInstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId, real_T c6_y[9])
{
  real_T c6_dv1[9];
  int32_T c6_i25;
  (void)chartInstance;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), c6_dv1, 1, 0, 0U, 1, 0U, 2, 3, 3);
  for (c6_i25 = 0; c6_i25 < 9; c6_i25++) {
    c6_y[c6_i25] = c6_dv1[c6_i25];
  }

  sf_mex_destroy(&c6_u);
}

static void c6_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_b_A_LN;
  emlrtMsgIdentifier c6_thisId;
  real_T c6_y[9];
  int32_T c6_i26;
  int32_T c6_i27;
  int32_T c6_i28;
  SFc6_euler_worksInstanceStruct *chartInstance;
  chartInstance = (SFc6_euler_worksInstanceStruct *)chartInstanceVoid;
  c6_b_A_LN = sf_mex_dup(c6_mxArrayInData);
  c6_thisId.fIdentifier = (const char *)c6_varName;
  c6_thisId.fParent = NULL;
  c6_thisId.bParentIsCell = false;
  c6_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_A_LN), &c6_thisId, c6_y);
  sf_mex_destroy(&c6_b_A_LN);
  c6_i26 = 0;
  for (c6_i27 = 0; c6_i27 < 3; c6_i27++) {
    for (c6_i28 = 0; c6_i28 < 3; c6_i28++) {
      (*(real_T (*)[9])c6_outData)[c6_i28 + c6_i26] = c6_y[c6_i28 + c6_i26];
    }

    c6_i26 += 3;
  }

  sf_mex_destroy(&c6_mxArrayInData);
}

static const mxArray *c6_b_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData;
  int32_T c6_i29;
  const mxArray *c6_y = NULL;
  real_T c6_u[3];
  SFc6_euler_worksInstanceStruct *chartInstance;
  chartInstance = (SFc6_euler_worksInstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_mxArrayOutData = NULL;
  for (c6_i29 = 0; c6_i29 < 3; c6_i29++) {
    c6_u[c6_i29] = (*(real_T (*)[3])c6_inData)[c6_i29];
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 1, 3), false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static const mxArray *c6_c_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData;
  real_T c6_u;
  const mxArray *c6_y = NULL;
  SFc6_euler_worksInstanceStruct *chartInstance;
  chartInstance = (SFc6_euler_worksInstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_mxArrayOutData = NULL;
  c6_u = *(real_T *)c6_inData;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static real_T c6_c_emlrt_marshallIn(SFc6_euler_worksInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  real_T c6_y;
  real_T c6_d0;
  (void)chartInstance;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_d0, 1, 0, 0U, 0, 0U, 0);
  c6_y = c6_d0;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void c6_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_nargout;
  emlrtMsgIdentifier c6_thisId;
  real_T c6_y;
  SFc6_euler_worksInstanceStruct *chartInstance;
  chartInstance = (SFc6_euler_worksInstanceStruct *)chartInstanceVoid;
  c6_nargout = sf_mex_dup(c6_mxArrayInData);
  c6_thisId.fIdentifier = (const char *)c6_varName;
  c6_thisId.fParent = NULL;
  c6_thisId.bParentIsCell = false;
  c6_y = c6_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_nargout), &c6_thisId);
  sf_mex_destroy(&c6_nargout);
  *(real_T *)c6_outData = c6_y;
  sf_mex_destroy(&c6_mxArrayInData);
}

static const mxArray *c6_d_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData;
  int32_T c6_i30;
  const mxArray *c6_y = NULL;
  real_T c6_u[3];
  SFc6_euler_worksInstanceStruct *chartInstance;
  chartInstance = (SFc6_euler_worksInstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_mxArrayOutData = NULL;
  for (c6_i30 = 0; c6_i30 < 3; c6_i30++) {
    c6_u[c6_i30] = (*(real_T (*)[3])c6_inData)[c6_i30];
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 2, 1, 3), false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static void c6_d_emlrt_marshallIn(SFc6_euler_worksInstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId, real_T c6_y[3])
{
  real_T c6_dv2[3];
  int32_T c6_i31;
  (void)chartInstance;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), c6_dv2, 1, 0, 0U, 1, 0U, 2, 1, 3);
  for (c6_i31 = 0; c6_i31 < 3; c6_i31++) {
    c6_y[c6_i31] = c6_dv2[c6_i31];
  }

  sf_mex_destroy(&c6_u);
}

static void c6_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_b_xp_dot;
  emlrtMsgIdentifier c6_thisId;
  real_T c6_y[3];
  int32_T c6_i32;
  SFc6_euler_worksInstanceStruct *chartInstance;
  chartInstance = (SFc6_euler_worksInstanceStruct *)chartInstanceVoid;
  c6_b_xp_dot = sf_mex_dup(c6_mxArrayInData);
  c6_thisId.fIdentifier = (const char *)c6_varName;
  c6_thisId.fParent = NULL;
  c6_thisId.bParentIsCell = false;
  c6_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_xp_dot), &c6_thisId, c6_y);
  sf_mex_destroy(&c6_b_xp_dot);
  for (c6_i32 = 0; c6_i32 < 3; c6_i32++) {
    (*(real_T (*)[3])c6_outData)[c6_i32] = c6_y[c6_i32];
  }

  sf_mex_destroy(&c6_mxArrayInData);
}

const mxArray *sf_c6_euler_works_get_eml_resolved_functions_info(void)
{
  const mxArray *c6_nameCaptureInfo = NULL;
  c6_nameCaptureInfo = NULL;
  sf_mex_assign(&c6_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c6_nameCaptureInfo;
}

static const mxArray *c6_e_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData;
  int32_T c6_u;
  const mxArray *c6_y = NULL;
  SFc6_euler_worksInstanceStruct *chartInstance;
  chartInstance = (SFc6_euler_worksInstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_mxArrayOutData = NULL;
  c6_u = *(int32_T *)c6_inData;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static int32_T c6_e_emlrt_marshallIn(SFc6_euler_worksInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  int32_T c6_y;
  int32_T c6_i33;
  (void)chartInstance;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_i33, 1, 6, 0U, 0, 0U, 0);
  c6_y = c6_i33;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void c6_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_b_sfEvent;
  emlrtMsgIdentifier c6_thisId;
  int32_T c6_y;
  SFc6_euler_worksInstanceStruct *chartInstance;
  chartInstance = (SFc6_euler_worksInstanceStruct *)chartInstanceVoid;
  c6_b_sfEvent = sf_mex_dup(c6_mxArrayInData);
  c6_thisId.fIdentifier = (const char *)c6_varName;
  c6_thisId.fParent = NULL;
  c6_thisId.bParentIsCell = false;
  c6_y = c6_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_sfEvent),
    &c6_thisId);
  sf_mex_destroy(&c6_b_sfEvent);
  *(int32_T *)c6_outData = c6_y;
  sf_mex_destroy(&c6_mxArrayInData);
}

static uint8_T c6_f_emlrt_marshallIn(SFc6_euler_worksInstanceStruct
  *chartInstance, const mxArray *c6_b_is_active_c6_euler_works, const char_T
  *c6_identifier)
{
  uint8_T c6_y;
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = (const char *)c6_identifier;
  c6_thisId.fParent = NULL;
  c6_thisId.bParentIsCell = false;
  c6_y = c6_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c6_b_is_active_c6_euler_works), &c6_thisId);
  sf_mex_destroy(&c6_b_is_active_c6_euler_works);
  return c6_y;
}

static uint8_T c6_g_emlrt_marshallIn(SFc6_euler_worksInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  uint8_T c6_y;
  uint8_T c6_u0;
  (void)chartInstance;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_u0, 1, 3, 0U, 0, 0U, 0);
  c6_y = c6_u0;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void init_dsm_address_info(SFc6_euler_worksInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc6_euler_worksInstanceStruct
  *chartInstance)
{
  chartInstance->c6_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c6_xp = (real_T (*)[3])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c6_A_LN = (real_T (*)[9])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c6_xp_dot = (real_T (*)[3])ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c6_euler_works_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(731272410U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2910091875U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1729422777U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1844353092U);
}

mxArray* sf_c6_euler_works_get_post_codegen_info(void);
mxArray *sf_c6_euler_works_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("zc3tGCOiDOq8S3XyZBvXX");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,1,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,1,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(3);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo = sf_c6_euler_works_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c6_euler_works_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c6_euler_works_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("pre");
  mxArray *fallbackReason = mxCreateString("hasBreakpoints");
  mxArray *hiddenFallbackType = mxCreateString("none");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c6_euler_works_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c6_euler_works_get_post_codegen_info(void)
{
  const char* fieldNames[] = { "exportedFunctionsUsedByThisChart",
    "exportedFunctionsChecksum" };

  mwSize dims[2] = { 1, 1 };

  mxArray* mxPostCodegenInfo = mxCreateStructArray(2, dims, sizeof(fieldNames)/
    sizeof(fieldNames[0]), fieldNames);

  {
    mxArray* mxExportedFunctionsChecksum = mxCreateString("");
    mwSize exp_dims[2] = { 0, 1 };

    mxArray* mxExportedFunctionsUsedByThisChart = mxCreateCellArray(2, exp_dims);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsUsedByThisChart",
               mxExportedFunctionsUsedByThisChart);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsChecksum",
               mxExportedFunctionsChecksum);
  }

  return mxPostCodegenInfo;
}

static const mxArray *sf_get_sim_state_info_c6_euler_works(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"A_LN\",},{M[8],M[0],T\"is_active_c6_euler_works\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c6_euler_works_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc6_euler_worksInstanceStruct *chartInstance =
      (SFc6_euler_worksInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _euler_worksMachineNumber_,
           6,
           1,
           1,
           0,
           3,
           0,
           0,
           0,
           0,
           0,
           &chartInstance->chartNumber,
           &chartInstance->instanceNumber,
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation(_euler_worksMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_euler_worksMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _euler_worksMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"xp");
          _SFD_SET_DATA_PROPS(1,1,1,0,"xp_dot");
          _SFD_SET_DATA_PROPS(2,2,0,1,"A_LN");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,182);

        {
          unsigned int dimVector[1];
          dimVector[0]= 3U;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c6_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3U;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c6_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3U;
          dimVector[1]= 3U;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)
            c6_sf_marshallIn);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _euler_worksMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static void chart_debug_initialize_data_addresses(SimStruct *S)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc6_euler_worksInstanceStruct *chartInstance =
      (SFc6_euler_worksInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(0U, (void *)chartInstance->c6_xp);
        _SFD_SET_DATA_VALUE_PTR(2U, (void *)chartInstance->c6_A_LN);
        _SFD_SET_DATA_VALUE_PTR(1U, (void *)chartInstance->c6_xp_dot);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "sbHJ3Ccdvym9IDWOIuzWzvB";
}

static void sf_opaque_initialize_c6_euler_works(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc6_euler_worksInstanceStruct*) chartInstanceVar)
    ->S,0);
  initialize_params_c6_euler_works((SFc6_euler_worksInstanceStruct*)
    chartInstanceVar);
  initialize_c6_euler_works((SFc6_euler_worksInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c6_euler_works(void *chartInstanceVar)
{
  enable_c6_euler_works((SFc6_euler_worksInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c6_euler_works(void *chartInstanceVar)
{
  disable_c6_euler_works((SFc6_euler_worksInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c6_euler_works(void *chartInstanceVar)
{
  sf_gateway_c6_euler_works((SFc6_euler_worksInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c6_euler_works(SimStruct* S)
{
  return get_sim_state_c6_euler_works((SFc6_euler_worksInstanceStruct *)
    sf_get_chart_instance_ptr(S));     /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c6_euler_works(SimStruct* S, const mxArray
  *st)
{
  set_sim_state_c6_euler_works((SFc6_euler_worksInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_terminate_c6_euler_works(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc6_euler_worksInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_euler_works_optimization_info();
    }

    finalize_c6_euler_works((SFc6_euler_worksInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc6_euler_works((SFc6_euler_worksInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c6_euler_works(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c6_euler_works((SFc6_euler_worksInstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

static void mdlSetWorkWidths_c6_euler_works(SimStruct *S)
{
  /* Set overwritable ports for inplace optimization */
  ssSetInputPortDirectFeedThrough(S, 0, 1);
  ssSetInputPortDirectFeedThrough(S, 1, 1);
  ssSetStatesModifiedOnlyInUpdate(S, 1);
  ssSetBlockIsPurelyCombinatorial_wrapper(S, 1);
  ssMdlUpdateIsEmpty(S, 1);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_euler_works_optimization_info(sim_mode_is_rtw_gen
      (S), sim_mode_is_modelref_sim(S), sim_mode_is_external(S));
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,6);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,1);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,6,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_set_chart_accesses_machine_info(S, sf_get_instance_specialization(),
      infoStruct, 6);
    sf_update_buildInfo(S, sf_get_instance_specialization(),infoStruct,6);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,6,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,6,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 2; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,6);
    sf_register_codegen_names_for_scoped_functions_defined_by_chart(S);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1905245322U));
  ssSetChecksum1(S,(3367768184U));
  ssSetChecksum2(S,(3667008541U));
  ssSetChecksum3(S,(4283878881U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSetStateSemanticsClassicAndSynchronous(S, true);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c6_euler_works(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c6_euler_works(SimStruct *S)
{
  SFc6_euler_worksInstanceStruct *chartInstance;
  chartInstance = (SFc6_euler_worksInstanceStruct *)utMalloc(sizeof
    (SFc6_euler_worksInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc6_euler_worksInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c6_euler_works;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c6_euler_works;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c6_euler_works;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c6_euler_works;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c6_euler_works;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c6_euler_works;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c6_euler_works;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c6_euler_works;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c6_euler_works;
  chartInstance->chartInfo.mdlStart = mdlStart_c6_euler_works;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c6_euler_works;
  chartInstance->chartInfo.callGetHoverDataForMsg = NULL;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.debugInstance = sfGlobalDebugInstanceStruct;
  chartInstance->S = S;
  sf_init_ChartRunTimeInfo(S, &(chartInstance->chartInfo), false, 0);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  chart_debug_initialization(S,1);
  mdl_start_c6_euler_works(chartInstance);
}

void c6_euler_works_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c6_euler_works(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c6_euler_works(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c6_euler_works(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c6_euler_works_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
