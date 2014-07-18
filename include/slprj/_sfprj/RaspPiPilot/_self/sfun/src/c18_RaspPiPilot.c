/* Include files */

#include <stddef.h>
#include "blas.h"
#include "RaspPiPilot_sfun.h"
#include "c18_RaspPiPilot.h"
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
static const char * c18_debug_family_names[8] = { "l", "y", "i", "nargin",
  "nargout", "area", "centroid", "centroid_largest" };

/* Function Declarations */
static void initialize_c18_RaspPiPilot(SFc18_RaspPiPilotInstanceStruct
  *chartInstance);
static void initialize_params_c18_RaspPiPilot(SFc18_RaspPiPilotInstanceStruct
  *chartInstance);
static void enable_c18_RaspPiPilot(SFc18_RaspPiPilotInstanceStruct
  *chartInstance);
static void disable_c18_RaspPiPilot(SFc18_RaspPiPilotInstanceStruct
  *chartInstance);
static void c18_update_debugger_state_c18_RaspPiPilot
  (SFc18_RaspPiPilotInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c18_RaspPiPilot
  (SFc18_RaspPiPilotInstanceStruct *chartInstance);
static void set_sim_state_c18_RaspPiPilot(SFc18_RaspPiPilotInstanceStruct
  *chartInstance, const mxArray *c18_st);
static void finalize_c18_RaspPiPilot(SFc18_RaspPiPilotInstanceStruct
  *chartInstance);
static void sf_gateway_c18_RaspPiPilot(SFc18_RaspPiPilotInstanceStruct
  *chartInstance);
static void initSimStructsc18_RaspPiPilot(SFc18_RaspPiPilotInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c18_machineNumber, uint32_T
  c18_chartNumber, uint32_T c18_instanceNumber);
static const mxArray *c18_sf_marshallOut(void *chartInstanceVoid, void
  *c18_inData);
static void c18_emlrt_marshallIn(SFc18_RaspPiPilotInstanceStruct *chartInstance,
  const mxArray *c18_centroid_largest, const char_T *c18_identifier, real_T
  c18_y[6]);
static void c18_b_emlrt_marshallIn(SFc18_RaspPiPilotInstanceStruct
  *chartInstance, const mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId,
  real_T c18_y[6]);
static void c18_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c18_mxArrayInData, const char_T *c18_varName, void *c18_outData);
static const mxArray *c18_b_sf_marshallOut(void *chartInstanceVoid, void
  *c18_inData);
static const mxArray *c18_c_sf_marshallOut(void *chartInstanceVoid, void
  *c18_inData);
static const mxArray *c18_d_sf_marshallOut(void *chartInstanceVoid, void
  *c18_inData);
static real_T c18_c_emlrt_marshallIn(SFc18_RaspPiPilotInstanceStruct
  *chartInstance, const mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId);
static void c18_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c18_mxArrayInData, const char_T *c18_varName, void *c18_outData);
static const mxArray *c18_e_sf_marshallOut(void *chartInstanceVoid, void
  *c18_inData);
static void c18_d_emlrt_marshallIn(SFc18_RaspPiPilotInstanceStruct
  *chartInstance, const mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId,
  real_T c18_y[16]);
static void c18_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c18_mxArrayInData, const char_T *c18_varName, void *c18_outData);
static const mxArray *c18_f_sf_marshallOut(void *chartInstanceVoid, void
  *c18_inData);
static void c18_e_emlrt_marshallIn(SFc18_RaspPiPilotInstanceStruct
  *chartInstance, const mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId,
  int32_T c18_y[16]);
static void c18_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c18_mxArrayInData, const char_T *c18_varName, void *c18_outData);
static void c18_info_helper(const mxArray **c18_info);
static const mxArray *c18_emlrt_marshallOut(const char * c18_u);
static const mxArray *c18_b_emlrt_marshallOut(const uint32_T c18_u);
static void c18_eml_sort(SFc18_RaspPiPilotInstanceStruct *chartInstance, int32_T
  c18_x[16], int32_T c18_y[16], int32_T c18_idx[16]);
static void c18_eml_sort_idx(SFc18_RaspPiPilotInstanceStruct *chartInstance,
  int32_T c18_x[16], int32_T c18_idx[16], int32_T c18_y[16]);
static void c18_check_forloop_overflow_error(SFc18_RaspPiPilotInstanceStruct
  *chartInstance, boolean_T c18_overflow);
static const mxArray *c18_g_sf_marshallOut(void *chartInstanceVoid, void
  *c18_inData);
static int32_T c18_f_emlrt_marshallIn(SFc18_RaspPiPilotInstanceStruct
  *chartInstance, const mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId);
static void c18_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c18_mxArrayInData, const char_T *c18_varName, void *c18_outData);
static uint8_T c18_g_emlrt_marshallIn(SFc18_RaspPiPilotInstanceStruct
  *chartInstance, const mxArray *c18_b_is_active_c18_RaspPiPilot, const char_T
  *c18_identifier);
static uint8_T c18_h_emlrt_marshallIn(SFc18_RaspPiPilotInstanceStruct
  *chartInstance, const mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId);
static void init_dsm_address_info(SFc18_RaspPiPilotInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c18_RaspPiPilot(SFc18_RaspPiPilotInstanceStruct
  *chartInstance)
{
  chartInstance->c18_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c18_is_active_c18_RaspPiPilot = 0U;
}

static void initialize_params_c18_RaspPiPilot(SFc18_RaspPiPilotInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void enable_c18_RaspPiPilot(SFc18_RaspPiPilotInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c18_RaspPiPilot(SFc18_RaspPiPilotInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c18_update_debugger_state_c18_RaspPiPilot
  (SFc18_RaspPiPilotInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c18_RaspPiPilot
  (SFc18_RaspPiPilotInstanceStruct *chartInstance)
{
  const mxArray *c18_st;
  const mxArray *c18_y = NULL;
  int32_T c18_i0;
  real_T c18_u[6];
  const mxArray *c18_b_y = NULL;
  uint8_T c18_hoistedGlobal;
  uint8_T c18_b_u;
  const mxArray *c18_c_y = NULL;
  real_T (*c18_centroid_largest)[6];
  c18_centroid_largest = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S,
    1);
  c18_st = NULL;
  c18_st = NULL;
  c18_y = NULL;
  sf_mex_assign(&c18_y, sf_mex_createcellmatrix(2, 1), false);
  for (c18_i0 = 0; c18_i0 < 6; c18_i0++) {
    c18_u[c18_i0] = (*c18_centroid_largest)[c18_i0];
  }

  c18_b_y = NULL;
  sf_mex_assign(&c18_b_y, sf_mex_create("y", c18_u, 0, 0U, 1U, 0U, 2, 3, 2),
                false);
  sf_mex_setcell(c18_y, 0, c18_b_y);
  c18_hoistedGlobal = chartInstance->c18_is_active_c18_RaspPiPilot;
  c18_b_u = c18_hoistedGlobal;
  c18_c_y = NULL;
  sf_mex_assign(&c18_c_y, sf_mex_create("y", &c18_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c18_y, 1, c18_c_y);
  sf_mex_assign(&c18_st, c18_y, false);
  return c18_st;
}

static void set_sim_state_c18_RaspPiPilot(SFc18_RaspPiPilotInstanceStruct
  *chartInstance, const mxArray *c18_st)
{
  const mxArray *c18_u;
  real_T c18_dv0[6];
  int32_T c18_i1;
  real_T (*c18_centroid_largest)[6];
  c18_centroid_largest = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S,
    1);
  chartInstance->c18_doneDoubleBufferReInit = true;
  c18_u = sf_mex_dup(c18_st);
  c18_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c18_u, 0)),
                       "centroid_largest", c18_dv0);
  for (c18_i1 = 0; c18_i1 < 6; c18_i1++) {
    (*c18_centroid_largest)[c18_i1] = c18_dv0[c18_i1];
  }

  chartInstance->c18_is_active_c18_RaspPiPilot = c18_g_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c18_u, 1)),
     "is_active_c18_RaspPiPilot");
  sf_mex_destroy(&c18_u);
  c18_update_debugger_state_c18_RaspPiPilot(chartInstance);
  sf_mex_destroy(&c18_st);
}

