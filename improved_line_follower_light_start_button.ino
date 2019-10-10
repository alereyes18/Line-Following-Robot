//Define Pin Mappings
const int leftMotorPin = 9;
const int leftSensorPin = A1;
const int rightMotorPin = 8;
const int rightSensorPin = A0;
const int startButton = 12;

int buttonCounter=0; //Declares a counter variable for when the button has been pressed
//Changes the sensitivity of the photoresistors
int lightThreshold = 400;

void setup()
{
  //Set Pin Modes
  Serial.begin(9600);             //Set Baud Rate, Required to use Serial Monitor Serial.begin(9600);
  pinMode(leftMotorPin, OUTPUT);
  pinMode(leftSensorPin, INPUT);
  pinMode(rightMotorPin, OUTPUT);
  pinMode(rightSensorPin, INPUT);
  pinMode (startButton, INPUT);
}


void loop()
{
  //Detects if button has been pressed
  int buttonPressed = digitalRead(startButton);
  
  if (buttonPressed == HIGH)
  {
    buttonCounter = 1;
  }

  while (buttonCounter ==1)
  {
    //Define Light Level Mappings
    int leftLightLevel = analogRead(leftSensorPin);
    int rightLightLevel = analogRead(rightSensorPin);

    //If left photoresistor value is greater than threshold
    //then turn left motor on, else turn left motor off

    if (leftLightLevel > lightThreshold)
      digitalWrite(leftMotorPin, HIGH);
    else
      digitalWrite(leftMotorPin, LOW);


    //If right photoresistor value is greater than threshold
    //then turn left motor on, else turn right motor off

    if (rightLightLevel > lightThreshold)
      digitalWrite(rightMotorPin, HIGH);
    else
      digitalWrite(rightMotorPin, LOW);

  }
}
