void disp_0() {
  lcd.setCursor(0, 0);
  lcd.print("====================");
  lcd.setCursor(0, 1);
  lcd.print("   Car for Future.  ");
  lcd.setCursor(0, 2);
  lcd.print("Precision.Engineer#2");
  lcd.setCursor(0, 3);
  lcd.print("====================");
  delay(1000);
  for (int i = 0 ; i < 3 ; i++) {
    digitalWrite(lamp, HIGH);
    digitalWrite(alrm, HIGH);
    delay(250);
    digitalWrite(lamp, LOW);
    digitalWrite(alrm, LOW);
    delay(250);
  }
  delay(1000);
  lcd.clear();
}

void disp_now() {
  lcd.setCursor(0, 0);
  lcd.print("NOW_ROBOT : ");

  if (tag == 999) {
    lcd.print("Unkonw!!");
  }
  else if (tag == 1) {
    lcd.print("HOME    ");
  }
  else {
    lcd.print(tag);
    lcd.print("       ");
  }

  lcd.setCursor(0, 1);
  lcd.print("LOAD_CELL : ");
  lcd.print(data);

  lcd.setCursor(0, 2);
  lcd.print("#KEY : ");
  lcd.setCursor(7, 2);
  lcd.print(xx_key);

  lcd.setCursor(10, 2);
  lcd.print("#LCR : ");
  lcd.print(ll);
  lcd.print(cc);
  lcd.print(rr);

  //-------------------------------------------


  if (xx_key == '*' && sts_k == 2) {
    int runx = 1;
    while (runx) {
      rfid_x();

      digitalWrite(lamp, HIGH);
      lcd.setCursor(0, 3);
      lcd.print("#STS : Move ");
      lcd.print(tag);
      lcd.print(" to ");
      lcd.print(now_x);
      lcd.print("  ");
      if ( now_x == tag) {
        lcd.setCursor(0, 3);
        lcd.print("#STS : OK!!!        ");
        runx = 0;
        sts_k = 0;
        delay(2000);
        digitalWrite(lamp, LOW);
        xx_key = " ";
        break;
      }
    }
  }

  if (sts_k == 0) {
    lcd.setCursor(0, 3);
    lcd.print("#STS : READY!!!     ");
  }

  if (xx_key == '#') {
    digitalWrite(alrm, HIGH);
    lcd.setCursor(0, 3);
    lcd.print("#STS : STOP!!!      ");

  }
  if (xx_key == '0') {
    digitalWrite(alrm, LOW);
    digitalWrite(lamp, LOW);
  }

  if (xx_key == '1' || xx_key == '2' || xx_key == '3' || xx_key == '4' || xx_key == '5' || xx_key == '6' || xx_key == '7' || xx_key == '8' || xx_key == '9')
  {
    now_x = int(xx_key) - 48;
    sts_k = 1;
  }

  if (sts_k == 1) {
    lcd.setCursor(0, 3);
    lcd.print("#STS : Plase * Move.");
    sts_k = 2;
  }



}
