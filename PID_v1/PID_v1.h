#ifndef PID_v1_h
#define PID_v1_h
#define LIBRARY_VERSION	1.0.0

//Constants used in some of the functions below
#define AUTOMATIC    1
#define MANUAL	     0
#define DIRECT       0
#define REVERSE      1

typedef struct
{
	float dispKp;				// * we'll hold on to the tuning parameters in user-entered 
	float dispKi;				//   format for display purposes
	float dispKd;				//
    
	float kp;                  // * (P)roportional Tuning Parameter
	float ki;                  // * (I)ntegral Tuning Parameter
	float kd;                  // * (D)erivative Tuning Parameter

	int controllerDirection;

	float *myInput;              // * Pointers to the Input, Output, and Setpoint variables
	float *myOutput;             //   This creates a hard link between the variables and the 
	float *mySetpoint;           //   PID, freeing the user from having to constantly tell us
                                  //   what these values are.  with pointers we'll just know.
			  
	unsigned long lastTime;
	float ITerm, lastInput;

	unsigned long SampleTime;
	float outMin, outMax;
	char inAuto;
}PID_T;

void PID_PidInit(PID_T *pid, float* Input, float* Output, float* Setpoint,
            float Kp, float Ki, float Kd, int ControllerDirection);
char PID_Compute(PID_T *pid);
void PID_SetTunings(PID_T *pid, float Kp, float Ki, float Kd);
void PID_SetSampleTime(PID_T *pid, int NewSampleTime);
void PID_SetOutputLimits(PID_T *pid, float Min, float Max);
void PID_SetMode(PID_T *pid, int Mode);
void PID_SetControllerDirection(PID_T *pid, int Direction);

/* Status Funcions*************************************************************
 * Just because you set the Kp=-1 doesn't mean it actually happened.  these
 * functions query the internal state of the PID.  they're here for display 
 * purposes.  this are the functions the PID Front-end uses for example
 ******************************************************************************/
float PID_GetKp(PID_T *pid);
float PID_GetKi(PID_T *pid);
float PID_GetKd(PID_T *pid);

int PID_GetMode(PID_T *pid);
int PID_GetDirection(PID_T *pid);


#endif

