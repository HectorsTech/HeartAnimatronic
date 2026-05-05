#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

// He subido un poco los límites de seguridad por si acaso
#define SERVOMIN  150 
#define SERVOMAX  580 

const int potPin = 34; 

int timePeriod = 1000;
float y = 0;
float t = 0;
float d = 330;

void setup() {
  Serial.begin(115200);
  pinMode(potPin, INPUT);
  
  pwm.begin();
  pwm.setPWMFreq(60); 

  delay(10);
}

void loop() {
  float i;
  
  int valorPot = analogRead(potPin);
  timePeriod = map(valorPot, 0, 4095, 2000, 300);

  // --- Fase de Latido ---
  for (i = 0; i < (3 * timePeriod / 40); i++) {
    y = sin(i / (timePeriod / 20.0));

    // ANTES: d = 430 - (y * 100); -> AHORA: 130 para más recorrido
    d = 430 - (y * 130); 
    
    // ANTES: t = 350 + (y * 50);  -> AHORA: 80 para más recorrido
    t = 350 + (y * 80);
    
    // Seguridad para no pasarnos de los límites del servo
    d = constrain(d, SERVOMIN, SERVOMAX);
    t = constrain(t, SERVOMIN, SERVOMAX);

    pwm.setPWM(0, 0, d);
    pwm.setPWM(1, 0, d);
    pwm.setPWM(2, 0, t);

    Serial.println(d); 
    delay(10);
  }

  // --- Pausas ---
  for (i = 0; i < (10 * timePeriod / 400); i++) {
    d = 430; 
    pwm.setPWM(0, 0, d);
    pwm.setPWM(1, 0, d);
    pwm.setPWM(2, 0, 350);

    Serial.println(d); 
    delay(10);
  }
}
