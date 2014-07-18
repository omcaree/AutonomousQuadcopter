/*
 * Serial_dt.h
 *
 * Code generation for model "Serial".
 *
 * Model version              : 1.72
 * Simulink Coder version : 8.6 (R2014a) 27-Dec-2013
 * C source code generated on : Thu Jul 03 14:32:29 2014
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
  { (char_T *)(&Serial_B.Constant3), 0, 0, 10 },

  { (char_T *)(&Serial_B.messageId), 3, 0, 258 },

  { (char_T *)(&Serial_B.Compare), 8, 0, 3 }
  ,

  { (char_T *)(&Serial_DW.UnitDelay_DSTATE), 0, 0, 1 },

  { (char_T *)(&Serial_DW.Scope_PWORK.LoggedData), 11, 0, 4 },

  { (char_T *)(&Serial_DW.spHandle), 6, 0, 2 },

  { (char_T *)(&Serial_DW.Subsystem_SubsysRanBC), 2, 0, 2 },

  { (char_T *)(&Serial_DW.is_active_c5_Serial), 3, 0, 5 },

  { (char_T *)(&Serial_DW.spHandle_not_empty), 8, 0, 2 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  9U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&Serial_P.CompareToConstant_const), 3, 0, 1 },

  { (char_T *)(&Serial_P.UnitDelay_InitialCondition), 0, 0, 8 },

  { (char_T *)(&Serial_P.Constant_Value_d), 6, 0, 1 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  3U,
  rtPTransitions
};

/* [EOF] Serial_dt.h */
