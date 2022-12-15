/*
 Relay Control with PWM reading value
 */

 #define PWM_INPUT_PIN A0 // MIN 978 ~ MAX 1990 ( MIDDLE 1500 )
#define relay1 13
#define relay2 12
#define relay3 11

int PWM_value = 0;

void setup() {
  Serial.begin(9600);
  pinMode(PWM_INPUT_PIN, INPUT);

  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
}

void loop() {
  PWM_value = pulseIn(PWM_INPUT_PIN, HIGH);
// Serial.println(PWM_value);

  if( (1500 < PWM_value) && (PWM_value < 1600) ){
    Serial.print(PWM_value);
    Serial.println(": realy1 On");
    digitalWrite(relay1, HIGH);
    digitalWrite(relay2, LOW);
    digitalWrite(relay3, LOW);
    delay(1000);
  }
  if( (1600 < PWM_value) && (PWM_value < 1700) ){
    Serial.print(PWM_value);
    Serial.println(": realy2 On");
    digitalWrite(relay2, HIGH);
    digitalWrite(relay1, LOW);
    digitalWrite(relay3, LOW);
    delay(1000);
  }
  if( (1700 < PWM_value) && (PWM_value < 1800) ){
    Serial.print(PWM_value);
    Serial.println(": realy3 On");
    digitalWrite(relay3, HIGH);
    digitalWrite(relay1, LOW);
    digitalWrite(relay2, LOW);
    delay(1000);
  }

  if( (1800 < PWM_value) && (PWM_value < 1900) ){ // All at once Turn On
    Serial.print(PWM_value);
    Serial.println(":Turn on all at once");
    digitalWrite(relay1, HIGH);
    digitalWrite(relay2, HIGH);
    digitalWrite(relay3, HIGH);
    delay(1000);
  }

  if( PWM_value < 1500 ){ // All at once Turn Off
    Serial.print(PWM_value);
    Serial.println(":Turn off all at once");
    digitalWrite(relay1, LOW);
    digitalWrite(relay2, LOW);
    digitalWrite(relay3, LOW);
    delay(1000);
  }
}
