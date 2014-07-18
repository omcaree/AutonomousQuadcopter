/* Include files */

#include <stddef.h>
#include "blas.h"
#include "RaspPiPilot_sfun.h"
#include "c7_RaspPiPilot.h"
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
static const char * c7_debug_family_names[6] = { "nargin", "nargout", "R", "G",
  "B", "greenIntensity" };

/* Function Declarations */
static void initialize_c7_RaspPiPilot(SFc7_RaspPiPilotInstanceStruct
  *chartInstance);
static void initialize_params_c7_RaspPiPilot(SFc7_RaspPiPilotInstanceStruct
  *chartInstance);
static void enable_c7_RaspPiPilot(SFc7_RaspPiPilotInstanceStruct *chartInstance);
static void disable_c7_RaspPiPilot(SFc7_RaspPiPilotInstanceStruct *chartInstance);
static void c7_update_debugger_state_c7_RaspPiPilot
  (SFc7_RaspPiPilotInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c7_RaspPiPilot
  (SFc7_RaspPiPilotInstanceStruct *chartInstance);
static void set_sim_state_c7_RaspPiPilot(SFc7_RaspPiPilotInstanceStruct
  *chartInstance, const mxArray *c7_st);
static void finalize_c7_RaspPiPilot(SFc7_RaspPiPilotInstanceStruct
  *chartInstance);
static void sf_gateway_c7_RaspPiPilot(SFc7_RaspPiPilotInstanceStruct
  *chartInstance);
static void initSimStructsc7_RaspPiPilot(SFc7_RaspPiPilotInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c7_machineNumber, uint32_T
  c7_chartNumber, uint32_T c7_instanceNumber);
static const mxArray *c7_sf_marshallOut(void *chartInstanceVoid, uint8_T
  c7_inData_data[], int32_T c7_inData_sizes[2]);
static void c7_emlrt_marshallIn(SFc7_RaspPiPilotInstanceStruct *chartInstance,
  const mxArray *c7_greenIntensity, const char_T *c7_identifier, uint8_T
  c7_y_data[], int32_T c7_y_sizes[2]);
static void c7_b_emlrt_marshallIn(SFc7_RaspPiPilotInstanceStruct *chartInstance,
  const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId, uint8_T c7_y_data[],
  int32_T c7_y_sizes[2]);
static void c7_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, uint8_T c7_outData_data[],
  int32_T c7_outData_sizes[2]);
static const mxArray *c7_b_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static real_T c7_c_emlrt_marshallIn(SFc7_RaspPiPilotInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId);
static void c7_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData);
static const mxArray *c7_c_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static int32_T c7_d_emlrt_marshallIn(SFc7_RaspPiPilotInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId);
static void c7_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData);
static uint8_T c7_e_emlrt_marshallIn(SFc7_RaspPiPilotInstanceStruct
  *chartInstance, const mxArray *c7_b_is_active_c7_RaspPiPilot, const char_T
  *c7_identifier);
