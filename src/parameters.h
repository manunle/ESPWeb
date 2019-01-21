#ifndef PARAMETERS_H
#define PARAMETERS_H
#define CFGVER "W1.4"

struct strConfig {
  boolean dhcp;                         // 1 Byte - EEPROM 16
  boolean free1;                        // 1 Byte - EEPROM 17
  byte  IP[4];                          // 4 Byte - EEPROM 18
  byte  Netmask[4];                     // 4 Byte - EEPROM 22
  byte  Gateway[4];                     // 4 Byte - EEPROM 26
  String ssid;                          // up to 16 Byte - EEPROM 30
  String password;                      // up to 16 Byte - EEPROM 46
  String DeviceName;                    // up to 16 Byte - EEPROM 62
  String OTApwd;                         // up to 16 Byte - EEPROM 78
  String MQTTServer;                    // up to 16 Byte - EEPROM 94
  long MQTTPort;                        // 4 Byte - EEPROM 110
//  String StatusTopic;                   // up to 16 Byte - EEPROM 126
//  String HeartbeatTopic;                // up to 16 Byte - EEPROM 142
  long HeartbeatEvery;                  // 4 Byte - EEPROM 156
  String BtnTopic;                      // 16 byte - EEPROM 172
  String BtnLabel[10];                  // 100 byte - EEPROM 188
  String BtnOnMsg[10];                  // 100 byte - EEPROM 288
  String BtnOffMsg[10];                 // 100 byte - EEPROM 388
  // Application Settings here... from EEPROM 488 up to 511 (0 - 511)

} config;



#ifdef ARDUINO_ESP32_DEV

  #include <Preferences.h>

  Preferences EEPROM;

  void WriteConfig(){

    Serial.println("Writing Config");
    EEPROM.putString("head", CFGVER);


    EEPROM.putUChar("dhcp", config.dhcp);
    EEPROM.putUChar("isDayLight", config.isDayLightSaving);

    EEPROM.putULong("NTPrate", config.Update_Time_Via_NTP_Every); // 4 Byte
    EEPROM.putULong("timeZone", config.timeZone); // 4 Byte

    EEPROM.putUChar("ip0", config.IP[0]);
    EEPROM.putUChar("ip1", config.IP[1]);
    EEPROM.putUChar("ip2", config.IP[2]);
    EEPROM.putUChar("ip3", config.IP[3]);

    EEPROM.putUChar("nm0", config.Netmask[0]);
    EEPROM.putUChar("nm1", config.Netmask[1]);
    EEPROM.putUChar("nm2", config.Netmask[2]);
    EEPROM.putUChar("nm3", config.Netmask[3]);

    EEPROM.putUChar("gw0", config.Gateway[0]);
    EEPROM.putUChar("gw1", config.Gateway[1]);
    EEPROM.putUChar("gw2", config.Gateway[2]);
    EEPROM.putUChar("gw3", config.Gateway[3]);

    EEPROM.putString("ssid", config.ssid);
    EEPROM.putString("pwd", config.password);
    EEPROM.putString("ntpSN", config.ntpServerName);
    EEPROM.putString("DevN", config.DeviceName);
    EEPROM.putString("OTApwd", config.OTApwd);
    EEPROM.putString("MQTTServer",config.MQTTServer);
    EEPROM.putULong("MQTTPort",config.MQTTPort);
    EEPROM.putString("Btn1Topic",config.Btn1Topic);
    EEPROM.putString("Btn1Message",config.Btn1Message);
    EEPROM.putString("StatusTopic",config.StatusTopic);
    EEPROM.putString("HeartbeatTopic",config.HeartbeatTopic);
    EEPROM.putULong("HeartbeatEvery",config.HeartbeatEvery);
  }
  boolean ReadConfig(){
    Serial.println("Reading Configuration");
    if (EEPROM.getString("head") == CFGVER )
    {
      Serial.println("Configurarion Found!" + CFGVER);
      config.dhcp = EEPROM.getUChar("dhcp",0);
      config.isDayLightSaving = EEPROM.getUChar("isDayLight");
      config.Update_Time_Via_NTP_Every = EEPROM.getULong("NTPrate"); // 4 Byte
      config.timeZone = EEPROM.getULong("timeZone"); // 4 Byte
      config.IP[0] = EEPROM.getUChar("ip0");
      config.IP[1] = EEPROM.getUChar("ip1");
      config.IP[2] = EEPROM.getUChar("ip2");
      config.IP[3] = EEPROM.getUChar("ip3");
      config.Netmask[0] = EEPROM.getUChar("nm0");
      config.Netmask[1] = EEPROM.getUChar("nm1");
      config.Netmask[2] = EEPROM.getUChar("nm2");
      config.Netmask[3] = EEPROM.getUChar("nm3");
      config.Gateway[0] = EEPROM.getUChar("gw0");
      config.Gateway[1] = EEPROM.getUChar("gw1");
      config.Gateway[2] = EEPROM.getUChar("gw2");
      config.Gateway[3] = EEPROM.getUChar("gw3");
      config.ssid = EEPROM.getString("ssid");
      config.password = EEPROM.getString("pwd");
      config.ntpServerName = EEPROM.getString("ntpSN");
      config.DeviceName = EEPROM.getString("DevN");
      config.OTApwd = EEPROM.getString("OTApwd");
      config.MQTTServer = EEPROM.getString("MQTTServer");
      config.MQTTPort = EEPROM.getULong("MQTTPort");
      config.Btn1Topic = EEPROM.getString("Btn1Topic");
      config.Btn1Message = EEPROM.GetString("Btn1Message");
      config.StatusTopic = EEPROM.GetString("StatusTopic");
      config.HeartbeatTopic = EEPROM.GetString("HeartbeatTopic");
      config.HeartbeatEvery = EEPROM.GetULong("HeartbeatEvery");
      // Application parameters here ... from EEPROM 356 to 511

      return true;

    }
    else
    {
      Serial.println("Configurarion NOT FOUND!!!!");
      return false;
    }
  }



