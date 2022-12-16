/*
 Relay Control with PWM reading value
 */
#define PWM_LEFT_ALL  1100
#define PWM_LEFT_1    1175
#define PWM_LEFT_2    1250
#define PWM_LEFT_3    1325
#define PWM_LEFT_4    1400
#define PWM_LEFT_5    1475

#define PWM_RIGHT_ALL 1550
#define PWM_RIGHT_1   1625
#define PWM_RIGHT_2   1700
#define PWM_RIGHT_3   1775
#define PWM_RIGHT_4   1850
#define PWM_RIGHT_5   1925

#define PWM_R_RESET     1925

const int PWM_INPUT_PIN = A0; // MIN 978 ~ MAX 1990 ( MIDDLE 1500 )
const int relay1 = 13; 
const int relay2 = 12;
const int relay3 = 11;

int PWM_in = 0;
bool flgL_1, flgL_2, flgL_3, flgL_4, flgL_5, flgL_All, flgL_Reset = 0;
bool flgR_1, flgR_2, flgR_3, flgR_4, flgR_5, flgR_All, flgR_Reset = 0;
/*
 The PWM value read from the Arduino is slightly different from 
 the value sent from the mission planner. In the case of Cube Orange FC, 
 there is a difference of -8 to -15. The reason is still unknown. 
 For other FCs, we don't know how the results will be different.
 */
#define ADJUSTMENT_RANGE 15
void setup() {
  Serial.begin(9600);
  pinMode(PWM_INPUT_PIN, INPUT);

  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
}

void loop() {
  PWM_in = pulseIn(PWM_INPUT_PIN, HIGH);
//  Serial.println(PWM_in);

  if( !flgR_1 && ( PWM_RIGHT_1==(PWM_in+ADJUSTMENT_RANGE)) ){//Relay1(Red)
    Serial.print(PWM_in);
    Serial.println(": R side realy1 On"); 
    digitalWrite(relay1, HIGH);
    digitalWrite(relay2, LOW);
    digitalWrite(relay3, LOW);
    flgR_1=1;
    flgR_2=0;
    flgR_3=0;
    flgR_Reset = 0;
  }
  if( !flgR_2 && ( PWM_RIGHT_2==(PWM_in+ADJUSTMENT_RANGE)) ){//Relay2(Green)
    Serial.print(PWM_in);
    Serial.println(": R side realy2 On");
    digitalWrite(relay2, HIGH);
    digitalWrite(relay1, LOW);
    digitalWrite(relay3, LOW);
    flgR_2=1;
    flgR_1=0;
    flgR_3=0;
    flgR_Reset = 0;
  }
  if( !flgR_3 && ( PWM_RIGHT_3==(PWM_in+ADJUSTMENT_RANGE)) ){//Relay3(Blue)
    Serial.print(PWM_in);
    Serial.println(": R side realy3 On"); // Blue LED
    digitalWrite(relay3, HIGH);
    digitalWrite(relay1, LOW);
    digitalWrite(relay2, LOW);
    flgR_3=1;
    flgR_1=0;
    flgR_2=0;
    flgR_Reset = 0;
  }
  if( !flgR_All && ( PWM_RIGHT_ALL==(PWM_in+ADJUSTMENT_RANGE)) ){//All at once(White)
    Serial.print(PWM_in);
    Serial.println(": Turn on all R side Relays at once");
    digitalWrite(relay1, HIGH);
    digitalWrite(relay2, HIGH);
    digitalWrite(relay3, HIGH);
    flgR_1=1;
    flgR_2=1;
    flgR_3=1;
    flgR_4=1;
    flgR_5=1;
    flgR_All=1;
    flgR_Reset = 0;
  }
  if( !flgR_Reset && ( PWM_R_RESET==(PWM_in+ADJUSTMENT_RANGE)) ){//Reset
    Serial.print(PWM_in);
    Serial.println(": Reset all Right side Relays");
    digitalWrite(relay1, LOW);
    digitalWrite(relay2, LOW);
    digitalWrite(relay3, LOW);
    flgR_1 = 0;
    flgR_2 = 0;
    flgR_3 = 0;
    flgR_4 = 0;
    flgR_5 = 0;
    flgR_All = 0;
    flgR_Reset = 1;
  }
}
