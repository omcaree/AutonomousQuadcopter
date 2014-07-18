/* Include files */

#include <stddef.h>
#include "blas.h"
#include "RaspPiPilot_sfun.h"
#include "c17_RaspPiPilot.h"
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
static const char * c17_debug_family_names[8] = { "l", "y", "i", "nargin",
  "nargout", "area", "centroid", "centroid_largest" };

/* Function Declarations */
static void initialize_c17_RaspPiPilot(SFc17_RaspPiPilotInstanceStruct
  *chartInstance);
static void initialize_params_c17_RaspPiPilot(SFc17_RaspPiPilotInstanceStruct
  *chartInstance);
static void enable_c17_RaspPiPilot(SFc17_RaspPiPilotInstanceStruct
  *chartInstance);
static void disable_c17_RaspPiPilot(SFc17_RaspPiPilotInstanceStruct
  *chartInstance);
static void c17_update_debugger_state_c17_RaspPiPilot
  (SFc17_RaspPiPilotInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c17_RaspPiPilot
  (SFc17_RaspPiPilotInstanceStruct *chartInstance);
static void set_sim_state_c17_RaspPiPilot(SFc17_RaspPiPilotInstanceStruct
  *chartInstance, const mxArray *c17_st);
static void finalize_c17_RaspPiPilot(SFc17_RaspPiPilotInstanceStruct
  *chartInstance);
static void sf_gateway_c17_RaspPiPilot(SFc17_RaspPiPilotInstanceStruct
  *chartInstance);
static void initSimStructsc17_RaspPiPilot(SFc17_RaspPiPilotInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c17_machineNumber, uint32_T
  c17_chartNumber, uint32_T c17_instanceNumber);
static const mxArray *c17_sf_marshallOut(void *chartInstanceVoid, void
  *c17_inData);
static void c17_emlrt_marshallIn(SFc17_RaspPiPilotInstanceStruct *chartInstance,
  const mxArray *c17_centroid_largest, const char_T *c17_identifier, real_T
  c17_y[6]);
static void c17_b_emlrt_marshallIn(SFc17_RaspPiPilotInstanceStruct
  *chartInstance, const mxArray *c17_u, const emlrtMsgIdentifier *c17_parentId,
  real_T c17_y[6]);
static void c17_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c17_mxArrayInData, const char_T *c17_varName, void *c17_outData);
static const mxArray *c17_b_sf_marshallOut(void *chartInstanceVoid, void
  *c17_inData);
static const mxArray *c17_c_sf_marshallOut(void *chartInstanceVoid, void
  *c17_inData);
static const mxArray *c17_d_sf_marshallOut(void *chartInstanceVoid, void
  *c17_inData);
static real_T c17_c_emlrt_marshallIn(SFc17_RaspPiPilotInstanceStruct
  *chartInstance, const mxArray *c17_u, const emlrtMsgIdentifier *c17_parentId);
static void c17_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c17_mxArrayInData, const char_T *c17_varName, void *c17_outData);
static const mxArray *c17_e_sf_marshallOut(void *chartInstanceVoid, void
  *c17_inData);
static void c17_d_emlrt_marshallIn(SFc17_RaspPiPilotInstanceStruct
  *chartInstance, const mxArray *c17_u, const emlrtMsgIdentifier *c17_parentId,
  real_T c17_y[16]);
static void c17_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c17_mxArrayInData, const char_T *c17_varName, void *c17_outData);
static const mxArray *c17_f_sf_marshallOut(void *chartInstanceVoid, void
  *c17_inData);
static void c17_e_emlrt_marshallIn(SFc17_RaspPiPilotInstanceStruct
  *chartInstance, const mxArray *c17_u, const emlrtMsgIdentifier *c17_parentId,
  int32_T c17_y[16]);
static void c17_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c17_mxArrayInData, const char_T *c17_varName, void *c17_outData);
static void c17_info_helper(const mxArray **c17_info);
static const mxArray *c17_emlrt_marshallOut(const char * c17_u);
static const mxArray *c17_b_emlrt_marshallOut(const uint32_T c17_u);
static void c17_eml_sort(SFc17_RaspPiPilotInstanceStruct *chartInstance, int32_T
  c17_x[16], int32_T c17_y[16], int32_T c17_idx[16]);
static void c17_eml_sort_idx(SFc17_RaspPiPilotInstanceStruct *chartInstance,
  int32_T c17_x[16], int32_T c17_idx[16], int32_T c17_y[16]);
static void c17_check_forloop_overflow_error(SFc17_RaspPiPilotInstanceStruct
  *chartInstance, boolean_T c17_overflow);
static const mxArray *c17_g_sf_marshallOut(void *chartInstanceVoid, void
  *c17_inData);
static int32_T c17_f_emlrt_marshallIn(SFc17_RaspPiPilotInstanceStruct
  *chartInstance, const mxArray *c17_u, const emlrtMsgIdentifier *c17_parentId);
static void c17_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c17_mxArrayInData, const char_T *c17_varName, void *c17_outData);
static uint8_T c17_g_emlrt_marshallIn(SFc17_RaspPiPilotInstanceStruct
  *chartInstance, const mxArray *c17_b_is_active_c17_RaspPiPilot, const char_T
  *c17_identifier);
static uint8_T c17_h_emlrt_marshallIn(SFc17_RaspPiPilotInstanceStruct
  *chartInstance, const mxArray *c17_u, const emlrtMsgIdentifier *c17_parentId);
static void init_dsm_address_info(SFc17_RaspPiPilotInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c17_RaspPiPilot(SFc17_RaspPiPilotInstanceStruct
  *chartInstance)
{
  chartInstance->c17_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c17_is_active_c17_RaspPiPilot = 0U;
}

static void initialize_params_c17_RaspPiPilot(SFc17_RaspPiPilotInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void enable_c17_RaspPiPilot(SFc17_RaspPiPilotInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c17_RaspPiPilot(SFc17_RaspPiPilotInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c17_update_debugger_state_c17_RaspPiPilot
  (SFc17_RaspPiPilotInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c17_RaspPiPilot
  (SFc17_RaspPiPilotInstanceStruct *chartInstance)
{
  const mxArray *c17_st;
  const mxArray *c17_y = NULL;
  int32_T c17_i0;
  real_T c17_u[6];
  const mxArray *c17_b_y = NULL;
  uint8_T c17_hoistedGlobal;
  uint8_T c17_b_u;
  const mxArray *c17_c_y = NULL;
  real_T (*c17_centroid_largest)[6];
  c17_centroid_largest = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S,
    1);
  c17_st = NULL;
  c17_st = NULL;
  c17_y = NULL;
  sf_mex_assign(&c17_y, sf_mex_createcellmatrix(2, 1), false);
  for (c17_i0 = 0; c17_i0 < 6; c17_i0++) {
    c17_u[c17_i0] = (*c17_centroid_largest)[c17_i0];
  }

  c17_b_y = NULL;
  sf_mex_assign(&c17_b_y, sf_mex_create("y", c17_u, 0, 0U, 1U, 0U, 2, 3, 2),
                false);
  sf_mex_setcell(c17_y, 0, c17_b_y);
  c17_hoistedGlobal = chartInstance->c17_is_active_c17_RaspPiPilot;
  c17_b_u = c17_hoistedGlobal;
  c17_c_y = NULL;
  sf_mex_assign(&c17_c_y, sf_mex_create("y", &c17_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c17_y, 1, c17_c_y);
  sf_mex_assign(&c17_st, c17_y, false);
  return c17_st;
}

static void set_sim_state_c17_RaspPiPilot(SFc17_RaspPiPilotInstanceStruct
  *chartInstance, const mxArray *c17_st)
{
  const mxArray *c17_u;
  real_T c17_dv0[6];
  int32_T c17_i1;
  real_T (*c17_centroid_largest)[6];
  c17_centroid_largest = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S,
    1);
  chartInstance->c17_doneDoubleBufferReInit = true;
  c17_u = sf_mex_dup(c17_st);
  c17_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c17_u, 0)),
                       "centroid_largest", c17_dv0);
  for (c17_i1 = 0; c17_i1 < 6; c17_i1++) {
    (*c17_centroid_largest)[c17_i1] = c17_dv0[c17_i1];
  }

  chartInstance->c17_is_active_c17_RaspPiPilot = c17_g_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c17_u, 1)),
     "is_active_c17_RaspPiPilot");
  sf_mex_destroy(&c17_u);
  c17_update_debugger_state_c17_RaspPiPilot(chartInstance);
  sf_mex_destroy(&c17_st);
}

