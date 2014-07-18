/* Include files */

#include <stddef.h>
#include "blas.h"
#include "RaspPiPilot_sfun.h"
#include "c8_RaspPiPilot.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "RaspPiPilot_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c8_debug_family_names[6] = { "nargin", "nargout", "R", "G",
  "B", "redIntensity" };

/* Function Declarations */
static void initialize_c8_RaspPiPilot(SFc8_RaspPiPilotInstanceStruct
  *chartInstance);
static void initialize_params_c8_RaspPiPilot(SFc8_RaspPiPilotInstanceStruct
  *chartInstance);
static void enable_c8_RaspPiPilot(SFc8_RaspPiPilotInstanceStruct *chartInstance);
static void disable_c8_RaspPiPilot(SFc8_RaspPiPilotInstanceStruct *chartInstance);
static void c8_update_debugger_state_c8_RaspPiPilot
  (SFc8_RaspPiPilotInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c8_RaspPiPilot
  (SFc8_RaspPiPilotInstanceStruct *chartInstance);
static void set_sim_state_c8_RaspPiPilot(SFc8_RaspPiPilotInstanceStruct
  *chartInstance, const mxArray *c8_st);
static void finalize_c8_RaspPiPilot(SFc8_RaspPiPilotInstanceStruct
  *chartInstance);
static void sf_gateway_c8_RaspPiPilot(SFc8_RaspPiPilotInstanceStruct
  *chartInstance);
static void c8_chartstep_c8_RaspPiPilot(SFc8_RaspPiPilotInstanceStruct
  *chartInstance);
static void initSimStructsc8_RaspPiPilot(SFc8_RaspPiPilotInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c8_machineNumber, uint32_T
  c8_chartNumber, uint32_T c8_instanceNumber);
static const mxArray *c8_sf_marshallOut(void *chartInstanceVoid, uint8_T
  c8_inData_data[], int32_T c8_inData_sizes[2]);
static void c8_emlrt_marshallIn(SFc8_RaspPiPilotInstanceStruct *chartInstance,
  const mxArray *c8_redIntensity, const char_T *c8_identifier, uint8_T
  c8_y_data[], int32_T c8_y_sizes[2]);
static void c8_b_emlrt_marshallIn(SFc8_RaspPiPilotInstanceStruct *chartInstance,
  const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId, uint8_T c8_y_data[],
  int32_T c8_y_sizes[2]);
static void c8_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, uint8_T c8_outData_data[],
  int32_T c8_outData_sizes[2]);
static const mxArray *c8_b_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static real_T c8_c_emlrt_marshallIn(SFc8_RaspPiPilotInstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId);
static void c8_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static void c8_info_helper(const mxArray **c8_info);
static const mxArray *c8_emlrt_marshallOut(const char * c8_u);
static const mxArray *c8_b_emlrt_marshallOut(const uint32_T c8_u);
static void c8_scalexpAlloc(SFc8_RaspPiPilotInstanceStruct *chartInstance,
  uint8_T c8_varargin_1_data[], int32_T c8_varargin_1_sizes[2], uint8_T
  c8_z_data[], int32_T c8_z_sizes[2]);
static const mxArray *c8_c_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static int32_T c8_d_emlrt_marshallIn(SFc8_RaspPiPilotInstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId);
static void c8_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static uint8_T c8_e_emlrt_marshallIn(SFc8_RaspPiPilotInstanceStruct
  *chartInstance, const mxArray *c8_b_is_active_c8_RaspPiPilot, const char_T
  *c8_identifier);
static uint8_T c8_f_emlrt_marshallIn(SFc8_RaspPiPilotInstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId);
static void init_dsm_address_info(SFc8_RaspPiPilotInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c8_RaspPiPilot(SFc8_RaspPiPilotInstanceStruct
  *chartInstance)
{
  chartInstance->c8_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c8_is_active_c8_RaspPiPilot = 0U;
}

static void initialize_params_c8_RaspPiPilot(SFc8_RaspPiPilotInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void enable_c8_RaspPiPilot(SFc8_RaspPiPilotInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c8_RaspPiPilot(SFc8_RaspPiPilotInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c8_update_debugger_state_c8_RaspPiPilot
  (SFc8_RaspPiPilotInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c8_RaspPiPilot
  (SFc8_RaspPiPilotInstanceStruct *chartInstance)
{
  const mxArray *c8_st;
  const mxArray *c8_y = NULL;
  int32_T c8_u_sizes[2];
  int32_T c8_u;
  int32_T c8_b_u;
  int32_T c8_loop_ub;
  int32_T c8_i0;
  uint8_T c8_u_data[76800];
  const mxArray *c8_b_y = NULL;
  uint8_T c8_hoistedGlobal;
  uint8_T c8_c_u;
  const mxArray *c8_c_y = NULL;
  int32_T (*c8_redIntensity_sizes)[2];
  uint8_T (*c8_redIntensity_data)[76800];
  c8_redIntensity_sizes = (int32_T (*)[2])
    ssGetCurrentOutputPortDimensions_wrapper(chartInstance->S, 1);
  c8_redIntensity_data = (uint8_T (*)[76800])ssGetOutputPortSignal
    (chartInstance->S, 1);
  c8_st = NULL;
  c8_st = NULL;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_createcellmatrix(2, 1), false);
  c8_u_sizes[0] = (*c8_redIntensity_sizes)[0];
  c8_u_sizes[1] = (*c8_redIntensity_sizes)[1];
  c8_u = c8_u_sizes[0];
  c8_b_u = c8_u_sizes[1];
  c8_loop_ub = (*c8_redIntensity_sizes)[0] * (*c8_redIntensity_sizes)[1] - 1;
  for (c8_i0 = 0; c8_i0 <= c8_loop_ub; c8_i0++) {
    c8_u_data[c8_i0] = (*c8_redIntensity_data)[c8_i0];
  }

  c8_b_y = NULL;
  sf_mex_assign(&c8_b_y, sf_mex_create("y", c8_u_data, 3, 0U, 1U, 0U, 2,
    c8_u_sizes[0], c8_u_sizes[1]), false);
  sf_mex_setcell(c8_y, 0, c8_b_y);
  c8_hoistedGlobal = chartInstance->c8_is_active_c8_RaspPiPilot;
  c8_c_u = c8_hoistedGlobal;
  c8_c_y = NULL;
  sf_mex_assign(&c8_c_y, sf_mex_create("y", &c8_c_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c8_y, 1, c8_c_y);
  sf_mex_assign(&c8_st, c8_y, false);
  return c8_st;
}

static void set_sim_state_c8_RaspPiPilot(SFc8_RaspPiPilotInstanceStruct
  *chartInstance, const mxArray *c8_st)
{
  const mxArray *c8_u;
  int32_T c8_tmp_sizes[2];
  uint8_T c8_tmp_data[76800];
  int32_T c8_i1;
  int32_T c8_i2;
  int32_T c8_loop_ub;
  int32_T c8_i3;
  uint8_T (*c8_redIntensity_data)[76800];
  int32_T (*c8_redIntensity_sizes)[2];
  c8_redIntensity_sizes = (int32_T (*)[2])
    ssGetCurrentOutputPortDimensions_wrapper(chartInstance->S, 1);
  c8_redIntensity_data = (uint8_T (*)[76800])ssGetOutputPortSignal
    (chartInstance->S, 1);
  chartInstance->c8_doneDoubleBufferReInit = true;
  c8_u = sf_mex_dup(c8_st);
  c8_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c8_u, 0)),
                      "redIntensity", c8_tmp_data, c8_tmp_sizes);
  ssSetCurrentOutputPortDimensions(chartInstance->S, 1, 0, c8_tmp_sizes[0]);
  ssSetCurrentOutputPortDimensions(chartInstance->S, 1, 1, c8_tmp_sizes[1]);
  c8_i1 = (*c8_redIntensity_sizes)[0];
  c8_i2 = (*c8_redIntensity_sizes)[1];
  c8_loop_ub = c8_tmp_sizes[0] * c8_tmp_sizes[1] - 1;
  for (c8_i3 = 0; c8_i3 <= c8_loop_ub; c8_i3++) {
    (*c8_redIntensity_data)[c8_i3] = c8_tmp_data[c8_i3];
  }

  chartInstance->c8_is_active_c8_RaspPiPilot = c8_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c8_u, 1)),
     "is_active_c8_RaspPiPilot");
  sf_mex_destroy(&c8_u);
  c8_update_debugger_state_c8_RaspPiPilot(chartInstance);
  sf_mex_destroy(&c8_st);
}

