void rfid_x() {
  if (RC522.isCard()) {
    digitalWrite(alrm, HIGH);
    RC522.readCardSerial();
    Serial.print("Card :");

    for (int i = 0; i < 5; i++) {
      Serial.print(i); Serial.print(">");
      Serial.print(RC522.serNum[i]);
      Serial.print(" ");
    }
    Serial.print(" TAG : ");

    //=========================================== TAG_CLEAR 9/9 ===========================================

    if (((RC522.serNum[0]) == 244) && ((RC522.serNum[1]) == 178) && ((RC522.serNum[2]) == 10) && ((RC522.serNum[3]) == 133) && ((RC522.serNum[4]) == 201)) {
      tag = 1;
    }
    else if (((RC522.serNum[0]) == 241) && ((RC522.serNum[1]) == 230) && ((RC522.serNum[2]) == 7) && ((RC522.serNum[3]) == 133) && ((RC522.serNum[4]) == 149)) {
      tag = 2;
    }
    else if (((RC522.serNum[0]) == 0) && ((RC522.serNum[1]) == 8) && ((RC522.serNum[2]) == 54) && ((RC522.serNum[3]) == 187) && ((RC522.serNum[4]) == 133))    {
      tag = 3;
    }
    else if (((RC522.serNum[0]) == 214) && ((RC522.serNum[1]) == 175) && ((RC522.serNum[2]) == 59) && ((RC522.serNum[3]) == 91) && ((RC522.serNum[4]) == 25)) {
      tag = 4;
    }
    else if (((RC522.serNum[0]) == 171) && ((RC522.serNum[1]) == 137) && ((RC522.serNum[2]) == 6) && ((RC522.serNum[3]) == 133) && ((RC522.serNum[4]) == 161)) {
      tag = 5;
    }
    else if (((RC522.serNum[0]) == 158) && ((RC522.serNum[1]) == 242) && ((RC522.serNum[2]) == 53) && ((RC522.serNum[3]) == 187) && ((RC522.serNum[4]) == 226)) {
      tag = 6;
    }
    else if (((RC522.serNum[0]) == 59) && ((RC522.serNum[1]) == 118) && ((RC522.serNum[2]) == 70) && ((RC522.serNum[3]) == 12) && ((RC522.serNum[4]) == 7)) {
      tag = 7;
    }
    else if (((RC522.serNum[0]) == 186) && ((RC522.serNum[1]) == 106) && ((RC522.serNum[2]) == 168) && ((RC522.serNum[3]) == 26) && ((RC522.serNum[4]) == 98)) {
      tag = 8;
    }
    else if (((RC522.serNum[0]) == 20) && ((RC522.serNum[1]) == 219) && ((RC522.serNum[2]) == 59) && ((RC522.serNum[3]) == 91) && ((RC522.serNum[4]) == 175)) {
      tag = 9;
    }
    else {
      tag = 999;
    }
    
    Serial.print(tag);
    Serial.println();

  } else {
    digitalWrite(alrm, LOW);
  }
}
