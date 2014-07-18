/* Include files */

#include <stddef.h>
#include "blas.h"
#include "RaspPiPilot_sfun.h"
#include "c10_RaspPiPilot.h"
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
static const char * c10_debug_family_names[2] = { "nargin", "nargout" };

/* Function Declarations */
static void initialize_c10_RaspPiPilot(SFc10_RaspPiPilotInstanceStruct
  *chartInstance);
static void initialize_params_c10_RaspPiPilot(SFc10_RaspPiPilotInstanceStruct
  *chartInstance);
static void enable_c10_RaspPiPilot(SFc10_RaspPiPilotInstanceStruct
  *chartInstance);
static void disable_c10_RaspPiPilot(SFc10_RaspPiPilotInstanceStruct
  *chartInstance);
static void c10_update_debugger_state_c10_RaspPiPilot
  (SFc10_RaspPiPilotInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c10_RaspPiPilot
  (SFc10_RaspPiPilotInstanceStruct *chartInstance);
static void set_sim_state_c10_RaspPiPilot(SFc10_RaspPiPilotInstanceStruct
  *chartInstance, const mxArray *c10_st);
static void finalize_c10_RaspPiPilot(SFc10_RaspPiPilotInstanceStruct
  *chartInstance);
static void sf_gateway_c10_RaspPiPilot(SFc10_RaspPiPilotInstanceStruct
  *chartInstance);
static void initSimStructsc10_RaspPiPilot(SFc10_RaspPiPilotInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c10_machineNumber, uint32_T
  c10_chartNumber, uint32_T c10_instanceNumber);
static const mxArray *c10_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static real_T c10_emlrt_marshallIn(SFc10_RaspPiPilotInstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId);
static void c10_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData);
static const mxArray *c10_b_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static int32_T c10_b_emlrt_marshallIn(SFc10_RaspPiPilotInstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId);
static void c10_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData);
static uint8_T c10_c_emlrt_marshallIn(SFc10_RaspPiPilotInstanceStruct
  *chartInstance, const mxArray *c10_b_is_active_c10_RaspPiPilot, const char_T
  *c10_identifier);
static uint8_T c10_d_emlrt_marshallIn(SFc10_RaspPiPilotInstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId);
static int32_T c10_get_spHandle(SFc10_RaspPiPilotInstanceStruct *chartInstance,
  uint32_T c10_b);
static void c10_set_spHandle(SFc10_RaspPiPilotInstanceStruct *chartInstance,
  uint32_T c10_b, int32_T c10_c);
static int32_T *c10_access_spHandle(SFc10_RaspPiPilotInstanceStruct
  *chartInstance, uint32_T c10_b);
