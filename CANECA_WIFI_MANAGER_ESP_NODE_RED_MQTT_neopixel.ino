

/********************************************************************/
/**           Software elaborado por Fernando Carvalho             **/
/*                    December-2020                                 */
/********************************************************************/
/* This software is based with a ESP8266.                           */
/*                                                                  */
/* Is possible to change de password, to acess the configuration,   */
/* which is: the connection to a local router                       */
/********************************************************************/
#include <ESP8266WiFi.h>          /** AP **/
#include <WiFiClient.h>           /** AP **/
#include <ESP8266WebServer.h>     /** AP **/
#include <DNSServer.h>            /** AP **/
#include <ESP8266mDNS.h>          /** AP **/


#include <ESP8266WiFiMulti.h>     /** Para o acesso ao Node-Red **/
#include <ESP8266HTTPClient.h>    /** Para o acesso ao Node-Red **/
#define USE_SERIAL Serial         /** Para o acesso ao Node-Red **/

ESP8266WiFiMulti WiFiMulti;       /** Para o acesso ao Node-Red **/
#include <PubSubClient.h>         /** Para o acesso ao MQTT do Node-Red **/

#include <EEPROM.h>/** AP **/
//********** livraria para acender os leds RGB *********//
//#include <Adafruit_DotStar.h>
//#include <SPI.h>  
#include <Adafruit_NeoPixel.h>

#define USERNAME          "led_username:abcdefghij,"  //Topic_1 no nodered_MQTT
#define PREAMBLE          "led_pass:456,"  //Topic_2 no nodered_MQTT
#define T_COMMAND         "led_action"  //Topic_3 no nodered_MQTT
unsigned long entry;
byte clientStatus, prevClientStatus = 99;
byte flag_connected=1;


#define DATAPIN 5 //16
//#define CLOCKPIN 4//14
#define NUMPIXELS 27
//Adafruit_DotStar strip(NUMPIXELS,DATAPIN, CLOCKPIN, DOTSTAR_BRG);

//#define LED_PIN    5
//#define LED_COUNT NUMPIXELS
//Adafruit_NeoPixel strip(NUMPIXELS, DATAPIN, NEO_BGR + NEO_KHZ800);
//Adafruit_NeoPixel strip(NUMPIXELS, DATAPIN, NEO_GBR + NEO_KHZ800);
//Adafruit_NeoPixel strip(NUMPIXELS, DATAPIN, NEO_RBG + NEO_KHZ800);
//Adafruit_NeoPixel strip(NUMPIXELS, DATAPIN, NEO_BRG + NEO_KHZ800);
Adafruit_NeoPixel strip(NUMPIXELS, DATAPIN, NEO_RGB + NEO_KHZ800);

#define LED 2
#define BUTTON 12

WiFiClient WiFiClient;
PubSubClient client(WiFiClient);

/**** This example serves a "BLINKER" on a WLAN and a SoftAP at the same time.
    * The SoftAP allow you to configure WLAN parameters at run time. They are not setup in the sketch but saved on EEPROM.
    * 
    * Connect your computer or cell phone to wifi network round_BLINKER with password 12345678. 
    * A popup may appear and it allow you to go to WLAN config. 
    * If it does not then navigate to http://192.168.4.1/wifi and config it there.
    * Then wait for the module to connect to your wifi and take note of the WLAN IP it got. 
    * Then you can disconnect from ESP_ap and return to your regular WLAN.
    * 
    * Now the ESP8266 is in your network. 
    * You can reach it through http://192.168.x.x/ (the IP you took note of) or maybe at http://esp8266.local too.
    * 
    * This is a captive portal because through the softAP it will redirect any http request to http://192.168.4.1/          
****/
/**** Set these to your desired softAP credentials. They are not configurable at runtime */
//**********************************************************************************************
//**********************************************************************************************
#ifndef APSSID


// ...

#define APSSID "roundBLINKER" //2º Nome varia para cada dispositivo

#define APPSK  "12345678"     //2º Password varia para cada dispositivo

#endif
//**********************************************************************************************
//**********************************************************************************************
/**** Set these to your desired softAP credentials. They are not configurable at runtime */
const char *softAP_ssid = APSSID;       //
const char *softAP_password = APPSK;    //

