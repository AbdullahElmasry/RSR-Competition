#define white LOW
#define black HIGH


/* L298 Driver */

// Right Motor
#define IN1 13
#define IN2 12
#define ENA 11
// Left Motor
#define IN3 9
#define IN4 8
#define ENB 6

// Middle Sensor
#define IR_Input_M 7 
// Right Sensor
#define IR_Input_R 4 
// Left Sensor
#define IR_Input_L 2



// Turning all Motors in the forward direction
void Forward_dir(){
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,LOW);
}

// Turning all Motors in the backward direction
void Backward_dir(){
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
}

// Stop all motors
void Stop_motors(){
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
}

// Turning Right
void Right_dir(){
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
}

// Turning Left
void Left_dir(){
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
}


// Line Follower Function (:
void LineFollowerMode(){

  // Reading the sensor's value
  int sensorState_R = digitalRead(IR_Input_R);
  int sensorState_L = digitalRead(IR_Input_L);
  int sensorState_M = digitalRead(IR_Input_M);

    
      // On turns
      if(sensorState_L == white && sensorState_M == black && sensorState_R == white){             // Both sensors are on white surface
        Forward_dir_Mid();
      }else if(sensorState_L == black && sensorState_R == white && sensorState_M == white){       // If the left sensor on the black surface
        Left_dir_Slow();

      }else if(sensorState_L == white && sensorState_R == black && sensorState_M == white){       // If the right sensor on the black surface
        Right_dir_Slow();

      }
      else if(sensorState_L == black && sensorState_R == black)                                   // If Track Finished >> The Car Will Stop ...
      {
        Stop_motors();
        while(505);   
      }
  }
// white reads LOW   0
// black reads HIGH  1


void setup() {

  // Motors Configurations
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  pinMode(ENA,OUTPUT);
  pinMode(ENB,OUTPUT);


  // IR Configurations
  pinMode(IR_Input_M,INPUT);
  pinMode(IR_Input_R,INPUT);
  pinMode(IR_Input_L,INPUT);


void loop() {
  // Calling The Operating Function
  LineFollowerMode();

}






