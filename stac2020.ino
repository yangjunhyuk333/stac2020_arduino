#include <SoftwareSerial.h>
#include <MPU6050_tockn.h>
#include <Wire.h>

SoftwareSerial BTSerial(1, 0); //블루투스 모듈 HC-06 모듈 핀 설정 (TX, RX)

MPU6050 mpu6050(Wire);

float Y;

void setup() {               
  Serial.begin(9600); //pc와 연결

  //블루투스 연결
  BTSerial.begin(9600);

  //자이로센서 각도 계산 시작 
  setAngelY();
}

void loop() {
}


//----------------------------------------------

//초기 Y값을 설정하는 함수
void setAngelY(){
  Wire.begin();
  mpu6050.begin();

  mpu6050.calcGyroOffsets(true);

  mpu6050.update();

  while(1){
    if(mpu6050.getGyroYoffset() > -10.0 && mpu6050.getGyroYoffset() < 10.0){
      Y = mpu6050.getGyroYoffset();
       Serial.print(Y);
       BTSerial.print(Y);
       break;
    }else{
       continue;
    }
  }
}