static void finalize_c18_RaspPiPilot(SFc18_RaspPiPilotInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c18_RaspPiPilot(SFc18_RaspPiPilotInstanceStruct
  *chartInstance)
{
  int32_T c18_i2;
  int32_T c18_area[16];
  int32_T c18_i3;
  real_T c18_centroid[32];
  uint32_T c18_debug_family_var_map[8];
  real_T c18_l;
  int32_T c18_y[16];
  real_T c18_i[16];
  real_T c18_nargin = 2.0;
  real_T c18_nargout = 1.0;
  real_T c18_centroid_largest[6];
  int32_T c18_i4;
  int32_T c18_x[16];
  int32_T c18_i5;
  int32_T c18_b_x[16];
  int32_T c18_iidx[16];
  int32_T c18_i6;
  real_T c18_b_i[16];
  int32_T c18_i7;
  int32_T c18_i8;
  int32_T c18_c_i;
  int32_T c18_d_i;
  int32_T c18_e_i;
  int32_T c18_i9;
  int32_T c18_i10;
  int32_T c18_i11;
  int32_T c18_i12;
  int32_T c18_i13;
  int32_T c18_i14;
  int32_T c18_i15;
  real_T (*c18_b_centroid_largest)[6];
  real_T (*c18_b_centroid)[32];
  int32_T (*c18_b_area)[16];
  c18_b_centroid = (real_T (*)[32])ssGetInputPortSignal(chartInstance->S, 1);
  c18_b_area = (int32_T (*)[16])ssGetInputPortSignal(chartInstance->S, 0);
  c18_b_centroid_largest = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S,
    1);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 17U, chartInstance->c18_sfEvent);
  chartInstance->c18_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 17U, chartInstance->c18_sfEvent);
  for (c18_i2 = 0; c18_i2 < 16; c18_i2++) {
    c18_area[c18_i2] = (*c18_b_area)[c18_i2];
  }

  for (c18_i3 = 0; c18_i3 < 32; c18_i3++) {
    c18_centroid[c18_i3] = (*c18_b_centroid)[c18_i3];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 8U, 8U, c18_debug_family_names,
    c18_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c18_l, 0U, c18_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c18_y, 1U, c18_f_sf_marshallOut,
    c18_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c18_i, 2U, c18_e_sf_marshallOut,
    c18_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c18_nargin, 3U, c18_d_sf_marshallOut,
    c18_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c18_nargout, 4U, c18_d_sf_marshallOut,
    c18_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c18_area, 5U, c18_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c18_centroid, 6U, c18_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c18_centroid_largest, 7U,
    c18_sf_marshallOut, c18_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c18_sfEvent, 3);
  c18_l = 16.0;
  _SFD_EML_CALL(0U, chartInstance->c18_sfEvent, 4);
  for (c18_i4 = 0; c18_i4 < 16; c18_i4++) {
    c18_x[c18_i4] = c18_area[c18_i4];
  }

  for (c18_i5 = 0; c18_i5 < 16; c18_i5++) {
    c18_b_x[c18_i5] = c18_x[c18_i5];
  }

  c18_eml_sort(chartInstance, c18_b_x, c18_x, c18_iidx);
  for (c18_i6 = 0; c18_i6 < 16; c18_i6++) {
    c18_b_i[c18_i6] = (real_T)c18_iidx[c18_i6];
  }

  for (c18_i7 = 0; c18_i7 < 16; c18_i7++) {
    c18_y[c18_i7] = c18_x[c18_i7];
  }

  for (c18_i8 = 0; c18_i8 < 16; c18_i8++) {
    c18_i[c18_i8] = c18_b_i[c18_i8];
  }

  _SFD_EML_CALL(0U, chartInstance->c18_sfEvent, 5);
  c18_c_i = _SFD_EML_ARRAY_BOUNDS_CHECK("centroid", (int32_T)_SFD_INTEGER_CHECK(
    "i(l)", c18_i[15]), 1, 16, 1, 0) - 1;
  c18_d_i = _SFD_EML_ARRAY_BOUNDS_CHECK("centroid", (int32_T)_SFD_INTEGER_CHECK(
    "i(l-1)", c18_i[14]), 1, 16, 1, 0) - 1;
  c18_e_i = _SFD_EML_ARRAY_BOUNDS_CHECK("centroid", (int32_T)_SFD_INTEGER_CHECK(
    "i(l-2)", c18_i[13]), 1, 16, 1, 0) - 1;
  for (c18_i9 = 0; c18_i9 < 2; c18_i9++) {
    c18_centroid_largest[3 * c18_i9] = c18_centroid[c18_c_i + (c18_i9 << 4)];
  }

  for (c18_i10 = 0; c18_i10 < 2; c18_i10++) {
    c18_centroid_largest[1 + 3 * c18_i10] = c18_centroid[c18_d_i + (c18_i10 << 4)];
  }

  for (c18_i11 = 0; c18_i11 < 2; c18_i11++) {
    c18_centroid_largest[2 + 3 * c18_i11] = c18_centroid[c18_e_i + (c18_i11 << 4)];
  }

  _SFD_EML_CALL(0U, chartInstance->c18_sfEvent, -5);
  _SFD_SYMBOL_SCOPE_POP();
  for (c18_i12 = 0; c18_i12 < 6; c18_i12++) {
    (*c18_b_centroid_largest)[c18_i12] = c18_centroid_largest[c18_i12];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 17U, chartInstance->c18_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_RaspPiPilotMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c18_i13 = 0; c18_i13 < 6; c18_i13++) {
    _SFD_DATA_RANGE_CHECK((*c18_b_centroid_largest)[c18_i13], 0U);
  }

  for (c18_i14 = 0; c18_i14 < 16; c18_i14++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c18_b_area)[c18_i14], 1U);
  }

  for (c18_i15 = 0; c18_i15 < 32; c18_i15++) {
    _SFD_DATA_RANGE_CHECK((*c18_b_centroid)[c18_i15], 2U);
  }
}

static void initSimStructsc18_RaspPiPilot(SFc18_RaspPiPilotInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c18_machineNumber, uint32_T
  c18_chartNumber, uint32_T c18_instanceNumber)
{
  (void)c18_machineNumber;
  (void)c18_chartNumber;
  (void)c18_instanceNumber;
}

static const mxArray *c18_sf_marshallOut(void *chartInstanceVoid, void
  *c18_inData)
{
  const mxArray *c18_mxArrayOutData = NULL;
  int32_T c18_i16;
  int32_T c18_i17;
  int32_T c18_i18;
  real_T c18_b_inData[6];
  int32_T c18_i19;
  int32_T c18_i20;
  int32_T c18_i21;
  real_T c18_u[6];
  const mxArray *c18_y = NULL;
  SFc18_RaspPiPilotInstanceStruct *chartInstance;
  chartInstance = (SFc18_RaspPiPilotInstanceStruct *)chartInstanceVoid;
  c18_mxArrayOutData = NULL;
  c18_i16 = 0;
  for (c18_i17 = 0; c18_i17 < 2; c18_i17++) {
    for (c18_i18 = 0; c18_i18 < 3; c18_i18++) {
      c18_b_inData[c18_i18 + c18_i16] = (*(real_T (*)[6])c18_inData)[c18_i18 +
        c18_i16];
    }

    c18_i16 += 3;
  }

  c18_i19 = 0;
  for (c18_i20 = 0; c18_i20 < 2; c18_i20++) {
    for (c18_i21 = 0; c18_i21 < 3; c18_i21++) {
      c18_u[c18_i21 + c18_i19] = c18_b_inData[c18_i21 + c18_i19];
    }

    c18_i19 += 3;
  }

  c18_y = NULL;
  sf_mex_assign(&c18_y, sf_mex_create("y", c18_u, 0, 0U, 1U, 0U, 2, 3, 2), false);
  sf_mex_assign(&c18_mxArrayOutData, c18_y, false);
  return c18_mxArrayOutData;
}

static void c18_emlrt_marshallIn(SFc18_RaspPiPilotInstanceStruct *chartInstance,
  const mxArray *c18_centroid_largest, const char_T *c18_identifier, real_T
  c18_y[6])
{
  emlrtMsgIdentifier c18_thisId;
  c18_thisId.fIdentifier = c18_identifier;
  c18_thisId.fParent = NULL;
  c18_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c18_centroid_largest),
    &c18_thisId, c18_y);
  sf_mex_destroy(&c18_centroid_largest);
}