static void finalize_c17_RaspPiPilot(SFc17_RaspPiPilotInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c17_RaspPiPilot(SFc17_RaspPiPilotInstanceStruct
  *chartInstance)
{
  int32_T c17_i2;
  int32_T c17_area[16];
  int32_T c17_i3;
  real_T c17_centroid[32];
  uint32_T c17_debug_family_var_map[8];
  real_T c17_l;
  int32_T c17_y[16];
  real_T c17_i[16];
  real_T c17_nargin = 2.0;
  real_T c17_nargout = 1.0;
  real_T c17_centroid_largest[6];
  int32_T c17_i4;
  int32_T c17_x[16];
  int32_T c17_i5;
  int32_T c17_b_x[16];
  int32_T c17_iidx[16];
  int32_T c17_i6;
  real_T c17_b_i[16];
  int32_T c17_i7;
  int32_T c17_i8;
  int32_T c17_c_i;
  int32_T c17_d_i;
  int32_T c17_e_i;
  int32_T c17_i9;
  int32_T c17_i10;
  int32_T c17_i11;
  int32_T c17_i12;
  int32_T c17_i13;
  int32_T c17_i14;
  int32_T c17_i15;
  real_T (*c17_b_centroid_largest)[6];
  real_T (*c17_b_centroid)[32];
  int32_T (*c17_b_area)[16];
  c17_b_centroid = (real_T (*)[32])ssGetInputPortSignal(chartInstance->S, 1);
  c17_b_area = (int32_T (*)[16])ssGetInputPortSignal(chartInstance->S, 0);
  c17_b_centroid_largest = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S,
    1);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 16U, chartInstance->c17_sfEvent);
  chartInstance->c17_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 16U, chartInstance->c17_sfEvent);
  for (c17_i2 = 0; c17_i2 < 16; c17_i2++) {
    c17_area[c17_i2] = (*c17_b_area)[c17_i2];
  }

  for (c17_i3 = 0; c17_i3 < 32; c17_i3++) {
    c17_centroid[c17_i3] = (*c17_b_centroid)[c17_i3];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 8U, 8U, c17_debug_family_names,
    c17_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c17_l, 0U, c17_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c17_y, 1U, c17_f_sf_marshallOut,
    c17_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c17_i, 2U, c17_e_sf_marshallOut,
    c17_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c17_nargin, 3U, c17_d_sf_marshallOut,
    c17_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c17_nargout, 4U, c17_d_sf_marshallOut,
    c17_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c17_area, 5U, c17_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c17_centroid, 6U, c17_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c17_centroid_largest, 7U,
    c17_sf_marshallOut, c17_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 3);
  c17_l = 16.0;
  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 4);
  for (c17_i4 = 0; c17_i4 < 16; c17_i4++) {
    c17_x[c17_i4] = c17_area[c17_i4];
  }

  for (c17_i5 = 0; c17_i5 < 16; c17_i5++) {
    c17_b_x[c17_i5] = c17_x[c17_i5];
  }

  c17_eml_sort(chartInstance, c17_b_x, c17_x, c17_iidx);
  for (c17_i6 = 0; c17_i6 < 16; c17_i6++) {
    c17_b_i[c17_i6] = (real_T)c17_iidx[c17_i6];
  }

  for (c17_i7 = 0; c17_i7 < 16; c17_i7++) {
    c17_y[c17_i7] = c17_x[c17_i7];
  }

  for (c17_i8 = 0; c17_i8 < 16; c17_i8++) {
    c17_i[c17_i8] = c17_b_i[c17_i8];
  }

  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, 5);
  c17_c_i = _SFD_EML_ARRAY_BOUNDS_CHECK("centroid", (int32_T)_SFD_INTEGER_CHECK(
    "i(l)", c17_i[15]), 1, 16, 1, 0) - 1;
  c17_d_i = _SFD_EML_ARRAY_BOUNDS_CHECK("centroid", (int32_T)_SFD_INTEGER_CHECK(
    "i(l-1)", c17_i[14]), 1, 16, 1, 0) - 1;
  c17_e_i = _SFD_EML_ARRAY_BOUNDS_CHECK("centroid", (int32_T)_SFD_INTEGER_CHECK(
    "i(l-2)", c17_i[13]), 1, 16, 1, 0) - 1;
  for (c17_i9 = 0; c17_i9 < 2; c17_i9++) {
    c17_centroid_largest[3 * c17_i9] = c17_centroid[c17_c_i + (c17_i9 << 4)];
  }

  for (c17_i10 = 0; c17_i10 < 2; c17_i10++) {
    c17_centroid_largest[1 + 3 * c17_i10] = c17_centroid[c17_d_i + (c17_i10 << 4)];
  }

  for (c17_i11 = 0; c17_i11 < 2; c17_i11++) {
    c17_centroid_largest[2 + 3 * c17_i11] = c17_centroid[c17_e_i + (c17_i11 << 4)];
  }

  _SFD_EML_CALL(0U, chartInstance->c17_sfEvent, -5);
  _SFD_SYMBOL_SCOPE_POP();
  for (c17_i12 = 0; c17_i12 < 6; c17_i12++) {
    (*c17_b_centroid_largest)[c17_i12] = c17_centroid_largest[c17_i12];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 16U, chartInstance->c17_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_RaspPiPilotMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c17_i13 = 0; c17_i13 < 6; c17_i13++) {
    _SFD_DATA_RANGE_CHECK((*c17_b_centroid_largest)[c17_i13], 0U);
  }

  for (c17_i14 = 0; c17_i14 < 16; c17_i14++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*c17_b_area)[c17_i14], 1U);
  }

  for (c17_i15 = 0; c17_i15 < 32; c17_i15++) {
    _SFD_DATA_RANGE_CHECK((*c17_b_centroid)[c17_i15], 2U);
  }
}

static void initSimStructsc17_RaspPiPilot(SFc17_RaspPiPilotInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c17_machineNumber, uint32_T
  c17_chartNumber, uint32_T c17_instanceNumber)
{
  (void)c17_machineNumber;
  (void)c17_chartNumber;
  (void)c17_instanceNumber;
}

static const mxArray *c17_sf_marshallOut(void *chartInstanceVoid, void
  *c17_inData)
{
  const mxArray *c17_mxArrayOutData = NULL;
  int32_T c17_i16;
  int32_T c17_i17;
  int32_T c17_i18;
  real_T c17_b_inData[6];
  int32_T c17_i19;
  int32_T c17_i20;
  int32_T c17_i21;
  real_T c17_u[6];
  const mxArray *c17_y = NULL;
  SFc17_RaspPiPilotInstanceStruct *chartInstance;
  chartInstance = (SFc17_RaspPiPilotInstanceStruct *)chartInstanceVoid;
  c17_mxArrayOutData = NULL;
  c17_i16 = 0;
  for (c17_i17 = 0; c17_i17 < 2; c17_i17++) {
    for (c17_i18 = 0; c17_i18 < 3; c17_i18++) {
      c17_b_inData[c17_i18 + c17_i16] = (*(real_T (*)[6])c17_inData)[c17_i18 +
        c17_i16];
    }

    c17_i16 += 3;
  }

  c17_i19 = 0;
  for (c17_i20 = 0; c17_i20 < 2; c17_i20++) {
    for (c17_i21 = 0; c17_i21 < 3; c17_i21++) {
      c17_u[c17_i21 + c17_i19] = c17_b_inData[c17_i21 + c17_i19];
    }

    c17_i19 += 3;
  }

  c17_y = NULL;
  sf_mex_assign(&c17_y, sf_mex_create("y", c17_u, 0, 0U, 1U, 0U, 2, 3, 2), false);
  sf_mex_assign(&c17_mxArrayOutData, c17_y, false);
  return c17_mxArrayOutData;
}

static void c17_emlrt_marshallIn(SFc17_RaspPiPilotInstanceStruct *chartInstance,
  const mxArray *c17_centroid_largest, const char_T *c17_identifier, real_T
  c17_y[6])
{
  emlrtMsgIdentifier c17_thisId;
  c17_thisId.fIdentifier = c17_identifier;
  c17_thisId.fParent = NULL;
  c17_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c17_centroid_largest),
    &c17_thisId, c17_y);
  sf_mex_destroy(&c17_centroid_largest);
}

