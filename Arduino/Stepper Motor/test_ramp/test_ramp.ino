#include "pinout.h"

const int num_steps = 1600;

void setup() {
    pinMode(X_STEP_PIN, OUTPUT);
    pinMode(X_DIR_PIN, OUTPUT);
    pinMode(X_ENABLE_PIN, OUTPUT);

    pinMode(X_MIN_PIN, INPUT_PULLUP);
    // pinMode(X_MAX_PIN, INPUT_PULLUP);

    pinMode(Y_STEP_PIN, OUTPUT);
    pinMode(Y_DIR_PIN, OUTPUT);
    pinMode(Y_ENABLE_PIN, OUTPUT);

    pinMode(Y_MIN_PIN, INPUT_PULLUP);
    // pinMode(Y_MAX_PIN, INPUT_PULLUP);

    pinMode(Z_STEP_PIN, OUTPUT);
    pinMode(Z_DIR_PIN, OUTPUT);
    pinMode(Z_ENABLE_PIN, OUTPUT);

    pinMode(Z_MIN_PIN, INPUT_PULLUP);
    // pinMode(Z_MAX_PIN, INPUT_PULLUP);
    
    digitalWrite(X_ENABLE_PIN, LOW);
    digitalWrite(Y_ENABLE_PIN, LOW);
    digitalWrite(Z_ENABLE_PIN, LOW);
    
}

void loop() {
  // looping_motor();
  // test_limit_x();
  // test_limit_y();
  test_limit_z();
}

void looping_motors(){
  digitalWrite(X_DIR_PIN, HIGH);
  for(int i = 0; i<num_steps; i++) 
    { // loop for num_steps steps
      digitalWrite(X_STEP_PIN, HIGH);
      delayMicroseconds(500);
      digitalWrite(X_STEP_PIN, LOW);
      delayMicroseconds(500);
    }
  delay(1000);

  digitalWrite(X_DIR_PIN, LOW);
  for(int i = 0; i<num_steps; i++) 
    { // loop for num_steps steps
      digitalWrite(X_STEP_PIN, HIGH);
      delayMicroseconds(500);
      digitalWrite(X_STEP_PIN, LOW);
      delayMicroseconds(500);
    }
  delay(1000);


  digitalWrite(Y_DIR_PIN, HIGH);
  for(int i = 0; i<num_steps; i++) 
    { // loop for num_steps steps
      digitalWrite(Y_STEP_PIN, HIGH);
      delayMicroseconds(500);
      digitalWrite(Y_STEP_PIN, LOW);
      delayMicroseconds(500);
    }
  delay(1000);

  digitalWrite(Y_DIR_PIN, LOW);
  for(int i = 0; i<num_steps; i++) 
    { // loop for num_steps steps
      digitalWrite(Y_STEP_PIN, HIGH);
      delayMicroseconds(500);
      digitalWrite(Y_STEP_PIN, LOW);
      delayMicroseconds(500);
    }
  delay(1000);
  

  digitalWrite(Z_DIR_PIN, HIGH);
  for(int i = 0; i<num_steps; i++) 
    { // loop for num_steps steps
      digitalWrite(Z_STEP_PIN, HIGH);
      delayMicroseconds(500);
      digitalWrite(Z_STEP_PIN, LOW);
      delayMicroseconds(500);
    }
  delay(1000);

  digitalWrite(Z_DIR_PIN, LOW);
  for(int i = 0; i<num_steps; i++) 
    { // loop for num_steps steps
      digitalWrite(Z_STEP_PIN, HIGH);
      delayMicroseconds(500);
      digitalWrite(Z_STEP_PIN, LOW);
      delayMicroseconds(500);
    }
  delay(1000);

}

void test_limit_x(){
  digitalWrite(X_DIR_PIN, HIGH);
  while(digitalRead(X_MIN_PIN)){
    digitalWrite(X_STEP_PIN, HIGH);
    delayMicroseconds(500);
    digitalWrite(X_STEP_PIN, LOW);
    delayMicroseconds(500);
  }
}

void test_limit_y(){
  digitalWrite(Y_DIR_PIN, LOW);
  while(digitalRead(Y_MIN_PIN)){
    digitalWrite(Y_STEP_PIN, HIGH);
    delayMicroseconds(500);
    digitalWrite(Y_STEP_PIN, LOW);
    delayMicroseconds(500);
  }
}

void test_limit_z(){
  digitalWrite(Z_DIR_PIN, LOW);
  while(digitalRead(Z_MIN_PIN)){
    digitalWrite(Z_STEP_PIN, HIGH);
    delayMicroseconds(500);
    digitalWrite(Z_STEP_PIN, LOW);
    delayMicroseconds(500);
  }
}