static void finalize_c8_RaspPiPilot(SFc8_RaspPiPilotInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c8_RaspPiPilot(SFc8_RaspPiPilotInstanceStruct
  *chartInstance)
{
  int32_T c8_loop_ub;
  int32_T c8_i4;
  int32_T c8_b_loop_ub;
  int32_T c8_i5;
  int32_T c8_c_loop_ub;
  int32_T c8_i6;
  int32_T c8_d_loop_ub;
  int32_T c8_i7;
  int32_T (*c8_R_sizes)[2];
  int32_T (*c8_redIntensity_sizes)[2];
  int32_T (*c8_G_sizes)[2];
  int32_T (*c8_B_sizes)[2];
  uint8_T (*c8_B_data)[76800];
  uint8_T (*c8_G_data)[76800];
  uint8_T (*c8_redIntensity_data)[76800];
  uint8_T (*c8_R_data)[76800];
  c8_B_sizes = (int32_T (*)[2])ssGetCurrentInputPortDimensions_wrapper
    (chartInstance->S, 2);
  c8_B_data = (uint8_T (*)[76800])ssGetInputPortSignal(chartInstance->S, 2);
  c8_G_sizes = (int32_T (*)[2])ssGetCurrentInputPortDimensions_wrapper
    (chartInstance->S, 1);
  c8_G_data = (uint8_T (*)[76800])ssGetInputPortSignal(chartInstance->S, 1);
  c8_redIntensity_sizes = (int32_T (*)[2])
    ssGetCurrentOutputPortDimensions_wrapper(chartInstance->S, 1);
  c8_redIntensity_data = (uint8_T (*)[76800])ssGetOutputPortSignal
    (chartInstance->S, 1);
  c8_R_sizes = (int32_T (*)[2])ssGetCurrentInputPortDimensions_wrapper
    (chartInstance->S, 0);
  c8_R_data = (uint8_T (*)[76800])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 7U, chartInstance->c8_sfEvent);
  c8_loop_ub = (*c8_R_sizes)[0] * (*c8_R_sizes)[1] - 1;
  for (c8_i4 = 0; c8_i4 <= c8_loop_ub; c8_i4++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c8_R_data)[c8_i4], 0U);
  }

  chartInstance->c8_sfEvent = CALL_EVENT;
  c8_chartstep_c8_RaspPiPilot(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_RaspPiPilotMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  c8_b_loop_ub = (*c8_redIntensity_sizes)[0] * (*c8_redIntensity_sizes)[1] - 1;
  for (c8_i5 = 0; c8_i5 <= c8_b_loop_ub; c8_i5++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c8_redIntensity_data)[c8_i5], 1U);
  }

  c8_c_loop_ub = (*c8_G_sizes)[0] * (*c8_G_sizes)[1] - 1;
  for (c8_i6 = 0; c8_i6 <= c8_c_loop_ub; c8_i6++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c8_G_data)[c8_i6], 2U);
  }

  c8_d_loop_ub = (*c8_B_sizes)[0] * (*c8_B_sizes)[1] - 1;
  for (c8_i7 = 0; c8_i7 <= c8_d_loop_ub; c8_i7++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c8_B_data)[c8_i7], 3U);
  }
}

