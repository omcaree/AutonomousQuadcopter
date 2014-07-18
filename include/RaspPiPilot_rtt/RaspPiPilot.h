/*
 * File: RaspPiPilot.h
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

#ifndef RTW_HEADER_RaspPiPilot_h_
#define RTW_HEADER_RaspPiPilot_h_
#include <string.h>
#include <float.h>
#include <stddef.h>
#ifndef RaspPiPilot_COMMON_INCLUDES_
# define RaspPiPilot_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "dt_info.h"
#include "ext_work.h"
#endif                                 /* RaspPiPilot_COMMON_INCLUDES_ */

#include "RaspPiPilot_types.h"

/* Shared type includes */
#include "multiword_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

/* user code (top of header file) */
#include <mavlink.h>
#include <common.h>

/* Block states (auto storage) for system '<Root>/MATLAB Function' */
typedef struct {
  int8_T MATLABFunction_SubsysRanBC;   /* '<Root>/MATLAB Function' */
} DW_MATLABFunction_RaspPiPilot_T;

/* Block signals (auto storage) */
typedef struct {
  real_T Constant3;                    /* '<Root>/Constant3' */
  real_T Constant4;                    /* '<Root>/Constant4' */
  real_T Constant5;                    /* '<Root>/Constant5' */
  real_T Constant6;                    /* '<Root>/Constant6' */
  real_T roll;                         /* '<S39>/MATLAB Function1' */
  real_T TmpSignalConversionAtSFunctionI[4];/* '<Root>/Chart' */
  uint8_T dataOut[256];                /* '<Root>/Chart' */
  uint8_T lengthOut;                   /* '<Root>/Chart' */
  boolean_T Compare;                   /* '<S3>/Compare' */
  boolean_T Constant1;                 /* '<Root>/Constant1' */
  boolean_T Constant2;                 /* '<Root>/Constant2' */
  boolean_T LogicalOperator;           /* '<Root>/Logical Operator' */
} B_RaspPiPilot_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T UnitDelay_DSTATE;             /* '<Root>/Unit Delay' */
  real_T Memory_PreviousInput[4];      /* '<Root>/Memory' */
  int32_T spHandle;                    /* '<Root>/Data Store Memory' */
  int32_T Memory_PreviousInput_n;      /* '<S36>/Memory' */
  int32_T sfEvent;                     /* '<Root>/Chart' */
  uint16_T temporalCounter_i1;         /* '<Root>/Chart' */
  int8_T messageParser_SubsysRanBC;    /* '<Root>/messageParser' */
  int8_T attitudeParser_SubsysRanBC;   /* '<S36>/attitudeParser' */
  int8_T resultParser_SubsysRanBC;     /* '<S36>/resultParser' */
  int8_T stringParser_SubsysRanBC;     /* '<S36>/stringParser' */
  int8_T statusParser_SubsysRanBC;     /* '<S36>/statusParser' */
  int8_T heartBeatParser_SubsysRanBC;  /* '<S36>/heartBeatParser' */
  uint8_T is_active_c5_RaspPiPilot;    /* '<Root>/Chart' */
  uint8_T is_c5_RaspPiPilot;           /* '<Root>/Chart' */
  uint8_T is_Armed;                    /* '<Root>/Chart' */
  boolean_T isStable;                  /* '<Root>/Chart' */
  DW_MATLABFunction_RaspPiPilot_T sf_MATLABFunction;/* '<Root>/MATLAB Function' */
} DW_RaspPiPilot_T;