static void c18_b_emlrt_marshallIn(SFc18_RaspPiPilotInstanceStruct
  *chartInstance, const mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId,
  real_T c18_y[6])
{
  real_T c18_dv1[6];
  int32_T c18_i22;
  (void)chartInstance;
  sf_mex_import(c18_parentId, sf_mex_dup(c18_u), c18_dv1, 1, 0, 0U, 1, 0U, 2, 3,
                2);
  for (c18_i22 = 0; c18_i22 < 6; c18_i22++) {
    c18_y[c18_i22] = c18_dv1[c18_i22];
  }

  sf_mex_destroy(&c18_u);
}

static void c18_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c18_mxArrayInData, const char_T *c18_varName, void *c18_outData)
{
  const mxArray *c18_centroid_largest;
  const char_T *c18_identifier;
  emlrtMsgIdentifier c18_thisId;
  real_T c18_y[6];
  int32_T c18_i23;
  int32_T c18_i24;
  int32_T c18_i25;
  SFc18_RaspPiPilotInstanceStruct *chartInstance;
  chartInstance = (SFc18_RaspPiPilotInstanceStruct *)chartInstanceVoid;
  c18_centroid_largest = sf_mex_dup(c18_mxArrayInData);
  c18_identifier = c18_varName;
  c18_thisId.fIdentifier = c18_identifier;
  c18_thisId.fParent = NULL;
  c18_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c18_centroid_largest),
    &c18_thisId, c18_y);
  sf_mex_destroy(&c18_centroid_largest);
  c18_i23 = 0;
  for (c18_i24 = 0; c18_i24 < 2; c18_i24++) {
    for (c18_i25 = 0; c18_i25 < 3; c18_i25++) {
      (*(real_T (*)[6])c18_outData)[c18_i25 + c18_i23] = c18_y[c18_i25 + c18_i23];
    }

    c18_i23 += 3;
  }

  sf_mex_destroy(&c18_mxArrayInData);
}

static const mxArray *c18_b_sf_marshallOut(void *chartInstanceVoid, void
  *c18_inData)
{
  const mxArray *c18_mxArrayOutData = NULL;
  int32_T c18_i26;
  int32_T c18_i27;
  int32_T c18_i28;
  real_T c18_b_inData[32];
  int32_T c18_i29;
  int32_T c18_i30;
  int32_T c18_i31;
  real_T c18_u[32];
  const mxArray *c18_y = NULL;
  SFc18_RaspPiPilotInstanceStruct *chartInstance;
  chartInstance = (SFc18_RaspPiPilotInstanceStruct *)chartInstanceVoid;
  c18_mxArrayOutData = NULL;
  c18_i26 = 0;
  for (c18_i27 = 0; c18_i27 < 2; c18_i27++) {
    for (c18_i28 = 0; c18_i28 < 16; c18_i28++) {
      c18_b_inData[c18_i28 + c18_i26] = (*(real_T (*)[32])c18_inData)[c18_i28 +
        c18_i26];
    }

    c18_i26 += 16;
  }

  c18_i29 = 0;
  for (c18_i30 = 0; c18_i30 < 2; c18_i30++) {
    for (c18_i31 = 0; c18_i31 < 16; c18_i31++) {
      c18_u[c18_i31 + c18_i29] = c18_b_inData[c18_i31 + c18_i29];
    }

    c18_i29 += 16;
  }

  c18_y = NULL;
  sf_mex_assign(&c18_y, sf_mex_create("y", c18_u, 0, 0U, 1U, 0U, 2, 16, 2),
                false);
  sf_mex_assign(&c18_mxArrayOutData, c18_y, false);
  return c18_mxArrayOutData;
}

static const mxArray *c18_c_sf_marshallOut(void *chartInstanceVoid, void
  *c18_inData)
{
  const mxArray *c18_mxArrayOutData = NULL;
  int32_T c18_i32;
  int32_T c18_b_inData[16];
  int32_T c18_i33;
  int32_T c18_u[16];
  const mxArray *c18_y = NULL;
  SFc18_RaspPiPilotInstanceStruct *chartInstance;
  chartInstance = (SFc18_RaspPiPilotInstanceStruct *)chartInstanceVoid;
  c18_mxArrayOutData = NULL;
  for (c18_i32 = 0; c18_i32 < 16; c18_i32++) {
    c18_b_inData[c18_i32] = (*(int32_T (*)[16])c18_inData)[c18_i32];
  }

  for (c18_i33 = 0; c18_i33 < 16; c18_i33++) {
    c18_u[c18_i33] = c18_b_inData[c18_i33];
  }

  c18_y = NULL;
  sf_mex_assign(&c18_y, sf_mex_create("y", c18_u, 6, 0U, 1U, 0U, 2, 16, 1),
                false);
  sf_mex_assign(&c18_mxArrayOutData, c18_y, false);
  return c18_mxArrayOutData;
}

static const mxArray *c18_d_sf_marshallOut(void *chartInstanceVoid, void
  *c18_inData)
{
  const mxArray *c18_mxArrayOutData = NULL;
  real_T c18_u;
  const mxArray *c18_y = NULL;
  SFc18_RaspPiPilotInstanceStruct *chartInstance;
  chartInstance = (SFc18_RaspPiPilotInstanceStruct *)chartInstanceVoid;
  c18_mxArrayOutData = NULL;
  c18_u = *(real_T *)c18_inData;
  c18_y = NULL;
  sf_mex_assign(&c18_y, sf_mex_create("y", &c18_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c18_mxArrayOutData, c18_y, false);
  return c18_mxArrayOutData;
}

static real_T c18_c_emlrt_marshallIn(SFc18_RaspPiPilotInstanceStruct
  *chartInstance, const mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId)
{
  real_T c18_y;
  real_T c18_d0;
  (void)chartInstance;
  sf_mex_import(c18_parentId, sf_mex_dup(c18_u), &c18_d0, 1, 0, 0U, 0, 0U, 0);
  c18_y = c18_d0;
  sf_mex_destroy(&c18_u);
  return c18_y;
}

static void c18_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c18_mxArrayInData, const char_T *c18_varName, void *c18_outData)
{
  const mxArray *c18_nargout;
  const char_T *c18_identifier;
  emlrtMsgIdentifier c18_thisId;
  real_T c18_y;
  SFc18_RaspPiPilotInstanceStruct *chartInstance;
  chartInstance = (SFc18_RaspPiPilotInstanceStruct *)chartInstanceVoid;
  c18_nargout = sf_mex_dup(c18_mxArrayInData);
  c18_identifier = c18_varName;
  c18_thisId.fIdentifier = c18_identifier;
  c18_thisId.fParent = NULL;
  c18_y = c18_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c18_nargout),
    &c18_thisId);
  sf_mex_destroy(&c18_nargout);
  *(real_T *)c18_outData = c18_y;
  sf_mex_destroy(&c18_mxArrayInData);
}

static const mxArray *c18_e_sf_marshallOut(void *chartInstanceVoid, void
  *c18_inData)
{
  const mxArray *c18_mxArrayOutData = NULL;
  int32_T c18_i34;
  real_T c18_b_inData[16];
  int32_T c18_i35;
  real_T c18_u[16];
  const mxArray *c18_y = NULL;
  SFc18_RaspPiPilotInstanceStruct *chartInstance;
  chartInstance = (SFc18_RaspPiPilotInstanceStruct *)chartInstanceVoid;
  c18_mxArrayOutData = NULL;
  for (c18_i34 = 0; c18_i34 < 16; c18_i34++) {
    c18_b_inData[c18_i34] = (*(real_T (*)[16])c18_inData)[c18_i34];
  }

  for (c18_i35 = 0; c18_i35 < 16; c18_i35++) {
    c18_u[c18_i35] = c18_b_inData[c18_i35];
  }

  c18_y = NULL;
  sf_mex_assign(&c18_y, sf_mex_create("y", c18_u, 0, 0U, 1U, 0U, 1, 16), false);
  sf_mex_assign(&c18_mxArrayOutData, c18_y, false);
  return c18_mxArrayOutData;
}

static void c18_d_emlrt_marshallIn(SFc18_RaspPiPilotInstanceStruct
  *chartInstance, const mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId,
  real_T c18_y[16])
{
  real_T c18_dv2[16];
  int32_T c18_i36;
  (void)chartInstance;
  sf_mex_import(c18_parentId, sf_mex_dup(c18_u), c18_dv2, 1, 0, 0U, 1, 0U, 1, 16);
  for (c18_i36 = 0; c18_i36 < 16; c18_i36++) {
    c18_y[c18_i36] = c18_dv2[c18_i36];
  }

  sf_mex_destroy(&c18_u);
}

