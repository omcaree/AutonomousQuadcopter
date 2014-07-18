/*
 * File: RaspPiPilot_private.h
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

#ifndef RTW_HEADER_RaspPiPilot_private_h_
#define RTW_HEADER_RaspPiPilot_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               (&(rtm)->Timing.taskTime0)
#endif

#ifndef __RTWTYPES_H__
#error This file requires rtwtypes.h to be included
#endif                                 /* __RTWTYPES_H__ */

extern void RaspPiPilot_MATLABFunction(const uint8_T rtu_dataOut[256], uint8_T
  rtu_lengthOut, DW_MATLABFunction_RaspPiPilot_T *localDW, int32_T *rtd_spHandle);

#endif                                 /* RTW_HEADER_RaspPiPilot_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
