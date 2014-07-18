/*
 * File: Serial.c
 *
 * Code generated for Simulink model 'Serial'.
 *
 * Model version                  : 1.72
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * TLC version                    : 8.6 (Jan 30 2014)
 * C/C++ source code generated on : Thu Jul 03 14:32:29 2014
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Serial.h"
#include "Serial_private.h"
#include "Serial_dt.h"

/* Named constants for Chart: '<Root>/Chart' */
#define Serial_CALL_EVENT              (-1)
#define Serial_IN_Armed                ((uint8_T)1U)
#define Serial_IN_Disarmed             ((uint8_T)2U)
#define Serial_IN_Flying               ((uint8_T)1U)
#define Serial_IN_Initializing         ((uint8_T)3U)
#define Serial_IN_NO_ACTIVE_CHILD      ((uint8_T)0U)
#define Serial_IN_idle                 ((uint8_T)1U)
#define Serial_IN_sendArm              ((uint8_T)2U)
#define Serial_IN_sendDisarm           ((uint8_T)2U)

/* Block signals (auto storage) */
B_Serial_T Serial_B;

/* Block states (auto storage) */
DW_Serial_T Serial_DW;

/* Real-time model */
RT_MODEL_Serial_T Serial_M_;
RT_MODEL_Serial_T *const Serial_M = &Serial_M_;

/* Forward declaration for local functions */
static void Serial_sendArmDisarmFun(real_T armdisarm, uint8_T data[256], uint8_T
  *length);
static void Serial_sendRPYT(real_T R, real_T P, real_T Y, real_T T, uint8_T
  data[256], uint8_T *length);