static void c17_b_emlrt_marshallIn(SFc17_RaspPiPilotInstanceStruct
  *chartInstance, const mxArray *c17_u, const emlrtMsgIdentifier *c17_parentId,
  real_T c17_y[6])
{
  real_T c17_dv1[6];
  int32_T c17_i22;
  (void)chartInstance;
  sf_mex_import(c17_parentId, sf_mex_dup(c17_u), c17_dv1, 1, 0, 0U, 1, 0U, 2, 3,
                2);
  for (c17_i22 = 0; c17_i22 < 6; c17_i22++) {
    c17_y[c17_i22] = c17_dv1[c17_i22];
  }

  sf_mex_destroy(&c17_u);
}

static void c17_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c17_mxArrayInData, const char_T *c17_varName, void *c17_outData)
{
  const mxArray *c17_centroid_largest;
  const char_T *c17_identifier;
  emlrtMsgIdentifier c17_thisId;
  real_T c17_y[6];
  int32_T c17_i23;
  int32_T c17_i24;
  int32_T c17_i25;
  SFc17_RaspPiPilotInstanceStruct *chartInstance;
  chartInstance = (SFc17_RaspPiPilotInstanceStruct *)chartInstanceVoid;
  c17_centroid_largest = sf_mex_dup(c17_mxArrayInData);
  c17_identifier = c17_varName;
  c17_thisId.fIdentifier = c17_identifier;
  c17_thisId.fParent = NULL;
  c17_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c17_centroid_largest),
    &c17_thisId, c17_y);
  sf_mex_destroy(&c17_centroid_largest);
  c17_i23 = 0;
  for (c17_i24 = 0; c17_i24 < 2; c17_i24++) {
    for (c17_i25 = 0; c17_i25 < 3; c17_i25++) {
      (*(real_T (*)[6])c17_outData)[c17_i25 + c17_i23] = c17_y[c17_i25 + c17_i23];
    }

    c17_i23 += 3;
  }

  sf_mex_destroy(&c17_mxArrayInData);
}

static const mxArray *c17_b_sf_marshallOut(void *chartInstanceVoid, void
  *c17_inData)
{
  const mxArray *c17_mxArrayOutData = NULL;
  int32_T c17_i26;
  int32_T c17_i27;
  int32_T c17_i28;
  real_T c17_b_inData[32];
  int32_T c17_i29;
  int32_T c17_i30;
  int32_T c17_i31;
  real_T c17_u[32];
  const mxArray *c17_y = NULL;
  SFc17_RaspPiPilotInstanceStruct *chartInstance;
  chartInstance = (SFc17_RaspPiPilotInstanceStruct *)chartInstanceVoid;
  c17_mxArrayOutData = NULL;
  c17_i26 = 0;
  for (c17_i27 = 0; c17_i27 < 2; c17_i27++) {
    for (c17_i28 = 0; c17_i28 < 16; c17_i28++) {
      c17_b_inData[c17_i28 + c17_i26] = (*(real_T (*)[32])c17_inData)[c17_i28 +
        c17_i26];
    }

    c17_i26 += 16;
  }

  c17_i29 = 0;
  for (c17_i30 = 0; c17_i30 < 2; c17_i30++) {
    for (c17_i31 = 0; c17_i31 < 16; c17_i31++) {
      c17_u[c17_i31 + c17_i29] = c17_b_inData[c17_i31 + c17_i29];
    }

    c17_i29 += 16;
  }

  c17_y = NULL;
  sf_mex_assign(&c17_y, sf_mex_create("y", c17_u, 0, 0U, 1U, 0U, 2, 16, 2),
                false);
  sf_mex_assign(&c17_mxArrayOutData, c17_y, false);
  return c17_mxArrayOutData;
}

static const mxArray *c17_c_sf_marshallOut(void *chartInstanceVoid, void
  *c17_inData)
{
  const mxArray *c17_mxArrayOutData = NULL;
  int32_T c17_i32;
  int32_T c17_b_inData[16];
  int32_T c17_i33;
  int32_T c17_u[16];
  const mxArray *c17_y = NULL;
  SFc17_RaspPiPilotInstanceStruct *chartInstance;
  chartInstance = (SFc17_RaspPiPilotInstanceStruct *)chartInstanceVoid;
  c17_mxArrayOutData = NULL;
  for (c17_i32 = 0; c17_i32 < 16; c17_i32++) {
    c17_b_inData[c17_i32] = (*(int32_T (*)[16])c17_inData)[c17_i32];
  }

  for (c17_i33 = 0; c17_i33 < 16; c17_i33++) {
    c17_u[c17_i33] = c17_b_inData[c17_i33];
  }

  c17_y = NULL;
  sf_mex_assign(&c17_y, sf_mex_create("y", c17_u, 6, 0U, 1U, 0U, 2, 16, 1),
                false);
  sf_mex_assign(&c17_mxArrayOutData, c17_y, false);
  return c17_mxArrayOutData;
}

static const mxArray *c17_d_sf_marshallOut(void *chartInstanceVoid, void
  *c17_inData)
{
  const mxArray *c17_mxArrayOutData = NULL;
  real_T c17_u;
  const mxArray *c17_y = NULL;
  SFc17_RaspPiPilotInstanceStruct *chartInstance;
  chartInstance = (SFc17_RaspPiPilotInstanceStruct *)chartInstanceVoid;
  c17_mxArrayOutData = NULL;
  c17_u = *(real_T *)c17_inData;
  c17_y = NULL;
  sf_mex_assign(&c17_y, sf_mex_create("y", &c17_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c17_mxArrayOutData, c17_y, false);
  return c17_mxArrayOutData;
}

static real_T c17_c_emlrt_marshallIn(SFc17_RaspPiPilotInstanceStruct
  *chartInstance, const mxArray *c17_u, const emlrtMsgIdentifier *c17_parentId)
{
  real_T c17_y;
  real_T c17_d0;
  (void)chartInstance;
  sf_mex_import(c17_parentId, sf_mex_dup(c17_u), &c17_d0, 1, 0, 0U, 0, 0U, 0);
  c17_y = c17_d0;
  sf_mex_destroy(&c17_u);
  return c17_y;
}

static void c17_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c17_mxArrayInData, const char_T *c17_varName, void *c17_outData)
{
  const mxArray *c17_nargout;
  const char_T *c17_identifier;
  emlrtMsgIdentifier c17_thisId;
  real_T c17_y;
  SFc17_RaspPiPilotInstanceStruct *chartInstance;
  chartInstance = (SFc17_RaspPiPilotInstanceStruct *)chartInstanceVoid;
  c17_nargout = sf_mex_dup(c17_mxArrayInData);
  c17_identifier = c17_varName;
  c17_thisId.fIdentifier = c17_identifier;
  c17_thisId.fParent = NULL;
  c17_y = c17_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c17_nargout),
    &c17_thisId);
  sf_mex_destroy(&c17_nargout);
  *(real_T *)c17_outData = c17_y;
  sf_mex_destroy(&c17_mxArrayInData);
}

static const mxArray *c17_e_sf_marshallOut(void *chartInstanceVoid, void
  *c17_inData)
{
  const mxArray *c17_mxArrayOutData = NULL;
  int32_T c17_i34;
  real_T c17_b_inData[16];
  int32_T c17_i35;
  real_T c17_u[16];
  const mxArray *c17_y = NULL;
  SFc17_RaspPiPilotInstanceStruct *chartInstance;
  chartInstance = (SFc17_RaspPiPilotInstanceStruct *)chartInstanceVoid;
  c17_mxArrayOutData = NULL;
  for (c17_i34 = 0; c17_i34 < 16; c17_i34++) {
    c17_b_inData[c17_i34] = (*(real_T (*)[16])c17_inData)[c17_i34];
  }

  for (c17_i35 = 0; c17_i35 < 16; c17_i35++) {
    c17_u[c17_i35] = c17_b_inData[c17_i35];
  }

  c17_y = NULL;
  sf_mex_assign(&c17_y, sf_mex_create("y", c17_u, 0, 0U, 1U, 0U, 1, 16), false);
  sf_mex_assign(&c17_mxArrayOutData, c17_y, false);
  return c17_mxArrayOutData;
}

static void c17_d_emlrt_marshallIn(SFc17_RaspPiPilotInstanceStruct
  *chartInstance, const mxArray *c17_u, const emlrtMsgIdentifier *c17_parentId,
  real_T c17_y[16])
{
  real_T c17_dv2[16];
  int32_T c17_i36;
  (void)chartInstance;
  sf_mex_import(c17_parentId, sf_mex_dup(c17_u), c17_dv2, 1, 0, 0U, 1, 0U, 1, 16);
  for (c17_i36 = 0; c17_i36 < 16; c17_i36++) {
    c17_y[c17_i36] = c17_dv2[c17_i36];
  }

  sf_mex_destroy(&c17_u);
}