static uint8_T c7_f_emlrt_marshallIn(SFc7_RaspPiPilotInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId);
static void init_dsm_address_info(SFc7_RaspPiPilotInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c7_RaspPiPilot(SFc7_RaspPiPilotInstanceStruct
  *chartInstance)
{
  chartInstance->c7_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c7_is_active_c7_RaspPiPilot = 0U;
}

static void initialize_params_c7_RaspPiPilot(SFc7_RaspPiPilotInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void enable_c7_RaspPiPilot(SFc7_RaspPiPilotInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c7_RaspPiPilot(SFc7_RaspPiPilotInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c7_update_debugger_state_c7_RaspPiPilot
  (SFc7_RaspPiPilotInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c7_RaspPiPilot
  (SFc7_RaspPiPilotInstanceStruct *chartInstance)
{
  const mxArray *c7_st;
  const mxArray *c7_y = NULL;
  int32_T c7_u_sizes[2];
  int32_T c7_u;
  int32_T c7_b_u;
  int32_T c7_loop_ub;
  int32_T c7_i0;
  uint8_T c7_u_data[76800];
  const mxArray *c7_b_y = NULL;
  uint8_T c7_hoistedGlobal;
  uint8_T c7_c_u;
  const mxArray *c7_c_y = NULL;
  int32_T (*c7_greenIntensity_sizes)[2];
  uint8_T (*c7_greenIntensity_data)[76800];
  c7_greenIntensity_sizes = (int32_T (*)[2])
    ssGetCurrentOutputPortDimensions_wrapper(chartInstance->S, 1);
  c7_greenIntensity_data = (uint8_T (*)[76800])ssGetOutputPortSignal
    (chartInstance->S, 1);
  c7_st = NULL;
  c7_st = NULL;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_createcellmatrix(2, 1), false);
  c7_u_sizes[0] = (*c7_greenIntensity_sizes)[0];
  c7_u_sizes[1] = (*c7_greenIntensity_sizes)[1];
  c7_u = c7_u_sizes[0];
  c7_b_u = c7_u_sizes[1];
  c7_loop_ub = (*c7_greenIntensity_sizes)[0] * (*c7_greenIntensity_sizes)[1] - 1;
  for (c7_i0 = 0; c7_i0 <= c7_loop_ub; c7_i0++) {
    c7_u_data[c7_i0] = (*c7_greenIntensity_data)[c7_i0];
  }

  c7_b_y = NULL;
  sf_mex_assign(&c7_b_y, sf_mex_create("y", c7_u_data, 3, 0U, 1U, 0U, 2,
    c7_u_sizes[0], c7_u_sizes[1]), false);
  sf_mex_setcell(c7_y, 0, c7_b_y);
  c7_hoistedGlobal = chartInstance->c7_is_active_c7_RaspPiPilot;
  c7_c_u = c7_hoistedGlobal;
  c7_c_y = NULL;
  sf_mex_assign(&c7_c_y, sf_mex_create("y", &c7_c_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c7_y, 1, c7_c_y);
  sf_mex_assign(&c7_st, c7_y, false);
  return c7_st;
}

static void set_sim_state_c7_RaspPiPilot(SFc7_RaspPiPilotInstanceStruct
  *chartInstance, const mxArray *c7_st)
{
  const mxArray *c7_u;
  int32_T c7_tmp_sizes[2];
  uint8_T c7_tmp_data[76800];
  int32_T c7_i1;
  int32_T c7_i2;
  int32_T c7_loop_ub;
  int32_T c7_i3;
  uint8_T (*c7_greenIntensity_data)[76800];
  int32_T (*c7_greenIntensity_sizes)[2];
  c7_greenIntensity_sizes = (int32_T (*)[2])
    ssGetCurrentOutputPortDimensions_wrapper(chartInstance->S, 1);
  c7_greenIntensity_data = (uint8_T (*)[76800])ssGetOutputPortSignal
    (chartInstance->S, 1);
  chartInstance->c7_doneDoubleBufferReInit = true;
  c7_u = sf_mex_dup(c7_st);
  c7_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c7_u, 0)),
                      "greenIntensity", c7_tmp_data, c7_tmp_sizes);
  ssSetCurrentOutputPortDimensions(chartInstance->S, 1, 0, c7_tmp_sizes[0]);
  ssSetCurrentOutputPortDimensions(chartInstance->S, 1, 1, c7_tmp_sizes[1]);
  c7_i1 = (*c7_greenIntensity_sizes)[0];
  c7_i2 = (*c7_greenIntensity_sizes)[1];
  c7_loop_ub = c7_tmp_sizes[0] * c7_tmp_sizes[1] - 1;
  for (c7_i3 = 0; c7_i3 <= c7_loop_ub; c7_i3++) {
    (*c7_greenIntensity_data)[c7_i3] = c7_tmp_data[c7_i3];
  }

  chartInstance->c7_is_active_c7_RaspPiPilot = c7_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c7_u, 1)),
     "is_active_c7_RaspPiPilot");
  sf_mex_destroy(&c7_u);
  c7_update_debugger_state_c7_RaspPiPilot(chartInstance);
  sf_mex_destroy(&c7_st);
}

