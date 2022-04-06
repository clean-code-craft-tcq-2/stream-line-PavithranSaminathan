#ifndef TransmitBatteryReport_h
#define TransmitBatteryReport_h

int TransmitBatteryStatus(int NoofReadings, int TotalNoOfBattery);
void ReadBatteryStatus(int Location,int BatteryPos,char* FormatOPData);

#endif
