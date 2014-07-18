/*
 * File: RaspPiPilot.c
 *
 * Code generated for Simulink model 'RaspPiPilot'.
 *
 * Model version                  : 1.288
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * TLC version                    : 8.6 (Jan 30 2014)
 * C/C++ source code generated on : Thu Jul 10 16:17:29 2014
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
#define RaspPiPilot_CALL_EVENT_h       (-1)
#define RaspPiPilot_IN_Armed           ((uint8_T)1U)
#define RaspPiPilot_IN_Disarmed        ((uint8_T)2U)
#define RaspPiPilot_IN_Flying          ((uint8_T)1U)
#define RaspPiPilot_IN_Initializing    ((uint8_T)3U)
#define RaspPiPilot_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define RaspPiPilot_IN_sendArm         ((uint8_T)2U)

/* Block signals (auto storage) */
B_RaspPiPilot_T RaspPiPilot_B;

/* Block states (auto storage) */
DW_RaspPiPilot_T RaspPiPilot_DW;

/* Real-time model */
RT_MODEL_RaspPiPilot_T RaspPiPilot_M_;
RT_MODEL_RaspPiPilot_T *const RaspPiPilot_M = &RaspPiPilot_M_;

/* Forward declaration for local functions */
static void RaspPiPilot_requestStreams(uint8_T data[256], uint8_T *length);

