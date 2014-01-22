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


#endif

