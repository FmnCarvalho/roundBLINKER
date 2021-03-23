void handleRoot() {
/**************** Handle root or redirect to captive portal *************/
        
                  if (captivePortal())  { // If caprive portal redirect instead of displaying the page.
                                        return;
                                        }
                  server.sendHeader("Cache-Control", "no-cache, no-store, must-revalidate" );
                  server.sendHeader("Pragma", "no-cache");
                  server.sendHeader("Expires", "-1");
                  
                  String Page;
                  
                  Page += F("<html><body style=\"background-color:#f8f8f8;\">");
                  Page += F("<h1 style=\"background-color:black;text-align:center;font-family:verdana;font-size:400%;color:white;margin:2px;\" >JACKTHEMAKER</h1>"
                            "<h2 style=\"background-color:#f0f0f0;text-align:center;font-family:verdana;font-size:400%;margin:2px;\">round_BLINKER</h2>");              
                  if (server.client().localIP() == apIP)  {
                    Page += String( F( "<pre style=\"font-size:200%;color:#0000a0;font-family:verdana;\"><b>You are connected     to:    </b>")) + softAP_ssid + "   "+F("");
                    Page += String( F( "<br>")) + "                                               " + toStringIp(WiFi.softAPIP()) + F("</pre>");
                    } else {Page += String(F("<pre style=\"font-size:200%;color:#0000a0;font-family:verdana;\"><b>You are connected through the wifi network: </b>")) + ssid + F("</pre>");}
                    Page += String( F( "<pre style=\"font-size:200%;color:#0000a0;font-family:verdana;\"><b>WLAN config           ssid:    </b>")) + String(ssid) + "<br>" +"<b>                                       ip:    </b>" + toStringIp(WiFi.localIP()) + F("<br>");
                    Page += String( F(                                                                 "<b>SERVER config        ssid:    </b>")) + SERVER + "<br>" + "<b>                                   port:    </b>" + SERVERPORT + F("<br>");
                    Page += String( F(                                                                 "<b>MQTT config username:     </b>")) + MQTT_USERNAME + "<br>" + "<b>                                    key:     </b>" + MQTT_KEY + F("<br>");
                    Page += String( F(                                                                 "<b>KEY                                   :    </b>")) + KEY_BLINKER + F("</pre>");  
                                   
                  Page += F("<form method='POST' >"
                            "<h1 style=\"background-color:#0000a0;text-align:center;height:2px;\"> </h1>"                          
                            "<h2 style=\"font-size:500%;font-family:verdana;\">Access BLINKER:</h2>"
                            "<h2 style=\"font-size:200%;font-family:verdana;\">Password (4 Digits)</h2>"
                            "<style>.tab0{float:left;margin:0px;border:1px solid #0000ff;padding:0px:max-width:341px;height:133px;}" 
                            ".tab1{float:left;margin:0px;padding:0px:max-width:105px;height:133px;}"
                            ".tab2{float:left;margin:0px;border:1px solid #0000ff;padding:0px:max-width:235px;height:133px;}</style>" 
                            "<div class=\"tab0\"><input style=\"font-size:670%;background-color:#f0f0f0;font-family:verdana;width:341px;\"  maxlength=\"4\" type=\"password\" name='numb'></div>"
                            "<div class=\"tab1\"><label style=\"font-size:670%;width:70px; color:#f8f8f8;\">__</label></div>"
                            "<div class=\"tab2\"><input style=\"font-size:670%;font-family:verdana;background-color:#a0a0a0; color:#000000;\" type='submit' value='OK' ></h2></div>"
                           );
                  server.arg("numb").toCharArray(numb,sizeof(numb)-1);

                  newpssw_tmp="";
                  loadNewPassw();
                  
                  Serial.print("newpassw0: ");Serial.println(newpssw_tmp);
                  Serial.print("numb0: ");Serial.println(numb);
                  
                  if (String(numb)==newpssw_tmp)  {Page += F( "<br>""<br>""<br>");
                                                Page += F( "<h2 ><a style=\"font-size:200%;color:#0000ff;font-family:verdana;\"href='/newpassw'>Change Password  ></a></h2>");
                                                Page += F( "<h2 ><a style=\"font-size:200%;color:#0000ff;font-family:verdana;\"href='/wifi'>Config the wifi connection  ></a></h2>");
                                                Page += F( "<h2 ><a style=\"font-size:200%;color:#0000ff;font-family:verdana;\"href='/blinker'>Config blinker  ></a></h2>");

                  } else {
                          if (String(numb)=="")  {  Page += F("<br>""<br>");
                                                    Page += F("<h2 style=\"font-size:400%;color:#0000ff;font-family:verdana;\">Enter Password</h2>");flag_access_filter=0;
                                                    Page += F("<br>");
                                                 } else {
                                                          Page += F("<br>""<br>"
                                                                    "<h2 style=\"font-size:400%;color:red;font-family:verdana;\">Password ERROR</h2>"
                                                                    "<br>""<br>");
                                                                    flag_access_filter=0;}
                         }

                  Page += F( "<h2 style=\"text-align:center;font-size:700%;color:#800000;font-family:verdana;\">Mercedes.iO</h2>""</form>""</body></html>");  
                                                                 
                  server.send(200, "text/html", Page);
                  server.client().stop(); // Stop is needed because we sent no content length  
                  content="";
                  flag_changepassw=0;
                  }

void handleNewPassw() {
                        server.sendHeader("Cache-Control", "no-cache, no-store, must-revalidate");
                        server.sendHeader("Pragma", "no-cache");
                        server.sendHeader("Expires", "-1");
                       
                        if (flag_changepassw==0){

                          String Page="";
                          Page += F("<html><body style=\"background-color:#f8f8f8;\">"
                                    "<h1 style=\"background-color:black;text-align:center;font-family:verdana;font-size:400%;color:white;margin:2px;\" >JACKTHEMAKER</h1>"
                                    "<h2 style=\"background-color:#f0f0f0;text-align:center;font-family:verdana;font-size:400%;margin:2px;\">round_BLINKER</h2>");
                          
                        if (server.client().localIP() == apIP)  {
                          Page += String( F( "<pre style=\"font-size:200%;color:#0000a0;font-family:verdana;\"><b>You are connected     to:    </b>")) + softAP_ssid + "   "+F("");       
                          Page += String( F( "<br>")) + "                                               " + toStringIp(WiFi.softAPIP()) + F("</pre>");
                        } else { Page += String(F("<pre style=\"font-size:200%;color:#0000a0;font-family:verdana;\"><b>You are connected through the wifi network: </b>")) + ssid + F("</pre>");}                          
                        Page += String( F( "<pre style=\"font-size:200%;color:#0000a0;font-family:verdana;\"><b>WLAN config           ssid:    </b>")) + String(ssid) + "<br>" +"<b>                                       ip:    </b>" + toStringIp(WiFi.localIP()) + F("<br>");                          
                        Page += String( F(                                                                 "<b>SERVER config        ssid:    </b>")) + SERVER + "<br>" + "<b>                                   port:    </b>" + SERVERPORT + F("<br>");                          
                        Page += String( F(                                                                 "<b>MQTT config username:     </b>")) + MQTT_USERNAME + "<br>" + "<b>                                    key:     </b>" + MQTT_KEY + F("<br>");                        
                        Page += String( F(                                                                 "<b>KEY                                   :    </b>")) + KEY_BLINKER + F("</pre>");  
                                                  
                          Page += F( "<form method='POST' >"
                                  "<h1 style=\"background-color:#0000a0;text-align:center;height:2px;\"></h1>"
                                  //"<h2 style=\"font-size:500%;\"></h2>"
                                  "<h2 style=\"font-size:500%;font-family:verdana;\">CHANGE PASSWORD</h2>"
                                  "<h2 style=\"font-size:200%;font-family:verdana;\">Password (4 Digitos)</h2>"
                                  "<style>.tab0{border:1px solid #0000ff;float:left;margin:0px;padding:0px;max-width:341px;height:133px;}"
                                  ".tab2{float:left;margin:0px;padding:0px;max-width:105px;height:133px;}"
                                  ".tab3{border:1px solid #0000ff;float:left;margin:0px;padding:0px;max-width:235px;height:133px;}</style>"
                                  "<div class=\"tab0\"><input style=\"font-size:670%;background-color:#f0f0f0; font-family:verdana;width:341px\" maxlength=\"4\" type=\"password\" name='newpassw'></div>"
                                  "<div class=\"tab2\"><label style=\"font-size:670%; width:70px; color:#f8f8f8;\" >__</label></div>"
                                  "<div class=\"tab3\"><input style=\"font-size:670%;background-color:#a0a0a0;font-family:verdana;color:#000000;\" type='submit' value='OK'></div>"
                                  "</form>"
                                );

                       server.arg("newpassw").toCharArray(newpassw,sizeof(newpassw)-1);
                       
                       Page += F( "<br>""<br>"
                                  "<h2 style=\"font-size:400%;font-family:verdana;color:#0000ff;\">Enter newpassword</h2>"
                                  "<br>"
                                  "<h2 ><a style=\"font-size:250%;font-family:verdana;color:#0000ff;\" href='/'><  Back</a></h2>"
                                  "<br>""<br>"
                                  "<h2 style=\"text-align:center;font-size:700%;color:#800000;font-family:verdana;\">Mercedes.iO</h2>"  
                                  "</body></html>"
                                );
                       if (String(newpassw).length()==4){
                          flag_changepassw=1;
                          }else{     
                       server.send(200, "text/html", Page); }                                   
                       }
                    if( flag_changepassw==1){
                               
                        String Page="";
                        
                        Page += F( "<html><body style=\"background-color:#f8f8f8;\">"
                                   "<h1 style=\"background-color:black;text-align:center;font-family:verdana;font-size:400%;color:white;margin:2px;\" >JACKTHEMAKER</h1>"
                                   "<h2 style=\"background-color:#f0f0f0;text-align:center;font-family:verdana;font-size:400%;margin:2px;\">round_BLINKER</h2>");

                        if (server.client().localIP() == apIP)  {
                        Page += String( F( "<pre style=\"font-size:200%;color:#0000a0;font-family:verdana;\"><b>You are connected     to:    </b>")) + softAP_ssid + "   "+F("");                        
                        Page += String( F( "<br>")) + "                                               " + toStringIp(WiFi.softAPIP()) + F("</pre>");                        
                        } else {
                          Page += String(F("<pre style=\"font-size:200%;color:#0000a0;font-family:verdana;\"><b>You are connected through the wifi network: </b>")) + ssid + F("</pre>");                          
                          }
            
                          Page += String( F( "<pre style=\"font-size:200%;color:#0000a0;font-family:verdana;\"><b>WLAN config           ssid:    </b>")) + String(ssid) + "<br>" +"<b>                                       ip:    </b>" + toStringIp(WiFi.localIP()) + F("<br>");                                                
                          Page += String( F(                                                                 "<b>SERVER config        ssid:    </b>")) + SERVER + "<br>" + "<b>                                   port:    </b>" + SERVERPORT + F("<br>");                          
                          Page += String( F(                                                                 "<b>MQTT config username:     </b>")) + MQTT_USERNAME + "<br>" + "<b>                                    key:     </b>" + MQTT_KEY + F("<br>");                        
                          Page += String( F(                                                                 "<b>KEY                                   :    </b>")) + KEY_BLINKER + F("</pre>");                            

                          Page += F ( "<br>"                                     
                                     "<form method='POST' >"
                                     "<h1 style=\"background-color:#0000a0;text-align:center;height:2px;" 
                                     "<h2 style=\"font-size:500%;\"></h2>"
                                     "<h2 style=\"font-size:500%;font-family:verdana;\">NOVA PASSWORD</h2>"
                                     "<h2 style=\"font-size:200%;font-family:verdana;\">Password (4 Digitos)</h2>"                                                           
                                     "<style>.tab0{border:1px solid #0000ff;float:left;margin:0px;padding:0px;max-width:341px;height:133px;}"
                                     ".tab2{float:left;margin:0px;padding:0px;max-width:105px;height:133px;}"
                                     ".tab3{border:1px solid #0000ff;float:left;margin:0px;padding:0px;max-width:235px;height:133px;}</style>"
                                     "<div class=\"tab0\"><input style=\"font-size:670%; width:341px;background-color:#f0f0f0; font-family:verdana;\" maxlength=\"4\" type=\"password\" name='numbpassw'></div>"
                                     "<div class=\"tab2\"><label style=\"font-size:670%; width:70px; color:#f8f8f8;\" >__</label></div>"
                                     "<div class=\"tab3\"><input style=\"font-size:670%;background-color:#a0a0a0;font-family:verdana;color:#000000;\" type='submit' value='OK'></div>"
                                     "</form>"
                                     "<br>""<br>"
                                   );
                          server.arg("numbpassw").toCharArray(numbpassw,sizeof(numbpassw)-1);
                          Serial.print("numbpassw: ");Serial.println(numbpassw);
                          if(String(newpassw)==String(numbpassw)) {
                            Page += F("<h2 style=\"font-size:400%;font-family:verdana;color:#00ff00;\">New Password, OK</h2>");
                            newpssw[0]=numbpassw[0];newpssw[1]=numbpassw[1];newpssw[2]=numbpassw[2];newpssw[3]=numbpassw[3];
                            
                                Serial.print("*numbpassw: ");Serial.println(numbpassw);
                            saveNewPassw(numbpassw);
                          
                            flag_changepassw=0;
                          } else {
                                  Page += F("<h2 style=\"font-size:400%;font-family:verdana;color:#0000ff;\">Repeat password</h2>");
                                 }
                          Page += F( 
                                     "<h2 ><a style=\"font-size:250%;font-family:verdana;color:#0000ff;\" href='/'><  Back</a></h2>"
                                     "<br>"
                                     "<h2 style=\"text-align:center;font-size:700%;font-family:verdana;color:#800000;\">Mercedes.iO</h2>"
                                     "</body></html>"
                                   );
                          server.send(200, "text/html", Page);      
                        }
                        
                          server.client().stop(); // Stop is needed because we sent no content length 
                                                     
                     }