/* Output and update for function-call system: '<Root>/MATLAB Function' */
void RaspPiPilot_MATLABFunction(const uint8_T rtu_dataOut[256], uint8_T
  rtu_lengthOut, DW_MATLABFunction_RaspPiPilot_T *localDW, int32_T *rtd_spHandle)
{
  uint8_T data2[256];

  /* MATLAB Function 'MATLAB Function': '<S5>:1' */
  if (rtu_lengthOut > 0) {
    /* '<S5>:1:4' */
    /* '<S5>:1:5' */
    memcpy(&data2[0], &rtu_dataOut[0], sizeof(uint8_T) << 8U);
    write(*rtd_spHandle, data2, (uint32_T)rtu_lengthOut);
    debugg();
  }

  localDW->MATLABFunction_SubsysRanBC = 4;
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

/* Model output function */
void RaspPiPilot_output(void)
{
  uint8_T lengthOut;
  int32_T length;
  int32_T bytesRead;
  uint8_T dataRead[512];
  static const char_T b[13] = { '/', 'd', 'e', 'v', '/', 't', 't', 'y', 'A', 'M',
    'A', '0', '\x00' };

  int32_T id;
  uint8_T tempD;
  boolean_T exitg1;
  real_T roll;
  real_T pitch;
  uint8_T rtb_data[512];
  char_T b_0[13];
  int32_T qY;

  /* Reset subsysRan breadcrumbs */
  srClearBC(RaspPiPilot_DW.sf_MATLABFunction.MATLABFunction_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(RaspPiPilot_DW.attitudeParser_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(RaspPiPilot_DW.resultParser_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(RaspPiPilot_DW.stringParser_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(RaspPiPilot_DW.statusParser_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(RaspPiPilot_DW.heartBeatParser_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(RaspPiPilot_DW.messageParser_SubsysRanBC);

  /* Constant: '<Root>/Constant3' */
  RaspPiPilot_B.Constant3 = RaspPiPilot_P.Constant3_Value;

  /* Constant: '<Root>/Constant4' */
  RaspPiPilot_B.Constant4 = RaspPiPilot_P.Constant4_Value;

  /* Constant: '<Root>/Constant5' */
  RaspPiPilot_B.Constant5 = RaspPiPilot_P.Constant5_Value;

  /* Constant: '<Root>/Constant6' */
  RaspPiPilot_B.Constant6 = RaspPiPilot_P.Constant6_Value;

  /* RelationalOperator: '<S3>/Compare' incorporates:
   *  Constant: '<S3>/Constant'
   *  UnitDelay: '<Root>/Unit Delay'
   */
  RaspPiPilot_B.Compare = (RaspPiPilot_DW.UnitDelay_DSTATE !=
    RaspPiPilot_P.Constant_Value);

  /* Constant: '<Root>/Constant1' */
  RaspPiPilot_B.Constant1 = RaspPiPilot_P.Constant1_Value;

  /* Constant: '<Root>/Constant2' */
  RaspPiPilot_B.Constant2 = RaspPiPilot_P.Constant2_Value;

  /* Logic: '<Root>/Logical Operator' incorporates:
   *  Constant: '<S4>/Constant'
   *  Memory: '<Root>/Memory'
   *  RelationalOperator: '<S4>/Compare'
   *  Sum: '<Root>/Subtract'
   */
  RaspPiPilot_B.LogicalOperator = ((RaspPiPilot_B.Constant3 -
    RaspPiPilot_DW.Memory_PreviousInput[0] != RaspPiPilot_P.Constant_Value_p) ||
                                   (RaspPiPilot_B.Constant4 -
    RaspPiPilot_DW.Memory_PreviousInput[1] != RaspPiPilot_P.Constant_Value_p) ||
                                   (RaspPiPilot_B.Constant5 -
    RaspPiPilot_DW.Memory_PreviousInput[2] != RaspPiPilot_P.Constant_Value_p) ||
                                   (RaspPiPilot_B.Constant6 -
    RaspPiPilot_DW.Memory_PreviousInput[3] != RaspPiPilot_P.Constant_Value_p));

  /* SignalConversion: '<S1>/TmpSignal ConversionAt SFunction Inport1' incorporates:
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
  RaspPiPilot_DW.sfEvent = RaspPiPilot_CALL_EVENT_h;

  /* During: Chart */
  if (RaspPiPilot_DW.is_active_c5_RaspPiPilot == 0U) {
    /* Entry: Chart */
    RaspPiPilot_DW.is_active_c5_RaspPiPilot = 1U;

    /* Entry Internal: Chart */
    /* Transition: '<S1>:12' */
    RaspPiPilot_DW.is_c5_RaspPiPilot = RaspPiPilot_IN_Initializing;
    RaspPiPilot_DW.temporalCounter_i1 = 0U;

    /* Entry 'Initializing': '<S1>:1' */
    RaspPiPilot_requestStreams(RaspPiPilot_B.dataOut, &lengthOut);
    RaspPiPilot_B.lengthOut = lengthOut;

    /* MATLAB Function: '<Root>/MATLAB Function' */
    /* MATLAB Function: '<Root>/MATLAB Function' */
    /* Event: '<S1>:54' */
    RaspPiPilot_MATLABFunction(RaspPiPilot_B.dataOut, RaspPiPilot_B.lengthOut,
      &RaspPiPilot_DW.sf_MATLABFunction, &RaspPiPilot_DW.spHandle);
  } else {
    switch (RaspPiPilot_DW.is_c5_RaspPiPilot) {
     case RaspPiPilot_IN_Armed:
      /* During 'Armed': '<S1>:3' */
      if (RaspPiPilot_B.Constant2) {
        /* Transition: '<S1>:10' */
        /* Exit Internal 'Armed': '<S1>:3' */
        RaspPiPilot_DW.is_Armed = RaspPiPilot_IN_NO_ACTIVE_CHILD;
        RaspPiPilot_DW.is_c5_RaspPiPilot = RaspPiPilot_IN_Disarmed;

        /* Entry 'Disarmed': '<S1>:2' */
        /* [dataOut,lengthOut] = sendArmDisarmFun(0); */
        /* send(sendme); */
      } else if ((RaspPiPilot_DW.is_Armed != RaspPiPilot_IN_Flying) &&
                 (RaspPiPilot_DW.temporalCounter_i1 >= 500U)) {
        /* During 'sendArm': '<S1>:31' */
        /* Transition: '<S1>:32' */
        RaspPiPilot_DW.is_Armed = RaspPiPilot_IN_Flying;

        /* Entry 'Flying': '<S1>:4' */
        /* entry:navOn=1; */
      } else {
        /* During 'Flying': '<S1>:4' */
        /* if prytUpdated %~all(prytUpdated-ones(4,1)) */
        /*   [dataOut,lengthOut] =sendRPYT(PRYTvals(1),... */
        /*      PRYTvals(2),PRYTvals(3),PRYTvals(4)); */
        /* end */
      }
      break;

     case RaspPiPilot_IN_Disarmed:
      /* During 'Disarmed': '<S1>:2' */
      if (RaspPiPilot_B.Constant1) {
        /* Transition: '<S1>:5' */
        RaspPiPilot_DW.is_c5_RaspPiPilot = RaspPiPilot_IN_Armed;

        /* Entry Internal 'Armed': '<S1>:3' */
        /* Transition: '<S1>:33' */
        RaspPiPilot_DW.is_Armed = RaspPiPilot_IN_sendArm;
        RaspPiPilot_DW.temporalCounter_i1 = 0U;

        /* Entry 'sendArm': '<S1>:31' */
        /* entry:[dataOut,lengthOut] = sendArmDisarmFun(1); */
        /* send(sendme); */
      }
      break;

     default:
      /* During 'Initializing': '<S1>:1' */
      if (RaspPiPilot_B.Compare) {
        /* Transition: '<S1>:6' */
        RaspPiPilot_DW.is_c5_RaspPiPilot = RaspPiPilot_IN_Disarmed;

        /* Entry 'Disarmed': '<S1>:2' */
        /* [dataOut,lengthOut] = sendArmDisarmFun(0); */
        /* send(sendme); */
      } else {
        if (RaspPiPilot_DW.temporalCounter_i1 >= 200U) {
          /* MATLAB Function: '<Root>/MATLAB Function' */
          /* MATLAB Function: '<Root>/MATLAB Function' */
          /* Event: '<S1>:54' */
          RaspPiPilot_MATLABFunction(RaspPiPilot_B.dataOut,
            RaspPiPilot_B.lengthOut, &RaspPiPilot_DW.sf_MATLABFunction,
            &RaspPiPilot_DW.spHandle);
        }
      }
      break;
    }
  }

  /* MATLAB Function: '<Root>/MATLAB Function1' */
  /* MATLAB Function 'MATLAB Function1': '<S6>:1' */
  /* '<S6>:1:3' */
  memset(&rtb_data[0], 0, sizeof(uint8_T) << 9U);

  /* '<S6>:1:4' */
  length = 0;
  if (RaspPiPilot_DW.spHandle > 0) {
    /* '<S6>:1:6' */
    /* '<S6>:1:8' */
    memset(&dataRead[0], 0, sizeof(uint8_T) << 9U);

    /* '<S6>:1:9' */
    bytesRead = read(RaspPiPilot_DW.spHandle, dataRead, 256U);
    if (bytesRead > 0) {
      /* '<S6>:1:10' */
      /* '<S6>:1:11' */
      memcpy(&rtb_data[0], &dataRead[0], sizeof(uint8_T) << 9U);

      /* '<S6>:1:12' */
      length = bytesRead;
    }
  }

  /* Outputs for Enabled SubSystem: '<Root>/messageParser' incorporates:
   *  EnablePort: '<S9>/Enable'
   */
  /* RelationalOperator: '<S2>/Compare' incorporates:
   *  Constant: '<S2>/Constant'
   *  Constant: '<S37>/Constant'
   *  MATLAB Function: '<Root>/MATLAB Function1'
   *  MATLAB Function: '<S36>/MATLAB Function'
   *  Memory: '<S36>/Memory'
   *  RelationalOperator: '<S37>/Compare'
   *  Sum: '<S36>/Subtract'
   */
  if (length > RaspPiPilot_P.Constant_Value_d) {
    /* Outputs for Iterator SubSystem: '<S9>/While Iterator Subsystem' incorporates:
     *  WhileIterator: '<S36>/While Iterator'
     */
    bytesRead = 1;
    do {
      id = RaspPiPilot_DW.Memory_PreviousInput_n;

      /* MATLAB Function 'messageParser/While Iterator Subsystem/MATLAB Function': '<S38>:1' */
      /* '<S38>:1:2' */
      lengthOut = 21U;

      /* '<S38>:1:3' */
      qY = 1;
      if (bytesRead == 1) {
        /* '<S38>:1:4' */
        /* '<S38>:1:5' */
        id = 1;
      }

      /* '<S38>:1:8' */
      exitg1 = false;
      while ((!exitg1) && (id <= length)) {
        /* '<S38>:1:8' */
        /* '<S38>:1:10' */
        tempD = parseMavlink(rtb_data[id - 1]);
        if (tempD > 0) {
          /* '<S38>:1:11' */
          /* '<S38>:1:12' */
          lengthOut = getMessageId(id, length);
          if (id == length) {
            /* '<S38>:1:13' */
            /* '<S38>:1:14' */
            qY = id;
          } else {
            /* '<S38>:1:16' */
            qY = id + 1;
            if ((id > 0) && (qY <= 0)) {
              qY = MAX_int32_T;
            }
          }

          exitg1 = true;
        } else {
          /* '<S38>:1:20' */
          qY = id;

          /*  if itteration finishes without id trigger -  */
          id++;
        }
      }

      /* SwitchCase: '<S36>/Switch Case' incorporates:
       *  Memory: '<S36>/Memory'
       */
      switch (lengthOut) {
       case 30:
        /* Outputs for IfAction SubSystem: '<S36>/attitudeParser' incorporates:
         *  ActionPort: '<S39>/Action Port'
         */
        /* MATLAB Function: '<S39>/MATLAB Function1' */
        /* MATLAB Function 'messageParser/While Iterator Subsystem/attitudeParser/MATLAB Function1': '<S44>:1' */
        /* '<S44>:1:2' */
        roll = 0.0;

        /* '<S44>:1:3' */
        pitch = 0.0;
        getRoll(&roll);
        getPitch(&pitch);
        RaspPiPilot_B.roll = roll;

        /* End of Outputs for SubSystem: '<S36>/attitudeParser' */

        /* Update for IfAction SubSystem: '<S36>/attitudeParser' incorporates:
         *  Update for ActionPort: '<S39>/Action Port'
         */
        /* Update for SwitchCase: '<S36>/Switch Case' */
        RaspPiPilot_DW.attitudeParser_SubsysRanBC = 4;

        /* End of Update for SubSystem: '<S36>/attitudeParser' */
        break;

       case 77:
        /* Outputs for IfAction SubSystem: '<S36>/resultParser' incorporates:
         *  ActionPort: '<S41>/Action Port'
         */
        /* MATLAB Function: '<S41>/MATLAB Function1' */
        /* MATLAB Function 'messageParser/While Iterator Subsystem/resultParser/MATLAB Function1': '<S46>:1' */
        /* '<S46>:1:2' */
        lengthOut = 0U;
        getResult(&lengthOut);

        /* End of Outputs for SubSystem: '<S36>/resultParser' */

        /* Update for IfAction SubSystem: '<S36>/resultParser' incorporates:
         *  Update for ActionPort: '<S41>/Action Port'
         */
        /* Update for SwitchCase: '<S36>/Switch Case' */
        RaspPiPilot_DW.resultParser_SubsysRanBC = 4;

        /* End of Update for SubSystem: '<S36>/resultParser' */
        break;

       case 253:
        /* Outputs for IfAction SubSystem: '<S36>/stringParser' incorporates:
         *  ActionPort: '<S43>/Action Port'
         */
        /* MATLAB Function: '<S43>/MATLAB Function1' */
        /* MATLAB Function 'messageParser/While Iterator Subsystem/stringParser/MATLAB Function1': '<S48>:1' */
        getString();

        /* End of Outputs for SubSystem: '<S36>/stringParser' */

        /* Update for IfAction SubSystem: '<S36>/stringParser' incorporates:
         *  Update for ActionPort: '<S43>/Action Port'
         */
        /* Update for SwitchCase: '<S36>/Switch Case' */
        RaspPiPilot_DW.stringParser_SubsysRanBC = 4;

        /* End of Update for SubSystem: '<S36>/stringParser' */
        break;

       case 1:
        /* Outputs for IfAction SubSystem: '<S36>/statusParser' incorporates:
         *  ActionPort: '<S42>/Action Port'
         */
        /* MATLAB Function: '<S42>/MATLAB Function1' */
        /* MATLAB Function 'messageParser/While Iterator Subsystem/statusParser/MATLAB Function1': '<S47>:1' */
        parseSysStatus();

        /* End of Outputs for SubSystem: '<S36>/statusParser' */

        /* Update for IfAction SubSystem: '<S36>/statusParser' incorporates:
         *  Update for ActionPort: '<S42>/Action Port'
         */
        /* Update for SwitchCase: '<S36>/Switch Case' */
        RaspPiPilot_DW.statusParser_SubsysRanBC = 4;

        /* End of Update for SubSystem: '<S36>/statusParser' */
        break;

       case 0:
        /* Outputs for IfAction SubSystem: '<S36>/heartBeatParser' incorporates:
         *  ActionPort: '<S40>/Action Port'
         */
        /* MATLAB Function: '<S40>/MATLAB Function1' */
        /* MATLAB Function 'messageParser/While Iterator Subsystem/heartBeatParser/MATLAB Function1': '<S45>:1' */
        /* '<S45>:1:5' */
        parseHeartBeat();

        /* End of Outputs for SubSystem: '<S36>/heartBeatParser' */

        /* Update for IfAction SubSystem: '<S36>/heartBeatParser' incorporates:
         *  Update for ActionPort: '<S40>/Action Port'
         */
        /* Update for SwitchCase: '<S36>/Switch Case' */
        /* '<S45>:1:6' */
        RaspPiPilot_DW.heartBeatParser_SubsysRanBC = 4;

        /* End of Update for SubSystem: '<S36>/heartBeatParser' */
        break;
      }

      /* End of SwitchCase: '<S36>/Switch Case' */

      /* Update for Memory: '<S36>/Memory' */
      RaspPiPilot_DW.Memory_PreviousInput_n = qY;
      bytesRead++;
    } while ((length - qY > RaspPiPilot_P.CompareToConstant3_const) &&
             (bytesRead <= 100));

    /* End of Outputs for SubSystem: '<S9>/While Iterator Subsystem' */
    srUpdateBC(RaspPiPilot_DW.messageParser_SubsysRanBC);
  }

  /* End of RelationalOperator: '<S2>/Compare' */
  /* End of Outputs for SubSystem: '<Root>/messageParser' */

  /* MATLAB Function: '<Root>/MATLAB Function2' */
  /* MATLAB Function 'MATLAB Function2': '<S7>:1' */
  /* '<S7>:1:6' */
  if (RaspPiPilot_DW.spHandle == -1) {
    /* '<S7>:1:4' */
    /* '<S7>:1:5' */
    RaspPiPilot_DW.spHandle = 0;

    /* '<S7>:1:6' */
    for (length = 0; length < 13; length++) {
      b_0[length] = b[length];
    }

    RaspPiPilot_DW.spHandle = setupSerialPort(b_0, 57600U);
  }

  /* End of MATLAB Function: '<Root>/MATLAB Function2' */
}

/* Model update function */
void RaspPiPilot_update(void)
{
  /* Update for UnitDelay: '<Root>/Unit Delay' */
  RaspPiPilot_DW.UnitDelay_DSTATE = RaspPiPilot_B.roll;

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
}

/* Model initialize function */
void RaspPiPilot_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)RaspPiPilot_M, 0,
                sizeof(RT_MODEL_RaspPiPilot_T));
  rtmSetTFinal(RaspPiPilot_M, -1);
  RaspPiPilot_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  RaspPiPilot_M->Sizes.checksums[0] = (1892813357U);
  RaspPiPilot_M->Sizes.checksums[1] = (3751393110U);
  RaspPiPilot_M->Sizes.checksums[2] = (3669874523U);
  RaspPiPilot_M->Sizes.checksums[3] = (3560854390U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[18];
    RaspPiPilot_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = (sysRanDType *)
      &RaspPiPilot_DW.sf_MATLABFunction.MATLABFunction_SubsysRanBC;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = (sysRanDType *)&RaspPiPilot_DW.messageParser_SubsysRanBC;
    systemRan[6] = (sysRanDType *)&RaspPiPilot_DW.attitudeParser_SubsysRanBC;
    systemRan[7] = (sysRanDType *)&RaspPiPilot_DW.attitudeParser_SubsysRanBC;
    systemRan[8] = (sysRanDType *)&RaspPiPilot_DW.heartBeatParser_SubsysRanBC;
    systemRan[9] = (sysRanDType *)&RaspPiPilot_DW.heartBeatParser_SubsysRanBC;
    systemRan[10] = (sysRanDType *)&RaspPiPilot_DW.resultParser_SubsysRanBC;
    systemRan[11] = (sysRanDType *)&RaspPiPilot_DW.resultParser_SubsysRanBC;
    systemRan[12] = (sysRanDType *)&RaspPiPilot_DW.statusParser_SubsysRanBC;
    systemRan[13] = (sysRanDType *)&RaspPiPilot_DW.statusParser_SubsysRanBC;
    systemRan[14] = (sysRanDType *)&RaspPiPilot_DW.stringParser_SubsysRanBC;
    systemRan[15] = (sysRanDType *)&RaspPiPilot_DW.stringParser_SubsysRanBC;
    systemRan[16] = (sysRanDType *)&RaspPiPilot_DW.messageParser_SubsysRanBC;
    systemRan[17] = (sysRanDType *)&RaspPiPilot_DW.messageParser_SubsysRanBC;
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
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Start for Constant: '<Root>/Constant1' */
  RaspPiPilot_B.Constant1 = RaspPiPilot_P.Constant1_Value;

  /* Start for Constant: '<Root>/Constant2' */
  RaspPiPilot_B.Constant2 = RaspPiPilot_P.Constant2_Value;

  /* Start for Enabled SubSystem: '<Root>/messageParser' */
  /* InitializeConditions for Iterator SubSystem: '<S9>/While Iterator Subsystem' */
  /* InitializeConditions for Memory: '<S36>/Memory' */
  RaspPiPilot_DW.Memory_PreviousInput_n = RaspPiPilot_P.Memory_X0_k;

  /* End of InitializeConditions for SubSystem: '<S9>/While Iterator Subsystem' */
  /* End of Start for SubSystem: '<Root>/messageParser' */

  /* Start for DataStoreMemory: '<Root>/Data Store Memory' */
  RaspPiPilot_DW.spHandle = RaspPiPilot_P.DataStoreMemory_InitialValue;

  /* InitializeConditions for UnitDelay: '<Root>/Unit Delay' */
  RaspPiPilot_DW.UnitDelay_DSTATE = RaspPiPilot_P.UnitDelay_InitialCondition;

  /* InitializeConditions for Memory: '<Root>/Memory' */
  RaspPiPilot_DW.Memory_PreviousInput[0] = RaspPiPilot_P.Memory_X0;
  RaspPiPilot_DW.Memory_PreviousInput[1] = RaspPiPilot_P.Memory_X0;
  RaspPiPilot_DW.Memory_PreviousInput[2] = RaspPiPilot_P.Memory_X0;
  RaspPiPilot_DW.Memory_PreviousInput[3] = RaspPiPilot_P.Memory_X0;

  /* InitializeConditions for Chart: '<Root>/Chart' */
  RaspPiPilot_DW.sfEvent = RaspPiPilot_CALL_EVENT_h;
  RaspPiPilot_DW.is_Armed = RaspPiPilot_IN_NO_ACTIVE_CHILD;
  RaspPiPilot_DW.temporalCounter_i1 = 0U;
  RaspPiPilot_DW.is_active_c5_RaspPiPilot = 0U;
  RaspPiPilot_DW.is_c5_RaspPiPilot = RaspPiPilot_IN_NO_ACTIVE_CHILD;
}

/* Model terminate function */
void RaspPiPilot_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
