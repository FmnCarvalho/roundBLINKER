void loadCredentials() {
//********************* WLAN *********************************************************************************/
                        EEPROM.begin(4096);
                        for(e=0;e<sizeof(ssid);e++){
                        ssid[e]=EEPROM.read(e);
                        }
                        for(e=0;e<sizeof(password);e++){
                        password[e]=EEPROM.read(64+e);
                        }
                        EEPROM.end();
                        Serial.println("Recovered credentials:");
                       }

void saveCredentials() {
                        EEPROM.begin(4096);                        
                        EEPROM.put(0, ssid);                      
                        EEPROM.put(64, password);
                        EEPROM.commit();
                        EEPROM.end();
                        Serial.println("saveCredentials");
                       }

void loadNewPassw(){
                        newpssw_tmp="";
                        EEPROM.begin(4096);
                        for(e=0;e<4;e++){
                        newpssw[e]=EEPROM.read(128+e);
                        newpssw_tmp += newpssw[e];
                        }
                        EEPROM.end();
                        Serial.print("loadNewPassw");Serial.println(newpssw_tmp);
                   }

void saveNewPassw(char *tmp1){
                        EEPROM.begin(4096);
                        for(e=0;e<4;e++){
                        Serial.print("tmp1");Serial.println(tmp1[e]);  
                        EEPROM.put(128+e,tmp1[e]);
                        }
                        EEPROM.commit();
                        EEPROM.end();
                    }

void loadSERVER(){  
                        EEPROM.begin(4096);
                        for(e=0;e<sizeof(SERVER);e++){
                        SERVER[e]=EEPROM.read(132+e);
                        }
                        for(e=0;e<sizeof(srvport);e++){
                        srvport[e]=EEPROM.read(196+e);
                        }    
                        EEPROM.end();
                        SERVERPORT=0;
                        conv_str_srvport=srvport;
                        for(e=0;e<conv_str_srvport.length();e++){
                          SERVERPORT=SERVERPORT+int((srvport[e]-48)*pow(10,conv_str_srvport.length()-1-e)); //converte caracter em int (X-48)
                        }
                      }
                      
void saveSERVER(){  
                        EEPROM.begin(4096);
                        EEPROM.put(132,SERVER);     
                        EEPROM.put(196,srvport);
                        EEPROM.commit();
                        EEPROM.end();
                        
                        Serial.println("saveSERVER");
                      }

void loadMQTT(){  
                        EEPROM.begin(4096);
                        for(e=0;e<sizeof(MQTT_USERNAME);e++){
                        MQTT_USERNAME[e]=EEPROM.read(260+e);
                        }
                        for(e=0;e<sizeof(MQTT_KEY);e++){
                        MQTT_KEY[e]=EEPROM.read(324+e);
                        }
                        EEPROM.end();
                      }
                      
void saveMQTT(){  
                        EEPROM.begin(4096);
                        EEPROM.put(260,MQTT_USERNAME);
                        EEPROM.put(324,MQTT_KEY);
                        EEPROM.commit();
                        EEPROM.end();
                        Serial.println("saveMQTT");
                      }
void loadKEY(){  
                        EEPROM.begin(4096);
                        for(e=0;e<sizeof(KEY_BLINKER);e++){
                        KEY_BLINKER[e]=EEPROM.read(388+e);
                        }
                        EEPROM.end();
                      }
                      
void saveKEY(){  
                        EEPROM.begin(4096);
                        EEPROM.put(388,KEY_BLINKER);
                        EEPROM.commit();
                        EEPROM.end();
                        Serial.println("saveKEY");
                      }

                      
void loadLEDS_ON0(){
                        EEPROM.begin(4096);
                        ON_B_0=EEPROM.read(2001);
                        ON_R_0=EEPROM.read(2004);
                        ON_G_0=EEPROM.read(2007);
                        OFF_B_0=EEPROM.read(2010);
                        OFF_R_0=EEPROM.read(2013);
                        OFF_G_0=EEPROM.read(2016);
                        EEPROM.end();
                        Serial.print("loadLEDS_ON0>");Serial.print(ON_G_0);Serial.print(" _ ");Serial.print(ON_B_0);Serial.print(" _ ");Serial.println(ON_R_0);
                        Serial.print("loadLEDS_OFF0>");Serial.print(OFF_G_0);Serial.print(" _ ");Serial.print(OFF_B_0);Serial.print(" _ ");Serial.println(OFF_R_0);
                      }