static void c8_chartstep_c8_RaspPiPilot(SFc8_RaspPiPilotInstanceStruct
  *chartInstance)
{
  int32_T c8_R_sizes[2];
  int32_T c8_R;
  int32_T c8_b_R;
  int32_T c8_loop_ub;
  int32_T c8_i8;
  static uint8_T c8_R_data[76800];
  int32_T c8_G_sizes[2];
  int32_T c8_G;
  int32_T c8_b_G;
  int32_T c8_b_loop_ub;
  int32_T c8_i9;
  static uint8_T c8_G_data[76800];
  int32_T c8_B_sizes[2];
  int32_T c8_B;
  int32_T c8_b_B;
  int32_T c8_c_loop_ub;
  int32_T c8_i10;
  static uint8_T c8_B_data[76800];
  uint32_T c8_debug_family_var_map[6];
  real_T c8_nargin = 3.0;
  real_T c8_nargout = 1.0;
  int32_T c8_redIntensity_sizes[2];
  static uint8_T c8_redIntensity_data[76800];
  int32_T c8_A_sizes[2];
  int32_T c8_A;
  int32_T c8_b_A;
  int32_T c8_d_loop_ub;
  int32_T c8_i11;
  static uint8_T c8_A_data[76800];
  int32_T c8_b_A_sizes[2];
  int32_T c8_c_A;
  int32_T c8_d_A;
  int32_T c8_e_loop_ub;
  int32_T c8_i12;
  static uint8_T c8_b_A_data[76800];
  int32_T c8_tmp_sizes[2];
  static uint8_T c8_tmp_data[76800];
  real_T c8_d0;
  int32_T c8_i13;
  int32_T c8_k;
  real_T c8_b_k;
  real_T c8_xk;
  real_T c8_d1;
  uint8_T c8_u0;
  int32_T c8_i14;
  int32_T c8_c_R[2];
  int32_T c8_i15;
  int32_T c8_iv0[2];
  int32_T c8_e_A;
  int32_T c8_f_A;
  int32_T c8_f_loop_ub;
  int32_T c8_i16;
  int32_T c8_c_A_sizes[2];
  int32_T c8_g_A;
  int32_T c8_h_A;
  int32_T c8_g_loop_ub;
  int32_T c8_i17;
  static uint8_T c8_c_A_data[76800];
  int32_T c8_b_tmp_sizes[2];
  uint8_T c8_b_tmp_data[76800];
  real_T c8_d2;
  int32_T c8_i18;
  int32_T c8_c_k;
  real_T c8_d_k;
  real_T c8_b_xk;
  real_T c8_d3;
  uint8_T c8_u1;
  int32_T c8_i19;
  int32_T c8_iv1[2];
  int32_T c8_i20;
  int32_T c8_iv2[2];
  int32_T c8_redIntensity;
  int32_T c8_b_redIntensity;
  int32_T c8_h_loop_ub;
  int32_T c8_i21;
  uint32_T c8_q0;
  uint32_T c8_qY;
  uint32_T c8_u2;
  uint32_T c8_b_q0;
  uint32_T c8_b_qY;
  uint32_T c8_u3;
  int32_T c8_i22;
  int32_T c8_i23;
  int32_T c8_i_loop_ub;
  int32_T c8_i24;
  uint8_T (*c8_b_redIntensity_data)[76800];
  int32_T (*c8_b_R_sizes)[2];
  int32_T (*c8_b_G_sizes)[2];
  int32_T (*c8_b_B_sizes)[2];
  int32_T (*c8_b_redIntensity_sizes)[2];
  uint8_T (*c8_b_B_data)[76800];
  uint8_T (*c8_b_G_data)[76800];
  uint8_T (*c8_b_R_data)[76800];
  c8_b_B_sizes = (int32_T (*)[2])ssGetCurrentInputPortDimensions_wrapper
    (chartInstance->S, 2);
  c8_b_B_data = (uint8_T (*)[76800])ssGetInputPortSignal(chartInstance->S, 2);
  c8_b_G_sizes = (int32_T (*)[2])ssGetCurrentInputPortDimensions_wrapper
    (chartInstance->S, 1);
  c8_b_G_data = (uint8_T (*)[76800])ssGetInputPortSignal(chartInstance->S, 1);
  c8_b_redIntensity_sizes = (int32_T (*)[2])
    ssGetCurrentOutputPortDimensions_wrapper(chartInstance->S, 1);
  c8_b_redIntensity_data = (uint8_T (*)[76800])ssGetOutputPortSignal
    (chartInstance->S, 1);
  c8_b_R_sizes = (int32_T (*)[2])ssGetCurrentInputPortDimensions_wrapper
    (chartInstance->S, 0);
  c8_b_R_data = (uint8_T (*)[76800])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 7U, chartInstance->c8_sfEvent);
  c8_R_sizes[0] = (*c8_b_R_sizes)[0];
  c8_R_sizes[1] = (*c8_b_R_sizes)[1];
  c8_R = c8_R_sizes[0];
  c8_b_R = c8_R_sizes[1];
  c8_loop_ub = (*c8_b_R_sizes)[0] * (*c8_b_R_sizes)[1] - 1;
  for (c8_i8 = 0; c8_i8 <= c8_loop_ub; c8_i8++) {
    c8_R_data[c8_i8] = (*c8_b_R_data)[c8_i8];
  }

  c8_G_sizes[0] = (*c8_b_G_sizes)[0];
  c8_G_sizes[1] = (*c8_b_G_sizes)[1];
  c8_G = c8_G_sizes[0];
  c8_b_G = c8_G_sizes[1];
  c8_b_loop_ub = (*c8_b_G_sizes)[0] * (*c8_b_G_sizes)[1] - 1;
  for (c8_i9 = 0; c8_i9 <= c8_b_loop_ub; c8_i9++) {
    c8_G_data[c8_i9] = (*c8_b_G_data)[c8_i9];
  }

  c8_B_sizes[0] = (*c8_b_B_sizes)[0];
  c8_B_sizes[1] = (*c8_b_B_sizes)[1];
  c8_B = c8_B_sizes[0];
  c8_b_B = c8_B_sizes[1];
  c8_c_loop_ub = (*c8_b_B_sizes)[0] * (*c8_b_B_sizes)[1] - 1;
  for (c8_i10 = 0; c8_i10 <= c8_c_loop_ub; c8_i10++) {
    c8_B_data[c8_i10] = (*c8_b_B_data)[c8_i10];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 6U, 6U, c8_debug_family_names,
    c8_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 0U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 1U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN(c8_R_data, (const int32_T *)&c8_R_sizes, NULL, 1,
    2, (void *)c8_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN(c8_G_data, (const int32_T *)&c8_G_sizes, NULL, 1,
    3, (void *)c8_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN(c8_B_data, (const int32_T *)&c8_B_sizes, NULL, 1,
    4, (void *)c8_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_IMPORTABLE(c8_redIntensity_data, (const int32_T *)
    &c8_redIntensity_sizes, NULL, 0, 5, (void *)c8_sf_marshallOut, (void *)
    c8_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 3);
  c8_A_sizes[0] = c8_G_sizes[0];
  c8_A_sizes[1] = c8_G_sizes[1];
  c8_A = c8_A_sizes[0];
  c8_b_A = c8_A_sizes[1];
  c8_d_loop_ub = c8_G_sizes[0] * c8_G_sizes[1] - 1;
  for (c8_i11 = 0; c8_i11 <= c8_d_loop_ub; c8_i11++) {
    c8_A_data[c8_i11] = c8_G_data[c8_i11];
  }

  c8_b_A_sizes[0] = c8_A_sizes[0];
  c8_b_A_sizes[1] = c8_A_sizes[1];
  c8_c_A = c8_b_A_sizes[0];
  c8_d_A = c8_b_A_sizes[1];
  c8_e_loop_ub = c8_A_sizes[0] * c8_A_sizes[1] - 1;
  for (c8_i12 = 0; c8_i12 <= c8_e_loop_ub; c8_i12++) {
    c8_b_A_data[c8_i12] = c8_A_data[c8_i12];
  }

  c8_scalexpAlloc(chartInstance, c8_b_A_data, c8_b_A_sizes, c8_tmp_data,
                  c8_tmp_sizes);
  c8_d0 = (real_T)(c8_tmp_sizes[0] * c8_tmp_sizes[1]);
  c8_i13 = (int32_T)c8_d0 - 1;
  for (c8_k = 0; c8_k <= c8_i13; c8_k++) {
    c8_b_k = 1.0 + (real_T)c8_k;
    c8_xk = (real_T)c8_A_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)c8_b_k, 1,
      c8_A_sizes[0] * c8_A_sizes[1], 1, 0) - 1];
    c8_d1 = muDoubleScalarRound(c8_xk / 2.0);
    if (c8_d1 < 256.0) {
      if (CV_SATURATION_EVAL(4, 0, 2, 1, c8_d1 >= 0.0)) {
        c8_u0 = (uint8_T)c8_d1;
      } else {
        c8_u0 = 0U;
      }
    } else if (CV_SATURATION_EVAL(4, 0, 2, 0, c8_d1 >= 256.0)) {
      c8_u0 = MAX_uint8_T;
    } else {
      c8_u0 = 0U;
    }

    c8_tmp_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)c8_b_k, 1,
      c8_tmp_sizes[0] * c8_tmp_sizes[1], 1, 0) - 1] = c8_u0;
  }

  for (c8_i14 = 0; c8_i14 < 2; c8_i14++) {
    c8_c_R[c8_i14] = c8_R_sizes[c8_i14];
  }

  for (c8_i15 = 0; c8_i15 < 2; c8_i15++) {
    c8_iv0[c8_i15] = c8_tmp_sizes[c8_i15];
  }

  _SFD_SIZE_EQ_CHECK_ND(c8_c_R, c8_iv0, 2);
  c8_A_sizes[0] = c8_B_sizes[0];
  c8_A_sizes[1] = c8_B_sizes[1];
  c8_e_A = c8_A_sizes[0];
  c8_f_A = c8_A_sizes[1];
  c8_f_loop_ub = c8_B_sizes[0] * c8_B_sizes[1] - 1;
  for (c8_i16 = 0; c8_i16 <= c8_f_loop_ub; c8_i16++) {
    c8_A_data[c8_i16] = c8_B_data[c8_i16];
  }

  c8_c_A_sizes[0] = c8_A_sizes[0];
  c8_c_A_sizes[1] = c8_A_sizes[1];
  c8_g_A = c8_c_A_sizes[0];
  c8_h_A = c8_c_A_sizes[1];
  c8_g_loop_ub = c8_A_sizes[0] * c8_A_sizes[1] - 1;
  for (c8_i17 = 0; c8_i17 <= c8_g_loop_ub; c8_i17++) {
    c8_c_A_data[c8_i17] = c8_A_data[c8_i17];
  }

  c8_scalexpAlloc(chartInstance, c8_c_A_data, c8_c_A_sizes, c8_b_tmp_data,
                  c8_b_tmp_sizes);
  c8_d2 = (real_T)(c8_b_tmp_sizes[0] * c8_b_tmp_sizes[1]);
  c8_i18 = (int32_T)c8_d2 - 1;
  for (c8_c_k = 0; c8_c_k <= c8_i18; c8_c_k++) {
    c8_d_k = 1.0 + (real_T)c8_c_k;
    c8_b_xk = (real_T)c8_A_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)c8_d_k,
      1, c8_A_sizes[0] * c8_A_sizes[1], 1, 0) - 1];
    c8_d3 = muDoubleScalarRound(c8_b_xk / 2.0);
    if (c8_d3 < 256.0) {
      if (CV_SATURATION_EVAL(4, 0, 3, 1, c8_d3 >= 0.0)) {
        c8_u1 = (uint8_T)c8_d3;
      } else {
        c8_u1 = 0U;
      }
    } else if (CV_SATURATION_EVAL(4, 0, 3, 0, c8_d3 >= 256.0)) {
      c8_u1 = MAX_uint8_T;
    } else {
      c8_u1 = 0U;
    }

    c8_b_tmp_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)c8_d_k, 1,
      c8_b_tmp_sizes[0] * c8_b_tmp_sizes[1], 1, 0) - 1] = c8_u1;
  }

  for (c8_i19 = 0; c8_i19 < 2; c8_i19++) {
    c8_iv1[c8_i19] = c8_tmp_sizes[c8_i19];
  }

  for (c8_i20 = 0; c8_i20 < 2; c8_i20++) {
    c8_iv2[c8_i20] = c8_b_tmp_sizes[c8_i20];
  }

  _SFD_SIZE_EQ_CHECK_ND(c8_iv1, c8_iv2, 2);
  _SFD_DIM_SIZE_GEQ_CHECK(320, c8_tmp_sizes[0], 1);
  _SFD_DIM_SIZE_GEQ_CHECK(240, c8_tmp_sizes[1], 2);
  c8_redIntensity_sizes[0] = c8_R_sizes[0];
  c8_redIntensity_sizes[1] = c8_R_sizes[1];
  c8_redIntensity = c8_redIntensity_sizes[0];
  c8_b_redIntensity = c8_redIntensity_sizes[1];
  c8_h_loop_ub = c8_R_sizes[0] * c8_R_sizes[1] - 1;
  for (c8_i21 = 0; c8_i21 <= c8_h_loop_ub; c8_i21++) {
    c8_q0 = c8_R_data[c8_i21];
    c8_qY = c8_q0 - (uint32_T)c8_tmp_data[c8_i21];
    if (CV_SATURATION_EVAL(4, 0, 0, 0, c8_qY > c8_q0)) {
      c8_qY = 0U;
    }

    c8_u2 = c8_qY;
    if (CV_SATURATION_EVAL(4, 0, 0, 0, c8_u2 > 255U)) {
      c8_u2 = 255U;
    }

    c8_b_q0 = (uint8_T)c8_u2;
    c8_b_qY = c8_b_q0 - (uint32_T)c8_b_tmp_data[c8_i21];
    if (CV_SATURATION_EVAL(4, 0, 1, 0, c8_b_qY > c8_b_q0)) {
      c8_b_qY = 0U;
    }

    c8_u3 = c8_b_qY;
    if (CV_SATURATION_EVAL(4, 0, 1, 0, c8_u3 > 255U)) {
      c8_u3 = 255U;
    }

    c8_redIntensity_data[c8_i21] = (uint8_T)c8_u3;
  }

  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, -3);
  _SFD_SYMBOL_SCOPE_POP();
  ssSetCurrentOutputPortDimensions(chartInstance->S, 1, 0,
    c8_redIntensity_sizes[0]);
  ssSetCurrentOutputPortDimensions(chartInstance->S, 1, 1,
    c8_redIntensity_sizes[1]);
  c8_i22 = (*c8_b_redIntensity_sizes)[0];
  c8_i23 = (*c8_b_redIntensity_sizes)[1];
  c8_i_loop_ub = c8_redIntensity_sizes[0] * c8_redIntensity_sizes[1] - 1;
  for (c8_i24 = 0; c8_i24 <= c8_i_loop_ub; c8_i24++) {
    (*c8_b_redIntensity_data)[c8_i24] = c8_redIntensity_data[c8_i24];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c8_sfEvent);
}

