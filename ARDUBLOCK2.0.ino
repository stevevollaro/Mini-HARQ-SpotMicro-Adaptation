long FRL_0 = 130 - 10;
long FRA_1 = 41 - 10;
long FRS_2 = 85 - 10;
long BRL_3 = 130 - 10;
long BRA_4 = 50 - 10;
long BRS_5 = 85 - 10;
long BLL_6 = 45 - 10;
long BLA_7 = 145 - 10;
long BLS_8 = 100 - 10;
long FLL_9 = 45 - 10;
long FLA_10 = 145 - 10;
long FLS_11 = 90 - 10;
int i;

#include <iarduino_MultiServo.h>
 iarduino_MultiServo MSS0x40;

void Bathroom_Break() {
  for (int count = 0; count < 20; count++) {
    MSS0x40.servoWrite(5,byte((BRS_5 + i)));
    delay(0.1*1000);
    i = i + 1;
  }
  delay(0.1*1000);
  MSS0x40.servoWrite(8,byte((BLS_8 + 50)));
  delay(5*1000);
  MSS0x40.servoWrite(8,byte(BLS_8));
  delay(0.1*1000);
  MSS0x40.servoWrite(5,byte(BRS_5));
}

void Step_Forward() {
  calibration();
  delay(1*1000);
  MSS0x40.servoWrite(11,byte((FLS_11 + 10)));
  delay(0.5*1000);
  MSS0x40.servoWrite(0,byte((FRL_0 + 15)));
  delay(0.5*1000);
  MSS0x40.servoWrite(1,byte((FRA_1 + 10)));
  delay(0.1*1000);
  MSS0x40.servoWrite(0,byte(((FRL_0 + 15) - 10)));
  delay(0.1*1000);
  MSS0x40.servoWrite(11,byte(FLS_11));
  delay(0.5*1000);
  MSS0x40.servoWrite(5,byte((BRS_5 + 10)));
  delay(0.5*1000);
  MSS0x40.servoWrite(6,byte((BLL_6 - 15)));
  delay(0.5*1000);
  MSS0x40.servoWrite(7,byte((BLA_7 - 10)));
  delay(0.1*1000);
  MSS0x40.servoWrite(6,byte(((BLL_6 - 15) + 10)));
  delay(0.1*1000);
  MSS0x40.servoWrite(5,byte(BRS_5));
  delay(0.5*1000);
  MSS0x40.servoWrite(8,byte((BLS_8 - 10)));
  delay(0.5*1000);
  MSS0x40.servoWrite(3,byte((BRL_3 + 15)));
  delay(0.5*1000);
  MSS0x40.servoWrite(4,byte((BRA_4 + 10)));
  delay(0.1*1000);
  MSS0x40.servoWrite(3,byte(((BRL_3 + 15) - 10)));
  delay(0.1*1000);
  MSS0x40.servoWrite(8,byte(BLS_8));
  delay(0.5*1000);
  MSS0x40.servoWrite(2,byte((FRS_2 - 10)));
  delay(0.5*1000);
  MSS0x40.servoWrite(9,byte((FLL_9 - 15)));
  delay(0.5*1000);
  MSS0x40.servoWrite(10,byte((FLA_10 - 10)));
  delay(0.1*1000);
  MSS0x40.servoWrite(9,byte(((FLL_9 - 15) + 10)));
  delay(0.1*1000);
  MSS0x40.servoWrite(2,byte(FRS_2));
}

void Turn_Left() {
  calibration();
  delay(1*1000);
  MSS0x40.servoWrite(2,byte((FRS_2 - 10)));
  MSS0x40.servoWrite(8,byte((BLS_8 - 10)));
  MSS0x40.servoWrite(0,byte((FRL_0 + 10)));
  MSS0x40.servoWrite(6,byte((BLL_6 - 10)));
  delay(0.5*1000);
  MSS0x40.servoWrite(5,byte((BRS_5 - 10)));
  MSS0x40.servoWrite(11,byte((FLS_11 - 10)));
  MSS0x40.servoWrite(4,byte((BRA_4 - 10)));
  MSS0x40.servoWrite(10,byte((FLA_10 - 10)));
  delay(0.5*1000);
  calibration();
  delay(0.1*1000);
}

void Jog_In_Place() {
  calibration();
  for (int count = 0; count < 5; count++) {
    MSS0x40.servoWrite(1,byte((FRA_1 - 10)));
    MSS0x40.servoWrite(7,byte((BLA_7 + 10)));
    delay(1*1000);
    MSS0x40.servoWrite(1,byte(FRA_1));
    MSS0x40.servoWrite(7,byte(BLA_7));
    delay(1*1000);
    MSS0x40.servoWrite(4,byte((BRA_4 - 10)));
    MSS0x40.servoWrite(10,byte((FLA_10 + 10)));
    delay(1*1000);
    MSS0x40.servoWrite(4,byte(BRA_4));
    MSS0x40.servoWrite(10,byte(FLA_10));
    delay(1*1000);
  }
}

void calibration() {
  MSS0x40.servoWrite(0,byte(FRL_0));
  MSS0x40.servoWrite(1,byte(FRA_1));
  MSS0x40.servoWrite(2,byte(FRS_2));
  MSS0x40.servoWrite(3,byte(BRL_3));
  MSS0x40.servoWrite(4,byte(BRA_4));
  MSS0x40.servoWrite(5,byte(BRS_5));
  MSS0x40.servoWrite(6,byte(BLL_6));
  MSS0x40.servoWrite(7,byte(BLA_7));
  MSS0x40.servoWrite(8,byte(BLS_8));
  MSS0x40.servoWrite(9,byte(FLL_9));
  MSS0x40.servoWrite(10,byte(FLA_10));
  MSS0x40.servoWrite(11,byte(FLS_11));
}

void Walk_10_mm() {
  for (int count = 0; count < 2; count++) {
    Step_Forward();
  }
}

void calibration3() {
  MSS0x40.servoWrite(0,byte(FRL_0));
}

void Stop() {
  delay(3600*1000);
}

void Turn_Left_45_deg() {
  for (int count = 0; count < 3; count++) {
    Turn_Left();
  }
}


void setup() {
    calibration();

    MSS0x40.servoSet(0, SERVO_SG90);
 MSS0x40.servoSet(1, SERVO_SG90);
  MSS0x40.servoSet(2, SERVO_SG90);
 MSS0x40.servoSet(3, SERVO_SG90);
 MSS0x40.servoSet(4, SERVO_SG90);
 MSS0x40.servoSet(5, SERVO_SG90);
 MSS0x40.servoSet(6, SERVO_SG90);
 MSS0x40.servoSet(7, SERVO_SG90);
 MSS0x40.servoSet(8, SERVO_SG90);
 MSS0x40.servoSet(9, SERVO_SG90);
 MSS0x40.servoSet(10, SERVO_SG90);
 MSS0x40.servoSet(11, SERVO_SG90);
 MSS0x40.servoSet(12, SERVO_SG90);
 MSS0x40.servoSet(13, SERVO_SG90);
 MSS0x40.servoSet(14, SERVO_SG90);
 MSS0x40.servoSet(15, SERVO_SG90);
 MSS0x40.servoSet(16, SERVO_SG90);
 MSS0x40.begin(0x40);

}

void loop() {
    Walk_10_mm();
    Bathroom_Break();
    Walk_10_mm();
    Turn_Left_45_deg();
    Walk_10_mm();
    Stop();
}