#elif ARDUINO_ESP8266_ESP01 || ARDUINO_ESP8266_NODEMCU
  //  Auxiliar function to handle EEPROM
  // EEPROM-parameters

  void EEPROMWritelong(int address, long value){
    byte four = (value & 0xFF);
    byte three = ((value >> 8) & 0xFF);
    byte two = ((value >> 16) & 0xFF);
    byte one = ((value >> 24) & 0xFF);

    //Write the 4 bytes into the eeprom memory.
    EEPROM.write(address, four);
    EEPROM.write(address + 1, three);
    EEPROM.write(address + 2, two);
    EEPROM.write(address + 3, one);
  }

  long EEPROMReadlong(long address){
    //Read the 4 bytes from the eeprom memory.
    long four = EEPROM.read(address);
    long three = EEPROM.read(address + 1);
    long two = EEPROM.read(address + 2);
    long one = EEPROM.read(address + 3);

    //Return the recomposed long by using bitshift.
    return ((four << 0) & 0xFF) + ((three << 8) & 0xFFFF) + ((two << 16) & 0xFFFFFF) + ((one << 24) & 0xFFFFFFFF);
  }

  void WriteStringToEEPROM(int beginaddress, String string){
    char  charBuf[string.length() + 1];
    string.toCharArray(charBuf, string.length() + 1);
    for (unsigned int t =  0; t < sizeof(charBuf); t++)
    {
      EEPROM.write(beginaddress + t, charBuf[t]);
    }
  }

  String  ReadStringFromEEPROM(int beginaddress){
    volatile byte counter = 0;
    char rChar;
    String retString = "";
    while (1)
    {
      rChar = EEPROM.read(beginaddress + counter);
      if (rChar == 0) break;
      if (counter > 31) break;
      counter++;
      retString.concat(rChar);

    }
    return retString;
  }

  void WriteConfig(){
    String cfgver = CFGVER;
    char ccfgver[5];
    cfgver.toCharArray(ccfgver,5);

    Serial.print("Writing Config ");
    Serial.println(ccfgver);
    EEPROM.write(0, ccfgver[0]);
    EEPROM.write(1, ccfgver[1]);
    EEPROM.write(2, ccfgver[2]);
    EEPROM.write(3, ccfgver[3]);

    EEPROM.write(16, config.dhcp);
    EEPROM.write(18, config.IP[0]);
    EEPROM.write(19, config.IP[1]);
    EEPROM.write(20, config.IP[2]);
    EEPROM.write(21, config.IP[3]);
    EEPROM.write(22, config.Netmask[0]);
    EEPROM.write(23, config.Netmask[1]);
    EEPROM.write(24, config.Netmask[2]);
    EEPROM.write(25, config.Netmask[3]);
    EEPROM.write(26, config.Gateway[0]);
    EEPROM.write(27, config.Gateway[1]);
    EEPROM.write(28, config.Gateway[2]);
    EEPROM.write(29, config.Gateway[3]);
    WriteStringToEEPROM(30, config.ssid);
    WriteStringToEEPROM(46, config.password);
    WriteStringToEEPROM(62, config.DeviceName);
    WriteStringToEEPROM(78, config.OTApwd);
    WriteStringToEEPROM(94, config.MQTTServer);
    EEPROMWritelong(110, config.MQTTPort);
    EEPROMWritelong(156, config.HeartbeatEvery);
    WriteStringToEEPROM(172, config.BtnTopic);
    int pos = 188;
    for(int i=0;i<10;i++)
    {
      WriteStringToEEPROM(pos,config.BtnLabel[i]);
      pos = pos + 10;
      WriteStringToEEPROM(pos,config.BtnOnMsg[i]);
      pos = pos + 10;
      WriteStringToEEPROM(pos,config.BtnOffMsg[i]);
      pos = pos + 10;
    }
      // Application Settings here... from EEPROM 392 up to 511 (0 - 511)

    EEPROM.commit();

  }

  boolean ReadConfig(){
    Serial.println("Reading Configuration");
    String cfgver = CFGVER;
    char ccfgver[5];
    cfgver.toCharArray(ccfgver,5);
    if (EEPROM.read(0) == cfgver[0] && EEPROM.read(1) == cfgver[1]  && EEPROM.read(2) == cfgver[2] && EEPROM.read(3) == cfgver[3])
    {
      Serial.println("Configurarion Found!");
      config.dhcp =   EEPROM.read(16);
      config.IP[0] = EEPROM.read(18);
      config.IP[1] = EEPROM.read(19);
      config.IP[2] = EEPROM.read(20);
      config.IP[3] = EEPROM.read(21);
      config.Netmask[0] = EEPROM.read(22);
      config.Netmask[1] = EEPROM.read(23);
      config.Netmask[2] = EEPROM.read(24);
      config.Netmask[3] = EEPROM.read(25);
      config.Gateway[0] = EEPROM.read(26);
      config.Gateway[1] = EEPROM.read(27);
      config.Gateway[2] = EEPROM.read(28);
      config.Gateway[3] = EEPROM.read(29);
      config.ssid = ReadStringFromEEPROM(30);
      config.password = ReadStringFromEEPROM(46);
      config.DeviceName = ReadStringFromEEPROM(62);
      config.OTApwd = ReadStringFromEEPROM(78);
      config.MQTTServer = ReadStringFromEEPROM(94);
      config.MQTTPort = EEPROMReadlong(110);
      config.HeartbeatEvery = EEPROMReadlong(156);
      config.BtnTopic = ReadStringFromEEPROM(172);
      int pos = 188;
      for(int i=0;i<10;i++)
      {
        config.BtnLabel[i] = ReadStringFromEEPROM(pos);
        pos = pos + 10;
        config.BtnOnMsg[i] = ReadStringFromEEPROM(pos);
        pos = pos + 10;
        config.BtnOffMsg[i] = ReadStringFromEEPROM(pos);
        pos = pos + 10;
    }
      // Application parameters here ... from EEPROM 392 to 511

      return true;

    }
    else
    {
      Serial.println("Configurarion NOT FOUND!!!!");
      return false;
    }
  }