void handleWifi() {
                    server.sendHeader("Cache-Control", "no-cache, no-store, must-revalidate" );
                    server.sendHeader("Pragma", "no-cache");
                    server.sendHeader("Expires", "-1");

                    String Page;
                                
                    Page += F( "<html><head></head><body style=\"background-color:#f8f8f8;\">"
                               "<h1 style=\"background-color:black;text-align:center;font-family:verdana;font-size:400%;color:white;margin:2px;\" >JACKTHEMAKER</h1>"
                               "<h2 style=\"background-color:#f0f0f0;text-align:center;font-family:verdana;font-size:400%;margin:2px;\">round_BLINKER</h2>");
                                
                    if (server.client().localIP() == apIP)  {
                        Page += String( F( "<pre style=\"font-size:200%;color:#0000a0;font-family:verdana;\"><b>You are connected     to:    </b>")) + softAP_ssid + "   "+F("");
                        Page += String( F( "<br>")) + "                                               " + toStringIp(WiFi.softAPIP()) + F("</pre>");
                        } else {Page += String(F("<pre style=\"font-size:200%;color:#0000a0;font-family:verdana;\"><b>You are connected through the wifi network: </b>")) + ssid + F("</pre>");}
                        Page += String( F( "<pre style=\"font-size:200%;color:#0000a0;font-family:verdana;\"><b>WLAN config           ssid:    </b>")) + String(ssid) + "<br>" +"<b>                                       ip:    </b>" + toStringIp(WiFi.localIP()) + F("<br>");
                        Page += String( F(                                                                 "<b>SERVER config        ssid:    </b>")) + SERVER + "<br>" + "<b>                                   port:    </b>" + SERVERPORT + F("<br>");
                        Page += String( F(                                                                 "<b>MQTT config username:     </b>")) + MQTT_USERNAME + "<br>" + "<b>                                    key:     </b>" + MQTT_KEY + F("<br>");
                        Page += String( F(                                                                 "<b>KEY                                   :    </b>")) + KEY_BLINKER + F("</pre>");  
                    
                    Page += String( F( "<pre style=\"background-color:#0000a0;text-align:center;height:2px;")) + F("</pre>");
                    Page += String( F( "<pre style=\"font-size:250%;color:#0000a0;\"><b></b>")) + F("</pre>");
                    Page += String( F( "<pre style=\"font-size:250%; color:#0000a0;\"><b>WLAN list (refresh if any missing)</b></pre>"));
                    //Serial.println("scan start");
                    int n = WiFi.scanNetworks();
                    //Serial.println("scan done");
                                if (n > 0) {
                                  for (int i = 0; i < n; i++) {
                                      Page += String( F( "<pre style=\"font-size:250%;color:#0000ff;font-family:verdana;\"><b>  ssid:    </b>")) + WiFi.SSID(i) + ((WiFi.encryptionType(i) == ENC_TYPE_NONE) ? F(" ") : F(" *")) + F(" (") + WiFi.RSSI(i) + F(")</pre>");
                                      }
                                      } else {
                                              Page += String(F( "<pre style=\"font-size:250%;color:#0000ff;font-family:verdana;\"><b>No WLAN found</b>")) + F("</pre>");
                                             } 
                                                                  
                                Page += F( "<form method='POST' action='wifisave'>");
                                           
                                Page += F( "<h1 style=\"font-size:400%;font-family:verdana;\">CONNECT TO NETWORK:</h1>"
                                           "<input style=\"font-size:500%;margin:2px;width:951px;height:100px;background-color:#f0f0f0;border:2px solid #0000ff;color:#000000;\" type='text' placeholder='network' name='n'/>"
                                           "<input style=\"font-size:500%;margin:2px;width:951px;height:100px;background-color:#f0f0f0;border:2px solid #0000ff;color:#000000;\" type='password' placeholder='password' name='p'/>");
                                Page += F( "<input style=\"font-size:500%;margin:2px;width:951px;height:100px;background-color:#a0a0a0;border:2px solid #0000ff;color:#000000;\" type='submit' value='Connect'/></form>");                     
   
                                Page += F(
                                          "<h2 ><a style=\"font-size:250%;color:#0000ff;font-family:verdana;\"href='/'><  Back</a></h2>"
                                          "</body></html>"
                                );
                                Page += F( "<h2 ><a style=\"font-size:250%;color:#0000ff;font-family:verdana;\"href='/server'>Continue to SERVER  ></a></h2>"
                                           "<h2 style=\"text-align:center;font-size:700%;font-family:verdana;color:#800000;\">Mercedes.iO</a></h2>"
                                           "</body></html>" );    
                                ep_creden=1; 

                                server.send(200, "text/html", Page);
                                server.client().stop(); // Stop is needed because we sent no content length      
                    
}

void handleSERVER() {
                    server.sendHeader("Cache-Control", "no-cache, no-store, must-revalidate" );
                    server.sendHeader("Pragma", "no-cache");
                    server.sendHeader("Expires", "-1");
                  
                    String Page;
                    Page += F( "<html><head></head><body style=\"background-color:#f8f8f8;\">"
                               "<h1 style=\"background-color:black;text-align:center;font-family:verdana;font-size:400%;color:white;margin:2px;\" >JACKTHEMAKER</h1>"
                               "<h2 style=\"background-color:#f0f0f0;text-align:center;font-family:verdana;font-size:400%;margin:2px;\">round_BLINKER</h2>");

                    if (server.client().localIP() == apIP)  {
                        Page += String( F( "<pre style=\"font-size:200%;color:#0000a0;font-family:verdana;\"><b>You are connected     to:    </b>")) + softAP_ssid + "   "+F("");
                        Page += String( F( "<br>")) + "                                               " + toStringIp(WiFi.softAPIP()) + F("</pre>");
                        } else {Page += String(F("<pre style=\"font-size:200%;color:#0000a0;font-family:verdana;\"><b>You are connected through the wifi network: </b>")) + ssid + F("</pre>");}
                        Page += String( F( "<pre style=\"font-size:200%;color:#0000a0;font-family:verdana;\"><b>WLAN config           ssid:    </b>")) + String(ssid) + "<br>" +"<b>                                       ip:    </b>" + toStringIp(WiFi.localIP()) + F("<br>");
                        Page += String( F(                                                                 "<b>SERVER config        ssid:    </b>")) + SERVER + "<br>" + "<b>                                   port:    </b>" + SERVERPORT + F("<br>");
                        Page += String( F(                                                                 "<b>MQTT config username:     </b>")) + MQTT_USERNAME + "<br>" + "<b>                                    key:     </b>" + MQTT_KEY + F("<br>");
                        Page += String( F(                                                                 "<b>KEY                                   :    </b>")) + KEY_BLINKER + F("</pre>");  
                    
                               Page += F( "<form method='POST' action='wifisave'>"
                                          "<h1 style=\"background-color:#0000a0;text-align:center;height:2px;" 
                                          "<h2 style=\"font-size:400%;\"></h2>"
                                          "<h1 style=\"font-size:400%;font-family:verdana;\">CONNECT TO SERVER:</h1>"
                                          "<input style=\"font-size:500%;margin:2px;width:951px;height:100px;font-family:verdana;background-color:#f0f0f0;border:2px solid #0000ff;\" type='text' placeholder='SERVER' name='q'/>"
                                          "<input style=\"font-size:500%;margin:2px;width:951px;height:100px;font-family:verdana;background-color:#f0f0f0;border:2px solid #0000ff;\" type='number' placeholder='SERVERPORT' name='r'/>"                                           
                                          //"<div class=\"tab0\"><input style=\"font-size:500%; width:341pxfont-family:verdana;\" maxlength=\"4\" type='number' name='SERVERPORT'></div>"
                                           );
                               Page += F( "<input style=\"font-size:500%;margin:2px;width:951px;height:100px;border:2px solid 0000ff;color:#000000;background-color:#a0a0a0;font-family:verdana;\" type='submit' value='Connect'/></form>");                     

                    Page += F( "<h2 ><a style=\"font-size:250%;font-family:verdana;color:#0000ff;\" href='/wifi'><  Back</a></h2>");
                             
                    Page += F( "<h2 ><a style=\"font-size:250%;font-family:verdana;color:#0000ff;\" href='/mqtt'>Continue to MQTT</a></h2>"
                               "<br>""<br>"
                               "<h2 style=\"text-align:center;font-size:700%;font-family:verdana;color:#800000;\">Mercedes.iO</a></h2>"
                               "</body></html>");         
                    ep_server=1;
                    ep_creden=0;
                    server.send(200, "text/html", Page);
                    server.client().stop(); // Stop is needed because we sent no content length 
}