static void finalize_c7_RaspPiPilot(SFc7_RaspPiPilotInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c7_RaspPiPilot(SFc7_RaspPiPilotInstanceStruct
  *chartInstance)
{
  int32_T c7_loop_ub;
  int32_T c7_i4;
  int32_T c7_R_sizes[2];
  int32_T c7_R;
  int32_T c7_b_R;
  int32_T c7_b_loop_ub;
  int32_T c7_i5;
  static uint8_T c7_R_data[76800];
  int32_T c7_G_sizes[2];
  int32_T c7_G;
  int32_T c7_b_G;
  int32_T c7_c_loop_ub;
  int32_T c7_i6;
  static uint8_T c7_G_data[76800];
  int32_T c7_B_sizes[2];
  int32_T c7_B;
  int32_T c7_b_B;
  int32_T c7_d_loop_ub;
  int32_T c7_i7;
  uint8_T c7_B_data[76800];
  uint32_T c7_debug_family_var_map[6];
  real_T c7_nargin = 3.0;
  real_T c7_nargout = 1.0;
  int32_T c7_greenIntensity_sizes[2];
  uint8_T c7_greenIntensity_data[76800];
  int32_T c7_i8;
  int32_T c7_c_G[2];
  int32_T c7_i9;
  int32_T c7_c_R[2];
  int32_T c7_i10;
  int32_T c7_d_G[2];
  int32_T c7_i11;
  int32_T c7_c_B[2];
  int32_T c7_greenIntensity;
  int32_T c7_b_greenIntensity;
  int32_T c7_e_loop_ub;
  int32_T c7_i12;
  uint32_T c7_q0;
  uint32_T c7_qY;
  uint32_T c7_u0;
  uint32_T c7_b_q0;
  uint32_T c7_b_qY;
  uint32_T c7_u1;
  int32_T c7_i13;
  int32_T c7_i14;
  int32_T c7_f_loop_ub;
  int32_T c7_i15;
  int32_T c7_g_loop_ub;
  int32_T c7_i16;
  int32_T c7_h_loop_ub;
  int32_T c7_i17;
  int32_T c7_i_loop_ub;
  int32_T c7_i18;
  uint8_T (*c7_b_greenIntensity_data)[76800];
  int32_T (*c7_b_R_sizes)[2];
  int32_T (*c7_b_G_sizes)[2];
  int32_T (*c7_b_B_sizes)[2];
  int32_T (*c7_b_greenIntensity_sizes)[2];
  uint8_T (*c7_b_B_data)[76800];
  uint8_T (*c7_b_G_data)[76800];
  uint8_T (*c7_b_R_data)[76800];
  c7_b_B_sizes = (int32_T (*)[2])ssGetCurrentInputPortDimensions_wrapper
    (chartInstance->S, 2);
  c7_b_B_data = (uint8_T (*)[76800])ssGetInputPortSignal(chartInstance->S, 2);
  c7_b_G_sizes = (int32_T (*)[2])ssGetCurrentInputPortDimensions_wrapper
    (chartInstance->S, 1);
  c7_b_G_data = (uint8_T (*)[76800])ssGetInputPortSignal(chartInstance->S, 1);
  c7_b_greenIntensity_sizes = (int32_T (*)[2])
    ssGetCurrentOutputPortDimensions_wrapper(chartInstance->S, 1);
  c7_b_greenIntensity_data = (uint8_T (*)[76800])ssGetOutputPortSignal
    (chartInstance->S, 1);
  c7_b_R_sizes = (int32_T (*)[2])ssGetCurrentInputPortDimensions_wrapper
    (chartInstance->S, 0);
  c7_b_R_data = (uint8_T (*)[76800])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 6U, chartInstance->c7_sfEvent);
  c7_loop_ub = (*c7_b_R_sizes)[0] * (*c7_b_R_sizes)[1] - 1;
  for (c7_i4 = 0; c7_i4 <= c7_loop_ub; c7_i4++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c7_b_R_data)[c7_i4], 0U);
  }

  chartInstance->c7_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 6U, chartInstance->c7_sfEvent);
  c7_R_sizes[0] = (*c7_b_R_sizes)[0];
  c7_R_sizes[1] = (*c7_b_R_sizes)[1];
  c7_R = c7_R_sizes[0];
  c7_b_R = c7_R_sizes[1];
  c7_b_loop_ub = (*c7_b_R_sizes)[0] * (*c7_b_R_sizes)[1] - 1;
  for (c7_i5 = 0; c7_i5 <= c7_b_loop_ub; c7_i5++) {
    c7_R_data[c7_i5] = (*c7_b_R_data)[c7_i5];
  }

  c7_G_sizes[0] = (*c7_b_G_sizes)[0];
  c7_G_sizes[1] = (*c7_b_G_sizes)[1];
  c7_G = c7_G_sizes[0];
  c7_b_G = c7_G_sizes[1];
  c7_c_loop_ub = (*c7_b_G_sizes)[0] * (*c7_b_G_sizes)[1] - 1;
  for (c7_i6 = 0; c7_i6 <= c7_c_loop_ub; c7_i6++) {
    c7_G_data[c7_i6] = (*c7_b_G_data)[c7_i6];
  }

  c7_B_sizes[0] = (*c7_b_B_sizes)[0];
  c7_B_sizes[1] = (*c7_b_B_sizes)[1];
  c7_B = c7_B_sizes[0];
  c7_b_B = c7_B_sizes[1];
  c7_d_loop_ub = (*c7_b_B_sizes)[0] * (*c7_b_B_sizes)[1] - 1;
  for (c7_i7 = 0; c7_i7 <= c7_d_loop_ub; c7_i7++) {
    c7_B_data[c7_i7] = (*c7_b_B_data)[c7_i7];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 6U, 6U, c7_debug_family_names,
    c7_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargin, 0U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargout, 1U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN(c7_R_data, (const int32_T *)&c7_R_sizes, NULL, 1,
    2, (void *)c7_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN(c7_G_data, (const int32_T *)&c7_G_sizes, NULL, 1,
    3, (void *)c7_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN(c7_B_data, (const int32_T *)&c7_B_sizes, NULL, 1,
    4, (void *)c7_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_IMPORTABLE(c7_greenIntensity_data, (const
    int32_T *)&c7_greenIntensity_sizes, NULL, 0, 5, (void *)c7_sf_marshallOut,
    (void *)c7_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 4);
  for (c7_i8 = 0; c7_i8 < 2; c7_i8++) {
    c7_c_G[c7_i8] = c7_G_sizes[c7_i8];
  }

  for (c7_i9 = 0; c7_i9 < 2; c7_i9++) {
    c7_c_R[c7_i9] = c7_R_sizes[c7_i9];
  }

  _SFD_SIZE_EQ_CHECK_ND(c7_c_G, c7_c_R, 2);
  for (c7_i10 = 0; c7_i10 < 2; c7_i10++) {
    c7_d_G[c7_i10] = c7_G_sizes[c7_i10];
  }

  for (c7_i11 = 0; c7_i11 < 2; c7_i11++) {
    c7_c_B[c7_i11] = c7_B_sizes[c7_i11];
  }

  _SFD_SIZE_EQ_CHECK_ND(c7_d_G, c7_c_B, 2);
  _SFD_DIM_SIZE_GEQ_CHECK(320, c7_G_sizes[0], 1);
  _SFD_DIM_SIZE_GEQ_CHECK(240, c7_G_sizes[1], 2);
  c7_greenIntensity_sizes[0] = c7_G_sizes[0];
  c7_greenIntensity_sizes[1] = c7_G_sizes[1];
  c7_greenIntensity = c7_greenIntensity_sizes[0];
  c7_b_greenIntensity = c7_greenIntensity_sizes[1];
  c7_e_loop_ub = c7_G_sizes[0] * c7_G_sizes[1] - 1;
  for (c7_i12 = 0; c7_i12 <= c7_e_loop_ub; c7_i12++) {
    c7_q0 = c7_G_data[c7_i12];
    c7_qY = c7_q0 - (uint32_T)c7_R_data[c7_i12];
    if (CV_SATURATION_EVAL(4, 0, 0, 0, c7_qY > c7_q0)) {
      c7_qY = 0U;
    }

    c7_u0 = c7_qY;
    if (CV_SATURATION_EVAL(4, 0, 0, 0, c7_u0 > 255U)) {
      c7_u0 = 255U;
    }

    c7_b_q0 = (uint8_T)c7_u0;
    c7_b_qY = c7_b_q0 - (uint32_T)c7_B_data[c7_i12];
    if (CV_SATURATION_EVAL(4, 0, 1, 0, c7_b_qY > c7_b_q0)) {
      c7_b_qY = 0U;
    }

    c7_u1 = c7_b_qY;
    if (CV_SATURATION_EVAL(4, 0, 1, 0, c7_u1 > 255U)) {
      c7_u1 = 255U;
    }

    c7_greenIntensity_data[c7_i12] = (uint8_T)c7_u1;
  }

  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, -4);
  _SFD_SYMBOL_SCOPE_POP();
  ssSetCurrentOutputPortDimensions(chartInstance->S, 1, 0,
    c7_greenIntensity_sizes[0]);
  ssSetCurrentOutputPortDimensions(chartInstance->S, 1, 1,
    c7_greenIntensity_sizes[1]);
  c7_i13 = (*c7_b_greenIntensity_sizes)[0];
  c7_i14 = (*c7_b_greenIntensity_sizes)[1];
  c7_f_loop_ub = c7_greenIntensity_sizes[0] * c7_greenIntensity_sizes[1] - 1;
  for (c7_i15 = 0; c7_i15 <= c7_f_loop_ub; c7_i15++) {
    (*c7_b_greenIntensity_data)[c7_i15] = c7_greenIntensity_data[c7_i15];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c7_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_RaspPiPilotMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  c7_g_loop_ub = (*c7_b_greenIntensity_sizes)[0] * (*c7_b_greenIntensity_sizes)
    [1] - 1;
  for (c7_i16 = 0; c7_i16 <= c7_g_loop_ub; c7_i16++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c7_b_greenIntensity_data)[c7_i16], 1U);
  }

  c7_h_loop_ub = (*c7_b_G_sizes)[0] * (*c7_b_G_sizes)[1] - 1;
  for (c7_i17 = 0; c7_i17 <= c7_h_loop_ub; c7_i17++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c7_b_G_data)[c7_i17], 2U);
  }

  c7_i_loop_ub = (*c7_b_B_sizes)[0] * (*c7_b_B_sizes)[1] - 1;
  for (c7_i18 = 0; c7_i18 <= c7_i_loop_ub; c7_i18++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c7_b_B_data)[c7_i18], 3U);
  }
}

