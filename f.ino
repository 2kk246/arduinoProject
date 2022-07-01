WidgetLED led1(V10);
void Stepper1 (int n_angle){
  if((n_angle - t_angle)>=0){
    my_Stepper.step(-stepsPerRevolution/360*(n_angle - t_angle));
    t_angle = n_angle;
    }
  if((n_angle - t_angle)<0){
    my_Stepper.step(stepsPerRevolution/360*(t_angle - n_angle));
    t_angle = n_angle;
    }
  }

//slide
BLYNK_WRITE(V0)
{
  n_angle = param.asInt();
  Stepper1(n_angle);

  if (0 < t_angle and t_angle < 35){Blynk.virtualWrite(V5,"약불");Blynk.virtualWrite(V1,t_angle);led1.off();}
  if (35 <= t_angle and t_angle < 70){Blynk.virtualWrite(V5,"중불");Blynk.virtualWrite(V1,t_angle);led1.off();}
  if (70 <= t_angle and t_angle <= 90){Blynk.virtualWrite(V5,"강불");Blynk.virtualWrite(V1,t_angle);led1.off();}
  if (t_angle == 0){
    Blynk.virtualWrite(V5,"소화");
    Blynk.virtualWrite(V1,t_angle);
    led1.on();
    delay(10000);
    led1.off();
    
    Blynk.virtualWrite(V5,"강불로 맞춰주세요");
    t_angle = 90;
    Blynk.virtualWrite(V1,t_angle);
    Stepper1(t_angle); //change motor to 90 degree
  }
}

//timer
BLYNK_WRITE(V6){
  my_Stepper.step(stepsPerRevolution/360*(t_angle));
  Serial.println("타이머 동작");
  Blynk.virtualWrite(V5, "타이머 소화");
  
  t_angle=0;
  Blynk.virtualWrite(V1,t_angle);
  led1.on();
}
