/*
 * RaspPiPilot_dt.h
 *
 * Code generation for model "RaspPiPilot".
 *
 * Model version              : 1.199
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Wed Jul 09 13:38:36 2014
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
  2*sizeof(uint32_T),
  sizeof(int16_T),
  sizeof(int32_T),
  sizeof(int16_T)
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
  "timer_uint32_pair_T",
  "int16_T",
  "int32_T",
  "int16_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&RaspPiPilot_B.Constant3), 0, 0, 47 },

  { (char_T *)(&RaspPiPilot_B.DataTypeConversion_d), 6, 0, 24 },

  { (char_T *)(&RaspPiPilot_B.result), 3, 0, 230659 },

  { (char_T *)(&RaspPiPilot_B.Compare), 8, 0, 9 }
  ,

  { (char_T *)(&RaspPiPilot_DW.GeneratedFilterBlock_states[0]), 0, 0, 87 },

  { (char_T *)(&RaspPiPilot_DW.Scope1_PWORK.LoggedData), 11, 0, 11 },

  { (char_T *)(&RaspPiPilot_DW.Memory_PreviousInput_c), 6, 0, 39 },

  { (char_T *)(&RaspPiPilot_DW.temporalCounter_i1), 5, 0, 1 },

  { (char_T *)(&RaspPiPilot_DW.UnitDelay_DSTATE), 8, 0, 1 },

  { (char_T *)(&RaspPiPilot_DW.messageParser_SubsysRanBC), 2, 0, 11 },

  { (char_T *)(&RaspPiPilot_DW.RateTransition_Buffer0[0]), 3, 0, 230404 },

  { (char_T *)(&RaspPiPilot_DW.spHandle_not_empty), 8, 0, 3 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  12U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&RaspPiPilot_P.CompareToConstant3_const), 6, 0, 3 },

  { (char_T *)(&RaspPiPilot_P.BlobAnalysis_minArea), 7, 0, 1 },

  { (char_T *)(&RaspPiPilot_P.DrawMarkers2_color[0]), 3, 0, 21 },

  { (char_T *)(&RaspPiPilot_P.Gain3_Gain), 0, 0, 119 },

  { (char_T *)(&RaspPiPilot_P.Memory_X0_j), 6, 0, 2 },

  { (char_T *)(&RaspPiPilot_P.DrawShapes1_RTP_FILLCOLOR[0]), 3, 0, 3 },

  { (char_T *)(&RaspPiPilot_P.UnitDelay_InitialCondition), 8, 0, 2 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  7U,
  rtPTransitions
};

/* [EOF] RaspPiPilot_dt.h */