static void c18_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c18_mxArrayInData, const char_T *c18_varName, void *c18_outData)
{
  const mxArray *c18_i;
  const char_T *c18_identifier;
  emlrtMsgIdentifier c18_thisId;
  real_T c18_y[16];
  int32_T c18_i37;
  SFc18_RaspPiPilotInstanceStruct *chartInstance;
  chartInstance = (SFc18_RaspPiPilotInstanceStruct *)chartInstanceVoid;
  c18_i = sf_mex_dup(c18_mxArrayInData);
  c18_identifier = c18_varName;
  c18_thisId.fIdentifier = c18_identifier;
  c18_thisId.fParent = NULL;
  c18_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c18_i), &c18_thisId, c18_y);
  sf_mex_destroy(&c18_i);
  for (c18_i37 = 0; c18_i37 < 16; c18_i37++) {
    (*(real_T (*)[16])c18_outData)[c18_i37] = c18_y[c18_i37];
  }

  sf_mex_destroy(&c18_mxArrayInData);
}

static const mxArray *c18_f_sf_marshallOut(void *chartInstanceVoid, void
  *c18_inData)
{
  const mxArray *c18_mxArrayOutData = NULL;
  int32_T c18_i38;
  int32_T c18_b_inData[16];
  int32_T c18_i39;
  int32_T c18_u[16];
  const mxArray *c18_y = NULL;
  SFc18_RaspPiPilotInstanceStruct *chartInstance;
  chartInstance = (SFc18_RaspPiPilotInstanceStruct *)chartInstanceVoid;
  c18_mxArrayOutData = NULL;
  for (c18_i38 = 0; c18_i38 < 16; c18_i38++) {
    c18_b_inData[c18_i38] = (*(int32_T (*)[16])c18_inData)[c18_i38];
  }

  for (c18_i39 = 0; c18_i39 < 16; c18_i39++) {
    c18_u[c18_i39] = c18_b_inData[c18_i39];
  }

  c18_y = NULL;
  sf_mex_assign(&c18_y, sf_mex_create("y", c18_u, 6, 0U, 1U, 0U, 1, 16), false);
  sf_mex_assign(&c18_mxArrayOutData, c18_y, false);
  return c18_mxArrayOutData;
}

static void c18_e_emlrt_marshallIn(SFc18_RaspPiPilotInstanceStruct
  *chartInstance, const mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId,
  int32_T c18_y[16])
{
  int32_T c18_iv0[16];
  int32_T c18_i40;
  (void)chartInstance;
  sf_mex_import(c18_parentId, sf_mex_dup(c18_u), c18_iv0, 1, 6, 0U, 1, 0U, 1, 16);
  for (c18_i40 = 0; c18_i40 < 16; c18_i40++) {
    c18_y[c18_i40] = c18_iv0[c18_i40];
  }

  sf_mex_destroy(&c18_u);
}

static void c18_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c18_mxArrayInData, const char_T *c18_varName, void *c18_outData)
{
  const mxArray *c18_y;
  const char_T *c18_identifier;
  emlrtMsgIdentifier c18_thisId;
  int32_T c18_b_y[16];
  int32_T c18_i41;
  SFc18_RaspPiPilotInstanceStruct *chartInstance;
  chartInstance = (SFc18_RaspPiPilotInstanceStruct *)chartInstanceVoid;
  c18_y = sf_mex_dup(c18_mxArrayInData);
  c18_identifier = c18_varName;
  c18_thisId.fIdentifier = c18_identifier;
  c18_thisId.fParent = NULL;
  c18_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c18_y), &c18_thisId, c18_b_y);
  sf_mex_destroy(&c18_y);
  for (c18_i41 = 0; c18_i41 < 16; c18_i41++) {
    (*(int32_T (*)[16])c18_outData)[c18_i41] = c18_b_y[c18_i41];
  }

  sf_mex_destroy(&c18_mxArrayInData);
}

const mxArray *sf_c18_RaspPiPilot_get_eml_resolved_functions_info(void)
{
  const mxArray *c18_nameCaptureInfo = NULL;
  c18_nameCaptureInfo = NULL;
  sf_mex_assign(&c18_nameCaptureInfo, sf_mex_createstruct("structure", 2, 39, 1),
                false);
  c18_info_helper(&c18_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c18_nameCaptureInfo);
  return c18_nameCaptureInfo;
}

