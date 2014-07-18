/* Include files */

#include <stddef.h>
#include "blas.h"
#include "RaspPiPilot_sfun.h"
#include "c20_RaspPiPilot.h"
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
static const char * c20_debug_family_names[6] = { "nargin", "nargout", "R", "G",
  "B", "blueIntensity" };

/* Function Declarations */
static void initialize_c20_RaspPiPilot(SFc20_RaspPiPilotInstanceStruct
  *chartInstance);
static void initialize_params_c20_RaspPiPilot(SFc20_RaspPiPilotInstanceStruct
  *chartInstance);
static void enable_c20_RaspPiPilot(SFc20_RaspPiPilotInstanceStruct
  *chartInstance);
static void disable_c20_RaspPiPilot(SFc20_RaspPiPilotInstanceStruct
  *chartInstance);
static void c20_update_debugger_state_c20_RaspPiPilot
  (SFc20_RaspPiPilotInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c20_RaspPiPilot
  (SFc20_RaspPiPilotInstanceStruct *chartInstance);
static void set_sim_state_c20_RaspPiPilot(SFc20_RaspPiPilotInstanceStruct
  *chartInstance, const mxArray *c20_st);
static void finalize_c20_RaspPiPilot(SFc20_RaspPiPilotInstanceStruct
  *chartInstance);
static void sf_gateway_c20_RaspPiPilot(SFc20_RaspPiPilotInstanceStruct
  *chartInstance);
static void initSimStructsc20_RaspPiPilot(SFc20_RaspPiPilotInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c20_machineNumber, uint32_T
  c20_chartNumber, uint32_T c20_instanceNumber);
static const mxArray *c20_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData);
static void c20_emlrt_marshallIn(SFc20_RaspPiPilotInstanceStruct *chartInstance,
  const mxArray *c20_blueIntensity, const char_T *c20_identifier, uint8_T c20_y
  [76800]);
static void c20_b_emlrt_marshallIn(SFc20_RaspPiPilotInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId,
  uint8_T c20_y[76800]);
static void c20_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData);
static const mxArray *c20_b_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData);
static real_T c20_c_emlrt_marshallIn(SFc20_RaspPiPilotInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId);
static void c20_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData);
static const mxArray *c20_c_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData);
static int32_T c20_d_emlrt_marshallIn(SFc20_RaspPiPilotInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId);
static void c20_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData);
static uint8_T c20_e_emlrt_marshallIn(SFc20_RaspPiPilotInstanceStruct
  *chartInstance, const mxArray *c20_b_is_active_c20_RaspPiPilot, const char_T
  *c20_identifier);