/**** hostname for mDNS. Should work at least on windows. Try http://esp8266.local */
//const char *myHostname = "blinker";
const char *myHostname = "";
/**** variaveis ******************************************************/
  int cnt=0;
  char SERVER[32]="";
  int SERVERPORT;
  char srvport[8]="";
  String conv_str_srvport;
  char MQTT_USERNAME[32]="";
  char MQTT_KEY[32]="";
  char KEY_BLINKER[14];
  char key_blnkr[14]; 
  int count_braq[30];   //guarda os numero de ordem dos leds dentro dos parentesis rectos
  String conv_crctr;
  String newpssw_tmp;
  char HOSTname[30];
  byte flag_AP;
      long    timer,tim_mqtt;
      long    strip_delay=0;
      long    flag_energy,flag_energyOFF,flag_energyON;
      byte    flag_access_filter=0;
      char    flag_zero[4];
      char    zero[4];
      byte    flag_BUTTON,flag_seq,braq_seq;
      long    lastConTry;
      byte    flag_lastConTry,flag_tim_mqtt;
      
      byte    RST=0;
      byte    ep_creden=0;
      byte    ep_server=0;
      byte    ep_mqtt=0;
      byte    ep_key=0;
      byte    flag_KEY=0;
      byte    flag_bright=0;
      long    tim_BUTTON;
      byte    flag2_BUTTON;
      String  content;
      int     i,e,n,p,i_seq,j_seq;
      int     length_seq;
      char    numb[6]      = {'0','0','0','0','0',0};
      char    numbpassw[6] = {'7','7','7','7','7',0};
      char    newpssw[5]   = {'9','9','9','9',0};  
      char    newpassw[6]  = {'0','0','0','0','0',0};  
      
      int     flag_changepassw;
      int     freq;
      long    length;
      String  mqtt_data;
      String  data;
      byte    flag_leds_on_seq;
      String  Bright_seq;
      int     BrightSeq;
      String  tmr_seq;
      int     tmrSeq,tmrSeqn;
      String  led_seq_n;
      int     ledSeqn;
      String  R_seq;
      int     RSeq;
      uint8_t RSeq0;
      String  G_seq;
      int     GSeq;
      uint8_t GSeq0;
      String  B_seq;
      int     BSeq;
      uint8_t BSeq0;
      int     RSeqfd,GSeqfd,BSeqfd;
      String  dly_seq;
      int     dlySeq;
      int     countb;
      int     nfG,nfR,nfB;
      int     brightseq0=0;
      char    nmbr[4];
      String  R_0,R_1,R_2,G_0,G_1,G_2,B_0,B_1,B_2;
      String  Rf_0,Rf_1,Rf_2,Gf_0,Gf_1,Gf_2,Bf_0,Bf_1,Bf_2;
      char    R[5]="R",Rf[5]="R";
      char    G[5]="G",Gf[5]="G";
      char    B[5]="B",Bf[5]="B";
      char    Load[6],test[6],Save[6];
      int     POS_MEM;
      int     V_BAT;
      long    tim_VBAT;
      long    tim_VBAT0;
      char    N[4]="N";
      byte    flag_load_0=0,flag_load_1=0,flag_load_2=0,flag_load_3=0,flag_load_4=0,flag_load_5=0,flag_load_6=0,flag_load_7=0,flag_load_8=0,flag_load_9=0;
      int     ON_B_0=0,   ON_B_1=0,   ON_B_2=010, ON_B_3=010, ON_B_4=010, ON_B_5=010, ON_B_6=010, ON_B_7=010, ON_B_8=010, ON_B_9=010;
      int     ON_R_0=0,   ON_R_1=0,   ON_R_2=0,   ON_R_3=0,   ON_R_4=0,   ON_R_5=0,   ON_R_6=0,   ON_R_7=0,   ON_R_8=0,   ON_R_9=0;
      int     ON_G_0=010, ON_G_1=010, ON_G_2=0,   ON_G_3=0,   ON_G_4=0,   ON_G_5=0,   ON_G_6=0,   ON_G_7=0,   ON_G_8=0,   ON_G_9=0;

      int     OFF_B_0=0,OFF_B_1=0,OFF_B_2=0,OFF_B_3=0,OFF_B_4=0,OFF_B_5=0,OFF_B_6=0,OFF_B_7=0,OFF_B_8=0,OFF_B_9=0;
      int     OFF_R_0=0,OFF_R_1=0,OFF_R_2=0,OFF_R_3=0,OFF_R_4=0,OFF_R_5=0,OFF_R_6=0,OFF_R_7=0,OFF_R_8=0,OFF_R_9=0;
      int     OFF_G_0=0,OFF_G_1=0,OFF_G_2=0,OFF_G_3=0,OFF_G_4=0,OFF_G_5=0,OFF_G_6=0,OFF_G_7=0,OFF_G_8=0,OFF_G_9=0;     

