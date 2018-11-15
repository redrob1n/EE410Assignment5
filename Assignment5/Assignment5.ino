/*
*
*
*
*
*/

// if left > right then Diff = positive
// if left is further... need to slow down left sonar.

#include "globals.h"

int setpoint = 30;

float Kp = 1;

float Kd = 3;

float error = 0;

float p_error = 0;

float u = 0;

void setup()
{
    Serial.begin(9600);
    Serial1.begin(9600);
    Serial.println("Hello world");
    motor_init();
    setMotorSpeeds(50);
    writeMotorSpeeds();
    sonar_init();
        
}

void loop()
{
    
    for(;;)   
    {
        ping();
        
        
        error = setpoint - sonarRead[6];
        
        //Test 30cm sonar read
        /*Serial.print("Right Sonar Read: ");
        Serial.println(sonarRead[6]);
        Serial.print("Left Sonar Read:  ");
        Serial.println(sonarRead[2]);*/
        
        u = -1 * error * Kp;
        u += -1 * (Kd * (error - p_error));
        leftDutyCyclePercent = bound(u, 38, 46);
        setSingleMotorSpeed(leftDutyCyclePercent, false);
        writeMotorSpeeds();
        p_error = error;
        
        
        /*Serial.print("Right Speed: ");
        Serial.println(rightDutyCyclePercent);
        Serial.print("Left Speed: ");
        Serial.println(leftDutyCyclePercent);*/
        /*
        float sonarAvg = (sonarRead[2]+sonarRead[6])/2;

        //sonar differences is the error
        int sonarDiff;
        error = sonarRead[2] - sonarRead[6];

        u = -1 * error * Kp;
        u += -1 * (Kd * (error - p_error));
        p_error = error;
        // if left is closer... left is smaller... diff is negative... error is positive
        //left speeds up
        // if left is further... need to slow down left sonar.
        if(u > 0)
        {
            leftDutyCyclePercent = bound(u, 38, 46);
        }
        else if(u < 0)
        {
            leftDutyCyclePercent = bound(u, 38, 46);
        }
        else if(u == 0)
        {
            leftDutyCyclePercent = bound(u, 42, 42);
        }
        setSingleMotorSpeed(leftDutyCyclePercent, false);
        writeMotorSpeeds();*/
    }
    
}

float bound(float x, float x_min, float x_max) 
{
    x = x + 42;

    if (x < x_min) { x = x_min; }
    if (x > x_max) { x = x_max; }

    /*
    if (x > 0) { x = x_max; }
    if (x < 0) { x = x_min; }
    */

    return x;
}