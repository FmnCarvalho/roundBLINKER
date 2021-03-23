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
  EEPROM.put(0, "jackthemaker");                      
  EEPROM.commit();
  EEPROM.end();
  EEPROM.begin(4096);
  //password[0]='W';password[1]='I';password[2]='F';password[3]='I';password[4]='_';password[5]='J';password[6]='T';password[7]='M';
  //password[8]='_';password[9]='2';password[10]='0';password[11]='2';password[12]='0';password[13]='#';
  EEPROM.put(64, "WIFI_JTM_2020#");
  EEPROM.commit();
  EEPROM.end();
  EEPROM.begin(4096);
  //newpassw[0]='1';newpassw[1]='1';newpassw[2]='1';newpassw[3]='1';
  EEPROM.put(128, "1111");
  EEPROM.commit();
  EEPROM.end();
  EEPROM.begin(4096);
  //SERVER[0]='m';SERVER[1]='b';SERVER[2]='.';SERVER[3]='j';SERVER[4]='a';SERVER[5]='c';SERVER[6]='k';SERVER[7]='t';SERVER[8]='h';SERVER[9]='e';
  //SERVER[10]='m';SERVER[11]='a';SERVER[12]='k';SERVER[13]='e';SERVER[14]='r';SERVER[15]='.';SERVER[16]='c';SERVER[17]='o';
  EEPROM.put(132,"mb.jackthemaker.co");
  EEPROM.commit();
  EEPROM.end();
  EEPROM.begin(4096);    
  //srvport[0]='1';srvport[1]='8';srvport[2]='8';srvport[3]='3';
  EEPROM.put(196,"1883");
  EEPROM.commit();
  EEPROM.end();
  EEPROM.begin(4096);
  //MQTT_USERNAME[0]='j';MQTT_USERNAME[1]='a';MQTT_USERNAME[2]='c';MQTT_USERNAME[3]='k';
  EEPROM.put(260,"jack_Blinker");
  EEPROM.commit();
  EEPROM.end();
  EEPROM.begin(4096);
  //MQTT_KEY[0]='j';MQTT_KEY[1]='a';MQTT_KEY[2]='c';MQTT_KEY[3]='k';
  EEPROM.put(324,"jackRGBlinker");
  EEPROM.commit();
  EEPROM.end();
  EEPROM.begin(4096);
  EEPROM.put(388,"dRgUkXp2s5"); // KEY************************************************** 6
  EEPROM.commit();
  EEPROM.end();
  EEPROM.begin(4096);
  ON_B_0=010;ON_B_1=010;ON_B_2=010;ON_B_3=010;ON_B_4=010;ON_B_5=010;ON_B_6=010;ON_B_7=010;ON_B_8=010;ON_B_9=010;
  EEPROM.put(2001,ON_B_0);EEPROM.put(2019,ON_B_1);EEPROM.put(2037,ON_B_2);EEPROM.put(2055,ON_B_3);EEPROM.put(2073,ON_B_4);
  EEPROM.put(2091,ON_B_5);EEPROM.put(2109,ON_B_6);EEPROM.put(2127,ON_B_7);EEPROM.put(2145,ON_B_8);EEPROM.put(2163,ON_B_9);
  EEPROM.commit();
  EEPROM.end();
  EEPROM.begin(4096);
  //flag_zero[0]='z';flag_zero[1]='e';flag_zero[2]='r';flag_zero[3]='o';
  EEPROM.put(4000,"zero");  
  
  EEPROM.commit();
  EEPROM.end();
  Serial.print("zero:");Serial.println(flag_zero);

  
}