static void initSimStructsc8_RaspPiPilot(SFc8_RaspPiPilotInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c8_machineNumber, uint32_T
  c8_chartNumber, uint32_T c8_instanceNumber)
{
  (void)c8_machineNumber;
  (void)c8_chartNumber;
  (void)c8_instanceNumber;
}

static const mxArray *c8_sf_marshallOut(void *chartInstanceVoid, uint8_T
  c8_inData_data[], int32_T c8_inData_sizes[2])
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_b_inData_sizes[2];
  int32_T c8_loop_ub;
  int32_T c8_i25;
  int32_T c8_b_loop_ub;
  int32_T c8_i26;
  uint8_T c8_b_inData_data[76800];
  int32_T c8_u_sizes[2];
  int32_T c8_c_loop_ub;
  int32_T c8_i27;
  int32_T c8_d_loop_ub;
  int32_T c8_i28;
  uint8_T c8_u_data[76800];
  const mxArray *c8_y = NULL;
  SFc8_RaspPiPilotInstanceStruct *chartInstance;
  chartInstance = (SFc8_RaspPiPilotInstanceStruct *)chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  c8_b_inData_sizes[0] = c8_inData_sizes[0];
  c8_b_inData_sizes[1] = c8_inData_sizes[1];
  c8_loop_ub = c8_inData_sizes[1] - 1;
  for (c8_i25 = 0; c8_i25 <= c8_loop_ub; c8_i25++) {
    c8_b_loop_ub = c8_inData_sizes[0] - 1;
    for (c8_i26 = 0; c8_i26 <= c8_b_loop_ub; c8_i26++) {
      c8_b_inData_data[c8_i26 + c8_b_inData_sizes[0] * c8_i25] =
        c8_inData_data[c8_i26 + c8_inData_sizes[0] * c8_i25];
    }
  }

  c8_u_sizes[0] = c8_b_inData_sizes[0];
  c8_u_sizes[1] = c8_b_inData_sizes[1];
  c8_c_loop_ub = c8_b_inData_sizes[1] - 1;
  for (c8_i27 = 0; c8_i27 <= c8_c_loop_ub; c8_i27++) {
    c8_d_loop_ub = c8_b_inData_sizes[0] - 1;
    for (c8_i28 = 0; c8_i28 <= c8_d_loop_ub; c8_i28++) {
      c8_u_data[c8_i28 + c8_u_sizes[0] * c8_i27] = c8_b_inData_data[c8_i28 +
        c8_b_inData_sizes[0] * c8_i27];
    }
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u_data, 3, 0U, 1U, 0U, 2,
    c8_u_sizes[0], c8_u_sizes[1]), false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static void c8_emlrt_marshallIn(SFc8_RaspPiPilotInstanceStruct *chartInstance,
  const mxArray *c8_redIntensity, const char_T *c8_identifier, uint8_T
  c8_y_data[], int32_T c8_y_sizes[2])
{
  emlrtMsgIdentifier c8_thisId;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_redIntensity), &c8_thisId,
                        c8_y_data, c8_y_sizes);
  sf_mex_destroy(&c8_redIntensity);
}

