void setup_x()
{
  Serial.begin(9600);
  SPI.begin();
  RC522.init();
  scale.set_scale(calibration_factor);
  scale.set_offset(zero_factor);
  pinMode(alrm, OUTPUT);
  pinMode(lamp, OUTPUT);
  lcd.begin();
  lcd.backlight();
  pinMode(statpin, OUTPUT);

  for (int i = 0; i < 2; i++)
  {
    pinMode(inApin[i], OUTPUT);
    pinMode(inBpin[i], OUTPUT);
    pinMode(pwmpin[i], OUTPUT);
  }
  for (int i = 0; i < 2; i++)
  {
    digitalWrite(inApin[i], LOW);
    digitalWrite(inBpin[i], LOW);
  }
 
}

void loadcell() 
{ 
  Serial.print("Reading: ");
  data = String(get_units_kg()+offset, DEC_POINT);
  Serial.print(data);
  Serial.println(" kg ");
}
float get_units_kg()
{
  return(scale.get_units()*0.453592);
}

void rfid() {
  if (RC522.isCard()) {
    RC522.readCardSerial();
    Serial.print("Card :");
    for (int i = 0; i < 5; i++) {
      Serial.print(RC522.serNum[i], DEC);
    }
    Serial.println();
  }
}