void saveLEDS_ON0(){
                        EEPROM.begin(4096);
                        EEPROM.put(2001,ON_B_0);
                        EEPROM.put(2004,ON_R_0);
                        EEPROM.put(2007,ON_G_0);
                        EEPROM.put(2010,OFF_B_0);
                        EEPROM.put(2013,OFF_R_0);
                        EEPROM.put(2016,OFF_G_0);
                        EEPROM.commit();
                        EEPROM.end();
                        Serial.print("saveLEDS_ON0>");Serial.print(ON_G_0);Serial.print(" _ ");Serial.print(ON_B_0);Serial.print(" _ ");Serial.println(ON_R_0);
                        Serial.print("saveLEDS_OFF0>");Serial.print(OFF_G_0);Serial.print(" _ ");Serial.print(OFF_B_0);Serial.print(" _ ");Serial.println(OFF_R_0);
}
void loadLEDS_ON1(){
                        EEPROM.begin(4096);
                        ON_B_1=EEPROM.read(2019);
                        ON_R_1=EEPROM.read(2022);
                        ON_G_1=EEPROM.read(2025);
                        OFF_B_1=EEPROM.read(2028);
                        OFF_R_1=EEPROM.read(2031);
                        OFF_G_1=EEPROM.read(2034);
                        EEPROM.end();
                        Serial.print("loadLEDS_ON1>");Serial.print(ON_G_1);Serial.print(" _ ");Serial.print(ON_B_1);Serial.print(" _ ");Serial.println(ON_R_1);
                        Serial.print("loadLEDS_OFF1>");Serial.print(OFF_G_1);Serial.print(" _ ");Serial.print(OFF_B_1);Serial.print(" _ ");Serial.println(OFF_R_1);
                      }
void saveLEDS_ON1(){
                        EEPROM.begin(4096);
                        EEPROM.put(2019,ON_B_1);
                        EEPROM.put(2022,ON_R_1);
                        EEPROM.put(2025,ON_G_1);
                        EEPROM.put(2028,OFF_B_1);
                        EEPROM.put(2031,OFF_R_1);
                        EEPROM.put(2034,OFF_G_1);
                        EEPROM.commit();
                        EEPROM.end();
                        Serial.print("saveLEDS_ON1>");Serial.print(ON_G_1);Serial.print(" _ ");Serial.print(ON_B_1);Serial.print(" _ ");Serial.println(ON_R_1);
                        Serial.print("saveLEDS_OFF1>");Serial.print(OFF_G_1);Serial.print(" _ ");Serial.print(OFF_B_1);Serial.print(" _ ");Serial.println(OFF_R_1);
}
void loadLEDS_ON2(){
                        EEPROM.begin(4096);
                        ON_B_2=EEPROM.read(2037);
                        ON_R_2=EEPROM.read(2040);
                        ON_G_2=EEPROM.read(2043);
                        OFF_B_2=EEPROM.read(2046);
                        OFF_R_2=EEPROM.read(2049);
                        OFF_G_2=EEPROM.read(2052);
                        EEPROM.end();
                        Serial.print("loadLEDS_ON2>");Serial.print(ON_G_2);Serial.print(" _ ");Serial.print(ON_B_2);Serial.print(" _ ");Serial.println(ON_R_2);
                        Serial.print("loadLEDS_OFF2>");Serial.print(OFF_G_2);Serial.print(" _ ");Serial.print(OFF_B_2);Serial.print(" _ ");Serial.println(OFF_R_2);
                      }
