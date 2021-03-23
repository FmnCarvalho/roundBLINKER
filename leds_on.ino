void leds_on0(){
        strip.begin();
        strip.clear();
        for(p=0;p<1;p++){
        for (n=0;n<100;n++){
        strip.setBrightness(n);
        for (i=0;i<NUMPIXELS;i++){strip.setPixelColor(i,ON_B_0,ON_G_0,ON_R_0); }
        strip.show();
        delay(1);
        }
        for (n=100;n>0;n--){
        strip.setBrightness(n);
        for (i=0;i<NUMPIXELS;i++){strip.setPixelColor(i,OFF_B_0,OFF_G_0,OFF_R_0); }
        strip.show();
        delay(1);
        }
        }
        digitalWrite(LED, HIGH);
}

void leds_on1(){
        strip.begin();
        strip.clear();
        for(p=0;p<4;p++){
        for (n=0;n<100;n++){
        strip.setBrightness(n);
        for (i=0;i<NUMPIXELS;i++){strip.setPixelColor(i,ON_B_1,ON_G_1,ON_R_1); }
        strip.show();
        delay(1);
        }
        for (n=100;n>0;n--){
        strip.setBrightness(n);
        for (i=0;i<NUMPIXELS;i++){strip.setPixelColor(i,OFF_B_1,OFF_G_1,OFF_R_1); }
        strip.show();
        delay(1);
        }
        }
        digitalWrite(LED, HIGH);
}

void leds_on2(){
        strip.begin();
        strip.clear();
        strip.setBrightness(200);
        for (i=0;i<NUMPIXELS;i++){strip.setPixelColor(i,ON_B_2,ON_G_2,ON_R_2); }
        strip.show();
        delay(400);
        strip.clear();
        for (i=0;i<NUMPIXELS;i++){strip.setPixelColor(i,OFF_B_2,OFF_G_2,OFF_R_2); }
        strip.show();
        delay(100);
        strip.clear();
        for (i=0;i<NUMPIXELS;i++){strip.setPixelColor(i,ON_B_2,ON_G_2,ON_R_2); }
        strip.show(); 
        delay(100);
        strip.clear();
        for (i=0;i<NUMPIXELS;i++){strip.setPixelColor(i,OFF_B_2,OFF_G_2,OFF_R_2); }
        strip.show(); 
        delay(500);
        for (i=0;i<NUMPIXELS;i++){strip.setPixelColor(i,0,0,0); }
        strip.show(); 
        digitalWrite(LED, HIGH);
}
void leds_on3(){
        strip.begin();
        strip.clear();
        strip.setBrightness(200);
        for(p=0;p<NUMPIXELS/6;p++){
        for (i=0;i<NUMPIXELS/4;i++){strip.setPixelColor(i,ON_B_3,ON_G_3,ON_R_3); }
        strip.show();
        delay(300);
        strip.clear();
        for (i=NUMPIXELS/4;i<NUMPIXELS/2;i++){strip.setPixelColor(i,OFF_B_3,OFF_G_3,OFF_R_3); }
        strip.show();
        delay(300);
        strip.clear();
        for (i=NUMPIXELS/2;i<NUMPIXELS*3/4;i++){strip.setPixelColor(i,ON_B_3,ON_G_3,ON_R_3); }
        strip.show(); 
        delay(300);
        strip.clear();
        for (i=NUMPIXELS*3/4;i<NUMPIXELS;i++){strip.setPixelColor(i,OFF_B_3,OFF_G_3,OFF_R_3); }
        strip.show(); 
        delay(300);
        }
        for (i=0;i<NUMPIXELS;i++){strip.setPixelColor(i,0,0,0); }
        strip.show(); 
        digitalWrite(LED, HIGH);
}
void leds_on4(){
        strip.begin();
        strip.clear();
        strip.setBrightness(200);
        for(p=0;p<2;p++){
        for (i=0;i<NUMPIXELS;i++){strip.setPixelColor(i,ON_B_4,ON_G_4,ON_R_4);strip.show();delay(100);}
        for (i=0;i<NUMPIXELS;i++){strip.setPixelColor(i,OFF_B_4,OFF_G_4,OFF_R_4);strip.show();delay(100);}
        }
        for (i=0;i<NUMPIXELS;i++){strip.setPixelColor(i,0,0,0); }
        strip.show(); 
  }
void leds_on5(){
        strip.begin();
        strip.clear();
        strip.setBrightness(200);
        for(p=0;p<2;p++){
        for (i=0;i<NUMPIXELS;i++){strip.setPixelColor(i,ON_B_5,ON_G_5,ON_R_5);strip.show();delay(100);strip.setPixelColor(i,OFF_B_5,OFF_G_5,OFF_R_5);delay(100);}
        }
        for (i=0;i<NUMPIXELS;i++){strip.setPixelColor(i,0,0,0); }
        strip.show(); 
  }
