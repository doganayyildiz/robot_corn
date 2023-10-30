#include <Servo.h>
Servo left;
Servo right;
Servo top;

int ses_sensoru = 12;

int alkis = 0;
long algilama_araligi_baslangic = 0;
long algilama_araligi = 0;

boolean robot = false;

int randomMotion;

void setup() {
//Serial.begin(9600);
pinMode(ses_sensoru, INPUT);

top.attach(9);
left.attach(10);
right.attach(11);

top.write(140);
left.write(80);
right.write(80);

}

void loop() {
int sensor_durumu = digitalRead(ses_sensoru);
randomMotion = random(3);
if (sensor_durumu == 1){
    if (alkis == 0){
      algilama_araligi_baslangic = algilama_araligi = millis();
      alkis++;
      //Serial.println("alkis");
    }
    else if (alkis > 0 && millis()-algilama_araligi >= 50){
      algilama_araligi = millis();
      alkis++;
      //Serial.println("alkis");
    }
  }
if (millis()-algilama_araligi_baslangic >= 400){
    if (alkis == 2){

      if (!robot){
          robot = true;
          wake_up();
          delay(200);
          if(randomMotion == 0){
            for(int i=0; i<3; i++){
            motion();
            delay(100);
          } 
          }
          else if(randomMotion == 1){
            motion2();
            delay(200);
          }
          else if(randomMotion == 2){
            motion3();
            delay(200);
          }
          
        }

        else if (robot){
          robot = false;
          sleep();
          delay(200);
        }
    }
    alkis = 0;
  }

}

void sleep(){
  top.write(140);
  left.write(70);
  right.write(90);
}

void wake_up(){
  top.write(90);
  left.write(80);
  right.write(80);
}

void motion(){

  top.write(90);
  left.write(110);
  right.write(120);
  delay(700);

  top.write(90);
  left.write(50);
  right.write(60);
  delay(700);

  top.write(90);
  left.write(90);
  right.write(90);
  delay(350); 
 
}

void motion2(){
  for(int i=1; i<=30; i++){
    top.write(90);
    left.write(80+i);
    right.write(90+i);
    delay(60);
  }
  delay(1000);

  top.write(90);
  left.write(50);
  right.write(60);
  delay(800);
  for(int i=0; i<2; i++){
    sleep();
    delay(200);
    wake_up();
    delay(200);
  }

}

void motion3(){
  for(int i=1; i<=30; i++){
    top.write(90);
    left.write(80-i);
    right.write(90-i);
    delay(60);
  }
  delay(1000);

  top.write(90);
  left.write(110);
  right.write(120);
  delay(800);
  for(int i=0; i<2; i++){
    sleep();
    delay(200);
    wake_up();
    delay(200);
  }
}