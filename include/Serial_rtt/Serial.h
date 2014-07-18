/*
 * File: Serial.h
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

#ifndef RTW_HEADER_Serial_h_
#define RTW_HEADER_Serial_h_
#include <math.h>
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
# define rtmGetT(rtm)                  ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

/* user code (top of header file) */
#include <mavlink.h>
#include <common.h>

/* Block signals (auto storage) */
typedef struct {
  real_T Constant3;                    /* '<Root>/Constant3' */
  real_T Constant4;                    /* '<Root>/Constant4' */
  real_T Constant5;                    /* '<Root>/Constant5' */
  real_T Constant6;                    /* '<Root>/Constant6' */
  real_T roll;                         /* '<S8>/MATLAB Function1' */
  real_T pitch;                        /* '<S8>/MATLAB Function1' */
  real_T TmpSignalConversionAtSFunctionI[4];/* '<Root>/Chart' */
  uint8_T messageId;                   /* '<S5>/MATLAB Function' */
  uint8_T dataOut[256];                /* '<Root>/Chart' */
  uint8_T lengthOut;                   /* '<Root>/Chart' */
  boolean_T Compare;                   /* '<S3>/Compare' */
  boolean_T DataTypeConversion2;       /* '<Root>/Data Type Conversion2' */
  boolean_T DataTypeConversion1;       /* '<Root>/Data Type Conversion1' */
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

  struct {
    void *LoggedData;
  } Scope2_PWORK;                      /* '<Root>/Scope2' */

  struct {
    void *LoggedData;
  } Scope_PWORK_a;                     /* '<S5>/Scope' */

  int32_T spHandle;                    /* '<Root>/MATLAB Function' */
  int32_T sfEvent;                     /* '<Root>/Chart' */
  int8_T Subsystem_SubsysRanBC;        /* '<Root>/Subsystem' */
  int8_T Subsystem_SubsysRanBC_f;      /* '<S5>/Subsystem' */
  uint8_T is_active_c5_Serial;         /* '<Root>/Chart' */
  uint8_T is_c5_Serial;                /* '<Root>/Chart' */
  uint8_T is_Disarmed;                 /* '<Root>/Chart' */
  uint8_T is_Armed;                    /* '<Root>/Chart' */
  uint8_T temporalCounter_i1;          /* '<Root>/Chart' */
  boolean_T spHandle_not_empty;        /* '<Root>/MATLAB Function' */
  boolean_T isStable;                  /* '<Root>/Chart' */
} DW_Serial_T;

/* Parameters (auto storage) */
struct P_Serial_T_ {
  uint8_T CompareToConstant_const;     /* Mask Parameter: CompareToConstant_const
                                        * Referenced by: '<S6>/Constant'
                                        */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<Root>/Unit Delay'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S3>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T Constant3_Value;              /* Expression: 1500
                                        * Referenced by: '<Root>/Constant3'
                                        */
  real_T Constant4_Value;              /* Expression: 1500
                                        * Referenced by: '<Root>/Constant4'
                                        */
  real_T Constant5_Value;              /* Expression: 1500
                                        * Referenced by: '<Root>/Constant5'
                                        */
  real_T Constant6_Value;              /* Expression: 1500
                                        * Referenced by: '<Root>/Constant6'
                                        */
  int32_T Constant_Value_d;            /* Computed Parameter: Constant_Value_d
                                        * Referenced by: '<S2>/Constant'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Serial_T {
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
extern P_Serial_T Serial_P;

/* Block signals (auto storage) */
extern B_Serial_T Serial_B;

/* Block states (auto storage) */
extern DW_Serial_T Serial_DW;

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
 * '<S6>'   : 'Serial/Subsystem/Compare To Constant'
 * '<S7>'   : 'Serial/Subsystem/MATLAB Function'
 * '<S8>'   : 'Serial/Subsystem/Subsystem'
 * '<S9>'   : 'Serial/Subsystem/Subsystem/MATLAB Function1'
 */
#endif                                 /* RTW_HEADER_Serial_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
