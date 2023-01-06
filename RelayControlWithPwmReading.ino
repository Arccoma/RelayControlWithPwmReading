/*
 Relay Control with PWM reading value
 Relay Module: LK 임베디드 6channel HL-56S (Low Level Trigger)
 */
#define PWM_R_RESET     1000
#define PWM_L_RESET     1000

#define PWM_LEFT_1    1175
#define PWM_LEFT_2    1250
#define PWM_LEFT_3    1325
#define PWM_LEFT_4    1400
#define PWM_LEFT_5    1475
#define PWM_LEFT_ALL  1100

#define PWM_RIGHT_1   1625
#define PWM_RIGHT_2   1700
#define PWM_RIGHT_3   1775
#define PWM_RIGHT_4   1850
#define PWM_RIGHT_5   1925
#define PWM_RIGHT_ALL 1550
/*
#define PWM_LEFT_1    1100//1175
#define PWM_LEFT_2    1175//1250
#define PWM_LEFT_3    1250//1325
#define PWM_LEFT_4    1325//1400
#define PWM_LEFT_5    1400//1475
#define PWM_LEFT_ALL  1475//1100

#define PWM_RIGHT_1   1550//1625
#define PWM_RIGHT_2   1625//1700
#define PWM_RIGHT_3   1700//1775
#define PWM_RIGHT_4   1775//1850
#define PWM_RIGHT_5   1850//1925
#define PWM_RIGHT_ALL 1925//1550
*/

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
const int relay10 =3;

int PWM_in = 0;
bool flgL_1, flgL_2, flgL_3, flgL_4, flgL_5, flgL_All, flgL_Reset = 0;
bool flgR_1, flgR_2, flgR_3, flgR_4, flgR_5, flgR_All, flgR_Reset = 0;
/*
 The PWM value read from the Arduino is slightly different from 
 the value sent from the mission planner. In the case of Cube Orange FC, 
 there is a difference of -8 to -15. The reason is still unknown. 
 For other FCs, we don't know how the results will be different.
 */
#define ADJUSTMENT_RANGE 16
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

  digitalWrite(relay1,HIGH); // Low Level Trigger  Relay
  digitalWrite(relay2,HIGH);
  digitalWrite(relay3,HIGH);
  digitalWrite(relay4,HIGH);
  digitalWrite(relay5,HIGH);
  digitalWrite(relay6,HIGH);
  digitalWrite(relay7,HIGH);
  digitalWrite(relay8,HIGH);
  digitalWrite(relay9,HIGH);
  digitalWrite(relay10,HIGH);
}

