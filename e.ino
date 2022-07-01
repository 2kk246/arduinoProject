#include <Stepper.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#define BLYNK_PRINT Serial

int stepsPerRevolution = 2048; 
Stepper my_Stepper(stepsPerRevolution, 13, 0, 14, 5); //node mcu

char auth[] = "RAHzBLpIpT_0lyonQtxi4gMh6g5wZvfl";
char ssid[] = "핫스파아앗";
char pass[] = "11223344";

int t_angle;
int n_angle;

void setup()
{
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass); 
  my_Stepper.setSpeed(8);
  Blynk.virtualWrite(V5,"강불로 맞춰주세요");
  t_angle = 90;
  Blynk.virtualWrite(V1,t_angle);
 }

void loop()
{
  Serial.print("t_angle : ");
  Serial.println(t_angle);
  Serial.print("n_angle : ");
  Serial.println(n_angle);
  delay(1000);
  Serial.println("");
  
  Blynk.run();
}