static void c17_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c17_mxArrayInData, const char_T *c17_varName, void *c17_outData)
{
  const mxArray *c17_i;
  const char_T *c17_identifier;
  emlrtMsgIdentifier c17_thisId;
  real_T c17_y[16];
  int32_T c17_i37;
  SFc17_RaspPiPilotInstanceStruct *chartInstance;
  chartInstance = (SFc17_RaspPiPilotInstanceStruct *)chartInstanceVoid;
  c17_i = sf_mex_dup(c17_mxArrayInData);
  c17_identifier = c17_varName;
  c17_thisId.fIdentifier = c17_identifier;
  c17_thisId.fParent = NULL;
  c17_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c17_i), &c17_thisId, c17_y);
  sf_mex_destroy(&c17_i);
  for (c17_i37 = 0; c17_i37 < 16; c17_i37++) {
    (*(real_T (*)[16])c17_outData)[c17_i37] = c17_y[c17_i37];
  }

  sf_mex_destroy(&c17_mxArrayInData);
}

static const mxArray *c17_f_sf_marshallOut(void *chartInstanceVoid, void
  *c17_inData)
{
  const mxArray *c17_mxArrayOutData = NULL;
  int32_T c17_i38;
  int32_T c17_b_inData[16];
  int32_T c17_i39;
  int32_T c17_u[16];
  const mxArray *c17_y = NULL;
  SFc17_RaspPiPilotInstanceStruct *chartInstance;
  chartInstance = (SFc17_RaspPiPilotInstanceStruct *)chartInstanceVoid;
  c17_mxArrayOutData = NULL;
  for (c17_i38 = 0; c17_i38 < 16; c17_i38++) {
    c17_b_inData[c17_i38] = (*(int32_T (*)[16])c17_inData)[c17_i38];
  }

  for (c17_i39 = 0; c17_i39 < 16; c17_i39++) {
    c17_u[c17_i39] = c17_b_inData[c17_i39];
  }

  c17_y = NULL;
  sf_mex_assign(&c17_y, sf_mex_create("y", c17_u, 6, 0U, 1U, 0U, 1, 16), false);
  sf_mex_assign(&c17_mxArrayOutData, c17_y, false);
  return c17_mxArrayOutData;
}

static void c17_e_emlrt_marshallIn(SFc17_RaspPiPilotInstanceStruct
  *chartInstance, const mxArray *c17_u, const emlrtMsgIdentifier *c17_parentId,
  int32_T c17_y[16])
{
  int32_T c17_iv0[16];
  int32_T c17_i40;
  (void)chartInstance;
  sf_mex_import(c17_parentId, sf_mex_dup(c17_u), c17_iv0, 1, 6, 0U, 1, 0U, 1, 16);
  for (c17_i40 = 0; c17_i40 < 16; c17_i40++) {
    c17_y[c17_i40] = c17_iv0[c17_i40];
  }

  sf_mex_destroy(&c17_u);
}

static void c17_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c17_mxArrayInData, const char_T *c17_varName, void *c17_outData)
{
  const mxArray *c17_y;
  const char_T *c17_identifier;
  emlrtMsgIdentifier c17_thisId;
  int32_T c17_b_y[16];
  int32_T c17_i41;
  SFc17_RaspPiPilotInstanceStruct *chartInstance;
  chartInstance = (SFc17_RaspPiPilotInstanceStruct *)chartInstanceVoid;
  c17_y = sf_mex_dup(c17_mxArrayInData);
  c17_identifier = c17_varName;
  c17_thisId.fIdentifier = c17_identifier;
  c17_thisId.fParent = NULL;
  c17_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c17_y), &c17_thisId, c17_b_y);
  sf_mex_destroy(&c17_y);
  for (c17_i41 = 0; c17_i41 < 16; c17_i41++) {
    (*(int32_T (*)[16])c17_outData)[c17_i41] = c17_b_y[c17_i41];
  }

  sf_mex_destroy(&c17_mxArrayInData);
}

const mxArray *sf_c17_RaspPiPilot_get_eml_resolved_functions_info(void)
{
  const mxArray *c17_nameCaptureInfo = NULL;
  c17_nameCaptureInfo = NULL;
  sf_mex_assign(&c17_nameCaptureInfo, sf_mex_createstruct("structure", 2, 39, 1),
                false);
  c17_info_helper(&c17_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c17_nameCaptureInfo);
  return c17_nameCaptureInfo;
}

