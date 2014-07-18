/*
 * File: Serial.h
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

#ifndef RTW_HEADER_Serial_h_
#define RTW_HEADER_Serial_h_
#include <string.h>
#include <float.h>
#include <stddef.h>
#ifndef Serial_COMMON_INCLUDES_
# define Serial_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "dt_info.h"
#include "ext_work.h"
#endif                                 /* Serial_COMMON_INCLUDES_ */

#include "Serial_types.h"

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
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

/* user code (top of header file) */
#include <mavlink.h>
#include <common.h>

/* Block signals (auto storage) */
typedef struct {
  real_T roll;                         /* '<S9>/MATLAB Function1' */
  real_T pitch;                        /* '<S9>/MATLAB Function1' */
  int8_T inputevents[4];               /* '<Root>/Chart' */
  uint8_T dataOut[256];                /* '<Root>/Chart' */
  uint8_T lengthOut;                   /* '<Root>/Chart' */
  boolean_T Compare;                   /* '<S3>/Compare' */
  boolean_T DataTypeConversion1;       /* '<S6>/Data Type Conversion1' */
  boolean_T DataTypeConversion2;       /* '<S6>/Data Type Conversion2' */
  boolean_T HiddenBuf_InsertedFor_Chart_at_[4];/* '<Root>/Subsystem1' */
} B_Serial_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T UnitDelay_DSTATE;             /* '<Root>/Unit Delay' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<Root>/Scope1' */

  int32_T spHandle;                    /* '<Root>/MATLAB Function' */
  int32_T sfEvent;                     /* '<Root>/Chart' */
  int8_T Chart_SubsysRanBC;            /* '<Root>/Chart' */
  int8_T Subsystem_SubsysRanBC;        /* '<Root>/Subsystem' */
  int8_T Subsystem_SubsysRanBC_f;      /* '<S5>/Subsystem' */
  uint8_T is_active_c5_Serial;         /* '<Root>/Chart' */
  uint8_T is_c5_Serial;                /* '<Root>/Chart' */
  uint8_T is_Armed;                    /* '<Root>/Chart' */
  boolean_T spHandle_not_empty;        /* '<Root>/MATLAB Function' */
  boolean_T isStable;                  /* '<Root>/Chart' */
} DW_Serial_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Chart_Trig_ZCE[4];        /* '<Root>/Chart' */
} PrevZCX_Serial_T;

/* Parameters (auto storage) */
struct P_Serial_T_ {
  uint8_T CompareToConstant_const;     /* Mask Parameter: CompareToConstant_const
                                        * Referenced by: '<S7>/Constant'
                                        */
  real_T Step_Time;                    /* Expression: 1
                                        * Referenced by: '<S6>/Step'
                                        */
  real_T Step_Y0;                      /* Expression: 0
                                        * Referenced by: '<S6>/Step'
                                        */
  real_T Step_YFinal;                  /* Expression: 1
                                        * Referenced by: '<S6>/Step'
                                        */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<Root>/Unit Delay'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S3>/Constant'
                                        */
  real_T Constant_Value_j;             /* Expression: 0
                                        * Referenced by: '<S6>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S6>/Constant1'
                                        */
  int32_T Constant_Value_d;            /* Computed Parameter: Constant_Value_d
                                        * Referenced by: '<S2>/Constant'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Serial_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;

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
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (auto storage) */
extern P_Serial_T Serial_P;

/* Block signals (auto storage) */
extern B_Serial_T Serial_B;

/* Block states (auto storage) */
extern DW_Serial_T Serial_DW;

/* External data declarations for dependent source files */

/* Zero-crossing (trigger) state */
extern PrevZCX_Serial_T Serial_PrevZCX;

/* Model entry point functions */
extern void Serial_initialize(void);
extern void Serial_output(void);
extern void Serial_update(void);
extern void Serial_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Serial_T *const Serial_M;

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
 * '<Root>' : 'Serial'
 * '<S1>'   : 'Serial/Chart'
 * '<S2>'   : 'Serial/Compare To Zero'
 * '<S3>'   : 'Serial/Compare To Zero1'
 * '<S4>'   : 'Serial/MATLAB Function'
 * '<S5>'   : 'Serial/Subsystem'
 * '<S6>'   : 'Serial/Subsystem1'
 * '<S7>'   : 'Serial/Subsystem/Compare To Constant'
 * '<S8>'   : 'Serial/Subsystem/MATLAB Function'
 * '<S9>'   : 'Serial/Subsystem/Subsystem'
 * '<S10>'  : 'Serial/Subsystem/Subsystem/MATLAB Function1'
 */
#endif                                 /* RTW_HEADER_Serial_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
