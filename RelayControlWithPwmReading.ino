/*
  Relay Control with PWM reading value
  Relay Module: LK 임베디드 6channel HL-56S (Low Level Trigger)
*/

//--------Left Side PWM VALUE -----------
#define PWM_L_00000   1000
#define PWM_L_00001   1015  // button 5
#define PWM_L_00010   1030  // button 4
#define PWM_L_00011   1045
#define PWM_L_00100   1060  // button 3
#define PWM_L_00101   1075
#define PWM_L_00110   1090
#define PWM_L_00111   1105
#define PWM_L_01000   1120  // button 2
#define PWM_L_01001   1135

#define PWM_L_01010   1150
#define PWM_L_01011   1165
#define PWM_L_01100   1180
#define PWM_L_01101   1195
#define PWM_L_01110   1210
#define PWM_L_01111   1225
#define PWM_L_10000   1240  // button 1
#define PWM_L_10001   1255
#define PWM_L_10010   1270
#define PWM_L_10011   1285

#define PWM_L_10100   1300
#define PWM_L_10101   1315
#define PWM_L_10110   1330
#define PWM_L_10111   1345
#define PWM_L_11000   1360  // button 1,2
#define PWM_L_11001   1375
#define PWM_L_11010   1390
#define PWM_L_11011   1405
#define PWM_L_11100   1420  // button 1,2,3
#define PWM_L_11101   1435

#define PWM_L_11110   1450  // button 1,2,3,4
#define PWM_L_11111   1465  // button 1,2,3,4,5

//--------Right Side PWM VALUE -----------------
#define PWM_R_00000   1500
#define PWM_R_00001   1515  // button 5
#define PWM_R_00010   1530  // button 4
#define PWM_R_00011   1545
#define PWM_R_00100   1560  // button 3
#define PWM_R_00101   1575
#define PWM_R_00110   1590
#define PWM_R_00111   1605
#define PWM_R_01000   1620  // button 2
#define PWM_R_01001   1635

#define PWM_R_01010   1650
#define PWM_R_01011   1665
#define PWM_R_01100   1680
#define PWM_R_01101   1695
#define PWM_R_01110   1710
#define PWM_R_01111   1725
#define PWM_R_10000   1740 // button 1
#define PWM_R_10001   1755
#define PWM_R_10010   1770
#define PWM_R_10011   1785

#define PWM_R_10100   1800
#define PWM_R_10101   1815
#define PWM_R_10110   1830
#define PWM_R_10111   1845
#define PWM_R_11000   1860
#define PWM_R_11001   1875
#define PWM_R_11010   1890
#define PWM_R_11011   1905
#define PWM_R_11100   1920
#define PWM_R_11101   1935

#define PWM_R_11110   1950
#define PWM_R_11111   1965  // button 1,2,3,4,5




const int PWM_INPUT_PIN = A0; // MIN 978 ~ MAX 1990 ( MIDDLE 1500 )
const int relay1 = 12;
const int relay2 = 11;
const int relay3 = 10;
const int relay4 = 9;
const int relay5 = 8;

const int relay6 = 7;
const int relay7 = 6;
const int relay8 = 5;
const int relay9 = 4;
const int relay10 = 3;

int PWM_in = 0;
bool flgL_1, flgL_2, flgL_3, flgL_4, flgL_5, flgL_All, flgL_Reset = 0;
bool flgR_1, flgR_2, flgR_3, flgR_4, flgR_5, flgR_All, flgR_Reset = 0;
/*
  The PWM value read from the Arduino is slightly different from
  the value sent from the mission planner. In the case of Cube Orange FC,
  there is a difference of -8 to -15. The reason is still unknown.
  For other FCs, we don't know how the results will be different.
*/
#define ADJUSTMENT_RANGE 14
#define DECREASE  4

void launchLeft();
void launchRgith();

