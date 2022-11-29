#include <AFMotor.h>


#include <Servo.h>              
Servo name_servo;               

int servo_position = 0 ;
AF_DCMotor motor1(1); // Ground motor 1
AF_DCMotor motor2(2); //Ground motor 2
AF_DCMotor motor3(3); // Mop motor
AF_DCMotor motor4(4); // Platform Motor

int del = 0;
char command; //Int to store app command state.
char sizee;
char mystr[3];
int speedCar = 255; // Initial car speed set 0 to 255.
void setup()
{
    Serial.begin(9600);
    name_servo.attach (10); 
    name_servo.write(0); 
    
//    Stop();
}

void forward()
{
  motor1.run(FORWARD);
  motor2.run(FORWARD);
 
  motor1.setSpeed(speedCar);
  motor2.setSpeed(speedCar);
  //delay(del);
}

void backward()
{
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor1.setSpeed(speedCar);
  motor2.setSpeed(speedCar);
}


void go()
{
  motor3.run(FORWARD);
  motor3.setSpeed(speedCar);
}

void Stop()
{
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  Serial.println("Intitiated");
  motor4.run(RELEASE);
}

void upward()
{
  motor4.run(FORWARD);
  motor4.setSpeed(speedCar);
}

void downward()
{
  motor4.run(BACKWARD);
  motor4.setSpeed(speedCar);
}
void stopmotor()
{
  motor3.run(RELEASE);
}


int firstbutton(){
  int var = 0;
  Serial.println("Arrived at first");
  char first;
  while(true){
  if (Serial.available() > 0) {
      first = Serial.read();
      Serial.println(first);
      break;
  }
  }
  Serial.println(int(first));
  int j = int(first)-48;
  for(int i = 0;i<j;i++){
    int temp;
    while(true){
    if (Serial.available() > 0) {
      temp = Serial.read();
      Serial.println("temp found");
      Serial.println(temp);
      break;
     }
   }
   temp-=48;
   Serial.println("***************************************************FINAL/////////////////////////////temp***********************************************************************************************************************************************************************");
   Serial.println(temp);
    Serial.println("***************************************************FINAL/////////////////////////////temp***********************************************************************************************************************************************************************");
   var += temp*pow(10,j-1-i);
   Serial.println("Varr");
   Serial.println(var);
  }

  Serial.println("**********************************Final Varr*********************************");
  Serial.println(var);
  Serial.println("Exiting from first");
  return var;
}


int secondbutton(){
  int var1 = 0;
  Serial.println("Arrived at Second");
  char first1;
  while(true){
  if (Serial.available() > 0) {
      first1 = Serial.read();
      Serial.println(first1);
      break;
  }
  }
  Serial.println(int(first1));
  int j1 = int(first1)-48;
  for(int i = 0;i<j1;i++){
    int temp1;
    while(true){
    if (Serial.available() > 0) {
      temp1 = Serial.read();
      Serial.println("temp found");
      Serial.println(temp1);
      break;
     }
   }
   temp1-=48;
   Serial.println("***************************************************FINAL/////////////////////////////temp***********************************************************************************************************************************************************************");
   Serial.println(temp1);
    Serial.println("***************************************************FINAL/////////////////////////////temp***********************************************************************************************************************************************************************");
   var1 += temp1*pow(10,j1-1-i);
   Serial.println("Varr");
   Serial.println(var1);
  }

  Serial.println("**********************************Final Varr*********************************");
  Serial.println(var1);
  Serial.println("Exiting from Second");
  return var1 ;
}



void text1() {
  int len = 0,width = 0;
   if(command == 'H'){
    Serial.println("Hlo going to first");
    len = firstbutton();
   }
   char f;
   while(true){
    if (Serial.available() > 0) {
      f = Serial.read();
      Serial.println("f found");
      Serial.println(f);
      break;
     }
   }
   Serial.println("                      ");
   Serial.println("                        ");
   Serial.println("                         ");
   if(f == 'Q'){
    Serial.println("Hlo going to second");
    width = secondbutton();
   }

//*****************************************************************************************

    char f1;
   while(true){
    if (Serial.available() > 0) {
      f1 = Serial.read();
      Serial.println("f found");
      Serial.println(f1);
      break;
     }
   }
   Serial.println("                      ");
   Serial.println("                        ");
   Serial.println("                         ");
   if(f1 == 'E'){
    Serial.println("***************Initating***********************");

    //********************************To be tested Accondingly***************************
    forward();
    delay(len);
    upward();
    delay(len);

    //********************************To be tested Accondingly***************************
   }
    

//********************************************************************************************


   
  return;
 }


 
void loop(){
     
  if (Serial.available() > 0) {
      command = Serial.read();
      //Stop();       //Initialize with motors stopped.
  Serial.println(command);
  switch (command) {
      case 'F':forward();break;
      case 'B':backward();break;
      case 'D':downward();break;
      case 'G':go();break;
      case 'S':Stop();break;
      case 'U':upward();break;
      case 'M':stopmotor();break;
      case 'H':text1();break;
      case 'Q':text1();break;
      }
   // Stop();
  }

}