static uint8_T c20_f_emlrt_marshallIn(SFc20_RaspPiPilotInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId);
static void init_dsm_address_info(SFc20_RaspPiPilotInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c20_RaspPiPilot(SFc20_RaspPiPilotInstanceStruct
  *chartInstance)
{
  chartInstance->c20_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c20_is_active_c20_RaspPiPilot = 0U;
}

static void initialize_params_c20_RaspPiPilot(SFc20_RaspPiPilotInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void enable_c20_RaspPiPilot(SFc20_RaspPiPilotInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c20_RaspPiPilot(SFc20_RaspPiPilotInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c20_update_debugger_state_c20_RaspPiPilot
  (SFc20_RaspPiPilotInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c20_RaspPiPilot
  (SFc20_RaspPiPilotInstanceStruct *chartInstance)
{
  const mxArray *c20_st;
  const mxArray *c20_y = NULL;
  int32_T c20_i0;
  uint8_T c20_u[76800];
  const mxArray *c20_b_y = NULL;
  uint8_T c20_hoistedGlobal;
  uint8_T c20_b_u;
  const mxArray *c20_c_y = NULL;
  uint8_T (*c20_blueIntensity)[76800];
  c20_blueIntensity = (uint8_T (*)[76800])ssGetOutputPortSignal(chartInstance->S,
    1);
  c20_st = NULL;
  c20_st = NULL;
  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_createcellmatrix(2, 1), false);
  for (c20_i0 = 0; c20_i0 < 76800; c20_i0++) {
    c20_u[c20_i0] = (*c20_blueIntensity)[c20_i0];
  }

  c20_b_y = NULL;
  sf_mex_assign(&c20_b_y, sf_mex_create("y", c20_u, 3, 0U, 1U, 0U, 2, 320, 240),
                false);
  sf_mex_setcell(c20_y, 0, c20_b_y);
  c20_hoistedGlobal = chartInstance->c20_is_active_c20_RaspPiPilot;
  c20_b_u = c20_hoistedGlobal;
  c20_c_y = NULL;
  sf_mex_assign(&c20_c_y, sf_mex_create("y", &c20_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c20_y, 1, c20_c_y);
  sf_mex_assign(&c20_st, c20_y, false);
  return c20_st;
}

static void set_sim_state_c20_RaspPiPilot(SFc20_RaspPiPilotInstanceStruct
  *chartInstance, const mxArray *c20_st)
{
  const mxArray *c20_u;
  uint8_T c20_uv0[76800];
  int32_T c20_i1;
  uint8_T (*c20_blueIntensity)[76800];
  c20_blueIntensity = (uint8_T (*)[76800])ssGetOutputPortSignal(chartInstance->S,
    1);
  chartInstance->c20_doneDoubleBufferReInit = true;
  c20_u = sf_mex_dup(c20_st);
  c20_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c20_u, 0)),
                       "blueIntensity", c20_uv0);
  for (c20_i1 = 0; c20_i1 < 76800; c20_i1++) {
    (*c20_blueIntensity)[c20_i1] = c20_uv0[c20_i1];
  }

  chartInstance->c20_is_active_c20_RaspPiPilot = c20_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c20_u, 1)),
     "is_active_c20_RaspPiPilot");
  sf_mex_destroy(&c20_u);
  c20_update_debugger_state_c20_RaspPiPilot(chartInstance);
  sf_mex_destroy(&c20_st);
}

static void finalize_c20_RaspPiPilot(SFc20_RaspPiPilotInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c20_RaspPiPilot(SFc20_RaspPiPilotInstanceStruct
  *chartInstance)
{
  int32_T c20_i2;
  int32_T c20_i3;
  int32_T c20_i4;
  int32_T c20_i5;
  static uint8_T c20_R[76800];
  int32_T c20_i6;
  static uint8_T c20_G[76800];
  int32_T c20_i7;
  uint8_T c20_B[76800];
  uint32_T c20_debug_family_var_map[6];
  real_T c20_nargin = 3.0;
  real_T c20_nargout = 1.0;
  uint8_T c20_blueIntensity[76800];
  int32_T c20_i8;
  uint32_T c20_q0;
  uint32_T c20_qY;
  uint32_T c20_u0;
  int32_T c20_i9;
  int32_T c20_i10;
  uint8_T (*c20_b_blueIntensity)[76800];
  uint8_T (*c20_b_B)[76800];
  uint8_T (*c20_b_G)[76800];
  uint8_T (*c20_b_R)[76800];
  c20_b_blueIntensity = (uint8_T (*)[76800])ssGetOutputPortSignal
    (chartInstance->S, 1);
  c20_b_B = (uint8_T (*)[76800])ssGetInputPortSignal(chartInstance->S, 2);
  c20_b_G = (uint8_T (*)[76800])ssGetInputPortSignal(chartInstance->S, 1);
  c20_b_R = (uint8_T (*)[76800])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 19U, chartInstance->c20_sfEvent);
  for (c20_i2 = 0; c20_i2 < 76800; c20_i2++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c20_b_R)[c20_i2], 0U);
  }

  for (c20_i3 = 0; c20_i3 < 76800; c20_i3++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c20_b_G)[c20_i3], 1U);
  }

  for (c20_i4 = 0; c20_i4 < 76800; c20_i4++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c20_b_B)[c20_i4], 2U);
  }

  chartInstance->c20_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 19U, chartInstance->c20_sfEvent);
  for (c20_i5 = 0; c20_i5 < 76800; c20_i5++) {
    c20_R[c20_i5] = (*c20_b_R)[c20_i5];
  }

  for (c20_i6 = 0; c20_i6 < 76800; c20_i6++) {
    c20_G[c20_i6] = (*c20_b_G)[c20_i6];
  }

  for (c20_i7 = 0; c20_i7 < 76800; c20_i7++) {
    c20_B[c20_i7] = (*c20_b_B)[c20_i7];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 6U, 6U, c20_debug_family_names,
    c20_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_nargin, 0U, c20_b_sf_marshallOut,
    c20_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_nargout, 1U, c20_b_sf_marshallOut,
    c20_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c20_R, 2U, c20_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c20_G, 3U, c20_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c20_B, 4U, c20_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c20_blueIntensity, 5U, c20_sf_marshallOut,
    c20_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c20_sfEvent, 3);
  for (c20_i8 = 0; c20_i8 < 76800; c20_i8++) {
    c20_q0 = c20_B[c20_i8];
    c20_qY = c20_q0 - (uint32_T)c20_G[c20_i8];
    if (CV_SATURATION_EVAL(4, 0, 0, 0, c20_qY > c20_q0)) {
      c20_qY = 0U;
    }

    c20_u0 = c20_qY;
    if (CV_SATURATION_EVAL(4, 0, 0, 0, c20_u0 > 255U)) {
      c20_u0 = 255U;
    }

    c20_blueIntensity[c20_i8] = (uint8_T)c20_u0;
  }

  _SFD_EML_CALL(0U, chartInstance->c20_sfEvent, -3);
  _SFD_SYMBOL_SCOPE_POP();
  for (c20_i9 = 0; c20_i9 < 76800; c20_i9++) {
    (*c20_b_blueIntensity)[c20_i9] = c20_blueIntensity[c20_i9];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 19U, chartInstance->c20_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_RaspPiPilotMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c20_i10 = 0; c20_i10 < 76800; c20_i10++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c20_b_blueIntensity)[c20_i10], 3U);
  }
}

