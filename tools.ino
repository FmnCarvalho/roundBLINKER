/** Is this an IP? */
boolean isIp(String str) {
  for (size_t i = 0; i < str.length(); i++) {
    int c = str.charAt(i);
    if (c != '.' && (c < '0' || c > '9')) {
      return false;
    }
  }
  return true;
}

/** IP to String? */
String toStringIp(IPAddress ip) {
  String res = "";
  for (int i = 0; i < 3; i++) {
    res += String((ip >> (8 * i)) & 0xFF) + ".";
  }
  res += String(((ip >> 8 * 3)) & 0xFF);
  return res;
}

void init_data(){
  EEPROM.begin(4096);
  for (i=0;i<4096;i++){
    EEPROM.put(i,0);
  }
  EEPROM.commit();
  EEPROM.end();
  EEPROM.begin(4096);
  EEPROM.put(0, "xxxxxxxxxxxx");                      
  EEPROM.commit();
  EEPROM.end();
  EEPROM.begin(4096);
  EEPROM.put(64, "xxxxxxxxxxxxxx");
  EEPROM.commit();
  EEPROM.end();
  EEPROM.begin(4096);
  EEPROM.put(128, "1111");
  EEPROM.commit();
  EEPROM.end();
  EEPROM.begin(4096);
 
  EEPROM.put(132,"xx.xxxxxxxxxxxx.xx");
  EEPROM.commit();
  EEPROM.end();
  EEPROM.begin(4096);    
  EEPROM.put(196,"1883");
  EEPROM.commit();
  EEPROM.end();
  EEPROM.begin(4096);
  
  EEPROM.put(260,"xxxx_Blinker");
  EEPROM.commit();
  EEPROM.end();
  EEPROM.begin(4096);
 
  EEPROM.put(324,"xxxxRGBlinker");
  EEPROM.commit();
  EEPROM.end();
  EEPROM.begin(4096);
  EEPROM.put(388,"xxxxxxxxxx"); // KEY************************************************** 
  EEPROM.commit();
  EEPROM.end();
  EEPROM.begin(4096);
  ON_B_0=010;ON_B_1=010;ON_B_2=010;ON_B_3=010;ON_B_4=010;ON_B_5=010;ON_B_6=010;ON_B_7=010;ON_B_8=010;ON_B_9=010;
  EEPROM.put(2001,ON_B_0);EEPROM.put(2019,ON_B_1);EEPROM.put(2037,ON_B_2);EEPROM.put(2055,ON_B_3);EEPROM.put(2073,ON_B_4);
  EEPROM.put(2091,ON_B_5);EEPROM.put(2109,ON_B_6);EEPROM.put(2127,ON_B_7);EEPROM.put(2145,ON_B_8);EEPROM.put(2163,ON_B_9);
  EEPROM.commit();
  EEPROM.end();
  EEPROM.begin(4096);
  EEPROM.put(4000,"zero");  
  
  EEPROM.commit();
  EEPROM.end();
  Serial.print("zero:");Serial.println(flag_zero);

  
}
