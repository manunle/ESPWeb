#include "Button.h"

void btncallback(int,int);
int getButtonStateCallback(int);
String btnstate[15];
Button* buttonList[15];

void BtnsInitialize()
{
    buttonList[0] = new Button("All","All",'1',"All");
    buttonList[1] = new Button("EDRelay","FirstEDRelay",'1',"House Left");
    buttonList[2] = new Button("EDRelay","FirstEDRelay",'2',"House Right");
    buttonList[3] = new Button("EDRelay","Tree",'1',"Tree 1");
    buttonList[4] = new Button("EDRelay","Tree",'2',"Tree 2");
    buttonList[5] = new Button("EDRelay","Woodshed",'1',"Front");
    buttonList[6] = new Button("EDRelay","Woodshed",'2',"Woodshed");
    buttonList[7] = new Button("dimmer","driveway",'1',"Driveway");
    buttonList[8] = new Button("devicetype","device5",'1',"label5-1");
    buttonList[9] = new Button("devicetype","device5",'2',"label5-2");
    buttonList[10] = new Button("devicetype","device6",'1',"label6-1");
    buttonList[11] = new Button("devicetype","device6",'2',"label6-2");
    buttonList[12] = new Button("devicetype","device7",'1',"label7-1");
    buttonList[13] = new Button("devicetype","device7",'2',"label7-2");
    buttonList[14] = new Button("devicetype","device8",'1',"label8-1");
}

void setBtnStatus(String type,String name,String num,String stat)
{
  char rlyNum;
  if(num == "1")
    rlyNum = '1';
  else
    rlyNum = '2';
  for(int i=0;i<15;i++)
  {
    if(buttonList[i]->deviceType == type && buttonList[i]->deviceName == name && buttonList[i]->relayNum == rlyNum)
    {
      Serial.println("Setting status " + stat + " on " + buttonList[i]->deviceName + " relay " + num);
      if(stat == "on")
        buttonList[i]->State = 1;
      if(stat == "off")
        buttonList[i]->State = 0;
    }
  }
}

String BuildCustomBtnsPage()
{
  String cstmbtns = "<meta name='viewport' content='width=device-width, initial-scale=1' />\n";
  cstmbtns = cstmbtns + "<meta http-equiv='Content-Type' content='text/html; charset=utf-8' />\n<a href='/'  class='btn btn--s'><</a>&nbsp;&nbsp;<strong>World Control</strong>\n<hr>\n<form action='' method='get'>\n<table border='0'  cellspacing='0' cellpadding='3'\n";
//Here is where I put my buttons
  for(int i=0;i<15;i++)
  {
    String sbtn = String(i);
    cstmbtns = cstmbtns + "<tr>";
    cstmbtns = cstmbtns + "<td align='center'><div id='btn" + sbtn + "on'><a href='javascript:Toggle(" + sbtn + ",1)' style='width:140px' class='btn btn--m btn--blue' id='btn" + sbtn + "' name='btn" + sbtn + "'>" + buttonList[i]->Label + " ON</a></div></td>";
    cstmbtns = cstmbtns + "<td align='center'><div id='btn" + sbtn + "off'><a href='javascript:Toggle(" + sbtn + ",0)' style='width:140px' class='btn btn--m btn--blue' id='btn" + sbtn + "' name='btn" + sbtn + "'>" + buttonList[i]->Label + " OFF</a></div></td>";
    cstmbtns = cstmbtns + "</tr>\n";
  }
////////////////////////////////////////
  cstmbtns = cstmbtns + "</table>\n</form>\n";
  cstmbtns = cstmbtns + "<script>\n\n";
  cstmbtns = cstmbtns + "function Toggle(i,state)\n";
  cstmbtns = cstmbtns + "{\n";
  cstmbtns = cstmbtns + "\tsetValues(\"/admin/toggle?btn=\" + i.toString() + \"&state=\" + state);\n";
  cstmbtns = cstmbtns + "}\n";
  cstmbtns = cstmbtns + "window.onload = function ()\n";
  cstmbtns = cstmbtns + "{\n";
  cstmbtns = cstmbtns + "\tload(\"style.css\",\"css\", function()\n";
  cstmbtns = cstmbtns + "\t{\n";
  cstmbtns = cstmbtns + "\t\tload(\"microajax.js\",\"js\", function()\n";
  cstmbtns = cstmbtns + "\t\t{\n";
  cstmbtns = cstmbtns + "\t\t\tsetValues(\"/admin/custombtns\");\n";
  cstmbtns = cstmbtns + "\t\t});\n";
  cstmbtns = cstmbtns + "\t});\n";
  cstmbtns = cstmbtns + "}\n";
  cstmbtns = cstmbtns + "function load(e,t,n){if(\"js\"==t){var a=document.createElement(\"script\");a.src=e,a.type=\"text/javascript\",a.async=!1,a.onload=function(){n()},document.getElementsByTagName(\"head\")[0].appendChild(a)}else if(\"css\"==t){var a=document.createElement(\"link\");a.href=e,a.rel=\"stylesheet\",a.type=\"text/css\",a.async=!1,a.onload=function(){n()},document.getElementsByTagName(\"head\")[0].appendChild(a)}}\n";
  cstmbtns = cstmbtns + "</script>\n";
  return cstmbtns;
}

void send_custombuttons_html()
{
//  if (server.args() > 0 )  // Save Settings
//  {
//    String temp = "";
//    for ( uint8_t i = 0; i < server.args(); i++ ) 
//    {
//    }
//  }
  String CustomBtns = BuildCustomBtnsPage();
  server.send ( 200, "text/html", CustomBtns.c_str() ); 
  Serial.println(__FUNCTION__); 
}

void setState()
{
  String values ="";
  for(int i=0;i<15;i++)
  {
    values += "btn";
    values += String(i);
    values += "|";
    if(buttonList[i]->State == 1)
      values += "1";
    else if(buttonList[i]->State == 0)
      values += "0";
    else
      values += "2";
    values += "|btn\n";
  }
  server.send ( 200, "text/plain", values);
  Serial.println(values);
  Serial.println(__FUNCTION__);
}

void send_custombuttons_values_html()
{
  setState();
  Serial.println(__FUNCTION__); 
}

void toggle()
{
  int btn = 0;
  int state = 0;
  if (server.args() > 0 )  
  {
    for ( uint8_t i = 0; i < server.args(); i++ ) 
    {
        Serial.println("arg " + String(i) + " = " + server.arg(i));
       if (server.argName(i) == "btn") btn = server.arg(i).toInt();
       if (server.argName(i) == "state") state = server.arg(i).toInt(); 
    }
  }
  if(btn == 0)
  {
    for(int idx = 1;idx < 15;idx++)
      if(buttonList[idx]->State != 2)
      {
        btncallback(idx,state);
      }
  }
  btncallback(btn,state);
  setState();
  Serial.println(__FUNCTION__); 
}

