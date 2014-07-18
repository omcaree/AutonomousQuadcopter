/*
 * File: RaspPiPilot.h
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

#ifndef RTW_HEADER_RaspPiPilot_h_
#define RTW_HEADER_RaspPiPilot_h_
#include <math.h>
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
#include "v4l2_capture.h"
#include "sdl_video_display.h"
#endif                                 /* RaspPiPilot_COMMON_INCLUDES_ */

#include "RaspPiPilot_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

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
  uint8_T RateTransition2[76800];      /* '<S6>/Rate Transition2' */
  uint8_T RateTransition1[76800];      /* '<S6>/Rate Transition1' */
  uint8_T RateTransition[76800];       /* '<S6>/Rate Transition' */
  uint8_T Selector3[76800];            /* '<S19>/Selector3' */
  uint8_T Selector4[76800];            /* '<S19>/Selector4' */
  uint8_T Selector2[76800];            /* '<S19>/Selector2' */
  uint8_T blueIntensity[76800];        /* '<S10>/MATLAB Function' */
  uint8_T V4L2VideoCapture_o3[76800];  /* '<S6>/V4L2 Video Capture' */
  uint8_T V4L2VideoCapture_o2[76800];  /* '<S6>/V4L2 Video Capture' */
  uint8_T V4L2VideoCapture_o1[76800];  /* '<S6>/V4L2 Video Capture' */
  uint8_T b_data[76800];
  real_T Constant3;                    /* '<Root>/Constant3' */
  real_T Constant4;                    /* '<Root>/Constant4' */
  real_T Constant5;                    /* '<Root>/Constant5' */
  real_T Constant6;                    /* '<Root>/Constant6' */
  real_T roll;                         /* '<S41>/MATLAB Function1' */
  real_T pitch;                        /* '<S41>/MATLAB Function1' */
  real_T Sum1;                         /* '<S6>/Sum1' */
  real_T GeneratedFilterBlock;         /* '<S8>/Generated Filter Block' */
  real_T GeneratedFilterBlock_o;       /* '<S9>/Generated Filter Block' */
  real_T Sum[2];                       /* '<S6>/Sum' */
  real_T X[4];                         /* '<S6>/MATLAB Function1' */
  real_T SubtractImageCentre[2];       /* '<S10>/Subtract Image Centre' */
  real_T Convertpixelstodegrees[2];    /* '<S10>/Convert pixels to degrees' */
  real_T BlobAnalysis1_o2[2];          /* '<S15>/Blob Analysis1' */
  real_T Gain4[2];                     /* '<S10>/Gain4' */
  real_T MathFunction;                 /* '<S20>/Math Function' */
  real_T DataTypeConversion1;          /* '<S13>/Data Type Conversion1' */
  real_T Product1;                     /* '<S20>/Product1' */
  real_T MathFunction2;                /* '<S21>/Math Function2' */
  real_T DataTypeConversion;           /* '<S14>/Data Type Conversion' */
  real_T Product;                      /* '<S20>/Product' */
  real_T Sum5;                         /* '<S21>/Sum5' */
  real_T Gain;                         /* '<S21>/Gain' */
  real_T DataTypeConversion_l;         /* '<S15>/Data Type Conversion' */
  real_T MatrixConcatenate[8];         /* '<S10>/Matrix Concatenate' */
  real_T TrigonometricFunction;        /* '<S10>/Trigonometric Function' */
  real_T avgIntensity;                 /* '<S10>/MATLAB Function' */
  real_T TmpSignalConversionAtSFunctionI[4];/* '<Root>/Chart' */
  real_T navOn;                        /* '<Root>/Chart' */
  int32_T DataTypeConversion_d;        /* '<S33>/Data Type Conversion' */
  int32_T WhileIterator;               /* '<S33>/While Iterator' */
  int32_T id1;                         /* '<S33>/MATLAB Function' */
  int32_T BlobAnalysis_o1[16];         /* '<S19>/Blob Analysis' */
  int32_T bbox_largest[4];             /* '<S19>/MATLAB Function' */
  int32_T length;                      /* '<Root>/MATLAB Function' */
  uint8_T result;                      /* '<S42>/MATLAB Function1' */
  uint8_T messageId;                   /* '<S33>/MATLAB Function' */
  uint8_T DrawMarkers2_o1[76800];      /* '<S6>/Draw Markers2' */
  uint8_T DrawMarkers2_o2[76800];      /* '<S6>/Draw Markers2' */
  uint8_T DrawMarkers2_o3[76800];      /* '<S6>/Draw Markers2' */
  uint8_T dataOut[256];                /* '<Root>/Chart' */
  uint8_T lengthOut;                   /* '<Root>/Chart' */
  boolean_T Compare;                   /* '<S3>/Compare' */
  boolean_T DataTypeConversion2;       /* '<Root>/Data Type Conversion2' */
  boolean_T DataTypeConversion1_k;     /* '<Root>/Data Type Conversion1' */
  boolean_T Compare_c[4];              /* '<S4>/Compare' */
  boolean_T Compare_j;                 /* '<S37>/Compare' */
  boolean_T Compare_b;                 /* '<S34>/Compare' */
  boolean_T Compare_j4[76800];         /* '<S26>/Compare' */
} B_RaspPiPilot_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  uint32_T BlobAnalysis1_STACK_DW_l[76800];/* '<S15>/Blob Analysis1' */
  uint32_T BlobAnalysis1_STACK_DW[76800];/* '<S14>/Blob Analysis1' */
  uint32_T BlobAnalysis2_STACK_DW[76800];/* '<S13>/Blob Analysis2' */
  uint32_T BlobAnalysis_STACK_DW[76800];/* '<S19>/Blob Analysis' */
  int16_T BlobAnalysis1_M_PIXLIST_DW_o[76800];/* '<S15>/Blob Analysis1' */
  int16_T BlobAnalysis1_N_PIXLIST_DW_f[76800];/* '<S15>/Blob Analysis1' */
  int16_T BlobAnalysis1_M_PIXLIST_DW[76800];/* '<S14>/Blob Analysis1' */
  int16_T BlobAnalysis1_N_PIXLIST_DW[76800];/* '<S14>/Blob Analysis1' */
  int16_T BlobAnalysis2_M_PIXLIST_DW[76800];/* '<S13>/Blob Analysis2' */
  int16_T BlobAnalysis2_N_PIXLIST_DW[76800];/* '<S13>/Blob Analysis2' */
  int16_T BlobAnalysis_M_PIXLIST_DW[76800];/* '<S19>/Blob Analysis' */
  int16_T BlobAnalysis_N_PIXLIST_DW[76800];/* '<S19>/Blob Analysis' */
  uint8_T BlobAnalysis1_PAD_DW_f[77924];/* '<S15>/Blob Analysis1' */
  uint8_T BlobAnalysis1_PAD_DW[77924]; /* '<S14>/Blob Analysis1' */
  uint8_T BlobAnalysis2_PAD_DW[77924]; /* '<S13>/Blob Analysis2' */
  uint8_T BlobAnalysis_PAD_DW[77924];  /* '<S19>/Blob Analysis' */
  real_T GeneratedFilterBlock_states[11];/* '<S8>/Generated Filter Block' */
  real_T GeneratedFilterBlock_states_g[11];/* '<S9>/Generated Filter Block' */
  real_T GeneratedFilterBlock_states_f[11];/* '<S16>/Generated Filter Block' */
  real_T GeneratedFilterBlock_states_m[11];/* '<S17>/Generated Filter Block' */
  real_T GeneratedFilterBlock_states_l[13];/* '<S31>/Generated Filter Block' */
  real_T GeneratedFilterBlock_states_j[13];/* '<S32>/Generated Filter Block' */
  real_T GeneratedFilterBlock_states_k[13];/* '<S30>/Generated Filter Block' */
  real_T Memory_PreviousInput[4];      /* '<Root>/Memory' */
  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<Root>/Scope1' */

  struct {
    void *LoggedData;
  } Scope2_PWORK;                      /* '<Root>/Scope2' */

  struct {
    void *LoggedData;
  } Scope4_PWORK;                      /* '<Root>/Scope4' */

  struct {
    void *LoggedData;
  } Scope5_PWORK;                      /* '<Root>/Scope5' */

  struct {
    void *LoggedData;
  } cond_PWORK;                        /* '<S33>/cond' */

  struct {
    void *LoggedData;
  } idIn_PWORK;                        /* '<S33>/idIn' */

  struct {
    void *LoggedData;
  } idOut_PWORK;                       /* '<S33>/idOut' */

  struct {
    void *LoggedData;
  } itterator_PWORK;                   /* '<S33>/itterator ' */

  struct {
    void *LoggedData;
  } length_PWORK;                      /* '<S33>/length' */

  struct {
    void *LoggedData;
  } msgId_PWORK;                       /* '<S33>/msgId' */

  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<S42>/Scope' */

  int32_T Memory_PreviousInput_c;      /* '<S33>/Memory' */
  int32_T Selector2_DIMS1[2];          /* '<S19>/Selector2' */
  int32_T Selector3_DIMS1[2];          /* '<S19>/Selector3' */
  int32_T Selector4_DIMS1[2];          /* '<S19>/Selector4' */
  int32_T BlobAnalysis2_WALKER_DW[8];  /* '<S13>/Blob Analysis2' */
  int32_T BlobAnalysis1_WALKER_DW[8];  /* '<S14>/Blob Analysis1' */
  int32_T BlobAnalysis1_WALKER_DW_b[8];/* '<S15>/Blob Analysis1' */
  int32_T SFunction_DIMS2[2];          /* '<S15>/MATLAB Function1' */
  int32_T SFunction_DIMS2_k[2];        /* '<S14>/MATLAB Function1' */
  int32_T SFunction_DIMS2_d[2];        /* '<S13>/MATLAB Function2' */
  int32_T spHandle;                    /* '<Root>/MATLAB Function' */
  int32_T sfEvent;                     /* '<Root>/Chart' */
  uint16_T temporalCounter_i1;         /* '<Root>/Chart' */
  boolean_T UnitDelay_DSTATE;          /* '<Root>/Unit Delay' */
  int8_T messageParser_SubsysRanBC;    /* '<Root>/messageParser' */
  int8_T Navigation_SubsysRanBC;       /* '<Root>/Navigation' */
  int8_T resultParser_SubsysRanBC;     /* '<S33>/resultParser' */
  int8_T statusParser_SubsysRanBC;     /* '<S33>/statusParser' */
  int8_T statusParser1_SubsysRanBC;    /* '<S33>/statusParser1' */
  int8_T stringParser_SubsysRanBC;     /* '<S33>/stringParser' */
  int8_T attitudeParser_SubsysRanBC;   /* '<S33>/attitudeParser' */
  int8_T RateTransition_semaphoreTaken;/* '<S6>/Rate Transition' */
  int8_T RateTransition1_semaphoreTaken;/* '<S6>/Rate Transition1' */
  int8_T RateTransition2_semaphoreTaken;/* '<S6>/Rate Transition2' */
  int8_T FunctionCallSubsystem_SubsysRan;/* '<S6>/Function-Call Subsystem' */
  uint8_T RateTransition_Buffer0[76800];/* '<S6>/Rate Transition' */
  uint8_T RateTransition1_Buffer0[76800];/* '<S6>/Rate Transition1' */
  uint8_T RateTransition2_Buffer0[76800];/* '<S6>/Rate Transition2' */
  uint8_T is_active_c5_RaspPiPilot;    /* '<Root>/Chart' */
  uint8_T is_c5_RaspPiPilot;           /* '<Root>/Chart' */
  uint8_T is_Disarmed;                 /* '<Root>/Chart' */
  uint8_T is_Armed;                    /* '<Root>/Chart' */
  boolean_T spHandle_not_empty;        /* '<Root>/MATLAB Function' */
  boolean_T isStable;                  /* '<Root>/Chart' */
  boolean_T Navigation_MODE;           /* '<Root>/Navigation' */
} DW_RaspPiPilot_T;