static void c8_b_emlrt_marshallIn(SFc8_RaspPiPilotInstanceStruct *chartInstance,
  const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId, uint8_T c8_y_data[],
  int32_T c8_y_sizes[2])
{
  int32_T c8_i29;
  uint32_T c8_uv0[2];
  int32_T c8_i30;
  boolean_T c8_bv0[2];
  int32_T c8_tmp_sizes[2];
  uint8_T c8_tmp_data[76800];
  int32_T c8_y;
  int32_T c8_b_y;
  int32_T c8_loop_ub;
  int32_T c8_i31;
  (void)chartInstance;
  for (c8_i29 = 0; c8_i29 < 2; c8_i29++) {
    c8_uv0[c8_i29] = 320U + (uint32_T)(-80 * (int32_T)(uint32_T)c8_i29);
  }

  for (c8_i30 = 0; c8_i30 < 2; c8_i30++) {
    c8_bv0[c8_i30] = true;
  }

  sf_mex_import_vs(c8_parentId, sf_mex_dup(c8_u), c8_tmp_data, 1, 3, 0U, 1, 0U,
                   2, c8_bv0, c8_uv0, c8_tmp_sizes);
  c8_y_sizes[0] = c8_tmp_sizes[0];
  c8_y_sizes[1] = c8_tmp_sizes[1];
  c8_y = c8_y_sizes[0];
  c8_b_y = c8_y_sizes[1];
  c8_loop_ub = c8_tmp_sizes[0] * c8_tmp_sizes[1] - 1;
  for (c8_i31 = 0; c8_i31 <= c8_loop_ub; c8_i31++) {
    c8_y_data[c8_i31] = c8_tmp_data[c8_i31];
  }

  sf_mex_destroy(&c8_u);
}