static void c17_info_helper(const mxArray **c17_info)
{
  const mxArray *c17_rhs0 = NULL;
  const mxArray *c17_lhs0 = NULL;
  const mxArray *c17_rhs1 = NULL;
  const mxArray *c17_lhs1 = NULL;
  const mxArray *c17_rhs2 = NULL;
  const mxArray *c17_lhs2 = NULL;
  const mxArray *c17_rhs3 = NULL;
  const mxArray *c17_lhs3 = NULL;
  const mxArray *c17_rhs4 = NULL;
  const mxArray *c17_lhs4 = NULL;
  const mxArray *c17_rhs5 = NULL;
  const mxArray *c17_lhs5 = NULL;
  const mxArray *c17_rhs6 = NULL;
  const mxArray *c17_lhs6 = NULL;
  const mxArray *c17_rhs7 = NULL;
  const mxArray *c17_lhs7 = NULL;
  const mxArray *c17_rhs8 = NULL;
  const mxArray *c17_lhs8 = NULL;
  const mxArray *c17_rhs9 = NULL;
  const mxArray *c17_lhs9 = NULL;
  const mxArray *c17_rhs10 = NULL;
  const mxArray *c17_lhs10 = NULL;
  const mxArray *c17_rhs11 = NULL;
  const mxArray *c17_lhs11 = NULL;
  const mxArray *c17_rhs12 = NULL;
  const mxArray *c17_lhs12 = NULL;
  const mxArray *c17_rhs13 = NULL;
  const mxArray *c17_lhs13 = NULL;
  const mxArray *c17_rhs14 = NULL;
  const mxArray *c17_lhs14 = NULL;
  const mxArray *c17_rhs15 = NULL;
  const mxArray *c17_lhs15 = NULL;
  const mxArray *c17_rhs16 = NULL;
  const mxArray *c17_lhs16 = NULL;
  const mxArray *c17_rhs17 = NULL;
  const mxArray *c17_lhs17 = NULL;
  const mxArray *c17_rhs18 = NULL;
  const mxArray *c17_lhs18 = NULL;
  const mxArray *c17_rhs19 = NULL;
  const mxArray *c17_lhs19 = NULL;
  const mxArray *c17_rhs20 = NULL;
  const mxArray *c17_lhs20 = NULL;
  const mxArray *c17_rhs21 = NULL;
  const mxArray *c17_lhs21 = NULL;
  const mxArray *c17_rhs22 = NULL;
  const mxArray *c17_lhs22 = NULL;
  const mxArray *c17_rhs23 = NULL;
  const mxArray *c17_lhs23 = NULL;
  const mxArray *c17_rhs24 = NULL;
  const mxArray *c17_lhs24 = NULL;
  const mxArray *c17_rhs25 = NULL;
  const mxArray *c17_lhs25 = NULL;
  const mxArray *c17_rhs26 = NULL;
  const mxArray *c17_lhs26 = NULL;
  const mxArray *c17_rhs27 = NULL;
  const mxArray *c17_lhs27 = NULL;
  const mxArray *c17_rhs28 = NULL;
  const mxArray *c17_lhs28 = NULL;
  const mxArray *c17_rhs29 = NULL;
  const mxArray *c17_lhs29 = NULL;
  const mxArray *c17_rhs30 = NULL;
  const mxArray *c17_lhs30 = NULL;
  const mxArray *c17_rhs31 = NULL;
  const mxArray *c17_lhs31 = NULL;
  const mxArray *c17_rhs32 = NULL;
  const mxArray *c17_lhs32 = NULL;
  const mxArray *c17_rhs33 = NULL;
  const mxArray *c17_lhs33 = NULL;
  const mxArray *c17_rhs34 = NULL;
  const mxArray *c17_lhs34 = NULL;
  const mxArray *c17_rhs35 = NULL;
  const mxArray *c17_lhs35 = NULL;
  const mxArray *c17_rhs36 = NULL;
  const mxArray *c17_lhs36 = NULL;
  const mxArray *c17_rhs37 = NULL;
  const mxArray *c17_lhs37 = NULL;
  const mxArray *c17_rhs38 = NULL;
  const mxArray *c17_lhs38 = NULL;
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("length"), "name", "name", 0);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("int32"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(1303149806U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c17_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c17_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(""), "context", "context", 1);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("sort"), "name", "name", 1);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("int32"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sort.m"), "resolved",
                  "resolved", 1);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(1363717456U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c17_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c17_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sort.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 2);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("int32"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(1363718156U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c17_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c17_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sort.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("eml_sort"), "name", "name",
                  3);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("int32"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_sort.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(1314740212U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c17_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c17_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_sort.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("eml_nonsingleton_dim"),
                  "name", "name", 4);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("int32"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_nonsingleton_dim.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(1307654842U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c17_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c17_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_nonsingleton_dim.m"),
                  "context", "context", 5);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 5);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(1323174178U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c17_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c17_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_sort.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("eml_assert_valid_dim"),
                  "name", "name", 6);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 6);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_dim.m"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(1372586016U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c17_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c17_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_dim.m"),
                  "context", "context", 7);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "coder.internal.assertValidDim"), "name", "name", 7);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 7);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assertValidDim.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(1372586760U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c17_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c17_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assertValidDim.m"),
                  "context", "context", 8);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 8);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 8);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(1363718156U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c17_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c17_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assertValidDim.m"),
                  "context", "context", 9);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("floor"), "name", "name", 9);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 9);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 9);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(1363717454U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c17_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c17_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 10);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 10);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 10);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(1363718156U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c17_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c17_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 11);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 11);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 11);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(1286822326U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c17_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c17_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assertValidDim.m"),
                  "context", "context", 12);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("intmax"), "name", "name", 12);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 12);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(1362265482U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c17_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c17_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "context",
                  "context", 13);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 13);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(1381853900U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c17_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c17_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_sort.m"), "context",
                  "context", 14);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 14);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("int32"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 14);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(1375984288U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c17_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c17_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 15);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 15);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("int32"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 15);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(1389311520U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c17_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c17_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_sort.m"), "context",
                  "context", 16);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("eml_sort_idx"), "name",
                  "name", 16);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("int32"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_sort_idx.m"), "resolved",
                  "resolved", 16);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(1305321604U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c17_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c17_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_sort_idx.m"), "context",
                  "context", 17);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 17);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 17);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(1323174178U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c17_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c17_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_sort_idx.m"), "context",
                  "context", 18);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("eml_size_ispow2"), "name",
                  "name", 18);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 18);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_size_ispow2.m"),
                  "resolved", "resolved", 18);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(1363717470U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c17_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c17_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_size_ispow2.m"),
                  "context", "context", 19);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("eml_unsigned_class"), "name",
                  "name", 19);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_unsigned_class.m"),
                  "resolved", "resolved", 19);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(1375984288U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c17_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c17_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_unsigned_class.m"),
                  "context", "context", 20);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "coder.internal.unsignedClass"), "name", "name", 20);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/unsignedClass.p"),
                  "resolved", "resolved", 20);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(1389311522U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c17_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c17_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/unsignedClass.p"),
                  "context", "context", 21);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 21);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 21);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(1381853900U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c17_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c17_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/unsignedClass.p"),
                  "context", "context", 22);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 22);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 22);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(1323174178U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c17_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c17_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_sort_idx.m"), "context",
                  "context", 23);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 23);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 23);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 23);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(1372586016U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c17_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c17_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"), "context",
                  "context", 24);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 24);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 24);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 24);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(1372586760U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c17_rhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c17_lhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_sort_idx.m"), "context",
                  "context", 25);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 25);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 25);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(1375984288U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c17_rhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c17_lhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_lhs25), "lhs", "lhs",
                  25);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 26);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("intmax"), "name", "name", 26);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 26);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 26);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(1362265482U), "fileTimeLo",
                  "fileTimeLo", 26);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 26);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 26);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 26);
  sf_mex_assign(&c17_rhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c17_lhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_rhs26), "rhs", "rhs",
                  26);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_lhs26), "lhs", "lhs",
                  26);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_sort_idx.m"), "context",
                  "context", 27);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("eml_index_minus"), "name",
                  "name", 27);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 27);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m"),
                  "resolved", "resolved", 27);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(1372586016U), "fileTimeLo",
                  "fileTimeLo", 27);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 27);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 27);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 27);
  sf_mex_assign(&c17_rhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c17_lhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_rhs27), "rhs", "rhs",
                  27);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_lhs27), "lhs", "lhs",
                  27);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m"),
                  "context", "context", 28);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("coder.internal.indexMinus"),
                  "name", "name", 28);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 28);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexMinus.m"),
                  "resolved", "resolved", 28);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(1372586760U), "fileTimeLo",
                  "fileTimeLo", 28);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 28);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 28);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 28);
  sf_mex_assign(&c17_rhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c17_lhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_rhs28), "rhs", "rhs",
                  28);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_lhs28), "lhs", "lhs",
                  28);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_sort_idx.m"), "context",
                  "context", 29);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 29);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 29);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 29);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(1372586016U), "fileTimeLo",
                  "fileTimeLo", 29);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 29);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 29);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 29);
  sf_mex_assign(&c17_rhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c17_lhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_rhs29), "rhs", "rhs",
                  29);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_lhs29), "lhs", "lhs",
                  29);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"), "context",
                  "context", 30);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 30);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 30);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 30);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(1372586760U), "fileTimeLo",
                  "fileTimeLo", 30);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 30);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 30);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 30);
  sf_mex_assign(&c17_rhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c17_lhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_rhs30), "rhs", "rhs",
                  30);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_lhs30), "lhs", "lhs",
                  30);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_sort_idx.m"), "context",
                  "context", 31);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("eml_sort_le"), "name",
                  "name", 31);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("int32"), "dominantType",
                  "dominantType", 31);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_sort_le.m"), "resolved",
                  "resolved", 31);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(1292194110U), "fileTimeLo",
                  "fileTimeLo", 31);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 31);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 31);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 31);
  sf_mex_assign(&c17_rhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c17_lhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_rhs31), "rhs", "rhs",
                  31);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_lhs31), "lhs", "lhs",
                  31);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_sort_le.m!eml_sort_ascending_le"),
                  "context", "context", 32);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("eml_relop"), "name", "name",
                  32);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("function_handle"),
                  "dominantType", "dominantType", 32);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_relop.m"), "resolved",
                  "resolved", 32);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(1342454782U), "fileTimeLo",
                  "fileTimeLo", 32);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 32);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 32);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 32);
  sf_mex_assign(&c17_rhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c17_lhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_rhs32), "rhs", "rhs",
                  32);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_lhs32), "lhs", "lhs",
                  32);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_sort_le.m!eml_sort_ascending_le"),
                  "context", "context", 33);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("isnan"), "name", "name", 33);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("int32"), "dominantType",
                  "dominantType", 33);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 33);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(1363717458U), "fileTimeLo",
                  "fileTimeLo", 33);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 33);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 33);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 33);
  sf_mex_assign(&c17_rhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c17_lhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_rhs33), "rhs", "rhs",
                  33);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_lhs33), "lhs", "lhs",
                  33);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "context",
                  "context", 34);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 34);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("int32"), "dominantType",
                  "dominantType", 34);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 34);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(1363718156U), "fileTimeLo",
                  "fileTimeLo", 34);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 34);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 34);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 34);
  sf_mex_assign(&c17_rhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c17_lhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_rhs34), "rhs", "rhs",
                  34);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_lhs34), "lhs", "lhs",
                  34);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_sort_idx.m"), "context",
                  "context", 35);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("eml_index_times"), "name",
                  "name", 35);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 35);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m"),
                  "resolved", "resolved", 35);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(1372586016U), "fileTimeLo",
                  "fileTimeLo", 35);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 35);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 35);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 35);
  sf_mex_assign(&c17_rhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c17_lhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_rhs35), "rhs", "rhs",
                  35);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_lhs35), "lhs", "lhs",
                  35);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m"),
                  "context", "context", 36);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("coder.internal.indexTimes"),
                  "name", "name", 36);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 36);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexTimes.m"),
                  "resolved", "resolved", 36);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(1372586760U), "fileTimeLo",
                  "fileTimeLo", 36);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 36);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 36);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 36);
  sf_mex_assign(&c17_rhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c17_lhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_rhs36), "rhs", "rhs",
                  36);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_lhs36), "lhs", "lhs",
                  36);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_sort_idx.m"), "context",
                  "context", 37);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("eml_index_minus"), "name",
                  "name", 37);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 37);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m"),
                  "resolved", "resolved", 37);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(1372586016U), "fileTimeLo",
                  "fileTimeLo", 37);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 37);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 37);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 37);
  sf_mex_assign(&c17_rhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c17_lhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_rhs37), "rhs", "rhs",
                  37);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_lhs37), "lhs", "lhs",
                  37);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m"),
                  "context", "context", 38);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("coder.internal.indexMinus"),
                  "name", "name", 38);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 38);
  sf_mex_addfield(*c17_info, c17_emlrt_marshallOut(
    "[IXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexMinus.m"),
                  "resolved", "resolved", 38);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(1372586760U), "fileTimeLo",
                  "fileTimeLo", 38);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 38);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 38);
  sf_mex_addfield(*c17_info, c17_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 38);
  sf_mex_assign(&c17_rhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c17_lhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_rhs38), "rhs", "rhs",
                  38);
  sf_mex_addfield(*c17_info, sf_mex_duplicatearraysafe(&c17_lhs38), "lhs", "lhs",
                  38);
  sf_mex_destroy(&c17_rhs0);
  sf_mex_destroy(&c17_lhs0);
  sf_mex_destroy(&c17_rhs1);
  sf_mex_destroy(&c17_lhs1);
  sf_mex_destroy(&c17_rhs2);
  sf_mex_destroy(&c17_lhs2);
  sf_mex_destroy(&c17_rhs3);
  sf_mex_destroy(&c17_lhs3);
  sf_mex_destroy(&c17_rhs4);
  sf_mex_destroy(&c17_lhs4);
  sf_mex_destroy(&c17_rhs5);
  sf_mex_destroy(&c17_lhs5);
  sf_mex_destroy(&c17_rhs6);
  sf_mex_destroy(&c17_lhs6);
  sf_mex_destroy(&c17_rhs7);
  sf_mex_destroy(&c17_lhs7);
  sf_mex_destroy(&c17_rhs8);
  sf_mex_destroy(&c17_lhs8);
  sf_mex_destroy(&c17_rhs9);
  sf_mex_destroy(&c17_lhs9);
  sf_mex_destroy(&c17_rhs10);
  sf_mex_destroy(&c17_lhs10);
  sf_mex_destroy(&c17_rhs11);
  sf_mex_destroy(&c17_lhs11);
  sf_mex_destroy(&c17_rhs12);
  sf_mex_destroy(&c17_lhs12);
  sf_mex_destroy(&c17_rhs13);
  sf_mex_destroy(&c17_lhs13);
  sf_mex_destroy(&c17_rhs14);
  sf_mex_destroy(&c17_lhs14);
  sf_mex_destroy(&c17_rhs15);
  sf_mex_destroy(&c17_lhs15);
  sf_mex_destroy(&c17_rhs16);
  sf_mex_destroy(&c17_lhs16);
  sf_mex_destroy(&c17_rhs17);
  sf_mex_destroy(&c17_lhs17);
  sf_mex_destroy(&c17_rhs18);
  sf_mex_destroy(&c17_lhs18);
  sf_mex_destroy(&c17_rhs19);
  sf_mex_destroy(&c17_lhs19);
  sf_mex_destroy(&c17_rhs20);
  sf_mex_destroy(&c17_lhs20);
  sf_mex_destroy(&c17_rhs21);
  sf_mex_destroy(&c17_lhs21);
  sf_mex_destroy(&c17_rhs22);
  sf_mex_destroy(&c17_lhs22);
  sf_mex_destroy(&c17_rhs23);
  sf_mex_destroy(&c17_lhs23);
  sf_mex_destroy(&c17_rhs24);
  sf_mex_destroy(&c17_lhs24);
  sf_mex_destroy(&c17_rhs25);
  sf_mex_destroy(&c17_lhs25);
  sf_mex_destroy(&c17_rhs26);
  sf_mex_destroy(&c17_lhs26);
  sf_mex_destroy(&c17_rhs27);
  sf_mex_destroy(&c17_lhs27);
  sf_mex_destroy(&c17_rhs28);
  sf_mex_destroy(&c17_lhs28);
  sf_mex_destroy(&c17_rhs29);
  sf_mex_destroy(&c17_lhs29);
  sf_mex_destroy(&c17_rhs30);
  sf_mex_destroy(&c17_lhs30);
  sf_mex_destroy(&c17_rhs31);
  sf_mex_destroy(&c17_lhs31);
  sf_mex_destroy(&c17_rhs32);
  sf_mex_destroy(&c17_lhs32);
  sf_mex_destroy(&c17_rhs33);
  sf_mex_destroy(&c17_lhs33);
  sf_mex_destroy(&c17_rhs34);
  sf_mex_destroy(&c17_lhs34);
  sf_mex_destroy(&c17_rhs35);
  sf_mex_destroy(&c17_lhs35);
  sf_mex_destroy(&c17_rhs36);
  sf_mex_destroy(&c17_lhs36);
  sf_mex_destroy(&c17_rhs37);
  sf_mex_destroy(&c17_lhs37);
  sf_mex_destroy(&c17_rhs38);
  sf_mex_destroy(&c17_lhs38);
}