void setup() {
  Serial.begin(9600);
  pinMode(PWM_INPUT_PIN, INPUT);

  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(relay4, OUTPUT);
  pinMode(relay5, OUTPUT);

  pinMode(relay6, OUTPUT);
  pinMode(relay7, OUTPUT);
  pinMode(relay8, OUTPUT);
  pinMode(relay9, OUTPUT);
  pinMode(relay10, OUTPUT);

  digitalWrite(relay1, HIGH); // Low Level Trigger  Relay
  digitalWrite(relay2, HIGH);
  digitalWrite(relay3, HIGH);
  digitalWrite(relay4, HIGH);
  digitalWrite(relay5, HIGH);
  digitalWrite(relay6, HIGH);
  digitalWrite(relay7, HIGH);
  digitalWrite(relay8, HIGH);
  digitalWrite(relay9, HIGH);
  digitalWrite(relay10, HIGH);
}

void loop() {
    PWM_in = pulseIn(PWM_INPUT_PIN, HIGH);
    Serial.println(PWM_in);
    //delay(100);

    launchLeft();
   // delay(100);
    launchRight();
  //  delay(100);

}

void launchLeft()
{
  if ( ( (PWM_L_00000 - ADJUSTMENT_RANGE) < PWM_in ) &&
       ( PWM_in <= PWM_L_00000-DECREASE  )                          )
  {
    digitalWrite(relay1, HIGH);
    digitalWrite(relay2, HIGH);
    digitalWrite(relay3, HIGH);
    digitalWrite(relay4, HIGH);
    digitalWrite(relay5, HIGH);
//    Serial.println("L 0 0 0 0 0");
  }

  else if ( ( (PWM_L_00001 - ADJUSTMENT_RANGE) < PWM_in ) &&
            ( PWM_in <= PWM_L_00001-DECREASE )                        )
  {
    digitalWrite(relay5, LOW);
//    Serial.println("L 0 0 0 0 1");
  }

  else if ( ( (PWM_L_00010 - ADJUSTMENT_RANGE) < PWM_in ) &&
            ( PWM_in <= PWM_L_00010-DECREASE  )                        )
  {
    digitalWrite(relay4, LOW);
//    Serial.println("L 0 0 0 1 0");
  }

  else if ( ( (PWM_L_00011 - ADJUSTMENT_RANGE) < PWM_in ) &&
            ( PWM_in <= PWM_L_00011-DECREASE  )                        )
  {
    digitalWrite(relay4, LOW);
    digitalWrite(relay5, LOW);
//    Serial.println("L 0 0 0 1 1");
  }

  else if ( ( (PWM_L_00100 - ADJUSTMENT_RANGE) < PWM_in ) &&
            ( PWM_in <= PWM_L_00100-DECREASE  )                        )
  {
    digitalWrite(relay3, LOW);
//    Serial.println("L 0 0 1 0 0");
  }

  else if ( ( (PWM_L_00101 - ADJUSTMENT_RANGE) < PWM_in ) &&
            ( PWM_in <= PWM_L_00101-DECREASE  )                        )
  {
    digitalWrite(relay3, LOW);
    digitalWrite(relay5, LOW);
//    Serial.println("L 0 0 1 0 1");
  }

  else if ( ( (PWM_L_00110 - ADJUSTMENT_RANGE) < PWM_in ) &&
            ( PWM_in <= PWM_L_00110-DECREASE  )                        )
  {
    digitalWrite(relay3, LOW);
    digitalWrite(relay4, LOW);
 //   Serial.println("L 0 0 1 1 0");
  }

  else if ( ( (PWM_L_00111 - ADJUSTMENT_RANGE) < PWM_in ) &&
            ( PWM_in <= PWM_L_00111-DECREASE  )                        )
  {
    digitalWrite(relay3, LOW);
    digitalWrite(relay4, LOW);
    digitalWrite(relay5, LOW);
//    Serial.println("L 0 0 1 1 1");
  }

  else if ( ( (PWM_L_01000 - ADJUSTMENT_RANGE) < PWM_in ) &&
            ( PWM_in <= PWM_L_01000-DECREASE  )                        )
  {
    digitalWrite(relay2, LOW);
//    Serial.println("L 0 1 0 0 0");
  }

  else if ( ( (PWM_L_01001 - ADJUSTMENT_RANGE) < PWM_in ) &&
            ( PWM_in <= PWM_L_01001-DECREASE  )                        )
  {
    digitalWrite(relay2, LOW);
    digitalWrite(relay5, LOW);
//    Serial.println("L 0 1 0 0 1");
  }

  else if ( ( (PWM_L_01010 - ADJUSTMENT_RANGE) < PWM_in ) &&
            ( PWM_in <= PWM_L_01010-DECREASE  )                        )
  {
    digitalWrite(relay2, LOW);
    digitalWrite(relay4, LOW);
//    Serial.println("L 0 1 0 1 0");
  }

  else if ( ( (PWM_L_01011 - ADJUSTMENT_RANGE) < PWM_in ) &&
            ( PWM_in <= PWM_L_01011-DECREASE )                        )
  {
    digitalWrite(relay2, LOW);
    digitalWrite(relay4, LOW);
    digitalWrite(relay5, LOW);
//    Serial.println("L 0 1 0 1 1");
  }

  else if ( ( (PWM_L_01100 - ADJUSTMENT_RANGE) < PWM_in ) &&
            ( PWM_in <= PWM_L_01100-DECREASE  )                        )
  {
    digitalWrite(relay2, LOW);
    digitalWrite(relay3, LOW);
//    Serial.println("L 0 1 1 0 0");
  }

  else if ( ( (PWM_L_01101 - ADJUSTMENT_RANGE) < PWM_in ) &&
            ( PWM_in <= PWM_L_01101-DECREASE  )                        )
  {
    digitalWrite(relay2, LOW);
    digitalWrite(relay3, LOW);
    digitalWrite(relay5, LOW);
//    Serial.println("L 0 1 1 0 1");
  }

  else if ( ( (PWM_L_01110 - ADJUSTMENT_RANGE) < PWM_in ) &&
            ( PWM_in <= PWM_L_01110-DECREASE  )                        )
  {
    digitalWrite(relay2, LOW);
    digitalWrite(relay3, LOW);
    digitalWrite(relay4, LOW);
//    Serial.println("L 0 1 1 1 0");
  }

  else if ( ( (PWM_L_01111 - ADJUSTMENT_RANGE) < PWM_in ) &&
            ( PWM_in <= PWM_L_01111-DECREASE  )                        )
  {
    digitalWrite(relay2, LOW);
    digitalWrite(relay3, LOW);
    digitalWrite(relay4, LOW);
    digitalWrite(relay5, LOW);
//    Serial.println("L 0 1 1 1 1");
  }

  else if ( ( (PWM_L_10000 - ADJUSTMENT_RANGE) < PWM_in ) &&
            ( PWM_in <= PWM_L_10000-DECREASE  )                        )
  {
    digitalWrite(relay1, LOW);
//    Serial.println("L 1 0 0 0 0");
  }

  else if ( ( (PWM_L_10001 - ADJUSTMENT_RANGE) < PWM_in ) &&
            ( PWM_in <= PWM_L_10001-DECREASE  )                        )
  {
    digitalWrite(relay1, LOW);
    digitalWrite(relay5, LOW);
//    Serial.println("L 1 0 0 0 1");
  }

  else if ( ( (PWM_L_10010 - ADJUSTMENT_RANGE) < PWM_in ) &&
            ( PWM_in <= PWM_L_10010-DECREASE  )                        )
  {
    digitalWrite(relay1, LOW);
    digitalWrite(relay4, LOW);
//    Serial.println("L 1 0 0 1 0");
  }

  else if ( ( (PWM_L_10011 - ADJUSTMENT_RANGE) < PWM_in ) &&
            ( PWM_in <= PWM_L_10011-DECREASE  )                        )
  {
    digitalWrite(relay1, LOW);
    digitalWrite(relay4, LOW);
    digitalWrite(relay5, LOW);
//    Serial.println("L 1 0 0 1 1");
  }

  else if ( ( (PWM_L_10100 - ADJUSTMENT_RANGE) < PWM_in ) &&
            ( PWM_in <= PWM_L_10100-DECREASE  )                        )
  {
    digitalWrite(relay1, LOW);
    digitalWrite(relay3, LOW);
//    Serial.println("L 1 0 1 0 0");
  }

  else if ( ( (PWM_L_10101 - ADJUSTMENT_RANGE) < PWM_in ) &&
            ( PWM_in <= PWM_L_10101-DECREASE  )                        )
  {
    digitalWrite(relay1, LOW);
    digitalWrite(relay3, LOW);
    digitalWrite(relay5, LOW);
//    Serial.println("L 1 0 1 0 1");
  }

  else if ( ( (PWM_L_10110 - ADJUSTMENT_RANGE) < PWM_in ) &&
            ( PWM_in <= PWM_L_10110-DECREASE  )                        )
  {
    digitalWrite(relay1, LOW);
    digitalWrite(relay3, LOW);
    digitalWrite(relay4, LOW);
//    Serial.println("L 1 0 1 1 0");
  }

  else if ( ( (PWM_L_10111 - ADJUSTMENT_RANGE) < PWM_in ) &&
            ( PWM_in <= PWM_L_10111-DECREASE  )                        )
  {
    digitalWrite(relay1, LOW);
    digitalWrite(relay3, LOW);
    digitalWrite(relay4, LOW);
    digitalWrite(relay5, LOW);
 //   Serial.println("L 1 0 1 1 1");
  }

  else if ( ( (PWM_L_11000 - ADJUSTMENT_RANGE) < PWM_in ) &&
            ( PWM_in <= PWM_L_11000-DECREASE  )                        )
  {
    digitalWrite(relay1, LOW);
    digitalWrite(relay2, LOW);
//    Serial.println("L 1 1 0 0 0");
  }

  else if ( ( (PWM_L_11001 - ADJUSTMENT_RANGE) < PWM_in ) &&
            ( PWM_in <= PWM_L_11001-DECREASE  )                        )
  {
    digitalWrite(relay1, LOW);
    digitalWrite(relay2, LOW);
    digitalWrite(relay5, LOW);
//    Serial.println("L 1 1 0 0 1");
  }

  else if ( ( (PWM_L_11010 - ADJUSTMENT_RANGE) < PWM_in ) &&
            ( PWM_in <= PWM_L_11010-DECREASE  )                        )
  {
    digitalWrite(relay1, LOW);
    digitalWrite(relay2, LOW);
    digitalWrite(relay4, LOW);
//    Serial.println("L 1 1 0 1 0");
  }

  else if ( ( (PWM_L_11011 - ADJUSTMENT_RANGE) < PWM_in ) &&
            ( PWM_in <= PWM_L_11011-DECREASE  )                        )
  {
    digitalWrite(relay1, LOW);
    digitalWrite(relay2, LOW);
    digitalWrite(relay4, LOW);
    digitalWrite(relay5, LOW);
//    Serial.println("L 1 1 0 1 1");
  }

  else if ( ( (PWM_L_11100 - ADJUSTMENT_RANGE) < PWM_in ) &&
            ( PWM_in <= PWM_L_11100-DECREASE  )                        )
  {
    digitalWrite(relay1, LOW);
    digitalWrite(relay2, LOW);
    digitalWrite(relay3, LOW);
//    Serial.println("L 1 1 1 0 0");
  }

  else if ( ( (PWM_L_11101 - ADJUSTMENT_RANGE) < PWM_in ) &&
            ( PWM_in <= PWM_L_11101-DECREASE  )                        )
  {
    digitalWrite(relay1, LOW);
    digitalWrite(relay2, LOW);
    digitalWrite(relay3, LOW);
    digitalWrite(relay5, LOW);
//    Serial.println("L 1 1 1 0 1");
  }

  else if ( ( (PWM_L_11110 - ADJUSTMENT_RANGE) < PWM_in ) &&
            ( PWM_in <= PWM_L_11110-DECREASE  )                        )
  {
    digitalWrite(relay1, LOW);
    digitalWrite(relay2, LOW);
    digitalWrite(relay3, LOW);
    digitalWrite(relay4, LOW);
//    Serial.println("L 1 1 1 1 0");
  }

  else if ( ( (PWM_L_11111 - ADJUSTMENT_RANGE) < PWM_in ) &&
            ( PWM_in <= PWM_L_11111-DECREASE  )                         )
  {
    digitalWrite(relay1, LOW);
    digitalWrite(relay2, LOW);
    digitalWrite(relay3, LOW);
    digitalWrite(relay4, LOW);
    digitalWrite(relay5, LOW);
//    Serial.println("L 1 1 1 1 1");
  }
}