void leds_on6(){
        strip.begin();
        strip.clear();
        strip.setBrightness(200);
        for(p=0;p<2;p++){
        for (i=0;i<NUMPIXELS;i++){strip.setPixelColor(i,ON_B_6,ON_G_6,ON_R_6);strip.show();delay(40);strip.setPixelColor(i,OFF_B_6,OFF_G_6,OFF_R_6);delay(40);}
        }
        for (i=0;i<NUMPIXELS;i++){strip.setPixelColor(i,0,0,0); }
        strip.show(); 
  }
void leds_on7(){
        strip.begin();
        strip.clear();
        strip.setBrightness(200);
        for(p=0;p<4;p++){
        for (i=0;i<NUMPIXELS;i++){strip.setPixelColor(i,ON_B_7,ON_G_7,ON_R_7);strip.show();delay(100);strip.setPixelColor(i,OFF_B_7,OFF_G_7,OFF_R_7);delay(100);}
        }
        for (i=0;i<NUMPIXELS;i++){strip.setPixelColor(i,0,0,0); }
        strip.show(); 
  }
void leds_on8(){
        strip.begin();
        strip.clear();
        strip.setBrightness(200);
        for(p=0;p<4;p++){
          for (i=p;i<NUMPIXELS+p+1;i=i+2){
            if(i>=NUMPIXELS+1){
              strip.setPixelColor(i-NUMPIXELS-1-1,OFF_B_8,OFF_G_8,OFF_R_8);
              strip.setPixelColor(i-NUMPIXELS-1,ON_B_8,ON_G_8,ON_R_8);
              delay(50); 
          }
          if(i<NUMPIXELS+1){
              strip.setPixelColor(i-1,OFF_B_8,OFF_G_8,OFF_R_8);
              strip.setPixelColor(i,ON_B_8,ON_G_8,ON_R_8);
              delay(50); 
          }
          delay(100);
          strip.show();
          } 
        }
        for (i=0;i<NUMPIXELS;i++){strip.setPixelColor(i,0,0,0); }
        strip.show(); 
  }
void leds_on9(){
        strip.begin();
        strip.clear();
        for(p=0;p<5;p++){
        strip.setBrightness(100);
          for (n=0;n<256;n++){
            for (i=0;i<NUMPIXELS+1;i=i+2){
              strip.setPixelColor(i-1,OFF_B_9*n/255,OFF_G_9*n/255,OFF_R_9*n/255);  
              strip.setPixelColor(i,ON_B_9*(255-n)/255,ON_G_9*(255-n)/255,ON_R_9*(255-n)/255);
            }
            strip.show();
            delay(1);
          }
          
          for (n=1;n<256;n++){    
            for (i=0;i<NUMPIXELS+1;i=i+2){
              strip.setPixelColor(i-1,OFF_B_9*(255-n)/255,OFF_G_9*(255-n)/255,OFF_R_9*(255-n)/255);
              strip.setPixelColor(i,ON_B_9*n/255,ON_G_9*n/255,ON_R_9*n/255);    
            }
            strip.show();
            delay(1);
          }
        }
        for (i=0;i<NUMPIXELS;i++){strip.setPixelColor(i,0,0,0); }
        strip.show(); 
  }