static const mxArray *c17_emlrt_marshallOut(const char * c17_u)
{
  const mxArray *c17_y = NULL;
  c17_y = NULL;
  sf_mex_assign(&c17_y, sf_mex_create("y", c17_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c17_u)), false);
  return c17_y;
}

static const mxArray *c17_b_emlrt_marshallOut(const uint32_T c17_u)
{
  const mxArray *c17_y = NULL;
  c17_y = NULL;
  sf_mex_assign(&c17_y, sf_mex_create("y", &c17_u, 7, 0U, 0U, 0U, 0), false);
  return c17_y;
}

static void c17_eml_sort(SFc17_RaspPiPilotInstanceStruct *chartInstance, int32_T
  c17_x[16], int32_T c17_y[16], int32_T c17_idx[16])
{
  int32_T c17_i42;
  int32_T c17_b_x[16];
  for (c17_i42 = 0; c17_i42 < 16; c17_i42++) {
    c17_b_x[c17_i42] = c17_x[c17_i42];
  }

  c17_eml_sort_idx(chartInstance, c17_b_x, c17_idx, c17_y);
}

static void c17_eml_sort_idx(SFc17_RaspPiPilotInstanceStruct *chartInstance,
  int32_T c17_x[16], int32_T c17_idx[16], int32_T c17_y[16])
{
  int32_T c17_k;
  int32_T c17_b_k;
  int32_T c17_c_k;
  int32_T c17_a;
  int32_T c17_b_a;
  int32_T c17_c;
  int32_T c17_irow1;
  int32_T c17_irow2;
  int32_T c17_c_a;
  int32_T c17_b;
  int32_T c17_d_a;
  int32_T c17_b_b;
  boolean_T c17_p;
  boolean_T c17_b0;
  boolean_T c17_b_p;
  int32_T c17_e_a;
  int32_T c17_f_a;
  int32_T c17_b_c;
  int32_T c17_g_a;
  int32_T c17_h_a;
  int32_T c17_c_c;
  int32_T c17_i43;
  int32_T c17_idx0[16];
  int32_T c17_i;
  int32_T c17_i_a;
  int32_T c17_j_a;
  int32_T c17_i2;
  int32_T c17_j;
  int32_T c17_c_b;
  int32_T c17_d_b;
  int32_T c17_pEnd;
  int32_T c17_c_p;
  int32_T c17_q;
  int32_T c17_k_a;
  int32_T c17_e_b;
  int32_T c17_l_a;
  int32_T c17_f_b;
  int32_T c17_qEnd;
  int32_T c17_m_a;
  int32_T c17_g_b;
  int32_T c17_n_a;
  int32_T c17_h_b;
  int32_T c17_kEnd;
  int32_T c17_b_irow1;
  int32_T c17_b_irow2;
  int32_T c17_o_a;
  int32_T c17_i_b;
  int32_T c17_p_a;
  int32_T c17_j_b;
  boolean_T c17_d_p;
  boolean_T c17_b1;
  boolean_T c17_e_p;
  int32_T c17_q_a;
  int32_T c17_r_a;
  int32_T c17_s_a;
  int32_T c17_t_a;
  int32_T c17_u_a;
  int32_T c17_v_a;
  int32_T c17_w_a;
  int32_T c17_x_a;
  int32_T c17_y_a;
  int32_T c17_ab_a;
  int32_T c17_bb_a;
  int32_T c17_cb_a;
  int32_T c17_db_a;
  int32_T c17_eb_a;
  int32_T c17_fb_a;
  int32_T c17_gb_a;
  int32_T c17_b_kEnd;
  int32_T c17_k_b;
  int32_T c17_l_b;
  boolean_T c17_overflow;
  int32_T c17_d_k;
  int32_T c17_hb_a;
  int32_T c17_m_b;
  int32_T c17_ib_a;
  int32_T c17_n_b;
  int32_T c17_d_c;
  int32_T c17_jb_a;
  int32_T c17_o_b;
  int32_T c17_kb_a;
  int32_T c17_p_b;
  int32_T c17_e_k;
  for (c17_k = 1; c17_k < 17; c17_k++) {
    c17_b_k = c17_k;
    c17_idx[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c17_b_k), 1, 16, 1, 0) - 1] = c17_b_k;
  }

  for (c17_c_k = 1; c17_c_k < 16; c17_c_k += 2) {
    c17_b_k = c17_c_k;
    c17_a = c17_b_k;
    c17_b_a = c17_a;
    c17_c = c17_b_a;
    c17_irow1 = c17_b_k;
    c17_irow2 = c17_c + 1;
    c17_c_a = c17_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c17_irow1), 1, 16, 1, 0) - 1];
    c17_b = c17_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c17_irow2), 1, 16, 1, 0) - 1];
    c17_d_a = c17_c_a;
    c17_b_b = c17_b;
    c17_p = (c17_d_a <= c17_b_b);
    c17_b0 = c17_p;
    c17_b_p = c17_b0;
    if (c17_b_p) {
    } else {
      c17_e_a = c17_b_k;
      c17_f_a = c17_e_a;
      c17_b_c = c17_f_a;
      c17_idx[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c17_b_k), 1, 16, 1, 0) - 1] = c17_b_c + 1;
      c17_g_a = c17_b_k;
      c17_h_a = c17_g_a;
      c17_c_c = c17_h_a;
      c17_idx[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)(c17_c_c + 1)), 1, 16, 1, 0) - 1] = c17_b_k;
    }
  }

  for (c17_i43 = 0; c17_i43 < 16; c17_i43++) {
    c17_idx0[c17_i43] = 1;
  }

  c17_i = 2;
  while (c17_i < 16) {
    c17_i_a = c17_i;
    c17_j_a = c17_i_a;
    c17_i2 = c17_j_a << 1;
    c17_j = 1;
    c17_c_b = c17_i;
    c17_d_b = c17_c_b + 1;
    for (c17_pEnd = c17_d_b; c17_pEnd < 17; c17_pEnd = c17_kb_a + c17_p_b) {
      c17_c_p = c17_j;
      c17_q = c17_pEnd;
      c17_k_a = c17_j;
      c17_e_b = c17_i2;
      c17_l_a = c17_k_a;
      c17_f_b = c17_e_b;
      c17_qEnd = c17_l_a + c17_f_b;
      c17_b_k = 1;
      c17_m_a = c17_qEnd;
      c17_g_b = c17_j;
      c17_n_a = c17_m_a;
      c17_h_b = c17_g_b;
      c17_kEnd = c17_n_a - c17_h_b;
      while (c17_b_k <= c17_kEnd) {
        c17_b_irow1 = c17_idx[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c17_c_p), 1, 16, 1, 0) - 1];
        c17_b_irow2 = c17_idx[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c17_q), 1, 16, 1, 0) - 1];
        c17_o_a = c17_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c17_b_irow1), 1, 16, 1, 0) - 1];
        c17_i_b = c17_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c17_b_irow2), 1, 16, 1, 0) - 1];
        c17_p_a = c17_o_a;
        c17_j_b = c17_i_b;
        c17_d_p = (c17_p_a <= c17_j_b);
        c17_b1 = c17_d_p;
        c17_e_p = c17_b1;
        if (c17_e_p) {
          c17_idx0[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
            "", (real_T)c17_b_k), 1, 16, 1, 0) - 1] =
            c17_idx[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
            "", (real_T)c17_c_p), 1, 16, 1, 0) - 1];
          c17_q_a = c17_c_p;
          c17_r_a = c17_q_a + 1;
          c17_c_p = c17_r_a;
          if (c17_c_p == c17_pEnd) {
            while (c17_q < c17_qEnd) {
              c17_s_a = c17_b_k;
              c17_t_a = c17_s_a + 1;
              c17_b_k = c17_t_a;
              c17_idx0[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c17_b_k), 1, 16, 1, 0) - 1] =
                c17_idx[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c17_q), 1, 16, 1, 0) - 1];
              c17_u_a = c17_q;
              c17_v_a = c17_u_a + 1;
              c17_q = c17_v_a;
            }
          }
        } else {
          c17_idx0[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
            "", (real_T)c17_b_k), 1, 16, 1, 0) - 1] =
            c17_idx[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
            "", (real_T)c17_q), 1, 16, 1, 0) - 1];
          c17_w_a = c17_q;
          c17_x_a = c17_w_a + 1;
          c17_q = c17_x_a;
          if (c17_q == c17_qEnd) {
            while (c17_c_p < c17_pEnd) {
              c17_y_a = c17_b_k;
              c17_ab_a = c17_y_a + 1;
              c17_b_k = c17_ab_a;
              c17_idx0[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c17_b_k), 1, 16, 1, 0) - 1] =
                c17_idx[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c17_c_p), 1, 16, 1, 0) - 1];
              c17_bb_a = c17_c_p;
              c17_cb_a = c17_bb_a + 1;
              c17_c_p = c17_cb_a;
            }
          }
        }

        c17_db_a = c17_b_k;
        c17_eb_a = c17_db_a + 1;
        c17_b_k = c17_eb_a;
      }

      c17_fb_a = c17_j;
      c17_gb_a = c17_fb_a;
      c17_c_p = c17_gb_a;
      c17_b_kEnd = c17_kEnd;
      c17_k_b = c17_b_kEnd;
      c17_l_b = c17_k_b;
      if (1 > c17_l_b) {
        c17_overflow = false;
      } else {
        c17_overflow = (c17_l_b > 2147483646);
      }

      if (c17_overflow) {
        c17_check_forloop_overflow_error(chartInstance, c17_overflow);
      }

      for (c17_d_k = 1; c17_d_k <= c17_b_kEnd; c17_d_k++) {
        c17_b_k = c17_d_k;
        c17_hb_a = c17_c_p - 1;
        c17_m_b = c17_b_k;
        c17_ib_a = c17_hb_a;
        c17_n_b = c17_m_b;
        c17_d_c = c17_ib_a + c17_n_b;
        c17_idx[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c17_d_c), 1, 16, 1, 0) - 1] =
          c17_idx0[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
          "", (real_T)c17_b_k), 1, 16, 1, 0) - 1];
      }

      c17_j = c17_qEnd;
      c17_jb_a = c17_j;
      c17_o_b = c17_i;
      c17_kb_a = c17_jb_a;
      c17_p_b = c17_o_b;
    }

    c17_i = c17_i2;
  }

  for (c17_e_k = 1; c17_e_k < 17; c17_e_k++) {
    c17_b_k = c17_e_k;
    c17_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c17_b_k), 1, 16, 1, 0) - 1] = c17_x[_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c17_idx[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c17_b_k), 1, 16, 1, 0) - 1]), 1, 16, 1, 0) - 1];
  }
}