/* Parameters (auto storage) */
struct P_RaspPiPilot_T_ {
  int32_T CompareToConstant3_const;    /* Mask Parameter: CompareToConstant3_const
                                        * Referenced by: '<S37>/Constant'
                                        */
  real_T Constant3_Value;              /* Expression: 1500
                                        * Referenced by: '<Root>/Constant3'
                                        */
  real_T Constant4_Value;              /* Expression: 1500
                                        * Referenced by: '<Root>/Constant4'
                                        */
  real_T Constant5_Value;              /* Expression: 1000
                                        * Referenced by: '<Root>/Constant5'
                                        */
  real_T Constant6_Value;              /* Expression: 1500
                                        * Referenced by: '<Root>/Constant6'
                                        */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<Root>/Unit Delay'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S3>/Constant'
                                        */
  real_T Memory_X0;                    /* Expression: 0
                                        * Referenced by: '<Root>/Memory'
                                        */
  real_T Constant_Value_p;             /* Expression: 0
                                        * Referenced by: '<S4>/Constant'
                                        */
  int32_T Memory_X0_k;                 /* Computed Parameter: Memory_X0_k
                                        * Referenced by: '<S36>/Memory'
                                        */
  int32_T Constant_Value_d;            /* Computed Parameter: Constant_Value_d
                                        * Referenced by: '<S2>/Constant'
                                        */
  int32_T DataStoreMemory_InitialValue;/* Computed Parameter: DataStoreMemory_InitialValue
                                        * Referenced by: '<Root>/Data Store Memory'
                                        */
  boolean_T Constant1_Value;           /* Computed Parameter: Constant1_Value
                                        * Referenced by: '<Root>/Constant1'
                                        */
  boolean_T Constant2_Value;           /* Computed Parameter: Constant2_Value
                                        * Referenced by: '<Root>/Constant2'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_RaspPiPilot_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (auto storage) */
extern P_RaspPiPilot_T RaspPiPilot_P;

/* Block signals (auto storage) */
extern B_RaspPiPilot_T RaspPiPilot_B;

/* Block states (auto storage) */
extern DW_RaspPiPilot_T RaspPiPilot_DW;

/* Model entry point functions */
extern void RaspPiPilot_initialize(void);
extern void RaspPiPilot_output(void);
extern void RaspPiPilot_update(void);
extern void RaspPiPilot_terminate(void);

/* Real-time Model object */
extern RT_MODEL_RaspPiPilot_T *const RaspPiPilot_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'RaspPiPilot'
 * '<S1>'   : 'RaspPiPilot/Chart'
 * '<S2>'   : 'RaspPiPilot/Compare To Zero'
 * '<S3>'   : 'RaspPiPilot/Compare To Zero1'
 * '<S4>'   : 'RaspPiPilot/Compare To Zero2'
 * '<S5>'   : 'RaspPiPilot/MATLAB Function'
 * '<S6>'   : 'RaspPiPilot/MATLAB Function1'
 * '<S7>'   : 'RaspPiPilot/MATLAB Function2'
 * '<S8>'   : 'RaspPiPilot/Navigation'
 * '<S9>'   : 'RaspPiPilot/messageParser'
 * '<S10>'  : 'RaspPiPilot/Navigation/ 2'
 * '<S11>'  : 'RaspPiPilot/Navigation/ 3'
 * '<S12>'  : 'RaspPiPilot/Navigation/Function-Call Subsystem'
 * '<S13>'  : 'RaspPiPilot/Navigation/MATLAB Function1'
 * '<S14>'  : 'RaspPiPilot/Navigation/Function-Call Subsystem/Compare To Constant'
 * '<S15>'  : 'RaspPiPilot/Navigation/Function-Call Subsystem/For Each Subsystem'
 * '<S16>'  : 'RaspPiPilot/Navigation/Function-Call Subsystem/MATLAB Function'
 * '<S17>'  : 'RaspPiPilot/Navigation/Function-Call Subsystem/Subsystem'
 * '<S18>'  : 'RaspPiPilot/Navigation/Function-Call Subsystem/parseLandMark'
 * '<S19>'  : 'RaspPiPilot/Navigation/Function-Call Subsystem/Subsystem/MATLAB Function'
 * '<S20>'  : 'RaspPiPilot/Navigation/Function-Call Subsystem/parseLandMark/Detect Colors'
 * '<S21>'  : 'RaspPiPilot/Navigation/Function-Call Subsystem/parseLandMark/Lowpass Filter'
 * '<S22>'  : 'RaspPiPilot/Navigation/Function-Call Subsystem/parseLandMark/Lowpass Filter1'
 * '<S23>'  : 'RaspPiPilot/Navigation/Function-Call Subsystem/parseLandMark/attitudeFix'
 * '<S24>'  : 'RaspPiPilot/Navigation/Function-Call Subsystem/parseLandMark/projectionFix'
 * '<S25>'  : 'RaspPiPilot/Navigation/Function-Call Subsystem/parseLandMark/Detect Colors/Compare To Constant1'
 * '<S26>'  : 'RaspPiPilot/Navigation/Function-Call Subsystem/parseLandMark/Detect Colors/Compare To Constant2'
 * '<S27>'  : 'RaspPiPilot/Navigation/Function-Call Subsystem/parseLandMark/Detect Colors/Compare To Constant3'
 * '<S28>'  : 'RaspPiPilot/Navigation/Function-Call Subsystem/parseLandMark/Detect Colors/Compare To Constant4'
 * '<S29>'  : 'RaspPiPilot/Navigation/Function-Call Subsystem/parseLandMark/Detect Colors/Compare To Constant5'
 * '<S30>'  : 'RaspPiPilot/Navigation/Function-Call Subsystem/parseLandMark/Detect Colors/Compare To Constant6'
 * '<S31>'  : 'RaspPiPilot/Navigation/Function-Call Subsystem/parseLandMark/Detect Colors/MATLAB Function2'
 * '<S32>'  : 'RaspPiPilot/Navigation/Function-Call Subsystem/parseLandMark/attitudeFix/MATLAB Function'
 * '<S33>'  : 'RaspPiPilot/Navigation/Function-Call Subsystem/parseLandMark/projectionFix/Lowpass Filter'
 * '<S34>'  : 'RaspPiPilot/Navigation/Function-Call Subsystem/parseLandMark/projectionFix/Lowpass Filter1'
 * '<S35>'  : 'RaspPiPilot/Navigation/Function-Call Subsystem/parseLandMark/projectionFix/Lowpass Filter2'
 * '<S36>'  : 'RaspPiPilot/messageParser/While Iterator Subsystem'
 * '<S37>'  : 'RaspPiPilot/messageParser/While Iterator Subsystem/Compare To Constant3'
 * '<S38>'  : 'RaspPiPilot/messageParser/While Iterator Subsystem/MATLAB Function'
 * '<S39>'  : 'RaspPiPilot/messageParser/While Iterator Subsystem/attitudeParser'
 * '<S40>'  : 'RaspPiPilot/messageParser/While Iterator Subsystem/heartBeatParser'
 * '<S41>'  : 'RaspPiPilot/messageParser/While Iterator Subsystem/resultParser'
 * '<S42>'  : 'RaspPiPilot/messageParser/While Iterator Subsystem/statusParser'
 * '<S43>'  : 'RaspPiPilot/messageParser/While Iterator Subsystem/stringParser'
 * '<S44>'  : 'RaspPiPilot/messageParser/While Iterator Subsystem/attitudeParser/MATLAB Function1'
 * '<S45>'  : 'RaspPiPilot/messageParser/While Iterator Subsystem/heartBeatParser/MATLAB Function1'
 * '<S46>'  : 'RaspPiPilot/messageParser/While Iterator Subsystem/resultParser/MATLAB Function1'
 * '<S47>'  : 'RaspPiPilot/messageParser/While Iterator Subsystem/statusParser/MATLAB Function1'
 * '<S48>'  : 'RaspPiPilot/messageParser/While Iterator Subsystem/stringParser/MATLAB Function1'
 */
#endif                                 /* RTW_HEADER_RaspPiPilot_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