void launchRight()
{
  if ( ( (PWM_R_00000 - ADJUSTMENT_RANGE) < PWM_in ) &&
       (  PWM_in <= PWM_R_00000-DECREASE)                          )
  {
    digitalWrite(relay6, HIGH);
    digitalWrite(relay7, HIGH);
    digitalWrite(relay8, HIGH);
    digitalWrite(relay9, HIGH);
    digitalWrite(relay10, HIGH);
//   Serial.println("R 0 0 0 0 0");
  }

  else if ( ( (PWM_R_00001 - ADJUSTMENT_RANGE) < PWM_in ) &&
            ( PWM_in <= PWM_R_00001-DECREASE )                        )
  {
    digitalWrite(relay10, LOW);
//    Serial.println("R 0 0 0 0 1");
  }

  else if ( ( (PWM_R_00010 - ADJUSTMENT_RANGE) < PWM_in ) &&
            ( PWM_in <= PWM_R_00010-DECREASE  )                        )
  {
    digitalWrite(relay9, LOW);
//    Serial.println("R 0 0 0 1 0");
  }

  else if ( ( (PWM_R_00011 - ADJUSTMENT_RANGE) < PWM_in ) &&
            ( PWM_in <= PWM_R_00011-DECREASE  )                        )
  {
    digitalWrite(relay9, LOW);
    digitalWrite(relay10, LOW);
//  Serial.println("R 0 0 0 1 1");
  }

  else if ( ( (PWM_R_00100 - ADJUSTMENT_RANGE) < PWM_in ) &&
            ( PWM_in <= PWM_R_00100-DECREASE  )                        )
  {
    digitalWrite(relay8, LOW);
//    Serial.println("R 0 0 1 0 0");
  }

  else if ( ( (PWM_R_00101 - ADJUSTMENT_RANGE) < PWM_in ) &&
            ( PWM_in <= PWM_R_00101-DECREASE  )                        )
  {
    digitalWrite(relay8, LOW);
    digitalWrite(relay10, LOW);
//    Serial.println("R 0 0 1 0 1");
  }

  else if ( ( (PWM_R_00110 - ADJUSTMENT_RANGE) < PWM_in ) &&
            ( PWM_in <= PWM_R_00110-DECREASE  )                        )
  {
    digitalWrite(relay8, LOW);
    digitalWrite(relay9, LOW);
//    Serial.println("R 0 0 1 1 0");
  }

  else if ( ( (PWM_R_00111 - ADJUSTMENT_RANGE) < PWM_in ) &&
            ( PWM_in <= PWM_R_00111-DECREASE  )                        )
  {
    digitalWrite(relay8, LOW);
    digitalWrite(relay9, LOW);
    digitalWrite(relay10, LOW);
//    Serial.println("R 0 0 1 1 1");
  }

  else if ( ( (PWM_R_01000 - ADJUSTMENT_RANGE) < PWM_in ) &&
            ( PWM_in <= PWM_R_01000-DECREASE  )                        )
  {
    digitalWrite(relay7, LOW);
//    Serial.println("R 0 1 0 0 0");
  }

  else if ( ( (PWM_R_01001 - ADJUSTMENT_RANGE) < PWM_in ) &&
            ( PWM_in <= PWM_R_01001-DECREASE  )                        )
  {
    digitalWrite(relay7, LOW);
    digitalWrite(relay10, LOW);
//    Serial.println("R 0 1 0 0 1");
  }

  else if ( ( (PWM_R_01010 - ADJUSTMENT_RANGE) < PWM_in ) &&
            ( PWM_in <= PWM_R_01010-DECREASE  )                        )
  {
    digitalWrite(relay7, LOW);
    digitalWrite(relay9, LOW);
//   Serial.println("R 0 1 0 1 0");
  }

  else if ( ( (PWM_R_01011 - ADJUSTMENT_RANGE) < PWM_in ) &&
            ( PWM_in <= PWM_R_01011-DECREASE  )                        )
  {
    digitalWrite(relay7, LOW);
    digitalWrite(relay9, LOW);
    digitalWrite(relay10, LOW);
//    Serial.println("R 0 1 0 1 1");
  }

  else if ( ( (PWM_R_01100 - ADJUSTMENT_RANGE) < PWM_in ) &&
            ( PWM_in <= PWM_R_01100-DECREASE  )                        )
  {
    digitalWrite(relay7, LOW);
    digitalWrite(relay8, LOW);
    Serial.println("R 0 1 1 0 0");
    delay(2000);
  }

  else if ( ( (PWM_R_01101 - ADJUSTMENT_RANGE) < PWM_in ) &&
            ( PWM_in <= PWM_R_01101-DECREASE  )                        )
  {
    digitalWrite(relay7, LOW);
    digitalWrite(relay8, LOW);
    digitalWrite(relay10, LOW);
//    Serial.println("R 0 1 1 0 1");
  }

  else if ( ( (PWM_R_01110 - ADJUSTMENT_RANGE) < PWM_in ) &&
            ( PWM_in <= PWM_R_01110-DECREASE  )                        )
  {
    digitalWrite(relay7, LOW);
    digitalWrite(relay8, LOW);
    digitalWrite(relay9, LOW);
//    Serial.println("R 0 1 1 1 0");
  }

  else if ( ( (PWM_R_01111 - ADJUSTMENT_RANGE) < PWM_in ) &&
            ( PWM_in <= PWM_R_01111-DECREASE  )                        )
  {
    digitalWrite(relay7, LOW);
    digitalWrite(relay8, LOW);
    digitalWrite(relay9, LOW);
    digitalWrite(relay10, LOW);
//    Serial.println("R 0 1 1 1 1");
  }

  else if ( ( (PWM_R_10000 - ADJUSTMENT_RANGE-2) < PWM_in ) &&
            ( PWM_in <= PWM_R_10000-DECREASE  )                        )
  {
    digitalWrite(relay6, LOW);
//    Serial.println("R 1 0 0 0 0");
  }

  else if ( ( (PWM_R_10001 - ADJUSTMENT_RANGE-2) < PWM_in ) &&
            ( PWM_in <= PWM_R_10001-DECREASE  )                        )
  {
    digitalWrite(relay6, LOW);
    digitalWrite(relay10, LOW);
//    Serial.println("R 1 0 0 0 1");
  }

  else if ( ( (PWM_R_10010 - ADJUSTMENT_RANGE-2) < PWM_in ) &&
            ( PWM_in <= PWM_R_10010-DECREASE  )                        )
  {
    digitalWrite(relay6, LOW);
    digitalWrite(relay9, LOW);
//    Serial.println("R 1 0 0 1 0");
  }

  else if ( ( (PWM_R_10011 - ADJUSTMENT_RANGE-2) < PWM_in ) &&
            ( PWM_in <= PWM_R_10011-DECREASE  )                        )
  {
    digitalWrite(relay6, LOW);
    digitalWrite(relay9, LOW);
    digitalWrite(relay10, LOW);
//    Serial.println("R 1 0 0 1 1");
  }

  else if ( ( (PWM_R_10100 - ADJUSTMENT_RANGE-2) < PWM_in ) &&
            ( PWM_in <= PWM_R_10100-DECREASE  )                        )
  {
    digitalWrite(relay6, LOW);
    digitalWrite(relay8, LOW);
//    Serial.println("R 1 0 1 0 0");
  }

  else if ( ( (PWM_R_10101 - ADJUSTMENT_RANGE-2) < PWM_in ) &&
            ( PWM_in <= PWM_R_10101-DECREASE  )                        )
  {
    digitalWrite(relay6, LOW);
    digitalWrite(relay8, LOW);
    digitalWrite(relay10, LOW);
//    Serial.println("R 1 0 1 0 1");
  }

  else if ( ( (PWM_R_10110 - ADJUSTMENT_RANGE-2) < PWM_in ) &&
            ( PWM_in <= PWM_R_10110-DECREASE  )                        )
  {
    digitalWrite(relay6, LOW);
    digitalWrite(relay9, LOW);
    digitalWrite(relay10, LOW);
//    Serial.println("R 1 0 1 1 0");
  }

  else if ( ( (PWM_R_10111 - ADJUSTMENT_RANGE-2) < PWM_in ) &&
            ( PWM_in <= PWM_R_10111-DECREASE  )                        )
  {
    digitalWrite(relay6, LOW);
    digitalWrite(relay8, LOW);
    digitalWrite(relay9, LOW);
    digitalWrite(relay10, LOW);
//    Serial.println("R 1 0 1 1 1");
  }

  else if ( ( (PWM_R_11000 - ADJUSTMENT_RANGE-2) < PWM_in ) &&
            ( PWM_in <= PWM_R_11000-DECREASE  )                        )
  {
    digitalWrite(relay6, LOW);
    digitalWrite(relay7, LOW);
//   Serial.println("R 1 1 0 0 0");
  }

  else if ( ( (PWM_R_11001 - ADJUSTMENT_RANGE-2) < PWM_in ) &&
            ( PWM_in <= PWM_R_11001-DECREASE  )                        )
  {
    digitalWrite(relay6, LOW);
    digitalWrite(relay7, LOW);
    digitalWrite(relay10, LOW);
//    Serial.println("R 1 1 0 0 1");
  }

  else if ( ( (PWM_R_11010 - ADJUSTMENT_RANGE-2) < PWM_in ) &&
            ( PWM_in <= PWM_R_11010-DECREASE  )                        )
  {
    digitalWrite(relay6, LOW);
    digitalWrite(relay7, LOW);
    digitalWrite(relay9, LOW);
//    Serial.println("R 1 1 0 1 0");
  }

  else if ( ( (PWM_R_11011 - ADJUSTMENT_RANGE-2) < PWM_in ) &&
            ( PWM_in <= PWM_R_11011-DECREASE  )                        )
  {
    digitalWrite(relay6, LOW);
    digitalWrite(relay7, LOW);
    digitalWrite(relay9, LOW);
    digitalWrite(relay10, LOW);
//    Serial.println("R 1 1 0 1 1");
  }

  else if ( ( (PWM_R_11100 - ADJUSTMENT_RANGE-2) < PWM_in ) &&
            ( PWM_in <= PWM_R_11100-DECREASE  )                        )
  {
    digitalWrite(relay6, LOW);
    digitalWrite(relay7, LOW);
    digitalWrite(relay8, LOW);
//    Serial.println("R 1 1 1 0 0");
  }

  else if ( ( (PWM_R_11101 - ADJUSTMENT_RANGE-2) < PWM_in ) &&
            ( PWM_in <= PWM_R_11101-DECREASE  )                        )
  {
    digitalWrite(relay6, LOW);
    digitalWrite(relay7, LOW);
    digitalWrite(relay8, LOW);
    digitalWrite(relay10, LOW);
//    Serial.println("R 1 1 1 0 1");
  }

  else if ( ( (PWM_R_11110 - ADJUSTMENT_RANGE-2) < PWM_in ) &&
            ( PWM_in <= PWM_R_11110-DECREASE  )                        )
  {
    digitalWrite(relay6, LOW);
    digitalWrite(relay7, LOW);
    digitalWrite(relay8, LOW);
    digitalWrite(relay9, LOW);
//    Serial.println("R 1 1 1 1 0");
  }

  else if ( ( (PWM_R_11111 - ADJUSTMENT_RANGE-2) < PWM_in ) &&
            ( PWM_in <= PWM_R_11111-DECREASE  )                         )
  {
    digitalWrite(relay6, LOW);
    digitalWrite(relay7, LOW);
    digitalWrite(relay8, LOW);
    digitalWrite(relay9, LOW);
    digitalWrite(relay10, LOW);
//    Serial.println("R 1 1 1 1 1");
  }
}
