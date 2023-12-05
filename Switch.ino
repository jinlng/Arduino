/*
  Switch

  Turns on and off the onboard light emitting diode(LED),
  when the two nitinol stent establish contact (attached to pin D6).

  The circuit:
  - LED_Builtin (GPIO48 / pin 13)
  - 'Switch' attached to pin D6 from +5V
  - 100K resistor attached to pin D6 from ground

  - Note: on most Arduinos there is already an LED on the board
    attached to pin 13.

  created 2023
  by LIANG Jingyi
  This code is based on an example code 'Button' in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Button
*/

// constants to set pin numbers:
const int buttonPin = 48;  // the number of the pushbutton pin
const int ledPin = 4;    // the number of the LED pin

// variables will change:
int buttonState = 0;  // variable for reading the pushbutton status

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);

  Serial.begin(9600);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
  delay(100);
  Serial.println(buttonState);
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
    Serial.print("Stents in Contact");
    delay(100);
  } else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
    Serial.print("Stents NOT in Contact");
    delay(1000);
  }
}
