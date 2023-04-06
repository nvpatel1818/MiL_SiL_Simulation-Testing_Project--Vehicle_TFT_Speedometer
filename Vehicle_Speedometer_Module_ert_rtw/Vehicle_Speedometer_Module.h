/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Vehicle_Speedometer_Module.h
 *
 * Code generated for Simulink model 'Vehicle_Speedometer_Module'.
 *
 * Model version                  : 1.35
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Sun Mar 19 04:03:56 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Mac OS X)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Vehicle_Speedometer_Module_h_
#define RTW_HEADER_Vehicle_Speedometer_Module_h_
#ifndef Vehicle_Speedometer_Module_COMMON_INCLUDES_
#define Vehicle_Speedometer_Module_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                         /* Vehicle_Speedometer_Module_COMMON_INCLUDES_ */

#include "Vehicle_Speedometer_Module_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  uint16_T DisplaySpeed_Filter;        /* '<S2>/Add' */
} B_Vehicle_Speedometer_Module_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  uint8_T In_MainFilt_SpeedValue;      /* '<Root>/In_MainFilt_SpeedValue' */
  uint8_T In_AuxFilt_SpeedValue;       /* '<Root>/In_AuxFilt_SpeedValue' */
  uint16_T Avg_VehicleSpeed;           /* '<Root>/Avg_VehicleSpeed' */
  uint16_T Timer_Input;                /* '<Root>/Timer_Input' */
} ExtU_Vehicle_Speedometer_Modu_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  uint16_T Out_VehicleSpeed_Display;   /* '<Root>/Out_VehicleSpeed_Display' */
} ExtY_Vehicle_Speedometer_Modu_T;

/* Real-time Model Data Structure */
struct tag_RTM_Vehicle_Speedometer_M_T {
  const char_T * volatile errorStatus;
};

/* Block signals (default storage) */
extern B_Vehicle_Speedometer_Module_T Vehicle_Speedometer_Module_B;

/* External inputs (root inport signals with default storage) */
extern ExtU_Vehicle_Speedometer_Modu_T Vehicle_Speedometer_Module_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_Vehicle_Speedometer_Modu_T Vehicle_Speedometer_Module_Y;

/* Model entry point functions */
extern void Vehicle_Speedometer_Module_initialize(void);
extern void Vehicle_Speedometer_Module_step(void);
extern void Vehicle_Speedometer_Module_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Vehicle_Speedometer__T *const Vehicle_Speedometer_Module_M;

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
 * '<Root>' : 'Vehicle_Speedometer_Module'
 * '<S1>'   : 'Vehicle_Speedometer_Module/Speedometer_Module'
 * '<S2>'   : 'Vehicle_Speedometer_Module/Speedometer_Module/Auxilliary_Data_Filtering'
 * '<S3>'   : 'Vehicle_Speedometer_Module/Speedometer_Module/Compare To Zero'
 * '<S4>'   : 'Vehicle_Speedometer_Module/Speedometer_Module/Display_Speed_Output'
 * '<S5>'   : 'Vehicle_Speedometer_Module/Speedometer_Module/Input_Processing'
 * '<S6>'   : 'Vehicle_Speedometer_Module/Speedometer_Module/Main_Data_Filtering'
 */
#endif                            /* RTW_HEADER_Vehicle_Speedometer_Module_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
