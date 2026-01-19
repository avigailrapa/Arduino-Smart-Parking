#include <Servo.h>
Servo myServo;
int pos=0;

#define PARKING A0//חיישן כניסת רכב
#define SERVO 9
#define LIGHT A1// חיישן תפוס/פנוי
#define RED 11
#define GREEN 5
#define BLUE 6
#define POWER A5
#define BUZZER 8

void setup() {
  Serial.begin(9600);
  myServo.attach(SERVO);

  pinMode(GREEN,OUTPUT);
  pinMode(BLUE,OUTPUT);
  pinMode(RED,OUTPUT);
  pinMode(BUZZER, OUTPUT);

  pinMode(PARKING,INPUT);
  pinMode(LIGHT,INPUT);
  pinMode(POWER, INPUT);
}
void lights(int r,int g,int b)
{
  analogWrite(RED,r);
  analogWrite(GREEN,g);
  analogWrite(BLUE,b);
 
}


void loop() {

  int parkingValue = analogRead(PARKING);
  int lightValue = analogRead(LIGHT);

  Serial.print("Parking: "); Serial.print(parkingValue);
  Serial.print(" | Light: "); Serial.println(lightValue);

//מראה האם החניה תפוסה
 if (lightValue >= 850) {
    lights(0, 255, 0); 
  } else {
    lights(255, 0, 0); 
  }

  // בדיקה אם נכנס רכב והחנייה פנויה
  if (parkingValue < 850 && lightValue >= 850) {   
    //פתיחת השער
    for (pos = 0; pos <= 90; pos += 1) {
      myServo.write(pos);
      //הדלקת זמזם
      tone(BUZZER, 1000);
      delay(20);
    }
    noTone(BUZZER);
    delay(4000);
    //סגירת השער
    for (pos = 90; pos >= 0; pos -= 1) {
      myServo.write(pos);
      tone(BUZZER, 1000);
      delay(20);
    }
    noTone(BUZZER);
  }
  delay(100);

    
  }
 