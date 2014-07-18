/*
 * RaspPiPilot_dt.h
 *
 * Code generation for model "RaspPiPilot".
 *
 * Model version              : 1.288
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Thu Jul 10 16:17:29 2014
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&RaspPiPilot_B.Constant3), 0, 0, 9 },

  { (char_T *)(&RaspPiPilot_B.dataOut[0]), 3, 0, 257 },

  { (char_T *)(&RaspPiPilot_B.Compare), 8, 0, 4 }
  ,

  { (char_T *)(&RaspPiPilot_DW.UnitDelay_DSTATE), 0, 0, 5 },

  { (char_T *)(&RaspPiPilot_DW.spHandle), 6, 0, 3 },

  { (char_T *)(&RaspPiPilot_DW.temporalCounter_i1), 5, 0, 1 },

  { (char_T *)(&RaspPiPilot_DW.messageParser_SubsysRanBC), 2, 0, 6 },

  { (char_T *)(&RaspPiPilot_DW.is_active_c5_RaspPiPilot), 3, 0, 3 },

  { (char_T *)(&RaspPiPilot_DW.isStable), 8, 0, 1 },

  { (char_T *)(&RaspPiPilot_DW.sf_MATLABFunction.MATLABFunction_SubsysRanBC), 2,
    0, 1 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  10U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&RaspPiPilot_P.CompareToConstant3_const), 6, 0, 1 },

  { (char_T *)(&RaspPiPilot_P.Constant3_Value), 0, 0, 8 },

  { (char_T *)(&RaspPiPilot_P.Memory_X0_k), 6, 0, 3 },

  { (char_T *)(&RaspPiPilot_P.Constant1_Value), 8, 0, 2 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  4U,
  rtPTransitions
};

/* [EOF] RaspPiPilot_dt.h */
