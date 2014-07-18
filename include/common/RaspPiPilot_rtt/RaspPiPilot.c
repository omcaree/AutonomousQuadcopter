/*
 * File: RaspPiPilot.c
 *
 * Code generated for Simulink model 'RaspPiPilot'.
 *
 * Model version                  : 1.199
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * TLC version                    : 8.6 (Jan 30 2014)
 * C/C++ source code generated on : Wed Jul 09 13:38:36 2014
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "RaspPiPilot.h"
#include "RaspPiPilot_private.h"
#include "RaspPiPilot_dt.h"

/* Named constants for Chart: '<Root>/Chart' */
#define RaspPiPilot_CALL_EVENT         (-1)
#define RaspPiPilot_IN_Armed           ((uint8_T)1U)
#define RaspPiPilot_IN_Disarmed        ((uint8_T)2U)
#define RaspPiPilot_IN_Flying          ((uint8_T)1U)
#define RaspPiPilot_IN_Initializing    ((uint8_T)3U)
#define RaspPiPilot_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define RaspPiPilot_IN_idle            ((uint8_T)1U)
#define RaspPiPilot_IN_sendArm         ((uint8_T)2U)
#define RaspPiPilot_IN_sendDisarm      ((uint8_T)2U)

/* Block signals (auto storage) */
B_RaspPiPilot_T RaspPiPilot_B;

/* Block states (auto storage) */
DW_RaspPiPilot_T RaspPiPilot_DW;

/* Real-time model */
RT_MODEL_RaspPiPilot_T RaspPiPilot_M_;
RT_MODEL_RaspPiPilot_T *const RaspPiPilot_M = &RaspPiPilot_M_;

/* Forward declaration for local functions */
static void RaspPiPilot_sendArmDisarmFun(real_T armdisarm, uint8_T data[256],
  uint8_T *length);
static void RaspPiPilot_requestStreams(uint8_T data[256], uint8_T *length);
static void RaspPiPilot_sendRPYT(real_T R, real_T P, real_T Y, real_T T, uint8_T
  data[256], uint8_T *length);
static void RaspPiPilot_scalexpAlloc(const int32_T varargin_1_sizes[2], int32_T
  z_sizes[2]);
static void RaspPiPilot_scalexpAlloc_i(const int32_T varargin_1_sizes[2],
  int32_T z_sizes[2]);
static void rate_scheduler(void);
int32_T div_s32_floor(int32_T numerator, int32_T denominator)
{
  int32_T quotient;
  uint32_T absNumerator;
  uint32_T absDenominator;
  uint32_T tempAbsQuotient;
  boolean_T quotientNeedsNegation;
  if (denominator == 0) {
    quotient = numerator >= 0 ? MAX_int32_T : MIN_int32_T;

    /* Divide by zero handler */
  } else {
    absNumerator = (uint32_T)(numerator >= 0 ? numerator : -numerator);
    absDenominator = (uint32_T)(denominator >= 0 ? denominator : -denominator);
    quotientNeedsNegation = ((numerator < 0) != (denominator < 0));
    tempAbsQuotient = absNumerator / absDenominator;
    if (quotientNeedsNegation) {
      absNumerator %= absDenominator;
      if (absNumerator > 0U) {
        tempAbsQuotient++;
      }
    }

    quotient = quotientNeedsNegation ? -(int32_T)tempAbsQuotient : (int32_T)
      tempAbsQuotient;
  }

  return quotient;
}