static void init_dsm_address_info(SFc10_RaspPiPilotInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c10_RaspPiPilot(SFc10_RaspPiPilotInstanceStruct
  *chartInstance)
{
  chartInstance->c10_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c10_is_active_c10_RaspPiPilot = 0U;
}

static void initialize_params_c10_RaspPiPilot(SFc10_RaspPiPilotInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void enable_c10_RaspPiPilot(SFc10_RaspPiPilotInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c10_RaspPiPilot(SFc10_RaspPiPilotInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c10_update_debugger_state_c10_RaspPiPilot
  (SFc10_RaspPiPilotInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c10_RaspPiPilot
  (SFc10_RaspPiPilotInstanceStruct *chartInstance)
{
  const mxArray *c10_st;
  const mxArray *c10_y = NULL;
  uint8_T c10_hoistedGlobal;
  uint8_T c10_u;
  const mxArray *c10_b_y = NULL;
  c10_st = NULL;
  c10_st = NULL;
  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_createcellmatrix(1, 1), false);
  c10_hoistedGlobal = chartInstance->c10_is_active_c10_RaspPiPilot;
  c10_u = c10_hoistedGlobal;
  c10_b_y = NULL;
  sf_mex_assign(&c10_b_y, sf_mex_create("y", &c10_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c10_y, 0, c10_b_y);
  sf_mex_assign(&c10_st, c10_y, false);
  return c10_st;
}

static void set_sim_state_c10_RaspPiPilot(SFc10_RaspPiPilotInstanceStruct
  *chartInstance, const mxArray *c10_st)
{
  const mxArray *c10_u;
  chartInstance->c10_doneDoubleBufferReInit = true;
  c10_u = sf_mex_dup(c10_st);
  chartInstance->c10_is_active_c10_RaspPiPilot = c10_c_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c10_u, 0)),
     "is_active_c10_RaspPiPilot");
  sf_mex_destroy(&c10_u);
  c10_update_debugger_state_c10_RaspPiPilot(chartInstance);
  sf_mex_destroy(&c10_st);
}

static void finalize_c10_RaspPiPilot(SFc10_RaspPiPilotInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c10_RaspPiPilot(SFc10_RaspPiPilotInstanceStruct
  *chartInstance)
{
  uint32_T c10_debug_family_var_map[2];
  real_T c10_nargin = 0.0;
  real_T c10_nargout = 0.0;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 7U, chartInstance->c10_sfEvent);
  chartInstance->c10_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 7U, chartInstance->c10_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c10_debug_family_names,
    c10_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargin, 0U, c10_sf_marshallOut,
    c10_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargout, 1U, c10_sf_marshallOut,
    c10_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 2);
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 3);
  CV_EML_COND(0, 1, 0, true);
  CV_EML_MCDC(0, 1, 0, false);
  CV_EML_IF(0, 1, 0, false);
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, -6);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c10_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_RaspPiPilotMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc10_RaspPiPilot(SFc10_RaspPiPilotInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c10_machineNumber, uint32_T
  c10_chartNumber, uint32_T c10_instanceNumber)
{
  (void)c10_machineNumber;
  (void)c10_chartNumber;
  (void)c10_instanceNumber;
}

static const mxArray *c10_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  real_T c10_u;
  const mxArray *c10_y = NULL;
  SFc10_RaspPiPilotInstanceStruct *chartInstance;
  chartInstance = (SFc10_RaspPiPilotInstanceStruct *)chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  c10_u = *(real_T *)c10_inData;
  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", &c10_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static real_T c10_emlrt_marshallIn(SFc10_RaspPiPilotInstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId)
{
  real_T c10_y;
  real_T c10_d0;
  (void)chartInstance;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), &c10_d0, 1, 0, 0U, 0, 0U, 0);
  c10_y = c10_d0;
  sf_mex_destroy(&c10_u);
  return c10_y;
}

static void c10_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData)
{
  const mxArray *c10_nargout;
  const char_T *c10_identifier;
  emlrtMsgIdentifier c10_thisId;
  real_T c10_y;
  SFc10_RaspPiPilotInstanceStruct *chartInstance;
  chartInstance = (SFc10_RaspPiPilotInstanceStruct *)chartInstanceVoid;
  c10_nargout = sf_mex_dup(c10_mxArrayInData);
  c10_identifier = c10_varName;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_y = c10_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_nargout),
    &c10_thisId);
  sf_mex_destroy(&c10_nargout);
  *(real_T *)c10_outData = c10_y;
  sf_mex_destroy(&c10_mxArrayInData);
}

const mxArray *sf_c10_RaspPiPilot_get_eml_resolved_functions_info(void)
{
  const mxArray *c10_nameCaptureInfo = NULL;
  c10_nameCaptureInfo = NULL;
  sf_mex_assign(&c10_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c10_nameCaptureInfo;
}

static const mxArray *c10_b_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_u;
  const mxArray *c10_y = NULL;
  SFc10_RaspPiPilotInstanceStruct *chartInstance;
  chartInstance = (SFc10_RaspPiPilotInstanceStruct *)chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  c10_u = *(int32_T *)c10_inData;
  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", &c10_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, false);
  return c10_mxArrayOutData;
}

static int32_T c10_b_emlrt_marshallIn(SFc10_RaspPiPilotInstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId)
{
  int32_T c10_y;
  int32_T c10_i0;
  (void)chartInstance;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), &c10_i0, 1, 6, 0U, 0, 0U, 0);
  c10_y = c10_i0;
  sf_mex_destroy(&c10_u);
  return c10_y;
}