static void initSimStructsc7_RaspPiPilot(SFc7_RaspPiPilotInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c7_machineNumber, uint32_T
  c7_chartNumber, uint32_T c7_instanceNumber)
{
  (void)c7_machineNumber;
  (void)c7_chartNumber;
  (void)c7_instanceNumber;
}

static const mxArray *c7_sf_marshallOut(void *chartInstanceVoid, uint8_T
  c7_inData_data[], int32_T c7_inData_sizes[2])
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_b_inData_sizes[2];
  int32_T c7_loop_ub;
  int32_T c7_i19;
  int32_T c7_b_loop_ub;
  int32_T c7_i20;
  uint8_T c7_b_inData_data[76800];
  int32_T c7_u_sizes[2];
  int32_T c7_c_loop_ub;
  int32_T c7_i21;
  int32_T c7_d_loop_ub;
  int32_T c7_i22;
  uint8_T c7_u_data[76800];
  const mxArray *c7_y = NULL;
  SFc7_RaspPiPilotInstanceStruct *chartInstance;
  chartInstance = (SFc7_RaspPiPilotInstanceStruct *)chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  c7_b_inData_sizes[0] = c7_inData_sizes[0];
  c7_b_inData_sizes[1] = c7_inData_sizes[1];
  c7_loop_ub = c7_inData_sizes[1] - 1;
  for (c7_i19 = 0; c7_i19 <= c7_loop_ub; c7_i19++) {
    c7_b_loop_ub = c7_inData_sizes[0] - 1;
    for (c7_i20 = 0; c7_i20 <= c7_b_loop_ub; c7_i20++) {
      c7_b_inData_data[c7_i20 + c7_b_inData_sizes[0] * c7_i19] =
        c7_inData_data[c7_i20 + c7_inData_sizes[0] * c7_i19];
    }
  }

  c7_u_sizes[0] = c7_b_inData_sizes[0];
  c7_u_sizes[1] = c7_b_inData_sizes[1];
  c7_c_loop_ub = c7_b_inData_sizes[1] - 1;
  for (c7_i21 = 0; c7_i21 <= c7_c_loop_ub; c7_i21++) {
    c7_d_loop_ub = c7_b_inData_sizes[0] - 1;
    for (c7_i22 = 0; c7_i22 <= c7_d_loop_ub; c7_i22++) {
      c7_u_data[c7_i22 + c7_u_sizes[0] * c7_i21] = c7_b_inData_data[c7_i22 +
        c7_b_inData_sizes[0] * c7_i21];
    }
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u_data, 3, 0U, 1U, 0U, 2,
    c7_u_sizes[0], c7_u_sizes[1]), false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static void c7_emlrt_marshallIn(SFc7_RaspPiPilotInstanceStruct *chartInstance,
  const mxArray *c7_greenIntensity, const char_T *c7_identifier, uint8_T
  c7_y_data[], int32_T c7_y_sizes[2])
{
  emlrtMsgIdentifier c7_thisId;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_greenIntensity), &c7_thisId,
                        c7_y_data, c7_y_sizes);
  sf_mex_destroy(&c7_greenIntensity);
}