static void initSimStructsc20_RaspPiPilot(SFc20_RaspPiPilotInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c20_machineNumber, uint32_T
  c20_chartNumber, uint32_T c20_instanceNumber)
{
  (void)c20_machineNumber;
  (void)c20_chartNumber;
  (void)c20_instanceNumber;
}

static const mxArray *c20_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData)
{
  const mxArray *c20_mxArrayOutData = NULL;
  int32_T c20_i11;
  int32_T c20_i12;
  int32_T c20_i13;
  uint8_T c20_b_inData[76800];
  int32_T c20_i14;
  int32_T c20_i15;
  int32_T c20_i16;
  uint8_T c20_u[76800];
  const mxArray *c20_y = NULL;
  SFc20_RaspPiPilotInstanceStruct *chartInstance;
  chartInstance = (SFc20_RaspPiPilotInstanceStruct *)chartInstanceVoid;
  c20_mxArrayOutData = NULL;
  c20_i11 = 0;
  for (c20_i12 = 0; c20_i12 < 240; c20_i12++) {
    for (c20_i13 = 0; c20_i13 < 320; c20_i13++) {
      c20_b_inData[c20_i13 + c20_i11] = (*(uint8_T (*)[76800])c20_inData)
        [c20_i13 + c20_i11];
    }

    c20_i11 += 320;
  }

  c20_i14 = 0;
  for (c20_i15 = 0; c20_i15 < 240; c20_i15++) {
    for (c20_i16 = 0; c20_i16 < 320; c20_i16++) {
      c20_u[c20_i16 + c20_i14] = c20_b_inData[c20_i16 + c20_i14];
    }

    c20_i14 += 320;
  }

  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", c20_u, 3, 0U, 1U, 0U, 2, 320, 240),
                false);
  sf_mex_assign(&c20_mxArrayOutData, c20_y, false);
  return c20_mxArrayOutData;
}

static void c20_emlrt_marshallIn(SFc20_RaspPiPilotInstanceStruct *chartInstance,
  const mxArray *c20_blueIntensity, const char_T *c20_identifier, uint8_T c20_y
  [76800])
{
  emlrtMsgIdentifier c20_thisId;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c20_blueIntensity),
    &c20_thisId, c20_y);
  sf_mex_destroy(&c20_blueIntensity);
}