void saveLEDS_ON2(){
                        EEPROM.begin(4096);
                        EEPROM.put(2037,ON_B_2);
                        EEPROM.put(2040,ON_R_2);
                        EEPROM.put(2043,ON_G_2);
                        EEPROM.put(2046,OFF_B_2);
                        EEPROM.put(2049,OFF_R_2);
                        EEPROM.put(2052,OFF_G_2);
                        EEPROM.commit();
                        EEPROM.end();
                        Serial.print("saveLEDS_ON2>");Serial.print(ON_G_2);Serial.print(" _ ");Serial.print(ON_B_2);Serial.print(" _ ");Serial.println(ON_R_2);
                        Serial.print("saveLEDS_OFF2>");Serial.print(OFF_G_2);Serial.print(" _ ");Serial.print(OFF_B_2);Serial.print(" _ ");Serial.println(OFF_R_2);
}
void loadLEDS_ON3(){
                        EEPROM.begin(4096);
                        ON_B_3=EEPROM.read(2055);
                        ON_R_3=EEPROM.read(2058);
                        ON_G_3=EEPROM.read(2061);
                        OFF_B_3=EEPROM.read(2064);
                        OFF_R_3=EEPROM.read(2067);
                        OFF_G_3=EEPROM.read(2070);
                        EEPROM.end();
                        Serial.print("loadLEDS_ON3>");Serial.print(ON_G_3);Serial.print(" _ ");Serial.print(ON_B_3);Serial.print(" _ ");Serial.println(ON_R_3);
                        Serial.print("loadLEDS_OFF3>");Serial.print(OFF_G_3);Serial.print(" _ ");Serial.print(OFF_B_3);Serial.print(" _ ");Serial.println(OFF_R_3);
                      }
void saveLEDS_ON3(){
                        EEPROM.begin(4096);
                        EEPROM.put(2055,ON_B_3);
                        EEPROM.put(2058,ON_R_3);
                        EEPROM.put(2061,ON_G_3);
                        EEPROM.put(2064,OFF_B_3);
                        EEPROM.put(2067,OFF_R_3);
                        EEPROM.put(2070,OFF_G_3);
                        EEPROM.commit();
                        EEPROM.end();
                        Serial.print("saveLEDS_ON3>");Serial.print(ON_G_3);Serial.print(" _ ");Serial.print(ON_B_3);Serial.print(" _ ");Serial.println(ON_R_3);
                        Serial.print("saveLEDS_OFF3>");Serial.print(OFF_G_3);Serial.print(" _ ");Serial.print(OFF_B_3);Serial.print(" _ ");Serial.println(OFF_R_3);
}
void loadLEDS_ON4(){
                        EEPROM.begin(4096);
                        ON_B_4=EEPROM.read(2073);
                        ON_R_4=EEPROM.read(2076);
                        ON_G_4=EEPROM.read(2079);
                        OFF_B_4=EEPROM.read(2082);
                        OFF_R_4=EEPROM.read(2085);
                        OFF_G_4=EEPROM.read(2088);
                        EEPROM.end();
                        Serial.print("loadLEDS_ON4>");Serial.print(ON_G_4);Serial.print(" _ ");Serial.print(ON_B_4);Serial.print(" _ ");Serial.println(ON_R_4);
                        Serial.print("loadLEDS_OFF4>");Serial.print(OFF_G_4);Serial.print(" _ ");Serial.print(OFF_B_4);Serial.print(" _ ");Serial.println(OFF_R_4);
                      }
void saveLEDS_ON4(){
                        EEPROM.begin(4096);
                        EEPROM.put(2073,ON_B_4);
                        EEPROM.put(2076,ON_R_4);
                        EEPROM.put(2079,ON_G_4);
                        EEPROM.put(2082,OFF_B_4);
                        EEPROM.put(2085,OFF_R_4);
                        EEPROM.put(2088,OFF_G_4);
                        EEPROM.commit();
                        EEPROM.end();
                        Serial.print("saveLEDS_ON4>");Serial.print(ON_G_4);Serial.print(" _ ");Serial.print(ON_B_4);Serial.print(" _ ");Serial.println(ON_R_4);
                        Serial.print("saveLEDS_OFF4>");Serial.print(OFF_G_4);Serial.print(" _ ");Serial.print(OFF_B_4);Serial.print(" _ ");Serial.println(OFF_R_4);
}
void loadLEDS_ON5(){
                        EEPROM.begin(4096);
                        ON_B_5=EEPROM.read(2091);
                        ON_R_5=EEPROM.read(2094);
                        ON_G_5=EEPROM.read(2097);
                        OFF_B_5=EEPROM.read(2100);
                        OFF_R_5=EEPROM.read(2103);
                        OFF_G_5=EEPROM.read(2106);
                        EEPROM.end();
                        Serial.print("loadLEDS_ON5>");Serial.print(ON_G_5);Serial.print(" _ ");Serial.print(ON_B_5);Serial.print(" _ ");Serial.println(ON_R_5);
                        Serial.print("loadLEDS_OFF5>");Serial.print(OFF_G_5);Serial.print(" _ ");Serial.print(OFF_B_5);Serial.print(" _ ");Serial.println(OFF_R_5);
                      }