static void c17_check_forloop_overflow_error(SFc17_RaspPiPilotInstanceStruct
  *chartInstance, boolean_T c17_overflow)
{
  int32_T c17_i44;
  static char_T c17_cv0[34] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'i', 'n', 't', '_', 'f', 'o', 'r', 'l', 'o', 'o', 'p',
    '_', 'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w' };

  char_T c17_u[34];
  const mxArray *c17_y = NULL;
  int32_T c17_i45;
  static char_T c17_cv1[23] = { 'c', 'o', 'd', 'e', 'r', '.', 'i', 'n', 't', 'e',
    'r', 'n', 'a', 'l', '.', 'i', 'n', 'd', 'e', 'x', 'I', 'n', 't' };

  char_T c17_b_u[23];
  const mxArray *c17_b_y = NULL;
  (void)chartInstance;
  if (!c17_overflow) {
  } else {
    for (c17_i44 = 0; c17_i44 < 34; c17_i44++) {
      c17_u[c17_i44] = c17_cv0[c17_i44];
    }

    c17_y = NULL;
    sf_mex_assign(&c17_y, sf_mex_create("y", c17_u, 10, 0U, 1U, 0U, 2, 1, 34),
                  false);
    for (c17_i45 = 0; c17_i45 < 23; c17_i45++) {
      c17_b_u[c17_i45] = c17_cv1[c17_i45];
    }

    c17_b_y = NULL;
    sf_mex_assign(&c17_b_y, sf_mex_create("y", c17_b_u, 10, 0U, 1U, 0U, 2, 1, 23),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 2U, 14, c17_y, 14, c17_b_y));
  }
}

