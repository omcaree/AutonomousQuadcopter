/*
 * File: Serial.c
 *
 * Code generated for Simulink model 'Serial'.
 *
 * Model version                  : 1.52
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * TLC version                    : 8.6 (Jan 30 2014)
 * C/C++ source code generated on : Thu Jul 03 10:33:49 2014
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
#define Serial_IN_Armed                ((uint8_T)1U)
#define Serial_IN_Disarmed             ((uint8_T)2U)
#define Serial_IN_Flying               ((uint8_T)1U)
#define Serial_IN_Initializing         ((uint8_T)3U)
#define Serial_IN_NO_ACTIVE_CHILD      ((uint8_T)0U)
#define Serial_event_arm               (2)
#define Serial_event_dataReceived      (1)
#define Serial_event_disarm            (3)
#define Serial_event_initialise        (0)

/* Block signals (auto storage) */
B_Serial_T Serial_B;

/* Block states (auto storage) */
DW_Serial_T Serial_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_Serial_T Serial_PrevZCX;

/* Real-time model */
RT_MODEL_Serial_T Serial_M_;
RT_MODEL_Serial_T *const Serial_M = &Serial_M_;

/* Forward declaration for local functions */
static void Serial_requestStreams(uint8_T data[256], uint8_T *length);
static void Serial_chartstep_c5_Serial(void);

/* Function for Chart: '<Root>/Chart' */
static void Serial_requestStreams(uint8_T data[256], uint8_T *length)
{
  int32_T tmp;

  /* MATLAB Function 'requestStreams': '<S1>:14' */
  /* '<S1>:14:2' */
  memset(&data[0], 0, sizeof(uint8_T) << 8U);

  /* '<S1>:14:6' */
  *length = requestAttitude(data);

  /* '<S1>:14:7' */
  tmp = (int32_T)(*length + 8U);
  if ((uint32_T)tmp > 255U) {
    tmp = 255;
  }

  *length = (uint8_T)tmp;

  /* '<S1>:14:8' */
}

/* Function for Chart: '<Root>/Chart' */
static void Serial_chartstep_c5_Serial(void)
{
  uint8_T lengthOut;

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
      if (Serial_DW.sfEvent == Serial_event_disarm) {
        /* Transition: '<S1>:10' */
        /* Exit Internal 'Armed': '<S1>:3' */
        Serial_DW.is_Armed = Serial_IN_NO_ACTIVE_CHILD;
        Serial_DW.is_c5_Serial = Serial_IN_Disarmed;
      } else {
        /* During 'Flying': '<S1>:4' */
      }
      break;

     case Serial_IN_Disarmed:
      /* During 'Disarmed': '<S1>:2' */
      if (Serial_DW.sfEvent == Serial_event_arm) {
        /* Transition: '<S1>:5' */
        Serial_DW.is_c5_Serial = Serial_IN_Armed;

        /* Entry Internal 'Armed': '<S1>:3' */
        Serial_DW.is_Armed = Serial_IN_Flying;
      }
      break;

     default:
      /* During 'Initializing': '<S1>:1' */
      if (Serial_DW.sfEvent == Serial_event_dataReceived) {
        /* Transition: '<S1>:6' */
        /* Exit 'Initializing': '<S1>:1' */
        Serial_B.lengthOut = 0U;
        Serial_DW.is_c5_Serial = Serial_IN_Disarmed;
      }
      break;
    }
  }
}

