/*
* initializes sonar pins 
*/
void sonar_init()
{
    pinMode(FrontSonar_pin, OUTPUT);
    pinMode(Left45FrontSonar_pin, OUTPUT);
    pinMode(LeftSonar_pin, OUTPUT);
    pinMode(Left45RearSonar_pin, OUTPUT);
    pinMode(RearSonar_pin, OUTPUT);
    pinMode(Right45RearSonar_pin, OUTPUT);
    pinMode(RightSonar_pin, OUTPUT);
    pinMode(Right45FrontSonar_pin, OUTPUT); 
}

/*
*   Returns a struct of sonar ranges
*/
void ping()
{
    sonarRead[0] = SonarRange(FrontSonar_pin);   
    sonarRead[1] = SonarRange(Left45FrontSonar_pin);
    sonarRead[2] = SonarRange(LeftSonar_pin);
    sonarRead[3] = SonarRange(Left45RearSonar_pin);
    sonarRead[4] = SonarRange(RearSonar_pin);
    sonarRead[5] = SonarRange(Right45RearSonar_pin);
    sonarRead[6] = SonarRange(RightSonar_pin);
    sonarRead[7] = SonarRange(Right45FrontSonar_pin);   
}

/*
* returns the range from a sonar
*/
float SonarRange(int sonar_pin) 
{
    float echo;  
    float range;
    pulseOut(sonar_pin);                      //sends out a ultrasonic pulse
    pinMode(sonar_pin, INPUT);
    echo = pulseIn (sonar_pin, HIGH);         //times the return pulse
    range = echo/58.0;                       //converts round trip pulse time to distance
    delay(50);  
    return range;
}

//pings the ultrasonic sensor
void pulseOut(int pin) 
{
    pinMode(pin, OUTPUT);  
    digitalWrite(pin, HIGH);
    delayMicroseconds(10);
    digitalWrite(pin, LOW);
}