/* Constant parameters (auto storage) */
typedef struct {
  /* Computed Parameter: BlobAnalysis_WALKER_R
   * Referenced by: '<S19>/Blob Analysis'
   */
  int32_T BlobAnalysis_WALKER_R[8];

  /* Expression: devName
   * Referenced by: '<S6>/V4L2 Video Capture'
   */
  uint8_T V4L2VideoCapture_p1[12];
} ConstP_RaspPiPilot_T;

/* Parameters (auto storage) */
struct P_RaspPiPilot_T_ {
  int32_T CompareToConstant3_const;    /* Mask Parameter: CompareToConstant3_const
                                        * Referenced by: '<S37>/Constant'
                                        */
  int32_T DrawShapes1_lineWidth;       /* Mask Parameter: DrawShapes1_lineWidth
                                        * Referenced by: '<S6>/Draw Shapes1'
                                        */
  int32_T DrawMarkers2_size;           /* Mask Parameter: DrawMarkers2_size
                                        * Referenced by: '<S6>/Draw Markers2'
                                        */
  uint32_T BlobAnalysis_minArea;       /* Mask Parameter: BlobAnalysis_minArea
                                        * Referenced by: '<S19>/Blob Analysis'
                                        */
  uint8_T DrawMarkers2_color[12];      /* Mask Parameter: DrawMarkers2_color
                                        * Referenced by: '<S6>/Draw Markers2'
                                        */
  uint8_T CompareToConstant_const;     /* Mask Parameter: CompareToConstant_const
                                        * Referenced by: '<S12>/Constant'
                                        */
  uint8_T CompareToConstant2_const;    /* Mask Parameter: CompareToConstant2_const
                                        * Referenced by: '<S22>/Constant'
                                        */
  uint8_T CompareToConstant1_const;    /* Mask Parameter: CompareToConstant1_const
                                        * Referenced by: '<S24>/Constant'
                                        */
  uint8_T CompareToConstant1_const_l;  /* Mask Parameter: CompareToConstant1_const_l
                                        * Referenced by: '<S26>/Constant'
                                        */
  uint8_T CompareToConstant1_const_p;  /* Mask Parameter: CompareToConstant1_const_p
                                        * Referenced by: '<S35>/Constant'
                                        */
  uint8_T CompareToConstant4_const;    /* Mask Parameter: CompareToConstant4_const
                                        * Referenced by: '<S38>/Constant'
                                        */
  uint8_T CompareToConstant5_const;    /* Mask Parameter: CompareToConstant5_const
                                        * Referenced by: '<S39>/Constant'
                                        */
  uint8_T CompareToConstant2_const_e;  /* Mask Parameter: CompareToConstant2_const_e
                                        * Referenced by: '<S36>/Constant'
                                        */
  uint8_T CompareToConstant_const_l;   /* Mask Parameter: CompareToConstant_const_l
                                        * Referenced by: '<S34>/Constant'
                                        */
  real_T Gain3_Gain;                   /* Expression: 1/2
                                        * Referenced by: '<S10>/Gain3'
                                        */
  real_T SubtractImageCentre_Bias[2];  /* Expression: -[240 320]/2
                                        * Referenced by: '<S10>/Subtract Image Centre'
                                        */
  real_T GeneratedFilterBlock_InitialSta;/* Expression: 0
                                          * Referenced by: '<S16>/Generated Filter Block'
                                          */
  real_T GeneratedFilterBlock_Coefficien[12];/* Expression: [0.0032276888738420255 -0.012093185057654832 -0.056871256727662273 -0.033025317279675399 0.16717851315296134 0.40566714821275895 0.40566714821275895 0.16717851315296134 -0.033025317279675399 -0.056871256727662273 -0.012093185057654832 0.0032276888738420255]
                                              * Referenced by: '<S16>/Generated Filter Block'
                                              */
  real_T GeneratedFilterBlock_InitialS_e;/* Expression: 0
                                          * Referenced by: '<S17>/Generated Filter Block'
                                          */
  real_T GeneratedFilterBlock_Coeffici_a[12];/* Expression: [0.0032276888738420255 -0.012093185057654832 -0.056871256727662273 -0.033025317279675399 0.16717851315296134 0.40566714821275895 0.40566714821275895 0.16717851315296134 -0.033025317279675399 -0.056871256727662273 -0.012093185057654832 0.0032276888738420255]
                                              * Referenced by: '<S17>/Generated Filter Block'
                                              */
  real_T Convertpixelstodegrees_Gain;  /* Expression: 0.083*2
                                        * Referenced by: '<S10>/Convert pixels to degrees'
                                        */
  real_T Gain4_Gain;                   /* Expression: pi/180.0
                                        * Referenced by: '<S10>/Gain4'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S20>/Constant'
                                        */
  real_T GeneratedFilterBlock_InitialS_b;/* Expression: 0
                                          * Referenced by: '<S31>/Generated Filter Block'
                                          */
  real_T GeneratedFilterBlock_Coeffici_h[14];/* Expression: [0.011901508381575016 0.02908797826733928 0.0025913585662860131 -0.068996275507793012 -0.050025679925086837 0.16540100530640869 0.41332778671981452 0.41332778671981452 0.16540100530640869 -0.050025679925086837 -0.068996275507793012 0.0025913585662860131 0.02908797826733928 0.011901508381575016]
                                              * Referenced by: '<S31>/Generated Filter Block'
                                              */
  real_T Convertpixelstodegrees1_Gain; /* Expression: 0.083*2
                                        * Referenced by: '<S21>/Convert pixels to degrees1'
                                        */
  real_T Gain6_Gain;                   /* Expression: pi/180.0
                                        * Referenced by: '<S21>/Gain6'
                                        */
  real_T Constant1_Value;              /* Expression: 4
                                        * Referenced by: '<S21>/Constant1'
                                        */
  real_T Constant_Value_f;             /* Expression: -0.4619
                                        * Referenced by: '<S21>/Constant'
                                        */
  real_T Gain2_Gain;                   /* Expression: 18.9/7.5*4
                                        * Referenced by: '<S21>/Gain2'
                                        */
  real_T GeneratedFilterBlock_InitialS_p;/* Expression: 0
                                          * Referenced by: '<S32>/Generated Filter Block'
                                          */
  real_T GeneratedFilterBlock_Coeffici_b[14];/* Expression: [0.011901508381575016 0.02908797826733928 0.0025913585662860131 -0.068996275507793012 -0.050025679925086837 0.16540100530640869 0.41332778671981452 0.41332778671981452 0.16540100530640869 -0.050025679925086837 -0.068996275507793012 0.0025913585662860131 0.02908797826733928 0.011901508381575016]
                                              * Referenced by: '<S32>/Generated Filter Block'
                                              */
  real_T Gain1_Gain;                   /* Expression: 18.9/7.5*4
                                        * Referenced by: '<S21>/Gain1'
                                        */
  real_T GeneratedFilterBlock_InitialS_f;/* Expression: 0
                                          * Referenced by: '<S30>/Generated Filter Block'
                                          */
  real_T GeneratedFilterBlock_Coeffic_hi[14];/* Expression: [0.011901508381575016 0.02908797826733928 0.0025913585662860131 -0.068996275507793012 -0.050025679925086837 0.16540100530640869 0.41332778671981452 0.41332778671981452 0.16540100530640869 -0.050025679925086837 -0.068996275507793012 0.0025913585662860131 0.02908797826733928 0.011901508381575016]
                                              * Referenced by: '<S30>/Generated Filter Block'
                                              */
  real_T Gain_Gain;                    /* Expression: 1/2
                                        * Referenced by: '<S21>/Gain'
                                        */
  real_T Constant_Value_k;             /* Expression: 0.19
                                        * Referenced by: '<S6>/Constant'
                                        */
  real_T GeneratedFilterBlock_InitialS_a;/* Expression: 0
                                          * Referenced by: '<S8>/Generated Filter Block'
                                          */
  real_T GeneratedFilterBlock_Coeffic_he[12];/* Expression: [0.0032276888738420255 -0.012093185057654832 -0.056871256727662273 -0.033025317279675399 0.16717851315296134 0.40566714821275895 0.40566714821275895 0.16717851315296134 -0.033025317279675399 -0.056871256727662273 -0.012093185057654832 0.0032276888738420255]
                                              * Referenced by: '<S8>/Generated Filter Block'
                                              */
  real_T GeneratedFilterBlock_InitialS_k;/* Expression: 0
                                          * Referenced by: '<S9>/Generated Filter Block'
                                          */
  real_T GeneratedFilterBlock_Coeffici_i[12];/* Expression: [0.0032276888738420255 -0.012093185057654832 -0.056871256727662273 -0.033025317279675399 0.16717851315296134 0.40566714821275895 0.40566714821275895 0.16717851315296134 -0.033025317279675399 -0.056871256727662273 -0.012093185057654832 0.0032276888738420255]
                                              * Referenced by: '<S9>/Generated Filter Block'
                                              */
  real_T Constant1_Value_d;            /* Expression: 1
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
  real_T Constant5_Value;              /* Expression: 1000
                                        * Referenced by: '<Root>/Constant5'
                                        */
  real_T Constant6_Value;              /* Expression: 1000
                                        * Referenced by: '<Root>/Constant6'
                                        */
  real_T Memory_X0;                    /* Expression: 0
                                        * Referenced by: '<Root>/Memory'
                                        */
  real_T Constant_Value_p;             /* Expression: 0
                                        * Referenced by: '<S4>/Constant'
                                        */
  int32_T Memory_X0_j;                 /* Computed Parameter: Memory_X0_j
                                        * Referenced by: '<S33>/Memory'
                                        */
  int32_T Constant_Value_d;            /* Computed Parameter: Constant_Value_d
                                        * Referenced by: '<S2>/Constant'
                                        */
  uint8_T DrawShapes1_RTP_FILLCOLOR[3];/* Computed Parameter: DrawShapes1_RTP_FILLCOLOR
                                        * Referenced by: '<S6>/Draw Shapes1'
                                        */
  boolean_T UnitDelay_InitialCondition;/* Computed Parameter: UnitDelay_InitialCondition
                                        * Referenced by: '<Root>/Unit Delay'
                                        */
  boolean_T Constant_Value_o;          /* Computed Parameter: Constant_Value_o
                                        * Referenced by: '<S3>/Constant'
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
    uint32_T clockTick1;
    uint32_T clockTick2;
    struct {
      uint8_T TID[3];
    } TaskCounters;

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

/* Constant parameters (auto storage) */
extern const ConstP_RaspPiPilot_T RaspPiPilot_ConstP;

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
 * '<S6>'   : 'RaspPiPilot/Navigation'
 * '<S7>'   : 'RaspPiPilot/messageParser'
 * '<S8>'   : 'RaspPiPilot/Navigation/ 2'
 * '<S9>'   : 'RaspPiPilot/Navigation/ 3'
 * '<S10>'  : 'RaspPiPilot/Navigation/Function-Call Subsystem'
 * '<S11>'  : 'RaspPiPilot/Navigation/MATLAB Function1'
 * '<S12>'  : 'RaspPiPilot/Navigation/Function-Call Subsystem/Compare To Constant'
 * '<S13>'  : 'RaspPiPilot/Navigation/Function-Call Subsystem/Detect Green'
 * '<S14>'  : 'RaspPiPilot/Navigation/Function-Call Subsystem/Detect Red'
 * '<S15>'  : 'RaspPiPilot/Navigation/Function-Call Subsystem/Detect yellow'
 * '<S16>'  : 'RaspPiPilot/Navigation/Function-Call Subsystem/Lowpass Filter'
 * '<S17>'  : 'RaspPiPilot/Navigation/Function-Call Subsystem/Lowpass Filter1'
 * '<S18>'  : 'RaspPiPilot/Navigation/Function-Call Subsystem/MATLAB Function'
 * '<S19>'  : 'RaspPiPilot/Navigation/Function-Call Subsystem/Subsystem'
 * '<S20>'  : 'RaspPiPilot/Navigation/Function-Call Subsystem/attitudeFix'
 * '<S21>'  : 'RaspPiPilot/Navigation/Function-Call Subsystem/projectionFix'
 * '<S22>'  : 'RaspPiPilot/Navigation/Function-Call Subsystem/Detect Green/Compare To Constant2'
 * '<S23>'  : 'RaspPiPilot/Navigation/Function-Call Subsystem/Detect Green/MATLAB Function2'
 * '<S24>'  : 'RaspPiPilot/Navigation/Function-Call Subsystem/Detect Red/Compare To Constant1'
 * '<S25>'  : 'RaspPiPilot/Navigation/Function-Call Subsystem/Detect Red/MATLAB Function1'
 * '<S26>'  : 'RaspPiPilot/Navigation/Function-Call Subsystem/Detect yellow/Compare To Constant1'
 * '<S27>'  : 'RaspPiPilot/Navigation/Function-Call Subsystem/Detect yellow/MATLAB Function1'
 * '<S28>'  : 'RaspPiPilot/Navigation/Function-Call Subsystem/Subsystem/MATLAB Function'
 * '<S29>'  : 'RaspPiPilot/Navigation/Function-Call Subsystem/attitudeFix/MATLAB Function'
 * '<S30>'  : 'RaspPiPilot/Navigation/Function-Call Subsystem/projectionFix/Lowpass Filter'
 * '<S31>'  : 'RaspPiPilot/Navigation/Function-Call Subsystem/projectionFix/Lowpass Filter1'
 * '<S32>'  : 'RaspPiPilot/Navigation/Function-Call Subsystem/projectionFix/Lowpass Filter2'
 * '<S33>'  : 'RaspPiPilot/messageParser/While Iterator Subsystem'
 * '<S34>'  : 'RaspPiPilot/messageParser/While Iterator Subsystem/Compare To Constant'
 * '<S35>'  : 'RaspPiPilot/messageParser/While Iterator Subsystem/Compare To Constant1'
 * '<S36>'  : 'RaspPiPilot/messageParser/While Iterator Subsystem/Compare To Constant2'
 * '<S37>'  : 'RaspPiPilot/messageParser/While Iterator Subsystem/Compare To Constant3'
 * '<S38>'  : 'RaspPiPilot/messageParser/While Iterator Subsystem/Compare To Constant4'
 * '<S39>'  : 'RaspPiPilot/messageParser/While Iterator Subsystem/Compare To Constant5'
 * '<S40>'  : 'RaspPiPilot/messageParser/While Iterator Subsystem/MATLAB Function'
 * '<S41>'  : 'RaspPiPilot/messageParser/While Iterator Subsystem/attitudeParser'
 * '<S42>'  : 'RaspPiPilot/messageParser/While Iterator Subsystem/resultParser'
 * '<S43>'  : 'RaspPiPilot/messageParser/While Iterator Subsystem/statusParser'
 * '<S44>'  : 'RaspPiPilot/messageParser/While Iterator Subsystem/statusParser1'
 * '<S45>'  : 'RaspPiPilot/messageParser/While Iterator Subsystem/stringParser'
 * '<S46>'  : 'RaspPiPilot/messageParser/While Iterator Subsystem/attitudeParser/MATLAB Function1'
 * '<S47>'  : 'RaspPiPilot/messageParser/While Iterator Subsystem/resultParser/MATLAB Function1'
 * '<S48>'  : 'RaspPiPilot/messageParser/While Iterator Subsystem/statusParser/MATLAB Function1'
 * '<S49>'  : 'RaspPiPilot/messageParser/While Iterator Subsystem/statusParser1/MATLAB Function1'
 * '<S50>'  : 'RaspPiPilot/messageParser/While Iterator Subsystem/stringParser/MATLAB Function1'
 */
#endif                                 /* RTW_HEADER_RaspPiPilot_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