void handleMQTT() {
                    server.sendHeader("Cache-Control", "no-cache, no-store, must-revalidate" );
                    server.sendHeader("Pragma", "no-cache");
                    server.sendHeader("Expires", "-1");
                  
                    String Page;
                    Page += F( "<html><head></head><body style=\"background-color:#f8f8f8;\">"
                               "<h1 style=\"background-color:black;text-align:center;font-family:verdana;font-size:400%;color:white;margin:2px;\" >JACKTHEMAKER</h1>"
                               "<h2 style=\"background-color:#f0f0f0;text-align:center;font-family:verdana;font-size:400%;margin:2px;\">round_BLINKER</h2>");

                    if (server.client().localIP() == apIP)  {
                    Page += String( F( "<pre style=\"font-size:200%;color:#0000a0;font-family:verdana;\"><b>You are connected     to:    </b>")) + softAP_ssid + "   "+F("");
                        Page += String( F( "<br>")) + "                                               " + toStringIp(WiFi.softAPIP()) + F("</pre>");
                        } else {Page += String(F("<pre style=\"font-size:200%;color:#0000a0;font-family:verdana;\"><b>You are connected through the wifi network: </b>")) + ssid + F("</pre>");}
                        Page += String( F( "<pre style=\"font-size:200%;color:#0000a0;font-family:verdana;\"><b>WLAN config           ssid:    </b>")) + String(ssid) + "<br>" +"<b>                                       ip:    </b>" + toStringIp(WiFi.localIP()) + F("<br>");
                        Page += String( F(                                                                 "<b>SERVER config        ssid:    </b>")) + SERVER + "<br>" + "<b>                                   port:    </b>" + SERVERPORT + F("<br>");
                        Page += String( F(                                                                 "<b>MQTT config username:     </b>")) + MQTT_USERNAME + "<br>" + "<b>                                    key:     </b>" + MQTT_KEY + F("<br>");
                        Page += String( F(                                                                 "<b>KEY                                   :    </b>")) + KEY_BLINKER + F("</pre>");  
                    
                    Page += F( "<form method='POST' action='wifisave'>"
                               "<h1 style=\"background-color:#0000a0;text-align:center;height:2px;" 
                               "<h2 style=\"font-size:400%;\"></h2>"
                               "<h1 style=\"font-size:400%;font-family:verdana;\">CONNECT TO MQTT:</h1>"
                               "<input style=\"font-size:500%;margin:2px;width:951px;height:100px;background-color:#f0f0f0;border:2px solid #0000ff;font-family:verdana;\" type='text' placeholder='MQTT_USERNAME' name='s'/>"
                               "<input style=\"font-size:500%;margin:2px;width:951px;height:100px;background-color:#f0f0f0;border:2px solid #0000ff;font-family:verdana;\" type='password' placeholder='MQTT_KEY' name='t'/>"                                        
                               );
                    Page += F( "<input style=\"font-size:500%;margin:2px;width:951px;height:100px;border:2px solid #0000ff;color:#000000;background-color:#a0a0a0;font-family:verdana;\" type='submit' value='Connect'/></form>");                     
       
                    ep_mqtt=1;
                    ep_server=0;
                    ep_creden=0;

                    Page += F( "<h2 ><a style=\"font-size:250%;font-family:verdana;color:#0000ff;\" href='/server'><  Back</a></h2>" );
                    Page += F( "<h2 ><a style=\"font-size:250%;font-family:verdana;color:#0000ff;\" href='/key'>Continue to KEY ></a></h2>"
                               "<h2 style=\"text-align:center;font-size:700%;font-family:verdana;color:#800000;\">Mercedes.iO</a></h2>"
                               "</body></html>");         
       
                    server.send(200, "text/html", Page);
                    server.client().stop(); // Stop is needed because we sent no content length 
}

void handleKEY() {
                    server.sendHeader("Cache-Control", "no-cache, no-store, must-revalidate" );
                    server.sendHeader("Pragma", "no-cache");
                    server.sendHeader("Expires", "-1");
                  
                    String Page;
                    Page += F( "<html><head></head><body style=\"background-color:#f8f8f8;\">"
                               "<h1 style=\"background-color:black;text-align:center;font-family:verdana;font-size:400%;color:white;margin:2px;\" >JACKTHEMAKER</h1>"
                               "<h2 style=\"background-color:#f0f0f0;text-align:center;font-family:verdana;font-size:400%;margin:2px;\">round_BLINKER</h2>");

                    if (server.client().localIP() == apIP)  {
                        Page += String( F( "<pre style=\"font-size:200%;color:#0000a0;font-family:verdana;\"><b>You are connected     to:    </b>")) + softAP_ssid + "   "+F("");
                        Page += String( F( "<br>")) + "                                               " + toStringIp(WiFi.softAPIP()) + F("</pre>");
                        } else {Page += String(F("<pre style=\"font-size:200%;color:#0000a0;font-family:verdana;\"><b>You are connected through the wifi network: </b>")) + ssid + F("</pre>");}
                        Page += String( F( "<pre style=\"font-size:200%;color:#0000a0;font-family:verdana;\"><b>WLAN config           ssid:    </b>")) + String(ssid) + "<br>" +"<b>                                       ip:    </b>" + toStringIp(WiFi.localIP()) + F("<br>");
                        Page += String( F(                                                                 "<b>SERVER config        ssid:    </b>")) + SERVER + "<br>" + "<b>                                   port:    </b>" + SERVERPORT + F("<br>");
                        Page += String( F(                                                                 "<b>MQTT config username:     </b>")) + MQTT_USERNAME + "<br>" + "<b>                                    key:     </b>" + MQTT_KEY + F("<br>");
                        Page += String( F(                                                                 "<b>KEY                                   :    </b>")) + KEY_BLINKER + F("</pre>");  
                    
                    Page += F( "<form method='POST' action='wifisave'>"
                               "<h1 style=\"background-color:#0000a0;text-align:center;height:2px;" 
                               "<h2 style=\"font-size:400%;\"></h2>"
                               "<h1 style=\"font-size:400%;font-family:verdana;\">CONNECT THE KEY:</h1>"
                               "<input style=\"font-size:500%;margin:2px;width:951px;height:100px;font-family:verdana;border:2px solid #0000ff;color:#a0a0a0;background-color:#f0f0f0;\" type='text' placeholder='KEY_BLINKER' name='u'/>"                                   
                               );
                    Page += F( "<input style=\"font-size:500%;margin:2px;width:951px;height:100px;font-family:verdana;border:2px solid #0000ff;color:#000000;background-color:#a0a0a0;\" type='submit' value='Connect'/></form>");                     

                    ep_key=1;
                    ep_mqtt=0;
                    ep_server=0;
                    ep_creden=0;

                    Page += F( "<h2 ><a style=\"font-size:250%;color:#0000ff;font-family:verdana;\" href='/server'><  Back</a></h2>");
                    Page += F( "<h2 ><a style=\"font-size:250%;color:#0000ff;font-family:verdana;\" href='/rst'>Continue to RESET</a></h2>"
                               "<h2 style=\"text-align:center;font-size:700%;font-family:verdana;color:#800000;\">Mercedes.iO</a></h2>"
                               "</body></html>");         
       
                    server.send(200, "text/html", Page);
                    server.client().stop(); // Stop is needed because we sent no content length 

}

void handleRST() {
                    server.sendHeader("Cache-Control", "no-cache, no-store, must-revalidate" );
                    server.sendHeader("Pragma", "no-cache");
                    server.sendHeader("Expires", "-1");

                    String Page;
                    Page += F( "<html><body style=\"background-color:#f8f8f8;\">"
                               "<h1 style=\"background-color:black;text-align:center;font-family:verdana;font-size:400%;color:white;margin:2px;\" >JACKTHEMAKER</h1>"
                               "<h2 style=\"background-color:#f0f0f0;text-align:center;font-family:verdana;font-size:400%;margin:2px;\">round_BLINKER</h2>"
                               "<br>""<br>""<br>""<br>""<br>""<br>""<br>""<br>""<br>""<br>");
                               //"<h2 style=\"background-color:#f0f0f0;text-align:center;font-size:400%;margin:2px;\">Restarting</h2>");
                             
                    Page += F( "<h2 ><a style=\"text-align:center;font-size:250%;font-family:verdana;color:#0000ff;\" href='/'>< RESTARTING ></a></h2>"
                               "<br>""<br>""<br>""<br>""<br>""<br>""<br>""<br>""<br>""<br>""<br>""<br>"
                               "<h2 style=\"text-align:center;font-size:700%;font-family:verdana;color:#800000;\">Mercedes.iO</a></h2>"
                               "</body></html>");          
       
                    server.send(200, "text/html", Page);
                    server.client().stop(); // Stop is needed because we sent no content length 
                    delay(2000);
                    RST=1;  
}      

                    