static void c8_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, uint8_T c8_outData_data[],
  int32_T c8_outData_sizes[2])
{
  const mxArray *c8_redIntensity;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  int32_T c8_y_sizes[2];
  uint8_T c8_y_data[76800];
  int32_T c8_loop_ub;
  int32_T c8_i32;
  int32_T c8_b_loop_ub;
  int32_T c8_i33;
  SFc8_RaspPiPilotInstanceStruct *chartInstance;
  chartInstance = (SFc8_RaspPiPilotInstanceStruct *)chartInstanceVoid;
  c8_redIntensity = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_redIntensity), &c8_thisId,
                        c8_y_data, c8_y_sizes);
  sf_mex_destroy(&c8_redIntensity);
  c8_outData_sizes[0] = c8_y_sizes[0];
  c8_outData_sizes[1] = c8_y_sizes[1];
  c8_loop_ub = c8_y_sizes[1] - 1;
  for (c8_i32 = 0; c8_i32 <= c8_loop_ub; c8_i32++) {
    c8_b_loop_ub = c8_y_sizes[0] - 1;
    for (c8_i33 = 0; c8_i33 <= c8_b_loop_ub; c8_i33++) {
      c8_outData_data[c8_i33 + c8_outData_sizes[0] * c8_i32] = c8_y_data[c8_i33
        + c8_y_sizes[0] * c8_i32];
    }
  }

  sf_mex_destroy(&c8_mxArrayInData);
}

static const mxArray *c8_b_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  real_T c8_u;
  const mxArray *c8_y = NULL;
  SFc8_RaspPiPilotInstanceStruct *chartInstance;
  chartInstance = (SFc8_RaspPiPilotInstanceStruct *)chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  c8_u = *(real_T *)c8_inData;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", &c8_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static real_T c8_c_emlrt_marshallIn(SFc8_RaspPiPilotInstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId)
{
  real_T c8_y;
  real_T c8_d4;
  (void)chartInstance;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), &c8_d4, 1, 0, 0U, 0, 0U, 0);
  c8_y = c8_d4;
  sf_mex_destroy(&c8_u);
  return c8_y;
}

static void c8_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_nargout;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  real_T c8_y;
  SFc8_RaspPiPilotInstanceStruct *chartInstance;
  chartInstance = (SFc8_RaspPiPilotInstanceStruct *)chartInstanceVoid;
  c8_nargout = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_y = c8_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_nargout), &c8_thisId);
  sf_mex_destroy(&c8_nargout);
  *(real_T *)c8_outData = c8_y;
  sf_mex_destroy(&c8_mxArrayInData);
}

const mxArray *sf_c8_RaspPiPilot_get_eml_resolved_functions_info(void)
{
  const mxArray *c8_nameCaptureInfo = NULL;
  c8_nameCaptureInfo = NULL;
  sf_mex_assign(&c8_nameCaptureInfo, sf_mex_createstruct("structure", 2, 12, 1),
                false);
  c8_info_helper(&c8_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c8_nameCaptureInfo);
  return c8_nameCaptureInfo;
}

static void c8_info_helper(const mxArray **c8_info)
{
  const mxArray *c8_rhs0 = NULL;
  const mxArray *c8_lhs0 = NULL;
  const mxArray *c8_rhs1 = NULL;
  const mxArray *c8_lhs1 = NULL;
  const mxArray *c8_rhs2 = NULL;
  const mxArray *c8_lhs2 = NULL;
  const mxArray *c8_rhs3 = NULL;
  const mxArray *c8_lhs3 = NULL;
  const mxArray *c8_rhs4 = NULL;
  const mxArray *c8_lhs4 = NULL;
  const mxArray *c8_rhs5 = NULL;
  const mxArray *c8_lhs5 = NULL;
  const mxArray *c8_rhs6 = NULL;
  const mxArray *c8_lhs6 = NULL;
  const mxArray *c8_rhs7 = NULL;
  const mxArray *c8_lhs7 = NULL;
  const mxArray *c8_rhs8 = NULL;
  const mxArray *c8_lhs8 = NULL;
  const mxArray *c8_rhs9 = NULL;
  const mxArray *c8_lhs9 = NULL;
  const mxArray *c8_rhs10 = NULL;
  const mxArray *c8_lhs10 = NULL;
  const mxArray *c8_rhs11 = NULL;
  const mxArray *c8_lhs11 = NULL;
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("mrdivide"), "name", "name", 0);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("uint8"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1388463696U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1370013486U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c8_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs0), "rhs", "rhs", 0);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs0), "lhs", "lhs", 0);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 1);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 1);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1363718156U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c8_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs1), "rhs", "rhs", 1);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs1), "lhs", "lhs", 1);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 2);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("rdivide"), "name", "name", 2);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("uint8"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1363717480U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c8_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs2), "rhs", "rhs", 2);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs2), "lhs", "lhs", 2);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 3);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("uint8"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1363718156U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c8_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs3), "rhs", "rhs", 3);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs3), "lhs", "lhs", 3);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 4);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1363718156U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c8_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs4), "rhs", "rhs", 4);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs4), "lhs", "lhs", 4);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 5);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("uint8"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1286822396U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c8_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs5), "rhs", "rhs", 5);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs5), "lhs", "lhs", 5);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("eml_div"), "name", "name", 6);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("uint8"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1375984288U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c8_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs6), "rhs", "rhs", 6);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs6), "lhs", "lhs", 6);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 7);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 7);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("uint8"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 7);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1389311520U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c8_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs7), "rhs", "rhs", 7);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs7), "lhs", "lhs", 7);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p!eml_mixed_integer_rdivide"),
                  "context", "context", 8);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("coder.internal.is64BitInteger"),
                  "name", "name", 8);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("uint8"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/is64BitInteger.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1368187894U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c8_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs8), "rhs", "rhs", 8);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs8), "lhs", "lhs", 8);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p!eml_mixed_integer_rdivide"),
                  "context", "context", 9);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("coder.internal.is64BitInteger"),
                  "name", "name", 9);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/is64BitInteger.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1368187894U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c8_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs9), "rhs", "rhs", 9);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs9), "lhs", "lhs", 9);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p!eml_mixed_integer_rdivide"),
                  "context", "context", 10);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 10);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("uint8"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1389311520U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c8_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p!eml_mixed_integer_rdivide"),
                  "context", "context", 11);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("coder.internal.scalexpAlloc"),
                  "name", "name", 11);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut("uint8"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c8_info, c8_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(1389311520U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c8_info, c8_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c8_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c8_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c8_info, sf_mex_duplicatearraysafe(&c8_lhs11), "lhs", "lhs",
                  11);
  sf_mex_destroy(&c8_rhs0);
  sf_mex_destroy(&c8_lhs0);
  sf_mex_destroy(&c8_rhs1);
  sf_mex_destroy(&c8_lhs1);
  sf_mex_destroy(&c8_rhs2);
  sf_mex_destroy(&c8_lhs2);
  sf_mex_destroy(&c8_rhs3);
  sf_mex_destroy(&c8_lhs3);
  sf_mex_destroy(&c8_rhs4);
  sf_mex_destroy(&c8_lhs4);
  sf_mex_destroy(&c8_rhs5);
  sf_mex_destroy(&c8_lhs5);
  sf_mex_destroy(&c8_rhs6);
  sf_mex_destroy(&c8_lhs6);
  sf_mex_destroy(&c8_rhs7);
  sf_mex_destroy(&c8_lhs7);
  sf_mex_destroy(&c8_rhs8);
  sf_mex_destroy(&c8_lhs8);
  sf_mex_destroy(&c8_rhs9);
  sf_mex_destroy(&c8_lhs9);
  sf_mex_destroy(&c8_rhs10);
  sf_mex_destroy(&c8_lhs10);
  sf_mex_destroy(&c8_rhs11);
  sf_mex_destroy(&c8_lhs11);
}