/* Model output function */
void Serial_output(void)
{
  real_T currentTime;
  uint8_T lengthOut;
  int32_T length;
  int32_T bytesRead;
  uint8_T dataRead[256];
  static const char_T b[13] = { '/', 'd', 'e', 'v', '/', 't', 't', 'y', 'A', 'M',
    'A', '0', '\x00' };

  uint8_T tempD;
  real_T pitch;
  uint8_T rtb_data[256];
  char_T b_0[13];
  boolean_T zcEvent_idx_0;
  boolean_T zcEvent_idx_1;
  boolean_T zcEvent_idx_2;
  boolean_T zcEvent_idx_3;

  /* Reset subsysRan breadcrumbs */
  srClearBC(Serial_DW.Chart_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Serial_DW.Subsystem_SubsysRanBC_f);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Serial_DW.Subsystem_SubsysRanBC);

  /* Step: '<S6>/Step' */
  currentTime = Serial_M->Timing.t[0];

  /* RelationalOperator: '<S3>/Compare' incorporates:
   *  Constant: '<S3>/Constant'
   *  UnitDelay: '<Root>/Unit Delay'
   */
  Serial_B.Compare = (Serial_DW.UnitDelay_DSTATE != Serial_P.Constant_Value);

  /* DataTypeConversion: '<S6>/Data Type Conversion1' incorporates:
   *  Constant: '<S6>/Constant'
   */
  Serial_B.DataTypeConversion1 = (Serial_P.Constant_Value_j != 0.0);

  /* DataTypeConversion: '<S6>/Data Type Conversion2' incorporates:
   *  Constant: '<S6>/Constant1'
   */
  Serial_B.DataTypeConversion2 = (Serial_P.Constant1_Value != 0.0);

  /* Step: '<S6>/Step' */
  if (currentTime < Serial_P.Step_Time) {
    /* SignalConversion: '<Root>/HiddenBuf_InsertedFor_Chart_at_inport_0' incorporates:
     *  DataTypeConversion: '<S6>/Data Type Conversion'
     */
    Serial_B.HiddenBuf_InsertedFor_Chart_at_[0] = (Serial_P.Step_Y0 != 0.0);
  } else {
    /* SignalConversion: '<Root>/HiddenBuf_InsertedFor_Chart_at_inport_0' incorporates:
     *  DataTypeConversion: '<S6>/Data Type Conversion'
     */
    Serial_B.HiddenBuf_InsertedFor_Chart_at_[0] = (Serial_P.Step_YFinal != 0.0);
  }

  /* SignalConversion: '<Root>/HiddenBuf_InsertedFor_Chart_at_inport_0' */
  Serial_B.HiddenBuf_InsertedFor_Chart_at_[1] = Serial_B.Compare;
  Serial_B.HiddenBuf_InsertedFor_Chart_at_[2] = Serial_B.DataTypeConversion1;
  Serial_B.HiddenBuf_InsertedFor_Chart_at_[3] = Serial_B.DataTypeConversion2;

  /* Chart: '<Root>/Chart' incorporates:
   *  TriggerPort: '<S1>/ input events '
   */
  zcEvent_idx_0 = (Serial_B.HiddenBuf_InsertedFor_Chart_at_[0] &&
                   (Serial_PrevZCX.Chart_Trig_ZCE[0] != POS_ZCSIG));
  zcEvent_idx_1 = (Serial_B.HiddenBuf_InsertedFor_Chart_at_[1] &&
                   (Serial_PrevZCX.Chart_Trig_ZCE[1] != POS_ZCSIG));
  zcEvent_idx_2 = (Serial_B.HiddenBuf_InsertedFor_Chart_at_[2] &&
                   (Serial_PrevZCX.Chart_Trig_ZCE[2] != POS_ZCSIG));
  zcEvent_idx_3 = (Serial_B.HiddenBuf_InsertedFor_Chart_at_[3] &&
                   (Serial_PrevZCX.Chart_Trig_ZCE[3] != POS_ZCSIG));
  if (zcEvent_idx_0 || zcEvent_idx_1 || zcEvent_idx_2 || zcEvent_idx_3) {
    Serial_B.inputevents[0] = (int8_T)zcEvent_idx_0;
    Serial_B.inputevents[1] = (int8_T)zcEvent_idx_1;
    Serial_B.inputevents[2] = (int8_T)zcEvent_idx_2;
    Serial_B.inputevents[3] = (int8_T)zcEvent_idx_3;

    /* Gateway: Chart */
    if (Serial_B.inputevents[0U] == 1) {
      /* Event: '<S1>:19' */
      Serial_DW.sfEvent = Serial_event_initialise;
      Serial_chartstep_c5_Serial();
    }

    if (Serial_B.inputevents[1U] == 1) {
      /* Event: '<S1>:7' */
      Serial_DW.sfEvent = Serial_event_dataReceived;
      Serial_chartstep_c5_Serial();
    }

    if (Serial_B.inputevents[2U] == 1) {
      /* Event: '<S1>:9' */
      Serial_DW.sfEvent = Serial_event_arm;
      Serial_chartstep_c5_Serial();
    }

    if (Serial_B.inputevents[3U] == 1) {
      /* Event: '<S1>:11' */
      Serial_DW.sfEvent = Serial_event_disarm;
      Serial_chartstep_c5_Serial();
    }

    Serial_DW.Chart_SubsysRanBC = 4;
  }

  Serial_PrevZCX.Chart_Trig_ZCE[0] = (uint8_T)
    (Serial_B.HiddenBuf_InsertedFor_Chart_at_[0] ? (int32_T)POS_ZCSIG : (int32_T)
     ZERO_ZCSIG);
  Serial_PrevZCX.Chart_Trig_ZCE[1] = (uint8_T)
    (Serial_B.HiddenBuf_InsertedFor_Chart_at_[1] ? (int32_T)POS_ZCSIG : (int32_T)
     ZERO_ZCSIG);
  Serial_PrevZCX.Chart_Trig_ZCE[2] = (uint8_T)
    (Serial_B.HiddenBuf_InsertedFor_Chart_at_[2] ? (int32_T)POS_ZCSIG : (int32_T)
     ZERO_ZCSIG);
  Serial_PrevZCX.Chart_Trig_ZCE[3] = (uint8_T)
    (Serial_B.HiddenBuf_InsertedFor_Chart_at_[3] ? (int32_T)POS_ZCSIG : (int32_T)
     ZERO_ZCSIG);

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
   *  Constant: '<S7>/Constant'
   *  MATLAB Function: '<Root>/MATLAB Function'
   *  MATLAB Function: '<S5>/MATLAB Function'
   *  RelationalOperator: '<S7>/Compare'
   */
  if (length > Serial_P.Constant_Value_d) {
    /* MATLAB Function: '<S5>/MATLAB Function' */
    /* MATLAB Function 'Subsystem/MATLAB Function': '<S8>:1' */
    /* '<S8>:1:2' */
    lengthOut = 0U;

    /* '<S8>:1:4' */
    for (bytesRead = 1; bytesRead <= length; bytesRead++) {
      /* '<S8>:1:4' */
      /* '<S8>:1:6' */
      tempD = parseMavlink(rtb_data[bytesRead - 1]);
      if (tempD > 0) {
        /* '<S8>:1:7' */
        /* '<S8>:1:8' */
        lengthOut = getMessageId();
      }
    }

    /* Outputs for Enabled SubSystem: '<S5>/Subsystem' incorporates:
     *  EnablePort: '<S9>/Enable'
     */
    if (lengthOut == Serial_P.CompareToConstant_const) {
      /* MATLAB Function: '<S9>/MATLAB Function1' */
      /* MATLAB Function 'Subsystem/Subsystem/MATLAB Function1': '<S10>:1' */
      /* '<S10>:1:2' */
      currentTime = 0.0;

      /* '<S10>:1:3' */
      pitch = 0.0;
      getRoll(&currentTime);
      getPitch(&pitch);
      Serial_B.roll = currentTime;
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
  {                                    /* Sample time: [0.0s, 0.0s] */
    if ((rtmGetTFinal(Serial_M)!=-1) &&
        !((rtmGetTFinal(Serial_M)-Serial_M->Timing.t[0]) > Serial_M->Timing.t[0]
          * (DBL_EPSILON))) {
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
  Serial_M->Timing.t[0] =
    (++Serial_M->Timing.clockTick0) * Serial_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.05s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.05, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    Serial_M->Timing.clockTick1++;
  }
}

/* Model initialize function */
void Serial_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)Serial_M, 0,
                sizeof(RT_MODEL_Serial_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Serial_M->solverInfo, &Serial_M->Timing.simTimeStep);
    rtsiSetTPtr(&Serial_M->solverInfo, &rtmGetTPtr(Serial_M));
    rtsiSetStepSizePtr(&Serial_M->solverInfo, &Serial_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&Serial_M->solverInfo, (&rtmGetErrorStatus(Serial_M)));
    rtsiSetRTModelPtr(&Serial_M->solverInfo, Serial_M);
  }

  rtsiSetSimTimeStep(&Serial_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&Serial_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(Serial_M, &Serial_M->Timing.tArray[0]);
  rtmSetTFinal(Serial_M, -1);
  Serial_M->Timing.stepSize0 = 0.05;

  /* External mode info */
  Serial_M->Sizes.checksums[0] = (1456197142U);
  Serial_M->Sizes.checksums[1] = (2124258787U);
  Serial_M->Sizes.checksums[2] = (567720501U);
  Serial_M->Sizes.checksums[3] = (1919715745U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[7];
    Serial_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = (sysRanDType *)&Serial_DW.Chart_SubsysRanBC;
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

  Serial_PrevZCX.Chart_Trig_ZCE[0] = POS_ZCSIG;
  Serial_PrevZCX.Chart_Trig_ZCE[1] = POS_ZCSIG;
  Serial_PrevZCX.Chart_Trig_ZCE[2] = POS_ZCSIG;
  Serial_PrevZCX.Chart_Trig_ZCE[3] = POS_ZCSIG;

  /* InitializeConditions for UnitDelay: '<Root>/Unit Delay' */
  Serial_DW.UnitDelay_DSTATE = Serial_P.UnitDelay_InitialCondition;

  /* InitializeConditions for Chart: '<Root>/Chart' */
  Serial_DW.is_Armed = Serial_IN_NO_ACTIVE_CHILD;
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