static void c20_b_emlrt_marshallIn(SFc20_RaspPiPilotInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId,
  uint8_T c20_y[76800])
{
  uint8_T c20_uv1[76800];
  int32_T c20_i17;
  (void)chartInstance;
  sf_mex_import(c20_parentId, sf_mex_dup(c20_u), c20_uv1, 1, 3, 0U, 1, 0U, 2,
                320, 240);
  for (c20_i17 = 0; c20_i17 < 76800; c20_i17++) {
    c20_y[c20_i17] = c20_uv1[c20_i17];
  }

  sf_mex_destroy(&c20_u);
}

static void c20_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData)
{
  const mxArray *c20_blueIntensity;
  const char_T *c20_identifier;
  emlrtMsgIdentifier c20_thisId;
  uint8_T c20_y[76800];
  int32_T c20_i18;
  int32_T c20_i19;
  int32_T c20_i20;
  SFc20_RaspPiPilotInstanceStruct *chartInstance;
  chartInstance = (SFc20_RaspPiPilotInstanceStruct *)chartInstanceVoid;
  c20_blueIntensity = sf_mex_dup(c20_mxArrayInData);
  c20_identifier = c20_varName;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c20_blueIntensity),
    &c20_thisId, c20_y);
  sf_mex_destroy(&c20_blueIntensity);
  c20_i18 = 0;
  for (c20_i19 = 0; c20_i19 < 240; c20_i19++) {
    for (c20_i20 = 0; c20_i20 < 320; c20_i20++) {
      (*(uint8_T (*)[76800])c20_outData)[c20_i20 + c20_i18] = c20_y[c20_i20 +
        c20_i18];
    }

    c20_i18 += 320;
  }

  sf_mex_destroy(&c20_mxArrayInData);
}

static const mxArray *c20_b_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData)
{
  const mxArray *c20_mxArrayOutData = NULL;
  real_T c20_u;
  const mxArray *c20_y = NULL;
  SFc20_RaspPiPilotInstanceStruct *chartInstance;
  chartInstance = (SFc20_RaspPiPilotInstanceStruct *)chartInstanceVoid;
  c20_mxArrayOutData = NULL;
  c20_u = *(real_T *)c20_inData;
  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", &c20_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c20_mxArrayOutData, c20_y, false);
  return c20_mxArrayOutData;
}

static real_T c20_c_emlrt_marshallIn(SFc20_RaspPiPilotInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId)
{
  real_T c20_y;
  real_T c20_d0;
  (void)chartInstance;
  sf_mex_import(c20_parentId, sf_mex_dup(c20_u), &c20_d0, 1, 0, 0U, 0, 0U, 0);
  c20_y = c20_d0;
  sf_mex_destroy(&c20_u);
  return c20_y;
}

static void c20_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData)
{
  const mxArray *c20_nargout;
  const char_T *c20_identifier;
  emlrtMsgIdentifier c20_thisId;
  real_T c20_y;
  SFc20_RaspPiPilotInstanceStruct *chartInstance;
  chartInstance = (SFc20_RaspPiPilotInstanceStruct *)chartInstanceVoid;
  c20_nargout = sf_mex_dup(c20_mxArrayInData);
  c20_identifier = c20_varName;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_y = c20_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c20_nargout),
    &c20_thisId);
  sf_mex_destroy(&c20_nargout);
  *(real_T *)c20_outData = c20_y;
  sf_mex_destroy(&c20_mxArrayInData);
}

const mxArray *sf_c20_RaspPiPilot_get_eml_resolved_functions_info(void)
{
  const mxArray *c20_nameCaptureInfo = NULL;
  c20_nameCaptureInfo = NULL;
  sf_mex_assign(&c20_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c20_nameCaptureInfo;
}

static const mxArray *c20_c_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData)
{
  const mxArray *c20_mxArrayOutData = NULL;
  int32_T c20_u;
  const mxArray *c20_y = NULL;
  SFc20_RaspPiPilotInstanceStruct *chartInstance;
  chartInstance = (SFc20_RaspPiPilotInstanceStruct *)chartInstanceVoid;
  c20_mxArrayOutData = NULL;
  c20_u = *(int32_T *)c20_inData;
  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", &c20_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c20_mxArrayOutData, c20_y, false);
  return c20_mxArrayOutData;
}

