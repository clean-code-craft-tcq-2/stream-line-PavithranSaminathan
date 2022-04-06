#ifndef TransmitBatteryReport_h
#define TransmitBatteryReport_h

#include<stdbool.h>

bool TransmitBatteryStatus(int NoofReadings, int TotalNoOfBattery);
void ReadBatteryStatus(int Location,int BatteryPos,char* FormatOPData);

#endif