static void c7_b_emlrt_marshallIn(SFc7_RaspPiPilotInstanceStruct *chartInstance,
  const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId, uint8_T c7_y_data[],
  int32_T c7_y_sizes[2])
{
  int32_T c7_i23;
  uint32_T c7_uv0[2];
  int32_T c7_i24;
  boolean_T c7_bv0[2];
  int32_T c7_tmp_sizes[2];
  uint8_T c7_tmp_data[76800];
  int32_T c7_y;
  int32_T c7_b_y;
  int32_T c7_loop_ub;
  int32_T c7_i25;
  (void)chartInstance;
  for (c7_i23 = 0; c7_i23 < 2; c7_i23++) {
    c7_uv0[c7_i23] = 320U + (uint32_T)(-80 * (int32_T)(uint32_T)c7_i23);
  }

  for (c7_i24 = 0; c7_i24 < 2; c7_i24++) {
    c7_bv0[c7_i24] = true;
  }

  sf_mex_import_vs(c7_parentId, sf_mex_dup(c7_u), c7_tmp_data, 1, 3, 0U, 1, 0U,
                   2, c7_bv0, c7_uv0, c7_tmp_sizes);
  c7_y_sizes[0] = c7_tmp_sizes[0];
  c7_y_sizes[1] = c7_tmp_sizes[1];
  c7_y = c7_y_sizes[0];
  c7_b_y = c7_y_sizes[1];
  c7_loop_ub = c7_tmp_sizes[0] * c7_tmp_sizes[1] - 1;
  for (c7_i25 = 0; c7_i25 <= c7_loop_ub; c7_i25++) {
    c7_y_data[c7_i25] = c7_tmp_data[c7_i25];
  }

  sf_mex_destroy(&c7_u);
}