static const mxArray *c8_emlrt_marshallOut(const char * c8_u)
{
  const mxArray *c8_y = NULL;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c8_u)), false);
  return c8_y;
}

static const mxArray *c8_b_emlrt_marshallOut(const uint32_T c8_u)
{
  const mxArray *c8_y = NULL;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", &c8_u, 7, 0U, 0U, 0U, 0), false);
  return c8_y;
}

static void c8_scalexpAlloc(SFc8_RaspPiPilotInstanceStruct *chartInstance,
  uint8_T c8_varargin_1_data[], int32_T c8_varargin_1_sizes[2], uint8_T
  c8_z_data[], int32_T c8_z_sizes[2])
{
  int32_T c8_i34;
  real_T c8_dv0[2];
  int32_T c8_iv3[2];
  int32_T c8_tmp_sizes[2];
  int32_T c8_iv4[2];
  int32_T c8_i35;
  int32_T c8_i36;
  int32_T c8_loop_ub;
  int32_T c8_i37;
  uint8_T c8_temp;
  uint8_T c8_tmp_data[76800];
  int32_T c8_i38;
  (void)chartInstance;
  (void)c8_varargin_1_data;
  (void)c8_z_data;
  for (c8_i34 = 0; c8_i34 < 2; c8_i34++) {
    c8_dv0[c8_i34] = (real_T)c8_varargin_1_sizes[c8_i34];
  }

  c8_iv3[0] = (int32_T)c8_dv0[0];
  c8_iv3[1] = (int32_T)c8_dv0[1];
  c8_tmp_sizes[0] = c8_iv3[0];
  c8_iv4[0] = (int32_T)c8_dv0[0];
  c8_iv4[1] = (int32_T)c8_dv0[1];
  c8_tmp_sizes[1] = c8_iv4[1];
  c8_i35 = c8_tmp_sizes[0];
  c8_i36 = c8_tmp_sizes[1];
  c8_loop_ub = (int32_T)c8_dv0[0] * (int32_T)c8_dv0[1] - 1;
  for (c8_i37 = 0; c8_i37 <= c8_loop_ub; c8_i37++) {
    c8_tmp_data[c8_i37] = c8_temp;
  }

  for (c8_i38 = 0; c8_i38 < 2; c8_i38++) {
    c8_z_sizes[c8_i38] = c8_tmp_sizes[c8_i38];
  }
}

static const mxArray *c8_c_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_u;
  const mxArray *c8_y = NULL;
  SFc8_RaspPiPilotInstanceStruct *chartInstance;
  chartInstance = (SFc8_RaspPiPilotInstanceStruct *)chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  c8_u = *(int32_T *)c8_inData;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", &c8_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, false);
  return c8_mxArrayOutData;
}

static int32_T c8_d_emlrt_marshallIn(SFc8_RaspPiPilotInstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId)
{
  int32_T c8_y;
  int32_T c8_i39;
  (void)chartInstance;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), &c8_i39, 1, 6, 0U, 0, 0U, 0);
  c8_y = c8_i39;
  sf_mex_destroy(&c8_u);
  return c8_y;
}

static void c8_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_b_sfEvent;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  int32_T c8_y;
  SFc8_RaspPiPilotInstanceStruct *chartInstance;
  chartInstance = (SFc8_RaspPiPilotInstanceStruct *)chartInstanceVoid;
  c8_b_sfEvent = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_y = c8_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_b_sfEvent),
    &c8_thisId);
  sf_mex_destroy(&c8_b_sfEvent);
  *(int32_T *)c8_outData = c8_y;
  sf_mex_destroy(&c8_mxArrayInData);
}

static uint8_T c8_e_emlrt_marshallIn(SFc8_RaspPiPilotInstanceStruct
  *chartInstance, const mxArray *c8_b_is_active_c8_RaspPiPilot, const char_T
  *c8_identifier)
{
  uint8_T c8_y;
  emlrtMsgIdentifier c8_thisId;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_y = c8_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c8_b_is_active_c8_RaspPiPilot), &c8_thisId);
  sf_mex_destroy(&c8_b_is_active_c8_RaspPiPilot);
  return c8_y;
}

static uint8_T c8_f_emlrt_marshallIn(SFc8_RaspPiPilotInstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId)
{
  uint8_T c8_y;
  uint8_T c8_u4;
  (void)chartInstance;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), &c8_u4, 1, 3, 0U, 0, 0U, 0);
  c8_y = c8_u4;
  sf_mex_destroy(&c8_u);
  return c8_y;
}

static void init_dsm_address_info(SFc8_RaspPiPilotInstanceStruct *chartInstance)
{
  (void)chartInstance;
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

void sf_c8_RaspPiPilot_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2405382442U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2194625789U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2282567818U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2240664254U);
}

