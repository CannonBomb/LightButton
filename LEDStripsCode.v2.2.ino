const int REDPIN = 11;
const int GREENPIN = 12;
const int BLUEPIN = 13;

//sets pins for buttons
const int RED1in = 3;
const int RED2in = 4;
const int RED1out = 1;
const int RED2out = 2;
const int YELLOW1in = 7;
const int YELLOW2in = 8;
const int YELLOW1out = 5;
const int YELLOW2out = 6;

//There are 4 buttons, 2 for each color
int buttonStateRED1 = 0;
int buttonStateRED2 = 0;
int buttonStateYELLOW1 = 0;
int buttonStateYELLOW2 = 0;


//Because the switches are double action, they will be "on" when they change state
int lastButtonStateRED1 = 0;
int lastButtonStateRED2 = 0;
int lastButtonStateYELLOW1 = 0;
int lastButtonStateYELLOW2 = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(REDPIN, OUTPUT);
  pinMode(GREENPIN, OUTPUT);
  pinMode(BLUEPIN, OUTPUT);
  pinMode(RED1in, INPUT);
  pinMode(RED2in, INPUT);
  pinMode(RED1out, OUTPUT);
  pinMode(RED2out, OUTPUT);
  pinMode(YELLOW1in, INPUT);
  pinMode(YELLOW2in, INPUT);
  pinMode(YELLOW1out, OUTPUT);
  pinMode(YELLOW2out, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  //always outputting signal, and only passes if switch is pressed.
  digitalWrite(RED1out, HIGH);
  digitalWrite(RED2out, HIGH);
  digitalWrite(YELLOW1out, HIGH);
  digitalWrite(YELLOW2out, HIGH);

  buttonStateRED1 = digitalRead(RED1in); //Reads buttonstate
  buttonStateRED2 = digitalRead(RED2in);
  buttonStateYELLOW1 = digitalRead(YELLOW1in);
  buttonStateYELLOW2 = digitalRead(YELLOW2in);
  


  if ((buttonStateRED1 != lastButtonStateRED1) || (buttonStateRED2 != lastButtonStateRED2)) { //Checks if button state has changed
    analogWrite(REDPIN, 255); //Sets LEDs to RED
    delay(3500); //Holds state for x seconds in milliseconds. 10000ms = 10s
    analogWrite(REDPIN, 0);  //Sets LED back to off
  //delay(50); //50 ms delay to debounce button
  }
  else if ((buttonStateYELLOW1 != lastButtonStateYELLOW1) || (buttonStateYELLOW2 != lastButtonStateYELLOW2)) {

    analogWrite(REDPIN, 255); //Sets LEDs to YELLOW
    analogWrite(GREENPIN, 255);
    analogWrite(BLUEPIN, 0);
    delay(3500);
    analogWrite(REDPIN, 0);
    analogWrite(GREENPIN, 0);
  //delay(50); //50 ms delay to debounce button
  }
  lastButtonStateRED1 = buttonStateRED1;
  lastButtonStateRED2 = buttonStateRED2;
  lastButtonStateYELLOW1 = buttonStateYELLOW1;
  lastButtonStateYELLOW2 = buttonStateYELLOW2;
}