void saveLEDS_ON5(){
                        EEPROM.begin(4096);
                        EEPROM.put(2091,ON_B_5);
                        EEPROM.put(2094,ON_R_5);
                        EEPROM.put(2097,ON_G_5);
                        EEPROM.put(2100,OFF_B_5);
                        EEPROM.put(2103,OFF_R_5);
                        EEPROM.put(2106,OFF_G_5);
                        EEPROM.commit();
                        EEPROM.end();
                        Serial.print("saveLEDS_ON5>");Serial.print(ON_G_5);Serial.print(" _ ");Serial.print(ON_B_5);Serial.print(" _ ");Serial.println(ON_R_5);
                        Serial.print("saveLEDS_OFF5>");Serial.print(OFF_G_5);Serial.print(" _ ");Serial.print(OFF_B_5);Serial.print(" _ ");Serial.println(OFF_R_5);
}
void loadLEDS_ON6(){
                        EEPROM.begin(4096);
                        ON_B_6=EEPROM.read(2109);
                        ON_R_6=EEPROM.read(2112);
                        ON_G_6=EEPROM.read(2115);
                        OFF_B_6=EEPROM.read(2118);
                        OFF_R_6=EEPROM.read(2121);
                        OFF_G_6=EEPROM.read(2124);
                        EEPROM.end();
                        Serial.print("loadLEDS_ON6>");Serial.print(ON_G_6);Serial.print(" _ ");Serial.print(ON_B_6);Serial.print(" _ ");Serial.println(ON_R_6);
                        Serial.print("loadLEDS_OFF6>");Serial.print(OFF_G_6);Serial.print(" _ ");Serial.print(OFF_B_6);Serial.print(" _ ");Serial.println(OFF_R_6);
                      }
void saveLEDS_ON6(){
                        EEPROM.begin(4096);
                        EEPROM.put(2109,ON_B_6);
                        EEPROM.put(2112,ON_R_6);
                        EEPROM.put(2115,ON_G_6);
                        EEPROM.put(2118,OFF_B_6);
                        EEPROM.put(2121,OFF_R_6);
                        EEPROM.put(2124,OFF_G_6);
                        EEPROM.commit();
                        EEPROM.end();
                        Serial.print("saveLEDS_ON6>");Serial.print(ON_G_6);Serial.print(" _ ");Serial.print(ON_B_6);Serial.print(" _ ");Serial.println(ON_R_6);
                        Serial.print("saveLEDS_OFF6>");Serial.print(OFF_G_6);Serial.print(" _ ");Serial.print(OFF_B_6);Serial.print(" _ ");Serial.println(OFF_R_6);
}
void loadLEDS_ON7(){
                        EEPROM.begin(4096);
                        ON_B_7=EEPROM.read(2127);
                        ON_R_7=EEPROM.read(2130);
                        ON_G_7=EEPROM.read(2133);
                        OFF_B_7=EEPROM.read(2136);
                        OFF_R_7=EEPROM.read(2139);
                        OFF_G_7=EEPROM.read(2142);
                        EEPROM.end();
                        Serial.print("loadLEDS_ON7>");Serial.print(ON_G_7);Serial.print(" _ ");Serial.print(ON_B_7);Serial.print(" _ ");Serial.println(ON_R_7);
                        Serial.print("loadLEDS_OFF7>");Serial.print(OFF_G_7);Serial.print(" _ ");Serial.print(OFF_B_7);Serial.print(" _ ");Serial.println(OFF_R_7);
                      }