static int32_T c20_d_emlrt_marshallIn(SFc20_RaspPiPilotInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId)
{
  int32_T c20_y;
  int32_T c20_i21;
  (void)chartInstance;
  sf_mex_import(c20_parentId, sf_mex_dup(c20_u), &c20_i21, 1, 6, 0U, 0, 0U, 0);
  c20_y = c20_i21;
  sf_mex_destroy(&c20_u);
  return c20_y;
}

static void c20_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData)
{
  const mxArray *c20_b_sfEvent;
  const char_T *c20_identifier;
  emlrtMsgIdentifier c20_thisId;
  int32_T c20_y;
  SFc20_RaspPiPilotInstanceStruct *chartInstance;
  chartInstance = (SFc20_RaspPiPilotInstanceStruct *)chartInstanceVoid;
  c20_b_sfEvent = sf_mex_dup(c20_mxArrayInData);
  c20_identifier = c20_varName;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_y = c20_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c20_b_sfEvent),
    &c20_thisId);
  sf_mex_destroy(&c20_b_sfEvent);
  *(int32_T *)c20_outData = c20_y;
  sf_mex_destroy(&c20_mxArrayInData);
}

static uint8_T c20_e_emlrt_marshallIn(SFc20_RaspPiPilotInstanceStruct
  *chartInstance, const mxArray *c20_b_is_active_c20_RaspPiPilot, const char_T
  *c20_identifier)
{
  uint8_T c20_y;
  emlrtMsgIdentifier c20_thisId;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_y = c20_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c20_b_is_active_c20_RaspPiPilot), &c20_thisId);
  sf_mex_destroy(&c20_b_is_active_c20_RaspPiPilot);
  return c20_y;
}

static uint8_T c20_f_emlrt_marshallIn(SFc20_RaspPiPilotInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId)
{
  uint8_T c20_y;
  uint8_T c20_u1;
  (void)chartInstance;
  sf_mex_import(c20_parentId, sf_mex_dup(c20_u), &c20_u1, 1, 3, 0U, 0, 0U, 0);
  c20_y = c20_u1;
  sf_mex_destroy(&c20_u);
  return c20_y;
}

static void init_dsm_address_info(SFc20_RaspPiPilotInstanceStruct *chartInstance)
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

void sf_c20_RaspPiPilot_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2512134646U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3783396080U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1375995737U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(765522011U);
}

mxArray *sf_c20_RaspPiPilot_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("clbudVQ6qzX7EHLRnnr53");
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

mxArray *sf_c20_RaspPiPilot_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c20_RaspPiPilot_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c20_RaspPiPilot(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[11],T\"blueIntensity\",},{M[8],M[0],T\"is_active_c20_RaspPiPilot\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c20_RaspPiPilot_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc20_RaspPiPilotInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc20_RaspPiPilotInstanceStruct *) chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _RaspPiPilotMachineNumber_,
           20,
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
          _SFD_SET_DATA_PROPS(1,1,1,0,"G");
          _SFD_SET_DATA_PROPS(2,1,1,0,"B");
          _SFD_SET_DATA_PROPS(3,2,0,1,"blueIntensity");
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
        _SFD_CV_INIT_EML(0,1,1,0,0,1,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,66);
        _SFD_CV_INIT_EML_SATURATION(0,1,0,62,-1,65);

        {
          unsigned int dimVector[2];
          dimVector[0]= 320;
          dimVector[1]= 240;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_UINT8,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c20_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 320;
          dimVector[1]= 240;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_UINT8,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c20_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 320;
          dimVector[1]= 240;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_UINT8,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c20_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 320;
          dimVector[1]= 240;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_UINT8,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c20_sf_marshallOut,(MexInFcnForType)
            c20_sf_marshallIn);
        }

        {
          uint8_T (*c20_R)[76800];
          uint8_T (*c20_G)[76800];
          uint8_T (*c20_B)[76800];
          uint8_T (*c20_blueIntensity)[76800];
          c20_blueIntensity = (uint8_T (*)[76800])ssGetOutputPortSignal
            (chartInstance->S, 1);
          c20_B = (uint8_T (*)[76800])ssGetInputPortSignal(chartInstance->S, 2);
          c20_G = (uint8_T (*)[76800])ssGetInputPortSignal(chartInstance->S, 1);
          c20_R = (uint8_T (*)[76800])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c20_R);
          _SFD_SET_DATA_VALUE_PTR(1U, *c20_G);
          _SFD_SET_DATA_VALUE_PTR(2U, *c20_B);
          _SFD_SET_DATA_VALUE_PTR(3U, *c20_blueIntensity);
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
  return "EEBXlg3MGfgHm3pW0nqGiF";
}

