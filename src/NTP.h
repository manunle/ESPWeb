
/*
**
**  NTP
**
*/

#ifndef NTP_H
#define NTP_H

static const uint8_t monthDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
#define LEAP_YEAR(Y) ( ((1970+Y)>0) && !((1970+Y)%4) && ( ((1970+Y)%100) || !((1970+Y)%400) ) )

WiFiUDP UDPNTPClient;											// NTP Client

struct  strDateTime{
  byte hour;
  byte minute;
  byte second;
  int year;
  byte month;
  byte day;
  byte wday;
  unsigned long NTPtime;
} ;

strDateTime DateTime;                      // Global DateTime structure, will be refreshed every Second
const int NTP_PACKET_SIZE = 48;
byte packetBuffer[ NTP_PACKET_SIZE];


strDateTime ConvertUnixTimeStamp( unsigned long _tempTimeStamp) {
  strDateTime _tempDateTime;
  uint8_t year;
  uint8_t month, monthLength;
  uint32_t time;
  unsigned long days;

  time = (uint32_t)_tempTimeStamp;
  _tempDateTime.second = time % 60;
  time /= 60; // now it is minutes
  _tempDateTime.minute = time % 60;
  time /= 60; // now it is hours
  _tempDateTime.hour = time % 24;
  time /= 24; // now it is days
  _tempDateTime.wday = ((time + 4) % 7) + 1;  // Sunday is day 1

  year = 0;
  days = 0;
  while ((unsigned)(days += (LEAP_YEAR(year) ? 366 : 365)) <= time) {
    year++;
  }
  _tempDateTime.year = year; // year is offset from 1970

  days -= LEAP_YEAR(year) ? 366 : 365;
  time  -= days; // now it is days in this year, starting at 0

  days = 0;
  month = 0;
  monthLength = 0;
  for (month = 0; month < 12; month++) {
    if (month == 1) { // february
      if (LEAP_YEAR(year)) {
        monthLength = 29;
      } else {
        monthLength = 28;
      }
    } else {
      monthLength = monthDays[month];
    }

    if (time >= monthLength) {
      time -= monthLength;
    } else {
      break;
    }
  }
  _tempDateTime.month = month + 1;  // jan is month 1
  _tempDateTime.day = time + 1;     // day of month
  _tempDateTime.year += 1970;

  return _tempDateTime;
}

//
// Summertime calculates the daylight saving time for middle Europe. Input: Unixtime in UTC
//
//boolean summerTime(unsigned long _timeStamp ) {
//  strDateTime  _tempDateTime = ConvertUnixTimeStamp(_timeStamp);
//  // printTime("Innerhalb ", _tempDateTime);
//
//  if (_tempDateTime.month < 3 || _tempDateTime.month > 10) return false; // keine Sommerzeit in Jan, Feb, Nov, Dez
//  if (_tempDateTime.month > 3 && _tempDateTime.month < 10) return true; // Sommerzeit in Apr, Mai, Jun, Jul, Aug, Sep
//  if (_tempDateTime.month == 3 && (_tempDateTime.hour + 24 * _tempDateTime.day) >= (3 +  24 * (31 - (5 * _tempDateTime.year / 4 + 4) % 7)) || _tempDateTime.month == 10 && (_tempDateTime.hour + 24 * _tempDateTime.day) < (3 +  24 * (31 - (5 * _tempDateTime.year / 4 + 1) % 7)))
//    return true;
//  else
//    return false;
//}

void ISRsecondTick(){
//  strDateTime _tempDateTime;
  AdminTimeOutCounter++;
  cNTP_Update++;
  cHeartbeat++;
  UnixTimestamp++;
  DateTime = ConvertUnixTimeStamp(absoluteActualTime);  //  convert to DateTime format
  actualTime = 3600 * DateTime.hour + 60 * DateTime.minute + DateTime.second;
  if (millis() - customWatchdog > 30000){
    Serial.println("CustomWatchdog bites. Bye");
      //ESP.reset();
      ESP.restart();
  }
}

#endif
