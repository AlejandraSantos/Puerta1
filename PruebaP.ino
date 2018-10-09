#include <avr/sleep.h>
int buz=11;
int reed=3;
int led=12;
volatile int estado1= LOW;

void setup(){
  pinMode(buz, OUTPUT);
  pinMode(led,OUTPUT);
  pinMode(reed, INPUT);
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  attachInterrupt(digitalPinToInterrupt(reed), interrupcion, RISING);
  Serial.begin(9600);
}

void loop(){
  if(estado1==LOW){
     digitalWrite(led,LOW);
     sleep_enable();
     sleep_mode();
     digitalWrite(led,LOW);
  }else{
     sleep_disable();
     digitalWrite(led,HIGH);
     alarma(estado1);
  }
   
}

void interrupcion() {
  estado1 = !estado1;
}


void alarma(int estado){
  if (estado1 == LOW) {
  } else {
    int volumen=0;
    analogWrite(buz, volumen); 
    digitalWrite(buz, LOW);
  }
}