#endif  // ESP8266

void printConfig(){

  Serial.println("Printing Config");

  Serial.printf("DHCP:%d\n", config.dhcp);
  Serial.printf("IP:%d.%d.%d.%d\n", config.IP[0],config.IP[1],config.IP[2],config.IP[3]);
  Serial.printf("Mask:%d.%d.%d.%d\n", config.Netmask[0],config.Netmask[1],config.Netmask[2],config.Netmask[3]);
  Serial.printf("Gateway:%d.%d.%d.%d\n", config.Gateway[0],config.Gateway[1],config.Gateway[2],config.Gateway[3]);
  Serial.printf("SSID:%s\n", config.ssid.c_str());
  Serial.printf("PWD:%s\n", config.password.c_str());
  Serial.printf("Device Name:%s\n", config.DeviceName.c_str());
  Serial.printf("OTA password:%s\n", config.OTApwd.c_str());
  Serial.printf("MQTT Server:%s\n", config.MQTTServer.c_str());
  Serial.printf("MQTT Port:%ld\n", config.MQTTPort);
  Serial.printf("Heartbeat Every %ld seconds",config.HeartbeatEvery);
    // Application Settings here... from EEPROM 356 up to 511 (0 - 511)

}

String formatConfig(){
  String outstring = "";
  outstring = outstring + "DHCP:"+String(config.dhcp) + "|";
  outstring = outstring + "IP:" + String(config.IP[0]) + "." + String(config.IP[1]) + "." + String(config.IP[2]) + "." + String(config.IP[3]) + "|";
  outstring = outstring + "Mask:" + String(config.Netmask[0]) + "." + String(config.Netmask[1]) + "." + String(config.Netmask[2]) + "." + String(config.Netmask[3]) + "|";
  outstring = outstring + "Gateway:" + String(config.Gateway[0]) + "." + String(config.Gateway[1]) + "." + String(config.Gateway[2]) + "." + String(config.Gateway[3]) + "|";
  outstring = outstring + "SSID:" + config.ssid + "|";
  outstring = outstring + "PWD:" + config.password + "|";
  outstring = outstring + "Device Name:" + config.DeviceName + "|";
  outstring = outstring + "OTA password" + config.OTApwd + "|";
  outstring = outstring + "MQTT Server:" + config.MQTTServer + "|";
  outstring = outstring + "MQTT Port:" + String(config.MQTTPort) + "|";
  outstring = outstring + "Heartbeat every " + String(config.HeartbeatEvery);
  return outstring;
}

