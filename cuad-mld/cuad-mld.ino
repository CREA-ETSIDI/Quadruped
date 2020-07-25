


#include <Wire.h>
#include <Adafruit_PWMServoDriver>
#include <SoftwareSerial.h>
SoftwareSerial BT1(10, 11); // RX | TX

// called this way, it uses the default address 0x40
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
// you can also call it with a different address you want
//Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x41);
// you can also call it with a different address and I2C interface
//Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40, Wire);

// Depending on your servo make, the pulse width min and max may vary, you 
// want these to be as small/large as possible without hitting the hard stop
// for max range. You'll have to tweak them as necessary to match the servos you
// have!
#define SERVOMIN  300 // This is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  400
#define NEOMIN 250
#define NEOMAX 420
#define USMIN  600 // This is the rounded 'minimum' microsecond length based on the minimum pulse of 150
#define USMAX  2400 // This is the rounded 'maximum' microsecond length based on the maximum pulse of 600
#define SERVO_FREQ 50 // Analog servos run at ~50 Hz updates

// our servo # counter
uint8_t servo1 = 0;
uint8_t servo2 = 1;
uint8_t servo3 = 3;
uint8_t servo4 = 4;
uint8_t servo5 = 6;
uint8_t servo6 = 7;
uint8_t servo7 = 9;
uint8_t servo8 = 10;
void setup() {
  Serial.begin(9600);
  Serial.println();
  pwm.begin();
  // In theory the internal oscillator is 25MHz but it really isn't
  // that precise. You can 'calibrate' by tweaking this number till
  // you get the frequency you're expecting!
  pwm.setOscillatorFrequency(27000000);  // The int.osc. is closer to 27MHz  
  pwm.setPWMFreq(SERVO_FREQ);  // Analog servos run at ~50 Hz updates

  delay(10);
  pinMode(8,INPUT);
  pinMode(9,INPUT);
  pinMode(10,INPUT);
  pinMode(11,INPUT);
  pinMode(12,INPUT);
  reposo();
  delay(1000);
  Wire.setClock(100000);//puede ir hasta 400 kHz para movimientos muy rapidos. Cuidado con esto
}


void loop() {
  //Falanges azules servomin 300 y servomax 400
  //Falanges negras neomin 250 neomax 420
  int estado;
  int bot1=LOW;
  int bot2=LOW;
  int bot3=LOW;
  bot1=digitalRead(8);
  bot2=digitalRead(9);
  bot3=digitalRead(10);
  if (bot1==HIGH){
    pwm.setPWM(servo4, 0, SERVOMAX);
    pwm.setPWM(servo3, 0, NEOMAX);
    pwm.setPWM(servo5, 0, NEOMIN);
    pwm.setPWM(servo6, 0, SERVOMAX);
    delay(1000);
    pwm.setPWM(servo4, 0, SERVOMIN);
    pwm.setPWM(servo6, 0, SERVOMIN);
    delay(1000);
    pwm.setPWM(servo3, 0, NEOMIN);
    pwm.setPWM(servo5, 0, NEOMAX);
  }
  if (bot2==HIGH){
    reposo();
  }
  
}
void reposo()
{
  //Azules
  pwm.setPWM(servo2, 0, NEOMIN);
  pwm.setPWM(servo4, 0, NEOMIN);
  pwm.setPWM(servo6, 0, NEOMIN);
  pwm.setPWM(servo8, 0, NEOMIN);
  //Negras
  pwm.setPWM(servo1, 0, SERVOMIN);
  pwm.setPWM(servo3, 0, SERVOMIN);
  pwm.setPWM(servo5, 0, SERVOMIN);
  pwm.setPWM(servo7, 0, SERVOMIN);
  delay(200);
}
void espera1()
{
  for(int i=0; i<=1; i++)
  {
    pwm.setPWM(servo6,0,SERVOMIN-80);
    delay(100);
    pwm.setPWM(servo6,0,SERVOMIN-50);
    delay(100);
    pwm.setPWM(servo8,0,SERVOMIN-80);
    delay(100);
    pwm.setPWM(servo8,0,SERVOMIN-50);
    delay(100);
  }
}
void adelante()
{
  for(int i=0; i<=1; i++)
  {
    //DiagonaL1
    pwm.setPWM(servo4, 0, SERVOMAX);
    pwm.setPWM(servo3, 0, NEOMAX);
    pwm.setPWM(servo5, 0, NEOMIN);
    pwm.setPWM(servo6, 0, SERVOMAX);
    delay(1000);
    pwm.setPWM(servo4, 0, SERVOMIN);
    pwm.setPWM(servo6, 0, SERVOMIN);
    delay(1000);
    pwm.setPWM(servo3, 0, NEOMIN);
    pwm.setPWM(servo5, 0, NEOMAX);
    //DiagonaL2
    pwm.setPWM(servo1, 0, NEOMIN);
    pwm.setPWM(servo7, 0, NEOMAX);
    pwm.setPWM(servo2, 0, SERVOMAX);
    pwm.setPWM(servo8, 0, SERVOMAX);
    delay(1000);
    pwm.setPWM(servo2, 0, SERVOMIN);
    pwm.setPWM(servo8, 0, SERVOMIN);
    delay(1000);
    pwm.setPWM(servo1, 0, NEOMAX);
    pwm.setPWM(servo7, 0, NEOMIN);
  }
}
void fast()
{
  for(int i=0; i<=1; i++)
  {
    //DiagonaL1
    pwm.setPWM(servo4, 0, SERVOMAX);
    pwm.setPWM(servo3, 0, NEOMAX);
    pwm.setPWM(servo5, 0, NEOMIN);
    pwm.setPWM(servo6, 0, SERVOMAX);
    delay(100);
    pwm.setPWM(servo4, 0, SERVOMIN);
    pwm.setPWM(servo6, 0, SERVOMIN);
    delay(1000);
    pwm.setPWM(servo3, 0, NEOMIN);
    pwm.setPWM(servo5, 0, NEOMAX);
    //DiagonaL2
    pwm.setPWM(servo1, 0, NEOMIN);
    pwm.setPWM(servo7, 0, NEOMAX);
    pwm.setPWM(servo2, 0, SERVOMAX);
    pwm.setPWM(servo8, 0, SERVOMAX);
    delay(100);
    pwm.setPWM(servo2, 0, SERVOMIN);
    pwm.setPWM(servo8, 0, SERVOMIN);
    delay(1000);
    pwm.setPWM(servo1, 0, NEOMAX);
    pwm.setPWM(servo7, 0, NEOMIN);
  }
}