static void c7_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, uint8_T c7_outData_data[],
  int32_T c7_outData_sizes[2])
{
  const mxArray *c7_greenIntensity;
  const char_T *c7_identifier;
  emlrtMsgIdentifier c7_thisId;
  int32_T c7_y_sizes[2];
  uint8_T c7_y_data[76800];
  int32_T c7_loop_ub;
  int32_T c7_i26;
  int32_T c7_b_loop_ub;
  int32_T c7_i27;
  SFc7_RaspPiPilotInstanceStruct *chartInstance;
  chartInstance = (SFc7_RaspPiPilotInstanceStruct *)chartInstanceVoid;
  c7_greenIntensity = sf_mex_dup(c7_mxArrayInData);
  c7_identifier = c7_varName;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_greenIntensity), &c7_thisId,
                        c7_y_data, c7_y_sizes);
  sf_mex_destroy(&c7_greenIntensity);
  c7_outData_sizes[0] = c7_y_sizes[0];
  c7_outData_sizes[1] = c7_y_sizes[1];
  c7_loop_ub = c7_y_sizes[1] - 1;
  for (c7_i26 = 0; c7_i26 <= c7_loop_ub; c7_i26++) {
    c7_b_loop_ub = c7_y_sizes[0] - 1;
    for (c7_i27 = 0; c7_i27 <= c7_b_loop_ub; c7_i27++) {
      c7_outData_data[c7_i27 + c7_outData_sizes[0] * c7_i26] = c7_y_data[c7_i27
        + c7_y_sizes[0] * c7_i26];
    }
  }

  sf_mex_destroy(&c7_mxArrayInData);
}

static const mxArray *c7_b_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  real_T c7_u;
  const mxArray *c7_y = NULL;
  SFc7_RaspPiPilotInstanceStruct *chartInstance;
  chartInstance = (SFc7_RaspPiPilotInstanceStruct *)chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  c7_u = *(real_T *)c7_inData;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", &c7_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static real_T c7_c_emlrt_marshallIn(SFc7_RaspPiPilotInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId)
{
  real_T c7_y;
  real_T c7_d0;
  (void)chartInstance;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), &c7_d0, 1, 0, 0U, 0, 0U, 0);
  c7_y = c7_d0;
  sf_mex_destroy(&c7_u);
  return c7_y;
}

static void c7_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData)
{
  const mxArray *c7_nargout;
  const char_T *c7_identifier;
  emlrtMsgIdentifier c7_thisId;
  real_T c7_y;
  SFc7_RaspPiPilotInstanceStruct *chartInstance;
  chartInstance = (SFc7_RaspPiPilotInstanceStruct *)chartInstanceVoid;
  c7_nargout = sf_mex_dup(c7_mxArrayInData);
  c7_identifier = c7_varName;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_y = c7_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_nargout), &c7_thisId);
  sf_mex_destroy(&c7_nargout);
  *(real_T *)c7_outData = c7_y;
  sf_mex_destroy(&c7_mxArrayInData);
}