static const mxArray *c17_g_sf_marshallOut(void *chartInstanceVoid, void
  *c17_inData)
{
  const mxArray *c17_mxArrayOutData = NULL;
  int32_T c17_u;
  const mxArray *c17_y = NULL;
  SFc17_RaspPiPilotInstanceStruct *chartInstance;
  chartInstance = (SFc17_RaspPiPilotInstanceStruct *)chartInstanceVoid;
  c17_mxArrayOutData = NULL;
  c17_u = *(int32_T *)c17_inData;
  c17_y = NULL;
  sf_mex_assign(&c17_y, sf_mex_create("y", &c17_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c17_mxArrayOutData, c17_y, false);
  return c17_mxArrayOutData;
}

static int32_T c17_f_emlrt_marshallIn(SFc17_RaspPiPilotInstanceStruct
  *chartInstance, const mxArray *c17_u, const emlrtMsgIdentifier *c17_parentId)
{
  int32_T c17_y;
  int32_T c17_i46;
  (void)chartInstance;
  sf_mex_import(c17_parentId, sf_mex_dup(c17_u), &c17_i46, 1, 6, 0U, 0, 0U, 0);
  c17_y = c17_i46;
  sf_mex_destroy(&c17_u);
  return c17_y;
}

static void c17_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c17_mxArrayInData, const char_T *c17_varName, void *c17_outData)
{
  const mxArray *c17_b_sfEvent;
  const char_T *c17_identifier;
  emlrtMsgIdentifier c17_thisId;
  int32_T c17_y;
  SFc17_RaspPiPilotInstanceStruct *chartInstance;
  chartInstance = (SFc17_RaspPiPilotInstanceStruct *)chartInstanceVoid;
  c17_b_sfEvent = sf_mex_dup(c17_mxArrayInData);
  c17_identifier = c17_varName;
  c17_thisId.fIdentifier = c17_identifier;
  c17_thisId.fParent = NULL;
  c17_y = c17_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c17_b_sfEvent),
    &c17_thisId);
  sf_mex_destroy(&c17_b_sfEvent);
  *(int32_T *)c17_outData = c17_y;
  sf_mex_destroy(&c17_mxArrayInData);
}

static uint8_T c17_g_emlrt_marshallIn(SFc17_RaspPiPilotInstanceStruct
  *chartInstance, const mxArray *c17_b_is_active_c17_RaspPiPilot, const char_T
  *c17_identifier)
{
  uint8_T c17_y;
  emlrtMsgIdentifier c17_thisId;
  c17_thisId.fIdentifier = c17_identifier;
  c17_thisId.fParent = NULL;
  c17_y = c17_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c17_b_is_active_c17_RaspPiPilot), &c17_thisId);
  sf_mex_destroy(&c17_b_is_active_c17_RaspPiPilot);
  return c17_y;
}

static uint8_T c17_h_emlrt_marshallIn(SFc17_RaspPiPilotInstanceStruct
  *chartInstance, const mxArray *c17_u, const emlrtMsgIdentifier *c17_parentId)
{
  uint8_T c17_y;
  uint8_T c17_u0;
  (void)chartInstance;
  sf_mex_import(c17_parentId, sf_mex_dup(c17_u), &c17_u0, 1, 3, 0U, 0, 0U, 0);
  c17_y = c17_u0;
  sf_mex_destroy(&c17_u);
  return c17_y;
}

static void init_dsm_address_info(SFc17_RaspPiPilotInstanceStruct *chartInstance)
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

void sf_c17_RaspPiPilot_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2490953285U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(838592964U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3030840602U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(183700202U);
}

mxArray *sf_c17_RaspPiPilot_get_autoinheritance_info(void)
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

mxArray *sf_c17_RaspPiPilot_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c17_RaspPiPilot_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c17_RaspPiPilot(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[8],T\"centroid_largest\",},{M[8],M[0],T\"is_active_c17_RaspPiPilot\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c17_RaspPiPilot_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc17_RaspPiPilotInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc17_RaspPiPilotInstanceStruct *) chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _RaspPiPilotMachineNumber_,
           17,
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
            1.0,0,0,(MexFcnForType)c17_sf_marshallOut,(MexInFcnForType)
            c17_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 16;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_INT32,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c17_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 16;
          dimVector[1]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c17_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          real_T (*c17_centroid_largest)[6];
          int32_T (*c17_area)[16];
          real_T (*c17_centroid)[32];
          c17_centroid = (real_T (*)[32])ssGetInputPortSignal(chartInstance->S,
            1);
          c17_area = (int32_T (*)[16])ssGetInputPortSignal(chartInstance->S, 0);
          c17_centroid_largest = (real_T (*)[6])ssGetOutputPortSignal
            (chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, *c17_centroid_largest);
          _SFD_SET_DATA_VALUE_PTR(1U, *c17_area);
          _SFD_SET_DATA_VALUE_PTR(2U, *c17_centroid);
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

static void sf_opaque_initialize_c17_RaspPiPilot(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc17_RaspPiPilotInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c17_RaspPiPilot((SFc17_RaspPiPilotInstanceStruct*)
    chartInstanceVar);
  initialize_c17_RaspPiPilot((SFc17_RaspPiPilotInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c17_RaspPiPilot(void *chartInstanceVar)
{
  enable_c17_RaspPiPilot((SFc17_RaspPiPilotInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c17_RaspPiPilot(void *chartInstanceVar)
{
  disable_c17_RaspPiPilot((SFc17_RaspPiPilotInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c17_RaspPiPilot(void *chartInstanceVar)
{
  sf_gateway_c17_RaspPiPilot((SFc17_RaspPiPilotInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c17_RaspPiPilot(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c17_RaspPiPilot
    ((SFc17_RaspPiPilotInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c17_RaspPiPilot();/* state var info */
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

extern void sf_internal_set_sim_state_c17_RaspPiPilot(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c17_RaspPiPilot();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c17_RaspPiPilot((SFc17_RaspPiPilotInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c17_RaspPiPilot(SimStruct* S)
{
  return sf_internal_get_sim_state_c17_RaspPiPilot(S);
}

static void sf_opaque_set_sim_state_c17_RaspPiPilot(SimStruct* S, const mxArray *
  st)
{
  sf_internal_set_sim_state_c17_RaspPiPilot(S, st);
}

static void sf_opaque_terminate_c17_RaspPiPilot(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc17_RaspPiPilotInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_RaspPiPilot_optimization_info();
    }

    finalize_c17_RaspPiPilot((SFc17_RaspPiPilotInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    if (crtInfo != NULL) {
      utFree((void *)crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc17_RaspPiPilot((SFc17_RaspPiPilotInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c17_RaspPiPilot(SimStruct *S)
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
    initialize_params_c17_RaspPiPilot((SFc17_RaspPiPilotInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c17_RaspPiPilot(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_RaspPiPilot_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      17);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,17,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,17,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,17);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,17,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,17,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,17);
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

static void mdlRTW_c17_RaspPiPilot(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c17_RaspPiPilot(SimStruct *S)
{
  SFc17_RaspPiPilotInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc17_RaspPiPilotInstanceStruct *)utMalloc(sizeof
    (SFc17_RaspPiPilotInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc17_RaspPiPilotInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c17_RaspPiPilot;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c17_RaspPiPilot;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c17_RaspPiPilot;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c17_RaspPiPilot;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c17_RaspPiPilot;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c17_RaspPiPilot;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c17_RaspPiPilot;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c17_RaspPiPilot;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c17_RaspPiPilot;
  chartInstance->chartInfo.mdlStart = mdlStart_c17_RaspPiPilot;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c17_RaspPiPilot;
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

void c17_RaspPiPilot_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c17_RaspPiPilot(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c17_RaspPiPilot(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c17_RaspPiPilot(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c17_RaspPiPilot_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
