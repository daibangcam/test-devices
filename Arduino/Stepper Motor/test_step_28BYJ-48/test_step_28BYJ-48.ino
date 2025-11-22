#include <AccelStepper.h>
#define HALFSTEP 8
#define FULLSTEP 4

#define blue 2
#define pink 3
#define yellow 4
#define orange 5

//Clockwise (true) or Counterclockwise(false)
//We'll default to clockwise
bool clockwise = true;

// How many steps to go before reversing
// int targetPosition = 2048;  //2049 steps per rotation when wave or full stepping
// int targetPosition = 4096;  //4096 steps per rotation when half stepping
int targetPosition = 800;
int homePosition = 0;

AccelStepper stepper1(HALFSTEP, blue, yellow, pink, orange);

void setup() {
  //Set the initial speed (read the AccelStepper docs on what "speed" means
  stepper1.setSpeed(1000.0);         
  //Tell it how fast to accelerate
  stepper1.setAcceleration(3000.0); 
  //Set a maximum speed it should exceed 
  stepper1.setMaxSpeed(6000.0);      
  //Tell it to move to the target position
  // // stepper1.moveTo(targetPosition); 
  // stepper1.moveTo(600);  
}

void loop() 
{
  //Check to see if the stepper has reached the target:
  if(stepper1.distanceToGo() == 0)
  {
    if(clockwise == true){
      clockwise = false;  //Go counterclockwise now
      stepper1.moveTo(homePosition); //Go back to the "home" (original) position
    } else 
    {
      clockwise = true;   //Go clockwise now
      stepper1.moveTo(targetPosition);  //Go to the target position
    }
  }  
  // If the stepper still needs to move (distanceToGo() != 0)
  // continue to advance (step) the motor
  stepper1.run();
}