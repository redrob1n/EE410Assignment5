/*
*   File: motor.ino
*/

void motor_init()
{
    attachInterrupt(1, LtEncoderRead, RISING); //pin 3
    attachInterrupt(0, RtEncoderRead, RISING); //pin 2

    //setup motor control pins
    pinMode(leftDir_Pin, OUTPUT);
    pinMode(leftPWM_Pin, OUTPUT);
    pinMode(rightDir_Pin, OUTPUT);
    pinMode(rightPWM_Pin, OUTPUT);

    //initialize motor speeds to equal values
    leftDutyCyclePercent = 42;
    rightDutyCyclePercent = 50;
    leftDutyCycle = leftDutyCyclePercent * 255 / 100;
    rightDutyCycle = rightDutyCyclePercent * 255 / 100;

    //set motor direction forward
    digitalWrite(leftDir_Pin, HIGH);
    digitalWrite(rightDir_Pin, HIGH);

    // turn on motors
    motor_stop();

    LtCount = 0;
    RtCount = 0;
}

void LtEncoderRead()
{
    LtCount += 1;
}

void RtEncoderRead()
{
    RtCount += 1;
}

void setMotorSpeeds(int dutyCyclePercent)
{
    leftDutyCycle = dutyCyclePercent * 255 / 100;
    rightDutyCycle = dutyCyclePercent * 255 / 100;
}

void setSingleMotorSpeed(int dutyCyclePercent, bool isRightMotor)
{
    if(isRightMotor)
    {
        rightDutyCycle = dutyCyclePercent * 255 / 100;        
    }
    else
    {
        leftDutyCycle = dutyCyclePercent * 255 / 100;
    }
}

void writeMotorSpeeds()
{
    analogWrite(leftPWM_Pin, leftDutyCycle);
    analogWrite(rightPWM_Pin, rightDutyCycle);
}

void motor_stop()
{
    setMotorSpeeds(0);
    writeMotorSpeeds();
}