void handleBlinker() {
                    server.sendHeader("Cache-Control", "no-cache, no-store, must-revalidate" );
                    server.sendHeader("Pragma", "no-cache");
                    server.sendHeader("Expires", "-1");

                    String Page;
                                
                    Page += F( "<html><body style=\"background-color:#f8f8f8;\">"
                               "<h1 style=\"background-color:black;text-align:center;font-family:verdana;font-size:400%;color:white;margin:2px;\" >JACKTHEMAKER</h1>"
                               "<h2 style=\"background-color:#f0f0f0;text-align:center;font-family:verdana;font-size:400%;margin:2px;\">round_BLINKER</h2>");

                    if (server.client().localIP() == apIP)  {
                      Page += String( F( "<pre style=\"font-size:200%;color:#0000a0;font-family:verdana;\"><b>You are connected     to:    </b>")) + softAP_ssid + "   "+F("");
                        Page += String( F( "<br>")) + "                                               " + toStringIp(WiFi.softAPIP()) + F("</pre>");
                        } else {Page += String(F("<pre style=\"font-size:200%;color:#0000a0;font-family:verdana;\"><b>You are connected through the wifi network: </b>")) + ssid + F("</pre>");}
                        Page += String( F( "<pre style=\"font-size:200%;color:#0000a0;font-family:verdana;\"><b>WLAN config           ssid:    </b>")) + String(ssid) + "<br>" +"<b>                                       ip:    </b>" + toStringIp(WiFi.localIP()) + F("<br>");
                        Page += String( F(                                                                 "<b>SERVER config        ssid:    </b>")) + SERVER + "<br>" + "<b>                                   port:    </b>" + SERVERPORT + F("<br>");
                        Page += String( F(                                                                 "<b>MQTT config username:     </b>")) + MQTT_USERNAME + "<br>" + "<b>                                    key:     </b>" + MQTT_KEY + F("<br>");
                        Page += String( F(                                                                 "<b>KEY                                   :    </b>")) + KEY_BLINKER + F("</pre>");  
                    
                    Page += F("<form method='POST' >"
                              "<h1 style=\"background-color:#0000a0;text-align:center;height:2px;\"></h1>" 
                              "<h2 style=\"font-size:400%;\"></h2>"
                              "<h2 style=\"font-size:400%;font-family:verdana;color:#000000;\">PARAMETERS ADJUST</h2>" 
                              "<style>.tab0{float:left;margin:0px;padding:0px;max-width:100px;height:90px;border:1px solid #0000ff;}"
                                     ".tab1{float:left;margin:0px;padding:0px;max-width:134px;height:90px;border:1px solid #0000ff;}"
                                     ".tab2{float:left;margin:0px;padding:0px;max-width:146px;height:90px;border:1px solid #0000ff;}"
                                     ".tab3{float:left;margin:0px;padding:0px;max-width:146px;height:90px;border:1px solid #0000ff;}"
                                     ".tab4{float:left;margin:0px;padding:0px;max-width:146px;height:90px;border:1px solid #0000ff;}"
                                     ".tab5{float:left;margin:0px;padding:0px;max-width:122px;height:90px;border:1px solid #0000ff;}"
                                     ".tab6{float:left;margin:0px;padding:0px;max-width:150px;height:90px;border:1px solid #0000ff;}"
                                     ".tab10{float:left;margin:0px;padding:0px;max-width:100px;height:90px;border:1px solid #0000ff;}"
                                     ".tab11{float:left;margin:0px;padding:0px;max-width:134px;height:90px;border:1px solid #0000ff;}"
                                     ".tab12{float:left;margin:0px;padding:0px;max-width:146px;height:90px;border:1px solid #0000ff;}"
                                     ".tab13{float:left;margin:0px;padding:0px;max-width:146px;height:90px;border:1px solid #0000ff;}"
                                     ".tab14{float:left;margin:0px;padding:0px;max-width:146px;height:90px;border:1px solid #0000ff;}"
                                     ".tab15{float:left;margin:0px;padding:0px;max-width:122px;height:90px;border:1px solid #0000ff;}"
                                     ".tab16{float:left;margin:0px;padding:0px;max-width:150px;height:90px;border:1px solid #0000ff;}"
                                     "</style>");

                    if(String(nmbr)=="0"&&flag_load_0==0){
                      N[0]='0000';                      
                      G_0=String(ON_B_0/100);G_1=String((ON_B_0%100)/10);G_2=String((ON_B_0%100)%10);
                      B_0=String(ON_R_0/100);B_1=String((ON_R_0%100)/10);B_2=String((ON_R_0%100)%10);
                      R_0=String(ON_G_0/100);R_1=String((ON_G_0%100)/10);R_2=String((ON_G_0%100)%10);
                      R[0]=R_0.charAt(0);R[1]=R_1.charAt(0);R[2]=R_2.charAt(0);
                      G[0]=G_0.charAt(0);G[1]=G_1.charAt(0);G[2]=G_2.charAt(0);
                      B[0]=B_0.charAt(0);B[1]=B_1.charAt(0);B[2]=B_2.charAt(0);
                      Gf_0=String(OFF_B_0/100);Gf_1=String((OFF_B_0%100)/10);Gf_2=String((OFF_B_0%100)%10);
                      Bf_0=String(OFF_R_0/100);Bf_1=String((OFF_R_0%100)/10);Bf_2=String((OFF_R_0%100)%10);
                      Rf_0=String(OFF_G_0/100);Rf_1=String((OFF_G_0%100)/10);Rf_2=String((OFF_G_0%100)%10);
                      Rf[0]=Rf_0.charAt(0);Rf[1]=Rf_1.charAt(0);Rf[2]=Rf_2.charAt(0);
                      Gf[0]=Gf_0.charAt(0);Gf[1]=Gf_1.charAt(0);Gf[2]=Gf_2.charAt(0);
                      Bf[0]=Bf_0.charAt(0);Bf[1]=Bf_1.charAt(0);Bf[2]=Bf_2.charAt(0);
                      flag_load_0=1;flag_load_1=0;flag_load_2=0;flag_load_3=0;flag_load_4=0;flag_load_5=0;flag_load_6=0;flag_load_7=0;flag_load_8=0;flag_load_9=0;
                    }
                    if(String(nmbr)=="1"&&flag_load_1==0){
                      N[0]='0001';                      
                      G_0=String(ON_B_1/100);G_1=String((ON_B_1%100)/10);G_2=String((ON_B_1%100)%10);
                      B_0=String(ON_R_1/100);B_1=String((ON_R_1%100)/10);B_2=String((ON_R_1%100)%10);
                      R_0=String(ON_G_1/100);R_1=String((ON_G_1%100)/10);R_2=String((ON_G_1%100)%10);
                      R[0]=R_0.charAt(0);R[1]=R_1.charAt(0);R[2]=R_2.charAt(0);
                      G[0]=G_0.charAt(0);G[1]=G_1.charAt(0);G[2]=G_2.charAt(0);
                      B[0]=B_0.charAt(0);B[1]=B_1.charAt(0);B[2]=B_2.charAt(0);
                      Gf_0=String(OFF_B_1/100);Gf_1=String((OFF_B_1%100)/10);Gf_2=String((OFF_B_1%100)%10);
                      Bf_0=String(OFF_R_1/100);Bf_1=String((OFF_R_1%100)/10);Bf_2=String((OFF_R_1%100)%10);
                      Rf_0=String(OFF_G_1/100);Rf_1=String((OFF_G_1%100)/10);Rf_2=String((OFF_G_1%100)%10);
                      Rf[0]=Rf_0.charAt(0);Rf[1]=Rf_1.charAt(0);Rf[2]=Rf_2.charAt(0);
                      Gf[0]=Gf_0.charAt(0);Gf[1]=Gf_1.charAt(0);Gf[2]=Gf_2.charAt(0);
                      Bf[0]=Bf_0.charAt(0);Bf[1]=Bf_1.charAt(0);Bf[2]=Bf_2.charAt(0);
                      flag_load_1=1;flag_load_0=0;flag_load_2=0;flag_load_3=0;flag_load_4=0;flag_load_5=0;flag_load_6=0;flag_load_7=0;flag_load_8=0;flag_load_9=0;
                    }
            
                    if(String(nmbr)=="2"&&flag_load_2==0){
                      N[0]='0002';
                      G_0=String(ON_B_2/100);G_1=String((ON_B_2%100)/10);G_2=String((ON_B_2%100)%10);
                      B_0=String(ON_R_2/100);B_1=String((ON_R_2%100)/10);B_2=String((ON_R_2%100)%10);
                      R_0=String(ON_G_2/100);R_1=String((ON_G_2%100)/10);R_2=String((ON_G_2%100)%10);
                      R[0]=R_0.charAt(0);R[1]=R_1.charAt(0);R[2]=R_2.charAt(0);
                      G[0]=G_0.charAt(0);G[1]=G_1.charAt(0);G[2]=G_2.charAt(0);
                      B[0]=B_0.charAt(0);B[1]=B_1.charAt(0);B[2]=B_2.charAt(0);
                      Gf_0=String(OFF_B_2/100);Gf_1=String((OFF_B_2%100)/10);Gf_2=String((OFF_B_2%100)%10);
                      Bf_0=String(OFF_R_2/100);Bf_1=String((OFF_R_2%100)/10);Bf_2=String((OFF_R_2%100)%10);
                      Rf_0=String(OFF_G_2/100);Rf_1=String((OFF_G_2%100)/10);Rf_2=String((OFF_G_2%100)%10);
                      Rf[0]=Rf_0.charAt(0);Rf[1]=Rf_1.charAt(0);Rf[2]=Rf_2.charAt(0);
                      Gf[0]=Gf_0.charAt(0);Gf[1]=Gf_1.charAt(0);Gf[2]=Gf_2.charAt(0);
                      Bf[0]=Bf_0.charAt(0);Bf[1]=Bf_1.charAt(0);Bf[2]=Bf_2.charAt(0);
                      flag_load_2=1;flag_load_0=0;flag_load_1=0;flag_load_3=0;flag_load_4=0;flag_load_5=0;flag_load_6=0;flag_load_7=0;flag_load_8=0;flag_load_9=0;
                    }
                    if(String(nmbr)=="3"&&flag_load_3==0){
                      N[0]='0003';
                      G_0=String(ON_B_3/100);G_1=String((ON_B_3%100)/10);G_2=String((ON_B_3%100)%10);
                      B_0=String(ON_R_3/100);B_1=String((ON_R_3%100)/10);B_2=String((ON_R_3%100)%10);
                      R_0=String(ON_G_3/100);R_1=String((ON_G_3%100)/10);R_2=String((ON_G_3%100)%10);
                      R[0]=R_0.charAt(0);R[1]=R_1.charAt(0);R[2]=R_2.charAt(0);
                      G[0]=G_0.charAt(0);G[1]=G_1.charAt(0);G[2]=G_2.charAt(0);
                      B[0]=B_0.charAt(0);B[1]=B_1.charAt(0);B[2]=B_2.charAt(0);
                      Gf_0=String(OFF_B_3/100);Gf_1=String((OFF_B_3%100)/10);Gf_2=String((OFF_B_3%100)%10);
                      Bf_0=String(OFF_R_3/100);Bf_1=String((OFF_R_3%100)/10);Bf_2=String((OFF_R_3%100)%10);
                      Rf_0=String(OFF_G_3/100);Rf_1=String((OFF_G_3%100)/10);Rf_2=String((OFF_G_3%100)%10);
                      Rf[0]=Rf_0.charAt(0);Rf[1]=Rf_1.charAt(0);Rf[2]=Rf_2.charAt(0);
                      Gf[0]=Gf_0.charAt(0);Gf[1]=Gf_1.charAt(0);Gf[2]=Gf_2.charAt(0);
                      Bf[0]=Bf_0.charAt(0);Bf[1]=Bf_1.charAt(0);Bf[2]=Bf_2.charAt(0);
                      flag_load_3=1;flag_load_0=0;flag_load_1=0;flag_load_2=0;flag_load_4=0;flag_load_5=0;flag_load_6=0;flag_load_7=0;flag_load_8=0;flag_load_9=0;
                    }
                    if(String(nmbr)=="4"&&flag_load_4==0){
                      N[0]='0004';
                      G_0=String(ON_B_4/100);G_1=String((ON_B_4%100)/10);G_2=String((ON_B_4%100)%10);
                      B_0=String(ON_R_4/100);B_1=String((ON_R_4%100)/10);B_2=String((ON_R_4%100)%10);
                      R_0=String(ON_G_4/100);R_1=String((ON_G_4%100)/10);R_2=String((ON_G_4%100)%10);
                      R[0]=R_0.charAt(0);R[1]=R_1.charAt(0);R[2]=R_2.charAt(0);
                      G[0]=G_0.charAt(0);G[1]=G_1.charAt(0);G[2]=G_2.charAt(0);
                      B[0]=B_0.charAt(0);B[1]=B_1.charAt(0);B[2]=B_2.charAt(0);
                      Gf_0=String(OFF_B_4/100);Gf_1=String((OFF_B_4%100)/10);Gf_2=String((OFF_B_4%100)%10);
                      Bf_0=String(OFF_R_4/100);Bf_1=String((OFF_R_4%100)/10);Bf_2=String((OFF_R_4%100)%10);
                      Rf_0=String(OFF_G_4/100);Rf_1=String((OFF_G_4%100)/10);Rf_2=String((OFF_G_4%100)%10);
                      Rf[0]=Rf_0.charAt(0);Rf[1]=Rf_1.charAt(0);Rf[2]=Rf_2.charAt(0);
                      Gf[0]=Gf_0.charAt(0);Gf[1]=Gf_1.charAt(0);Gf[2]=Gf_2.charAt(0);
                      Bf[0]=Bf_0.charAt(0);Bf[1]=Bf_1.charAt(0);Bf[2]=Bf_2.charAt(0);
                      flag_load_4=1;flag_load_0=0;flag_load_1=0;flag_load_2=0;flag_load_3=0;flag_load_5=0;flag_load_6=0;flag_load_7=0;flag_load_8=0;flag_load_9=0;
                    }
                    if(String(nmbr)=="5"&&flag_load_5==0){
                      N[0]='0005';
                      G_0=String(ON_B_5/100);G_1=String((ON_B_5%100)/10);G_2=String((ON_B_5%100)%10);
                      B_0=String(ON_R_5/100);B_1=String((ON_R_5%100)/10);B_2=String((ON_R_5%100)%10);
                      R_0=String(ON_G_5/100);R_1=String((ON_G_5%100)/10);R_2=String((ON_G_5%100)%10);
                      R[0]=R_0.charAt(0);R[1]=R_1.charAt(0);R[2]=R_2.charAt(0);
                      G[0]=G_0.charAt(0);G[1]=G_1.charAt(0);G[2]=G_2.charAt(0);
                      B[0]=B_0.charAt(0);B[1]=B_1.charAt(0);B[2]=B_2.charAt(0);
                      Gf_0=String(OFF_B_5/100);Gf_1=String((OFF_B_5%100)/10);Gf_2=String((OFF_B_5%100)%10);
                      Bf_0=String(OFF_R_5/100);Bf_1=String((OFF_R_5%100)/10);Bf_2=String((OFF_R_5%100)%10);
                      Rf_0=String(OFF_G_5/100);Rf_1=String((OFF_G_5%100)/10);Rf_2=String((OFF_G_5%100)%10);
                      Rf[0]=Rf_0.charAt(0);Rf[1]=Rf_1.charAt(0);Rf[2]=Rf_2.charAt(0);
                      Gf[0]=Gf_0.charAt(0);Gf[1]=Gf_1.charAt(0);Gf[2]=Gf_2.charAt(0);
                      Bf[0]=Bf_0.charAt(0);Bf[1]=Bf_1.charAt(0);Bf[2]=Bf_2.charAt(0);
                      flag_load_5=1;flag_load_0=0;flag_load_1=0;flag_load_2=0;flag_load_3=0;flag_load_4=0;flag_load_6=0;flag_load_7=0;flag_load_8=0;flag_load_9=0;
                    }
                    if(String(nmbr)=="6"&&flag_load_6==0){
                      N[0]='0006';
                      G_0=String(ON_B_6/100);G_1=String((ON_B_6%100)/10);G_2=String((ON_B_6%100)%10);
                      B_0=String(ON_R_6/100);B_1=String((ON_R_6%100)/10);B_2=String((ON_R_6%100)%10);
                      R_0=String(ON_G_6/100);R_1=String((ON_G_6%100)/10);R_2=String((ON_G_6%100)%10);
                      R[0]=R_0.charAt(0);R[1]=R_1.charAt(0);R[2]=R_2.charAt(0);
                      G[0]=G_0.charAt(0);G[1]=G_1.charAt(0);G[2]=G_2.charAt(0);
                      B[0]=B_0.charAt(0);B[1]=B_1.charAt(0);B[2]=B_2.charAt(0);
                      Gf_0=String(OFF_B_6/100);Gf_1=String((OFF_B_6%100)/10);Gf_2=String((OFF_B_6%100)%10);
                      Bf_0=String(OFF_R_6/100);Bf_1=String((OFF_R_6%100)/10);Bf_2=String((OFF_R_6%100)%10);
                      Rf_0=String(OFF_G_6/100);Rf_1=String((OFF_G_6%100)/10);Rf_2=String((OFF_G_6%100)%10);
                      Rf[0]=Rf_0.charAt(0);Rf[1]=Rf_1.charAt(0);Rf[2]=Rf_2.charAt(0);
                      Gf[0]=Gf_0.charAt(0);Gf[1]=Gf_1.charAt(0);Gf[2]=Gf_2.charAt(0);
                      Bf[0]=Bf_0.charAt(0);Bf[1]=Bf_1.charAt(0);Bf[2]=Bf_2.charAt(0);
                      flag_load_6=1;flag_load_0=0;flag_load_1=0;flag_load_2=0;flag_load_3=0;flag_load_4=0;flag_load_5=0;flag_load_7=0;flag_load_8=0;flag_load_9=0;
                    }
                    if(String(nmbr)=="7"&&flag_load_7==0){
                      N[0]='0007';
                      G_0=String(ON_B_7/100);G_1=String((ON_B_7%100)/10);G_2=String((ON_B_7%100)%10);
                      B_0=String(ON_R_7/100);B_1=String((ON_R_7%100)/10);B_2=String((ON_R_7%100)%10);
                      R_0=String(ON_G_7/100);R_1=String((ON_G_7%100)/10);R_2=String((ON_G_7%100)%10);
                      R[0]=R_0.charAt(0);R[1]=R_1.charAt(0);R[2]=R_2.charAt(0);
                      G[0]=G_0.charAt(0);G[1]=G_1.charAt(0);G[2]=G_2.charAt(0);
                      B[0]=B_0.charAt(0);B[1]=B_1.charAt(0);B[2]=B_2.charAt(0);
                      Gf_0=String(OFF_B_7/100);Gf_1=String((OFF_B_7%100)/10);Gf_2=String((OFF_B_7%100)%10);
                      Bf_0=String(OFF_R_7/100);Bf_1=String((OFF_R_7%100)/10);Bf_2=String((OFF_R_7%100)%10);
                      Rf_0=String(OFF_G_7/100);Rf_1=String((OFF_G_7%100)/10);Rf_2=String((OFF_G_7%100)%10);
                      Rf[0]=Rf_0.charAt(0);Rf[1]=Rf_1.charAt(0);Rf[2]=Rf_2.charAt(0);
                      Gf[0]=Gf_0.charAt(0);Gf[1]=Gf_1.charAt(0);Gf[2]=Gf_2.charAt(0);
                      Bf[0]=Bf_0.charAt(0);Bf[1]=Bf_1.charAt(0);Bf[2]=Bf_2.charAt(0);
                      flag_load_7=1;flag_load_0=0;flag_load_1=0;flag_load_2=0;flag_load_3=0;flag_load_4=0;flag_load_5=0;flag_load_6=0;flag_load_8=0;flag_load_9=0;
                    }
                    if(String(nmbr)=="8"&&flag_load_8==0){
                      N[0]='0008';
                      G_0=String(ON_B_8/100);G_1=String((ON_B_8%100)/10);G_2=String((ON_B_8%100)%10);
                      B_0=String(ON_R_8/100);B_1=String((ON_R_8%100)/10);B_2=String((ON_R_8%100)%10);
                      R_0=String(ON_G_8/100);R_1=String((ON_G_8%100)/10);R_2=String((ON_G_8%100)%10);
                      R[0]=R_0.charAt(0);R[1]=R_1.charAt(0);R[2]=R_2.charAt(0);
                      G[0]=G_0.charAt(0);G[1]=G_1.charAt(0);G[2]=G_2.charAt(0);
                      B[0]=B_0.charAt(0);B[1]=B_1.charAt(0);B[2]=B_2.charAt(0);
                      Gf_0=String(OFF_B_8/100);Gf_1=String((OFF_B_8%100)/10);Gf_2=String((OFF_B_8%100)%10);
                      Bf_0=String(OFF_R_8/100);Bf_1=String((OFF_R_8%100)/10);Bf_2=String((OFF_R_8%100)%10);
                      Rf_0=String(OFF_G_8/100);Rf_1=String((OFF_G_8%100)/10);Rf_2=String((OFF_G_8%100)%10);
                      Rf[0]=Rf_0.charAt(0);Rf[1]=Rf_1.charAt(0);Rf[2]=Rf_2.charAt(0);
                      Gf[0]=Gf_0.charAt(0);Gf[1]=Gf_1.charAt(0);Gf[2]=Gf_2.charAt(0);
                      Bf[0]=Bf_0.charAt(0);Bf[1]=Bf_1.charAt(0);Bf[2]=Bf_2.charAt(0);
                      flag_load_8=1;flag_load_0=0;flag_load_1=0;flag_load_2=0;flag_load_3=0;flag_load_4=0;flag_load_5=0;flag_load_6=0;flag_load_7=0;flag_load_9=0;
                    }
                    if(String(nmbr)=="9"&&flag_load_9==0){
                      N[0]='0009';
                      G_0=String(ON_B_9/100);G_1=String((ON_B_9%100)/10);G_2=String((ON_B_9%100)%10);
                      B_0=String(ON_R_9/100);B_1=String((ON_R_9%100)/10);B_2=String((ON_R_9%100)%10);
                      R_0=String(ON_G_9/100);R_1=String((ON_G_9%100)/10);R_2=String((ON_G_9%100)%10);
                      R[0]=R_0.charAt(0);R[1]=R_1.charAt(0);R[2]=R_2.charAt(0);
                      G[0]=G_0.charAt(0);G[1]=G_1.charAt(0);G[2]=G_2.charAt(0);
                      B[0]=B_0.charAt(0);B[1]=B_1.charAt(0);B[2]=B_2.charAt(0);
                      Gf_0=String(OFF_B_9/100);Gf_1=String((OFF_B_9%100)/10);Gf_2=String((OFF_B_9%100)%10);
                      Bf_0=String(OFF_R_9/100);Bf_1=String((OFF_R_9%100)/10);Bf_2=String((OFF_R_9%100)%10);
                      Rf_0=String(OFF_G_9/100);Rf_1=String((OFF_G_9%100)/10);Rf_2=String((OFF_G_9%100)%10);
                      Rf[0]=Rf_0.charAt(0);Rf[1]=Rf_1.charAt(0);Rf[2]=Rf_2.charAt(0);
                      Gf[0]=Gf_0.charAt(0);Gf[1]=Gf_1.charAt(0);Gf[2]=Gf_2.charAt(0);
                      Bf[0]=Bf_0.charAt(0);Bf[1]=Bf_1.charAt(0);Bf[2]=Bf_2.charAt(0);
                      flag_load_9=1;flag_load_0=0;flag_load_1=0;flag_load_2=0;flag_load_3=0;flag_load_4=0;flag_load_5=0;flag_load_6=0;flag_load_7=0;flag_load_8=0;
                    }
          
                    Page += String(F ("<div class=\"tab0\"> <input style=\"font-size:500%;margin:0px;color:grey; background-color:#f0f0f0;width:100px;height:90px;\" maxlength=\"2\"  border:1px;solid black;\" type='text'   value='"))+String(N)+ String("'")+ String(F("name='nmbr'/> </div>"));
                    Page += String(F ("<div class=\"tab1\"> <input style=\"font-size:350%;margin:0px;color:black;background-color:lightgrey;  width:134px;height:90px;                border:1px;solid black;\" type='submit' value='Load' name='Load'/>                                 </div>"));
                    Page += String(F ("<div class=\"tab2\"> <input style=\"font-size:500%;margin:0px;color:grey; background-color:#f0f0f0;width:146px;height:90px;\" maxlength=\"3\"  border:1px;solid black;\" type='text'   value='"))+String(R)+String("'")+String(F("name='R'/>      </div>"));
                    Page += String(F ("<div class=\"tab3\"> <input style=\"font-size:500%;margin:0px;color:grey; background-color:#f0f0f0;width:146px;height:90px;\" maxlength=\"3\"  border:1px;solid black;\" type='text'   value='"))+String(G)+String("'")+String(F("name='G'/>      </div>"));
                    Page += String(F ("<div class=\"tab4\"> <input style=\"font-size:500%;margin:0px;color:grey; background-color:#f0f0f0;width:146px;height:90px;\" maxlength=\"3\"  border:1px;solid black;\" type='text'   value='"))+String(B)+String("'")+String(F("name='B'/>      </div>"));
                    Page += String(F ("<div class=\"tab5\"> <input style=\"font-size:400%;margin:0px;color:black;background-color:lightgrey;  width:122px;height:90px;                border:1px;solid black;\" type='submit' value='test' name='test'/>                                 </div>"));
                    Page += String(F ("<div class=\"tab6\"> <input style=\"font-size:400%;margin:0px;color:black;background-color:grey;       width:150px;height:90px;                border:1px;solid black;\" type='submit' value='Save' name='Save'/>                                 </div>"));
                    Page += String(F ("<div class=\"tab10\"><input style=\"font-size:500%;margin:0px;color:grey; background-color:#f0f0f0;width:100px;height:90px;\" maxlength=\"2\"  border:1px;solid black;\" type='text'   value='"))+String(N)+ String("'")+ String(F("name='nmbr'/> </div>"));
                    Page += String(F ("<div class=\"tab11\"><input style=\"font-size:350%;margin:0px;color:black;background-color:lightgrey;  width:134px;height:90px;                border:1px;solid black;\" type='submit' value='Load' name='Load'/>                                 </div>"));
                    Page += String(F ("<div class=\"tab12\"><input style=\"font-size:500%;margin:0px;color:grey; background-color:#f0f0f0;width:146px;height:90px;\" maxlength=\"3\"  border:1px;solid black;\" type='text'   value='"))+String(Rf)+String("'")+String(F("name='Rf'/>    </div>"));
                    Page += String(F ("<div class=\"tab13\"><input style=\"font-size:500%;margin:0px;color:grey; background-color:#f0f0f0;width:146px;height:90px;\" maxlength=\"3\"  border:1px;solid black;\" type='text'   value='"))+String(Gf)+String("'")+String(F("name='Gf'/>    </div>"));
                    Page += String(F ("<div class=\"tab14\"><input style=\"font-size:500%;margin:0px;color:grey; background-color:#f0f0f0;width:146px;height:90px;\" maxlength=\"3\"  border:1px;solid black;\" type='text'   value='"))+String(Bf)+String("'")+String(F("name='Bf'/>    </div>"));
                    Page += String(F ("<div class=\"tab15\"><input style=\"font-size:400%;margin:0px;color:black;background-color:lightgrey;  width:122px;height:90px;                border:1px;solid black;\" type='submit' value='test' name='test'/>                                 </div>"));
                    Page += String(F ("<div class=\"tab16\"><input style=\"font-size:400%;margin:0px;color:black;background-color:grey;       width:150px;height:90px;                border:1px;solid black;\" type='submit' value='Save' name='Save'/>                                 </div>"));           
                    Page += String(F ("</form>"));                   
                    
                    server.arg("Save").toCharArray(Save,sizeof(Save)-1);
                    server.arg("test").toCharArray(test,sizeof(test)-1);
                    server.arg("Load").toCharArray(Load,sizeof(Load)-1);
                    server.arg("nmbr").toCharArray(nmbr,sizeof(nmbr)-1);
                    server.arg("R").toCharArray(R,sizeof(R)-1);
                    server.arg("G").toCharArray(G,sizeof(G)-1);
                    server.arg("B").toCharArray(B,sizeof(B)-1);
                    server.arg("Rf").toCharArray(Rf,sizeof(Rf)-1);
                    server.arg("Gf").toCharArray(Gf,sizeof(Gf)-1);
                    server.arg("Bf").toCharArray(Bf,sizeof(Bf)-1);
                    
                    if(String(Load)=="Load"||String(test)=="test"){

                      if(String(nmbr)=="0"&&flag_load_0==1){
                        N[0]='0000';                       
                        ON_B_0=100*String(G[0]).toInt()+10*String(G[1]).toInt()+String(G[2]).toInt();     
                        ON_R_0=100*String(B[0]).toInt()+10*String(B[1]).toInt()+String(B[2]).toInt();
                        ON_G_0=100*String(R[0]).toInt()+10*String(R[1]).toInt()+String(R[2]).toInt();
                        G_0=String(ON_B_0/100);G_1=String((ON_B_0%100)/10);G_2=String((ON_B_0%100)%10);
                        B_0=String(ON_R_0/100);B_1=String((ON_R_0%100)/10);B_2=String((ON_R_0%100)%10);
                        R_0=String(ON_G_0/100);R_1=String((ON_G_0%100)/10);R_2=String((ON_G_0%100)%10);
                        OFF_B_0=100*String(Gf[0]).toInt()+10*String(Gf[1]).toInt()+String(Gf[2]).toInt();     
                        OFF_R_0=100*String(Bf[0]).toInt()+10*String(Bf[1]).toInt()+String(Bf[2]).toInt();
                        OFF_G_0=100*String(Rf[0]).toInt()+10*String(Rf[1]).toInt()+String(Rf[2]).toInt();
                        Gf_0=String(OFF_B_0/100);Gf_1=String((OFF_B_0%100)/10);Gf_2=String((OFF_B_0%100)%10);
                        Bf_0=String(OFF_R_0/100);Bf_1=String((OFF_R_0%100)/10);Bf_2=String((OFF_R_0%100)%10);
                        Rf_0=String(OFF_G_0/100);Rf_1=String((OFF_G_0%100)/10);Rf_2=String((OFF_G_0%100)%10);                      
                      }
                      if(String(nmbr)=="1"&&flag_load_1==1){
                        N[0]='0001';                       
                        ON_B_1=100*String(G[0]).toInt()+10*String(G[1]).toInt()+String(G[2]).toInt();     
                        ON_R_1=100*String(B[0]).toInt()+10*String(B[1]).toInt()+String(B[2]).toInt();
                        ON_G_1=100*String(R[0]).toInt()+10*String(R[1]).toInt()+String(R[2]).toInt();
                        G_0=String(ON_B_1/100);G_1=String((ON_B_1%100)/10);G_2=String((ON_B_1%100)%10);
                        B_0=String(ON_R_1/100);B_1=String((ON_R_1%100)/10);B_2=String((ON_R_1%100)%10);
                        R_0=String(ON_G_1/100);R_1=String((ON_G_1%100)/10);R_2=String((ON_G_1%100)%10);
                        OFF_B_1=100*String(Gf[0]).toInt()+10*String(Gf[1]).toInt()+String(Gf[2]).toInt();     
                        OFF_R_1=100*String(Bf[0]).toInt()+10*String(Bf[1]).toInt()+String(Bf[2]).toInt();
                        OFF_G_1=100*String(Rf[0]).toInt()+10*String(Rf[1]).toInt()+String(Rf[2]).toInt();
                        Gf_0=String(OFF_B_1/100);Gf_1=String((OFF_B_1%100)/10);Gf_2=String((OFF_B_1%100)%10);
                        Bf_0=String(OFF_R_1/100);Bf_1=String((OFF_R_1%100)/10);Bf_2=String((OFF_R_1%100)%10);
                        Rf_0=String(OFF_G_1/100);Rf_1=String((OFF_G_1%100)/10);Rf_2=String((OFF_G_1%100)%10);                      
                      }
                      if(String(nmbr)=="2"&&flag_load_2==1){
                        N[0]='0002'; 
                        ON_B_2=100*String(G[0]).toInt()+10*String(G[1]).toInt()+String(G[2]).toInt();     
                        ON_R_2=100*String(B[0]).toInt()+10*String(B[1]).toInt()+String(B[2]).toInt();
                        ON_G_2=100*String(R[0]).toInt()+10*String(R[1]).toInt()+String(R[2]).toInt();
                        G_0=String(ON_B_2/100);G_1=String((ON_B_2%100)/10);G_2=String((ON_B_2%100)%10);
                        B_0=String(ON_R_2/100);B_1=String((ON_R_2%100)/10);B_2=String((ON_R_2%100)%10);
                        R_0=String(ON_G_2/100);R_1=String((ON_G_2%100)/10);R_2=String((ON_G_2%100)%10);
                        OFF_B_2=100*String(Gf[0]).toInt()+10*String(Gf[1]).toInt()+String(Gf[2]).toInt();     
                        OFF_R_2=100*String(Bf[0]).toInt()+10*String(Bf[1]).toInt()+String(Bf[2]).toInt();
                        OFF_G_2=100*String(Rf[0]).toInt()+10*String(Rf[1]).toInt()+String(Rf[2]).toInt();
                        Gf_0=String(OFF_B_2/100);Gf_1=String((OFF_B_2%100)/10);Gf_2=String((OFF_B_2%100)%10);
                        Bf_0=String(OFF_R_2/100);Bf_1=String((OFF_R_2%100)/10);Bf_2=String((OFF_R_2%100)%10);
                        Rf_0=String(OFF_G_2/100);Rf_1=String((OFF_G_2%100)/10);Rf_2=String((OFF_G_2%100)%10);
                      }
                     if(String(nmbr)=="3"&&flag_load_3==1){
                        N[0]='0003'; 
                        ON_B_3=100*String(G[0]).toInt()+10*String(G[1]).toInt()+String(G[2]).toInt();     
                        ON_R_3=100*String(B[0]).toInt()+10*String(B[1]).toInt()+String(B[2]).toInt();
                        ON_G_3=100*String(R[0]).toInt()+10*String(R[1]).toInt()+String(R[2]).toInt();
                        G_0=String(ON_B_3/100);G_1=String((ON_B_3%100)/10);G_2=String((ON_B_3%100)%10);
                        B_0=String(ON_R_3/100);B_1=String((ON_R_3%100)/10);B_2=String((ON_R_3%100)%10);
                        R_0=String(ON_G_3/100);R_1=String((ON_G_3%100)/10);R_2=String((ON_G_3%100)%10);
                        OFF_B_3=100*String(Gf[0]).toInt()+10*String(Gf[1]).toInt()+String(Gf[2]).toInt();     
                        OFF_R_3=100*String(Bf[0]).toInt()+10*String(Bf[1]).toInt()+String(Bf[2]).toInt();
                        OFF_G_3=100*String(Rf[0]).toInt()+10*String(Rf[1]).toInt()+String(Rf[2]).toInt();
                        Gf_0=String(OFF_B_3/100);Gf_1=String((OFF_B_3%100)/10);Gf_2=String((OFF_B_3%100)%10);
                        Bf_0=String(OFF_R_3/100);Bf_1=String((OFF_R_3%100)/10);Bf_2=String((OFF_R_3%100)%10);
                        Rf_0=String(OFF_G_3/100);Rf_1=String((OFF_G_3%100)/10);Rf_2=String((OFF_G_3%100)%10);
                      }
                      if(String(nmbr)=="4"&&flag_load_4==1){
                        N[0]='0004'; 
                        ON_B_4=100*String(G[0]).toInt()+10*String(G[1]).toInt()+String(G[2]).toInt();     
                        ON_R_4=100*String(B[0]).toInt()+10*String(B[1]).toInt()+String(B[2]).toInt();
                        ON_G_4=100*String(R[0]).toInt()+10*String(R[1]).toInt()+String(R[2]).toInt();
                        G_0=String(ON_B_4/100);G_1=String((ON_B_4%100)/10);G_2=String((ON_B_4%100)%10);
                        B_0=String(ON_R_4/100);B_1=String((ON_R_4%100)/10);B_2=String((ON_R_4%100)%10);
                        R_0=String(ON_G_4/100);R_1=String((ON_G_4%100)/10);R_2=String((ON_G_4%100)%10);
                        OFF_B_4=100*String(Gf[0]).toInt()+10*String(Gf[1]).toInt()+String(Gf[2]).toInt();     
                        OFF_R_4=100*String(Bf[0]).toInt()+10*String(Bf[1]).toInt()+String(Bf[2]).toInt();
                        OFF_G_4=100*String(Rf[0]).toInt()+10*String(Rf[1]).toInt()+String(Rf[2]).toInt();
                        Gf_0=String(OFF_B_4/100);Gf_1=String((OFF_B_4%100)/10);Gf_2=String((OFF_B_4%100)%10);
                        Bf_0=String(OFF_R_4/100);Bf_1=String((OFF_R_4%100)/10);Bf_2=String((OFF_R_4%100)%10);
                        Rf_0=String(OFF_G_4/100);Rf_1=String((OFF_G_4%100)/10);Rf_2=String((OFF_G_4%100)%10);
                      }
                      if(String(nmbr)=="5"&&flag_load_5==1){
                        N[0]='0005'; 
                        ON_B_5=100*String(G[0]).toInt()+10*String(G[1]).toInt()+String(G[2]).toInt();     
                        ON_R_5=100*String(B[0]).toInt()+10*String(B[1]).toInt()+String(B[2]).toInt();
                        ON_G_5=100*String(R[0]).toInt()+10*String(R[1]).toInt()+String(R[2]).toInt();
                        G_0=String(ON_B_5/100);G_1=String((ON_B_5%100)/10);G_2=String((ON_B_5%100)%10);
                        B_0=String(ON_R_5/100);B_1=String((ON_R_5%100)/10);B_2=String((ON_R_5%100)%10);
                        R_0=String(ON_G_5/100);R_1=String((ON_G_5%100)/10);R_2=String((ON_G_5%100)%10);
                        OFF_B_5=100*String(Gf[0]).toInt()+10*String(Gf[1]).toInt()+String(Gf[2]).toInt();     
                        OFF_R_5=100*String(Bf[0]).toInt()+10*String(Bf[1]).toInt()+String(Bf[2]).toInt();
                        OFF_G_5=100*String(Rf[0]).toInt()+10*String(Rf[1]).toInt()+String(Rf[2]).toInt();
                        Gf_0=String(OFF_B_5/100);Gf_1=String((OFF_B_5%100)/10);Gf_2=String((OFF_B_5%100)%10);
                        Bf_0=String(OFF_R_5/100);Bf_1=String((OFF_R_5%100)/10);Bf_2=String((OFF_R_5%100)%10);
                        Rf_0=String(OFF_G_5/100);Rf_1=String((OFF_G_5%100)/10);Rf_2=String((OFF_G_5%100)%10);
                      }
                      if(String(nmbr)=="6"&&flag_load_6==1){
                        N[0]='0006'; 
                        ON_B_6=100*String(G[0]).toInt()+10*String(G[1]).toInt()+String(G[2]).toInt();     
                        ON_R_6=100*String(B[0]).toInt()+10*String(B[1]).toInt()+String(B[2]).toInt();
                        ON_G_6=100*String(R[0]).toInt()+10*String(R[1]).toInt()+String(R[2]).toInt();
                        G_0=String(ON_B_6/100);G_1=String((ON_B_6%100)/10);G_2=String((ON_B_6%100)%10);
                        B_0=String(ON_R_6/100);B_1=String((ON_R_6%100)/10);B_2=String((ON_R_6%100)%10);
                        R_0=String(ON_G_6/100);R_1=String((ON_G_6%100)/10);R_2=String((ON_G_6%100)%10);
                        OFF_B_6=100*String(Gf[0]).toInt()+10*String(Gf[1]).toInt()+String(Gf[2]).toInt();     
                        OFF_R_6=100*String(Bf[0]).toInt()+10*String(Bf[1]).toInt()+String(Bf[2]).toInt();
                        OFF_G_6=100*String(Rf[0]).toInt()+10*String(Rf[1]).toInt()+String(Rf[2]).toInt();
                        Gf_0=String(OFF_B_6/100);Gf_1=String((OFF_B_6%100)/10);Gf_2=String((OFF_B_6%100)%10);
                        Bf_0=String(OFF_R_6/100);Bf_1=String((OFF_R_6%100)/10);Bf_2=String((OFF_R_6%100)%10);
                        Rf_0=String(OFF_G_6/100);Rf_1=String((OFF_G_6%100)/10);Rf_2=String((OFF_G_6%100)%10);
                      }
                      if(String(nmbr)=="7"&&flag_load_7==1){
                        N[0]='0007'; 
                        ON_B_7=100*String(G[0]).toInt()+10*String(G[1]).toInt()+String(G[2]).toInt();     
                        ON_R_7=100*String(B[0]).toInt()+10*String(B[1]).toInt()+String(B[2]).toInt();
                        ON_G_7=100*String(R[0]).toInt()+10*String(R[1]).toInt()+String(R[2]).toInt();
                        G_0=String(ON_B_7/100);G_1=String((ON_B_7%100)/10);G_2=String((ON_B_7%100)%10);
                        B_0=String(ON_R_7/100);B_1=String((ON_R_7%100)/10);B_2=String((ON_R_7%100)%10);
                        R_0=String(ON_G_7/100);R_1=String((ON_G_7%100)/10);R_2=String((ON_G_7%100)%10);
                        OFF_B_7=100*String(Gf[0]).toInt()+10*String(Gf[1]).toInt()+String(Gf[2]).toInt();     
                        OFF_R_7=100*String(Bf[0]).toInt()+10*String(Bf[1]).toInt()+String(Bf[2]).toInt();
                        OFF_G_7=100*String(Rf[0]).toInt()+10*String(Rf[1]).toInt()+String(Rf[2]).toInt();
                        Gf_0=String(OFF_B_7/100);Gf_1=String((OFF_B_7%100)/10);Gf_2=String((OFF_B_7%100)%10);
                        Bf_0=String(OFF_R_7/100);Bf_1=String((OFF_R_7%100)/10);Bf_2=String((OFF_R_7%100)%10);
                        Rf_0=String(OFF_G_7/100);Rf_1=String((OFF_G_7%100)/10);Rf_2=String((OFF_G_7%100)%10);
                      }
                      if(String(nmbr)=="8"&&flag_load_8==1){
                        N[0]='0008'; 
                        ON_B_8=100*String(G[0]).toInt()+10*String(G[1]).toInt()+String(G[2]).toInt();     
                        ON_R_8=100*String(B[0]).toInt()+10*String(B[1]).toInt()+String(B[2]).toInt();
                        ON_G_8=100*String(R[0]).toInt()+10*String(R[1]).toInt()+String(R[2]).toInt();
                        G_0=String(ON_B_8/100);G_1=String((ON_B_8%100)/10);G_2=String((ON_B_8%100)%10);
                        B_0=String(ON_R_8/100);B_1=String((ON_R_8%100)/10);B_2=String((ON_R_8%100)%10);
                        R_0=String(ON_G_8/100);R_1=String((ON_G_8%100)/10);R_2=String((ON_G_8%100)%10);
                        OFF_B_8=100*String(Gf[0]).toInt()+10*String(Gf[1]).toInt()+String(Gf[2]).toInt();     
                        OFF_R_8=100*String(Bf[0]).toInt()+10*String(Bf[1]).toInt()+String(Bf[2]).toInt();
                        OFF_G_8=100*String(Rf[0]).toInt()+10*String(Rf[1]).toInt()+String(Rf[2]).toInt();
                        Gf_0=String(OFF_B_8/100);Gf_1=String((OFF_B_8%100)/10);Gf_2=String((OFF_B_8%100)%10);
                        Bf_0=String(OFF_R_8/100);Bf_1=String((OFF_R_8%100)/10);Bf_2=String((OFF_R_8%100)%10);
                        Rf_0=String(OFF_G_8/100);Rf_1=String((OFF_G_8%100)/10);Rf_2=String((OFF_G_8%100)%10);
                      }
                      if(String(nmbr)=="9"&&flag_load_9==1){
                        N[0]='0009'; 
                        ON_B_9=100*String(G[0]).toInt()+10*String(G[1]).toInt()+String(G[2]).toInt();     
                        ON_R_9=100*String(B[0]).toInt()+10*String(B[1]).toInt()+String(B[2]).toInt();
                        ON_G_9=100*String(R[0]).toInt()+10*String(R[1]).toInt()+String(R[2]).toInt();
                        G_0=String(ON_B_9/100);G_1=String((ON_B_9%100)/10);G_2=String((ON_B_9%100)%10);
                        B_0=String(ON_R_9/100);B_1=String((ON_R_9%100)/10);B_2=String((ON_R_9%100)%10);
                        R_0=String(ON_G_9/100);R_1=String((ON_G_9%100)/10);R_2=String((ON_G_9%100)%10);
                        OFF_B_9=100*String(Gf[0]).toInt()+10*String(Gf[1]).toInt()+String(Gf[2]).toInt();     
                        OFF_R_9=100*String(Bf[0]).toInt()+10*String(Bf[1]).toInt()+String(Bf[2]).toInt();
                        OFF_G_9=100*String(Rf[0]).toInt()+10*String(Rf[1]).toInt()+String(Rf[2]).toInt();
                        Gf_0=String(OFF_B_9/100);Gf_1=String((OFF_B_9%100)/10);Gf_2=String((OFF_B_9%100)%10);
                        Bf_0=String(OFF_R_9/100);Bf_1=String((OFF_R_9%100)/10);Bf_2=String((OFF_R_9%100)%10);
                        Rf_0=String(OFF_G_9/100);Rf_1=String((OFF_G_9%100)/10);Rf_2=String((OFF_G_9%100)%10);
                      }
                      
                      R[0]=R_0.charAt(0);R[1]=R_1.charAt(0);R[2]=R_2.charAt(0);
                      G[0]=G_0.charAt(0);G[1]=G_1.charAt(0);G[2]=G_2.charAt(0);
                      B[0]=B_0.charAt(0);B[1]=B_1.charAt(0);B[2]=B_2.charAt(0);
                      Rf[0]=Rf_0.charAt(0);Rf[1]=Rf_1.charAt(0);Rf[2]=Rf_2.charAt(0);
                      Gf[0]=Gf_0.charAt(0);Gf[1]=Gf_1.charAt(0);Gf[2]=Gf_2.charAt(0);
                      Bf[0]=Bf_0.charAt(0);Bf[1]=Bf_1.charAt(0);Bf[2]=Bf_2.charAt(0);
            
                      server.sendHeader("Refresh","0" );
                    
                   }

                   if(String(test)=="test"){
                     if(String(nmbr)=="0"){leds_on0();}
                     if(String(nmbr)=="1"){leds_on1();}
                     if(String(nmbr)=="2"){leds_on2();}
                     if(String(nmbr)=="3"){leds_on3();} 
                     if(String(nmbr)=="4"){leds_on4();}
                     if(String(nmbr)=="5"){leds_on5();}
                     if(String(nmbr)=="6"){leds_on6();}
                     if(String(nmbr)=="7"){leds_on7();}
                     if(String(nmbr)=="8"){leds_on8();}
                     if(String(nmbr)=="9"){leds_on9();}
                    }

                   if(String(Save)=="Save"){
                    if(String(nmbr)=="0"){saveLEDS_ON0();}
                    if(String(nmbr)=="1"){saveLEDS_ON1();}
                    if(String(nmbr)=="2"){saveLEDS_ON2();}
                    if(String(nmbr)=="3"){saveLEDS_ON3();}
                    if(String(nmbr)=="4"){saveLEDS_ON4();}
                    if(String(nmbr)=="5"){saveLEDS_ON5();}
                    if(String(nmbr)=="6"){saveLEDS_ON6();}
                    if(String(nmbr)=="7"){saveLEDS_ON7();}
                    if(String(nmbr)=="8"){saveLEDS_ON8();}
                    if(String(nmbr)=="9"){saveLEDS_ON9();}
                    //nmbr[0]='000N';
                    N[0]='000N';
                    flag_load_0=0;flag_load_1=0;flag_load_2=0;flag_load_3=0;flag_load_4=0;flag_load_5=0;flag_load_6=0;flag_load_7=0;flag_load_8=0;flag_load_9=0;
                    server.sendHeader("Refresh","0" );
                   }
                  
                    Page += F("<br>""<br>""<br>""<br>");
                                      
                    Page += F("<h2><a style=\"font-size:250%;font-family:verdana;color:#0000ff;\" href='/'><  Back</a></h2>"
                              "<br>""<br>""<br>"
                              "<h2 style=\"text-align:center;font-size:700%;font-family:verdana;color:#800000;\">Mercedes.iO</h2>"
                              "</body></html>"
                              );
                    server.send(200, "text/html", Page);
                    server.client().stop(); // Stop is needed because we sent no content length 
}

