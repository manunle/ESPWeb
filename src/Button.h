#ifndef BUTTON_H
#define BUTTON_H

#define B_ON 1
#define B_OFF 0
#define B_UNKNOWN 2

class Button
{
  public:
    String deviceType;
    String deviceName;
    char relayNum;
    String Label;
    int State;
    Button(String,String,char,String);
};

Button::Button(String devType,String devName,char num,String lbl)
{
  deviceType=devType;
  deviceName=devName;
  relayNum=num;
  Label=lbl;
  State = B_UNKNOWN; 
}

#endif