void saveLEDS_ON7(){
                        EEPROM.begin(4096);
                        EEPROM.put(2127,ON_B_7);
                        EEPROM.put(2130,ON_R_7);
                        EEPROM.put(2133,ON_G_7);
                        EEPROM.put(2136,OFF_B_7);
                        EEPROM.put(2139,OFF_R_7);
                        EEPROM.put(2142,OFF_G_7);
                        EEPROM.commit();
                        EEPROM.end();
                        Serial.print("saveLEDS_ON7>");Serial.print(ON_G_7);Serial.print(" _ ");Serial.print(ON_B_7);Serial.print(" _ ");Serial.println(ON_R_7);
                        Serial.print("saveLEDS_OFF7>");Serial.print(OFF_G_7);Serial.print(" _ ");Serial.print(OFF_B_7);Serial.print(" _ ");Serial.println(OFF_R_7);
}
void loadLEDS_ON8(){
                        EEPROM.begin(4096);
                        ON_B_8=EEPROM.read(2145);
                        ON_R_8=EEPROM.read(2148);
                        ON_G_8=EEPROM.read(2151);
                        OFF_B_8=EEPROM.read(2154);
                        OFF_R_8=EEPROM.read(2157);
                        OFF_G_8=EEPROM.read(2160);
                        EEPROM.end();
                        Serial.print("loadLEDS_ON8>");Serial.print(ON_G_8);Serial.print(" _ ");Serial.print(ON_B_8);Serial.print(" _ ");Serial.println(ON_R_8);
                        Serial.print("loadLEDS_OFF8>");Serial.print(OFF_G_8);Serial.print(" _ ");Serial.print(OFF_B_8);Serial.print(" _ ");Serial.println(OFF_R_8);
                      }
void saveLEDS_ON8(){
                        EEPROM.begin(4096);
                        EEPROM.put(2145,ON_B_8);
                        EEPROM.put(2148,ON_R_8);
                        EEPROM.put(2151,ON_G_8);
                        EEPROM.put(2154,OFF_B_8);
                        EEPROM.put(2157,OFF_R_8);
                        EEPROM.put(2160,OFF_G_8);
                        EEPROM.commit();
                        EEPROM.end();
                        Serial.print("saveLEDS_ON8>");Serial.print(ON_G_8);Serial.print(" _ ");Serial.print(ON_B_8);Serial.print(" _ ");Serial.println(ON_R_8);
                        Serial.print("saveLEDS_OFF8>");Serial.print(OFF_G_8);Serial.print(" _ ");Serial.print(OFF_B_8);Serial.print(" _ ");Serial.println(OFF_R_8);
}
void loadLEDS_ON9(){
                        EEPROM.begin(4096);
                        ON_B_9=EEPROM.read(2163);
                        ON_R_9=EEPROM.read(2166);
                        ON_G_9=EEPROM.read(2169);
                        OFF_B_9=EEPROM.read(2172);
                        OFF_R_9=EEPROM.read(2175);
                        OFF_G_9=EEPROM.read(2178);
                        EEPROM.end();
                        Serial.print("loadLEDS_ON9>");Serial.print(ON_G_9);Serial.print(" _ ");Serial.print(ON_B_9);Serial.print(" _ ");Serial.println(ON_R_9);
                        Serial.print("loadLEDS_OFF9>");Serial.print(OFF_G_9);Serial.print(" _ ");Serial.print(OFF_B_9);Serial.print(" _ ");Serial.println(OFF_R_9);
                      }
void saveLEDS_ON9(){
                        EEPROM.begin(4096);
                        EEPROM.put(2163,ON_B_9);
                        EEPROM.put(2166,ON_R_9);
                        EEPROM.put(2169,ON_G_9);
                        EEPROM.put(2172,OFF_B_9);
                        EEPROM.put(2175,OFF_R_9);
                        EEPROM.put(2178,OFF_G_9);
                        EEPROM.commit();
                        EEPROM.end();
                        Serial.print("saveLEDS_ON9>");Serial.print(ON_G_9);Serial.print(" _ ");Serial.print(ON_B_9);Serial.print(" _ ");Serial.println(ON_R_9);
                        Serial.print("saveLEDS_OFF9>");Serial.print(OFF_G_9);Serial.print(" _ ");Serial.print(OFF_B_9);Serial.print(" _ ");Serial.println(OFF_R_9);
}