/*
 *   This function updates active task flag for each subrate.
 * The function is called at model base rate, hence the
 * generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (RaspPiPilot_M->Timing.TaskCounters.TID[1])++;
  if ((RaspPiPilot_M->Timing.TaskCounters.TID[1]) > 5) {/* Sample time: [0.06s, 0.0s] */
    RaspPiPilot_M->Timing.TaskCounters.TID[1] = 0;
  }

  (RaspPiPilot_M->Timing.TaskCounters.TID[2])++;
  if ((RaspPiPilot_M->Timing.TaskCounters.TID[2]) > 11) {/* Sample time: [0.12s, 0.0s] */
    RaspPiPilot_M->Timing.TaskCounters.TID[2] = 0;
  }
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* Function for Chart: '<Root>/Chart' */
static void RaspPiPilot_sendArmDisarmFun(real_T armdisarm, uint8_T data[256],
  uint8_T *length)
{
  real_T tmp;
  uint8_T tmp_0;

  /* MATLAB Function 'sendArmDisarmFun': '<S1>:26' */
  /* '<S1>:26:2' */
  memset(&data[0], 0, sizeof(uint8_T) << 8U);

  /* '<S1>:26:6' */
  tmp = rt_roundd_snf(armdisarm);
  if (tmp < 256.0) {
    if (tmp >= 0.0) {
      tmp_0 = (uint8_T)tmp;
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = MAX_uint8_T;
  }

  *length = sendArmDisarm(data, tmp_0);

  /* '<S1>:26:7' */
}

/* Function for Chart: '<Root>/Chart' */
static void RaspPiPilot_requestStreams(uint8_T data[256], uint8_T *length)
{
  /* MATLAB Function 'requestStreams': '<S1>:14' */
  /* '<S1>:14:2' */
  memset(&data[0], 0, sizeof(uint8_T) << 8U);

  /* '<S1>:14:6' */
  *length = requestAttitude(data);

  /* '<S1>:14:7' */
}

/* Function for Chart: '<Root>/Chart' */
static void RaspPiPilot_sendRPYT(real_T R, real_T P, real_T Y, real_T T, uint8_T
  data[256], uint8_T *length)
{
  real_T tmp;
  real_T tmp_0;
  real_T tmp_1;
  real_T tmp_2;
  uint16_T tmp_3;
  uint16_T tmp_4;
  uint16_T tmp_5;
  uint16_T tmp_6;

  /* MATLAB Function 'sendRPYT': '<S1>:37' */
  /* '<S1>:37:2' */
  memset(&data[0], 0, sizeof(uint8_T) << 8U);

  /* '<S1>:37:6' */
  tmp = rt_roundd_snf(R);
  tmp_0 = rt_roundd_snf(P);
  tmp_1 = rt_roundd_snf(Y);
  tmp_2 = rt_roundd_snf(T);
  if (tmp < 65536.0) {
    if (tmp >= 0.0) {
      tmp_3 = (uint16_T)tmp;
    } else {
      tmp_3 = 0U;
    }
  } else {
    tmp_3 = MAX_uint16_T;
  }

  if (tmp_0 < 65536.0) {
    if (tmp_0 >= 0.0) {
      tmp_4 = (uint16_T)tmp_0;
    } else {
      tmp_4 = 0U;
    }
  } else {
    tmp_4 = MAX_uint16_T;
  }

  if (tmp_1 < 65536.0) {
    if (tmp_1 >= 0.0) {
      tmp_5 = (uint16_T)tmp_1;
    } else {
      tmp_5 = 0U;
    }
  } else {
    tmp_5 = MAX_uint16_T;
  }

  if (tmp_2 < 65536.0) {
    if (tmp_2 >= 0.0) {
      tmp_6 = (uint16_T)tmp_2;
    } else {
      tmp_6 = 0U;
    }
  } else {
    tmp_6 = MAX_uint16_T;
  }

  *length = sendRPYT(data, tmp_3, tmp_4, tmp_5, tmp_6);

  /* '<S1>:37:8' */
}

/* Function for MATLAB Function: '<S13>/MATLAB Function2' */
static void RaspPiPilot_scalexpAlloc(const int32_T varargin_1_sizes[2], int32_T
  z_sizes[2])
{
  z_sizes[0] = (int16_T)varargin_1_sizes[0];
  z_sizes[1] = (int16_T)varargin_1_sizes[1];
}

/* Function for MATLAB Function: '<S14>/MATLAB Function1' */
static void RaspPiPilot_scalexpAlloc_i(const int32_T varargin_1_sizes[2],
  int32_T z_sizes[2])
{
  z_sizes[0] = (int16_T)varargin_1_sizes[0];
  z_sizes[1] = (int16_T)varargin_1_sizes[1];
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
        y = (rtNaN);
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

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  int32_T u0_0;
  int32_T u1_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      u0_0 = 1;
    } else {
      u0_0 = -1;
    }

    if (u1 > 0.0) {
      u1_0 = 1;
    } else {
      u1_0 = -1;
    }

    y = atan2(u0_0, u1_0);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

/* Model output function */
void RaspPiPilot_output(void)
{
  int8_T x[4];
  boolean_T exitg1;
  int32_T bytesRead;
  uint8_T dataRead[512];
  uint8_T data2[256];
  static const char_T b[13] = { '/', 'd', 'e', 'v', '/', 't', 't', 'y', 'A', 'M',
    'A', '0', '\x00' };

  int32_T lastCol;
  boolean_T visited2;
  boolean_T done;
  uint8_T tempD;
  real_T pitch;
  real_T y[240];
  int32_T ix;
  int32_T iy;
  int32_T itmp;
  real_T rtb_GeneratedFilterBlock;
  real_T rtb_TrigonometricFunction;
  real_T rtb_TmpSignalConversionAtDotPro[2];
  real_T rtb_c;
  real_T rtb_BlobAnalysis_o2[32];
  int32_T rtb_BlobAnalysis_o3[64];
  int32_T rtb_BlobAnalysis2_o1;
  int32_T rtb_DataTypeConversion[8];
  int32_T rtb_BlobAnalysis1_o1_h;
  int32_T rtb_BlobAnalysis1_o1;
  uint32_T BlobAnalysis1_NUM_PIX_DW_b;
  int32_T m;
  uint32_T padIdx;
  uint32_T BlobAnalysis1_NUM_PIX_DW;
  uint32_T BlobAnalysis2_NUM_PIX_DW;
  uint32_T numBlobs;
  int32_T pixListNinc;
  uint32_T BlobAnalysis_NUM_PIX_DW[16];
  int32_T pixListMinc;
  boolean_T maxNumBlobsReached;
  uint8_T currentLabel;
  uint32_T pixIdx;
  uint32_T start_pixIdx;
  uint32_T stackIdx;
  int32_T n;
  uint8_T rtb_data[512];
  char_T b_0[13];
  int32_T loop_ub;
  int32_T loop_ub_0;
  int32_T b_sizes[2];
  real_T rtb_Sum4_idx_1;
  real_T rtb_Sum2_idx_1;
  real_T rtb_Sum4_idx_0;
  real_T rtb_Sum2_idx_0;
  int32_T line_idx_3;
  int32_T line_idx_3_0;
  int32_T line_idx_0;
  int32_T rtb_TmpSignalConversionAtSele_0;

  /* Reset subsysRan breadcrumbs */
  srClearBC(RaspPiPilot_DW.FunctionCallSubsystem_SubsysRan);

  /* Reset subsysRan breadcrumbs */
  srClearBC(RaspPiPilot_DW.Navigation_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(RaspPiPilot_DW.attitudeParser_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(RaspPiPilot_DW.resultParser_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(RaspPiPilot_DW.statusParser_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(RaspPiPilot_DW.statusParser1_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(RaspPiPilot_DW.stringParser_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(RaspPiPilot_DW.messageParser_SubsysRanBC);

  /* RelationalOperator: '<S3>/Compare' incorporates:
   *  Constant: '<S3>/Constant'
   *  UnitDelay: '<Root>/Unit Delay'
   */
  RaspPiPilot_B.Compare = (RaspPiPilot_DW.UnitDelay_DSTATE !=
    RaspPiPilot_P.Constant_Value_o);

  /* DataTypeConversion: '<Root>/Data Type Conversion2' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  RaspPiPilot_B.DataTypeConversion2 = (RaspPiPilot_P.Constant1_Value_d != 0.0);

  /* DataTypeConversion: '<Root>/Data Type Conversion1' incorporates:
   *  Constant: '<Root>/Constant2'
   */
  RaspPiPilot_B.DataTypeConversion1_k = (RaspPiPilot_P.Constant2_Value != 0.0);

  /* Constant: '<Root>/Constant3' */
  RaspPiPilot_B.Constant3 = RaspPiPilot_P.Constant3_Value;

  /* Constant: '<Root>/Constant4' */
  RaspPiPilot_B.Constant4 = RaspPiPilot_P.Constant4_Value;

  /* Constant: '<Root>/Constant5' */
  RaspPiPilot_B.Constant5 = RaspPiPilot_P.Constant5_Value;

  /* Constant: '<Root>/Constant6' */
  RaspPiPilot_B.Constant6 = RaspPiPilot_P.Constant6_Value;

  /* RelationalOperator: '<S4>/Compare' incorporates:
   *  Constant: '<S4>/Constant'
   *  Memory: '<Root>/Memory'
   *  Sum: '<Root>/Subtract'
   */
  RaspPiPilot_B.Compare_c[0] = (RaspPiPilot_B.Constant3 -
    RaspPiPilot_DW.Memory_PreviousInput[0] != RaspPiPilot_P.Constant_Value_p);
  RaspPiPilot_B.Compare_c[1] = (RaspPiPilot_B.Constant4 -
    RaspPiPilot_DW.Memory_PreviousInput[1] != RaspPiPilot_P.Constant_Value_p);
  RaspPiPilot_B.Compare_c[2] = (RaspPiPilot_B.Constant5 -
    RaspPiPilot_DW.Memory_PreviousInput[2] != RaspPiPilot_P.Constant_Value_p);
  RaspPiPilot_B.Compare_c[3] = (RaspPiPilot_B.Constant6 -
    RaspPiPilot_DW.Memory_PreviousInput[3] != RaspPiPilot_P.Constant_Value_p);

  /* SignalConversion: '<S1>/TmpSignal ConversionAt SFunction Inport4' incorporates:
   *  Chart: '<Root>/Chart'
   */
  RaspPiPilot_B.TmpSignalConversionAtSFunctionI[0] = RaspPiPilot_B.Constant3;
  RaspPiPilot_B.TmpSignalConversionAtSFunctionI[1] = RaspPiPilot_B.Constant4;
  RaspPiPilot_B.TmpSignalConversionAtSFunctionI[2] = RaspPiPilot_B.Constant5;
  RaspPiPilot_B.TmpSignalConversionAtSFunctionI[3] = RaspPiPilot_B.Constant6;

  /* Chart: '<Root>/Chart' */
  if (RaspPiPilot_DW.temporalCounter_i1 < 511U) {
    RaspPiPilot_DW.temporalCounter_i1++;
  }

  /* Gateway: Chart */
  RaspPiPilot_DW.sfEvent = RaspPiPilot_CALL_EVENT;

  /* During: Chart */
  if (RaspPiPilot_DW.is_active_c5_RaspPiPilot == 0U) {
    /* Entry: Chart */
    RaspPiPilot_DW.is_active_c5_RaspPiPilot = 1U;

    /* Entry Internal: Chart */
    /* Transition: '<S1>:12' */
    RaspPiPilot_DW.is_c5_RaspPiPilot = RaspPiPilot_IN_Initializing;

    /* Entry 'Initializing': '<S1>:1' */
    RaspPiPilot_B.navOn = 0.0;
    RaspPiPilot_requestStreams(RaspPiPilot_B.dataOut, &currentLabel);
    RaspPiPilot_B.lengthOut = currentLabel;
  } else {
    switch (RaspPiPilot_DW.is_c5_RaspPiPilot) {
     case RaspPiPilot_IN_Armed:
      /* During 'Armed': '<S1>:3' */
      if (RaspPiPilot_B.DataTypeConversion1_k) {
        /* Transition: '<S1>:10' */
        /* Exit Internal 'Armed': '<S1>:3' */
        if (RaspPiPilot_DW.is_Armed == RaspPiPilot_IN_sendArm) {
          /* Exit 'sendArm': '<S1>:31' */
          RaspPiPilot_B.lengthOut = 0U;
          RaspPiPilot_DW.is_Armed = RaspPiPilot_IN_NO_ACTIVE_CHILD;
        } else {
          RaspPiPilot_DW.is_Armed = RaspPiPilot_IN_NO_ACTIVE_CHILD;
        }

        RaspPiPilot_DW.is_c5_RaspPiPilot = RaspPiPilot_IN_Disarmed;

        /* Entry Internal 'Disarmed': '<S1>:2' */
        /* Transition: '<S1>:22' */
        RaspPiPilot_DW.is_Disarmed = RaspPiPilot_IN_sendDisarm;
        RaspPiPilot_DW.temporalCounter_i1 = 0U;

        /* Entry 'sendDisarm': '<S1>:20' */
        RaspPiPilot_sendArmDisarmFun(0.0, RaspPiPilot_B.dataOut, &currentLabel);
        RaspPiPilot_B.lengthOut = currentLabel;
        RaspPiPilot_B.navOn = 0.0;
      } else if (RaspPiPilot_DW.is_Armed == RaspPiPilot_IN_Flying) {
        /* During 'Flying': '<S1>:4' */
        x[0] = (int8_T)(RaspPiPilot_B.Compare_c[0] - 1);
        x[1] = (int8_T)(RaspPiPilot_B.Compare_c[1] - 1);
        x[2] = (int8_T)(RaspPiPilot_B.Compare_c[2] - 1);
        x[3] = (int8_T)(RaspPiPilot_B.Compare_c[3] - 1);
        maxNumBlobsReached = true;
        m = 0;
        exitg1 = false;
        while ((!exitg1) && (m < 4)) {
          if (x[m] == 0) {
            maxNumBlobsReached = false;
            exitg1 = true;
          } else {
            m++;
          }
        }

        if (!maxNumBlobsReached) {
          RaspPiPilot_sendRPYT(RaspPiPilot_B.TmpSignalConversionAtSFunctionI[0],
                               RaspPiPilot_B.TmpSignalConversionAtSFunctionI[1],
                               RaspPiPilot_B.TmpSignalConversionAtSFunctionI[2],
                               RaspPiPilot_B.TmpSignalConversionAtSFunctionI[3],
                               RaspPiPilot_B.dataOut, &currentLabel);
          RaspPiPilot_B.lengthOut = currentLabel;
        }
      } else {
        /* During 'sendArm': '<S1>:31' */
        if (RaspPiPilot_DW.temporalCounter_i1 >= 500U) {
          /* Transition: '<S1>:32' */
          /* Exit 'sendArm': '<S1>:31' */
          RaspPiPilot_B.lengthOut = 0U;
          RaspPiPilot_DW.is_Armed = RaspPiPilot_IN_Flying;

          /* Entry 'Flying': '<S1>:4' */
          RaspPiPilot_B.navOn = 1.0;
          RaspPiPilot_requestStreams(RaspPiPilot_B.dataOut, &currentLabel);
          RaspPiPilot_B.lengthOut = currentLabel;
        }
      }
      break;

     case RaspPiPilot_IN_Disarmed:
      /* During 'Disarmed': '<S1>:2' */
      if (RaspPiPilot_B.DataTypeConversion2) {
        /* Transition: '<S1>:5' */
        /* Exit Internal 'Disarmed': '<S1>:2' */
        if (RaspPiPilot_DW.is_Disarmed == RaspPiPilot_IN_sendDisarm) {
          /* Exit 'sendDisarm': '<S1>:20' */
          RaspPiPilot_B.lengthOut = 0U;
          RaspPiPilot_DW.is_Disarmed = RaspPiPilot_IN_NO_ACTIVE_CHILD;
        } else {
          RaspPiPilot_DW.is_Disarmed = RaspPiPilot_IN_NO_ACTIVE_CHILD;
        }

        RaspPiPilot_DW.is_c5_RaspPiPilot = RaspPiPilot_IN_Armed;

        /* Entry Internal 'Armed': '<S1>:3' */
        /* Transition: '<S1>:33' */
        RaspPiPilot_DW.is_Armed = RaspPiPilot_IN_sendArm;
        RaspPiPilot_DW.temporalCounter_i1 = 0U;

        /* Entry 'sendArm': '<S1>:31' */
        /* [dataOut,lengthOut] = sendArmDisarmFun(1); */
      } else if ((RaspPiPilot_DW.is_Disarmed != RaspPiPilot_IN_idle) &&
                 (RaspPiPilot_DW.temporalCounter_i1 >= 100U)) {
        /* During 'sendDisarm': '<S1>:20' */
        /* Transition: '<S1>:23' */
        /* Exit 'sendDisarm': '<S1>:20' */
        RaspPiPilot_B.lengthOut = 0U;
        RaspPiPilot_DW.is_Disarmed = RaspPiPilot_IN_idle;
      } else {
        /* During 'idle': '<S1>:21' */
      }
      break;

     default:
      /* During 'Initializing': '<S1>:1' */
      if (RaspPiPilot_B.Compare) {
        /* Transition: '<S1>:6' */
        /* Exit 'Initializing': '<S1>:1' */
        RaspPiPilot_B.lengthOut = 0U;
        RaspPiPilot_DW.is_c5_RaspPiPilot = RaspPiPilot_IN_Disarmed;

        /* Entry Internal 'Disarmed': '<S1>:2' */
        /* Transition: '<S1>:22' */
        RaspPiPilot_DW.is_Disarmed = RaspPiPilot_IN_sendDisarm;
        RaspPiPilot_DW.temporalCounter_i1 = 0U;

        /* Entry 'sendDisarm': '<S1>:20' */
        RaspPiPilot_sendArmDisarmFun(0.0, RaspPiPilot_B.dataOut, &currentLabel);
        RaspPiPilot_B.lengthOut = currentLabel;
        RaspPiPilot_B.navOn = 0.0;
      }
      break;
    }
  }

  /* MATLAB Function: '<Root>/MATLAB Function' */
  currentLabel = RaspPiPilot_B.lengthOut;

  /* MATLAB Function 'MATLAB Function': '<S5>:1' */
  /* '<S5>:1:8' */
  /* '<S5>:1:3' */
  memset(&rtb_data[0], 0, sizeof(uint8_T) << 9U);

  /* '<S5>:1:4' */
  n = 0;
  if (!RaspPiPilot_DW.spHandle_not_empty) {
    /* '<S5>:1:6' */
    RaspPiPilot_DW.spHandle_not_empty = true;

    /* '<S5>:1:8' */
    for (line_idx_0 = 0; line_idx_0 < 13; line_idx_0++) {
      b_0[line_idx_0] = b[line_idx_0];
    }

    RaspPiPilot_DW.spHandle = setupSerialPort(b_0, 57600U);
  }

  if (RaspPiPilot_DW.spHandle > 0) {
    /* '<S5>:1:10' */
    /* '<S5>:1:12' */
    memset(&dataRead[0], 0, sizeof(uint8_T) << 9U);

    /* '<S5>:1:13' */
    bytesRead = read(RaspPiPilot_DW.spHandle, dataRead, 256U);
    if (bytesRead > 0) {
      /* '<S5>:1:14' */
      /* '<S5>:1:15' */
      memcpy(&rtb_data[0], &dataRead[0], sizeof(uint8_T) << 9U);

      /* '<S5>:1:16' */
      n = bytesRead;
    }

    if (currentLabel > 0) {
      /* '<S5>:1:18' */
      /* '<S5>:1:20' */
      memcpy(&data2[0], &RaspPiPilot_B.dataOut[0], sizeof(uint8_T) << 8U);
      write(RaspPiPilot_DW.spHandle, data2, (uint32_T)currentLabel);
    }
  }

  RaspPiPilot_B.length = n;

  /* End of MATLAB Function: '<Root>/MATLAB Function' */

  /* Outputs for Enabled SubSystem: '<Root>/messageParser' incorporates:
   *  EnablePort: '<S7>/Enable'
   */
  /* RelationalOperator: '<S2>/Compare' incorporates:
   *  Constant: '<S2>/Constant'
   *  Constant: '<S35>/Constant'
   *  Constant: '<S36>/Constant'
   *  Constant: '<S38>/Constant'
   *  Constant: '<S39>/Constant'
   *  RelationalOperator: '<S35>/Compare'
   *  RelationalOperator: '<S36>/Compare'
   *  RelationalOperator: '<S38>/Compare'
   *  RelationalOperator: '<S39>/Compare'
   */
  if (RaspPiPilot_B.length > RaspPiPilot_P.Constant_Value_d) {
    /* Outputs for Iterator SubSystem: '<S7>/While Iterator Subsystem' incorporates:
     *  WhileIterator: '<S33>/While Iterator'
     */
    bytesRead = 1;
    do {
      RaspPiPilot_B.WhileIterator = bytesRead;

      /* DataTypeConversion: '<S33>/Data Type Conversion' incorporates:
       *  Memory: '<S33>/Memory'
       */
      RaspPiPilot_B.DataTypeConversion_d = RaspPiPilot_DW.Memory_PreviousInput_c;

      /* MATLAB Function: '<S33>/MATLAB Function' */
      n = RaspPiPilot_B.length;
      iy = RaspPiPilot_B.DataTypeConversion_d;

      /* MATLAB Function 'messageParser/While Iterator Subsystem/MATLAB Function': '<S40>:1' */
      /* '<S40>:1:2' */
      currentLabel = 21U;

      /* '<S40>:1:3' */
      ix = 1;
      if (RaspPiPilot_B.WhileIterator == 1) {
        /* '<S40>:1:4' */
        /* '<S40>:1:5' */
        iy = 1;
      }

      /* '<S40>:1:8' */
      exitg1 = false;
      while ((!exitg1) && (iy <= n)) {
        /* '<S40>:1:8' */
        /* '<S40>:1:10' */
        tempD = parseMavlink(rtb_data[iy - 1]);
        if (tempD > 0) {
          /* '<S40>:1:11' */
          /* '<S40>:1:12' */
          currentLabel = getMessageId(iy, n);
          if (iy == n) {
            /* '<S40>:1:13' */
            /* '<S40>:1:14' */
            ix = iy;
          } else {
            /* '<S40>:1:16' */
            ix = iy + 1;
            if ((iy > 0) && (ix <= 0)) {
              ix = MAX_int32_T;
            }
          }

          exitg1 = true;
        } else {
          /* '<S40>:1:20' */
          ix = iy;

          /*  if itteration finishes without id trigger -  */
          iy++;
        }
      }

      RaspPiPilot_B.messageId = currentLabel;
      RaspPiPilot_B.id1 = ix;

      /* End of MATLAB Function: '<S33>/MATLAB Function' */

      /* RelationalOperator: '<S37>/Compare' incorporates:
       *  Constant: '<S37>/Constant'
       *  Sum: '<S33>/Subtract'
       */
      RaspPiPilot_B.Compare_j = (RaspPiPilot_B.length - RaspPiPilot_B.id1 >
        RaspPiPilot_P.CompareToConstant3_const);

      /* Outputs for Enabled SubSystem: '<S33>/resultParser' incorporates:
       *  EnablePort: '<S42>/Enable'
       */
      if (RaspPiPilot_B.messageId == RaspPiPilot_P.CompareToConstant1_const_p) {
        /* MATLAB Function: '<S42>/MATLAB Function1' */
        /* MATLAB Function 'messageParser/While Iterator Subsystem/resultParser/MATLAB Function1': '<S47>:1' */
        /* '<S47>:1:2' */
        currentLabel = 0U;
        getResult(&currentLabel);
        RaspPiPilot_B.result = currentLabel;
        RaspPiPilot_DW.resultParser_SubsysRanBC = 4;
      }

      /* End of Outputs for SubSystem: '<S33>/resultParser' */

      /* Outputs for Enabled SubSystem: '<S33>/statusParser' incorporates:
       *  EnablePort: '<S43>/Enable'
       */
      if (RaspPiPilot_B.messageId == RaspPiPilot_P.CompareToConstant4_const) {
        /* MATLAB Function: '<S43>/MATLAB Function1' */
        /* MATLAB Function 'messageParser/While Iterator Subsystem/statusParser/MATLAB Function1': '<S48>:1' */
        parseSysStatus();
        RaspPiPilot_DW.statusParser_SubsysRanBC = 4;
      }

      /* End of Outputs for SubSystem: '<S33>/statusParser' */

      /* Outputs for Enabled SubSystem: '<S33>/statusParser1' incorporates:
       *  EnablePort: '<S44>/Enable'
       */
      if (RaspPiPilot_B.messageId == RaspPiPilot_P.CompareToConstant5_const) {
        /* MATLAB Function: '<S44>/MATLAB Function1' */
        /* MATLAB Function 'messageParser/While Iterator Subsystem/statusParser1/MATLAB Function1': '<S49>:1' */
        parseHeartBeat();
        RaspPiPilot_DW.statusParser1_SubsysRanBC = 4;
      }

      /* End of Outputs for SubSystem: '<S33>/statusParser1' */

      /* Outputs for Enabled SubSystem: '<S33>/stringParser' incorporates:
       *  EnablePort: '<S45>/Enable'
       */
      if (RaspPiPilot_B.messageId == RaspPiPilot_P.CompareToConstant2_const_e) {
        /* MATLAB Function: '<S45>/MATLAB Function1' */
        /* MATLAB Function 'messageParser/While Iterator Subsystem/stringParser/MATLAB Function1': '<S50>:1' */
        getString();
        RaspPiPilot_DW.stringParser_SubsysRanBC = 4;
      }

      /* End of Outputs for SubSystem: '<S33>/stringParser' */

      /* RelationalOperator: '<S34>/Compare' incorporates:
       *  Constant: '<S34>/Constant'
       *  Constant: '<S35>/Constant'
       *  Constant: '<S36>/Constant'
       *  Constant: '<S38>/Constant'
       *  Constant: '<S39>/Constant'
       *  RelationalOperator: '<S35>/Compare'
       *  RelationalOperator: '<S36>/Compare'
       *  RelationalOperator: '<S38>/Compare'
       *  RelationalOperator: '<S39>/Compare'
       */
      RaspPiPilot_B.Compare_b = (RaspPiPilot_B.messageId ==
        RaspPiPilot_P.CompareToConstant_const_l);

      /* Outputs for Enabled SubSystem: '<S33>/attitudeParser' incorporates:
       *  EnablePort: '<S41>/Enable'
       */
      if (RaspPiPilot_B.Compare_b) {
        /* MATLAB Function: '<S41>/MATLAB Function1' */
        /* MATLAB Function 'messageParser/While Iterator Subsystem/attitudeParser/MATLAB Function1': '<S46>:1' */
        /* '<S46>:1:2' */
        rtb_c = 0.0;

        /* '<S46>:1:3' */
        pitch = 0.0;
        getRoll(&rtb_c);
        getPitch(&pitch);
        RaspPiPilot_B.roll = rtb_c;
        RaspPiPilot_B.pitch = pitch;
        RaspPiPilot_DW.attitudeParser_SubsysRanBC = 4;
      }

      /* End of Outputs for SubSystem: '<S33>/attitudeParser' */

      /* Update for Memory: '<S33>/Memory' */
      RaspPiPilot_DW.Memory_PreviousInput_c = RaspPiPilot_B.id1;
      bytesRead++;
    } while (RaspPiPilot_B.Compare_j && (bytesRead <= 100));

    /* End of Outputs for SubSystem: '<S7>/While Iterator Subsystem' */
    srUpdateBC(RaspPiPilot_DW.messageParser_SubsysRanBC);
  }

  /* End of RelationalOperator: '<S2>/Compare' */
  /* End of Outputs for SubSystem: '<Root>/messageParser' */

  /* Outputs for Enabled SubSystem: '<Root>/Navigation' incorporates:
   *  EnablePort: '<S6>/Enable'
   */
  if (RaspPiPilot_B.navOn > 0.0) {
    if (!RaspPiPilot_DW.Navigation_MODE) {
      RaspPiPilot_DW.Navigation_MODE = true;
    }

    if (RaspPiPilot_M->Timing.TaskCounters.TID[1] == 0) {
      /* S-Function (v4l2_video_capture_sfcn): '<S6>/V4L2 Video Capture' */
      MW_videoCaptureOutput(RaspPiPilot_ConstP.V4L2VideoCapture_p1,
                            RaspPiPilot_B.V4L2VideoCapture_o1,
                            RaspPiPilot_B.V4L2VideoCapture_o2,
                            RaspPiPilot_B.V4L2VideoCapture_o3);

      /* RateTransition: '<S6>/Rate Transition' */
      if (!(RaspPiPilot_DW.RateTransition_semaphoreTaken != 0)) {
        memcpy(&RaspPiPilot_DW.RateTransition_Buffer0[0],
               &RaspPiPilot_B.V4L2VideoCapture_o1[0], 76800U * sizeof(uint8_T));
      }
    }

    /* RateTransition: '<S6>/Rate Transition' */
    if (RaspPiPilot_M->Timing.TaskCounters.TID[2] == 0) {
      RaspPiPilot_DW.RateTransition_semaphoreTaken = 1;
      memcpy(&RaspPiPilot_B.RateTransition[0],
             &RaspPiPilot_DW.RateTransition_Buffer0[0], 76800U * sizeof(uint8_T));
      RaspPiPilot_DW.RateTransition_semaphoreTaken = 0;
    }

    /* RateTransition: '<S6>/Rate Transition1' */
    if ((RaspPiPilot_M->Timing.TaskCounters.TID[1] == 0) &&
        (!(RaspPiPilot_DW.RateTransition1_semaphoreTaken != 0))) {
      memcpy(&RaspPiPilot_DW.RateTransition1_Buffer0[0],
             &RaspPiPilot_B.V4L2VideoCapture_o2[0], 76800U * sizeof(uint8_T));
    }

    if (RaspPiPilot_M->Timing.TaskCounters.TID[2] == 0) {
      RaspPiPilot_DW.RateTransition1_semaphoreTaken = 1;
      memcpy(&RaspPiPilot_B.RateTransition1[0],
             &RaspPiPilot_DW.RateTransition1_Buffer0[0], 76800U * sizeof(uint8_T));
      RaspPiPilot_DW.RateTransition1_semaphoreTaken = 0;
    }

    /* End of RateTransition: '<S6>/Rate Transition1' */

    /* RateTransition: '<S6>/Rate Transition2' */
    if ((RaspPiPilot_M->Timing.TaskCounters.TID[1] == 0) &&
        (!(RaspPiPilot_DW.RateTransition2_semaphoreTaken != 0))) {
      memcpy(&RaspPiPilot_DW.RateTransition2_Buffer0[0],
             &RaspPiPilot_B.V4L2VideoCapture_o3[0], 76800U * sizeof(uint8_T));
    }

    if (RaspPiPilot_M->Timing.TaskCounters.TID[2] == 0) {
      RaspPiPilot_DW.RateTransition2_semaphoreTaken = 1;
      memcpy(&RaspPiPilot_B.RateTransition2[0],
             &RaspPiPilot_DW.RateTransition2_Buffer0[0], 76800U * sizeof(uint8_T));
      RaspPiPilot_DW.RateTransition2_semaphoreTaken = 0;
    }

    /* End of RateTransition: '<S6>/Rate Transition2' */

    /* Sum: '<S6>/Sum1' incorporates:
     *  Constant: '<S6>/Constant'
     */
    RaspPiPilot_B.Sum1 = RaspPiPilot_B.roll + RaspPiPilot_P.Constant_Value_k;

    /* DiscreteFir: '<S8>/Generated Filter Block' */
    /* Consume delay line and beginning of input samples */
    for (rtb_TmpSignalConversionAtSele_0 = 1; rtb_TmpSignalConversionAtSele_0 -
         1 < 1; rtb_TmpSignalConversionAtSele_0++) {
      rtb_c = 0.0;
      for (lastCol = 0; lastCol < rtb_TmpSignalConversionAtSele_0; lastCol++) {
        rtb_c += RaspPiPilot_B.Sum1 *
          RaspPiPilot_P.GeneratedFilterBlock_Coeffic_he[lastCol];
      }

      for (lastCol = 0; lastCol < 12 - rtb_TmpSignalConversionAtSele_0; lastCol
           ++) {
        rtb_c +=
          RaspPiPilot_P.GeneratedFilterBlock_Coeffic_he[rtb_TmpSignalConversionAtSele_0
          + lastCol] * RaspPiPilot_DW.GeneratedFilterBlock_states[lastCol];
      }

      RaspPiPilot_B.GeneratedFilterBlock = rtb_c;
    }

    /* Update delay line for next frame */
    for (rtb_TmpSignalConversionAtSele_0 = 9; rtb_TmpSignalConversionAtSele_0 >=
         0; rtb_TmpSignalConversionAtSele_0--) {
      RaspPiPilot_DW.GeneratedFilterBlock_states[1 +
        rtb_TmpSignalConversionAtSele_0] =
        RaspPiPilot_DW.GeneratedFilterBlock_states[rtb_TmpSignalConversionAtSele_0];
    }

    for (rtb_TmpSignalConversionAtSele_0 = 1; rtb_TmpSignalConversionAtSele_0 -
         1 < 1; rtb_TmpSignalConversionAtSele_0++) {
      RaspPiPilot_DW.GeneratedFilterBlock_states[1 -
        rtb_TmpSignalConversionAtSele_0] = RaspPiPilot_B.Sum1;
    }

    /* End of DiscreteFir: '<S8>/Generated Filter Block' */

    /* DiscreteFir: '<S9>/Generated Filter Block' */
    /* Consume delay line and beginning of input samples */
    for (rtb_TmpSignalConversionAtSele_0 = 1; rtb_TmpSignalConversionAtSele_0 -
         1 < 1; rtb_TmpSignalConversionAtSele_0++) {
      rtb_c = 0.0;
      for (lastCol = 0; lastCol < rtb_TmpSignalConversionAtSele_0; lastCol++) {
        rtb_c += RaspPiPilot_B.pitch *
          RaspPiPilot_P.GeneratedFilterBlock_Coeffici_i[lastCol];
      }

      for (lastCol = 0; lastCol < 12 - rtb_TmpSignalConversionAtSele_0; lastCol
           ++) {
        rtb_c +=
          RaspPiPilot_P.GeneratedFilterBlock_Coeffici_i[rtb_TmpSignalConversionAtSele_0
          + lastCol] * RaspPiPilot_DW.GeneratedFilterBlock_states_g[lastCol];
      }

      RaspPiPilot_B.GeneratedFilterBlock_o = rtb_c;
    }

    /* Update delay line for next frame */
    for (rtb_TmpSignalConversionAtSele_0 = 9; rtb_TmpSignalConversionAtSele_0 >=
         0; rtb_TmpSignalConversionAtSele_0--) {
      RaspPiPilot_DW.GeneratedFilterBlock_states_g[1 +
        rtb_TmpSignalConversionAtSele_0] =
        RaspPiPilot_DW.GeneratedFilterBlock_states_g[rtb_TmpSignalConversionAtSele_0];
    }

    for (rtb_TmpSignalConversionAtSele_0 = 1; rtb_TmpSignalConversionAtSele_0 -
         1 < 1; rtb_TmpSignalConversionAtSele_0++) {
      RaspPiPilot_DW.GeneratedFilterBlock_states_g[1 -
        rtb_TmpSignalConversionAtSele_0] = RaspPiPilot_B.pitch;
    }

    /* End of DiscreteFir: '<S9>/Generated Filter Block' */
    if (RaspPiPilot_M->Timing.TaskCounters.TID[2] == 0) {
      /* S-Function (fcncallgen): '<S6>/Function-Call Generator' incorporates:
       *  SubSystem: '<S6>/Function-Call Subsystem'
       */
      /* MATLAB Function: '<S10>/MATLAB Function' */
      /* MATLAB Function 'Navigation/Function-Call Subsystem/MATLAB Function': '<S18>:1' */
      /* '<S18>:1:3' */
      for (line_idx_0 = 0; line_idx_0 < 76800; line_idx_0++) {
        line_idx_3 = (int32_T)((uint32_T)RaspPiPilot_B.RateTransition[line_idx_0]
          + RaspPiPilot_B.RateTransition1[line_idx_0]);
        if ((uint32_T)line_idx_3 > 255U) {
          line_idx_3 = 255;
        }

        line_idx_3 = (int32_T)((uint32_T)line_idx_3 +
          RaspPiPilot_B.RateTransition2[line_idx_0]);
        if ((uint32_T)line_idx_3 > 255U) {
          line_idx_3 = 255;
        }

        RaspPiPilot_B.blueIntensity[line_idx_0] = (uint8_T)line_idx_3;
      }

      ix = -1;
      iy = -1;
      for (rtb_TmpSignalConversionAtSele_0 = 0; rtb_TmpSignalConversionAtSele_0 <
           240; rtb_TmpSignalConversionAtSele_0++) {
        bytesRead = ix + 1;
        ix++;
        rtb_c = RaspPiPilot_B.blueIntensity[bytesRead];
        for (m = 0; m < 319; m++) {
          ix++;
          rtb_c += (real_T)RaspPiPilot_B.blueIntensity[ix];
        }

        iy++;
        y[iy] = rtb_c;
      }

      for (line_idx_0 = 0; line_idx_0 < 240; line_idx_0++) {
        y[line_idx_0] /= 320.0;
      }

      rtb_c = y[0];
      for (bytesRead = 0; bytesRead < 239; bytesRead++) {
        rtb_c += y[bytesRead + 1];
      }

      RaspPiPilot_B.avgIntensity = rtb_c / 240.0;

      /* '<S18>:1:4' */
      for (bytesRead = 0; bytesRead < 76800; bytesRead++) {
        /* MATLAB Function: '<S10>/MATLAB Function' */
        start_pixIdx = (uint32_T)RaspPiPilot_B.RateTransition2[bytesRead] -
          (uint8_T)(int32_T)rt_roundd_snf((real_T)
          RaspPiPilot_B.RateTransition[bytesRead] / 2.0);
        if (start_pixIdx > RaspPiPilot_B.RateTransition2[bytesRead]) {
          start_pixIdx = 0U;
        }

        stackIdx = start_pixIdx - (uint8_T)(int32_T)rt_roundd_snf((real_T)
          RaspPiPilot_B.RateTransition1[bytesRead] / 2.0);
        if (stackIdx > start_pixIdx) {
          stackIdx = 0U;
        }

        /* RelationalOperator: '<S12>/Compare' incorporates:
         *  Constant: '<S12>/Constant'
         *  MATLAB Function: '<S10>/MATLAB Function'
         */
        RaspPiPilot_B.Compare_j4[bytesRead] = ((uint8_T)stackIdx >
          RaspPiPilot_P.CompareToConstant_const);

        /* MATLAB Function: '<S10>/MATLAB Function' */
        RaspPiPilot_B.blueIntensity[bytesRead] = (uint8_T)stackIdx;
      }

      /* S-Function (svipblob): '<S19>/Blob Analysis' */
      maxNumBlobsReached = false;
      memset(&RaspPiPilot_DW.BlobAnalysis_PAD_DW[0], 0, 323U * sizeof(uint8_T));
      currentLabel = 1U;
      rtb_TmpSignalConversionAtSele_0 = 0;
      iy = 323;
      for (n = 0; n < 240; n++) {
        for (m = 0; m < 320; m++) {
          RaspPiPilot_DW.BlobAnalysis_PAD_DW[iy] = (uint8_T)
            (RaspPiPilot_B.Compare_j4[rtb_TmpSignalConversionAtSele_0] ? 255 : 0);
          rtb_TmpSignalConversionAtSele_0++;
          iy++;
        }

        RaspPiPilot_DW.BlobAnalysis_PAD_DW[iy] = 0U;
        RaspPiPilot_DW.BlobAnalysis_PAD_DW[iy + 1] = 0U;
        iy += 2;
      }

      memset(&RaspPiPilot_DW.BlobAnalysis_PAD_DW[iy], 0, 321U * sizeof(uint8_T));
      bytesRead = 1;
      stackIdx = 0U;
      for (n = 0; n < 2; n++) {
        iy = 1;
        ix = bytesRead * 322;
        for (m = 0; m < 320; m++) {
          padIdx = (uint32_T)(ix + iy);
          if (RaspPiPilot_DW.BlobAnalysis_PAD_DW[padIdx] == 255) {
            RaspPiPilot_DW.BlobAnalysis_PAD_DW[padIdx] = 0U;
            RaspPiPilot_DW.BlobAnalysis_STACK_DW[0U] = padIdx;
            stackIdx = 1U;
          }

          while (stackIdx != 0U) {
            stackIdx--;
            numBlobs = RaspPiPilot_DW.BlobAnalysis_STACK_DW[stackIdx];
            for (rtb_TmpSignalConversionAtSele_0 = 0;
                 rtb_TmpSignalConversionAtSele_0 < 8;
                 rtb_TmpSignalConversionAtSele_0++) {
              padIdx = numBlobs +
                RaspPiPilot_ConstP.BlobAnalysis_WALKER_R[rtb_TmpSignalConversionAtSele_0];
              if (RaspPiPilot_DW.BlobAnalysis_PAD_DW[padIdx] == 255) {
                RaspPiPilot_DW.BlobAnalysis_PAD_DW[padIdx] = 0U;
                RaspPiPilot_DW.BlobAnalysis_STACK_DW[stackIdx] = padIdx;
                stackIdx++;
              }
            }
          }

          iy++;
        }

        bytesRead += 239;
      }

      bytesRead = 2;
      for (n = 0; n < 238; n++) {
        iy = 1;
        ix = bytesRead * 322;
        for (m = 0; m < 2; m++) {
          padIdx = (uint32_T)(ix + iy);
          if (RaspPiPilot_DW.BlobAnalysis_PAD_DW[padIdx] == 255) {
            RaspPiPilot_DW.BlobAnalysis_PAD_DW[padIdx] = 0U;
            RaspPiPilot_DW.BlobAnalysis_STACK_DW[0U] = padIdx;
            stackIdx = 1U;
          }

          while (stackIdx != 0U) {
            stackIdx--;
            numBlobs = RaspPiPilot_DW.BlobAnalysis_STACK_DW[stackIdx];
            for (rtb_TmpSignalConversionAtSele_0 = 0;
                 rtb_TmpSignalConversionAtSele_0 < 8;
                 rtb_TmpSignalConversionAtSele_0++) {
              padIdx = numBlobs +
                RaspPiPilot_ConstP.BlobAnalysis_WALKER_R[rtb_TmpSignalConversionAtSele_0];
              if (RaspPiPilot_DW.BlobAnalysis_PAD_DW[padIdx] == 255) {
                RaspPiPilot_DW.BlobAnalysis_PAD_DW[padIdx] = 0U;
                RaspPiPilot_DW.BlobAnalysis_STACK_DW[stackIdx] = padIdx;
                stackIdx++;
              }
            }
          }

          iy += 319;
        }

        bytesRead++;
      }

      bytesRead = 1;
      pixIdx = 0U;
      n = 0;
      while (n < 238) {
        iy = 1;
        ix = (bytesRead + 1) * 322;
        m = 0;
        while (m < 318) {
          padIdx = (uint32_T)((ix + iy) + 1);
          start_pixIdx = pixIdx;
          if (RaspPiPilot_DW.BlobAnalysis_PAD_DW[padIdx] == 255) {
            RaspPiPilot_DW.BlobAnalysis_PAD_DW[padIdx] = currentLabel;
            RaspPiPilot_DW.BlobAnalysis_N_PIXLIST_DW[pixIdx] = (int16_T)
              bytesRead;
            RaspPiPilot_DW.BlobAnalysis_M_PIXLIST_DW[pixIdx] = (int16_T)iy;
            pixIdx++;
            BlobAnalysis_NUM_PIX_DW[currentLabel - 1] = 1U;
            RaspPiPilot_DW.BlobAnalysis_STACK_DW[0U] = padIdx;
            stackIdx = 1U;
            while (stackIdx != 0U) {
              stackIdx--;
              numBlobs = RaspPiPilot_DW.BlobAnalysis_STACK_DW[stackIdx];
              for (rtb_TmpSignalConversionAtSele_0 = 0;
                   rtb_TmpSignalConversionAtSele_0 < 8;
                   rtb_TmpSignalConversionAtSele_0++) {
                padIdx = numBlobs +
                  RaspPiPilot_ConstP.BlobAnalysis_WALKER_R[rtb_TmpSignalConversionAtSele_0];
                if (RaspPiPilot_DW.BlobAnalysis_PAD_DW[padIdx] == 255) {
                  RaspPiPilot_DW.BlobAnalysis_PAD_DW[padIdx] = currentLabel;
                  RaspPiPilot_DW.BlobAnalysis_N_PIXLIST_DW[pixIdx] = (int16_T)
                    ((int16_T)(padIdx / 322U) - 1);
                  RaspPiPilot_DW.BlobAnalysis_M_PIXLIST_DW[pixIdx] = (int16_T)
                    (padIdx % 322U - 1U);
                  pixIdx++;
                  BlobAnalysis_NUM_PIX_DW[currentLabel - 1]++;
                  RaspPiPilot_DW.BlobAnalysis_STACK_DW[stackIdx] = padIdx;
                  stackIdx++;
                }
              }
            }

            if (BlobAnalysis_NUM_PIX_DW[currentLabel - 1] <
                RaspPiPilot_P.BlobAnalysis_minArea) {
              currentLabel--;
              pixIdx = start_pixIdx;
            }

            if (currentLabel == 16) {
              maxNumBlobsReached = true;
              n = 238;
              m = 318;
            }

            if (m < 318) {
              currentLabel++;
            }
          }

          iy++;
          m++;
        }

        bytesRead++;
        n++;
      }

      numBlobs = (uint32_T)(maxNumBlobsReached ? (int32_T)currentLabel :
                            (int32_T)(uint8_T)(currentLabel - 1U));
      pixListMinc = 0;
      pixListNinc = 0;
      for (rtb_TmpSignalConversionAtSele_0 = 0; rtb_TmpSignalConversionAtSele_0 <
           (int32_T)numBlobs; rtb_TmpSignalConversionAtSele_0++) {
        RaspPiPilot_B.BlobAnalysis_o1[rtb_TmpSignalConversionAtSele_0] =
          (int32_T)BlobAnalysis_NUM_PIX_DW[rtb_TmpSignalConversionAtSele_0];
        bytesRead = 0;
        n = 0;
        for (lastCol = 0; lastCol < (int32_T)
             BlobAnalysis_NUM_PIX_DW[rtb_TmpSignalConversionAtSele_0]; lastCol++)
        {
          bytesRead += RaspPiPilot_DW.BlobAnalysis_N_PIXLIST_DW[lastCol +
            pixListNinc];
          n += RaspPiPilot_DW.BlobAnalysis_M_PIXLIST_DW[lastCol + pixListMinc];
        }

        rtb_BlobAnalysis_o2[rtb_TmpSignalConversionAtSele_0] = (real_T)bytesRead
          / (real_T)BlobAnalysis_NUM_PIX_DW[rtb_TmpSignalConversionAtSele_0] +
          1.0;
        rtb_BlobAnalysis_o2[16U + rtb_TmpSignalConversionAtSele_0] = (real_T)n /
          (real_T)BlobAnalysis_NUM_PIX_DW[rtb_TmpSignalConversionAtSele_0] + 1.0;
        iy = 240;
        ix = 320;
        n = 0;
        m = 0;
        for (lastCol = 0; lastCol < (int32_T)
             BlobAnalysis_NUM_PIX_DW[rtb_TmpSignalConversionAtSele_0]; lastCol++)
        {
          bytesRead = lastCol + pixListNinc;
          if (RaspPiPilot_DW.BlobAnalysis_N_PIXLIST_DW[bytesRead] < iy) {
            iy = RaspPiPilot_DW.BlobAnalysis_N_PIXLIST_DW[bytesRead];
          }

          if (RaspPiPilot_DW.BlobAnalysis_N_PIXLIST_DW[bytesRead] > n) {
            n = RaspPiPilot_DW.BlobAnalysis_N_PIXLIST_DW[bytesRead];
          }

          bytesRead = lastCol + pixListMinc;
          if (RaspPiPilot_DW.BlobAnalysis_M_PIXLIST_DW[bytesRead] < ix) {
            ix = RaspPiPilot_DW.BlobAnalysis_M_PIXLIST_DW[bytesRead];
          }

          if (RaspPiPilot_DW.BlobAnalysis_M_PIXLIST_DW[bytesRead] > m) {
            m = RaspPiPilot_DW.BlobAnalysis_M_PIXLIST_DW[bytesRead];
          }
        }

        rtb_BlobAnalysis_o3[rtb_TmpSignalConversionAtSele_0] = iy + 1;
        rtb_BlobAnalysis_o3[16U + rtb_TmpSignalConversionAtSele_0] = ix + 1;
        rtb_BlobAnalysis_o3[32 + rtb_TmpSignalConversionAtSele_0] = (n - iy) + 1;
        rtb_BlobAnalysis_o3[48 + rtb_TmpSignalConversionAtSele_0] = (m - ix) + 1;
        pixListMinc += (int32_T)
          BlobAnalysis_NUM_PIX_DW[rtb_TmpSignalConversionAtSele_0];
        pixListNinc += (int32_T)
          BlobAnalysis_NUM_PIX_DW[rtb_TmpSignalConversionAtSele_0];
      }

      for (m = (int32_T)numBlobs; m < 16; m++) {
        RaspPiPilot_B.BlobAnalysis_o1[m] = -1;
      }

      for (m = (int32_T)numBlobs; m < 16; m++) {
        rtb_BlobAnalysis_o2[m] = -1.0;
      }

      for (m = 16 + (int32_T)numBlobs; m < 32; m++) {
        rtb_BlobAnalysis_o2[m] = -1.0;
      }

      for (m = (int32_T)numBlobs; m < 16; m++) {
        rtb_BlobAnalysis_o3[m] = -1;
      }

      for (m = 16 + (int32_T)numBlobs; m < 32; m++) {
        rtb_BlobAnalysis_o3[m] = -1;
      }

      for (m = 32 + (int32_T)numBlobs; m < 48; m++) {
        rtb_BlobAnalysis_o3[m] = -1;
      }

      for (m = 48 + (int32_T)numBlobs; m < 64; m++) {
        rtb_BlobAnalysis_o3[m] = -1;
      }

      /* End of S-Function (svipblob): '<S19>/Blob Analysis' */

      /* MATLAB Function: '<S19>/MATLAB Function' */
      /* MATLAB Function 'Navigation/Function-Call Subsystem/Subsystem/MATLAB Function': '<S28>:1' */
      bytesRead = RaspPiPilot_B.BlobAnalysis_o1[0];
      itmp = 0;
      for (ix = 0; ix < 15; ix++) {
        if (RaspPiPilot_B.BlobAnalysis_o1[ix + 1] > bytesRead) {
          bytesRead = RaspPiPilot_B.BlobAnalysis_o1[ix + 1];
          itmp = ix + 1;
        }
      }

      /* '<S28>:1:5' */
      RaspPiPilot_B.bbox_largest[0] = rtb_BlobAnalysis_o3[itmp];
      RaspPiPilot_B.bbox_largest[1] = rtb_BlobAnalysis_o3[itmp + 16];
      RaspPiPilot_B.bbox_largest[2] = rtb_BlobAnalysis_o3[itmp + 32];
      RaspPiPilot_B.bbox_largest[3] = rtb_BlobAnalysis_o3[itmp + 48];

      /* SignalConversion: '<S19>/TmpSignal ConversionAtSelector2Inport2' incorporates:
       *  Sum: '<S19>/Sum'
       */
      /* '<S28>:1:6' */
      rtb_TmpSignalConversionAtSele_0 = RaspPiPilot_B.bbox_largest[1] +
        RaspPiPilot_B.bbox_largest[3];

      /* Sum: '<S19>/Sum1' */
      rtb_BlobAnalysis2_o1 = RaspPiPilot_B.bbox_largest[0] +
        RaspPiPilot_B.bbox_largest[2];

      /* Selector: '<S19>/Selector2' incorporates:
       *  SignalConversion: '<S19>/TmpSignal ConversionAtSelector2Inport2'
       *  SignalConversion: '<S19>/TmpSignal ConversionAtSelector2Inport3'
       */
      RaspPiPilot_DW.Selector2_DIMS1[0] = (rtb_TmpSignalConversionAtSele_0 -
        RaspPiPilot_B.bbox_largest[1]) + 1;
      RaspPiPilot_DW.Selector2_DIMS1[1] = (rtb_BlobAnalysis2_o1 -
        RaspPiPilot_B.bbox_largest[0]) + 1;
      loop_ub = rtb_TmpSignalConversionAtSele_0 - RaspPiPilot_B.bbox_largest[1];
      loop_ub_0 = rtb_BlobAnalysis2_o1 - RaspPiPilot_B.bbox_largest[0];
      for (line_idx_0 = 0; line_idx_0 <= loop_ub_0; line_idx_0++) {
        for (line_idx_3 = 0; line_idx_3 <= loop_ub; line_idx_3++) {
          RaspPiPilot_B.Selector2[line_idx_3 + RaspPiPilot_DW.Selector2_DIMS1[0]
            * line_idx_0] = RaspPiPilot_B.RateTransition[((((line_idx_0 +
            RaspPiPilot_B.bbox_largest[0]) - 1) * 320 + line_idx_3) +
            RaspPiPilot_B.bbox_largest[1]) - 1];
        }
      }

      /* End of Selector: '<S19>/Selector2' */

      /* Selector: '<S19>/Selector3' incorporates:
       *  SignalConversion: '<S19>/TmpSignal ConversionAtSelector2Inport2'
       *  SignalConversion: '<S19>/TmpSignal ConversionAtSelector2Inport3'
       */
      RaspPiPilot_DW.Selector3_DIMS1[0] = (rtb_TmpSignalConversionAtSele_0 -
        RaspPiPilot_B.bbox_largest[1]) + 1;
      RaspPiPilot_DW.Selector3_DIMS1[1] = (rtb_BlobAnalysis2_o1 -
        RaspPiPilot_B.bbox_largest[0]) + 1;
      loop_ub = rtb_TmpSignalConversionAtSele_0 - RaspPiPilot_B.bbox_largest[1];
      loop_ub_0 = rtb_BlobAnalysis2_o1 - RaspPiPilot_B.bbox_largest[0];
      for (line_idx_0 = 0; line_idx_0 <= loop_ub_0; line_idx_0++) {
        for (line_idx_3 = 0; line_idx_3 <= loop_ub; line_idx_3++) {
          RaspPiPilot_B.Selector3[line_idx_3 + RaspPiPilot_DW.Selector3_DIMS1[0]
            * line_idx_0] = RaspPiPilot_B.RateTransition1[((((line_idx_0 +
            RaspPiPilot_B.bbox_largest[0]) - 1) * 320 + line_idx_3) +
            RaspPiPilot_B.bbox_largest[1]) - 1];
        }
      }

      /* End of Selector: '<S19>/Selector3' */

      /* Selector: '<S19>/Selector4' incorporates:
       *  SignalConversion: '<S19>/TmpSignal ConversionAtSelector2Inport2'
       *  SignalConversion: '<S19>/TmpSignal ConversionAtSelector2Inport3'
       */
      RaspPiPilot_DW.Selector4_DIMS1[0] = (rtb_TmpSignalConversionAtSele_0 -
        RaspPiPilot_B.bbox_largest[1]) + 1;
      RaspPiPilot_DW.Selector4_DIMS1[1] = (rtb_BlobAnalysis2_o1 -
        RaspPiPilot_B.bbox_largest[0]) + 1;
      loop_ub = rtb_TmpSignalConversionAtSele_0 - RaspPiPilot_B.bbox_largest[1];
      loop_ub_0 = rtb_BlobAnalysis2_o1 - RaspPiPilot_B.bbox_largest[0];
      for (line_idx_0 = 0; line_idx_0 <= loop_ub_0; line_idx_0++) {
        for (line_idx_3 = 0; line_idx_3 <= loop_ub; line_idx_3++) {
          RaspPiPilot_B.Selector4[line_idx_3 + RaspPiPilot_DW.Selector4_DIMS1[0]
            * line_idx_0] = RaspPiPilot_B.RateTransition2[((((line_idx_0 +
            RaspPiPilot_B.bbox_largest[0]) - 1) * 320 + line_idx_3) +
            RaspPiPilot_B.bbox_largest[1]) - 1];
        }
      }

      /* End of Selector: '<S19>/Selector4' */

      /* MATLAB Function: '<S13>/MATLAB Function2' */
      /* MATLAB Function 'Navigation/Function-Call Subsystem/Detect Green/MATLAB Function2': '<S23>:1' */
      RaspPiPilot_scalexpAlloc(RaspPiPilot_DW.Selector2_DIMS1, b_sizes);
      RaspPiPilot_DW.SFunction_DIMS2_d[0] = b_sizes[0];
      RaspPiPilot_DW.SFunction_DIMS2_d[1] = b_sizes[1];
      loop_ub = b_sizes[0] * b_sizes[1];
      for (line_idx_0 = 0; line_idx_0 < loop_ub; line_idx_0++) {
        RaspPiPilot_B.blueIntensity[line_idx_0] =
          RaspPiPilot_B.b_data[line_idx_0];
      }

      bytesRead = RaspPiPilot_DW.SFunction_DIMS2_d[0] *
        RaspPiPilot_DW.SFunction_DIMS2_d[1];
      for (m = 0; m < bytesRead; m++) {
        RaspPiPilot_B.blueIntensity[m] = (uint8_T)(int32_T)rt_roundd_snf((real_T)
          RaspPiPilot_B.Selector2[m] / 2.0);
      }

      RaspPiPilot_scalexpAlloc(RaspPiPilot_DW.Selector4_DIMS1, b_sizes);
      iy = b_sizes[0] * b_sizes[1];
      for (bytesRead = 0; bytesRead < iy; bytesRead++) {
        RaspPiPilot_B.b_data[bytesRead] = (uint8_T)(int32_T)rt_roundd_snf
          ((real_T)RaspPiPilot_B.Selector4[bytesRead] / 2.0);
      }

      /* '<S23>:1:4' */
      RaspPiPilot_DW.SFunction_DIMS2_d[0] = RaspPiPilot_DW.Selector3_DIMS1[0];
      RaspPiPilot_DW.SFunction_DIMS2_d[1] = RaspPiPilot_DW.Selector3_DIMS1[1];
      loop_ub = RaspPiPilot_DW.Selector3_DIMS1[0] *
        RaspPiPilot_DW.Selector3_DIMS1[1];
      for (line_idx_0 = 0; line_idx_0 < loop_ub; line_idx_0++) {
        start_pixIdx = (uint32_T)RaspPiPilot_B.Selector3[line_idx_0] -
          RaspPiPilot_B.blueIntensity[line_idx_0];
        if (start_pixIdx > RaspPiPilot_B.Selector3[line_idx_0]) {
          start_pixIdx = 0U;
        }

        stackIdx = start_pixIdx - RaspPiPilot_B.b_data[line_idx_0];
        if (stackIdx > start_pixIdx) {
          stackIdx = 0U;
        }

        RaspPiPilot_B.blueIntensity[line_idx_0] = (uint8_T)stackIdx;
      }

      /* End of MATLAB Function: '<S13>/MATLAB Function2' */

      /* RelationalOperator: '<S22>/Compare' incorporates:
       *  Constant: '<S22>/Constant'
       */
      loop_ub = RaspPiPilot_DW.SFunction_DIMS2_d[0] *
        RaspPiPilot_DW.SFunction_DIMS2_d[1];
      for (line_idx_0 = 0; line_idx_0 < loop_ub; line_idx_0++) {
        RaspPiPilot_B.Compare_j4[line_idx_0] =
          (RaspPiPilot_B.blueIntensity[line_idx_0] >
           RaspPiPilot_P.CompareToConstant2_const);
      }

      /* End of RelationalOperator: '<S22>/Compare' */

      /* S-Function (svipblob): '<S13>/Blob Analysis2' */
      pixListMinc = RaspPiPilot_DW.SFunction_DIMS2_d[0] + 2;
      RaspPiPilot_DW.BlobAnalysis2_WALKER_DW[0] = -1;
      RaspPiPilot_DW.BlobAnalysis2_WALKER_DW[1] = pixListMinc - 1;
      RaspPiPilot_DW.BlobAnalysis2_WALKER_DW[2] = pixListMinc;
      RaspPiPilot_DW.BlobAnalysis2_WALKER_DW[3] = pixListMinc + 1;
      RaspPiPilot_DW.BlobAnalysis2_WALKER_DW[4] = 1;
      RaspPiPilot_DW.BlobAnalysis2_WALKER_DW[5] = 1 - pixListMinc;
      RaspPiPilot_DW.BlobAnalysis2_WALKER_DW[6] = -pixListMinc;
      RaspPiPilot_DW.BlobAnalysis2_WALKER_DW[7] = -pixListMinc - 1;
      maxNumBlobsReached = false;
      for (bytesRead = 0; bytesRead < pixListMinc + 1; bytesRead++) {
        RaspPiPilot_DW.BlobAnalysis2_PAD_DW[bytesRead] = 0U;
      }

      currentLabel = 1U;
      rtb_TmpSignalConversionAtSele_0 = 0;
      iy = pixListMinc + 1;
      for (n = 0; n < RaspPiPilot_DW.SFunction_DIMS2_d[1]; n++) {
        for (m = 0; m < pixListMinc - 2; m++) {
          RaspPiPilot_DW.BlobAnalysis2_PAD_DW[iy] = (uint8_T)
            (RaspPiPilot_B.Compare_j4[rtb_TmpSignalConversionAtSele_0] ? 255 : 0);
          rtb_TmpSignalConversionAtSele_0++;
          iy++;
        }

        RaspPiPilot_DW.BlobAnalysis2_PAD_DW[iy] = 0U;
        RaspPiPilot_DW.BlobAnalysis2_PAD_DW[iy + 1] = 0U;
        iy += 2;
      }

      for (bytesRead = 0; bytesRead < pixListMinc - 1; bytesRead++) {
        RaspPiPilot_DW.BlobAnalysis2_PAD_DW[bytesRead + iy] = 0U;
      }

      bytesRead = 0;
      pixIdx = 0U;
      n = 0;
      while (n < RaspPiPilot_DW.SFunction_DIMS2_d[1]) {
        iy = 0;
        ix = (bytesRead + 1) * pixListMinc;
        m = 0;
        while (m < pixListMinc - 2) {
          padIdx = (uint32_T)((ix + iy) + 1);
          if (RaspPiPilot_DW.BlobAnalysis2_PAD_DW[padIdx] == 255) {
            RaspPiPilot_DW.BlobAnalysis2_PAD_DW[padIdx] = currentLabel;
            RaspPiPilot_DW.BlobAnalysis2_N_PIXLIST_DW[pixIdx] = (int16_T)
              bytesRead;
            RaspPiPilot_DW.BlobAnalysis2_M_PIXLIST_DW[pixIdx] = (int16_T)iy;
            pixIdx++;
            BlobAnalysis2_NUM_PIX_DW = 1U;
            RaspPiPilot_DW.BlobAnalysis2_STACK_DW[0U] = padIdx;
            stackIdx = 1U;
            while (stackIdx != 0U) {
              stackIdx--;
              numBlobs = RaspPiPilot_DW.BlobAnalysis2_STACK_DW[stackIdx];
              for (rtb_TmpSignalConversionAtSele_0 = 0;
                   rtb_TmpSignalConversionAtSele_0 < 8;
                   rtb_TmpSignalConversionAtSele_0++) {
                padIdx = numBlobs +
                  RaspPiPilot_DW.BlobAnalysis2_WALKER_DW[rtb_TmpSignalConversionAtSele_0];
                if (RaspPiPilot_DW.BlobAnalysis2_PAD_DW[padIdx] == 255) {
                  RaspPiPilot_DW.BlobAnalysis2_PAD_DW[padIdx] = currentLabel;
                  start_pixIdx = (uint32_T)pixListMinc;
                  RaspPiPilot_DW.BlobAnalysis2_N_PIXLIST_DW[pixIdx] = (int16_T)
                    ((int16_T)(start_pixIdx == 0U ? MAX_uint32_T : padIdx /
                               start_pixIdx) - 1);
                  RaspPiPilot_DW.BlobAnalysis2_M_PIXLIST_DW[pixIdx] = (int16_T)
                    (padIdx % pixListMinc - 1U);
                  pixIdx++;
                  BlobAnalysis2_NUM_PIX_DW++;
                  RaspPiPilot_DW.BlobAnalysis2_STACK_DW[stackIdx] = padIdx;
                  stackIdx++;
                }
              }
            }

            if (currentLabel == 1) {
              maxNumBlobsReached = true;
              n = RaspPiPilot_DW.SFunction_DIMS2_d[1];
              m = pixListMinc - 2;
            }

            if (m < pixListMinc - 2) {
              currentLabel++;
            }
          }

          iy++;
          m++;
        }

        bytesRead++;
        n++;
      }

      numBlobs = (uint32_T)(maxNumBlobsReached ? (int32_T)currentLabel :
                            (int32_T)(uint8_T)(currentLabel - 1U));
      pixListMinc = 0;
      pixListNinc = 0;
      for (rtb_TmpSignalConversionAtSele_0 = 0; rtb_TmpSignalConversionAtSele_0 <
           (int32_T)numBlobs; rtb_TmpSignalConversionAtSele_0++) {
        rtb_BlobAnalysis2_o1 = (int32_T)BlobAnalysis2_NUM_PIX_DW;
        bytesRead = 0;
        n = 0;
        for (lastCol = 0; lastCol < (int32_T)BlobAnalysis2_NUM_PIX_DW; lastCol++)
        {
          bytesRead += RaspPiPilot_DW.BlobAnalysis2_N_PIXLIST_DW[lastCol +
            pixListNinc];
          n += RaspPiPilot_DW.BlobAnalysis2_M_PIXLIST_DW[lastCol + pixListMinc];
        }

        rtb_TmpSignalConversionAtDotPro[rtb_TmpSignalConversionAtSele_0] =
          (real_T)bytesRead / (real_T)BlobAnalysis2_NUM_PIX_DW + 1.0;
        rtb_TmpSignalConversionAtDotPro[1U + rtb_TmpSignalConversionAtSele_0] =
          (real_T)n / (real_T)BlobAnalysis2_NUM_PIX_DW + 1.0;
        pixListMinc += (int32_T)BlobAnalysis2_NUM_PIX_DW;
        pixListNinc += (int32_T)BlobAnalysis2_NUM_PIX_DW;
      }

      for (m = (int32_T)numBlobs; m < 1; m++) {
        rtb_BlobAnalysis2_o1 = -1;
      }

      for (m = (int32_T)numBlobs; m < 1; m++) {
        rtb_TmpSignalConversionAtDotPro[m] = -1.0;
      }

      for (m = 1 + (int32_T)numBlobs; m < 2; m++) {
        rtb_TmpSignalConversionAtDotPro[m] = -1.0;
      }

      /* End of S-Function (svipblob): '<S13>/Blob Analysis2' */

      /* Sum: '<S10>/Sum3' */
      rtb_Sum4_idx_0 = (real_T)RaspPiPilot_B.bbox_largest[0] +
        rtb_TmpSignalConversionAtDotPro[0];
      rtb_Sum4_idx_1 = (real_T)RaspPiPilot_B.bbox_largest[1] +
        rtb_TmpSignalConversionAtDotPro[1];

      /* MATLAB Function: '<S14>/MATLAB Function1' */
      /* MATLAB Function 'Navigation/Function-Call Subsystem/Detect Red/MATLAB Function1': '<S25>:1' */
      RaspPiPilot_scalexpAlloc_i(RaspPiPilot_DW.Selector3_DIMS1, b_sizes);
      RaspPiPilot_DW.SFunction_DIMS2_k[0] = b_sizes[0];
      RaspPiPilot_DW.SFunction_DIMS2_k[1] = b_sizes[1];
      loop_ub = b_sizes[0] * b_sizes[1];
      for (line_idx_0 = 0; line_idx_0 < loop_ub; line_idx_0++) {
        RaspPiPilot_B.blueIntensity[line_idx_0] =
          RaspPiPilot_B.b_data[line_idx_0];
      }

      bytesRead = RaspPiPilot_DW.SFunction_DIMS2_k[0] *
        RaspPiPilot_DW.SFunction_DIMS2_k[1];
      for (m = 0; m < bytesRead; m++) {
        RaspPiPilot_B.blueIntensity[m] = (uint8_T)(int32_T)rt_roundd_snf((real_T)
          RaspPiPilot_B.Selector3[m] / 2.0);
      }

      RaspPiPilot_scalexpAlloc_i(RaspPiPilot_DW.Selector4_DIMS1, b_sizes);
      iy = b_sizes[0] * b_sizes[1];
      for (bytesRead = 0; bytesRead < iy; bytesRead++) {
        RaspPiPilot_B.b_data[bytesRead] = (uint8_T)(int32_T)rt_roundd_snf
          ((real_T)RaspPiPilot_B.Selector4[bytesRead] / 2.0);
      }

      /* '<S25>:1:3' */
      RaspPiPilot_DW.SFunction_DIMS2_k[0] = RaspPiPilot_DW.Selector2_DIMS1[0];
      RaspPiPilot_DW.SFunction_DIMS2_k[1] = RaspPiPilot_DW.Selector2_DIMS1[1];
      loop_ub = RaspPiPilot_DW.Selector2_DIMS1[0] *
        RaspPiPilot_DW.Selector2_DIMS1[1];
      for (line_idx_0 = 0; line_idx_0 < loop_ub; line_idx_0++) {
        start_pixIdx = (uint32_T)RaspPiPilot_B.Selector2[line_idx_0] -
          RaspPiPilot_B.blueIntensity[line_idx_0];
        if (start_pixIdx > RaspPiPilot_B.Selector2[line_idx_0]) {
          start_pixIdx = 0U;
        }

        stackIdx = start_pixIdx - RaspPiPilot_B.b_data[line_idx_0];
        if (stackIdx > start_pixIdx) {
          stackIdx = 0U;
        }

        RaspPiPilot_B.blueIntensity[line_idx_0] = (uint8_T)stackIdx;
      }

      /* End of MATLAB Function: '<S14>/MATLAB Function1' */

      /* RelationalOperator: '<S24>/Compare' incorporates:
       *  Constant: '<S24>/Constant'
       */
      loop_ub = RaspPiPilot_DW.SFunction_DIMS2_k[0] *
        RaspPiPilot_DW.SFunction_DIMS2_k[1];
      for (line_idx_0 = 0; line_idx_0 < loop_ub; line_idx_0++) {
        RaspPiPilot_B.Compare_j4[line_idx_0] =
          (RaspPiPilot_B.blueIntensity[line_idx_0] >
           RaspPiPilot_P.CompareToConstant1_const);
      }

      /* End of RelationalOperator: '<S24>/Compare' */

      /* S-Function (svipblob): '<S14>/Blob Analysis1' */
      pixListMinc = RaspPiPilot_DW.SFunction_DIMS2_k[0] + 2;
      RaspPiPilot_DW.BlobAnalysis1_WALKER_DW[0] = -1;
      RaspPiPilot_DW.BlobAnalysis1_WALKER_DW[1] = pixListMinc - 1;
      RaspPiPilot_DW.BlobAnalysis1_WALKER_DW[2] = pixListMinc;
      RaspPiPilot_DW.BlobAnalysis1_WALKER_DW[3] = pixListMinc + 1;
      RaspPiPilot_DW.BlobAnalysis1_WALKER_DW[4] = 1;
      RaspPiPilot_DW.BlobAnalysis1_WALKER_DW[5] = 1 - pixListMinc;
      RaspPiPilot_DW.BlobAnalysis1_WALKER_DW[6] = -pixListMinc;
      RaspPiPilot_DW.BlobAnalysis1_WALKER_DW[7] = -pixListMinc - 1;
      maxNumBlobsReached = false;
      for (bytesRead = 0; bytesRead < pixListMinc + 1; bytesRead++) {
        RaspPiPilot_DW.BlobAnalysis1_PAD_DW[bytesRead] = 0U;
      }

      currentLabel = 1U;
      rtb_TmpSignalConversionAtSele_0 = 0;
      iy = pixListMinc + 1;
      for (n = 0; n < RaspPiPilot_DW.SFunction_DIMS2_k[1]; n++) {
        for (m = 0; m < pixListMinc - 2; m++) {
          RaspPiPilot_DW.BlobAnalysis1_PAD_DW[iy] = (uint8_T)
            (RaspPiPilot_B.Compare_j4[rtb_TmpSignalConversionAtSele_0] ? 255 : 0);
          rtb_TmpSignalConversionAtSele_0++;
          iy++;
        }

        RaspPiPilot_DW.BlobAnalysis1_PAD_DW[iy] = 0U;
        RaspPiPilot_DW.BlobAnalysis1_PAD_DW[iy + 1] = 0U;
        iy += 2;
      }

      for (bytesRead = 0; bytesRead < pixListMinc - 1; bytesRead++) {
        RaspPiPilot_DW.BlobAnalysis1_PAD_DW[bytesRead + iy] = 0U;
      }

      bytesRead = 0;
      pixIdx = 0U;
      n = 0;
      while (n < RaspPiPilot_DW.SFunction_DIMS2_k[1]) {
        iy = 0;
        ix = (bytesRead + 1) * pixListMinc;
        m = 0;
        while (m < pixListMinc - 2) {
          padIdx = (uint32_T)((ix + iy) + 1);
          if (RaspPiPilot_DW.BlobAnalysis1_PAD_DW[padIdx] == 255) {
            RaspPiPilot_DW.BlobAnalysis1_PAD_DW[padIdx] = currentLabel;
            RaspPiPilot_DW.BlobAnalysis1_N_PIXLIST_DW[pixIdx] = (int16_T)
              bytesRead;
            RaspPiPilot_DW.BlobAnalysis1_M_PIXLIST_DW[pixIdx] = (int16_T)iy;
            pixIdx++;
            BlobAnalysis1_NUM_PIX_DW = 1U;
            RaspPiPilot_DW.BlobAnalysis1_STACK_DW[0U] = padIdx;
            stackIdx = 1U;
            while (stackIdx != 0U) {
              stackIdx--;
              numBlobs = RaspPiPilot_DW.BlobAnalysis1_STACK_DW[stackIdx];
              for (rtb_TmpSignalConversionAtSele_0 = 0;
                   rtb_TmpSignalConversionAtSele_0 < 8;
                   rtb_TmpSignalConversionAtSele_0++) {
                padIdx = numBlobs +
                  RaspPiPilot_DW.BlobAnalysis1_WALKER_DW[rtb_TmpSignalConversionAtSele_0];
                if (RaspPiPilot_DW.BlobAnalysis1_PAD_DW[padIdx] == 255) {
                  RaspPiPilot_DW.BlobAnalysis1_PAD_DW[padIdx] = currentLabel;
                  start_pixIdx = (uint32_T)pixListMinc;
                  RaspPiPilot_DW.BlobAnalysis1_N_PIXLIST_DW[pixIdx] = (int16_T)
                    ((int16_T)(start_pixIdx == 0U ? MAX_uint32_T : padIdx /
                               start_pixIdx) - 1);
                  RaspPiPilot_DW.BlobAnalysis1_M_PIXLIST_DW[pixIdx] = (int16_T)
                    (padIdx % pixListMinc - 1U);
                  pixIdx++;
                  BlobAnalysis1_NUM_PIX_DW++;
                  RaspPiPilot_DW.BlobAnalysis1_STACK_DW[stackIdx] = padIdx;
                  stackIdx++;
                }
              }
            }

            if (currentLabel == 1) {
              maxNumBlobsReached = true;
              n = RaspPiPilot_DW.SFunction_DIMS2_k[1];
              m = pixListMinc - 2;
            }

            if (m < pixListMinc - 2) {
              currentLabel++;
            }
          }

          iy++;
          m++;
        }

        bytesRead++;
        n++;
      }

      numBlobs = (uint32_T)(maxNumBlobsReached ? (int32_T)currentLabel :
                            (int32_T)(uint8_T)(currentLabel - 1U));
      pixListMinc = 0;
      pixListNinc = 0;
      for (rtb_TmpSignalConversionAtSele_0 = 0; rtb_TmpSignalConversionAtSele_0 <
           (int32_T)numBlobs; rtb_TmpSignalConversionAtSele_0++) {
        rtb_BlobAnalysis1_o1 = (int32_T)BlobAnalysis1_NUM_PIX_DW;
        bytesRead = 0;
        n = 0;
        for (lastCol = 0; lastCol < (int32_T)BlobAnalysis1_NUM_PIX_DW; lastCol++)
        {
          bytesRead += RaspPiPilot_DW.BlobAnalysis1_N_PIXLIST_DW[lastCol +
            pixListNinc];
          n += RaspPiPilot_DW.BlobAnalysis1_M_PIXLIST_DW[lastCol + pixListMinc];
        }

        rtb_TmpSignalConversionAtDotPro[rtb_TmpSignalConversionAtSele_0] =
          (real_T)bytesRead / (real_T)BlobAnalysis1_NUM_PIX_DW + 1.0;
        rtb_TmpSignalConversionAtDotPro[1U + rtb_TmpSignalConversionAtSele_0] =
          (real_T)n / (real_T)BlobAnalysis1_NUM_PIX_DW + 1.0;
        pixListMinc += (int32_T)BlobAnalysis1_NUM_PIX_DW;
        pixListNinc += (int32_T)BlobAnalysis1_NUM_PIX_DW;
      }

      for (m = (int32_T)numBlobs; m < 1; m++) {
        rtb_BlobAnalysis1_o1 = -1;
      }

      for (m = (int32_T)numBlobs; m < 1; m++) {
        rtb_TmpSignalConversionAtDotPro[m] = -1.0;
      }

      for (m = 1 + (int32_T)numBlobs; m < 2; m++) {
        rtb_TmpSignalConversionAtDotPro[m] = -1.0;
      }

      /* End of S-Function (svipblob): '<S14>/Blob Analysis1' */

      /* Sum: '<S10>/Sum2' */
      rtb_Sum2_idx_0 = (real_T)RaspPiPilot_B.bbox_largest[0] +
        rtb_TmpSignalConversionAtDotPro[0];
      rtb_Sum2_idx_1 = (real_T)RaspPiPilot_B.bbox_largest[1] +
        rtb_TmpSignalConversionAtDotPro[1];

      /* Bias: '<S10>/Subtract Image Centre' incorporates:
       *  Gain: '<S10>/Gain3'
       *  Sum: '<S10>/Sum1'
       */
      RaspPiPilot_B.SubtractImageCentre[0] = (rtb_Sum4_idx_0 + rtb_Sum2_idx_0) *
        RaspPiPilot_P.Gain3_Gain + RaspPiPilot_P.SubtractImageCentre_Bias[0];
      RaspPiPilot_B.SubtractImageCentre[1] = (rtb_Sum4_idx_1 + rtb_Sum2_idx_1) *
        RaspPiPilot_P.Gain3_Gain + RaspPiPilot_P.SubtractImageCentre_Bias[1];

      /* DiscreteFir: '<S16>/Generated Filter Block' */
      /* Consume delay line and beginning of input samples */
      for (rtb_TmpSignalConversionAtSele_0 = 1; rtb_TmpSignalConversionAtSele_0
           - 1 < 1; rtb_TmpSignalConversionAtSele_0++) {
        rtb_TrigonometricFunction = 0.0;
        for (lastCol = 0; lastCol < rtb_TmpSignalConversionAtSele_0; lastCol++)
        {
          rtb_TrigonometricFunction += RaspPiPilot_B.SubtractImageCentre[0] *
            RaspPiPilot_P.GeneratedFilterBlock_Coefficien[lastCol];
        }

        for (lastCol = 0; lastCol < 12 - rtb_TmpSignalConversionAtSele_0;
             lastCol++) {
          rtb_TrigonometricFunction +=
            RaspPiPilot_P.GeneratedFilterBlock_Coefficien[rtb_TmpSignalConversionAtSele_0
            + lastCol] * RaspPiPilot_DW.GeneratedFilterBlock_states_f[lastCol];
        }
      }

      /* Update delay line for next frame */
      for (rtb_TmpSignalConversionAtSele_0 = 9; rtb_TmpSignalConversionAtSele_0 >=
           0; rtb_TmpSignalConversionAtSele_0--) {
        RaspPiPilot_DW.GeneratedFilterBlock_states_f[1 +
          rtb_TmpSignalConversionAtSele_0] =
          RaspPiPilot_DW.GeneratedFilterBlock_states_f[rtb_TmpSignalConversionAtSele_0];
      }

      for (rtb_TmpSignalConversionAtSele_0 = 1; rtb_TmpSignalConversionAtSele_0
           - 1 < 1; rtb_TmpSignalConversionAtSele_0++) {
        RaspPiPilot_DW.GeneratedFilterBlock_states_f[1 -
          rtb_TmpSignalConversionAtSele_0] = RaspPiPilot_B.SubtractImageCentre[0];
      }

      /* End of DiscreteFir: '<S16>/Generated Filter Block' */

      /* DiscreteFir: '<S17>/Generated Filter Block' */
      /* Consume delay line and beginning of input samples */
      for (rtb_TmpSignalConversionAtSele_0 = 1; rtb_TmpSignalConversionAtSele_0
           - 1 < 1; rtb_TmpSignalConversionAtSele_0++) {
        rtb_GeneratedFilterBlock = 0.0;
        for (lastCol = 0; lastCol < rtb_TmpSignalConversionAtSele_0; lastCol++)
        {
          rtb_GeneratedFilterBlock += RaspPiPilot_B.SubtractImageCentre[1] *
            RaspPiPilot_P.GeneratedFilterBlock_Coeffici_a[lastCol];
        }

        for (lastCol = 0; lastCol < 12 - rtb_TmpSignalConversionAtSele_0;
             lastCol++) {
          rtb_GeneratedFilterBlock +=
            RaspPiPilot_P.GeneratedFilterBlock_Coeffici_a[rtb_TmpSignalConversionAtSele_0
            + lastCol] * RaspPiPilot_DW.GeneratedFilterBlock_states_m[lastCol];
        }
      }

      /* Update delay line for next frame */
      for (rtb_TmpSignalConversionAtSele_0 = 9; rtb_TmpSignalConversionAtSele_0 >=
           0; rtb_TmpSignalConversionAtSele_0--) {
        RaspPiPilot_DW.GeneratedFilterBlock_states_m[1 +
          rtb_TmpSignalConversionAtSele_0] =
          RaspPiPilot_DW.GeneratedFilterBlock_states_m[rtb_TmpSignalConversionAtSele_0];
      }

      for (rtb_TmpSignalConversionAtSele_0 = 1; rtb_TmpSignalConversionAtSele_0
           - 1 < 1; rtb_TmpSignalConversionAtSele_0++) {
        RaspPiPilot_DW.GeneratedFilterBlock_states_m[1 -
          rtb_TmpSignalConversionAtSele_0] = RaspPiPilot_B.SubtractImageCentre[1];
      }

      /* End of DiscreteFir: '<S17>/Generated Filter Block' */

      /* SignalConversion: '<S21>/TmpSignal ConversionAtDot ProductInport1' */
      rtb_TmpSignalConversionAtDotPro[1] = rtb_GeneratedFilterBlock;

      /* Gain: '<S10>/Convert pixels to degrees' incorporates:
       *  SignalConversion: '<S21>/TmpSignal ConversionAtDot ProductInport1'
       */
      RaspPiPilot_B.Convertpixelstodegrees[0] =
        RaspPiPilot_P.Convertpixelstodegrees_Gain * rtb_TrigonometricFunction;
      RaspPiPilot_B.Convertpixelstodegrees[1] =
        RaspPiPilot_P.Convertpixelstodegrees_Gain * rtb_GeneratedFilterBlock;

      /* MATLAB Function: '<S15>/MATLAB Function1' */
      /* MATLAB Function 'Navigation/Function-Call Subsystem/Detect yellow/MATLAB Function1': '<S27>:1' */
      /* '<S27>:1:3' */
      RaspPiPilot_DW.SFunction_DIMS2[0] = 320;
      RaspPiPilot_DW.SFunction_DIMS2[1] = 240;
      for (line_idx_0 = 0; line_idx_0 < 76800; line_idx_0++) {
        rtb_TmpSignalConversionAtSele_0 = (int32_T)((uint32_T)
          RaspPiPilot_B.RateTransition[line_idx_0] +
          RaspPiPilot_B.RateTransition1[line_idx_0]);
        if ((uint32_T)rtb_TmpSignalConversionAtSele_0 > 255U) {
          rtb_TmpSignalConversionAtSele_0 = 255;
        }

        if (RaspPiPilot_B.RateTransition2[line_idx_0] > 127) {
          currentLabel = MAX_uint8_T;
        } else {
          currentLabel = (uint8_T)(RaspPiPilot_B.RateTransition2[line_idx_0] <<
            1);
        }

        start_pixIdx = (uint32_T)rtb_TmpSignalConversionAtSele_0 - currentLabel;
        if (start_pixIdx > (uint32_T)rtb_TmpSignalConversionAtSele_0) {
          start_pixIdx = 0U;
        }

        RaspPiPilot_B.blueIntensity[line_idx_0] = (uint8_T)(int32_T)
          rt_roundd_snf((real_T)(uint8_T)start_pixIdx / 2.0);
      }

      /* End of MATLAB Function: '<S15>/MATLAB Function1' */

      /* RelationalOperator: '<S26>/Compare' incorporates:
       *  Constant: '<S26>/Constant'
       */
      loop_ub = RaspPiPilot_DW.SFunction_DIMS2[0] *
        RaspPiPilot_DW.SFunction_DIMS2[1];
      for (line_idx_0 = 0; line_idx_0 < loop_ub; line_idx_0++) {
        RaspPiPilot_B.Compare_j4[line_idx_0] =
          (RaspPiPilot_B.blueIntensity[line_idx_0] >
           RaspPiPilot_P.CompareToConstant1_const_l);
      }

      /* End of RelationalOperator: '<S26>/Compare' */

      /* S-Function (svipblob): '<S15>/Blob Analysis1' */
      pixListMinc = RaspPiPilot_DW.SFunction_DIMS2[0] + 2;
      RaspPiPilot_DW.BlobAnalysis1_WALKER_DW_b[0] = -1;
      RaspPiPilot_DW.BlobAnalysis1_WALKER_DW_b[1] = pixListMinc - 1;
      RaspPiPilot_DW.BlobAnalysis1_WALKER_DW_b[2] = pixListMinc;
      RaspPiPilot_DW.BlobAnalysis1_WALKER_DW_b[3] = pixListMinc + 1;
      RaspPiPilot_DW.BlobAnalysis1_WALKER_DW_b[4] = 1;
      RaspPiPilot_DW.BlobAnalysis1_WALKER_DW_b[5] = 1 - pixListMinc;
      RaspPiPilot_DW.BlobAnalysis1_WALKER_DW_b[6] = -pixListMinc;
      RaspPiPilot_DW.BlobAnalysis1_WALKER_DW_b[7] = -pixListMinc - 1;
      maxNumBlobsReached = false;
      for (bytesRead = 0; bytesRead < pixListMinc + 1; bytesRead++) {
        RaspPiPilot_DW.BlobAnalysis1_PAD_DW_f[bytesRead] = 0U;
      }

      currentLabel = 1U;
      rtb_TmpSignalConversionAtSele_0 = 0;
      iy = pixListMinc + 1;
      for (n = 0; n < RaspPiPilot_DW.SFunction_DIMS2[1]; n++) {
        for (m = 0; m < pixListMinc - 2; m++) {
          RaspPiPilot_DW.BlobAnalysis1_PAD_DW_f[iy] = (uint8_T)
            (RaspPiPilot_B.Compare_j4[rtb_TmpSignalConversionAtSele_0] ? 255 : 0);
          rtb_TmpSignalConversionAtSele_0++;
          iy++;
        }

        RaspPiPilot_DW.BlobAnalysis1_PAD_DW_f[iy] = 0U;
        RaspPiPilot_DW.BlobAnalysis1_PAD_DW_f[iy + 1] = 0U;
        iy += 2;
      }

      for (bytesRead = 0; bytesRead < pixListMinc - 1; bytesRead++) {
        RaspPiPilot_DW.BlobAnalysis1_PAD_DW_f[bytesRead + iy] = 0U;
      }

      bytesRead = 0;
      pixIdx = 0U;
      n = 0;
      while (n < RaspPiPilot_DW.SFunction_DIMS2[1]) {
        iy = 0;
        ix = (bytesRead + 1) * pixListMinc;
        m = 0;
        while (m < pixListMinc - 2) {
          padIdx = (uint32_T)((ix + iy) + 1);
          if (RaspPiPilot_DW.BlobAnalysis1_PAD_DW_f[padIdx] == 255) {
            RaspPiPilot_DW.BlobAnalysis1_PAD_DW_f[padIdx] = currentLabel;
            RaspPiPilot_DW.BlobAnalysis1_N_PIXLIST_DW_f[pixIdx] = (int16_T)
              bytesRead;
            RaspPiPilot_DW.BlobAnalysis1_M_PIXLIST_DW_o[pixIdx] = (int16_T)iy;
            pixIdx++;
            BlobAnalysis1_NUM_PIX_DW_b = 1U;
            RaspPiPilot_DW.BlobAnalysis1_STACK_DW_l[0U] = padIdx;
            stackIdx = 1U;
            while (stackIdx != 0U) {
              stackIdx--;
              numBlobs = RaspPiPilot_DW.BlobAnalysis1_STACK_DW_l[stackIdx];
              for (rtb_TmpSignalConversionAtSele_0 = 0;
                   rtb_TmpSignalConversionAtSele_0 < 8;
                   rtb_TmpSignalConversionAtSele_0++) {
                padIdx = numBlobs +
                  RaspPiPilot_DW.BlobAnalysis1_WALKER_DW_b[rtb_TmpSignalConversionAtSele_0];
                if (RaspPiPilot_DW.BlobAnalysis1_PAD_DW_f[padIdx] == 255) {
                  RaspPiPilot_DW.BlobAnalysis1_PAD_DW_f[padIdx] = currentLabel;
                  start_pixIdx = (uint32_T)pixListMinc;
                  RaspPiPilot_DW.BlobAnalysis1_N_PIXLIST_DW_f[pixIdx] = (int16_T)
                    ((int16_T)(start_pixIdx == 0U ? MAX_uint32_T : padIdx /
                               start_pixIdx) - 1);
                  RaspPiPilot_DW.BlobAnalysis1_M_PIXLIST_DW_o[pixIdx] = (int16_T)
                    (padIdx % pixListMinc - 1U);
                  pixIdx++;
                  BlobAnalysis1_NUM_PIX_DW_b++;
                  RaspPiPilot_DW.BlobAnalysis1_STACK_DW_l[stackIdx] = padIdx;
                  stackIdx++;
                }
              }
            }

            if (currentLabel == 1) {
              maxNumBlobsReached = true;
              n = RaspPiPilot_DW.SFunction_DIMS2[1];
              m = pixListMinc - 2;
            }

            if (m < pixListMinc - 2) {
              currentLabel++;
            }
          }

          iy++;
          m++;
        }

        bytesRead++;
        n++;
      }

      numBlobs = (uint32_T)(maxNumBlobsReached ? (int32_T)currentLabel :
                            (int32_T)(uint8_T)(currentLabel - 1U));
      pixListMinc = 0;
      pixListNinc = 0;
      for (rtb_TmpSignalConversionAtSele_0 = 0; rtb_TmpSignalConversionAtSele_0 <
           (int32_T)numBlobs; rtb_TmpSignalConversionAtSele_0++) {
        rtb_BlobAnalysis1_o1_h = (int32_T)BlobAnalysis1_NUM_PIX_DW_b;
        bytesRead = 0;
        n = 0;
        for (lastCol = 0; lastCol < (int32_T)BlobAnalysis1_NUM_PIX_DW_b; lastCol
             ++) {
          bytesRead += RaspPiPilot_DW.BlobAnalysis1_N_PIXLIST_DW_f[lastCol +
            pixListNinc];
          n += RaspPiPilot_DW.BlobAnalysis1_M_PIXLIST_DW_o[lastCol + pixListMinc];
        }

        RaspPiPilot_B.BlobAnalysis1_o2[rtb_TmpSignalConversionAtSele_0] =
          (real_T)bytesRead / (real_T)BlobAnalysis1_NUM_PIX_DW_b + 1.0;
        RaspPiPilot_B.BlobAnalysis1_o2[1U + rtb_TmpSignalConversionAtSele_0] =
          (real_T)n / (real_T)BlobAnalysis1_NUM_PIX_DW_b + 1.0;
        pixListMinc += (int32_T)BlobAnalysis1_NUM_PIX_DW_b;
        pixListNinc += (int32_T)BlobAnalysis1_NUM_PIX_DW_b;
      }

      for (m = (int32_T)numBlobs; m < 1; m++) {
        rtb_BlobAnalysis1_o1_h = -1;
      }

      for (m = (int32_T)numBlobs; m < 1; m++) {
        RaspPiPilot_B.BlobAnalysis1_o2[m] = -1.0;
      }

      for (m = 1 + (int32_T)numBlobs; m < 2; m++) {
        RaspPiPilot_B.BlobAnalysis1_o2[m] = -1.0;
      }

      /* End of S-Function (svipblob): '<S15>/Blob Analysis1' */

      /* Gain: '<S10>/Gain4' */
      RaspPiPilot_B.Gain4[0] = RaspPiPilot_P.Gain4_Gain *
        RaspPiPilot_B.Convertpixelstodegrees[0];
      RaspPiPilot_B.Gain4[1] = RaspPiPilot_P.Gain4_Gain *
        RaspPiPilot_B.Convertpixelstodegrees[1];

      /* MATLAB Function: '<S20>/MATLAB Function' */
      /* MATLAB Function 'Navigation/Function-Call Subsystem/attitudeFix/MATLAB Function': '<S29>:1' */
      /* '<S29>:1:2' */
      rtb_c = RaspPiPilot_B.GeneratedFilterBlock_o - RaspPiPilot_B.Gain4[0];
      pitch = RaspPiPilot_B.GeneratedFilterBlock - RaspPiPilot_B.Gain4[1];

      /* '<S29>:1:3' */
      rtb_c = 1.0 / cos(sqrt(rtb_c * rtb_c + pitch * pitch));

      /* Math: '<S20>/Math Function' incorporates:
       *  Constant: '<S20>/Constant'
       */
      if ((rtb_c < 0.0) && (RaspPiPilot_P.Constant_Value > floor
                            (RaspPiPilot_P.Constant_Value))) {
        RaspPiPilot_B.MathFunction = -rt_powd_snf(-rtb_c,
          RaspPiPilot_P.Constant_Value);
      } else {
        RaspPiPilot_B.MathFunction = rt_powd_snf(rtb_c,
          RaspPiPilot_P.Constant_Value);
      }

      /* End of Math: '<S20>/Math Function' */

      /* DataTypeConversion: '<S13>/Data Type Conversion1' */
      RaspPiPilot_B.DataTypeConversion1 = rtb_BlobAnalysis2_o1;

      /* Product: '<S20>/Product1' */
      RaspPiPilot_B.Product1 = RaspPiPilot_B.MathFunction *
        RaspPiPilot_B.DataTypeConversion1;

      /* DiscreteFir: '<S31>/Generated Filter Block' */
      /* Consume delay line and beginning of input samples */
      for (rtb_TmpSignalConversionAtSele_0 = 1; rtb_TmpSignalConversionAtSele_0
           - 1 < 1; rtb_TmpSignalConversionAtSele_0++) {
        rtb_GeneratedFilterBlock = 0.0;
        for (lastCol = 0; lastCol < rtb_TmpSignalConversionAtSele_0; lastCol++)
        {
          rtb_GeneratedFilterBlock += RaspPiPilot_B.Product1 *
            RaspPiPilot_P.GeneratedFilterBlock_Coeffici_h[lastCol];
        }

        for (lastCol = 0; lastCol < 14 - rtb_TmpSignalConversionAtSele_0;
             lastCol++) {
          rtb_GeneratedFilterBlock +=
            RaspPiPilot_P.GeneratedFilterBlock_Coeffici_h[rtb_TmpSignalConversionAtSele_0
            + lastCol] * RaspPiPilot_DW.GeneratedFilterBlock_states_l[lastCol];
        }
      }

      /* Update delay line for next frame */
      for (rtb_TmpSignalConversionAtSele_0 = 11; rtb_TmpSignalConversionAtSele_0
           >= 0; rtb_TmpSignalConversionAtSele_0--) {
        RaspPiPilot_DW.GeneratedFilterBlock_states_l[1 +
          rtb_TmpSignalConversionAtSele_0] =
          RaspPiPilot_DW.GeneratedFilterBlock_states_l[rtb_TmpSignalConversionAtSele_0];
      }

      for (rtb_TmpSignalConversionAtSele_0 = 1; rtb_TmpSignalConversionAtSele_0
           - 1 < 1; rtb_TmpSignalConversionAtSele_0++) {
        RaspPiPilot_DW.GeneratedFilterBlock_states_l[1 -
          rtb_TmpSignalConversionAtSele_0] = RaspPiPilot_B.Product1;
      }

      /* End of DiscreteFir: '<S31>/Generated Filter Block' */

      /* Trigonometry: '<S21>/Trigonometric Function' incorporates:
       *  DotProduct: '<S21>/Dot Product'
       *  Gain: '<S21>/Convert pixels to degrees1'
       *  Gain: '<S21>/Gain6'
       *  SignalConversion: '<S21>/TmpSignal ConversionAtDot ProductInport1'
       *  Sqrt: '<S21>/Sqrt'
       */
      rtb_TrigonometricFunction = cos(sqrt(rtb_TrigonometricFunction *
        rtb_TrigonometricFunction + rtb_TmpSignalConversionAtDotPro[1] *
        rtb_TmpSignalConversionAtDotPro[1]) *
        RaspPiPilot_P.Convertpixelstodegrees1_Gain * RaspPiPilot_P.Gain6_Gain);

      /* Math: '<S21>/Math Function2' incorporates:
       *  Constant: '<S21>/Constant1'
       */
      if ((rtb_TrigonometricFunction < 0.0) && (RaspPiPilot_P.Constant1_Value >
           floor(RaspPiPilot_P.Constant1_Value))) {
        RaspPiPilot_B.MathFunction2 = -rt_powd_snf(-rtb_TrigonometricFunction,
          RaspPiPilot_P.Constant1_Value);
      } else {
        RaspPiPilot_B.MathFunction2 = rt_powd_snf(rtb_TrigonometricFunction,
          RaspPiPilot_P.Constant1_Value);
      }

      /* End of Math: '<S21>/Math Function2' */

      /* Product: '<S21>/Product' */
      rtb_GeneratedFilterBlock *= RaspPiPilot_B.MathFunction2;

      /* Math: '<S21>/Math Function' incorporates:
       *  Constant: '<S21>/Constant'
       */
      if ((rtb_GeneratedFilterBlock < 0.0) && (RaspPiPilot_P.Constant_Value_f >
           floor(RaspPiPilot_P.Constant_Value_f))) {
        rtb_GeneratedFilterBlock = -rt_powd_snf(-rtb_GeneratedFilterBlock,
          RaspPiPilot_P.Constant_Value_f);
      } else {
        rtb_GeneratedFilterBlock = rt_powd_snf(rtb_GeneratedFilterBlock,
          RaspPiPilot_P.Constant_Value_f);
      }

      /* End of Math: '<S21>/Math Function' */

      /* Gain: '<S21>/Gain2' */
      rtb_c = RaspPiPilot_P.Gain2_Gain * rtb_GeneratedFilterBlock;

      /* DataTypeConversion: '<S14>/Data Type Conversion' */
      RaspPiPilot_B.DataTypeConversion = rtb_BlobAnalysis1_o1;

      /* Product: '<S20>/Product' */
      RaspPiPilot_B.Product = RaspPiPilot_B.DataTypeConversion *
        RaspPiPilot_B.MathFunction;

      /* DiscreteFir: '<S32>/Generated Filter Block' */
      /* Consume delay line and beginning of input samples */
      for (rtb_TmpSignalConversionAtSele_0 = 1; rtb_TmpSignalConversionAtSele_0
           - 1 < 1; rtb_TmpSignalConversionAtSele_0++) {
        rtb_GeneratedFilterBlock = 0.0;
        for (lastCol = 0; lastCol < rtb_TmpSignalConversionAtSele_0; lastCol++)
        {
          rtb_GeneratedFilterBlock += RaspPiPilot_B.Product *
            RaspPiPilot_P.GeneratedFilterBlock_Coeffici_b[lastCol];
        }

        for (lastCol = 0; lastCol < 14 - rtb_TmpSignalConversionAtSele_0;
             lastCol++) {
          rtb_GeneratedFilterBlock +=
            RaspPiPilot_P.GeneratedFilterBlock_Coeffici_b[rtb_TmpSignalConversionAtSele_0
            + lastCol] * RaspPiPilot_DW.GeneratedFilterBlock_states_j[lastCol];
        }
      }

      /* Update delay line for next frame */
      for (rtb_TmpSignalConversionAtSele_0 = 11; rtb_TmpSignalConversionAtSele_0
           >= 0; rtb_TmpSignalConversionAtSele_0--) {
        RaspPiPilot_DW.GeneratedFilterBlock_states_j[1 +
          rtb_TmpSignalConversionAtSele_0] =
          RaspPiPilot_DW.GeneratedFilterBlock_states_j[rtb_TmpSignalConversionAtSele_0];
      }

      for (rtb_TmpSignalConversionAtSele_0 = 1; rtb_TmpSignalConversionAtSele_0
           - 1 < 1; rtb_TmpSignalConversionAtSele_0++) {
        RaspPiPilot_DW.GeneratedFilterBlock_states_j[1 -
          rtb_TmpSignalConversionAtSele_0] = RaspPiPilot_B.Product;
      }

      /* End of DiscreteFir: '<S32>/Generated Filter Block' */

      /* Product: '<S21>/Product1' */
      rtb_GeneratedFilterBlock *= RaspPiPilot_B.MathFunction2;

      /* Math: '<S21>/Math Function1' incorporates:
       *  Constant: '<S21>/Constant'
       */
      if ((rtb_GeneratedFilterBlock < 0.0) && (RaspPiPilot_P.Constant_Value_f >
           floor(RaspPiPilot_P.Constant_Value_f))) {
        rtb_GeneratedFilterBlock = -rt_powd_snf(-rtb_GeneratedFilterBlock,
          RaspPiPilot_P.Constant_Value_f);
      } else {
        rtb_GeneratedFilterBlock = rt_powd_snf(rtb_GeneratedFilterBlock,
          RaspPiPilot_P.Constant_Value_f);
      }

      /* End of Math: '<S21>/Math Function1' */

      /* Sum: '<S21>/Sum5' incorporates:
       *  Gain: '<S21>/Gain1'
       */
      RaspPiPilot_B.Sum5 = RaspPiPilot_P.Gain1_Gain * rtb_GeneratedFilterBlock +
        rtb_c;

      /* DiscreteFir: '<S30>/Generated Filter Block' */
      /* Consume delay line and beginning of input samples */
      for (rtb_TmpSignalConversionAtSele_0 = 1; rtb_TmpSignalConversionAtSele_0
           - 1 < 1; rtb_TmpSignalConversionAtSele_0++) {
        rtb_GeneratedFilterBlock = 0.0;
        for (lastCol = 0; lastCol < rtb_TmpSignalConversionAtSele_0; lastCol++)
        {
          rtb_GeneratedFilterBlock += RaspPiPilot_B.Sum5 *
            RaspPiPilot_P.GeneratedFilterBlock_Coeffic_hi[lastCol];
        }

        for (lastCol = 0; lastCol < 14 - rtb_TmpSignalConversionAtSele_0;
             lastCol++) {
          rtb_GeneratedFilterBlock +=
            RaspPiPilot_P.GeneratedFilterBlock_Coeffic_hi[rtb_TmpSignalConversionAtSele_0
            + lastCol] * RaspPiPilot_DW.GeneratedFilterBlock_states_k[lastCol];
        }
      }

      /* Update delay line for next frame */
      for (rtb_TmpSignalConversionAtSele_0 = 11; rtb_TmpSignalConversionAtSele_0
           >= 0; rtb_TmpSignalConversionAtSele_0--) {
        RaspPiPilot_DW.GeneratedFilterBlock_states_k[1 +
          rtb_TmpSignalConversionAtSele_0] =
          RaspPiPilot_DW.GeneratedFilterBlock_states_k[rtb_TmpSignalConversionAtSele_0];
      }

      for (rtb_TmpSignalConversionAtSele_0 = 1; rtb_TmpSignalConversionAtSele_0
           - 1 < 1; rtb_TmpSignalConversionAtSele_0++) {
        RaspPiPilot_DW.GeneratedFilterBlock_states_k[1 -
          rtb_TmpSignalConversionAtSele_0] = RaspPiPilot_B.Sum5;
      }

      /* End of DiscreteFir: '<S30>/Generated Filter Block' */

      /* Gain: '<S21>/Gain' */
      RaspPiPilot_B.Gain = RaspPiPilot_P.Gain_Gain * rtb_GeneratedFilterBlock;

      /* DataTypeConversion: '<S15>/Data Type Conversion' */
      RaspPiPilot_B.DataTypeConversion_l = rtb_BlobAnalysis1_o1_h;

      /* Concatenate: '<S10>/Matrix Concatenate' incorporates:
       *  MATLAB Function: '<S19>/MATLAB Function'
       */
      RaspPiPilot_B.MatrixConcatenate[0] = rtb_Sum2_idx_0;
      RaspPiPilot_B.MatrixConcatenate[4] = rtb_Sum2_idx_1;
      RaspPiPilot_B.MatrixConcatenate[1] = rtb_Sum4_idx_0;
      RaspPiPilot_B.MatrixConcatenate[5] = rtb_Sum4_idx_1;
      RaspPiPilot_B.MatrixConcatenate[2] = rtb_BlobAnalysis_o2[itmp];
      RaspPiPilot_B.MatrixConcatenate[6] = rtb_BlobAnalysis_o2[itmp + 16];
      RaspPiPilot_B.MatrixConcatenate[3] = RaspPiPilot_B.BlobAnalysis1_o2[0];
      RaspPiPilot_B.MatrixConcatenate[7] = RaspPiPilot_B.BlobAnalysis1_o2[1];

      /* Sum: '<S10>/Sum4' */
      rtb_Sum4_idx_0 = rtb_Sum2_idx_0 - rtb_Sum4_idx_0;

      /* Trigonometry: '<S10>/Trigonometric Function' incorporates:
       *  Sum: '<S10>/Sum4'
       */
      RaspPiPilot_B.TrigonometricFunction = rt_atan2d_snf(rtb_Sum2_idx_1 -
        rtb_Sum4_idx_1, rtb_Sum4_idx_0);
      RaspPiPilot_DW.FunctionCallSubsystem_SubsysRan = 4;
    }

    /* Sum: '<S6>/Sum' */
    RaspPiPilot_B.Sum[0] = RaspPiPilot_B.Gain4[0] -
      RaspPiPilot_B.GeneratedFilterBlock_o;
    RaspPiPilot_B.Sum[1] = RaspPiPilot_B.Gain4[1] -
      RaspPiPilot_B.GeneratedFilterBlock;

    /* MATLAB Function: '<S6>/MATLAB Function1' */
    /* MATLAB Function 'Navigation/MATLAB Function1': '<S11>:1' */
    /* '<S11>:1:2' */
    /* '<S11>:1:3' */
    /* '<S11>:1:4' */
    rtb_c = -RaspPiPilot_B.Gain * sin(RaspPiPilot_B.Sum[0]);
    pitch = -RaspPiPilot_B.Gain * -sin(RaspPiPilot_B.Sum[1]);
    RaspPiPilot_B.X[0] = cos(-RaspPiPilot_B.TrigonometricFunction) * rtb_c + sin
      (-RaspPiPilot_B.TrigonometricFunction) * pitch;
    RaspPiPilot_B.X[1] = -sin(-RaspPiPilot_B.TrigonometricFunction) * rtb_c +
      cos(-RaspPiPilot_B.TrigonometricFunction) * pitch;
    RaspPiPilot_B.X[2] = RaspPiPilot_B.Gain;
    RaspPiPilot_B.X[3] = RaspPiPilot_B.TrigonometricFunction;
    if (RaspPiPilot_M->Timing.TaskCounters.TID[2] == 0) {
      /* S-Function (svipdrawshapes): '<S6>/Draw Shapes1' */
      /* Copy the image from input to output. */
      /* Update view port. */
      /* Draw all rectangles. */
      iy = RaspPiPilot_B.bbox_largest[1] - 1;
      pixListMinc = RaspPiPilot_B.bbox_largest[0] - 1;
      pixListNinc = (iy + RaspPiPilot_B.bbox_largest[3]) - 1;
      lastCol = (pixListMinc + RaspPiPilot_B.bbox_largest[2]) - 1;
      if (RaspPiPilot_P.DrawShapes1_lineWidth > 1) {
        bytesRead = RaspPiPilot_P.DrawShapes1_lineWidth >> 1;
        iy -= bytesRead;
        pixListNinc += bytesRead;
        pixListMinc -= bytesRead;
        lastCol += bytesRead;
      }

      if ((iy <= pixListNinc) && (pixListMinc <= lastCol)) {
        for (bytesRead = 0; bytesRead < RaspPiPilot_P.DrawShapes1_lineWidth;
             bytesRead++) {
          rtb_TmpSignalConversionAtSele_0 = iy + bytesRead;
          loop_ub_0 = iy + bytesRead;
          maxNumBlobsReached = false;

          /* Find the visible portion of a line. */
          exitg1 = false;
          visited2 = false;
          done = false;
          line_idx_0 = rtb_TmpSignalConversionAtSele_0;
          loop_ub = pixListMinc;
          rtb_BlobAnalysis1_o1_h = loop_ub_0;
          line_idx_3 = lastCol;
          while (!done) {
            numBlobs = 0U;
            padIdx = 0U;

            /* Determine viewport violations. */
            if (line_idx_0 < 0) {
              numBlobs = 4U;
            } else {
              if (line_idx_0 > 319) {
                numBlobs = 8U;
              }
            }

            if (rtb_BlobAnalysis1_o1_h < 0) {
              padIdx = 4U;
            } else {
              if (rtb_BlobAnalysis1_o1_h > 319) {
                padIdx = 8U;
              }
            }

            if (loop_ub < 0) {
              numBlobs |= 1U;
            } else {
              if (loop_ub > 239) {
                numBlobs |= 2U;
              }
            }

            if (line_idx_3 < 0) {
              padIdx |= 1U;
            } else {
              if (line_idx_3 > 239) {
                padIdx |= 2U;
              }
            }

            if (!((numBlobs | padIdx) != 0U)) {
              /* Line falls completely within bounds. */
              done = true;
              maxNumBlobsReached = true;
            } else if ((numBlobs & padIdx) != 0U) {
              /* Line falls completely out of bounds. */
              done = true;
              maxNumBlobsReached = false;
            } else if (numBlobs != 0U) {
              /* Clip 1st point; if it's in-bounds, clip 2nd point. */
              if (exitg1) {
                line_idx_0 = rtb_TmpSignalConversionAtSele_0;
                loop_ub = pixListMinc;
              }

              ix = rtb_BlobAnalysis1_o1_h - line_idx_0;
              n = line_idx_3 - loop_ub;
              if ((numBlobs & 4U) != 0U) {
                /* Violated RMin. */
                m = -line_idx_0 * n;
                if ((m > 1073741824) || (m < -1073741824)) {
                  done = true;
                  maxNumBlobsReached = false;
                } else if (((m >= 0) && (ix >= 0)) || ((m < 0) && (ix < 0))) {
                  loop_ub += (div_s32_floor(m << 1, ix) + 1) >> 1;
                } else {
                  loop_ub -= (div_s32_floor(-m << 1, ix) + 1) >> 1;
                }

                line_idx_0 = 0;
                exitg1 = true;
              } else if ((numBlobs & 8U) != 0U) {
                /* Violated RMax. */
                m = (319 - line_idx_0) * n;
                if ((m > 1073741824) || (m < -1073741824)) {
                  done = true;
                  maxNumBlobsReached = false;
                } else if (((m >= 0) && (ix >= 0)) || ((m < 0) && (ix < 0))) {
                  loop_ub += (div_s32_floor(m << 1, ix) + 1) >> 1;
                } else {
                  loop_ub -= (div_s32_floor(-m << 1, ix) + 1) >> 1;
                }

                line_idx_0 = 319;
                exitg1 = true;
              } else if ((numBlobs & 1U) != 0U) {
                /* Violated CMin. */
                m = -loop_ub * ix;
                if ((m > 1073741824) || (m < -1073741824)) {
                  done = true;
                  maxNumBlobsReached = false;
                } else if (((m >= 0) && (n >= 0)) || ((m < 0) && (n < 0))) {
                  line_idx_0 += (div_s32_floor(m << 1, n) + 1) >> 1;
                } else {
                  line_idx_0 -= (div_s32_floor(-m << 1, n) + 1) >> 1;
                }

                loop_ub = 0;
                exitg1 = true;
              } else {
                /* Violated CMax. */
                m = (239 - loop_ub) * ix;
                if ((m > 1073741824) || (m < -1073741824)) {
                  done = true;
                  maxNumBlobsReached = false;
                } else if (((m >= 0) && (n >= 0)) || ((m < 0) && (n < 0))) {
                  line_idx_0 += (div_s32_floor(m << 1, n) + 1) >> 1;
                } else {
                  line_idx_0 -= (div_s32_floor(-m << 1, n) + 1) >> 1;
                }

                loop_ub = 239;
                exitg1 = true;
              }
            } else {
              /* Clip the 2nd point. */
              if (visited2) {
                rtb_BlobAnalysis1_o1_h = loop_ub_0;
                line_idx_3 = lastCol;
              }

              ix = rtb_BlobAnalysis1_o1_h - line_idx_0;
              n = line_idx_3 - loop_ub;
              if ((padIdx & 4U) != 0U) {
                /* Violated RMin. */
                m = -rtb_BlobAnalysis1_o1_h * n;
                if ((m > 1073741824) || (m < -1073741824)) {
                  done = true;
                  maxNumBlobsReached = false;
                } else if (((m >= 0) && (ix >= 0)) || ((m < 0) && (ix < 0))) {
                  line_idx_3 += (div_s32_floor(m << 1, ix) + 1) >> 1;
                } else {
                  line_idx_3 -= (div_s32_floor(-m << 1, ix) + 1) >> 1;
                }

                rtb_BlobAnalysis1_o1_h = 0;
                visited2 = true;
              } else if ((padIdx & 8U) != 0U) {
                /* Violated RMax. */
                m = (319 - rtb_BlobAnalysis1_o1_h) * n;
                if ((m > 1073741824) || (m < -1073741824)) {
                  done = true;
                  maxNumBlobsReached = false;
                } else if (((m >= 0) && (ix >= 0)) || ((m < 0) && (ix < 0))) {
                  line_idx_3 += (div_s32_floor(m << 1, ix) + 1) >> 1;
                } else {
                  line_idx_3 -= (div_s32_floor(-m << 1, ix) + 1) >> 1;
                }

                rtb_BlobAnalysis1_o1_h = 319;
                visited2 = true;
              } else if ((padIdx & 1U) != 0U) {
                /* Violated CMin. */
                m = -line_idx_3 * ix;
                if ((m > 1073741824) || (m < -1073741824)) {
                  done = true;
                  maxNumBlobsReached = false;
                } else if (((m >= 0) && (n >= 0)) || ((m < 0) && (n < 0))) {
                  rtb_BlobAnalysis1_o1_h += (div_s32_floor(m << 1, n) + 1) >> 1;
                } else {
                  rtb_BlobAnalysis1_o1_h -= (div_s32_floor(-m << 1, n) + 1) >> 1;
                }

                line_idx_3 = 0;
                visited2 = true;
              } else {
                /* Violated CMax. */
                m = (239 - line_idx_3) * ix;
                if ((m > 1073741824) || (m < -1073741824)) {
                  done = true;
                  maxNumBlobsReached = false;
                } else if (((m >= 0) && (n >= 0)) || ((m < 0) && (n < 0))) {
                  rtb_BlobAnalysis1_o1_h += (div_s32_floor(m << 1, n) + 1) >> 1;
                } else {
                  rtb_BlobAnalysis1_o1_h -= (div_s32_floor(-m << 1, n) + 1) >> 1;
                }

                line_idx_3 = 239;
                visited2 = true;
              }
            }
          }

          if (maxNumBlobsReached) {
            ix = loop_ub * 320 + line_idx_0;
            for (n = loop_ub; n <= line_idx_3; n++) {
              RaspPiPilot_B.RateTransition[ix] =
                RaspPiPilot_P.DrawShapes1_RTP_FILLCOLOR[0];
              RaspPiPilot_B.RateTransition1[ix] =
                RaspPiPilot_P.DrawShapes1_RTP_FILLCOLOR[1];
              RaspPiPilot_B.RateTransition2[ix] =
                RaspPiPilot_P.DrawShapes1_RTP_FILLCOLOR[2];
              ix += 320;
            }
          }

          loop_ub = pixListMinc + bytesRead;
          line_idx_3 = pixListMinc + bytesRead;
          maxNumBlobsReached = false;

          /* Find the visible portion of a line. */
          exitg1 = false;
          visited2 = false;
          done = false;
          rtb_TmpSignalConversionAtSele_0 = iy;
          rtb_BlobAnalysis1_o1 = loop_ub;
          loop_ub_0 = pixListNinc;
          line_idx_3_0 = line_idx_3;
          while (!done) {
            numBlobs = 0U;
            padIdx = 0U;

            /* Determine viewport violations. */
            if (rtb_TmpSignalConversionAtSele_0 < 0) {
              numBlobs = 4U;
            } else {
              if (rtb_TmpSignalConversionAtSele_0 > 319) {
                numBlobs = 8U;
              }
            }

            if (loop_ub_0 < 0) {
              padIdx = 4U;
            } else {
              if (loop_ub_0 > 319) {
                padIdx = 8U;
              }
            }

            if (rtb_BlobAnalysis1_o1 < 0) {
              numBlobs |= 1U;
            } else {
              if (rtb_BlobAnalysis1_o1 > 239) {
                numBlobs |= 2U;
              }
            }

            if (line_idx_3_0 < 0) {
              padIdx |= 1U;
            } else {
              if (line_idx_3_0 > 239) {
                padIdx |= 2U;
              }
            }

            if (!((numBlobs | padIdx) != 0U)) {
              /* Line falls completely within bounds. */
              done = true;
              maxNumBlobsReached = true;
            } else if ((numBlobs & padIdx) != 0U) {
              /* Line falls completely out of bounds. */
              done = true;
              maxNumBlobsReached = false;
            } else if (numBlobs != 0U) {
              /* Clip 1st point; if it's in-bounds, clip 2nd point. */
              if (exitg1) {
                rtb_TmpSignalConversionAtSele_0 = iy;
                rtb_BlobAnalysis1_o1 = loop_ub;
              }

              ix = loop_ub_0 - rtb_TmpSignalConversionAtSele_0;
              n = line_idx_3_0 - rtb_BlobAnalysis1_o1;
              if ((numBlobs & 4U) != 0U) {
                /* Violated RMin. */
                m = -rtb_TmpSignalConversionAtSele_0 * n;
                if ((m > 1073741824) || (m < -1073741824)) {
                  done = true;
                  maxNumBlobsReached = false;
                } else if (((m >= 0) && (ix >= 0)) || ((m < 0) && (ix < 0))) {
                  rtb_BlobAnalysis1_o1 += (div_s32_floor(m << 1, ix) + 1) >> 1;
                } else {
                  rtb_BlobAnalysis1_o1 -= (div_s32_floor(-m << 1, ix) + 1) >> 1;
                }

                rtb_TmpSignalConversionAtSele_0 = 0;
                exitg1 = true;
              } else if ((numBlobs & 8U) != 0U) {
                /* Violated RMax. */
                m = (319 - rtb_TmpSignalConversionAtSele_0) * n;
                if ((m > 1073741824) || (m < -1073741824)) {
                  done = true;
                  maxNumBlobsReached = false;
                } else if (((m >= 0) && (ix >= 0)) || ((m < 0) && (ix < 0))) {
                  rtb_BlobAnalysis1_o1 += (div_s32_floor(m << 1, ix) + 1) >> 1;
                } else {
                  rtb_BlobAnalysis1_o1 -= (div_s32_floor(-m << 1, ix) + 1) >> 1;
                }

                rtb_TmpSignalConversionAtSele_0 = 319;
                exitg1 = true;
              } else if ((numBlobs & 1U) != 0U) {
                /* Violated CMin. */
                m = -rtb_BlobAnalysis1_o1 * ix;
                if ((m > 1073741824) || (m < -1073741824)) {
                  done = true;
                  maxNumBlobsReached = false;
                } else if (((m >= 0) && (n >= 0)) || ((m < 0) && (n < 0))) {
                  rtb_TmpSignalConversionAtSele_0 += (div_s32_floor(m << 1, n) +
                    1) >> 1;
                } else {
                  rtb_TmpSignalConversionAtSele_0 -= (div_s32_floor(-m << 1, n)
                    + 1) >> 1;
                }

                rtb_BlobAnalysis1_o1 = 0;
                exitg1 = true;
              } else {
                /* Violated CMax. */
                m = (239 - rtb_BlobAnalysis1_o1) * ix;
                if ((m > 1073741824) || (m < -1073741824)) {
                  done = true;
                  maxNumBlobsReached = false;
                } else if (((m >= 0) && (n >= 0)) || ((m < 0) && (n < 0))) {
                  rtb_TmpSignalConversionAtSele_0 += (div_s32_floor(m << 1, n) +
                    1) >> 1;
                } else {
                  rtb_TmpSignalConversionAtSele_0 -= (div_s32_floor(-m << 1, n)
                    + 1) >> 1;
                }

                rtb_BlobAnalysis1_o1 = 239;
                exitg1 = true;
              }
            } else {
              /* Clip the 2nd point. */
              if (visited2) {
                loop_ub_0 = pixListNinc;
                line_idx_3_0 = line_idx_3;
              }

              ix = loop_ub_0 - rtb_TmpSignalConversionAtSele_0;
              n = line_idx_3_0 - rtb_BlobAnalysis1_o1;
              if ((padIdx & 4U) != 0U) {
                /* Violated RMin. */
                m = -loop_ub_0 * n;
                if ((m > 1073741824) || (m < -1073741824)) {
                  done = true;
                  maxNumBlobsReached = false;
                } else if (((m >= 0) && (ix >= 0)) || ((m < 0) && (ix < 0))) {
                  line_idx_3_0 += (div_s32_floor(m << 1, ix) + 1) >> 1;
                } else {
                  line_idx_3_0 -= (div_s32_floor(-m << 1, ix) + 1) >> 1;
                }

                loop_ub_0 = 0;
                visited2 = true;
              } else if ((padIdx & 8U) != 0U) {
                /* Violated RMax. */
                m = (319 - loop_ub_0) * n;
                if ((m > 1073741824) || (m < -1073741824)) {
                  done = true;
                  maxNumBlobsReached = false;
                } else if (((m >= 0) && (ix >= 0)) || ((m < 0) && (ix < 0))) {
                  line_idx_3_0 += (div_s32_floor(m << 1, ix) + 1) >> 1;
                } else {
                  line_idx_3_0 -= (div_s32_floor(-m << 1, ix) + 1) >> 1;
                }

                loop_ub_0 = 319;
                visited2 = true;
              } else if ((padIdx & 1U) != 0U) {
                /* Violated CMin. */
                m = -line_idx_3_0 * ix;
                if ((m > 1073741824) || (m < -1073741824)) {
                  done = true;
                  maxNumBlobsReached = false;
                } else if (((m >= 0) && (n >= 0)) || ((m < 0) && (n < 0))) {
                  loop_ub_0 += (div_s32_floor(m << 1, n) + 1) >> 1;
                } else {
                  loop_ub_0 -= (div_s32_floor(-m << 1, n) + 1) >> 1;
                }

                line_idx_3_0 = 0;
                visited2 = true;
              } else {
                /* Violated CMax. */
                m = (239 - line_idx_3_0) * ix;
                if ((m > 1073741824) || (m < -1073741824)) {
                  done = true;
                  maxNumBlobsReached = false;
                } else if (((m >= 0) && (n >= 0)) || ((m < 0) && (n < 0))) {
                  loop_ub_0 += (div_s32_floor(m << 1, n) + 1) >> 1;
                } else {
                  loop_ub_0 -= (div_s32_floor(-m << 1, n) + 1) >> 1;
                }

                line_idx_3_0 = 239;
                visited2 = true;
              }
            }
          }

          if (maxNumBlobsReached) {
            ix = rtb_BlobAnalysis1_o1 * 320 + rtb_TmpSignalConversionAtSele_0;
            for (n = rtb_TmpSignalConversionAtSele_0; n <= loop_ub_0; n++) {
              RaspPiPilot_B.RateTransition[ix] =
                RaspPiPilot_P.DrawShapes1_RTP_FILLCOLOR[0];
              RaspPiPilot_B.RateTransition1[ix] =
                RaspPiPilot_P.DrawShapes1_RTP_FILLCOLOR[1];
              RaspPiPilot_B.RateTransition2[ix] =
                RaspPiPilot_P.DrawShapes1_RTP_FILLCOLOR[2];
              ix++;
            }
          }

          rtb_TmpSignalConversionAtSele_0 = pixListNinc - bytesRead;
          loop_ub_0 = pixListNinc - bytesRead;
          maxNumBlobsReached = false;

          /* Find the visible portion of a line. */
          exitg1 = false;
          visited2 = false;
          done = false;
          line_idx_0 = rtb_TmpSignalConversionAtSele_0;
          loop_ub = pixListMinc;
          rtb_BlobAnalysis1_o1_h = loop_ub_0;
          line_idx_3 = lastCol;
          while (!done) {
            numBlobs = 0U;
            padIdx = 0U;

            /* Determine viewport violations. */
            if (line_idx_0 < 0) {
              numBlobs = 4U;
            } else {
              if (line_idx_0 > 319) {
                numBlobs = 8U;
              }
            }

            if (rtb_BlobAnalysis1_o1_h < 0) {
              padIdx = 4U;
            } else {
              if (rtb_BlobAnalysis1_o1_h > 319) {
                padIdx = 8U;
              }
            }

            if (loop_ub < 0) {
              numBlobs |= 1U;
            } else {
              if (loop_ub > 239) {
                numBlobs |= 2U;
              }
            }

            if (line_idx_3 < 0) {
              padIdx |= 1U;
            } else {
              if (line_idx_3 > 239) {
                padIdx |= 2U;
              }
            }

            if (!((numBlobs | padIdx) != 0U)) {
              /* Line falls completely within bounds. */
              done = true;
              maxNumBlobsReached = true;
            } else if ((numBlobs & padIdx) != 0U) {
              /* Line falls completely out of bounds. */
              done = true;
              maxNumBlobsReached = false;
            } else if (numBlobs != 0U) {
              /* Clip 1st point; if it's in-bounds, clip 2nd point. */
              if (exitg1) {
                line_idx_0 = rtb_TmpSignalConversionAtSele_0;
                loop_ub = pixListMinc;
              }

              ix = rtb_BlobAnalysis1_o1_h - line_idx_0;
              n = line_idx_3 - loop_ub;
              if ((numBlobs & 4U) != 0U) {
                /* Violated RMin. */
                m = -line_idx_0 * n;
                if ((m > 1073741824) || (m < -1073741824)) {
                  done = true;
                  maxNumBlobsReached = false;
                } else if (((m >= 0) && (ix >= 0)) || ((m < 0) && (ix < 0))) {
                  loop_ub += (div_s32_floor(m << 1, ix) + 1) >> 1;
                } else {
                  loop_ub -= (div_s32_floor(-m << 1, ix) + 1) >> 1;
                }

                line_idx_0 = 0;
                exitg1 = true;
              } else if ((numBlobs & 8U) != 0U) {
                /* Violated RMax. */
                m = (319 - line_idx_0) * n;
                if ((m > 1073741824) || (m < -1073741824)) {
                  done = true;
                  maxNumBlobsReached = false;
                } else if (((m >= 0) && (ix >= 0)) || ((m < 0) && (ix < 0))) {
                  loop_ub += (div_s32_floor(m << 1, ix) + 1) >> 1;
                } else {
                  loop_ub -= (div_s32_floor(-m << 1, ix) + 1) >> 1;
                }

                line_idx_0 = 319;
                exitg1 = true;
              } else if ((numBlobs & 1U) != 0U) {
                /* Violated CMin. */
                m = -loop_ub * ix;
                if ((m > 1073741824) || (m < -1073741824)) {
                  done = true;
                  maxNumBlobsReached = false;
                } else if (((m >= 0) && (n >= 0)) || ((m < 0) && (n < 0))) {
                  line_idx_0 += (div_s32_floor(m << 1, n) + 1) >> 1;
                } else {
                  line_idx_0 -= (div_s32_floor(-m << 1, n) + 1) >> 1;
                }

                loop_ub = 0;
                exitg1 = true;
              } else {
                /* Violated CMax. */
                m = (239 - loop_ub) * ix;
                if ((m > 1073741824) || (m < -1073741824)) {
                  done = true;
                  maxNumBlobsReached = false;
                } else if (((m >= 0) && (n >= 0)) || ((m < 0) && (n < 0))) {
                  line_idx_0 += (div_s32_floor(m << 1, n) + 1) >> 1;
                } else {
                  line_idx_0 -= (div_s32_floor(-m << 1, n) + 1) >> 1;
                }

                loop_ub = 239;
                exitg1 = true;
              }
            } else {
              /* Clip the 2nd point. */
              if (visited2) {
                rtb_BlobAnalysis1_o1_h = loop_ub_0;
                line_idx_3 = lastCol;
              }

              ix = rtb_BlobAnalysis1_o1_h - line_idx_0;
              n = line_idx_3 - loop_ub;
              if ((padIdx & 4U) != 0U) {
                /* Violated RMin. */
                m = -rtb_BlobAnalysis1_o1_h * n;
                if ((m > 1073741824) || (m < -1073741824)) {
                  done = true;
                  maxNumBlobsReached = false;
                } else if (((m >= 0) && (ix >= 0)) || ((m < 0) && (ix < 0))) {
                  line_idx_3 += (div_s32_floor(m << 1, ix) + 1) >> 1;
                } else {
                  line_idx_3 -= (div_s32_floor(-m << 1, ix) + 1) >> 1;
                }

                rtb_BlobAnalysis1_o1_h = 0;
                visited2 = true;
              } else if ((padIdx & 8U) != 0U) {
                /* Violated RMax. */
                m = (319 - rtb_BlobAnalysis1_o1_h) * n;
                if ((m > 1073741824) || (m < -1073741824)) {
                  done = true;
                  maxNumBlobsReached = false;
                } else if (((m >= 0) && (ix >= 0)) || ((m < 0) && (ix < 0))) {
                  line_idx_3 += (div_s32_floor(m << 1, ix) + 1) >> 1;
                } else {
                  line_idx_3 -= (div_s32_floor(-m << 1, ix) + 1) >> 1;
                }

                rtb_BlobAnalysis1_o1_h = 319;
                visited2 = true;
              } else if ((padIdx & 1U) != 0U) {
                /* Violated CMin. */
                m = -line_idx_3 * ix;
                if ((m > 1073741824) || (m < -1073741824)) {
                  done = true;
                  maxNumBlobsReached = false;
                } else if (((m >= 0) && (n >= 0)) || ((m < 0) && (n < 0))) {
                  rtb_BlobAnalysis1_o1_h += (div_s32_floor(m << 1, n) + 1) >> 1;
                } else {
                  rtb_BlobAnalysis1_o1_h -= (div_s32_floor(-m << 1, n) + 1) >> 1;
                }

                line_idx_3 = 0;
                visited2 = true;
              } else {
                /* Violated CMax. */
                m = (239 - line_idx_3) * ix;
                if ((m > 1073741824) || (m < -1073741824)) {
                  done = true;
                  maxNumBlobsReached = false;
                } else if (((m >= 0) && (n >= 0)) || ((m < 0) && (n < 0))) {
                  rtb_BlobAnalysis1_o1_h += (div_s32_floor(m << 1, n) + 1) >> 1;
                } else {
                  rtb_BlobAnalysis1_o1_h -= (div_s32_floor(-m << 1, n) + 1) >> 1;
                }

                line_idx_3 = 239;
                visited2 = true;
              }
            }
          }

          if (maxNumBlobsReached) {
            ix = loop_ub * 320 + line_idx_0;
            for (n = loop_ub; n <= line_idx_3; n++) {
              RaspPiPilot_B.RateTransition[ix] =
                RaspPiPilot_P.DrawShapes1_RTP_FILLCOLOR[0];
              RaspPiPilot_B.RateTransition1[ix] =
                RaspPiPilot_P.DrawShapes1_RTP_FILLCOLOR[1];
              RaspPiPilot_B.RateTransition2[ix] =
                RaspPiPilot_P.DrawShapes1_RTP_FILLCOLOR[2];
              ix += 320;
            }
          }

          loop_ub = lastCol - bytesRead;
          line_idx_3 = lastCol - bytesRead;
          maxNumBlobsReached = false;

          /* Find the visible portion of a line. */
          exitg1 = false;
          visited2 = false;
          done = false;
          rtb_TmpSignalConversionAtSele_0 = iy;
          rtb_BlobAnalysis1_o1 = loop_ub;
          loop_ub_0 = pixListNinc;
          line_idx_3_0 = line_idx_3;
          while (!done) {
            numBlobs = 0U;
            padIdx = 0U;

            /* Determine viewport violations. */
            if (rtb_TmpSignalConversionAtSele_0 < 0) {
              numBlobs = 4U;
            } else {
              if (rtb_TmpSignalConversionAtSele_0 > 319) {
                numBlobs = 8U;
              }
            }

            if (loop_ub_0 < 0) {
              padIdx = 4U;
            } else {
              if (loop_ub_0 > 319) {
                padIdx = 8U;
              }
            }

            if (rtb_BlobAnalysis1_o1 < 0) {
              numBlobs |= 1U;
            } else {
              if (rtb_BlobAnalysis1_o1 > 239) {
                numBlobs |= 2U;
              }
            }

            if (line_idx_3_0 < 0) {
              padIdx |= 1U;
            } else {
              if (line_idx_3_0 > 239) {
                padIdx |= 2U;
              }
            }

            if (!((numBlobs | padIdx) != 0U)) {
              /* Line falls completely within bounds. */
              done = true;
              maxNumBlobsReached = true;
            } else if ((numBlobs & padIdx) != 0U) {
              /* Line falls completely out of bounds. */
              done = true;
              maxNumBlobsReached = false;
            } else if (numBlobs != 0U) {
              /* Clip 1st point; if it's in-bounds, clip 2nd point. */
              if (exitg1) {
                rtb_TmpSignalConversionAtSele_0 = iy;
                rtb_BlobAnalysis1_o1 = loop_ub;
              }

              ix = loop_ub_0 - rtb_TmpSignalConversionAtSele_0;
              n = line_idx_3_0 - rtb_BlobAnalysis1_o1;
              if ((numBlobs & 4U) != 0U) {
                /* Violated RMin. */
                m = -rtb_TmpSignalConversionAtSele_0 * n;
                if ((m > 1073741824) || (m < -1073741824)) {
                  done = true;
                  maxNumBlobsReached = false;
                } else if (((m >= 0) && (ix >= 0)) || ((m < 0) && (ix < 0))) {
                  rtb_BlobAnalysis1_o1 += (div_s32_floor(m << 1, ix) + 1) >> 1;
                } else {
                  rtb_BlobAnalysis1_o1 -= (div_s32_floor(-m << 1, ix) + 1) >> 1;
                }

                rtb_TmpSignalConversionAtSele_0 = 0;
                exitg1 = true;
              } else if ((numBlobs & 8U) != 0U) {
                /* Violated RMax. */
                m = (319 - rtb_TmpSignalConversionAtSele_0) * n;
                if ((m > 1073741824) || (m < -1073741824)) {
                  done = true;
                  maxNumBlobsReached = false;
                } else if (((m >= 0) && (ix >= 0)) || ((m < 0) && (ix < 0))) {
                  rtb_BlobAnalysis1_o1 += (div_s32_floor(m << 1, ix) + 1) >> 1;
                } else {
                  rtb_BlobAnalysis1_o1 -= (div_s32_floor(-m << 1, ix) + 1) >> 1;
                }

                rtb_TmpSignalConversionAtSele_0 = 319;
                exitg1 = true;
              } else if ((numBlobs & 1U) != 0U) {
                /* Violated CMin. */
                m = -rtb_BlobAnalysis1_o1 * ix;
                if ((m > 1073741824) || (m < -1073741824)) {
                  done = true;
                  maxNumBlobsReached = false;
                } else if (((m >= 0) && (n >= 0)) || ((m < 0) && (n < 0))) {
                  rtb_TmpSignalConversionAtSele_0 += (div_s32_floor(m << 1, n) +
                    1) >> 1;
                } else {
                  rtb_TmpSignalConversionAtSele_0 -= (div_s32_floor(-m << 1, n)
                    + 1) >> 1;
                }

                rtb_BlobAnalysis1_o1 = 0;
                exitg1 = true;
              } else {
                /* Violated CMax. */
                m = (239 - rtb_BlobAnalysis1_o1) * ix;
                if ((m > 1073741824) || (m < -1073741824)) {
                  done = true;
                  maxNumBlobsReached = false;
                } else if (((m >= 0) && (n >= 0)) || ((m < 0) && (n < 0))) {
                  rtb_TmpSignalConversionAtSele_0 += (div_s32_floor(m << 1, n) +
                    1) >> 1;
                } else {
                  rtb_TmpSignalConversionAtSele_0 -= (div_s32_floor(-m << 1, n)
                    + 1) >> 1;
                }

                rtb_BlobAnalysis1_o1 = 239;
                exitg1 = true;
              }
            } else {
              /* Clip the 2nd point. */
              if (visited2) {
                loop_ub_0 = pixListNinc;
                line_idx_3_0 = line_idx_3;
              }

              ix = loop_ub_0 - rtb_TmpSignalConversionAtSele_0;
              n = line_idx_3_0 - rtb_BlobAnalysis1_o1;
              if ((padIdx & 4U) != 0U) {
                /* Violated RMin. */
                m = -loop_ub_0 * n;
                if ((m > 1073741824) || (m < -1073741824)) {
                  done = true;
                  maxNumBlobsReached = false;
                } else if (((m >= 0) && (ix >= 0)) || ((m < 0) && (ix < 0))) {
                  line_idx_3_0 += (div_s32_floor(m << 1, ix) + 1) >> 1;
                } else {
                  line_idx_3_0 -= (div_s32_floor(-m << 1, ix) + 1) >> 1;
                }

                loop_ub_0 = 0;
                visited2 = true;
              } else if ((padIdx & 8U) != 0U) {
                /* Violated RMax. */
                m = (319 - loop_ub_0) * n;
                if ((m > 1073741824) || (m < -1073741824)) {
                  done = true;
                  maxNumBlobsReached = false;
                } else if (((m >= 0) && (ix >= 0)) || ((m < 0) && (ix < 0))) {
                  line_idx_3_0 += (div_s32_floor(m << 1, ix) + 1) >> 1;
                } else {
                  line_idx_3_0 -= (div_s32_floor(-m << 1, ix) + 1) >> 1;
                }

                loop_ub_0 = 319;
                visited2 = true;
              } else if ((padIdx & 1U) != 0U) {
                /* Violated CMin. */
                m = -line_idx_3_0 * ix;
                if ((m > 1073741824) || (m < -1073741824)) {
                  done = true;
                  maxNumBlobsReached = false;
                } else if (((m >= 0) && (n >= 0)) || ((m < 0) && (n < 0))) {
                  loop_ub_0 += (div_s32_floor(m << 1, n) + 1) >> 1;
                } else {
                  loop_ub_0 -= (div_s32_floor(-m << 1, n) + 1) >> 1;
                }

                line_idx_3_0 = 0;
                visited2 = true;
              } else {
                /* Violated CMax. */
                m = (239 - line_idx_3_0) * ix;
                if ((m > 1073741824) || (m < -1073741824)) {
                  done = true;
                  maxNumBlobsReached = false;
                } else if (((m >= 0) && (n >= 0)) || ((m < 0) && (n < 0))) {
                  loop_ub_0 += (div_s32_floor(m << 1, n) + 1) >> 1;
                } else {
                  loop_ub_0 -= (div_s32_floor(-m << 1, n) + 1) >> 1;
                }

                line_idx_3_0 = 239;
                visited2 = true;
              }
            }
          }

          if (maxNumBlobsReached) {
            ix = rtb_BlobAnalysis1_o1 * 320 + rtb_TmpSignalConversionAtSele_0;
            for (n = rtb_TmpSignalConversionAtSele_0; n <= loop_ub_0; n++) {
              RaspPiPilot_B.RateTransition[ix] =
                RaspPiPilot_P.DrawShapes1_RTP_FILLCOLOR[0];
              RaspPiPilot_B.RateTransition1[ix] =
                RaspPiPilot_P.DrawShapes1_RTP_FILLCOLOR[1];
              RaspPiPilot_B.RateTransition2[ix] =
                RaspPiPilot_P.DrawShapes1_RTP_FILLCOLOR[2];
              ix++;
            }
          }
        }
      }

      /* End of S-Function (svipdrawshapes): '<S6>/Draw Shapes1' */

      /* DataTypeConversion: '<S6>/Data Type Conversion' */
      for (rtb_TmpSignalConversionAtSele_0 = 0; rtb_TmpSignalConversionAtSele_0 <
           8; rtb_TmpSignalConversionAtSele_0++) {
        rtb_c = floor
          (RaspPiPilot_B.MatrixConcatenate[rtb_TmpSignalConversionAtSele_0]);
        if (rtIsNaN(rtb_c) || rtIsInf(rtb_c)) {
          rtb_c = 0.0;
        } else {
          rtb_c = fmod(rtb_c, 4.294967296E+9);
        }

        rtb_DataTypeConversion[rtb_TmpSignalConversionAtSele_0] = rtb_c < 0.0 ?
          -(int32_T)(uint32_T)-rtb_c : (int32_T)(uint32_T)rtb_c;
      }

      /* End of DataTypeConversion: '<S6>/Data Type Conversion' */

      /* S-Function (svipdrawmarkers): '<S6>/Draw Markers2' */
      /* Copy the image from input to output. */
      for (rtb_TmpSignalConversionAtSele_0 = 0; rtb_TmpSignalConversionAtSele_0 <
           76800; rtb_TmpSignalConversionAtSele_0++) {
        RaspPiPilot_B.DrawMarkers2_o1[rtb_TmpSignalConversionAtSele_0] =
          RaspPiPilot_B.RateTransition[rtb_TmpSignalConversionAtSele_0];
        RaspPiPilot_B.DrawMarkers2_o2[rtb_TmpSignalConversionAtSele_0] =
          RaspPiPilot_B.RateTransition1[rtb_TmpSignalConversionAtSele_0];
        RaspPiPilot_B.DrawMarkers2_o3[rtb_TmpSignalConversionAtSele_0] =
          RaspPiPilot_B.RateTransition2[rtb_TmpSignalConversionAtSele_0];
      }

      /* Update view port. */
      /* Draw all X marks. */
      rtb_BlobAnalysis2_o1 = 0;
      for (itmp = 0; itmp < 4; itmp++) {
        bytesRead = rtb_DataTypeConversion[itmp + 4] - 1;
        iy = rtb_DataTypeConversion[itmp] - 1;
        rtb_TmpSignalConversionAtSele_0 = bytesRead -
          RaspPiPilot_P.DrawMarkers2_size;
        loop_ub = iy - RaspPiPilot_P.DrawMarkers2_size;
        loop_ub_0 = bytesRead + RaspPiPilot_P.DrawMarkers2_size;
        line_idx_3 = iy + RaspPiPilot_P.DrawMarkers2_size;
        maxNumBlobsReached = false;

        /* Find the visible portion of a line. */
        exitg1 = false;
        visited2 = false;
        done = false;
        line_idx_0 = rtb_TmpSignalConversionAtSele_0;
        rtb_BlobAnalysis1_o1 = loop_ub;
        rtb_BlobAnalysis1_o1_h = loop_ub_0;
        line_idx_3_0 = line_idx_3;
        while (!done) {
          numBlobs = 0U;
          padIdx = 0U;

          /* Determine viewport violations. */
          if (line_idx_0 < 0) {
            numBlobs = 4U;
          } else {
            if (line_idx_0 > 319) {
              numBlobs = 8U;
            }
          }

          if (rtb_BlobAnalysis1_o1_h < 0) {
            padIdx = 4U;
          } else {
            if (rtb_BlobAnalysis1_o1_h > 319) {
              padIdx = 8U;
            }
          }

          if (rtb_BlobAnalysis1_o1 < 0) {
            numBlobs |= 1U;
          } else {
            if (rtb_BlobAnalysis1_o1 > 239) {
              numBlobs |= 2U;
            }
          }

          if (line_idx_3_0 < 0) {
            padIdx |= 1U;
          } else {
            if (line_idx_3_0 > 239) {
              padIdx |= 2U;
            }
          }

          if (!((numBlobs | padIdx) != 0U)) {
            /* Line falls completely within bounds. */
            done = true;
            maxNumBlobsReached = true;
          } else if ((numBlobs & padIdx) != 0U) {
            /* Line falls completely out of bounds. */
            done = true;
            maxNumBlobsReached = false;
          } else if (numBlobs != 0U) {
            /* Clip 1st point; if it's in-bounds, clip 2nd point. */
            if (exitg1) {
              line_idx_0 = rtb_TmpSignalConversionAtSele_0;
              rtb_BlobAnalysis1_o1 = loop_ub;
            }

            ix = rtb_BlobAnalysis1_o1_h - line_idx_0;
            n = line_idx_3_0 - rtb_BlobAnalysis1_o1;
            if ((numBlobs & 4U) != 0U) {
              /* Violated RMin. */
              m = -line_idx_0 * n;
              if ((m > 1073741824) || (m < -1073741824)) {
                done = true;
                maxNumBlobsReached = false;
              } else if (((m >= 0) && (ix >= 0)) || ((m < 0) && (ix < 0))) {
                rtb_BlobAnalysis1_o1 += (div_s32_floor(m << 1, ix) + 1) >> 1;
              } else {
                rtb_BlobAnalysis1_o1 -= (div_s32_floor(-m << 1, ix) + 1) >> 1;
              }

              line_idx_0 = 0;
              exitg1 = true;
            } else if ((numBlobs & 8U) != 0U) {
              /* Violated RMax. */
              m = (319 - line_idx_0) * n;
              if ((m > 1073741824) || (m < -1073741824)) {
                done = true;
                maxNumBlobsReached = false;
              } else if (((m >= 0) && (ix >= 0)) || ((m < 0) && (ix < 0))) {
                rtb_BlobAnalysis1_o1 += (div_s32_floor(m << 1, ix) + 1) >> 1;
              } else {
                rtb_BlobAnalysis1_o1 -= (div_s32_floor(-m << 1, ix) + 1) >> 1;
              }

              line_idx_0 = 319;
              exitg1 = true;
            } else if ((numBlobs & 1U) != 0U) {
              /* Violated CMin. */
              m = -rtb_BlobAnalysis1_o1 * ix;
              if ((m > 1073741824) || (m < -1073741824)) {
                done = true;
                maxNumBlobsReached = false;
              } else if (((m >= 0) && (n >= 0)) || ((m < 0) && (n < 0))) {
                line_idx_0 += (div_s32_floor(m << 1, n) + 1) >> 1;
              } else {
                line_idx_0 -= (div_s32_floor(-m << 1, n) + 1) >> 1;
              }

              rtb_BlobAnalysis1_o1 = 0;
              exitg1 = true;
            } else {
              /* Violated CMax. */
              m = (239 - rtb_BlobAnalysis1_o1) * ix;
              if ((m > 1073741824) || (m < -1073741824)) {
                done = true;
                maxNumBlobsReached = false;
              } else if (((m >= 0) && (n >= 0)) || ((m < 0) && (n < 0))) {
                line_idx_0 += (div_s32_floor(m << 1, n) + 1) >> 1;
              } else {
                line_idx_0 -= (div_s32_floor(-m << 1, n) + 1) >> 1;
              }

              rtb_BlobAnalysis1_o1 = 239;
              exitg1 = true;
            }
          } else {
            /* Clip the 2nd point. */
            if (visited2) {
              rtb_BlobAnalysis1_o1_h = loop_ub_0;
              line_idx_3_0 = line_idx_3;
            }

            ix = rtb_BlobAnalysis1_o1_h - line_idx_0;
            n = line_idx_3_0 - rtb_BlobAnalysis1_o1;
            if ((padIdx & 4U) != 0U) {
              /* Violated RMin. */
              m = -rtb_BlobAnalysis1_o1_h * n;
              if ((m > 1073741824) || (m < -1073741824)) {
                done = true;
                maxNumBlobsReached = false;
              } else if (((m >= 0) && (ix >= 0)) || ((m < 0) && (ix < 0))) {
                line_idx_3_0 += (div_s32_floor(m << 1, ix) + 1) >> 1;
              } else {
                line_idx_3_0 -= (div_s32_floor(-m << 1, ix) + 1) >> 1;
              }

              rtb_BlobAnalysis1_o1_h = 0;
              visited2 = true;
            } else if ((padIdx & 8U) != 0U) {
              /* Violated RMax. */
              m = (319 - rtb_BlobAnalysis1_o1_h) * n;
              if ((m > 1073741824) || (m < -1073741824)) {
                done = true;
                maxNumBlobsReached = false;
              } else if (((m >= 0) && (ix >= 0)) || ((m < 0) && (ix < 0))) {
                line_idx_3_0 += (div_s32_floor(m << 1, ix) + 1) >> 1;
              } else {
                line_idx_3_0 -= (div_s32_floor(-m << 1, ix) + 1) >> 1;
              }

              rtb_BlobAnalysis1_o1_h = 319;
              visited2 = true;
            } else if ((padIdx & 1U) != 0U) {
              /* Violated CMin. */
              m = -line_idx_3_0 * ix;
              if ((m > 1073741824) || (m < -1073741824)) {
                done = true;
                maxNumBlobsReached = false;
              } else if (((m >= 0) && (n >= 0)) || ((m < 0) && (n < 0))) {
                rtb_BlobAnalysis1_o1_h += (div_s32_floor(m << 1, n) + 1) >> 1;
              } else {
                rtb_BlobAnalysis1_o1_h -= (div_s32_floor(-m << 1, n) + 1) >> 1;
              }

              line_idx_3_0 = 0;
              visited2 = true;
            } else {
              /* Violated CMax. */
              m = (239 - line_idx_3_0) * ix;
              if ((m > 1073741824) || (m < -1073741824)) {
                done = true;
                maxNumBlobsReached = false;
              } else if (((m >= 0) && (n >= 0)) || ((m < 0) && (n < 0))) {
                rtb_BlobAnalysis1_o1_h += (div_s32_floor(m << 1, n) + 1) >> 1;
              } else {
                rtb_BlobAnalysis1_o1_h -= (div_s32_floor(-m << 1, n) + 1) >> 1;
              }

              line_idx_3_0 = 239;
              visited2 = true;
            }
          }
        }

        if (maxNumBlobsReached) {
          ix = rtb_BlobAnalysis1_o1 * 320 + line_idx_0;
          for (n = line_idx_0; n <= rtb_BlobAnalysis1_o1_h; n++) {
            RaspPiPilot_B.DrawMarkers2_o1[ix] =
              RaspPiPilot_P.DrawMarkers2_color[rtb_BlobAnalysis2_o1];
            m = rtb_BlobAnalysis2_o1 + 4;
            RaspPiPilot_B.DrawMarkers2_o2[ix] =
              RaspPiPilot_P.DrawMarkers2_color[m];
            RaspPiPilot_B.DrawMarkers2_o3[ix] =
              RaspPiPilot_P.DrawMarkers2_color[m + 4];
            ix += 321;
          }
        }

        rtb_TmpSignalConversionAtSele_0 = bytesRead -
          RaspPiPilot_P.DrawMarkers2_size;
        loop_ub = iy + RaspPiPilot_P.DrawMarkers2_size;
        loop_ub_0 = bytesRead + RaspPiPilot_P.DrawMarkers2_size;
        line_idx_3 = iy - RaspPiPilot_P.DrawMarkers2_size;
        maxNumBlobsReached = false;

        /* Find the visible portion of a line. */
        exitg1 = false;
        visited2 = false;
        done = false;
        line_idx_0 = rtb_TmpSignalConversionAtSele_0;
        rtb_BlobAnalysis1_o1 = loop_ub;
        rtb_BlobAnalysis1_o1_h = loop_ub_0;
        line_idx_3_0 = line_idx_3;
        while (!done) {
          numBlobs = 0U;
          padIdx = 0U;

          /* Determine viewport violations. */
          if (line_idx_0 < 0) {
            numBlobs = 4U;
          } else {
            if (line_idx_0 > 319) {
              numBlobs = 8U;
            }
          }

          if (rtb_BlobAnalysis1_o1_h < 0) {
            padIdx = 4U;
          } else {
            if (rtb_BlobAnalysis1_o1_h > 319) {
              padIdx = 8U;
            }
          }

          if (rtb_BlobAnalysis1_o1 < 0) {
            numBlobs |= 1U;
          } else {
            if (rtb_BlobAnalysis1_o1 > 239) {
              numBlobs |= 2U;
            }
          }

          if (line_idx_3_0 < 0) {
            padIdx |= 1U;
          } else {
            if (line_idx_3_0 > 239) {
              padIdx |= 2U;
            }
          }

          if (!((numBlobs | padIdx) != 0U)) {
            /* Line falls completely within bounds. */
            done = true;
            maxNumBlobsReached = true;
          } else if ((numBlobs & padIdx) != 0U) {
            /* Line falls completely out of bounds. */
            done = true;
            maxNumBlobsReached = false;
          } else if (numBlobs != 0U) {
            /* Clip 1st point; if it's in-bounds, clip 2nd point. */
            if (exitg1) {
              line_idx_0 = rtb_TmpSignalConversionAtSele_0;
              rtb_BlobAnalysis1_o1 = loop_ub;
            }

            ix = rtb_BlobAnalysis1_o1_h - line_idx_0;
            n = line_idx_3_0 - rtb_BlobAnalysis1_o1;
            if ((numBlobs & 4U) != 0U) {
              /* Violated RMin. */
              m = -line_idx_0 * n;
              if ((m > 1073741824) || (m < -1073741824)) {
                done = true;
                maxNumBlobsReached = false;
              } else if (((m >= 0) && (ix >= 0)) || ((m < 0) && (ix < 0))) {
                rtb_BlobAnalysis1_o1 += (div_s32_floor(m << 1, ix) + 1) >> 1;
              } else {
                rtb_BlobAnalysis1_o1 -= (div_s32_floor(-m << 1, ix) + 1) >> 1;
              }

              line_idx_0 = 0;
              exitg1 = true;
            } else if ((numBlobs & 8U) != 0U) {
              /* Violated RMax. */
              m = (319 - line_idx_0) * n;
              if ((m > 1073741824) || (m < -1073741824)) {
                done = true;
                maxNumBlobsReached = false;
              } else if (((m >= 0) && (ix >= 0)) || ((m < 0) && (ix < 0))) {
                rtb_BlobAnalysis1_o1 += (div_s32_floor(m << 1, ix) + 1) >> 1;
              } else {
                rtb_BlobAnalysis1_o1 -= (div_s32_floor(-m << 1, ix) + 1) >> 1;
              }

              line_idx_0 = 319;
              exitg1 = true;
            } else if ((numBlobs & 1U) != 0U) {
              /* Violated CMin. */
              m = -rtb_BlobAnalysis1_o1 * ix;
              if ((m > 1073741824) || (m < -1073741824)) {
                done = true;
                maxNumBlobsReached = false;
              } else if (((m >= 0) && (n >= 0)) || ((m < 0) && (n < 0))) {
                line_idx_0 += (div_s32_floor(m << 1, n) + 1) >> 1;
              } else {
                line_idx_0 -= (div_s32_floor(-m << 1, n) + 1) >> 1;
              }

              rtb_BlobAnalysis1_o1 = 0;
              exitg1 = true;
            } else {
              /* Violated CMax. */
              m = (239 - rtb_BlobAnalysis1_o1) * ix;
              if ((m > 1073741824) || (m < -1073741824)) {
                done = true;
                maxNumBlobsReached = false;
              } else if (((m >= 0) && (n >= 0)) || ((m < 0) && (n < 0))) {
                line_idx_0 += (div_s32_floor(m << 1, n) + 1) >> 1;
              } else {
                line_idx_0 -= (div_s32_floor(-m << 1, n) + 1) >> 1;
              }

              rtb_BlobAnalysis1_o1 = 239;
              exitg1 = true;
            }
          } else {
            /* Clip the 2nd point. */
            if (visited2) {
              rtb_BlobAnalysis1_o1_h = loop_ub_0;
              line_idx_3_0 = line_idx_3;
            }

            ix = rtb_BlobAnalysis1_o1_h - line_idx_0;
            n = line_idx_3_0 - rtb_BlobAnalysis1_o1;
            if ((padIdx & 4U) != 0U) {
              /* Violated RMin. */
              m = -rtb_BlobAnalysis1_o1_h * n;
              if ((m > 1073741824) || (m < -1073741824)) {
                done = true;
                maxNumBlobsReached = false;
              } else if (((m >= 0) && (ix >= 0)) || ((m < 0) && (ix < 0))) {
                line_idx_3_0 += (div_s32_floor(m << 1, ix) + 1) >> 1;
              } else {
                line_idx_3_0 -= (div_s32_floor(-m << 1, ix) + 1) >> 1;
              }

              rtb_BlobAnalysis1_o1_h = 0;
              visited2 = true;
            } else if ((padIdx & 8U) != 0U) {
              /* Violated RMax. */
              m = (319 - rtb_BlobAnalysis1_o1_h) * n;
              if ((m > 1073741824) || (m < -1073741824)) {
                done = true;
                maxNumBlobsReached = false;
              } else if (((m >= 0) && (ix >= 0)) || ((m < 0) && (ix < 0))) {
                line_idx_3_0 += (div_s32_floor(m << 1, ix) + 1) >> 1;
              } else {
                line_idx_3_0 -= (div_s32_floor(-m << 1, ix) + 1) >> 1;
              }

              rtb_BlobAnalysis1_o1_h = 319;
              visited2 = true;
            } else if ((padIdx & 1U) != 0U) {
              /* Violated CMin. */
              m = -line_idx_3_0 * ix;
              if ((m > 1073741824) || (m < -1073741824)) {
                done = true;
                maxNumBlobsReached = false;
              } else if (((m >= 0) && (n >= 0)) || ((m < 0) && (n < 0))) {
                rtb_BlobAnalysis1_o1_h += (div_s32_floor(m << 1, n) + 1) >> 1;
              } else {
                rtb_BlobAnalysis1_o1_h -= (div_s32_floor(-m << 1, n) + 1) >> 1;
              }

              line_idx_3_0 = 0;
              visited2 = true;
            } else {
              /* Violated CMax. */
              m = (239 - line_idx_3_0) * ix;
              if ((m > 1073741824) || (m < -1073741824)) {
                done = true;
                maxNumBlobsReached = false;
              } else if (((m >= 0) && (n >= 0)) || ((m < 0) && (n < 0))) {
                rtb_BlobAnalysis1_o1_h += (div_s32_floor(m << 1, n) + 1) >> 1;
              } else {
                rtb_BlobAnalysis1_o1_h -= (div_s32_floor(-m << 1, n) + 1) >> 1;
              }

              line_idx_3_0 = 239;
              visited2 = true;
            }
          }
        }

        if (maxNumBlobsReached) {
          ix = rtb_BlobAnalysis1_o1 * 320 + line_idx_0;
          for (n = line_idx_0; n <= rtb_BlobAnalysis1_o1_h; n++) {
            RaspPiPilot_B.DrawMarkers2_o1[ix] =
              RaspPiPilot_P.DrawMarkers2_color[rtb_BlobAnalysis2_o1];
            m = rtb_BlobAnalysis2_o1 + 4;
            RaspPiPilot_B.DrawMarkers2_o2[ix] =
              RaspPiPilot_P.DrawMarkers2_color[m];
            RaspPiPilot_B.DrawMarkers2_o3[ix] =
              RaspPiPilot_P.DrawMarkers2_color[m + 4];
            ix -= 319;
          }
        }

        if (rtb_BlobAnalysis2_o1 < 9) {
          rtb_BlobAnalysis2_o1++;
        } else {
          rtb_BlobAnalysis2_o1 = 0;
        }
      }

      /* End of S-Function (svipdrawmarkers): '<S6>/Draw Markers2' */

      /* S-Function (sdl_video_display_sfcn): '<S6>/SDL Video Display' */
      MW_SDL_videoDisplayOutput(RaspPiPilot_B.DrawMarkers2_o1,
        RaspPiPilot_B.DrawMarkers2_o2, RaspPiPilot_B.DrawMarkers2_o3);
    }

    srUpdateBC(RaspPiPilot_DW.Navigation_SubsysRanBC);
  } else {
    if (RaspPiPilot_DW.Navigation_MODE) {
      RaspPiPilot_DW.Navigation_MODE = false;
    }
  }

  /* End of Outputs for SubSystem: '<Root>/Navigation' */
}

/* Model update function */
void RaspPiPilot_update(void)
{
  /* Update for UnitDelay: '<Root>/Unit Delay' */
  RaspPiPilot_DW.UnitDelay_DSTATE = RaspPiPilot_B.Compare_b;

  /* Update for Memory: '<Root>/Memory' */
  RaspPiPilot_DW.Memory_PreviousInput[0] = RaspPiPilot_B.Constant3;
  RaspPiPilot_DW.Memory_PreviousInput[1] = RaspPiPilot_B.Constant4;
  RaspPiPilot_DW.Memory_PreviousInput[2] = RaspPiPilot_B.Constant5;
  RaspPiPilot_DW.Memory_PreviousInput[3] = RaspPiPilot_B.Constant6;

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.01s, 0.0s] */
    if ((rtmGetTFinal(RaspPiPilot_M)!=-1) &&
        !((rtmGetTFinal(RaspPiPilot_M)-RaspPiPilot_M->Timing.taskTime0) >
          RaspPiPilot_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(RaspPiPilot_M, "Simulation finished");
    }

    if (rtmGetStopRequested(RaspPiPilot_M)) {
      rtmSetErrorStatus(RaspPiPilot_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  RaspPiPilot_M->Timing.taskTime0 =
    (++RaspPiPilot_M->Timing.clockTick0) * RaspPiPilot_M->Timing.stepSize0;
  if (RaspPiPilot_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update absolute timer for sample time: [0.06s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.06, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    RaspPiPilot_M->Timing.clockTick1++;
  }

  if (RaspPiPilot_M->Timing.TaskCounters.TID[2] == 0) {
    /* Update absolute timer for sample time: [0.12s, 0.0s] */
    /* The "clockTick2" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.12, which is the step size
     * of the task. Size of "clockTick2" ensures timer will not overflow during the
     * application lifespan selected.
     */
    RaspPiPilot_M->Timing.clockTick2++;
  }

  rate_scheduler();
}

/* Model initialize function */
void RaspPiPilot_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)RaspPiPilot_M, 0,
                sizeof(RT_MODEL_RaspPiPilot_T));
  rtmSetTFinal(RaspPiPilot_M, -1);
  RaspPiPilot_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  RaspPiPilot_M->Sizes.checksums[0] = (2786906485U);
  RaspPiPilot_M->Sizes.checksums[1] = (544495020U);
  RaspPiPilot_M->Sizes.checksums[2] = (1268545206U);
  RaspPiPilot_M->Sizes.checksums[3] = (368425856U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[25];
    RaspPiPilot_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = (sysRanDType *)
      &RaspPiPilot_DW.FunctionCallSubsystem_SubsysRan;
    systemRan[4] = (sysRanDType *)
      &RaspPiPilot_DW.FunctionCallSubsystem_SubsysRan;
    systemRan[5] = (sysRanDType *)
      &RaspPiPilot_DW.FunctionCallSubsystem_SubsysRan;
    systemRan[6] = (sysRanDType *)
      &RaspPiPilot_DW.FunctionCallSubsystem_SubsysRan;
    systemRan[7] = (sysRanDType *)
      &RaspPiPilot_DW.FunctionCallSubsystem_SubsysRan;
    systemRan[8] = (sysRanDType *)
      &RaspPiPilot_DW.FunctionCallSubsystem_SubsysRan;
    systemRan[9] = (sysRanDType *)
      &RaspPiPilot_DW.FunctionCallSubsystem_SubsysRan;
    systemRan[10] = (sysRanDType *)&RaspPiPilot_DW.Navigation_SubsysRanBC;
    systemRan[11] = (sysRanDType *)&RaspPiPilot_DW.Navigation_SubsysRanBC;
    systemRan[12] = (sysRanDType *)&RaspPiPilot_DW.messageParser_SubsysRanBC;
    systemRan[13] = (sysRanDType *)&RaspPiPilot_DW.attitudeParser_SubsysRanBC;
    systemRan[14] = (sysRanDType *)&RaspPiPilot_DW.attitudeParser_SubsysRanBC;
    systemRan[15] = (sysRanDType *)&RaspPiPilot_DW.resultParser_SubsysRanBC;
    systemRan[16] = (sysRanDType *)&RaspPiPilot_DW.resultParser_SubsysRanBC;
    systemRan[17] = (sysRanDType *)&RaspPiPilot_DW.statusParser_SubsysRanBC;
    systemRan[18] = (sysRanDType *)&RaspPiPilot_DW.statusParser_SubsysRanBC;
    systemRan[19] = (sysRanDType *)&RaspPiPilot_DW.statusParser1_SubsysRanBC;
    systemRan[20] = (sysRanDType *)&RaspPiPilot_DW.statusParser1_SubsysRanBC;
    systemRan[21] = (sysRanDType *)&RaspPiPilot_DW.stringParser_SubsysRanBC;
    systemRan[22] = (sysRanDType *)&RaspPiPilot_DW.stringParser_SubsysRanBC;
    systemRan[23] = (sysRanDType *)&RaspPiPilot_DW.messageParser_SubsysRanBC;
    systemRan[24] = (sysRanDType *)&RaspPiPilot_DW.messageParser_SubsysRanBC;
    rteiSetModelMappingInfoPtr(RaspPiPilot_M->extModeInfo,
      &RaspPiPilot_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(RaspPiPilot_M->extModeInfo,
                        RaspPiPilot_M->Sizes.checksums);
    rteiSetTPtr(RaspPiPilot_M->extModeInfo, rtmGetTPtr(RaspPiPilot_M));
  }

  /* block I/O */
  (void) memset(((void *) &RaspPiPilot_B), 0,
                sizeof(B_RaspPiPilot_T));

  /* states (dwork) */
  (void) memset((void *)&RaspPiPilot_DW, 0,
                sizeof(DW_RaspPiPilot_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    RaspPiPilot_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 17;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  {
    int32_T i;

    /* Start for Enabled SubSystem: '<Root>/messageParser' */

    /* InitializeConditions for Iterator SubSystem: '<S7>/While Iterator Subsystem' */
    /* InitializeConditions for Memory: '<S33>/Memory' */
    RaspPiPilot_DW.Memory_PreviousInput_c = RaspPiPilot_P.Memory_X0_j;

    /* End of InitializeConditions for SubSystem: '<S7>/While Iterator Subsystem' */
    /* End of Start for SubSystem: '<Root>/messageParser' */
    /* Start for Enabled SubSystem: '<Root>/Navigation' */
    /* Start for S-Function (v4l2_video_capture_sfcn): '<S6>/V4L2 Video Capture' */
    MW_videoCaptureInit(RaspPiPilot_ConstP.V4L2VideoCapture_p1, 0, 0, 0, 0, 320U,
                        240U, 2U, 2U, 1U, 0.06);

    /* Start for S-Function (sdl_video_display_sfcn): '<S6>/SDL Video Display' */
    MW_SDL_videoDisplayInit(1, 1, 1, 320, 240);

    /* End of Start for SubSystem: '<Root>/Navigation' */

    /* InitializeConditions for Enabled SubSystem: '<Root>/Navigation' */
    /* InitializeConditions for S-Function (fcncallgen): '<S6>/Function-Call Generator' incorporates:
     *  InitializeConditions for SubSystem: '<S6>/Function-Call Subsystem'
     */
    for (i = 0; i < 11; i++) {
      /* InitializeConditions for DiscreteFir: '<S8>/Generated Filter Block' */
      RaspPiPilot_DW.GeneratedFilterBlock_states[i] =
        RaspPiPilot_P.GeneratedFilterBlock_InitialS_a;

      /* InitializeConditions for DiscreteFir: '<S9>/Generated Filter Block' */
      RaspPiPilot_DW.GeneratedFilterBlock_states_g[i] =
        RaspPiPilot_P.GeneratedFilterBlock_InitialS_k;

      /* InitializeConditions for DiscreteFir: '<S16>/Generated Filter Block' */
      RaspPiPilot_DW.GeneratedFilterBlock_states_f[i] =
        RaspPiPilot_P.GeneratedFilterBlock_InitialSta;

      /* InitializeConditions for DiscreteFir: '<S17>/Generated Filter Block' */
      RaspPiPilot_DW.GeneratedFilterBlock_states_m[i] =
        RaspPiPilot_P.GeneratedFilterBlock_InitialS_e;
    }

    for (i = 0; i < 13; i++) {
      /* InitializeConditions for DiscreteFir: '<S31>/Generated Filter Block' */
      RaspPiPilot_DW.GeneratedFilterBlock_states_l[i] =
        RaspPiPilot_P.GeneratedFilterBlock_InitialS_b;

      /* InitializeConditions for DiscreteFir: '<S32>/Generated Filter Block' */
      RaspPiPilot_DW.GeneratedFilterBlock_states_j[i] =
        RaspPiPilot_P.GeneratedFilterBlock_InitialS_p;

      /* InitializeConditions for DiscreteFir: '<S30>/Generated Filter Block' */
      RaspPiPilot_DW.GeneratedFilterBlock_states_k[i] =
        RaspPiPilot_P.GeneratedFilterBlock_InitialS_f;
    }

    /* End of InitializeConditions for SubSystem: '<Root>/Navigation' */
  }

  /* InitializeConditions for UnitDelay: '<Root>/Unit Delay' */
  RaspPiPilot_DW.UnitDelay_DSTATE = RaspPiPilot_P.UnitDelay_InitialCondition;

  /* InitializeConditions for Memory: '<Root>/Memory' */
  RaspPiPilot_DW.Memory_PreviousInput[0] = RaspPiPilot_P.Memory_X0;
  RaspPiPilot_DW.Memory_PreviousInput[1] = RaspPiPilot_P.Memory_X0;
  RaspPiPilot_DW.Memory_PreviousInput[2] = RaspPiPilot_P.Memory_X0;
  RaspPiPilot_DW.Memory_PreviousInput[3] = RaspPiPilot_P.Memory_X0;

  /* InitializeConditions for Chart: '<Root>/Chart' */
  RaspPiPilot_DW.sfEvent = RaspPiPilot_CALL_EVENT;
  RaspPiPilot_DW.is_Armed = RaspPiPilot_IN_NO_ACTIVE_CHILD;
  RaspPiPilot_DW.is_Disarmed = RaspPiPilot_IN_NO_ACTIVE_CHILD;
  RaspPiPilot_DW.temporalCounter_i1 = 0U;
  RaspPiPilot_DW.is_active_c5_RaspPiPilot = 0U;
  RaspPiPilot_DW.is_c5_RaspPiPilot = RaspPiPilot_IN_NO_ACTIVE_CHILD;

  /* InitializeConditions for MATLAB Function: '<Root>/MATLAB Function' */
  RaspPiPilot_DW.spHandle_not_empty = false;
  RaspPiPilot_DW.spHandle = 0;
}

/* Model terminate function */
void RaspPiPilot_terminate(void)
{
  /* Terminate for Enabled SubSystem: '<Root>/Navigation' */
  /* Terminate for S-Function (v4l2_video_capture_sfcn): '<S6>/V4L2 Video Capture' */
  MW_videoCaptureTerminate(RaspPiPilot_ConstP.V4L2VideoCapture_p1);

  /* Terminate for S-Function (sdl_video_display_sfcn): '<S6>/SDL Video Display' */
  MW_SDL_videoDisplayTerminate(320, 240);

  /* End of Terminate for SubSystem: '<Root>/Navigation' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
