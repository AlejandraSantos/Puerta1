int buttonPin = 3;
int ledPin = 13;
int buttonState = 0;
const int intPin = 2;
volatile int state = LOW;

void setup() {
pinMode(ledPin, OUTPUT);
pinMode(buttonPin, INPUT);
attachInterrupt(digitalPinToInterrupt(intPin), blink, RISING);
}

void loop(){
buttonState = digitalRead( buttonPin);
if (buttonState == HIGH) {
    digitalWrite(ledPin, HIGH);}
else {
    digitalWrite(ledPin, LOW);
    }
} 
void blink() {
    state = !state;
    digitalWrite(ledPin, state);
}
