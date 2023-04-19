
void motorOff(int motor)
{
 for (int i = 0; i < 2; i++)
 {
   digitalWrite(inApin[i], LOW);
   digitalWrite(inBpin[i], LOW);
 }
 analogWrite(pwmpin[motor], 0);
}

void motorGo(uint8_t motor, uint8_t direct, uint8_t pwm)
{
 if (motor <= 1)
 {
   if (direct <= 4)
   {
     if (direct <= 1)
       digitalWrite(inApin[motor], HIGH);
     else
       digitalWrite(inApin[motor], LOW);

     // Set to INB[motor]
     if ((direct == 0) || (direct == 2))
       digitalWrite(inBpin[motor], HIGH);
     else
       digitalWrite(inBpin[motor], LOW);

     analogWrite(pwmpin[motor], pwm);
   }
 }
}