mxArray *sf_c8_RaspPiPilot_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("s7j7kbFzsCxCexzbt7ZcQC");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(320);
      pr[1] = (double)(240);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(320);
      pr[1] = (double)(240);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(320);
      pr[1] = (double)(240);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));
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
      pr[0] = (double)(320);
      pr[1] = (double)(240);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c8_RaspPiPilot_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c8_RaspPiPilot_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c8_RaspPiPilot(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"redIntensity\",},{M[8],M[0],T\"is_active_c8_RaspPiPilot\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c8_RaspPiPilot_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc8_RaspPiPilotInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc8_RaspPiPilotInstanceStruct *) chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _RaspPiPilotMachineNumber_,
           8,
           1,
           1,
           0,
           4,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize ist own list of scripts */
        init_script_number_translation(_RaspPiPilotMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_RaspPiPilotMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _RaspPiPilotMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"R");
          _SFD_SET_DATA_PROPS(1,2,0,1,"redIntensity");
          _SFD_SET_DATA_PROPS(2,1,1,0,"G");
          _SFD_SET_DATA_PROPS(3,1,1,0,"B");
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
        _SFD_CV_INIT_EML(0,1,1,0,0,4,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,74);
        _SFD_CV_INIT_EML_SATURATION(0,1,0,60,-1,67);
        _SFD_CV_INIT_EML_SATURATION(0,1,1,60,-1,73);
        _SFD_CV_INIT_EML_SATURATION(0,1,2,64,-1,67);
        _SFD_CV_INIT_EML_SATURATION(0,1,3,70,-1,73);

        {
          unsigned int dimVector[2];
          dimVector[0]= 320;
          dimVector[1]= 240;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_UINT8,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c8_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 320;
          dimVector[1]= 240;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_UINT8,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c8_sf_marshallOut,(MexInFcnForType)
            c8_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 320;
          dimVector[1]= 240;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_UINT8,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c8_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 320;
          dimVector[1]= 240;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_UINT8,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c8_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          int32_T (*c8_R_sizes)[2];
          int32_T (*c8_redIntensity_sizes)[2];
          int32_T (*c8_G_sizes)[2];
          int32_T (*c8_B_sizes)[2];
          uint8_T (*c8_R_data)[76800];
          uint8_T (*c8_redIntensity_data)[76800];
          uint8_T (*c8_G_data)[76800];
          uint8_T (*c8_B_data)[76800];
          c8_B_sizes = (int32_T (*)[2])ssGetCurrentInputPortDimensions_wrapper
            (chartInstance->S, 2);
          c8_B_data = (uint8_T (*)[76800])ssGetInputPortSignal(chartInstance->S,
            2);
          c8_G_sizes = (int32_T (*)[2])ssGetCurrentInputPortDimensions_wrapper
            (chartInstance->S, 1);
          c8_G_data = (uint8_T (*)[76800])ssGetInputPortSignal(chartInstance->S,
            1);
          c8_redIntensity_sizes = (int32_T (*)[2])
            ssGetCurrentOutputPortDimensions_wrapper(chartInstance->S, 1);
          c8_redIntensity_data = (uint8_T (*)[76800])ssGetOutputPortSignal
            (chartInstance->S, 1);
          c8_R_sizes = (int32_T (*)[2])ssGetCurrentInputPortDimensions_wrapper
            (chartInstance->S, 0);
          c8_R_data = (uint8_T (*)[76800])ssGetInputPortSignal(chartInstance->S,
            0);
          _SFD_SET_DATA_VALUE_PTR_VAR_DIM(0U, *c8_R_data, (void *)c8_R_sizes);
          _SFD_SET_DATA_VALUE_PTR_VAR_DIM(1U, *c8_redIntensity_data, (void *)
            c8_redIntensity_sizes);
          _SFD_SET_DATA_VALUE_PTR_VAR_DIM(2U, *c8_G_data, (void *)c8_G_sizes);
          _SFD_SET_DATA_VALUE_PTR_VAR_DIM(3U, *c8_B_data, (void *)c8_B_sizes);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _RaspPiPilotMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "TX4oNDVpcShaiMxiQjQ9IG";
}

static void sf_opaque_initialize_c8_RaspPiPilot(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc8_RaspPiPilotInstanceStruct*) chartInstanceVar)
    ->S,0);
  initialize_params_c8_RaspPiPilot((SFc8_RaspPiPilotInstanceStruct*)
    chartInstanceVar);
  initialize_c8_RaspPiPilot((SFc8_RaspPiPilotInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c8_RaspPiPilot(void *chartInstanceVar)
{
  enable_c8_RaspPiPilot((SFc8_RaspPiPilotInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c8_RaspPiPilot(void *chartInstanceVar)
{
  disable_c8_RaspPiPilot((SFc8_RaspPiPilotInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c8_RaspPiPilot(void *chartInstanceVar)
{
  sf_gateway_c8_RaspPiPilot((SFc8_RaspPiPilotInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c8_RaspPiPilot(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c8_RaspPiPilot
    ((SFc8_RaspPiPilotInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c8_RaspPiPilot();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c8_RaspPiPilot(SimStruct* S, const mxArray
  *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c8_RaspPiPilot();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c8_RaspPiPilot((SFc8_RaspPiPilotInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c8_RaspPiPilot(SimStruct* S)
{
  return sf_internal_get_sim_state_c8_RaspPiPilot(S);
}

static void sf_opaque_set_sim_state_c8_RaspPiPilot(SimStruct* S, const mxArray
  *st)
{
  sf_internal_set_sim_state_c8_RaspPiPilot(S, st);
}

static void sf_opaque_terminate_c8_RaspPiPilot(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc8_RaspPiPilotInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_RaspPiPilot_optimization_info();
    }

    finalize_c8_RaspPiPilot((SFc8_RaspPiPilotInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    if (crtInfo != NULL) {
      utFree((void *)crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc8_RaspPiPilot((SFc8_RaspPiPilotInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c8_RaspPiPilot(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    initialize_params_c8_RaspPiPilot((SFc8_RaspPiPilotInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c8_RaspPiPilot(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_RaspPiPilot_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,8);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,8,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,8,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,8);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,8,3);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,8,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 3; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,8);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3848227352U));
  ssSetChecksum1(S,(2622189984U));
  ssSetChecksum2(S,(2870445881U));
  ssSetChecksum3(S,(1062755133U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c8_RaspPiPilot(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c8_RaspPiPilot(SimStruct *S)
{
  SFc8_RaspPiPilotInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc8_RaspPiPilotInstanceStruct *)utMalloc(sizeof
    (SFc8_RaspPiPilotInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc8_RaspPiPilotInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c8_RaspPiPilot;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c8_RaspPiPilot;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c8_RaspPiPilot;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c8_RaspPiPilot;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c8_RaspPiPilot;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c8_RaspPiPilot;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c8_RaspPiPilot;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c8_RaspPiPilot;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c8_RaspPiPilot;
  chartInstance->chartInfo.mdlStart = mdlStart_c8_RaspPiPilot;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c8_RaspPiPilot;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.debugInstance = sfGlobalDebugInstanceStruct;
  chartInstance->S = S;
  crtInfo->instanceInfo = (&(chartInstance->chartInfo));
  crtInfo->isJITEnabled = false;
  ssSetUserData(S,(void *)(crtInfo));  /* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c8_RaspPiPilot_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c8_RaspPiPilot(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c8_RaspPiPilot(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c8_RaspPiPilot(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c8_RaspPiPilot_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
