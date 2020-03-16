 /* Sample Rover Control
 * Wednesday, March 4, 2020
 * 
 * spins motors according to Serial input
 * 
 * hardest part
 * ===========
 * battery pack was broken and i didn't realize
 * 
 * 
 */

//Pin definition
#define RightEnA 10
#define RightEnB 11 
#define RightIn1 42 
#define RightIn2 40 
#define RightIn3 38 
#define RightIn4 36 
#define LeftEnA 3 
#define LeftEnB 4 
#define LeftIn1 37 
#define LeftIn2 39 
#define LeftIn3 41 
#define LeftIn4 43 

int val = 0;

void setup() {
  //Allow serial control
  Serial.begin(9600);
  Serial.println("not dead");
  
  //Set control pins to output
  pinMode(RightEnA, OUTPUT);
  pinMode(RightEnB, OUTPUT);
  pinMode(RightIn1, OUTPUT);
  pinMode(RightIn2, OUTPUT);
  pinMode(RightIn3, OUTPUT);
  pinMode(RightIn4, OUTPUT);
  pinMode(LeftEnA, OUTPUT);
  pinMode(LeftEnB, OUTPUT);
  pinMode(LeftIn1, OUTPUT);
  pinMode(LeftIn2, OUTPUT);
  pinMode(LeftIn3, OUTPUT);
  pinMode(LeftIn4, OUTPUT);
}

void loop() {
  if (Serial.available()){
    val = Serial.read();
    Serial.println(val);
  
    //Direction control
    if (240 <= val < 360) //Forward
    {
      drive(255,255);
    }
    else if (120 <= val < 240) //Left
    {
      drive(127,255);
    }
    else if (360 <= val < 480) //Right
    {
      drive(255,127);
    }
    else if (0 <= val < 120) //More left
    {
      drive(0,255);
    }
    else if (480 <= val <= 600) //More right
    {
      drive(255,0);
    }
    else if (val < 0 || val > 600) //Stop; error
    {
      drive(0,0);
    }
  }
}

void drive(int Lspeed, int Rspeed){
   if (Lspeed > 0){
      digitalWrite(LeftIn1, HIGH);
      digitalWrite(LeftIn2, LOW);
      analogWrite(LeftEnA, Lspeed); 
      digitalWrite(LeftIn3, HIGH);
      digitalWrite(LeftIn4, LOW);
      analogWrite(LeftEnB, Lspeed); 
   }
   else if (Lspeed < 0){
      digitalWrite(LeftIn1, LOW);
      digitalWrite(LeftIn2, HIGH);
      analogWrite(LeftEnA, Lspeed); 
      digitalWrite(LeftIn3, LOW);
      digitalWrite(LeftIn4, HIGH);
      analogWrite(LeftEnB, Lspeed); 
   }
   else if (Lspeed == 0){
      digitalWrite(LeftIn1, LOW);
      digitalWrite(LeftIn2, LOW);
      digitalWrite(LeftIn3, LOW);
      digitalWrite(LeftIn4, LOW);
   }
   if (Rspeed > 0){
      digitalWrite(RightIn1, HIGH);
      digitalWrite(RightIn2, LOW);
      analogWrite(RightEnA, Rspeed); 
      digitalWrite(RightIn3, HIGH);
      digitalWrite(RightIn4, LOW);
      analogWrite(RightEnB, Rspeed); 
   }
   else if (Rspeed < 0){
      digitalWrite(RightIn1, LOW);
      digitalWrite(RightIn2, HIGH);
      analogWrite(RightEnA, Rspeed); 
      digitalWrite(RightIn3, LOW);
      digitalWrite(RightIn4, HIGH);
      analogWrite(RightEnB, Rspeed); 
   }
   else if (Rspeed == 0){
      digitalWrite(RightIn1, LOW);
      digitalWrite(RightIn2, LOW);
      digitalWrite(RightIn3, LOW);
      digitalWrite(RightIn4, LOW);
   }
}