static void c10_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData)
{
  const mxArray *c10_b_sfEvent;
  const char_T *c10_identifier;
  emlrtMsgIdentifier c10_thisId;
  int32_T c10_y;
  SFc10_RaspPiPilotInstanceStruct *chartInstance;
  chartInstance = (SFc10_RaspPiPilotInstanceStruct *)chartInstanceVoid;
  c10_b_sfEvent = sf_mex_dup(c10_mxArrayInData);
  c10_identifier = c10_varName;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_y = c10_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_b_sfEvent),
    &c10_thisId);
  sf_mex_destroy(&c10_b_sfEvent);
  *(int32_T *)c10_outData = c10_y;
  sf_mex_destroy(&c10_mxArrayInData);
}

static uint8_T c10_c_emlrt_marshallIn(SFc10_RaspPiPilotInstanceStruct
  *chartInstance, const mxArray *c10_b_is_active_c10_RaspPiPilot, const char_T
  *c10_identifier)
{
  uint8_T c10_y;
  emlrtMsgIdentifier c10_thisId;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_y = c10_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c10_b_is_active_c10_RaspPiPilot), &c10_thisId);
  sf_mex_destroy(&c10_b_is_active_c10_RaspPiPilot);
  return c10_y;
}

static uint8_T c10_d_emlrt_marshallIn(SFc10_RaspPiPilotInstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId)
{
  uint8_T c10_y;
  uint8_T c10_u0;
  (void)chartInstance;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), &c10_u0, 1, 3, 0U, 0, 0U, 0);
  c10_y = c10_u0;
  sf_mex_destroy(&c10_u);
  return c10_y;
}

static int32_T c10_get_spHandle(SFc10_RaspPiPilotInstanceStruct *chartInstance,
  uint32_T c10_b)
{
  ssReadFromDataStoreElement(chartInstance->S, 0, NULL, c10_b);
  if (chartInstance->c10_spHandle_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'spHandle\' (#712) in the initialization routine of the chart.\n");
  }

  return *chartInstance->c10_spHandle_address;
}

static void c10_set_spHandle(SFc10_RaspPiPilotInstanceStruct *chartInstance,
  uint32_T c10_b, int32_T c10_c)
{
  ssWriteToDataStoreElement(chartInstance->S, 0, NULL, c10_b);
  if (chartInstance->c10_spHandle_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'spHandle\' (#712) in the initialization routine of the chart.\n");
  }

  *chartInstance->c10_spHandle_address = c10_c;
}

static int32_T *c10_access_spHandle(SFc10_RaspPiPilotInstanceStruct
  *chartInstance, uint32_T c10_b)
{
  int32_T *c10_c;
  ssReadFromDataStore(chartInstance->S, 0, NULL);
  if (chartInstance->c10_spHandle_address == 0) {
    sf_mex_error_message("Invalid access to Data Store Memory data \'spHandle\' (#712) in the initialization routine of the chart.\n");
  }

  c10_c = chartInstance->c10_spHandle_address;
  if (c10_b == 0) {
    ssWriteToDataStore(chartInstance->S, 0, NULL);
  }

  return c10_c;
}

static void init_dsm_address_info(SFc10_RaspPiPilotInstanceStruct *chartInstance)
{
  ssGetSFcnDataStoreNameAddrIdx(chartInstance->S, "spHandle", (void **)
    &chartInstance->c10_spHandle_address, &chartInstance->c10_spHandle_index);
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

void sf_c10_RaspPiPilot_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2365855865U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1314469345U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1708227305U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(666901602U);
}