void configLoadDefaults(uint16_t ChipId){

  #ifdef ARDUINO_ESP32_DEV
    config.ssid = "ESP32-" + String(ChipId,HEX);       // SSID of access point
  #elif ARDUINO_ESP8266_ESP01 || ARDUINO_ESP8266_NODEMCU
    config.ssid = "ESP8266-" + String(ChipId,HEX);       // SSID of access point
  #endif
  config.password = "" ;   // password of access point
  config.dhcp = true;
  config.IP[0] = 192; config.IP[1] = 168; config.IP[2] = 1; config.IP[3] = 100;
  config.Netmask[0] = 255; config.Netmask[1] = 255; config.Netmask[2] = 255; config.Netmask[3] = 0;
  config.Gateway[0] = 192; config.Gateway[1] = 168; config.Gateway[2] = 1; config.Gateway[3] = 254;
  config.DeviceName = "Not Named";
  config.OTApwd = "";
  config.MQTTServer = "";
  config.MQTTPort = 0;
  config.HeartbeatEvery = 0;
  config.BtnTopic = "test/btns";
  for(int i=0;i<10;i++)
  {
    config.BtnLabel[i] = "btn" + String(i+1); 
    config.BtnOnMsg[i] = "btnon" + String(i+1); 
    config.BtnOffMsg[i] = "btnoff" + String(i+1); 
  }
  return;
}


#endif