static void c18_info_helper(const mxArray **c18_info)
{
  const mxArray *c18_rhs0 = NULL;
  const mxArray *c18_lhs0 = NULL;
  const mxArray *c18_rhs1 = NULL;
  const mxArray *c18_lhs1 = NULL;
  const mxArray *c18_rhs2 = NULL;
  const mxArray *c18_lhs2 = NULL;
  const mxArray *c18_rhs3 = NULL;
  const mxArray *c18_lhs3 = NULL;
  const mxArray *c18_rhs4 = NULL;
  const mxArray *c18_lhs4 = NULL;
  const mxArray *c18_rhs5 = NULL;
  const mxArray *c18_lhs5 = NULL;
  const mxArray *c18_rhs6 = NULL;
  const mxArray *c18_lhs6 = NULL;
  const mxArray *c18_rhs7 = NULL;
  const mxArray *c18_lhs7 = NULL;
  const mxArray *c18_rhs8 = NULL;
  const mxArray *c18_lhs8 = NULL;
  const mxArray *c18_rhs9 = NULL;
  const mxArray *c18_lhs9 = NULL;
  const mxArray *c18_rhs10 = NULL;
  const mxArray *c18_lhs10 = NULL;
  const mxArray *c18_rhs11 = NULL;
  const mxArray *c18_lhs11 = NULL;
  const mxArray *c18_rhs12 = NULL;
  const mxArray *c18_lhs12 = NULL;
  const mxArray *c18_rhs13 = NULL;
  const mxArray *c18_lhs13 = NULL;
  const mxArray *c18_rhs14 = NULL;
  const mxArray *c18_lhs14 = NULL;
  const mxArray *c18_rhs15 = NULL;
  const mxArray *c18_lhs15 = NULL;
  const mxArray *c18_rhs16 = NULL;
  const mxArray *c18_lhs16 = NULL;
  const mxArray *c18_rhs17 = NULL;
  const mxArray *c18_lhs17 = NULL;
  const mxArray *c18_rhs18 = NULL;
  const mxArray *c18_lhs18 = NULL;
  const mxArray *c18_rhs19 = NULL;
  const mxArray *c18_lhs19 = NULL;
  const mxArray *c18_rhs20 = NULL;
  const mxArray *c18_lhs20 = NULL;
  const mxArray *c18_rhs21 = NULL;
  const mxArray *c18_lhs21 = NULL;
  const mxArray *c18_rhs22 = NULL;
  const mxArray *c18_lhs22 = NULL;
  const mxArray *c18_rhs23 = NULL;
  const mxArray *c18_lhs23 = NULL;
  const mxArray *c18_rhs24 = NULL;
  const mxArray *c18_lhs24 = NULL;
  const mxArray *c18_rhs25 = NULL;
  const mxArray *c18_lhs25 = NULL;
  const mxArray *c18_rhs26 = NULL;
  const mxArray *c18_lhs26 = NULL;
  const mxArray *c18_rhs27 = NULL;
  const mxArray *c18_lhs27 = NULL;
  const mxArray *c18_rhs28 = NULL;
  const mxArray *c18_lhs28 = NULL;
  const mxArray *c18_rhs29 = NULL;
  const mxArray *c18_lhs29 = NULL;
  const mxArray *c18_rhs30 = NULL;
  const mxArray *c18_lhs30 = NULL;
  const mxArray *c18_rhs31 = NULL;
  const mxArray *c18_lhs31 = NULL;
  const mxArray *c18_rhs32 = NULL;
  const mxArray *c18_lhs32 = NULL;
  const mxArray *c18_rhs33 = NULL;
  const mxArray *c18_lhs33 = NULL;
  const mxArray *c18_rhs34 = NULL;
  const mxArray *c18_lhs34 = NULL;
  const mxArray *c18_rhs35 = NULL;
  const mxArray *c18_lhs35 = NULL;
  const mxArray *c18_rhs36 = NULL;
  const mxArray *c18_lhs36 = NULL;
  const mxArray *c18_rhs37 = NULL;
  const mxArray *c18_lhs37 = NULL;
  const mxArray *c18_rhs38 = NULL;
  const mxArray *c18_lhs38 = NULL;
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("length"), "name", "name", 0);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("int32"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(1303149806U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c18_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c18_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(""), "context", "context", 1);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("sort"), "name", "name", 1);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("int32"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sort.m"), "resolved",
                  "resolved", 1);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(1363717456U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c18_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c18_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sort.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 2);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("int32"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(1363718156U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c18_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c18_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sort.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("eml_sort"), "name", "name",
                  3);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("int32"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_sort.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(1314740212U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c18_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c18_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_sort.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("eml_nonsingleton_dim"),
                  "name", "name", 4);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("int32"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_nonsingleton_dim.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(1307654842U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c18_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c18_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_nonsingleton_dim.m"),
                  "context", "context", 5);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 5);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(1323174178U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c18_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c18_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_sort.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("eml_assert_valid_dim"),
                  "name", "name", 6);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 6);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_dim.m"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(1372586016U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c18_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c18_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_dim.m"),
                  "context", "context", 7);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "coder.internal.assertValidDim"), "name", "name", 7);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 7);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assertValidDim.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(1372586760U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c18_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c18_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assertValidDim.m"),
                  "context", "context", 8);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 8);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 8);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(1363718156U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c18_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c18_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assertValidDim.m"),
                  "context", "context", 9);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("floor"), "name", "name", 9);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 9);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 9);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(1363717454U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c18_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c18_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 10);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 10);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 10);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(1363718156U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c18_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c18_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 11);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 11);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 11);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(1286822326U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c18_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c18_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assertValidDim.m"),
                  "context", "context", 12);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("intmax"), "name", "name", 12);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 12);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(1362265482U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c18_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c18_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "context",
                  "context", 13);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 13);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(1381853900U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c18_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c18_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_sort.m"), "context",
                  "context", 14);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 14);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("int32"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 14);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(1375984288U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c18_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c18_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 15);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 15);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("int32"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 15);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(1389311520U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c18_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c18_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_sort.m"), "context",
                  "context", 16);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("eml_sort_idx"), "name",
                  "name", 16);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("int32"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_sort_idx.m"), "resolved",
                  "resolved", 16);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(1305321604U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c18_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c18_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_sort_idx.m"), "context",
                  "context", 17);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 17);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 17);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(1323174178U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c18_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c18_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_sort_idx.m"), "context",
                  "context", 18);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("eml_size_ispow2"), "name",
                  "name", 18);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 18);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_size_ispow2.m"),
                  "resolved", "resolved", 18);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(1363717470U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c18_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c18_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_size_ispow2.m"),
                  "context", "context", 19);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("eml_unsigned_class"), "name",
                  "name", 19);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_unsigned_class.m"),
                  "resolved", "resolved", 19);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(1375984288U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c18_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c18_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_unsigned_class.m"),
                  "context", "context", 20);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "coder.internal.unsignedClass"), "name", "name", 20);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/unsignedClass.p"),
                  "resolved", "resolved", 20);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(1389311522U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c18_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c18_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/unsignedClass.p"),
                  "context", "context", 21);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 21);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 21);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(1381853900U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c18_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c18_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/unsignedClass.p"),
                  "context", "context", 22);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 22);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 22);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(1323174178U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c18_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c18_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_sort_idx.m"), "context",
                  "context", 23);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 23);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 23);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 23);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(1372586016U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c18_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c18_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"), "context",
                  "context", 24);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 24);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 24);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 24);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(1372586760U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c18_rhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c18_lhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_sort_idx.m"), "context",
                  "context", 25);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 25);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 25);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(1375984288U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c18_rhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c18_lhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_lhs25), "lhs", "lhs",
                  25);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 26);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("intmax"), "name", "name", 26);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 26);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 26);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(1362265482U), "fileTimeLo",
                  "fileTimeLo", 26);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 26);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 26);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 26);
  sf_mex_assign(&c18_rhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c18_lhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_rhs26), "rhs", "rhs",
                  26);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_lhs26), "lhs", "lhs",
                  26);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_sort_idx.m"), "context",
                  "context", 27);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("eml_index_minus"), "name",
                  "name", 27);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 27);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m"),
                  "resolved", "resolved", 27);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(1372586016U), "fileTimeLo",
                  "fileTimeLo", 27);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 27);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 27);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 27);
  sf_mex_assign(&c18_rhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c18_lhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_rhs27), "rhs", "rhs",
                  27);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_lhs27), "lhs", "lhs",
                  27);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m"),
                  "context", "context", 28);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("coder.internal.indexMinus"),
                  "name", "name", 28);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 28);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexMinus.m"),
                  "resolved", "resolved", 28);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(1372586760U), "fileTimeLo",
                  "fileTimeLo", 28);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 28);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 28);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 28);
  sf_mex_assign(&c18_rhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c18_lhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_rhs28), "rhs", "rhs",
                  28);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_lhs28), "lhs", "lhs",
                  28);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_sort_idx.m"), "context",
                  "context", 29);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 29);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 29);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 29);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(1372586016U), "fileTimeLo",
                  "fileTimeLo", 29);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 29);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 29);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 29);
  sf_mex_assign(&c18_rhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c18_lhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_rhs29), "rhs", "rhs",
                  29);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_lhs29), "lhs", "lhs",
                  29);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"), "context",
                  "context", 30);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 30);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 30);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 30);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(1372586760U), "fileTimeLo",
                  "fileTimeLo", 30);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 30);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 30);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 30);
  sf_mex_assign(&c18_rhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c18_lhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_rhs30), "rhs", "rhs",
                  30);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_lhs30), "lhs", "lhs",
                  30);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_sort_idx.m"), "context",
                  "context", 31);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("eml_sort_le"), "name",
                  "name", 31);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("int32"), "dominantType",
                  "dominantType", 31);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_sort_le.m"), "resolved",
                  "resolved", 31);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(1292194110U), "fileTimeLo",
                  "fileTimeLo", 31);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 31);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 31);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 31);
  sf_mex_assign(&c18_rhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c18_lhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_rhs31), "rhs", "rhs",
                  31);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_lhs31), "lhs", "lhs",
                  31);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_sort_le.m!eml_sort_ascending_le"),
                  "context", "context", 32);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("eml_relop"), "name", "name",
                  32);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("function_handle"),
                  "dominantType", "dominantType", 32);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_relop.m"), "resolved",
                  "resolved", 32);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(1342454782U), "fileTimeLo",
                  "fileTimeLo", 32);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 32);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 32);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 32);
  sf_mex_assign(&c18_rhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c18_lhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_rhs32), "rhs", "rhs",
                  32);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_lhs32), "lhs", "lhs",
                  32);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_sort_le.m!eml_sort_ascending_le"),
                  "context", "context", 33);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("isnan"), "name", "name", 33);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("int32"), "dominantType",
                  "dominantType", 33);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 33);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(1363717458U), "fileTimeLo",
                  "fileTimeLo", 33);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 33);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 33);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 33);
  sf_mex_assign(&c18_rhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c18_lhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_rhs33), "rhs", "rhs",
                  33);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_lhs33), "lhs", "lhs",
                  33);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "context",
                  "context", 34);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 34);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("int32"), "dominantType",
                  "dominantType", 34);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 34);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(1363718156U), "fileTimeLo",
                  "fileTimeLo", 34);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 34);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 34);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 34);
  sf_mex_assign(&c18_rhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c18_lhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_rhs34), "rhs", "rhs",
                  34);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_lhs34), "lhs", "lhs",
                  34);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_sort_idx.m"), "context",
                  "context", 35);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("eml_index_times"), "name",
                  "name", 35);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 35);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m"),
                  "resolved", "resolved", 35);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(1372586016U), "fileTimeLo",
                  "fileTimeLo", 35);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 35);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 35);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 35);
  sf_mex_assign(&c18_rhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c18_lhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_rhs35), "rhs", "rhs",
                  35);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_lhs35), "lhs", "lhs",
                  35);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m"),
                  "context", "context", 36);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("coder.internal.indexTimes"),
                  "name", "name", 36);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 36);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexTimes.m"),
                  "resolved", "resolved", 36);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(1372586760U), "fileTimeLo",
                  "fileTimeLo", 36);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 36);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 36);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 36);
  sf_mex_assign(&c18_rhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c18_lhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_rhs36), "rhs", "rhs",
                  36);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_lhs36), "lhs", "lhs",
                  36);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_sort_idx.m"), "context",
                  "context", 37);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("eml_index_minus"), "name",
                  "name", 37);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 37);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m"),
                  "resolved", "resolved", 37);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(1372586016U), "fileTimeLo",
                  "fileTimeLo", 37);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 37);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 37);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 37);
  sf_mex_assign(&c18_rhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c18_lhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_rhs37), "rhs", "rhs",
                  37);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_lhs37), "lhs", "lhs",
                  37);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m"),
                  "context", "context", 38);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("coder.internal.indexMinus"),
                  "name", "name", 38);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 38);
  sf_mex_addfield(*c18_info, c18_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexMinus.m"),
                  "resolved", "resolved", 38);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(1372586760U), "fileTimeLo",
                  "fileTimeLo", 38);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 38);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 38);
  sf_mex_addfield(*c18_info, c18_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 38);
  sf_mex_assign(&c18_rhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c18_lhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_rhs38), "rhs", "rhs",
                  38);
  sf_mex_addfield(*c18_info, sf_mex_duplicatearraysafe(&c18_lhs38), "lhs", "lhs",
                  38);
  sf_mex_destroy(&c18_rhs0);
  sf_mex_destroy(&c18_lhs0);
  sf_mex_destroy(&c18_rhs1);
  sf_mex_destroy(&c18_lhs1);
  sf_mex_destroy(&c18_rhs2);
  sf_mex_destroy(&c18_lhs2);
  sf_mex_destroy(&c18_rhs3);
  sf_mex_destroy(&c18_lhs3);
  sf_mex_destroy(&c18_rhs4);
  sf_mex_destroy(&c18_lhs4);
  sf_mex_destroy(&c18_rhs5);
  sf_mex_destroy(&c18_lhs5);
  sf_mex_destroy(&c18_rhs6);
  sf_mex_destroy(&c18_lhs6);
  sf_mex_destroy(&c18_rhs7);
  sf_mex_destroy(&c18_lhs7);
  sf_mex_destroy(&c18_rhs8);
  sf_mex_destroy(&c18_lhs8);
  sf_mex_destroy(&c18_rhs9);
  sf_mex_destroy(&c18_lhs9);
  sf_mex_destroy(&c18_rhs10);
  sf_mex_destroy(&c18_lhs10);
  sf_mex_destroy(&c18_rhs11);
  sf_mex_destroy(&c18_lhs11);
  sf_mex_destroy(&c18_rhs12);
  sf_mex_destroy(&c18_lhs12);
  sf_mex_destroy(&c18_rhs13);
  sf_mex_destroy(&c18_lhs13);
  sf_mex_destroy(&c18_rhs14);
  sf_mex_destroy(&c18_lhs14);
  sf_mex_destroy(&c18_rhs15);
  sf_mex_destroy(&c18_lhs15);
  sf_mex_destroy(&c18_rhs16);
  sf_mex_destroy(&c18_lhs16);
  sf_mex_destroy(&c18_rhs17);
  sf_mex_destroy(&c18_lhs17);
  sf_mex_destroy(&c18_rhs18);
  sf_mex_destroy(&c18_lhs18);
  sf_mex_destroy(&c18_rhs19);
  sf_mex_destroy(&c18_lhs19);
  sf_mex_destroy(&c18_rhs20);
  sf_mex_destroy(&c18_lhs20);
  sf_mex_destroy(&c18_rhs21);
  sf_mex_destroy(&c18_lhs21);
  sf_mex_destroy(&c18_rhs22);
  sf_mex_destroy(&c18_lhs22);
  sf_mex_destroy(&c18_rhs23);
  sf_mex_destroy(&c18_lhs23);
  sf_mex_destroy(&c18_rhs24);
  sf_mex_destroy(&c18_lhs24);
  sf_mex_destroy(&c18_rhs25);
  sf_mex_destroy(&c18_lhs25);
  sf_mex_destroy(&c18_rhs26);
  sf_mex_destroy(&c18_lhs26);
  sf_mex_destroy(&c18_rhs27);
  sf_mex_destroy(&c18_lhs27);
  sf_mex_destroy(&c18_rhs28);
  sf_mex_destroy(&c18_lhs28);
  sf_mex_destroy(&c18_rhs29);
  sf_mex_destroy(&c18_lhs29);
  sf_mex_destroy(&c18_rhs30);
  sf_mex_destroy(&c18_lhs30);
  sf_mex_destroy(&c18_rhs31);
  sf_mex_destroy(&c18_lhs31);
  sf_mex_destroy(&c18_rhs32);
  sf_mex_destroy(&c18_lhs32);
  sf_mex_destroy(&c18_rhs33);
  sf_mex_destroy(&c18_lhs33);
  sf_mex_destroy(&c18_rhs34);
  sf_mex_destroy(&c18_lhs34);
  sf_mex_destroy(&c18_rhs35);
  sf_mex_destroy(&c18_lhs35);
  sf_mex_destroy(&c18_rhs36);
  sf_mex_destroy(&c18_lhs36);
  sf_mex_destroy(&c18_rhs37);
  sf_mex_destroy(&c18_lhs37);
  sf_mex_destroy(&c18_rhs38);
  sf_mex_destroy(&c18_lhs38);
}