const mxArray *sf_c7_RaspPiPilot_get_eml_resolved_functions_info(void)
{
  const mxArray *c7_nameCaptureInfo = NULL;
  c7_nameCaptureInfo = NULL;
  sf_mex_assign(&c7_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c7_nameCaptureInfo;
}

static const mxArray *c7_c_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_u;
  const mxArray *c7_y = NULL;
  SFc7_RaspPiPilotInstanceStruct *chartInstance;
  chartInstance = (SFc7_RaspPiPilotInstanceStruct *)chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  c7_u = *(int32_T *)c7_inData;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", &c7_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static int32_T c7_d_emlrt_marshallIn(SFc7_RaspPiPilotInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId)
{
  int32_T c7_y;
  int32_T c7_i28;
  (void)chartInstance;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), &c7_i28, 1, 6, 0U, 0, 0U, 0);
  c7_y = c7_i28;
  sf_mex_destroy(&c7_u);
  return c7_y;
}

static void c7_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData)
{
  const mxArray *c7_b_sfEvent;
  const char_T *c7_identifier;
  emlrtMsgIdentifier c7_thisId;
  int32_T c7_y;
  SFc7_RaspPiPilotInstanceStruct *chartInstance;
  chartInstance = (SFc7_RaspPiPilotInstanceStruct *)chartInstanceVoid;
  c7_b_sfEvent = sf_mex_dup(c7_mxArrayInData);
  c7_identifier = c7_varName;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_y = c7_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_b_sfEvent),
    &c7_thisId);
  sf_mex_destroy(&c7_b_sfEvent);
  *(int32_T *)c7_outData = c7_y;
  sf_mex_destroy(&c7_mxArrayInData);
}

static uint8_T c7_e_emlrt_marshallIn(SFc7_RaspPiPilotInstanceStruct
  *chartInstance, const mxArray *c7_b_is_active_c7_RaspPiPilot, const char_T
  *c7_identifier)
{
  uint8_T c7_y;
  emlrtMsgIdentifier c7_thisId;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_y = c7_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c7_b_is_active_c7_RaspPiPilot), &c7_thisId);
  sf_mex_destroy(&c7_b_is_active_c7_RaspPiPilot);
  return c7_y;
}

static uint8_T c7_f_emlrt_marshallIn(SFc7_RaspPiPilotInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId)
{
  uint8_T c7_y;
  uint8_T c7_u2;
  (void)chartInstance;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), &c7_u2, 1, 3, 0U, 0, 0U, 0);
  c7_y = c7_u2;
  sf_mex_destroy(&c7_u);
  return c7_y;
}

static void init_dsm_address_info(SFc7_RaspPiPilotInstanceStruct *chartInstance)
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

void sf_c7_RaspPiPilot_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1917051501U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2167098711U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2883459436U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3167927387U);
}

mxArray *sf_c7_RaspPiPilot_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("vqVFdVu5hWKkuftCLKadWE");
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

mxArray *sf_c7_RaspPiPilot_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c7_RaspPiPilot_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c7_RaspPiPilot(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"greenIntensity\",},{M[8],M[0],T\"is_active_c7_RaspPiPilot\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c7_RaspPiPilot_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc7_RaspPiPilotInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc7_RaspPiPilotInstanceStruct *) chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _RaspPiPilotMachineNumber_,
           7,
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
          _SFD_SET_DATA_PROPS(1,2,0,1,"greenIntensity");
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
        _SFD_CV_INIT_EML(0,1,1,0,0,2,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,75);
        _SFD_CV_INIT_EML_SATURATION(0,1,0,65,-1,70);
        _SFD_CV_INIT_EML_SATURATION(0,1,1,65,-1,74);

        {
          unsigned int dimVector[2];
          dimVector[0]= 320;
          dimVector[1]= 240;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_UINT8,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 320;
          dimVector[1]= 240;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_UINT8,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)
            c7_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 320;
          dimVector[1]= 240;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_UINT8,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 320;
          dimVector[1]= 240;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_UINT8,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          int32_T (*c7_R_sizes)[2];
          int32_T (*c7_greenIntensity_sizes)[2];
          int32_T (*c7_G_sizes)[2];
          int32_T (*c7_B_sizes)[2];
          uint8_T (*c7_R_data)[76800];
          uint8_T (*c7_greenIntensity_data)[76800];
          uint8_T (*c7_G_data)[76800];
          uint8_T (*c7_B_data)[76800];
          c7_B_sizes = (int32_T (*)[2])ssGetCurrentInputPortDimensions_wrapper
            (chartInstance->S, 2);
          c7_B_data = (uint8_T (*)[76800])ssGetInputPortSignal(chartInstance->S,
            2);
          c7_G_sizes = (int32_T (*)[2])ssGetCurrentInputPortDimensions_wrapper
            (chartInstance->S, 1);
          c7_G_data = (uint8_T (*)[76800])ssGetInputPortSignal(chartInstance->S,
            1);
          c7_greenIntensity_sizes = (int32_T (*)[2])
            ssGetCurrentOutputPortDimensions_wrapper(chartInstance->S, 1);
          c7_greenIntensity_data = (uint8_T (*)[76800])ssGetOutputPortSignal
            (chartInstance->S, 1);
          c7_R_sizes = (int32_T (*)[2])ssGetCurrentInputPortDimensions_wrapper
            (chartInstance->S, 0);
          c7_R_data = (uint8_T (*)[76800])ssGetInputPortSignal(chartInstance->S,
            0);
          _SFD_SET_DATA_VALUE_PTR_VAR_DIM(0U, *c7_R_data, (void *)c7_R_sizes);
          _SFD_SET_DATA_VALUE_PTR_VAR_DIM(1U, *c7_greenIntensity_data, (void *)
            c7_greenIntensity_sizes);
          _SFD_SET_DATA_VALUE_PTR_VAR_DIM(2U, *c7_G_data, (void *)c7_G_sizes);
          _SFD_SET_DATA_VALUE_PTR_VAR_DIM(3U, *c7_B_data, (void *)c7_B_sizes);
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
  return "wnKqJ0BLxoJBHezQtJrNyD";
}

