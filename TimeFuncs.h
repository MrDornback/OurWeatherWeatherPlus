
void printDigits(int digits) {
  // utility function for digital clock display: prints an leading 0

  if (digits < 10)
    Serial.print('0');
  Serial.print(digits);
}

void digitalClockDisplay() {
  // digital clock display of the time
  Serial.print(hour());
  printDigits(minute());
  printDigits(second());
  Serial.print(" ");
  Serial.print(day());
  Serial.print(" ");
  Serial.print(month());
  Serial.print(" ");
  Serial.print(year());
  Serial.println();
}


void return2Digits(char returnString[], char *buffer2, int digits)
{
  if (digits < 10)
    sprintf(returnString, "0%i", digits);
  else
    sprintf(returnString, "%i", digits);

  strcpy(returnString, buffer2);


}

void buildTimeString(char returnString[], char *buffer2, tmElements_t convertTime)
{



  char myBuffer[5];
  sprintf(myBuffer, "%i-", tmYearToCalendar(convertTime.Year));
  strcat(returnString, myBuffer);

  return2Digits(myBuffer, myBuffer, convertTime.Month);
  strcat(returnString, myBuffer);
  strcat(returnString, "-");

  return2Digits(myBuffer, myBuffer, convertTime.Day);
  strcat(returnString, myBuffer);
  strcat(returnString, " ");

  return2Digits(myBuffer, myBuffer, convertTime.Hour);
  strcat(returnString, myBuffer);
  strcat(returnString, ":");

  return2Digits(myBuffer, myBuffer, convertTime.Minute);
  strcat(returnString, myBuffer);
  strcat(returnString, ":");

  return2Digits(myBuffer, myBuffer, convertTime.Second);
  strcat(returnString, myBuffer);



}

#define countof(a) (sizeof(a) / sizeof(a[0]))

void printDateTime(const RtcDateTime& dt)
{
  char datestring[20];

  snprintf_P(datestring,
             countof(datestring),
             "%02u/%02u/%04u %02u:%02u:%02u",
             dt.Month(),
             dt.Day(),
             dt.Year(),
             dt.Hour(),
             dt.Minute(),
             dt.Second() );
  Serial.print(datestring);
}

String returnDateTime(const RtcDateTime& dt)
{
  char datestring[20];

  snprintf_P(datestring,
             countof(datestring),
             "%04u-%02u-%02u %02u:%02u:%02u",
             dt.Year(),
             dt.Month(),
             dt.Day(),
             dt.Hour(),
             dt.Minute(),
             dt.Second() );
  return String(datestring);
}