static const mxArray *c18_emlrt_marshallOut(const char * c18_u)
{
  const mxArray *c18_y = NULL;
  c18_y = NULL;
  sf_mex_assign(&c18_y, sf_mex_create("y", c18_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c18_u)), false);
  return c18_y;
}

static const mxArray *c18_b_emlrt_marshallOut(const uint32_T c18_u)
{
  const mxArray *c18_y = NULL;
  c18_y = NULL;
  sf_mex_assign(&c18_y, sf_mex_create("y", &c18_u, 7, 0U, 0U, 0U, 0), false);
  return c18_y;
}

static void c18_eml_sort(SFc18_RaspPiPilotInstanceStruct *chartInstance, int32_T
  c18_x[16], int32_T c18_y[16], int32_T c18_idx[16])
{
  int32_T c18_i42;
  int32_T c18_b_x[16];
  for (c18_i42 = 0; c18_i42 < 16; c18_i42++) {
    c18_b_x[c18_i42] = c18_x[c18_i42];
  }

  c18_eml_sort_idx(chartInstance, c18_b_x, c18_idx, c18_y);
}

static void c18_eml_sort_idx(SFc18_RaspPiPilotInstanceStruct *chartInstance,
  int32_T c18_x[16], int32_T c18_idx[16], int32_T c18_y[16])
{
  int32_T c18_k;
  int32_T c18_b_k;
  int32_T c18_c_k;
  int32_T c18_a;
  int32_T c18_b_a;
  int32_T c18_c;
  int32_T c18_irow1;
  int32_T c18_irow2;
  int32_T c18_c_a;
  int32_T c18_b;
  int32_T c18_d_a;
  int32_T c18_b_b;
  boolean_T c18_p;
  boolean_T c18_b0;
  boolean_T c18_b_p;
  int32_T c18_e_a;
  int32_T c18_f_a;
  int32_T c18_b_c;
  int32_T c18_g_a;
  int32_T c18_h_a;
  int32_T c18_c_c;
  int32_T c18_i43;
  int32_T c18_idx0[16];
  int32_T c18_i;
  int32_T c18_i_a;
  int32_T c18_j_a;
  int32_T c18_i2;
  int32_T c18_j;
  int32_T c18_c_b;
  int32_T c18_d_b;
  int32_T c18_pEnd;
  int32_T c18_c_p;
  int32_T c18_q;
  int32_T c18_k_a;
  int32_T c18_e_b;
  int32_T c18_l_a;
  int32_T c18_f_b;
  int32_T c18_qEnd;
  int32_T c18_m_a;
  int32_T c18_g_b;
  int32_T c18_n_a;
  int32_T c18_h_b;
  int32_T c18_kEnd;
  int32_T c18_b_irow1;
  int32_T c18_b_irow2;
  int32_T c18_o_a;
  int32_T c18_i_b;
  int32_T c18_p_a;
  int32_T c18_j_b;
  boolean_T c18_d_p;
  boolean_T c18_b1;
  boolean_T c18_e_p;
  int32_T c18_q_a;
  int32_T c18_r_a;
  int32_T c18_s_a;
  int32_T c18_t_a;
  int32_T c18_u_a;
  int32_T c18_v_a;
  int32_T c18_w_a;
  int32_T c18_x_a;
  int32_T c18_y_a;
  int32_T c18_ab_a;
  int32_T c18_bb_a;
  int32_T c18_cb_a;
  int32_T c18_db_a;
  int32_T c18_eb_a;
  int32_T c18_fb_a;
  int32_T c18_gb_a;
  int32_T c18_b_kEnd;
  int32_T c18_k_b;
  int32_T c18_l_b;
  boolean_T c18_overflow;
  int32_T c18_d_k;
  int32_T c18_hb_a;
  int32_T c18_m_b;
  int32_T c18_ib_a;
  int32_T c18_n_b;
  int32_T c18_d_c;
  int32_T c18_jb_a;
  int32_T c18_o_b;
  int32_T c18_kb_a;
  int32_T c18_p_b;
  int32_T c18_e_k;
  for (c18_k = 1; c18_k < 17; c18_k++) {
    c18_b_k = c18_k;
    c18_idx[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c18_b_k), 1, 16, 1, 0) - 1] = c18_b_k;
  }

  for (c18_c_k = 1; c18_c_k < 16; c18_c_k += 2) {
    c18_b_k = c18_c_k;
    c18_a = c18_b_k;
    c18_b_a = c18_a;
    c18_c = c18_b_a;
    c18_irow1 = c18_b_k;
    c18_irow2 = c18_c + 1;
    c18_c_a = c18_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c18_irow1), 1, 16, 1, 0) - 1];
    c18_b = c18_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c18_irow2), 1, 16, 1, 0) - 1];
    c18_d_a = c18_c_a;
    c18_b_b = c18_b;
    c18_p = (c18_d_a <= c18_b_b);
    c18_b0 = c18_p;
    c18_b_p = c18_b0;
    if (c18_b_p) {
    } else {
      c18_e_a = c18_b_k;
      c18_f_a = c18_e_a;
      c18_b_c = c18_f_a;
      c18_idx[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c18_b_k), 1, 16, 1, 0) - 1] = c18_b_c + 1;
      c18_g_a = c18_b_k;
      c18_h_a = c18_g_a;
      c18_c_c = c18_h_a;
      c18_idx[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)(c18_c_c + 1)), 1, 16, 1, 0) - 1] = c18_b_k;
    }
  }

  for (c18_i43 = 0; c18_i43 < 16; c18_i43++) {
    c18_idx0[c18_i43] = 1;
  }

  c18_i = 2;
  while (c18_i < 16) {
    c18_i_a = c18_i;
    c18_j_a = c18_i_a;
    c18_i2 = c18_j_a << 1;
    c18_j = 1;
    c18_c_b = c18_i;
    c18_d_b = c18_c_b + 1;
    for (c18_pEnd = c18_d_b; c18_pEnd < 17; c18_pEnd = c18_kb_a + c18_p_b) {
      c18_c_p = c18_j;
      c18_q = c18_pEnd;
      c18_k_a = c18_j;
      c18_e_b = c18_i2;
      c18_l_a = c18_k_a;
      c18_f_b = c18_e_b;
      c18_qEnd = c18_l_a + c18_f_b;
      c18_b_k = 1;
      c18_m_a = c18_qEnd;
      c18_g_b = c18_j;
      c18_n_a = c18_m_a;
      c18_h_b = c18_g_b;
      c18_kEnd = c18_n_a - c18_h_b;
      while (c18_b_k <= c18_kEnd) {
        c18_b_irow1 = c18_idx[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c18_c_p), 1, 16, 1, 0) - 1];
        c18_b_irow2 = c18_idx[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c18_q), 1, 16, 1, 0) - 1];
        c18_o_a = c18_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c18_b_irow1), 1, 16, 1, 0) - 1];
        c18_i_b = c18_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c18_b_irow2), 1, 16, 1, 0) - 1];
        c18_p_a = c18_o_a;
        c18_j_b = c18_i_b;
        c18_d_p = (c18_p_a <= c18_j_b);
        c18_b1 = c18_d_p;
        c18_e_p = c18_b1;
        if (c18_e_p) {
          c18_idx0[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
            "", (real_T)c18_b_k), 1, 16, 1, 0) - 1] =
            c18_idx[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
            "", (real_T)c18_c_p), 1, 16, 1, 0) - 1];
          c18_q_a = c18_c_p;
          c18_r_a = c18_q_a + 1;
          c18_c_p = c18_r_a;
          if (c18_c_p == c18_pEnd) {
            while (c18_q < c18_qEnd) {
              c18_s_a = c18_b_k;
              c18_t_a = c18_s_a + 1;
              c18_b_k = c18_t_a;
              c18_idx0[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c18_b_k), 1, 16, 1, 0) - 1] =
                c18_idx[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c18_q), 1, 16, 1, 0) - 1];
              c18_u_a = c18_q;
              c18_v_a = c18_u_a + 1;
              c18_q = c18_v_a;
            }
          }
        } else {
          c18_idx0[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
            "", (real_T)c18_b_k), 1, 16, 1, 0) - 1] =
            c18_idx[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
            "", (real_T)c18_q), 1, 16, 1, 0) - 1];
          c18_w_a = c18_q;
          c18_x_a = c18_w_a + 1;
          c18_q = c18_x_a;
          if (c18_q == c18_qEnd) {
            while (c18_c_p < c18_pEnd) {
              c18_y_a = c18_b_k;
              c18_ab_a = c18_y_a + 1;
              c18_b_k = c18_ab_a;
              c18_idx0[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c18_b_k), 1, 16, 1, 0) - 1] =
                c18_idx[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c18_c_p), 1, 16, 1, 0) - 1];
              c18_bb_a = c18_c_p;
              c18_cb_a = c18_bb_a + 1;
              c18_c_p = c18_cb_a;
            }
          }
        }

        c18_db_a = c18_b_k;
        c18_eb_a = c18_db_a + 1;
        c18_b_k = c18_eb_a;
      }

      c18_fb_a = c18_j;
      c18_gb_a = c18_fb_a;
      c18_c_p = c18_gb_a;
      c18_b_kEnd = c18_kEnd;
      c18_k_b = c18_b_kEnd;
      c18_l_b = c18_k_b;
      if (1 > c18_l_b) {
        c18_overflow = false;
      } else {
        c18_overflow = (c18_l_b > 2147483646);
      }

      if (c18_overflow) {
        c18_check_forloop_overflow_error(chartInstance, c18_overflow);
      }

      for (c18_d_k = 1; c18_d_k <= c18_b_kEnd; c18_d_k++) {
        c18_b_k = c18_d_k;
        c18_hb_a = c18_c_p - 1;
        c18_m_b = c18_b_k;
        c18_ib_a = c18_hb_a;
        c18_n_b = c18_m_b;
        c18_d_c = c18_ib_a + c18_n_b;
        c18_idx[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c18_d_c), 1, 16, 1, 0) - 1] =
          c18_idx0[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
          "", (real_T)c18_b_k), 1, 16, 1, 0) - 1];
      }

      c18_j = c18_qEnd;
      c18_jb_a = c18_j;
      c18_o_b = c18_i;
      c18_kb_a = c18_jb_a;
      c18_p_b = c18_o_b;
    }

    c18_i = c18_i2;
  }

  for (c18_e_k = 1; c18_e_k < 17; c18_e_k++) {
    c18_b_k = c18_e_k;
    c18_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c18_b_k), 1, 16, 1, 0) - 1] = c18_x[_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c18_idx[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c18_b_k), 1, 16, 1, 0) - 1]), 1, 16, 1, 0) - 1];
  }
}