/**** Don't set this wifi credentials. They are configurated at runtime and stored on EEPROM */
char ssid[64] = "";
char password[64] = "";
    
/**** WS*********************************************/
      
      //int httpCode = -1;
      
      //String inputString="";
     // String inputStringComplete="";
/***************************************************/

/**** DNS server ****/
const byte DNS_PORT = 53;
DNSServer dnsServer;

/**** Web server ****/
ESP8266WebServer server(80);

/**** Soft AP network parameters ****/
IPAddress apIP(172, 217, 28, 1);
IPAddress netMsk(255, 255, 255, 0);

/**** Should I connect to WLAN asap? ****/
boolean connect;

/**** Last time I tried to connect to WLAN ****/
unsigned long lastConnectTry = 0;

/**** Current WLAN status ****/
unsigned int status = WL_IDLE_STATUS;

void setup() {
                Serial.begin(115200);
                Serial.println("start_SETUP");
              pinMode(LED,OUTPUT);
              pinMode(BUTTON,INPUT);
WiFi.softAPdisconnect (true);
              timer=millis();
              
              //ooooooooooo Initiate data
                EEPROM.begin(4096);
                flag_zero[0]=EEPROM.read(4000);flag_zero[1]=EEPROM.read(4001);flag_zero[2]=EEPROM.read(4002);flag_zero[3]=EEPROM.read(4003);
                EEPROM.end();
                  Serial.print("flag_zero: ");Serial.println(flag_zero);
                if(String(flag_zero)!="zero"){init_data();}
              //ooooooooooo Initiate data
                        
   //               Serial.println("Configuring access point...");
              //************ You can remove the password parameter if you want the AP to be open. *************/
   //             WiFi.softAPConfig(apIP, apIP, netMsk);
   //             WiFi.softAP(softAP_ssid, softAP_password);
   //             delay(1000); /** Without delay I've seen the IP address blank **/
                  Serial.print("AP IP address: ");
                  Serial.println(WiFi.softAPIP());

              //************ Setup the DNS server redirecting all the domains to the apIP *********************/  
    //            dnsServer.setErrorReplyCode(DNSReplyCode::NoError);
    //            dnsServer.start(DNS_PORT, "*", apIP);

              //************ Setup web pages: root, wifi config pages, SO captive portal detectors and not found. ****/               
                server.on("/", handleRoot); 
                server.on("/newpassw", handleNewPassw);   
                server.on("/rst", handleRST); 
                server.on("/key", handleKEY); 
                server.on("/server", handleSERVER);  
                server.on("/mqtt", handleMQTT);       
                server.on("/wifi", handleWifi);
                server.on("/blinker", handleBlinker);
                server.on("/wifisave", handleWifiSave);
                server.on("/generate_204", handleRoot);/** Android captive portal. Maybe not needed. Might be handled by notFound handler. **/  
                server.on("/fwlink", handleRoot);/** Microsoft captive portal. Maybe not needed. Might be handled by notFound handler. **/       
                server.onNotFound ( handleNotFound );
                server.begin();/** Web server start **/
     
                  Serial.println("HTTP server started");
                loadCredentials();/** Load WLAN credentials from network **/
                  Serial.print("ssid: ");Serial.println(ssid);
                  Serial.print("password: ");Serial.println(password);
                loadSERVER();
                  Serial.print("SERVER: ");Serial.println(SERVER);
                  Serial.print("SERVERPORT ");Serial.println(SERVERPORT);
                loadMQTT();
                  Serial.print("MQTT_USERNAME: ");Serial.println(MQTT_USERNAME);
                  Serial.print("MQTT_KEY: ");Serial.println(MQTT_KEY);
                loadKEY();
                  Serial.print("KEY: ");Serial.println(KEY_BLINKER);
                loadLEDS_ON0();loadLEDS_ON1();loadLEDS_ON2();loadLEDS_ON3();loadLEDS_ON4();loadLEDS_ON5();loadLEDS_ON6();loadLEDS_ON7();loadLEDS_ON8();loadLEDS_ON9();
                //connect = strlen(ssid) > 0;/** Request WLAN connect if there is a SSID **/ 

                ChangeHostname();
                
                //Switch off leds
                  strip.begin();
                  strip.clear();
                  strip.show();          
}