void handleBlinker_2() {
                    server.sendHeader("Cache-Control", "no-cache, no-store, must-revalidate" );
                    server.sendHeader("Pragma", "no-cache");
                    server.sendHeader("Expires", "-1");

                    String Page;
                                
                    Page += F( "<html><head></head><body style=\"background-color:#f8f8f8;\">"
                               "<h1 style=\"background-color:black;text-align:center;font-size:400%;color:white;margin:2px;\" >JACKTHEMAKER</h1>"
                               "<h2 style=\"background-color:#ffffb0;text-align:center;font-size:400%;margin:2px;\">round_BLINKER</h2>"
                             );

                    if (server.client().localIP() == apIP)  {
                    Page += String( F( "<pre style=\"font-size:250%;color:#0000a0;\"><b>You are connected to:    </b>")) + softAP_ssid + "   "+F("");
                    Page += String( F( "<br>")) + "                         " + toStringIp(WiFi.softAPIP()) + F("</pre>");
                    } else {Page += String(F("<pre><b>You are connected through the wifi network: </b>")) + ssid + F("</pre>");}
                    Page += String( F( "<pre style=\"font-size:250%;color:#0000a0;\"><b>WLAN config     ssid:    </b>")) + String(ssid) + "<br>" +"<b>                  ip:    </b>" + toStringIp(WiFi.localIP()) + F("</pre>");
                    Page += String( F( "<pre style=\"font-size:250%;color:#0000a0;\"><b>SERVER config   ssid:    </b>")) + SERVER + "<br>" + "<b>                port:    </b>" + SERVERPORT + F("</pre>");
                    Page += String( F( "<pre style=\"font-size:250%;color:#0000a0;\"><b>MQTT config username:    </b>")) + MQTT_USERNAME + "<br>" + "<b>                 key:    </b>" + MQTT_KEY + F("</pre>");
     
                    Page += F("<form method='POST' >"
                              "<h1 style=\"background-color:yellow;text-align:center;height:2px;\"></h1>"
                              "<h2 style=\"font-size:400%;\"></h2>"
                              "<h2 style=\"font-size:400%;\">PARAMETERS ADJUST</h2>" 
                              "<style>.tab0{float:left;margin:0px;padding:0px;max-width:100px;height:100px;border:1px solid black;}"
                                     ".tab1{float:left;margin:0px;padding:0px;max-width:200px;height:100px;border:1px solid black;}"
                                     ".tab2{float:left;margin:0px;padding:0px;max-width:146px;height:100px;border:1px solid black;}"
                                     ".tab3{float:left;margin:0px;padding:0px;max-width:146px;height:100px;border:1px solid black;}"
                                     ".tab4{float:left;margin:0px;padding:0px;max-width:146px;height:100px;border:1px solid black;}"
                                     ".tab5{float:left;margin:0px;padding:0px;max-width:124px;height:100px;border:1px solid black;}"
                                     ".tab6{float:left;margin:0px;padding:0px;max-width:128px;height:100px;border:1px solid black;}</style>");
                     Page +=String(F("<div class=\"tab0\"><input style=\"font-size:500%;margin:0px;max-width:100px;\" maxlength=\"2\" height:100px;border:1px;  solid black;color:black;background-color:lightyellow;\" type='text' value='"))+String(N)+String("'")+ String(F("name='nmbr'/>  </div>"));
                     Page +=F("<div class=\"tab1\"><input style=\"font-size:400%;margin:0px;max-width:180px;                   height:100px;border:1px;  solid black;color:black;background-color:lightgrey;\" type='submit' value='Load' name='Load'/>                  </div>");
           
            if(String(nmbr)=="1"){
             
            R_0=String(ON_B_1/100);R_1=String((ON_B_1%100)/10);R_2=String((ON_B_1%100)%10);
            G_0=String(ON_R_1/100);G_1=String((ON_R_1%100)/10);G_2=String((ON_R_1%100)%10);
            B_0=String(ON_G_1/100);B_1=String((ON_G_1%100)/10);B_2=String((ON_G_1%100)%10);
            R[0]=R_0.charAt(0);R[1]=R_1.charAt(0);R[2]=R_2.charAt(0);
            G[0]=G_0.charAt(0);G[1]=G_1.charAt(0);G[2]=G_2.charAt(0);
            B[0]=B_0.charAt(0);B[1]=B_1.charAt(0);B[2]=B_2.charAt(0);
            }
            if(String(nmbr)=="2"){
            R_0=String(ON_B_2/100);R_1=String((ON_B_2%100)/10);R_2=String((ON_B_2%100)%10);
            G_0=String(ON_R_2/100);G_1=String((ON_R_2%100)/10);G_2=String((ON_R_2%100)%10);
            B_0=String(ON_G_2/100);B_1=String((ON_G_2%100)/10);B_2=String((ON_G_2%100)%10);
            R[0]=R_0.charAt(0);R[1]=R_1.charAt(0);R[2]=R_2.charAt(0);
            G[0]=G_0.charAt(0);G[1]=G_1.charAt(0);G[2]=G_2.charAt(0);
            B[0]=B_0.charAt(0);B[1]=B_1.charAt(0);B[2]=B_2.charAt(0);
            }
                        
                   Page += String(F ("<div class=\"tab2\"><input style=\"font-size:500%;margin:0px;width:146px\" maxlength=\"3\"    height:100px;border:1px;  solid black;color:black;background-color:lightyellow;\" type='text' value='"))+String(R)+String("'")+String(F("name='R'/>   </div>"));
                   Page += String(F ("<div class=\"tab3\"><input style=\"font-size:500%;margin:0px;width:146px\" maxlength=\"3\"    height:100px;border:1px;  solid black;color:black;background-color:lightyellow;\" type='text' value='"))+String(G)+String("'")+String(F("name='G'/>   </div>"));
                   Page += String(F ("<div class=\"tab4\"><input style=\"font-size:500%;margin:0px;width:146px\" maxlength=\"3\"    height:100px;border:1px;  solid black;color:black;background-color:lightyellow;\" type='text' value='"))+String(B)+String("'")+String(F("name='B'/>   </div>"));
                   
                   Page += F ("<div class=\"tab5\"><input style=\"font-size:400%;margin:0px;width:124px;                      height:100px;border:1px;  solid black;color:black;background-color:lightgrey;\"   type='submit' value='test'/>                   </div>"
                              "<div class=\"tab6\"><input style=\"font-size:400%;margin:0px;width:128px;                      height:100px;border:1px;  solid black;color:black;background-color:grey;\"        type='submit' value='Save'/>                     </div>"
                              "</form>");

                    server.arg("Save").toCharArray(Save,sizeof(Save)-1);
                    server.arg("test").toCharArray(test,sizeof(test)-1);
                    server.arg("Load").toCharArray(Load,sizeof(Load)-1);
                    server.arg("nmbr").toCharArray(nmbr,sizeof(nmbr)-1);

                    //if(String(test)=="test"){
                    //  mqtt_data=String("ON")+String(nmbr);
                    //  Serial.print("mqtt_data ");Serial.println(mqtt_data); 
                    //}
                    
                    if(String(Load)=="Load"){Serial.print("Load:");Serial.println(ON_B_1); 
                     
                      server.arg("nmbr").toCharArray(nmbr,sizeof(nmbr)-1);
                      server.arg("R").toCharArray(R,sizeof(R)-1);
                      server.arg("G").toCharArray(G,sizeof(G)-1);
                      server.arg("B").toCharArray(B,sizeof(B)-1);
                      
                      if(String(nmbr)=="1"){
                      ON_B_1=100*String(R[0]).toInt()+10*String(R[1]).toInt()+String(R[2]).toInt();     
                      ON_R_1=100*String(G[0]).toInt()+10*String(G[1]).toInt()+String(G[2]).toInt();
                      ON_G_1=100*String(B[0]).toInt()+10*String(B[1]).toInt()+String(B[2]).toInt();
                      Serial.print("R:");Serial.println(ON_B_1); 
                      }
                      if(String(nmbr)=="2"){
                      ON_B_2=100*String(R[0]).toInt()+10*String(R[1]).toInt()+String(R[2]).toInt();     
                      ON_R_2=100*String(G[0]).toInt()+10*String(G[1]).toInt()+String(G[2]).toInt();
                      ON_G_2=100*String(B[0]).toInt()+10*String(B[1]).toInt()+String(B[2]).toInt();
                      Serial.print("R:");Serial.println(ON_B_2); 
                      }
                      }
                    
                    Page += F("<br>""<br>""<br>");
                                       
                    Page += F("<br>""<br>""<br>""<br>""<br>""<br>""<br>""<br>""<br>");   
                    Page += F("<h2><div class=\"tab7\" ><a style=\"font-size:250%;font-family:verdana;color:#0000ff;\"href='/'><  Back</a></div></h2>"
                            "</form></body></head></html>"
                           );
                                  
                    server.send(200, "text/html", Page);
                    server.client().stop(); // Stop is needed because we sent no content length 

}