static void c18_check_forloop_overflow_error(SFc18_RaspPiPilotInstanceStruct
  *chartInstance, boolean_T c18_overflow)
{
  int32_T c18_i44;
  static char_T c18_cv0[34] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'i', 'n', 't', '_', 'f', 'o', 'r', 'l', 'o', 'o', 'p',
    '_', 'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w' };

  char_T c18_u[34];
  const mxArray *c18_y = NULL;
  int32_T c18_i45;
  static char_T c18_cv1[23] = { 'c', 'o', 'd', 'e', 'r', '.', 'i', 'n', 't', 'e',
    'r', 'n', 'a', 'l', '.', 'i', 'n', 'd', 'e', 'x', 'I', 'n', 't' };

  char_T c18_b_u[23];
  const mxArray *c18_b_y = NULL;
  (void)chartInstance;
  if (!c18_overflow) {
  } else {
    for (c18_i44 = 0; c18_i44 < 34; c18_i44++) {
      c18_u[c18_i44] = c18_cv0[c18_i44];
    }

    c18_y = NULL;
    sf_mex_assign(&c18_y, sf_mex_create("y", c18_u, 10, 0U, 1U, 0U, 2, 1, 34),
                  false);
    for (c18_i45 = 0; c18_i45 < 23; c18_i45++) {
      c18_b_u[c18_i45] = c18_cv1[c18_i45];
    }

    c18_b_y = NULL;
    sf_mex_assign(&c18_b_y, sf_mex_create("y", c18_b_u, 10, 0U, 1U, 0U, 2, 1, 23),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 2U, 14, c18_y, 14, c18_b_y));
  }
}