void ChangeHostname(){
            //*********** Mudar o nome do hostname de "ESP-" par "precious-" *****************
              HOSTname[0]='p';HOSTname[1]='r';HOSTname[2]='e';HOSTname[3]='c';
              HOSTname[4]='i';HOSTname[5]='o';HOSTname[6]='u';HOSTname[7]='s';HOSTname[8]='-';
              for (i=4;i<WiFi.hostname().length();i++){
                  HOSTname[i+5]+=WiFi.hostname()[i];     
              }
              myHostname=HOSTname;
              WiFi.hostname(HOSTname);                             
                  Serial.print("wifihostname: ");Serial.println(WiFi.hostname());              
            //**********************************************************************************    
}

void connectWifi()  {
                        Serial.println("Connecting as wifi client...");
                      WiFi.disconnect();
                      WiFi.begin ( ssid, password );
                      int connRes = WiFi.waitForConnectResult();
                        Serial.print ( "connRes: " );Serial.println ( connRes );
                    }

void connect_MQTT(){
      
      client.setServer(SERVER, SERVERPORT);
      client.setCallback(callback);
      yield();
      if (!client.connected()) {
        if(millis()-strip_delay>5000){
            Serial.println("Attempting MQTT connection...");
          //***** Attempt to connect
          if (client.connect("", MQTT_USERNAME, MQTT_KEY)) {
              //+++++++++++++++++++++++++++++++++++++++++
                strip.begin();
                //strip.clear();
                for (i=3;i<cnt+3;i++){strip.setPixelColor(i,0,0,0); }
                strip.setPixelColor(3,0,0,3);   //+++++++ Acende 4ºled. AZUL.
                strip.show();
                delay(2000);
              //+++++++++++++++++++++++++++++++++++++++++
                tim_mqtt=millis();
                flag_tim_mqtt=1;
                if(flag_BUTTON==0){
                  //+++++++++++++++++++++++++++++++++++++
                  //strip.begin();
                  strip.clear();
                  for (i=3;i>=0;i--){
                    strip.setPixelColor(i,0,0,5); //+++ Acende do 4º ao 0º led AZUL
                    strip.show();
                    delay(200);
                    strip.setPixelColor(i+1,0,0,0); //+++ Apaga do 4º ao 0º led AZUL
                    strip.show();
                    delay(200);
                    }
                  strip.setPixelColor(0,0,0,0); //+++ Apaga o 0º led AZUL
                  strip.show();
                  //+++++++++++++++++++++++++++++++++++++++
                  }
              // ... and resubscribe
                client.subscribe(USERNAME PREAMBLE T_COMMAND, 1);
              } else {
                if(cnt<10){
                cnt=cnt+1;
                  Serial.print(cnt);
                  Serial.print("failed, rc=");
                  Serial.print(client.state());
                  Serial.println(" try again in 5 seconds");
                //++++++++++++++++++++++++++++++++++++++++++++++++++++  Tentativa de concluir a ligacao    
                  strip.begin();
                  //strip.clear();
                  for (i=4;i<cnt+4;i++){strip.setPixelColor(i,0,i*i-8,0); }   //+++++ Acende leds vermelhos
                  strip.show();
                //++++++++++++++++++++++++++++++++++++++++++++++++++++  Tentativa de concluir a ligacao
                //***** Wait 5 seconds before retrying     
                  if(cnt==9){ 
                    for (i=cnt+4;i>4;i--){
                      //+++++++++++++++++++++++++++ Não conclui a ligacao
                      strip.begin();
                      strip.setPixelColor(i,0,0,0); //+++++ Apaga leds vermelhos 
                      strip.show();
                      delay(200);
                      cnt=0;
                      //+++++++++++++++++++++++++++ Não conclui a ligacao
                      }
                  }
        
                }
              }
            strip_delay=millis();
          } 
        }
        client.loop();
    }