static void Serial_requestStreams(uint8_T data[256], uint8_T *length);
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
static void Serial_sendArmDisarmFun(real_T armdisarm, uint8_T data[256], uint8_T
  *length)
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
static void Serial_sendRPYT(real_T R, real_T P, real_T Y, real_T T, uint8_T
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

/* Function for Chart: '<Root>/Chart' */
static void Serial_requestStreams(uint8_T data[256], uint8_T *length)
{
  /* MATLAB Function 'requestStreams': '<S1>:14' */
  /* '<S1>:14:2' */
  memset(&data[0], 0, sizeof(uint8_T) << 8U);

  /* '<S1>:14:6' */
  *length = requestAttitude(data);

  /* '<S1>:14:7' */
}

/* Model output function */
void Serial_output(void)
{
  uint8_T lengthOut;
  int32_T length;
  int32_T bytesRead;
  uint8_T dataRead[256];
  static const char_T b[13] = { '/', 'd', 'e', 'v', '/', 't', 't', 'y', 'A', 'M',
    'A', '0', '\x00' };

  uint8_T tempD;
  real_T roll;
  real_T pitch;
  uint8_T rtb_data[256];
  char_T b_0[13];

  /* Reset subsysRan breadcrumbs */
  srClearBC(Serial_DW.Subsystem_SubsysRanBC_f);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Serial_DW.Subsystem_SubsysRanBC);

  /* RelationalOperator: '<S3>/Compare' incorporates:
   *  Constant: '<S3>/Constant'
   *  UnitDelay: '<Root>/Unit Delay'
   */
  Serial_B.Compare = (Serial_DW.UnitDelay_DSTATE != Serial_P.Constant_Value);

  /* DataTypeConversion: '<Root>/Data Type Conversion2' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  Serial_B.DataTypeConversion2 = (Serial_P.Constant1_Value != 0.0);

  /* DataTypeConversion: '<Root>/Data Type Conversion1' incorporates:
   *  Constant: '<Root>/Constant2'
   */
  Serial_B.DataTypeConversion1 = (Serial_P.Constant2_Value != 0.0);

  /* Constant: '<Root>/Constant3' */
  Serial_B.Constant3 = Serial_P.Constant3_Value;

  /* Constant: '<Root>/Constant4' */
  Serial_B.Constant4 = Serial_P.Constant4_Value;

  /* Constant: '<Root>/Constant5' */
  Serial_B.Constant5 = Serial_P.Constant5_Value;

  /* Constant: '<Root>/Constant6' */
  Serial_B.Constant6 = Serial_P.Constant6_Value;

  /* SignalConversion: '<S1>/TmpSignal ConversionAt SFunction Inport4' incorporates:
   *  Chart: '<Root>/Chart'
   */
  Serial_B.TmpSignalConversionAtSFunctionI[0] = Serial_B.Constant3;
  Serial_B.TmpSignalConversionAtSFunctionI[1] = Serial_B.Constant4;
  Serial_B.TmpSignalConversionAtSFunctionI[2] = Serial_B.Constant5;
  Serial_B.TmpSignalConversionAtSFunctionI[3] = Serial_B.Constant6;

  /* Chart: '<Root>/Chart' */
  if (Serial_DW.temporalCounter_i1 < 31U) {
    Serial_DW.temporalCounter_i1++;
  }

  /* Gateway: Chart */
  Serial_DW.sfEvent = Serial_CALL_EVENT;

  /* During: Chart */
  if (Serial_DW.is_active_c5_Serial == 0U) {
    /* Entry: Chart */
    Serial_DW.is_active_c5_Serial = 1U;

    /* Entry Internal: Chart */
    /* Transition: '<S1>:12' */
    Serial_DW.is_c5_Serial = Serial_IN_Initializing;

    /* Entry 'Initializing': '<S1>:1' */
    Serial_requestStreams(Serial_B.dataOut, &lengthOut);
    Serial_B.lengthOut = lengthOut;
  } else {
    switch (Serial_DW.is_c5_Serial) {
     case Serial_IN_Armed:
      /* During 'Armed': '<S1>:3' */
      if (Serial_B.DataTypeConversion1) {
        /* Transition: '<S1>:10' */
        /* Exit Internal 'Armed': '<S1>:3' */
        if (Serial_DW.is_Armed == Serial_IN_sendArm) {
          /* Exit 'sendArm': '<S1>:31' */
          Serial_B.lengthOut = 0U;
          Serial_DW.is_Armed = Serial_IN_NO_ACTIVE_CHILD;
        } else {
          Serial_DW.is_Armed = Serial_IN_NO_ACTIVE_CHILD;
        }

        Serial_DW.is_c5_Serial = Serial_IN_Disarmed;

        /* Entry Internal 'Disarmed': '<S1>:2' */
        /* Transition: '<S1>:22' */
        Serial_DW.is_Disarmed = Serial_IN_sendDisarm;
        Serial_DW.temporalCounter_i1 = 0U;

        /* Entry 'sendDisarm': '<S1>:20' */
        Serial_sendArmDisarmFun(0.0, Serial_B.dataOut, &lengthOut);
        Serial_B.lengthOut = lengthOut;
      } else if (Serial_DW.is_Armed == Serial_IN_Flying) {
        /* During 'Flying': '<S1>:4' */
        Serial_sendRPYT(Serial_B.TmpSignalConversionAtSFunctionI[0],
                        Serial_B.TmpSignalConversionAtSFunctionI[1],
                        Serial_B.TmpSignalConversionAtSFunctionI[2],
                        Serial_B.TmpSignalConversionAtSFunctionI[3],
                        Serial_B.dataOut, &lengthOut);
        Serial_B.lengthOut = lengthOut;
      } else {
        /* During 'sendArm': '<S1>:31' */
        if (Serial_DW.temporalCounter_i1 >= 20U) {
          /* Transition: '<S1>:32' */
          /* Exit 'sendArm': '<S1>:31' */
          Serial_B.lengthOut = 0U;
          Serial_DW.is_Armed = Serial_IN_Flying;
        }
      }
      break;

     case Serial_IN_Disarmed:
      /* During 'Disarmed': '<S1>:2' */
      if (Serial_B.DataTypeConversion2) {
        /* Transition: '<S1>:5' */
        /* Exit Internal 'Disarmed': '<S1>:2' */
        if (Serial_DW.is_Disarmed == Serial_IN_sendDisarm) {
          /* Exit 'sendDisarm': '<S1>:20' */
          Serial_B.lengthOut = 0U;
          Serial_DW.is_Disarmed = Serial_IN_NO_ACTIVE_CHILD;
        } else {
          Serial_DW.is_Disarmed = Serial_IN_NO_ACTIVE_CHILD;
        }

        Serial_DW.is_c5_Serial = Serial_IN_Armed;

        /* Entry Internal 'Armed': '<S1>:3' */
        /* Transition: '<S1>:33' */
        Serial_DW.is_Armed = Serial_IN_sendArm;
        Serial_DW.temporalCounter_i1 = 0U;

        /* Entry 'sendArm': '<S1>:31' */
        Serial_sendArmDisarmFun(1.0, Serial_B.dataOut, &lengthOut);
        Serial_B.lengthOut = lengthOut;
      } else if ((Serial_DW.is_Disarmed != Serial_IN_idle) &&
                 (Serial_DW.temporalCounter_i1 >= 20U)) {
        /* During 'sendDisarm': '<S1>:20' */
        /* Transition: '<S1>:23' */
        /* Exit 'sendDisarm': '<S1>:20' */
        Serial_B.lengthOut = 0U;
        Serial_DW.is_Disarmed = Serial_IN_idle;
      } else {
        /* During 'idle': '<S1>:21' */
      }
      break;

     default:
      /* During 'Initializing': '<S1>:1' */
      if (Serial_B.Compare) {
        /* Transition: '<S1>:6' */
        /* Exit 'Initializing': '<S1>:1' */
        Serial_B.lengthOut = 0U;
        Serial_DW.is_c5_Serial = Serial_IN_Disarmed;

        /* Entry Internal 'Disarmed': '<S1>:2' */
        /* Transition: '<S1>:22' */
        Serial_DW.is_Disarmed = Serial_IN_sendDisarm;
        Serial_DW.temporalCounter_i1 = 0U;

        /* Entry 'sendDisarm': '<S1>:20' */
        Serial_sendArmDisarmFun(0.0, Serial_B.dataOut, &lengthOut);
        Serial_B.lengthOut = lengthOut;
      }
      break;
    }
  }

  /* MATLAB Function: '<Root>/MATLAB Function' */
  lengthOut = Serial_B.lengthOut;

  /* MATLAB Function 'MATLAB Function': '<S4>:1' */
  /* '<S4>:1:8' */
  /* '<S4>:1:3' */
  memset(&rtb_data[0], 0, sizeof(uint8_T) << 8U);

  /* '<S4>:1:4' */
  length = 0;
  if (!Serial_DW.spHandle_not_empty) {
    /* '<S4>:1:6' */
    Serial_DW.spHandle_not_empty = true;

    /* '<S4>:1:8' */
    for (bytesRead = 0; bytesRead < 13; bytesRead++) {
      b_0[bytesRead] = b[bytesRead];
    }

    Serial_DW.spHandle = setupSerialPort(b_0, 57600U);
  }

  if (Serial_DW.spHandle > 0) {
    /* '<S4>:1:10' */
    /* '<S4>:1:12' */
    memset(&dataRead[0], 0, sizeof(uint8_T) << 8U);

    /* '<S4>:1:13' */
    bytesRead = read(Serial_DW.spHandle, dataRead, 256U);
    if (bytesRead > 0) {
      /* '<S4>:1:14' */
      /* '<S4>:1:15' */
      memcpy(&rtb_data[0], &dataRead[0], sizeof(uint8_T) << 8U);

      /* '<S4>:1:16' */
      length = bytesRead;
    }

    if (lengthOut > 0) {
      /* '<S4>:1:18' */
      /* '<S4>:1:20' */
      memcpy(&dataRead[0], &Serial_B.dataOut[0], sizeof(uint8_T) << 8U);
      write(Serial_DW.spHandle, dataRead, (uint32_T)lengthOut);
    }
  }

  /* Outputs for Enabled SubSystem: '<Root>/Subsystem' incorporates:
   *  EnablePort: '<S5>/Enable'
   */
  /* RelationalOperator: '<S2>/Compare' incorporates:
   *  Constant: '<S2>/Constant'
   *  Constant: '<S6>/Constant'
   *  MATLAB Function: '<Root>/MATLAB Function'
   *  RelationalOperator: '<S6>/Compare'
   */
  if (length > Serial_P.Constant_Value_d) {
    /* MATLAB Function: '<S5>/MATLAB Function' */
    /* MATLAB Function 'Subsystem/MATLAB Function': '<S7>:1' */
    /* '<S7>:1:2' */
    lengthOut = 0U;

    /* '<S7>:1:4' */
    for (bytesRead = 1; bytesRead <= length; bytesRead++) {
      /* '<S7>:1:4' */
      /* '<S7>:1:6' */
      tempD = parseMavlink(rtb_data[bytesRead - 1]);
      if (tempD > 0) {
        /* '<S7>:1:7' */
        /* '<S7>:1:8' */
        lengthOut = getMessageId();
      }
    }

    Serial_B.messageId = lengthOut;

    /* End of MATLAB Function: '<S5>/MATLAB Function' */

    /* Outputs for Enabled SubSystem: '<S5>/Subsystem' incorporates:
     *  EnablePort: '<S8>/Enable'
     */
    if (Serial_B.messageId == Serial_P.CompareToConstant_const) {
      /* MATLAB Function: '<S8>/MATLAB Function1' */
      /* MATLAB Function 'Subsystem/Subsystem/MATLAB Function1': '<S9>:1' */
      /* '<S9>:1:2' */
      roll = 0.0;

      /* '<S9>:1:3' */
      pitch = 0.0;
      getRoll(&roll);
      getPitch(&pitch);
      Serial_B.roll = roll;
      Serial_B.pitch = pitch;
      srUpdateBC(Serial_DW.Subsystem_SubsysRanBC_f);
    }

    /* End of Outputs for SubSystem: '<S5>/Subsystem' */
    srUpdateBC(Serial_DW.Subsystem_SubsysRanBC);
  }

  /* End of RelationalOperator: '<S2>/Compare' */
  /* End of Outputs for SubSystem: '<Root>/Subsystem' */
}