static void sf_opaque_initialize_c20_RaspPiPilot(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc20_RaspPiPilotInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c20_RaspPiPilot((SFc20_RaspPiPilotInstanceStruct*)
    chartInstanceVar);
  initialize_c20_RaspPiPilot((SFc20_RaspPiPilotInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c20_RaspPiPilot(void *chartInstanceVar)
{
  enable_c20_RaspPiPilot((SFc20_RaspPiPilotInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c20_RaspPiPilot(void *chartInstanceVar)
{
  disable_c20_RaspPiPilot((SFc20_RaspPiPilotInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c20_RaspPiPilot(void *chartInstanceVar)
{
  sf_gateway_c20_RaspPiPilot((SFc20_RaspPiPilotInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c20_RaspPiPilot(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c20_RaspPiPilot
    ((SFc20_RaspPiPilotInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c20_RaspPiPilot();/* state var info */
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

extern void sf_internal_set_sim_state_c20_RaspPiPilot(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c20_RaspPiPilot();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c20_RaspPiPilot((SFc20_RaspPiPilotInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c20_RaspPiPilot(SimStruct* S)
{
  return sf_internal_get_sim_state_c20_RaspPiPilot(S);
}

static void sf_opaque_set_sim_state_c20_RaspPiPilot(SimStruct* S, const mxArray *
  st)
{
  sf_internal_set_sim_state_c20_RaspPiPilot(S, st);
}

static void sf_opaque_terminate_c20_RaspPiPilot(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc20_RaspPiPilotInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_RaspPiPilot_optimization_info();
    }

    finalize_c20_RaspPiPilot((SFc20_RaspPiPilotInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    if (crtInfo != NULL) {
      utFree((void *)crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc20_RaspPiPilot((SFc20_RaspPiPilotInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c20_RaspPiPilot(SimStruct *S)
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
    initialize_params_c20_RaspPiPilot((SFc20_RaspPiPilotInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c20_RaspPiPilot(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_RaspPiPilot_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      20);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,20,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,20,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,20);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,20,3);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,20,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,20);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(707123943U));
  ssSetChecksum1(S,(1470928285U));
  ssSetChecksum2(S,(4022878243U));
  ssSetChecksum3(S,(4130351650U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c20_RaspPiPilot(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c20_RaspPiPilot(SimStruct *S)
{
  SFc20_RaspPiPilotInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc20_RaspPiPilotInstanceStruct *)utMalloc(sizeof
    (SFc20_RaspPiPilotInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc20_RaspPiPilotInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c20_RaspPiPilot;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c20_RaspPiPilot;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c20_RaspPiPilot;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c20_RaspPiPilot;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c20_RaspPiPilot;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c20_RaspPiPilot;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c20_RaspPiPilot;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c20_RaspPiPilot;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c20_RaspPiPilot;
  chartInstance->chartInfo.mdlStart = mdlStart_c20_RaspPiPilot;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c20_RaspPiPilot;
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

void c20_RaspPiPilot_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c20_RaspPiPilot(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c20_RaspPiPilot(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c20_RaspPiPilot(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c20_RaspPiPilot_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