void connectAP(){

          if(flag_AP==1){
                  Serial.println("Configuring access point...");
          //************ You can remove the password parameter if you want the AP to be open. *************/
              WiFi.softAPConfig(apIP, apIP, netMsk);
              WiFi.softAP(softAP_ssid, softAP_password);
              delay(500); /** Without delay I've seen the IP address blank **/
              Serial.print("AP IP address: ");
              Serial.println(WiFi.softAPIP());

           //************ Setup the DNS server redirecting all the domains to the apIP *********************/  
              dnsServer.setErrorReplyCode(DNSReplyCode::NoError);
              dnsServer.start(DNS_PORT, "*", apIP);
                  Serial.print("wifihostname: ");Serial.println(WiFi.hostname());
              connect = strlen(ssid) > 0;   
              flag_AP=0;      
          }

  
          //*****************ligar ao servidor de rede
          if (connect){
                  Serial.println ( "Connect requested" );
              connect = false;
              connectWifi(); 
              lastConnectTry = millis();
          }  

          {
            unsigned int s = WiFi.status();          
            if (s == 0 && millis() > (lastConnectTry + 60000)) {
            //**************** If WLAN disconnected and idle try to connect **********/
            //**************** Don't set retry time too low as retry interfere the softAP operation *********/
            connect = true;
            }
            if (status != s) { /******** WLAN status change ******/
                Serial.print ( "Status: " );Serial.println ( s );
              //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++  
                  strip.begin();                
                  strip.clear();
                  strip.setPixelColor(0,3,0,0); //+++++ Ligth 1ºled GREEN
                  strip.show();
                //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
            status = s;
                  
            if (s == WL_CONNECTED){
            //******************** Just connected to WLAN ***************************/
                  Serial.println ( "" );
                  Serial.print ( "Connected to " );
                  Serial.println ( ssid );
                  Serial.print ( "IP address: " );
                  Serial.println ( WiFi.localIP() );
            //+++++++++++++++++++ Liga-se a WLAN
                strip.begin();
                //strip.clear();
                strip.setPixelColor(1,3,0,0); //+++++ Acende 2º led. VERDE.
                strip.show();                    
            //+++++++++++++++++++ Liga-se a WLAN
                      
            //******************** Setup MDNS responder **************************//
                      if (!MDNS.begin(myHostname)){                               //
                        Serial.println("Error setting up MDNS responder!");       //
                          } else {                                                //
                                  Serial.println("mDNS responder started");       //
            //******************** Add service to MDNS-SD ************************//
                                  MDNS.addService("http", "tcp", 80);             //
                                 }                                                //
                           } else if (s == WL_NO_SSID_AVAIL) {                    //
                                      Serial.println("WiFi.disconnect");          //
                                      WiFi.disconnect();                          //
                                      cnt=0;
            } //******************************************************************//       
          }
          if (s == WL_CONNECTED) {
            MDNS.update();
          }                    
         }
          work();
        /********** DNS **********/
          dnsServer.processNextRequest();            
        /********** HTTP *********/
          server.handleClient();          
}

void callback(char* topic, byte * data, unsigned int length) {
      //***** handle message arrived 
        length_seq=length;
          Serial.print("length_seq: ");Serial.println(length_seq);
        mqtt_data="";
        flag_KEY=0;
        i=0;
      //for (int i=0;i<length;i++)
        do{
            Serial.print("0: done ");Serial.print(i);Serial.print(" ");Serial.print((char)data[i]);Serial.print(" ");Serial.println(KEY_BLINKER[i]);
          if((char)data[i]==KEY_BLINKER[0]&&(char)data[i+1]==KEY_BLINKER[1]&&(char)data[i+2]==KEY_BLINKER[2]&&
            (char)data[i+3]==KEY_BLINKER[3]&&(char)data[i+4]==KEY_BLINKER[4]&&(char)data[i+5]==KEY_BLINKER[5]&&
            (char)data[i+6]==KEY_BLINKER[6]&&(char)data[i+7]==KEY_BLINKER[7]&&(char)data[i+8]==KEY_BLINKER[8]&&
            (char)data[i+9]==KEY_BLINKER[9]){flag_KEY=1;Serial.println("0: done000 ");}
          i++;
        }while(flag_KEY==0&&i<length_seq);
          if(flag_KEY==1){
            for (int i = 0; i < length_seq; i++) {
              mqtt_data+=(char)data[i];
              if((char)data[i]=='O'&&(char)data[i+1]=='N'&&(char)data[i+2]=='0'){leds_on0();}
              if((char)data[i]=='O'&&(char)data[i+1]=='N'&&(char)data[i+2]=='1'){leds_on1();}     
              if((char)data[i]=='O'&&(char)data[i+1]=='N'&&(char)data[i+2]=='2'){leds_on2();}  
              if((char)data[i]=='O'&&(char)data[i+1]=='N'&&(char)data[i+2]=='3'){leds_on3();}
              if((char)data[i]=='O'&&(char)data[i+1]=='N'&&(char)data[i+2]=='4'){leds_on4();}
              if((char)data[i]=='O'&&(char)data[i+1]=='N'&&(char)data[i+2]=='5'){leds_on5();}     
              if((char)data[i]=='O'&&(char)data[i+1]=='N'&&(char)data[i+2]=='6'){leds_on6();}  
              if((char)data[i]=='O'&&(char)data[i+1]=='N'&&(char)data[i+2]=='7'){leds_on7();}
              if((char)data[i]=='O'&&(char)data[i+1]=='N'&&(char)data[i+2]=='8'){leds_on8();}
              if((char)data[i]=='O'&&(char)data[i+1]=='N'&&(char)data[i+2]=='9'){leds_on9();}
              if((char)data[i]=='S'&&(char)data[i+1]=='E'&&(char)data[i+2]=='Q'){flag_leds_on_seq=1;}    
              if((char)data[i]=='O'&&(char)data[i+1]=='F'&&(char)data[i+2]=='F'){leds_off();digitalWrite(LED, LOW);Serial.println("OFF_led");}
            }
          if(flag_leds_on_seq==1){leds_on_seq();flag_leds_on_seq=0;}
              Serial.println();
              Serial.println(mqtt_data);
              Serial.println();
    
          flag_KEY=0;
        }
    }

