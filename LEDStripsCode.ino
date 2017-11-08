#define REDPIN 5
#define GREENPIN 6
#define BLUEPIN 3
const int buttonPin = 2; //sets pin for on/off switch
int buttonState = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(REDPIN, OUTPUT);
  pinMode(GREENPIN, OUTPUT);
  pinMode(BLUEPIN, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int r = 0;
  int g = 0;
  int b = 0;
  buttonState = digitalRead(buttonPin); //Checks state of button


  //add another if statement here if using a switch to control color

  if (buttonState == HIGH) {
    analogWrite(REDPIN, 256);
    analogWrite(GREENPIN, 256); //Sets LED color to Yellow
    delay(10000); //Holds State for x seconds in milliseconds. 10000ms = 10s
    analogWrite(REDPIN, 0);
    analogWrite(GREENPIN, 0); //Sets LED back to off
    
  }
}