static void sf_opaque_initialize_c7_RaspPiPilot(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc7_RaspPiPilotInstanceStruct*) chartInstanceVar)
    ->S,0);
  initialize_params_c7_RaspPiPilot((SFc7_RaspPiPilotInstanceStruct*)
    chartInstanceVar);
  initialize_c7_RaspPiPilot((SFc7_RaspPiPilotInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c7_RaspPiPilot(void *chartInstanceVar)
{
  enable_c7_RaspPiPilot((SFc7_RaspPiPilotInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c7_RaspPiPilot(void *chartInstanceVar)
{
  disable_c7_RaspPiPilot((SFc7_RaspPiPilotInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c7_RaspPiPilot(void *chartInstanceVar)
{
  sf_gateway_c7_RaspPiPilot((SFc7_RaspPiPilotInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c7_RaspPiPilot(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c7_RaspPiPilot
    ((SFc7_RaspPiPilotInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c7_RaspPiPilot();/* state var info */
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

extern void sf_internal_set_sim_state_c7_RaspPiPilot(SimStruct* S, const mxArray
  *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c7_RaspPiPilot();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c7_RaspPiPilot((SFc7_RaspPiPilotInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c7_RaspPiPilot(SimStruct* S)
{
  return sf_internal_get_sim_state_c7_RaspPiPilot(S);
}

static void sf_opaque_set_sim_state_c7_RaspPiPilot(SimStruct* S, const mxArray
  *st)
{
  sf_internal_set_sim_state_c7_RaspPiPilot(S, st);
}

static void sf_opaque_terminate_c7_RaspPiPilot(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc7_RaspPiPilotInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_RaspPiPilot_optimization_info();
    }

    finalize_c7_RaspPiPilot((SFc7_RaspPiPilotInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    if (crtInfo != NULL) {
      utFree((void *)crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc7_RaspPiPilot((SFc7_RaspPiPilotInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c7_RaspPiPilot(SimStruct *S)
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
    initialize_params_c7_RaspPiPilot((SFc7_RaspPiPilotInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c7_RaspPiPilot(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_RaspPiPilot_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,7);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,7,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,7,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,7);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,7,3);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,7,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,7);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(4110661127U));
  ssSetChecksum1(S,(3092784576U));
  ssSetChecksum2(S,(159186802U));
  ssSetChecksum3(S,(3119263082U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c7_RaspPiPilot(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c7_RaspPiPilot(SimStruct *S)
{
  SFc7_RaspPiPilotInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc7_RaspPiPilotInstanceStruct *)utMalloc(sizeof
    (SFc7_RaspPiPilotInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc7_RaspPiPilotInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c7_RaspPiPilot;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c7_RaspPiPilot;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c7_RaspPiPilot;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c7_RaspPiPilot;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c7_RaspPiPilot;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c7_RaspPiPilot;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c7_RaspPiPilot;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c7_RaspPiPilot;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c7_RaspPiPilot;
  chartInstance->chartInfo.mdlStart = mdlStart_c7_RaspPiPilot;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c7_RaspPiPilot;
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

void c7_RaspPiPilot_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c7_RaspPiPilot(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c7_RaspPiPilot(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c7_RaspPiPilot(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c7_RaspPiPilot_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