mxArray *sf_c10_RaspPiPilot_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("XbrBH2gCVDFBU3a8VcFIGG");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c10_RaspPiPilot_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c10_RaspPiPilot_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c10_RaspPiPilot(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S'type','srcId','name','auxInfo'{{M[8],M[0],T\"is_active_c10_RaspPiPilot\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 1, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c10_RaspPiPilot_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc10_RaspPiPilotInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc10_RaspPiPilotInstanceStruct *) chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _RaspPiPilotMachineNumber_,
           10,
           1,
           1,
           0,
           1,
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
          _SFD_SET_DATA_PROPS(0,11,0,0,"spHandle");
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
        _SFD_CV_INIT_EML(0,1,1,2,0,0,0,0,0,3,2);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,242);
        _SFD_CV_INIT_EML_IF(0,1,0,37,61,-1,237);
        _SFD_CV_INIT_EML_IF(0,1,1,69,103,-1,232);

        {
          static int condStart[] = { 41 };

          static int condEnd[] = { 61 };

          static int pfixExpr[] = { 0, -1 };

          _SFD_CV_INIT_EML_MCDC(0,1,0,40,61,1,0,&(condStart[0]),&(condEnd[0]),2,
                                &(pfixExpr[0]));
        }

        {
          static int condStart[] = { 72, 91 };

          static int condEnd[] = { 89, 103 };

          static int pfixExpr[] = { 0, 1, -2 };

          _SFD_CV_INIT_EML_MCDC(0,1,1,72,103,2,1,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_INT32,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c10_b_sf_marshallOut,(MexInFcnForType)
          c10_b_sf_marshallIn);
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c10_spHandle_address);
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
  return "o8KY0hG91xhuqbEFb6AEvB";
}

static void sf_opaque_initialize_c10_RaspPiPilot(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc10_RaspPiPilotInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c10_RaspPiPilot((SFc10_RaspPiPilotInstanceStruct*)
    chartInstanceVar);
  initialize_c10_RaspPiPilot((SFc10_RaspPiPilotInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c10_RaspPiPilot(void *chartInstanceVar)
{
  enable_c10_RaspPiPilot((SFc10_RaspPiPilotInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c10_RaspPiPilot(void *chartInstanceVar)
{
  disable_c10_RaspPiPilot((SFc10_RaspPiPilotInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c10_RaspPiPilot(void *chartInstanceVar)
{
  sf_gateway_c10_RaspPiPilot((SFc10_RaspPiPilotInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c10_RaspPiPilot(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c10_RaspPiPilot
    ((SFc10_RaspPiPilotInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c10_RaspPiPilot();/* state var info */
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

extern void sf_internal_set_sim_state_c10_RaspPiPilot(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c10_RaspPiPilot();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c10_RaspPiPilot((SFc10_RaspPiPilotInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c10_RaspPiPilot(SimStruct* S)
{
  return sf_internal_get_sim_state_c10_RaspPiPilot(S);
}

static void sf_opaque_set_sim_state_c10_RaspPiPilot(SimStruct* S, const mxArray *
  st)
{
  sf_internal_set_sim_state_c10_RaspPiPilot(S, st);
}

static void sf_opaque_terminate_c10_RaspPiPilot(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc10_RaspPiPilotInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_RaspPiPilot_optimization_info();
    }

    finalize_c10_RaspPiPilot((SFc10_RaspPiPilotInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    if (crtInfo != NULL) {
      utFree((void *)crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc10_RaspPiPilot((SFc10_RaspPiPilotInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c10_RaspPiPilot(SimStruct *S)
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
    initialize_params_c10_RaspPiPilot((SFc10_RaspPiPilotInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c10_RaspPiPilot(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_RaspPiPilot_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      10);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,10,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,10,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,10);
    if (chartIsInlinable) {
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=0; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,10);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(79963868U));
  ssSetChecksum1(S,(2315555417U));
  ssSetChecksum2(S,(1692174817U));
  ssSetChecksum3(S,(330306425U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,0);
}

static void mdlRTW_c10_RaspPiPilot(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c10_RaspPiPilot(SimStruct *S)
{
  SFc10_RaspPiPilotInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc10_RaspPiPilotInstanceStruct *)utMalloc(sizeof
    (SFc10_RaspPiPilotInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc10_RaspPiPilotInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c10_RaspPiPilot;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c10_RaspPiPilot;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c10_RaspPiPilot;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c10_RaspPiPilot;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c10_RaspPiPilot;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c10_RaspPiPilot;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c10_RaspPiPilot;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c10_RaspPiPilot;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c10_RaspPiPilot;
  chartInstance->chartInfo.mdlStart = mdlStart_c10_RaspPiPilot;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c10_RaspPiPilot;
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

void c10_RaspPiPilot_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c10_RaspPiPilot(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c10_RaspPiPilot(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c10_RaspPiPilot(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c10_RaspPiPilot_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}