void loop() {

      
      if(digitalRead(BUTTON)==HIGH){flag_BUTTON=3;}     
         
      
      if(digitalRead(BUTTON)==LOW){
          if(flag_BUTTON==3){
              if(millis()-tim_VBAT<3000){flag_BUTTON=1; Serial.print("V_BAT1");Serial.println(millis()-tim_VBAT);}
              if(millis()-tim_VBAT>3000){flag_BUTTON=2; Serial.println("V_BAT2");tim_VBAT0=millis();}
          }
      }
      if(flag_BUTTON==0){
          tim_VBAT=millis();
          if(flag_AP==0){
                Serial.println("softAPdisconnect"); 
              flag_AP=1;
          } 
          connect_MQTT();
      }
      if(flag_BUTTON==1){
        if(flag_AP==1){
            Serial.println("softAPconnect");
          connectAP();
          flag_AP=0;
        }       
        connect_MQTT();
        connectAP();
        //tim_VBAT=millis();
      }
      if(flag_BUTTON==2){
        V_BAT=analogRead(A0); //5 steps: 4.2V,3.95V,3.7V,3.45V,3.2V
        Serial.print("V_BAT");Serial.println(V_BAT);
        int range = map(V_BAT, 748,976,0,4);
        Serial.print("range");Serial.println(range);
        switch (range){
          case 0:
            strip.begin();
            strip.clear();
            strip.setPixelColor(0,0,3,0);
            strip.show();
            break;
          case 1:
            strip.begin();
            strip.clear();
            strip.setPixelColor(0,0,3,0);
            strip.setPixelColor(1,1,3,0);
            strip.show();
            break;
          case 2:
            strip.begin();
            strip.clear();
            strip.setPixelColor(0,0,3,0);
            strip.setPixelColor(1,1,3,0);
            strip.setPixelColor(2,3,3,0);
            strip.show();
            break;
          case 3:
            strip.begin();
            strip.clear();
            strip.setPixelColor(0,3,0,0);
            strip.setPixelColor(1,3,1,0);
            strip.setPixelColor(2,3,3,0);
            strip.setPixelColor(3,1,1,0);
            strip.show();
            break;
          case 4:
            strip.begin();
            strip.clear();
            strip.setPixelColor(0,0,3,0);
            strip.setPixelColor(1,1,3,0);
            strip.setPixelColor(2,3,3,0);
            strip.setPixelColor(3,3,1,0);
            strip.setPixelColor(3,3,0,0);
            strip.show();
            break;        
        }
        if (range>4){
            strip.begin();
            strip.clear();
            strip.setPixelColor(0,0,3,0);
            strip.setPixelColor(1,1,3,0);
            strip.setPixelColor(2,3,3,0);
            strip.setPixelColor(3,3,1,0);
            strip.setPixelColor(3,3,0,0);
            strip.show();
        }
        if(millis()-tim_VBAT0>3000){
              strip.begin();
              strip.clear();
              strip.show();
            flag_BUTTON=0;}

}       
      if(RST==1){ESP.reset();}

      if(tim_mqtt>10000&&flag_tim_mqtt==1){
        strip.begin();
        strip.clear();
        strip.show();
        flag_tim_mqtt=0;
      }             
}

void work(){
            /********** Do work: *************/

}
              