/* Model update function */
void Serial_update(void)
{
  /* Update for UnitDelay: '<Root>/Unit Delay' */
  Serial_DW.UnitDelay_DSTATE = Serial_B.pitch;

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.05s, 0.0s] */
    if ((rtmGetTFinal(Serial_M)!=-1) &&
        !((rtmGetTFinal(Serial_M)-Serial_M->Timing.taskTime0) >
          Serial_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(Serial_M, "Simulation finished");
    }

    if (rtmGetStopRequested(Serial_M)) {
      rtmSetErrorStatus(Serial_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  Serial_M->Timing.taskTime0 =
    (++Serial_M->Timing.clockTick0) * Serial_M->Timing.stepSize0;
}

/* Model initialize function */
void Serial_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)Serial_M, 0,
                sizeof(RT_MODEL_Serial_T));
  rtmSetTFinal(Serial_M, -1);
  Serial_M->Timing.stepSize0 = 0.05;

  /* External mode info */
  Serial_M->Sizes.checksums[0] = (4212426178U);
  Serial_M->Sizes.checksums[1] = (4061241107U);
  Serial_M->Sizes.checksums[2] = (3611883126U);
  Serial_M->Sizes.checksums[3] = (298091154U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[7];
    Serial_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = (sysRanDType *)&Serial_DW.Subsystem_SubsysRanBC;
    systemRan[4] = (sysRanDType *)&Serial_DW.Subsystem_SubsysRanBC_f;
    systemRan[5] = (sysRanDType *)&Serial_DW.Subsystem_SubsysRanBC_f;
    systemRan[6] = (sysRanDType *)&Serial_DW.Subsystem_SubsysRanBC;
    rteiSetModelMappingInfoPtr(Serial_M->extModeInfo,
      &Serial_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Serial_M->extModeInfo, Serial_M->Sizes.checksums);
    rteiSetTPtr(Serial_M->extModeInfo, rtmGetTPtr(Serial_M));
  }

  /* block I/O */
  (void) memset(((void *) &Serial_B), 0,
                sizeof(B_Serial_T));

  /* states (dwork) */
  (void) memset((void *)&Serial_DW, 0,
                sizeof(DW_Serial_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Serial_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* InitializeConditions for UnitDelay: '<Root>/Unit Delay' */
  Serial_DW.UnitDelay_DSTATE = Serial_P.UnitDelay_InitialCondition;

  /* InitializeConditions for Chart: '<Root>/Chart' */
  Serial_DW.sfEvent = Serial_CALL_EVENT;
  Serial_DW.is_Armed = Serial_IN_NO_ACTIVE_CHILD;
  Serial_DW.is_Disarmed = Serial_IN_NO_ACTIVE_CHILD;
  Serial_DW.temporalCounter_i1 = 0U;
  Serial_DW.is_active_c5_Serial = 0U;
  Serial_DW.is_c5_Serial = Serial_IN_NO_ACTIVE_CHILD;

  /* InitializeConditions for MATLAB Function: '<Root>/MATLAB Function' */
  Serial_DW.spHandle_not_empty = false;
  Serial_DW.spHandle = 0;
}

/* Model terminate function */
void Serial_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
