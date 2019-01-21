#include <Arduino.h>

#include "ESPBASE.h"
#include "Button.h"

const byte mqttDebug = 1;
bool buttonState[10];
long lastReconnectAttempt = 0;
long lastupdate = 0;
String StatusTopic;
String StateTopic;
#define verstr "ESPWebApp 1.2"

ESPBASE Esp;

void setup() 
{
  Serial.begin(115200);
  Esp.initialize();
  StatusTopic = String(DEVICE_TYPE) + "/" + config.DeviceName + "/status";
  StateTopic = String(DEVICE_TYPE) + "/" + config.DeviceName + "/state";
  Esp.setupMQTTClient();
  for(int i=0;i<10;i++)
    buttonState[i] = false;
  customWatchdog = millis();
  if(Esp.WIFI_connected)
  {
    Serial.println("Done with MQTT Setup");
    customWatchdog = millis();
  }
  Serial.println("Done with setup");
}

void loop() 
{
  Esp.loop();
}

String getValue(String data, char separator, int index)
{
    int found = 0;
    int strIndex[] = { 0, -1 };
    int maxIndex = data.length() - 1;

    for (int i = 0; i <= maxIndex && found <= index; i++) {
        if (data.charAt(i) == separator || i == maxIndex) {
            found++;
            strIndex[0] = strIndex[1] + 1;
            strIndex[1] = (i == maxIndex) ? i+1 : i;
        }
    }
    return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}

void mqttCallback(char* topic, byte* payload, unsigned int length) 
{
  char c_payload[length];
  memcpy(c_payload, payload, length);
  c_payload[length] = '\0';
  
  String s_topic = String(topic);
  String s_payload = String(c_payload);
  String deviceType = getValue(s_topic,'/',0);
  String deviceName = getValue(s_topic,'/',1);
  String msgType = getValue(s_topic,'/',2);
  Serial.println("got " + deviceType + " " + deviceName + " " + msgType);
  if(msgType == "status")
  {
    String relay1 = getValue(s_payload,':',0);
    String relay2 = getValue(s_payload,':',1);
    String relayName = getValue(relay1,',',0);
    String relayNum = getValue(relay1,',',1);
    String relayStat = getValue(relay1,',',2);
    Serial.println("got " + relayName + " " + relayNum + " " + relayStat);
    setBtnStatus(deviceType,deviceName,relayNum,relayStat);
    relayName = getValue(relay2,',',0);
    relayNum = getValue(relay2,',',1);
    relayStat = getValue(relay2,',',2);
    Serial.println("got " + relayName + " " + relayNum + " " + relayStat);
    setBtnStatus(deviceType,deviceName,relayNum,relayStat);
  }
/*
Need to take this message:
Got message EDRelay/FirstEDRelay/status:HouseLeft,on:HouseRight,on
break it appart and set the status of the buttons
*/
  if (s_topic == StateTopic) 
  {
      if(s_payload.startsWith("Btn"))
      {
        Serial.print("Got Btn ");
        String btnno = s_payload.substring(3);
        Serial.println(btnno);
        int bt = atoi(btnno.c_str());
        Serial.println(bt);
//        if(p[0]=='T')
//        {
//          buttonState[bt] = true;
////          buttonState[9]=true; //unused button take this out when this button is used
//          buttonState[0]=true;
//          for(int i=1;i<10;i++)
//            if(!buttonState[i])
//              buttonState[0] = false;
//        }
//        else
//        {
//          buttonState[bt] = false;
//        }
////        setState();
//        Esp.mqttSend(config.BtnTopic,DeviceName,p);
      }
  }
  else 
  {
    if (mqttDebug) { Serial.println("Got message " + s_topic + ":" + s_payload); }
  }
}

void btncallback(int btn,int state)
{
  String Topic;
  String Message = "Unset";
  Topic = buttonList[btn]->deviceType + "/" + buttonList[btn]->deviceName + "/command";
  if(state == 1)
    Message = "ON_" + String(buttonList[btn]->relayNum);
  else
    Message = "OFF_" + String(buttonList[btn]->relayNum);
  if(btn==7)
  { 
    if(state == 1)
    {
      Esp.mqttSend("lights/state","","ON");
      Esp.mqttSend("lights/brightness","","255");
    }
    if(state == 0)
    {
      Esp.mqttSend("lights/brightness","","0");
    }
  }
  else
    Esp.mqttSend(Topic,Message);
  unsigned long tm = millis();
  while(tm+5000 > millis() and buttonList[btn]->State != state)
  {
    Esp.mqttClient->loop();
    yield();
  }
  Serial.println("Got my callback!!");
}

int getButtonStateCallback(int btn)
{
  return buttonList[btn]->State;  
}

void mqttSubscribe()
{
    if (Esp.mqttClient->connected()) 
    {
      if (Esp.mqttClient->subscribe(StateTopic.c_str())) 
      {
        Esp.mqttClient->subscribe("EDRelay/#");
        Serial.println("Subscribed to EDRelay/#");
        Esp.mqttSend(StatusTopic,"Subscribed to ",StateTopic);
        Esp.mqttSend(StatusTopic,verstr,","+Esp.MyIP() + " start");
      }
    }
}
