/*
 * File: RaspPiPilot_data.c
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

/* Block parameters (auto storage) */
P_RaspPiPilot_T RaspPiPilot_P = {
  0,                                   /* Mask Parameter: CompareToConstant3_const
                                        * Referenced by: '<S37>/Constant'
                                        */
  1,                                   /* Mask Parameter: DrawShapes1_lineWidth
                                        * Referenced by: '<S6>/Draw Shapes1'
                                        */
  4,                                   /* Mask Parameter: DrawMarkers2_size
                                        * Referenced by: '<S6>/Draw Markers2'
                                        */
  64U,                                 /* Mask Parameter: BlobAnalysis_minArea
                                        * Referenced by: '<S19>/Blob Analysis'
                                        */

  /*  Mask Parameter: DrawMarkers2_color
   * Referenced by: '<S6>/Draw Markers2'
   */
  { 0U, 255U, 255U, 0U, 255U, 0U, 255U, 0U, 0U, 0U, 255U, 255U },
  20U,                                 /* Mask Parameter: CompareToConstant_const
                                        * Referenced by: '<S12>/Constant'
                                        */
  30U,                                 /* Mask Parameter: CompareToConstant2_const
                                        * Referenced by: '<S22>/Constant'
                                        */
  30U,                                 /* Mask Parameter: CompareToConstant1_const
                                        * Referenced by: '<S24>/Constant'
                                        */
  30U,                                 /* Mask Parameter: CompareToConstant1_const_l
                                        * Referenced by: '<S26>/Constant'
                                        */
  77U,                                 /* Mask Parameter: CompareToConstant1_const_p
                                        * Referenced by: '<S35>/Constant'
                                        */
  1U,                                  /* Mask Parameter: CompareToConstant4_const
                                        * Referenced by: '<S38>/Constant'
                                        */
  0U,                                  /* Mask Parameter: CompareToConstant5_const
                                        * Referenced by: '<S39>/Constant'
                                        */
  253U,                                /* Mask Parameter: CompareToConstant2_const_e
                                        * Referenced by: '<S36>/Constant'
                                        */
  30U,                                 /* Mask Parameter: CompareToConstant_const_l
                                        * Referenced by: '<S34>/Constant'
                                        */
  0.5,                                 /* Expression: 1/2
                                        * Referenced by: '<S10>/Gain3'
                                        */

  /*  Expression: -[240 320]/2
   * Referenced by: '<S10>/Subtract Image Centre'
   */
  { -120.0, -160.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S16>/Generated Filter Block'
                                        */

  /*  Expression: [0.0032276888738420255 -0.012093185057654832 -0.056871256727662273 -0.033025317279675399 0.16717851315296134 0.40566714821275895 0.40566714821275895 0.16717851315296134 -0.033025317279675399 -0.056871256727662273 -0.012093185057654832 0.0032276888738420255]
   * Referenced by: '<S16>/Generated Filter Block'
   */
  { 0.0032276888738420255, -0.012093185057654832, -0.056871256727662273,
    -0.0330253172796754, 0.16717851315296134, 0.40566714821275895,
    0.40566714821275895, 0.16717851315296134, -0.0330253172796754,
    -0.056871256727662273, -0.012093185057654832, 0.0032276888738420255 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S17>/Generated Filter Block'
                                        */

  /*  Expression: [0.0032276888738420255 -0.012093185057654832 -0.056871256727662273 -0.033025317279675399 0.16717851315296134 0.40566714821275895 0.40566714821275895 0.16717851315296134 -0.033025317279675399 -0.056871256727662273 -0.012093185057654832 0.0032276888738420255]
   * Referenced by: '<S17>/Generated Filter Block'
   */
  { 0.0032276888738420255, -0.012093185057654832, -0.056871256727662273,
    -0.0330253172796754, 0.16717851315296134, 0.40566714821275895,
    0.40566714821275895, 0.16717851315296134, -0.0330253172796754,
    -0.056871256727662273, -0.012093185057654832, 0.0032276888738420255 },
  0.166,                               /* Expression: 0.083*2
                                        * Referenced by: '<S10>/Convert pixels to degrees'
                                        */
  0.017453292519943295,                /* Expression: pi/180.0
                                        * Referenced by: '<S10>/Gain4'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S20>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S31>/Generated Filter Block'
                                        */

  /*  Expression: [0.011901508381575016 0.02908797826733928 0.0025913585662860131 -0.068996275507793012 -0.050025679925086837 0.16540100530640869 0.41332778671981452 0.41332778671981452 0.16540100530640869 -0.050025679925086837 -0.068996275507793012 0.0025913585662860131 0.02908797826733928 0.011901508381575016]
   * Referenced by: '<S31>/Generated Filter Block'
   */
  { 0.011901508381575016, 0.02908797826733928, 0.0025913585662860131,
    -0.068996275507793012, -0.050025679925086837, 0.16540100530640869,
    0.41332778671981452, 0.41332778671981452, 0.16540100530640869,
    -0.050025679925086837, -0.068996275507793012, 0.0025913585662860131,
    0.02908797826733928, 0.011901508381575016 },
  0.166,                               /* Expression: 0.083*2
                                        * Referenced by: '<S21>/Convert pixels to degrees1'
                                        */
  0.017453292519943295,                /* Expression: pi/180.0
                                        * Referenced by: '<S21>/Gain6'
                                        */
  4.0,                                 /* Expression: 4
                                        * Referenced by: '<S21>/Constant1'
                                        */
  -0.4619,                             /* Expression: -0.4619
                                        * Referenced by: '<S21>/Constant'
                                        */
  10.08,                               /* Expression: 18.9/7.5*4
                                        * Referenced by: '<S21>/Gain2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S32>/Generated Filter Block'
                                        */

  /*  Expression: [0.011901508381575016 0.02908797826733928 0.0025913585662860131 -0.068996275507793012 -0.050025679925086837 0.16540100530640869 0.41332778671981452 0.41332778671981452 0.16540100530640869 -0.050025679925086837 -0.068996275507793012 0.0025913585662860131 0.02908797826733928 0.011901508381575016]
   * Referenced by: '<S32>/Generated Filter Block'
   */
  { 0.011901508381575016, 0.02908797826733928, 0.0025913585662860131,
    -0.068996275507793012, -0.050025679925086837, 0.16540100530640869,
    0.41332778671981452, 0.41332778671981452, 0.16540100530640869,
    -0.050025679925086837, -0.068996275507793012, 0.0025913585662860131,
    0.02908797826733928, 0.011901508381575016 },
  10.08,                               /* Expression: 18.9/7.5*4
                                        * Referenced by: '<S21>/Gain1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S30>/Generated Filter Block'
                                        */

  /*  Expression: [0.011901508381575016 0.02908797826733928 0.0025913585662860131 -0.068996275507793012 -0.050025679925086837 0.16540100530640869 0.41332778671981452 0.41332778671981452 0.16540100530640869 -0.050025679925086837 -0.068996275507793012 0.0025913585662860131 0.02908797826733928 0.011901508381575016]
   * Referenced by: '<S30>/Generated Filter Block'
   */
  { 0.011901508381575016, 0.02908797826733928, 0.0025913585662860131,
    -0.068996275507793012, -0.050025679925086837, 0.16540100530640869,
    0.41332778671981452, 0.41332778671981452, 0.16540100530640869,
    -0.050025679925086837, -0.068996275507793012, 0.0025913585662860131,
    0.02908797826733928, 0.011901508381575016 },
  0.5,                                 /* Expression: 1/2
                                        * Referenced by: '<S21>/Gain'
                                        */
  0.19,                                /* Expression: 0.19
                                        * Referenced by: '<S6>/Constant'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S8>/Generated Filter Block'
                                        */

  /*  Expression: [0.0032276888738420255 -0.012093185057654832 -0.056871256727662273 -0.033025317279675399 0.16717851315296134 0.40566714821275895 0.40566714821275895 0.16717851315296134 -0.033025317279675399 -0.056871256727662273 -0.012093185057654832 0.0032276888738420255]
   * Referenced by: '<S8>/Generated Filter Block'
   */
  { 0.0032276888738420255, -0.012093185057654832, -0.056871256727662273,
    -0.0330253172796754, 0.16717851315296134, 0.40566714821275895,
    0.40566714821275895, 0.16717851315296134, -0.0330253172796754,
    -0.056871256727662273, -0.012093185057654832, 0.0032276888738420255 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S9>/Generated Filter Block'
                                        */

  /*  Expression: [0.0032276888738420255 -0.012093185057654832 -0.056871256727662273 -0.033025317279675399 0.16717851315296134 0.40566714821275895 0.40566714821275895 0.16717851315296134 -0.033025317279675399 -0.056871256727662273 -0.012093185057654832 0.0032276888738420255]
   * Referenced by: '<S9>/Generated Filter Block'
   */
  { 0.0032276888738420255, -0.012093185057654832, -0.056871256727662273,
    -0.0330253172796754, 0.16717851315296134, 0.40566714821275895,
    0.40566714821275895, 0.16717851315296134, -0.0330253172796754,
    -0.056871256727662273, -0.012093185057654832, 0.0032276888738420255 },
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Constant1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Constant2'
                                        */
  1500.0,                              /* Expression: 1500
                                        * Referenced by: '<Root>/Constant3'
                                        */
  1500.0,                              /* Expression: 1500
                                        * Referenced by: '<Root>/Constant4'
                                        */
  1000.0,                              /* Expression: 1000
                                        * Referenced by: '<Root>/Constant5'
                                        */
  1000.0,                              /* Expression: 1000
                                        * Referenced by: '<Root>/Constant6'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Memory'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S4>/Constant'
                                        */
  1,                                   /* Computed Parameter: Memory_X0_j
                                        * Referenced by: '<S33>/Memory'
                                        */
  0,                                   /* Computed Parameter: Constant_Value_d
                                        * Referenced by: '<S2>/Constant'
                                        */

  /*  Computed Parameter: DrawShapes1_RTP_FILLCOLOR
   * Referenced by: '<S6>/Draw Shapes1'
   */
  { 255U, 0U, 0U },
  0,                                   /* Computed Parameter: UnitDelay_InitialCondition
                                        * Referenced by: '<Root>/Unit Delay'
                                        */
  0                                    /* Computed Parameter: Constant_Value_o
                                        * Referenced by: '<S3>/Constant'
                                        */
};

/* Constant parameters (auto storage) */
const ConstP_RaspPiPilot_T RaspPiPilot_ConstP = {
  /* Computed Parameter: BlobAnalysis_WALKER_R
   * Referenced by: '<S19>/Blob Analysis'
   */
  { -1, 321, 322, 323, 1, -321, -322, -323 },

  /* Expression: devName
   * Referenced by: '<S6>/V4L2 Video Capture'
   */
  { 47U, 100U, 101U, 118U, 47U, 118U, 105U, 100U, 101U, 111U, 48U, 0U }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
