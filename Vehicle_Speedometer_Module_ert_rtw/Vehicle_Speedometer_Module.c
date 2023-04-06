/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Vehicle_Speedometer_Module.c
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

#include "Vehicle_Speedometer_Module.h"
#include "rtwtypes.h"
#include "Vehicle_Speedometer_Module_private.h"

/* Block signals (default storage) */
B_Vehicle_Speedometer_Module_T Vehicle_Speedometer_Module_B;

/* External inputs (root inport signals with default storage) */
ExtU_Vehicle_Speedometer_Modu_T Vehicle_Speedometer_Module_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_Vehicle_Speedometer_Modu_T Vehicle_Speedometer_Module_Y;

/* Real-time model */
static RT_MODEL_Vehicle_Speedometer__T Vehicle_Speedometer_Module_M_;
RT_MODEL_Vehicle_Speedometer__T *const Vehicle_Speedometer_Module_M =
  &Vehicle_Speedometer_Module_M_;

/* Model step function */
void Vehicle_Speedometer_Module_step(void)
{
  int16_T rtb_Add;
  uint16_T rtb_Add_0;
  uint16_T tmp;

  /* Outputs for Atomic SubSystem: '<Root>/Speedometer_Module' */
  /* Saturate: '<S5>/Saturation' incorporates:
   *  Inport: '<Root>/Avg_VehicleSpeed'
   */
  if (Vehicle_Speedometer_Module_U.Avg_VehicleSpeed > 25000) {
    /* Saturate: '<S5>/Saturation' */
    Vehicle_Speedometer_Module_Y.Out_VehicleSpeed_Display = 25000U;
  } else if (Vehicle_Speedometer_Module_U.Avg_VehicleSpeed < 200) {
    /* Saturate: '<S5>/Saturation' */
    Vehicle_Speedometer_Module_Y.Out_VehicleSpeed_Display = 200U;
  } else {
    /* Saturate: '<S5>/Saturation' */
    Vehicle_Speedometer_Module_Y.Out_VehicleSpeed_Display =
      Vehicle_Speedometer_Module_U.Avg_VehicleSpeed;
  }

  /* End of Saturate: '<S5>/Saturation' */

  /* Outputs for Enabled SubSystem: '<S1>/Auxilliary_Data_Filtering' incorporates:
   *  EnablePort: '<S2>/Enable'
   */
  /* Outputs for Enabled SubSystem: '<S1>/Main_Data_Filtering' incorporates:
   *  EnablePort: '<S6>/Enable'
   */
  /* RelationalOperator: '<S3>/Compare' incorporates:
   *  Constant: '<S3>/Constant'
   *  Inport: '<Root>/Timer_Input'
   *  Math: '<S1>/Rem'
   */
  if ((uint16_T)(Vehicle_Speedometer_Module_U.Timer_Input % 10) == 0) {
    /* Product: '<S6>/Divide' incorporates:
     *  Gain: '<S6>/Gain'
     *  Inport: '<Root>/In_MainFilt_SpeedValue'
     *  Saturate: '<S5>/Saturation'
     */
    if (Vehicle_Speedometer_Module_U.In_MainFilt_SpeedValue == 0U) {
      rtb_Add_0 = MAX_uint16_T;

      /* Divide by zero handler */
    } else {
      rtb_Add_0 = (uint16_T)((uint32_T)(uint16_T)((((65U *
        Vehicle_Speedometer_Module_Y.Out_VehicleSpeed_Display) >> 7) * 2684355UL)
        >> 21) / Vehicle_Speedometer_Module_U.In_MainFilt_SpeedValue);
    }

    /* Product: '<S2>/Divide' incorporates:
     *  Constant: '<S6>/Constant'
     *  Gain: '<S2>/Gain'
     *  Inport: '<Root>/In_AuxFilt_SpeedValue'
     *  Product: '<S6>/Divide'
     *  Sum: '<S6>/Add'
     */
    if (Vehicle_Speedometer_Module_U.In_AuxFilt_SpeedValue == 0U) {
      rtb_Add_0 = MAX_uint16_T;

      /* Divide by zero handler */
    } else {
      rtb_Add_0 = (uint16_T)((uint32_T)(uint16_T)(((((uint16_T)(rtb_Add_0 - 5U) *
        39U) >> 6) * 2684355UL) >> 21) /
        Vehicle_Speedometer_Module_U.In_AuxFilt_SpeedValue);
    }

    /* Sum: '<S2>/Add' incorporates:
     *  Constant: '<S2>/Constant'
     *  Product: '<S2>/Divide'
     */
    Vehicle_Speedometer_Module_B.DisplaySpeed_Filter = (uint16_T)(rtb_Add_0 - 3U);
  }

  /* End of RelationalOperator: '<S3>/Compare' */
  /* End of Outputs for SubSystem: '<S1>/Main_Data_Filtering' */
  /* End of Outputs for SubSystem: '<S1>/Auxilliary_Data_Filtering' */

  /* Sum: '<S4>/Add' incorporates:
   *  Saturate: '<S5>/Saturation'
   *  Sum: '<S2>/Add'
   */
  rtb_Add_0 = Vehicle_Speedometer_Module_B.DisplaySpeed_Filter;
  if (Vehicle_Speedometer_Module_B.DisplaySpeed_Filter > 32767) {
    rtb_Add_0 = 32767U;
  }

  tmp = Vehicle_Speedometer_Module_Y.Out_VehicleSpeed_Display;
  if (Vehicle_Speedometer_Module_Y.Out_VehicleSpeed_Display > 32767) {
    tmp = 32767U;
  }

  rtb_Add = (int16_T)(rtb_Add_0 - tmp);

  /* End of Sum: '<S4>/Add' */

  /* Abs: '<S4>/Abs' incorporates:
   *  Sum: '<S4>/Add'
   */
  if (rtb_Add < 0) {
    rtb_Add_0 = (uint16_T)-rtb_Add;
  } else {
    rtb_Add_0 = (uint16_T)rtb_Add;
  }

  /* End of Abs: '<S4>/Abs' */

  /* Switch: '<S4>/Switch' incorporates:
   *  RelationalOperator: '<S4>/Relational Operator'
   */
  if (rtb_Add_0 <= 150) {
    /* Saturate: '<S5>/Saturation' incorporates:
     *  Outport: '<Root>/Out_VehicleSpeed_Display'
     *  Sum: '<S2>/Add'
     */
    Vehicle_Speedometer_Module_Y.Out_VehicleSpeed_Display =
      Vehicle_Speedometer_Module_B.DisplaySpeed_Filter;
  }

  /* End of Switch: '<S4>/Switch' */
  /* End of Outputs for SubSystem: '<Root>/Speedometer_Module' */
}

/* Model initialize function */
void Vehicle_Speedometer_Module_initialize(void)
{
  /* (no initialization code required) */
}

/* Model terminate function */
void Vehicle_Speedometer_Module_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
