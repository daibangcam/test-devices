// Test Stepper Motor with CNC Shield
const int StepX = 2;
const int DirX = 5;
const int StepY = 3;
const int DirY = 6;
const int StepZ = 4;
const int DirZ = 7;
const int num_steps = 3200;
const int en = 8;

// mode = 1: x
// mode = 2: y
// mode = 3: z
// mode = 4: d
// mode = 0: xyz
const int mode = 2;

void setup() 
{
  pinMode(StepX,OUTPUT);
  pinMode(DirX,OUTPUT);
  ///////////////////////
  pinMode(StepY,OUTPUT);
  pinMode(DirY,OUTPUT);
  ///////////////////////
  pinMode(StepZ,OUTPUT);
  pinMode( DirZ,OUTPUT);
  ///////////////////////
  pinMode(en, OUTPUT);
  digitalWrite(en, LOW);
}

void loop() 
{
  if (mode == 1)
  {
      digitalWrite(DirX, HIGH); // set direction, HIGH for clockwise, LOW for anticlockwise
      for(int i = 0; i<num_steps; i++) 
      { // loop for num_steps steps
        digitalWrite(StepX,HIGH);
        delayMicroseconds(500);
        digitalWrite(StepX,LOW); 
        delayMicroseconds(500);
      }
      delay(1000); // delay for 1 second
      digitalWrite(DirX, LOW); // set direction, HIGH for clockwise, LOW for anticlockwise
      for(int i = 0; i<num_steps; i++) 
      { // loop for num_steps steps
        digitalWrite(StepX,HIGH);
        delayMicroseconds(500);
        digitalWrite(StepX,LOW); 
        delayMicroseconds(500);
      }
      delay(1000); // delay for 1 second
    }
  /////////////////////////////////////////////////////////////////////////////////////
  else if (mode == 2)
  {
    digitalWrite(DirY, HIGH); // set direction, HIGH for clockwise, LOW for anticlockwise
    for(int i = 0; i<num_steps; i++) 
    { // loop for num_steps steps
      digitalWrite(StepY,HIGH);
      delayMicroseconds(500);
      digitalWrite(StepY,LOW); 
      delayMicroseconds(500);
    }
    delay(1000); // delay for 1 second
    digitalWrite(DirY, LOW); // set direction, HIGH for clockwise, LOW for anticlockwise
    for(int i = 0; i<num_steps; i++) 
    { // loop for num_steps steps
      digitalWrite(StepY,HIGH);
      delayMicroseconds(500);
      digitalWrite(StepY,LOW); 
      delayMicroseconds(500);
    }
    delay(1000); // delay for 1 second
    }
  // /////////////////////////////////////////////////////////////////////////////////////
  else if (mode == 3)
  {
    digitalWrite(DirZ, HIGH); // set direction, HIGH for clockwise, LOW for anticlockwise
    for(int i = 0; i<num_steps; i++) 
    { // loop for num_steps steps
      digitalWrite(StepZ,HIGH);
      delayMicroseconds(500);
      digitalWrite(StepZ,LOW); 
      delayMicroseconds(500);
    }
    delay(1000); // delay for 1 second
    digitalWrite(DirZ, LOW); // set direction, HIGH for clockwise, LOW for anticlockwise
    for(int i = 0; i<num_steps; i++) 
    { // loop for num_steps steps
      digitalWrite(StepZ,HIGH);
      delayMicroseconds(500);
      digitalWrite(StepZ,LOW); 
      delayMicroseconds(500);
    }
    delay(1000); // delay for 1 second
  }
  ///////////////////////////////////////////////////////////////////////////////////////
  else
  {
    digitalWrite(DirX, HIGH); // set direction, HIGH for clockwise, LOW for anticlockwise
    for(int i = 0; i<num_steps; i++) 
    { // loop for num_steps steps
      digitalWrite(StepX,HIGH);
      delayMicroseconds(500);
      digitalWrite(StepX,LOW); 
      delayMicroseconds(500);
    }
    delay(1000); // delay for 1 second
    digitalWrite(DirX, LOW); // set direction, HIGH for clockwise, LOW for anticlockwise
    for(int i = 0; i<num_steps; i++) 
    { // loop for num_steps steps
      digitalWrite(StepX,HIGH);
      delayMicroseconds(500);
      digitalWrite(StepX,LOW); 
      delayMicroseconds(500);
    }
    delay(1000); // delay for 1 second
    /////////////////////////////////////////////////////////////////////////////////////
    digitalWrite(DirY, HIGH); // set direction, HIGH for clockwise, LOW for anticlockwise
    for(int i = 0; i<num_steps; i++) 
    { // loop for num_steps steps
      digitalWrite(StepY,HIGH);
      delayMicroseconds(500);
      digitalWrite(StepY,LOW); 
      delayMicroseconds(500);
    }
    delay(1000); // delay for 1 second
    digitalWrite(DirY, LOW); // set direction, HIGH for clockwise, LOW for anticlockwise
    for(int i = 0; i<num_steps; i++) 
    { // loop for num_steps steps
      digitalWrite(StepY,HIGH);
      delayMicroseconds(500);
      digitalWrite(StepY,LOW); 
      delayMicroseconds(500);
    }
    delay(1000); // delay for 1 second
    /////////////////////////////////////////////////////////////////////////////////////
    digitalWrite(DirZ, HIGH); // set direction, HIGH for clockwise, LOW for anticlockwise
    for(int i = 0; i<num_steps; i++) 
    { // loop for num_steps steps
      digitalWrite(StepZ,HIGH);
      delayMicroseconds(500);
      digitalWrite(StepZ,LOW); 
      delayMicroseconds(500);
    }
    delay(1000); // delay for 1 second
    digitalWrite(DirZ, LOW); // set direction, HIGH for clockwise, LOW for anticlockwise
    for(int i = 0; i<num_steps; i++) 
    { // loop for num_steps steps
      digitalWrite(StepZ,HIGH);
      delayMicroseconds(500);
      digitalWrite(StepZ,LOW); 
      delayMicroseconds(500);
    }
    delay(1000); // delay for 1 second
  ///////////////////////////////////////////////////////////////////////////////////////
  }
}