boolean captivePortal() {
  /************************ Redirect to captive portal if we got a request for another domain. Return true in that case so the page handler do not try to handle the request again. */  
  if (!isIp(server.hostHeader())&&server.hostHeader()!=(String(myHostname)+".local")){
    Serial.println("Request redirected to captive portal");
    server.sendHeader("Location", String("http://") + toStringIp(server.client().localIP()), true);
    server.send ( 302, "text/plain", ""); /** Empty content inhibits Content-length header so we have to close the socket ourselves. **/
    server.client().stop(); /** Stop is needed because we sent no content length **/
    return true;
  }
  return false;
  }

void handleWifiSave() {
  Serial.println("wifi save");
  if(ep_creden==1){
  server.arg("n").toCharArray(ssid, sizeof(ssid) - 1);
  server.arg("p").toCharArray(password, sizeof(password) - 1);
  }
  if(ep_server==1){
  server.arg("q").toCharArray(SERVER, sizeof(SERVER) - 1);  
  server.arg("r").toCharArray(srvport, sizeof(srvport) - 1);
  SERVERPORT=0;
  conv_str_srvport=srvport;
  for(e=0;e<conv_str_srvport.length();e++){
    SERVERPORT=SERVERPORT+int((srvport[e]-48)*pow(10,conv_str_srvport.length()-1-e)); //converte caracter em int (X-48)
    Serial.print("SERVERPORT ");Serial.print(SERVERPORT);
  }
  }
  if(ep_mqtt==1){
  server.arg("s").toCharArray(MQTT_USERNAME, sizeof(MQTT_USERNAME) - 1);
  server.arg("t").toCharArray(MQTT_KEY, sizeof(MQTT_KEY) - 1);
  }
  if(ep_key==1){
  server.arg("u").toCharArray(KEY_BLINKER, sizeof(KEY_BLINKER) - 1);
  }
  if(ep_creden==1){
  server.sendHeader("Location", "wifi", true);
  }
  if(ep_server==1){
  server.sendHeader("Location", "server", true);
  }
  if(ep_mqtt==1){
  server.sendHeader("Location", "mqtt", true);
  }
  if(ep_key==1){
  server.sendHeader("Location", "key", true);
  }
  server.sendHeader("Cache-Control", "no-cache, no-store, must-revalidate");
  server.sendHeader("Pragma", "no-cache");
  server.sendHeader("Expires", "-1");
  server.send(302, "text/plain", "");    // Empty content inhibits Content-length header so we have to close the socket ourselves.
  server.client().stop(); // Stop is needed because we sent no content length
  if(ep_creden==1){
    saveCredentials();
    ep_creden=0;
  }  
  if(ep_server==1){
    saveSERVER();
    ep_server=0;
  }
  if(ep_mqtt==1){
    saveMQTT();
    ep_mqtt=0;
  }
  if(ep_key==1){
    saveKEY();
    ep_key=0;
  }
  connect = strlen(ssid) > 0; // Request WLAN connect with new credentials if there is a SSID
}

void handleNotFound() {
  if (captivePortal()) {/** If caprive portal redirect instead of displaying the error page. **/
    return;
  }
  String message = F("File Not Found\n\n");
  message += F("URI: ");
  message += server.uri();
  message += F("\nMethod: ");
  message += ( server.method() == HTTP_GET ) ? "GET" : "POST";
  message += F("\nArguments: ");
  message += server.args();
  message += F("\n");
  for ( uint8_t i = 0; i < server.args(); i++ ) {
    message += " " + server.argName ( i ) + F(": ") + server.arg ( i ) + F("\n");
  }
  server.sendHeader("Cache-Control", "no-cache, no-store, must-revalidate");
  server.sendHeader("Pragma", "no-cache");
  server.sendHeader("Expires", "-1");
  server.send ( 404, "text/plain", message );
}