void leds_on_seq(){
        strip.begin();
        strip.clear();
        Serial.print("length_seq: ");Serial.println(length_seq);
        i=0;
        p=0;
        Bright_seq="";BrightSeq=Bright_seq.toInt();
        tmr_seq="";tmrSeq=tmr_seq.toInt();
        led_seq_n="";ledSeqn=led_seq_n.toInt();
        R_seq="";RSeq=R_seq.toInt();
        G_seq="";GSeq=G_seq.toInt();
        B_seq="";BSeq=B_seq.toInt();
        dly_seq="";dlySeq=dly_seq.toInt();
        
        do{
          
          do{
            i++;          
            if((char)mqtt_data[i]==':'){j_seq=i;flag_bright=1;}
            if((char)mqtt_data[i]==';'||(char)mqtt_data[i]=='['||(char)mqtt_data[i]==']'){i_seq=i;
              if(flag_bright==1){
                for(n=0;n<i_seq-j_seq-1;n++){Bright_seq+=(char)mqtt_data[n+j_seq+1];}BrightSeq=Bright_seq.toInt();//Serial.print("1: ");Serial.print(" Bright_seq ");Serial.println(BrightSeq);
              }
              flag_bright=0;}
          }while((char)mqtt_data[i]!=';'&&(char)mqtt_data[i]!='['&&(char)mqtt_data[i]!=']'&&i<length_seq);

          do{
            i++;
            
            if((char)mqtt_data[i]=='['){i_seq=i;i++;braq_seq=1;countb=1;Serial.print("**(char)mqtt_data[i]: ");Serial.print((char)mqtt_data[i-1]);Serial.print((char)mqtt_data[i]);Serial.println((char)mqtt_data[i+1]);}
            if((char)mqtt_data[i]==','||(char)mqtt_data[i]==';'||(char)mqtt_data[i]=='['||(char)mqtt_data[i]==']'||(char)mqtt_data[i]=='}'){j_seq=i;led_seq_n="";//Serial.print("2: start ");Serial.print(i_seq);Serial.print("_");Serial.println(j_seq);
              for(n=0;n<j_seq-i_seq-1;n++){led_seq_n+=(char)mqtt_data[n+i_seq+1];}ledSeqn=led_seq_n.toInt();Serial.print("2: ");Serial.print(" led_seq_n ");Serial.println(led_seq_n);
            }
          }while((char)mqtt_data[i]!=','&&(char)mqtt_data[i]!=';'&&(char)mqtt_data[i]!='['&&(char)mqtt_data[i]!=']'&&(char)mqtt_data[i]!='}'&&i<length_seq);
          
          //Serial.print("(char)mqtt_data[i]: ");Serial.print((char)mqtt_data[i-1]);Serial.print((char)mqtt_data[i]);Serial.println((char)mqtt_data[i+1]);
          
        
          if((char)mqtt_data[i]==']'){braq_seq=2;i++;Serial.print("braq_seq: ");Serial.println(braq_seq);}
          if((char)mqtt_data[i]!=';'&&(char)mqtt_data[i]!='['&&(char)mqtt_data[i]!=']'&&(char)mqtt_data[i]!='}'&&i<length_seq){          
            tmr_seq="";tmrSeq=tmr_seq.toInt();
            R_seq="";RSeq=R_seq.toInt();
            G_seq="";GSeq=G_seq.toInt();
            B_seq="";BSeq=B_seq.toInt();
            dly_seq="";dlySeq=dly_seq.toInt();
        
            do{
              i++;
              if((char)mqtt_data[i]=='('){i_seq=i;//Serial.println("3: start");Serial.print(j_seq);Serial.print("_");Serial.println(i_seq);
                for(n=0;n<i_seq-j_seq-1;n++){tmr_seq+=(char)mqtt_data[n+j_seq+1];}tmrSeq=tmr_seq.toInt();//Serial.print("3: ");Serial.print(" tmr_seq ");Serial.println(tmrSeq);
              }
            }while((char)mqtt_data[i]!='('&&i<length_seq);
            //strip.show();
  
            do{
              i++;
              if((char)mqtt_data[i]==','){j_seq=i;//Serial.println("4: start");Serial.print(i_seq);Serial.print("_");Serial.println(j_seq);
                for(n=0;n<j_seq-i_seq-1;n++){R_seq+=(char)mqtt_data[n+i_seq+1];}RSeq=R_seq.toInt();//Serial.print("4: ");Serial.print(" R_seq ");Serial.println(RSeq);
              }
            }while((char)mqtt_data[i]!=','&&i<length_seq);
 
            do{
              i++;
              if((char)mqtt_data[i]==','){i_seq=i;//Serial.println("5: start");Serial.print(j_seq);Serial.print("_");Serial.println(i_seq);
                for(n=0;n<i_seq-j_seq-1;n++){G_seq+=(char)mqtt_data[n+j_seq+1];}GSeq=G_seq.toInt();//Serial.print("5: ");Serial.print(" G_seq ");Serial.println(GSeq);
              }
            }while((char)mqtt_data[i]!=','&&i<length_seq);
        
            do{
              i++;
              if((char)mqtt_data[i]==')'){j_seq=i;//Serial.println("6: start");Serial.print(i_seq);Serial.print("_");Serial.println(j_seq);
                for(n=0;n<j_seq-i_seq-1;n++){B_seq+=(char)mqtt_data[n+i_seq+1];}BSeq=B_seq.toInt();//Serial.print("6: ");Serial.print(" B_seq ");Serial.println(BSeq);
              }
            }while((char)mqtt_data[i]!=')'&&i<length_seq);
        
            do{
              i++;
              if((char)mqtt_data[i]==';'||(char)mqtt_data[i]=='['||(char)mqtt_data[i]==']'||(char)mqtt_data[i]=='}'){i_seq=i;//Serial.println("7: start");Serial.print(j_seq);Serial.print("_");Serial.println(i_seq);
                for(n=0;n<i_seq-j_seq-1;n++){dly_seq+=(char)mqtt_data[n+j_seq+1];}dlySeq=dly_seq.toInt();//Serial.print("7: ");Serial.print(" dly_seq ");Serial.println(dly_seq);
              }          
            }while((char)mqtt_data[i]!=';'&&(char)mqtt_data[i]!='['&&(char)mqtt_data[i]!=']'&&(char)mqtt_data[i]!='}'&&i<length_seq);
          }
          
 /*       
            Serial.print("brightseq0: ");Serial.print(" ");Serial.println(brightseq0);  
            Serial.print("BrightSeq: ");Serial.print(" ");Serial.println(BrightSeq);
            */
            Serial.print("tmrSeq: ");Serial.print(" ");Serial.println(tmrSeq);
        
            Serial.print("ledSeqn: ");Serial.print(" ");Serial.println(ledSeqn);
            /*
            Serial.print("GSeq: ");Serial.print(" ");Serial.println(GSeq);
            Serial.print("RSeq: ");Serial.print(" ");Serial.println(RSeq);
            Serial.print("BSeq: ");Serial.print(" ");Serial.println(BSeq);
            Serial.print("dly_seq: ");Serial.print(" ");Serial.println(dly_seq);
*/
            if((char)mqtt_data[i]=='['){braq_seq=1;countb=1;}
            //if((char)mqtt_data[i]==']'){braq_seq=0;}
            if(tmrSeq>1){
              GSeq0=(strip.getPixelColor(ledSeqn) >> 16); Serial.print("strip.getPixelColor(ledSeqn): ");Serial.print(strip.getPixelColor(ledSeqn));
              RSeq0=(strip.getPixelColor(ledSeqn) >> 8);
              BSeq0=(strip.getPixelColor(ledSeqn)) ;  
              Serial.print("GSeq0: ");Serial.print(GSeq0);Serial.print(" ");Serial.print(RSeq0);Serial.print(" ");Serial.print(BSeq0);                        
              RSeqfd=RSeq-RSeq0;
              GSeqfd=GSeq-GSeq0;
              BSeqfd=BSeq-BSeq0;
              tmrSeqn=tmrSeq/2.4;  //porque stripshow() demora 1,4ms a processar

            if(braq_seq==1){
              count_braq[countb]=ledSeqn;Serial.print("countb: ");Serial.print(countb);Serial.print("count_braq[countb]: ");Serial.println(count_braq[countb]);
              countb++;
            }


            if(braq_seq==0){
              for(n=0;n<=tmrSeqn;n++){
                strip.setPixelColor(ledSeqn,GSeq0+n*GSeqfd/tmrSeqn,RSeq0+n*RSeqfd/tmrSeqn,BSeq0+n*BSeqfd/tmrSeqn);
                delay(1);//Serial.print("R: ");Serial.println(RSeq0+n*RSeqfd/tmrSeqn);
                strip.show();   //1,4 ms        
              }
            }
            if(braq_seq==2){Serial.print("BSeq0: ");Serial.print(BSeq0);Serial.print(" ");Serial.print(BSeq);Serial.print(" ");Serial.println(BSeqfd);
              count_braq[countb]=ledSeqn;
              for(e=0;e<=tmrSeqn;e++){//Serial.print("e: ");Serial.println(e);
                for(n=1;n<=countb;n++){//Serial.print(".");
                  strip.setPixelColor(count_braq[n],GSeq0+e*GSeqfd/tmrSeqn,RSeq0+e*RSeqfd/tmrSeqn,BSeq0+e*BSeqfd/tmrSeqn);
                }
                delay(1);
                strip.show();
              }
              braq_seq=0;
            }
          
          }else{strip.setPixelColor(ledSeqn,GSeq,RSeq,BSeq);}
          delay(dlySeq);

          j_seq=i_seq;
        
          p++;Serial.print("p: ");Serial.print(p);Serial.print(" ");Serial.print("i: ");Serial.println(i);
          if((char)mqtt_data[i]==';'){i=i-1;}
        
        }while(i<length_seq);

        
            //uint8_t LEDg =(strip.getPixelColor(1) >> 16);
            //uint8_t LEDr =(strip.getPixelColor(1) >> 8);
            //uint8_t LEDb =(strip.getPixelColor(1)) ;
            //strip.setPixelColor(2, LEDg, LEDr, LEDb);
            //uint8_t LEDbr =strip.getBrightness();//Serial.print("brigh ");Serial.print(LEDbr);


        
        //B,R,G
        //delay(1000);
        //strip.setPixelColor(5,255,0,0);
        //strip.show();
        delay(1000);
        for (i=0;i<NUMPIXELS;i++){strip.setPixelColor(i,000,000,000); }
        strip.show();
/*
        led_seq_n="";
        Bright_seq="";
        tmr_seq="";
        led_seq_n="";
        R_seq="";
        G_seq="";
        B_seq="";
        dly_seq="";
        */
        }
  
void leds_off(){
        clientStatus = 1;
        strip.begin();
        strip.clear();
        strip.show();
}