static const mxArray *c18_g_sf_marshallOut(void *chartInstanceVoid, void
  *c18_inData)
{
  const mxArray *c18_mxArrayOutData = NULL;
  int32_T c18_u;
  const mxArray *c18_y = NULL;
  SFc18_RaspPiPilotInstanceStruct *chartInstance;
  chartInstance = (SFc18_RaspPiPilotInstanceStruct *)chartInstanceVoid;
  c18_mxArrayOutData = NULL;
  c18_u = *(int32_T *)c18_inData;
  c18_y = NULL;
  sf_mex_assign(&c18_y, sf_mex_create("y", &c18_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c18_mxArrayOutData, c18_y, false);
  return c18_mxArrayOutData;
}

static int32_T c18_f_emlrt_marshallIn(SFc18_RaspPiPilotInstanceStruct
  *chartInstance, const mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId)
{
  int32_T c18_y;
  int32_T c18_i46;
  (void)chartInstance;
  sf_mex_import(c18_parentId, sf_mex_dup(c18_u), &c18_i46, 1, 6, 0U, 0, 0U, 0);
  c18_y = c18_i46;
  sf_mex_destroy(&c18_u);
  return c18_y;
}

static void c18_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c18_mxArrayInData, const char_T *c18_varName, void *c18_outData)
{
  const mxArray *c18_b_sfEvent;
  const char_T *c18_identifier;
  emlrtMsgIdentifier c18_thisId;
  int32_T c18_y;
  SFc18_RaspPiPilotInstanceStruct *chartInstance;
  chartInstance = (SFc18_RaspPiPilotInstanceStruct *)chartInstanceVoid;
  c18_b_sfEvent = sf_mex_dup(c18_mxArrayInData);
  c18_identifier = c18_varName;
  c18_thisId.fIdentifier = c18_identifier;
  c18_thisId.fParent = NULL;
  c18_y = c18_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c18_b_sfEvent),
    &c18_thisId);
  sf_mex_destroy(&c18_b_sfEvent);
  *(int32_T *)c18_outData = c18_y;
  sf_mex_destroy(&c18_mxArrayInData);
}

static uint8_T c18_g_emlrt_marshallIn(SFc18_RaspPiPilotInstanceStruct
  *chartInstance, const mxArray *c18_b_is_active_c18_RaspPiPilot, const char_T
  *c18_identifier)
{
  uint8_T c18_y;
  emlrtMsgIdentifier c18_thisId;
  c18_thisId.fIdentifier = c18_identifier;
  c18_thisId.fParent = NULL;
  c18_y = c18_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c18_b_is_active_c18_RaspPiPilot), &c18_thisId);
  sf_mex_destroy(&c18_b_is_active_c18_RaspPiPilot);
  return c18_y;
}

static uint8_T c18_h_emlrt_marshallIn(SFc18_RaspPiPilotInstanceStruct
  *chartInstance, const mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId)
{
  uint8_T c18_y;
  uint8_T c18_u0;
  (void)chartInstance;
  sf_mex_import(c18_parentId, sf_mex_dup(c18_u), &c18_u0, 1, 3, 0U, 0, 0U, 0);
  c18_y = c18_u0;
  sf_mex_destroy(&c18_u);
  return c18_y;
}

static void init_dsm_address_info(SFc18_RaspPiPilotInstanceStruct *chartInstance)
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

void sf_c18_RaspPiPilot_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2490953285U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(838592964U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3030840602U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(183700202U);
}

mxArray *sf_c18_RaspPiPilot_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("elHoBF8J6S5CZhAqYX5GaG");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(16);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(8));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(16);
      pr[1] = (double)(2);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
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
      pr[1] = (double)(2);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
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

mxArray *sf_c18_RaspPiPilot_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c18_RaspPiPilot_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c18_RaspPiPilot(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[8],T\"centroid_largest\",},{M[8],M[0],T\"is_active_c18_RaspPiPilot\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c18_RaspPiPilot_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc18_RaspPiPilotInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc18_RaspPiPilotInstanceStruct *) chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _RaspPiPilotMachineNumber_,
           18,
           1,
           1,
           0,
           3,
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
          _SFD_SET_DATA_PROPS(0,2,0,1,"centroid_largest");
          _SFD_SET_DATA_PROPS(1,1,1,0,"area");
          _SFD_SET_DATA_PROPS(2,1,1,0,"centroid");
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
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,184);

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c18_sf_marshallOut,(MexInFcnForType)
            c18_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 16;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_INT32,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c18_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 16;
          dimVector[1]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c18_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          real_T (*c18_centroid_largest)[6];
          int32_T (*c18_area)[16];
          real_T (*c18_centroid)[32];
          c18_centroid = (real_T (*)[32])ssGetInputPortSignal(chartInstance->S,
            1);
          c18_area = (int32_T (*)[16])ssGetInputPortSignal(chartInstance->S, 0);
          c18_centroid_largest = (real_T (*)[6])ssGetOutputPortSignal
            (chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, *c18_centroid_largest);
          _SFD_SET_DATA_VALUE_PTR(1U, *c18_area);
          _SFD_SET_DATA_VALUE_PTR(2U, *c18_centroid);
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
  return "g1SbvliozcMmRHk2jP70qE";
}

static void sf_opaque_initialize_c18_RaspPiPilot(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc18_RaspPiPilotInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c18_RaspPiPilot((SFc18_RaspPiPilotInstanceStruct*)
    chartInstanceVar);
  initialize_c18_RaspPiPilot((SFc18_RaspPiPilotInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c18_RaspPiPilot(void *chartInstanceVar)
{
  enable_c18_RaspPiPilot((SFc18_RaspPiPilotInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c18_RaspPiPilot(void *chartInstanceVar)
{
  disable_c18_RaspPiPilot((SFc18_RaspPiPilotInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c18_RaspPiPilot(void *chartInstanceVar)
{
  sf_gateway_c18_RaspPiPilot((SFc18_RaspPiPilotInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c18_RaspPiPilot(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c18_RaspPiPilot
    ((SFc18_RaspPiPilotInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c18_RaspPiPilot();/* state var info */
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

extern void sf_internal_set_sim_state_c18_RaspPiPilot(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c18_RaspPiPilot();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c18_RaspPiPilot((SFc18_RaspPiPilotInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c18_RaspPiPilot(SimStruct* S)
{
  return sf_internal_get_sim_state_c18_RaspPiPilot(S);
}

static void sf_opaque_set_sim_state_c18_RaspPiPilot(SimStruct* S, const mxArray *
  st)
{
  sf_internal_set_sim_state_c18_RaspPiPilot(S, st);
}

static void sf_opaque_terminate_c18_RaspPiPilot(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc18_RaspPiPilotInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_RaspPiPilot_optimization_info();
    }

    finalize_c18_RaspPiPilot((SFc18_RaspPiPilotInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    if (crtInfo != NULL) {
      utFree((void *)crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc18_RaspPiPilot((SFc18_RaspPiPilotInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c18_RaspPiPilot(SimStruct *S)
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
    initialize_params_c18_RaspPiPilot((SFc18_RaspPiPilotInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c18_RaspPiPilot(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_RaspPiPilot_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      18);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,18,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,18,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,18);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,18,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,18,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,18);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1383969967U));
  ssSetChecksum1(S,(3811567653U));
  ssSetChecksum2(S,(505256101U));
  ssSetChecksum3(S,(1878376547U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c18_RaspPiPilot(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c18_RaspPiPilot(SimStruct *S)
{
  SFc18_RaspPiPilotInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc18_RaspPiPilotInstanceStruct *)utMalloc(sizeof
    (SFc18_RaspPiPilotInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc18_RaspPiPilotInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c18_RaspPiPilot;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c18_RaspPiPilot;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c18_RaspPiPilot;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c18_RaspPiPilot;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c18_RaspPiPilot;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c18_RaspPiPilot;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c18_RaspPiPilot;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c18_RaspPiPilot;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c18_RaspPiPilot;
  chartInstance->chartInfo.mdlStart = mdlStart_c18_RaspPiPilot;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c18_RaspPiPilot;
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

void c18_RaspPiPilot_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c18_RaspPiPilot(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c18_RaspPiPilot(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c18_RaspPiPilot(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c18_RaspPiPilot_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
