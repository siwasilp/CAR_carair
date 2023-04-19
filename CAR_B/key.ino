void key_x(){
  char key = keypad.getKey();

  if (key != NO_KEY) {
    xx_key = key;
    Serial.println(key);
    
 
//    if (key == 'B') {
//      lcd.setCursor(9, 3);
//      lcd.print("B");
//      motorGo(0, ClockWise, 255);
//      motorGo(1, ClockWise, 255);
//      delay(300);
//      motorOff(1); motorOff(2);
//    }
//    if (key == 'A') {
//      lcd.setCursor(9, 3);
//      lcd.print("G");
//      motorGo(0, CClockWise, 255);
//      motorGo(1, CClockWise, 255);
//      delay(300);
//      motorOff(1); motorOff(2);
//    }
//    if (key == 'D') {
//      lcd.setCursor(9, 3);
//      lcd.print("R");
//      motorGo(0, CClockWise, 255);
//      motorGo(1, ClockWise, 255);
//      delay(300);
//      motorOff(1); motorOff(2);
//    }
//    if (key == 'C') {
//      lcd.setCursor(9, 3);
//      lcd.print("L");
//      motorGo(0, ClockWise, 255);
//      motorGo(1, CClockWise, 255);
//      delay(300);
//      motorOff(1); motorOff(2);
//    }
    
  }
}