void loop() {
  PWM_in = pulseIn(PWM_INPUT_PIN, HIGH);
  Serial.println(PWM_in);


if( !flgL_1 && 
      ( (PWM_LEFT_1-ADJUSTMENT_RANGE) < PWM_in ) &&  
      ( (PWM_LEFT_1+ADJUSTMENT_RANGE) > PWM_in ) )
  {
    Serial.print(PWM_in);
    Serial.println(": L side realy1 On"); 
    digitalWrite(relay1, LOW);
    flgL_1=1;
    flgL_Reset = 0;
  }
  if( !flgL_2 && 
      ( (PWM_LEFT_2-ADJUSTMENT_RANGE) < PWM_in ) &&
      ( (PWM_LEFT_2+ADJUSTMENT_RANGE) > PWM_in ) )
  {
    Serial.print(PWM_in);
    Serial.println(": L side realy2 On");
    digitalWrite(relay2, LOW);
    flgL_2=1;
    flgL_Reset = 0;
  }
  if( !flgL_3 && 
      ( (PWM_LEFT_3-ADJUSTMENT_RANGE) < PWM_in ) &&
      ( (PWM_LEFT_3+ADJUSTMENT_RANGE) > PWM_in ) )
  {
    Serial.print(PWM_in);
    Serial.println(": L side realy3 On");
    digitalWrite(relay3, LOW);
    flgL_3=1;
    flgL_Reset = 0;
  }
  if( !flgL_4 && 
      ( (PWM_LEFT_4-ADJUSTMENT_RANGE) < PWM_in ) &&
      ( (PWM_LEFT_4+ADJUSTMENT_RANGE) > PWM_in ) )
  {
    Serial.print(PWM_in);
    Serial.println(": L side realy4 On");
    digitalWrite(relay4, LOW);
    flgL_4=1;
    flgL_Reset = 0;
  }
  if( !flgL_5 && 
      ( (PWM_LEFT_5-ADJUSTMENT_RANGE) < PWM_in ) &&
      ( (PWM_LEFT_5+ADJUSTMENT_RANGE) > PWM_in ) )
  {
    Serial.print(PWM_in);
    Serial.println(": L side realy5 On");
    digitalWrite(relay5, LOW);
    flgL_5=1;
    flgL_Reset = 0;
  }

  // LEFT SIDE RELAY All at once
  if( !flgL_All && 
      ( (PWM_LEFT_ALL-ADJUSTMENT_RANGE) < PWM_in ) &&
      ( (PWM_LEFT_ALL+ADJUSTMENT_RANGE) > PWM_in ) )
  {
    Serial.print(PWM_in);
    Serial.println(": Turn on all L side Relays at once");
    digitalWrite(relay1, LOW);
    digitalWrite(relay2, LOW);
    digitalWrite(relay3, LOW);
    digitalWrite(relay4, LOW);
    digitalWrite(relay5, LOW);
    flgL_1=1;
    flgL_2=1;
    flgL_3=1;
    flgL_4=1;
    flgL_5=1;
    flgL_All=1;
    flgL_Reset = 0;
  }
  
  
  if( !flgL_Reset && ( PWM_R_RESET > PWM_in) ){//Reset
    Serial.print(PWM_in);
    Serial.println(": Reset all LEFT side Relays");
    digitalWrite(relay1, HIGH);
    digitalWrite(relay2, HIGH);
    digitalWrite(relay3, HIGH);
    digitalWrite(relay4, HIGH);
    digitalWrite(relay5, HIGH);
    flgL_1 = 0;
    flgL_2 = 0;
    flgL_3 = 0;
    flgL_4 = 0;
    flgL_5 = 0;
    flgL_All = 0;
    flgL_Reset = 1;
  }

//------------------------------------------------Rigth Side
  if( !flgR_1 && 
      ( (PWM_RIGHT_1-ADJUSTMENT_RANGE) < PWM_in ) &&  
      ( (PWM_RIGHT_1+ADJUSTMENT_RANGE) > PWM_in ) )
  {
    Serial.print(PWM_in);
    Serial.println(": R side realy1 On"); 
    digitalWrite(relay6, LOW); // Low level trigger relay
    flgR_1=1;
    flgR_Reset = 0;
  }
  if( !flgR_2 && 
      ( (PWM_RIGHT_2-ADJUSTMENT_RANGE) < PWM_in ) &&
      ( (PWM_RIGHT_2+ADJUSTMENT_RANGE) > PWM_in ) )
  {
    Serial.print(PWM_in);
    Serial.println(": R side realy2 On");
    digitalWrite(relay7, LOW);
    flgR_2=1;
    flgR_Reset = 0;
  }
  if( !flgR_3 && 
      ( (PWM_RIGHT_3-ADJUSTMENT_RANGE) < PWM_in ) &&
      ( (PWM_RIGHT_3+ADJUSTMENT_RANGE) > PWM_in ) )
  {
    Serial.print(PWM_in);
    Serial.println(": R side realy3 On"); // Blue LED
    digitalWrite(relay8, LOW);
    flgR_3=1;
    flgR_Reset = 0;
  }
  if( !flgR_4 && 
      ( (PWM_RIGHT_4-ADJUSTMENT_RANGE) < PWM_in ) &&
      ( (PWM_RIGHT_4+ADJUSTMENT_RANGE) > PWM_in ) )
  {
    Serial.print(PWM_in);
    Serial.println(": R side realy4 On");
    digitalWrite(relay9, LOW);
    flgR_4=1;
    flgR_Reset = 0;
  }
  if( !flgR_5 && 
      ( (PWM_RIGHT_5-ADJUSTMENT_RANGE) < PWM_in ) &&
      ( (PWM_RIGHT_5+ADJUSTMENT_RANGE) > PWM_in ) )
  {
    Serial.print(PWM_in);
    Serial.println(": R side realy5 On");
    digitalWrite(relay10, LOW);
    flgR_5=1;
    flgR_Reset = 0;
  }

  //All at once
  if( !flgR_All && 
      ( (PWM_RIGHT_ALL-ADJUSTMENT_RANGE) < PWM_in ) &&
      ( (PWM_RIGHT_ALL+ADJUSTMENT_RANGE) > PWM_in ) )
  {
    Serial.print(PWM_in);
    Serial.println(": Turn on all R side Relays at once");
    digitalWrite(relay6, LOW);
    digitalWrite(relay7, LOW);
    digitalWrite(relay8, LOW);
    digitalWrite(relay9, LOW);
    digitalWrite(relay10, LOW);
    flgR_1=1;
    flgR_2=1;
    flgR_3=1;
    flgR_4=1;
    flgR_5=1;
    flgR_All=1;
    flgR_Reset = 0;
  }
  
  if( !flgR_Reset && ( PWM_R_RESET > PWM_in) ){//Reset
    Serial.print(PWM_in);
    Serial.println(": Reset all Right side Relays");
    digitalWrite(relay6, HIGH);
    digitalWrite(relay7, HIGH);
    digitalWrite(relay8, HIGH);
    digitalWrite(relay9, HIGH);
    digitalWrite(relay10, HIGH);
    flgR_1 = 0;
    flgR_2 = 0;
    flgR_3 = 0;
    flgR_4 = 0;
    flgR_5 = 0;
    flgR_All = 0;
    flgR_Reset = 1;
  }
}
