/****** INCLUDES  *********/
#include<stdio.h>
#include<stdlib.h>
#include<float.h>
#include<string.h>
#include<stdbool.h>
#include "TransmitBatteryReport.h"
#include "BatteryCR_Cfg.h"


/*******MACROS***********/
#define TRUE        1
#define FALSE       0
/***** DEFINES***********/

/******VARIABLES***********/


/***********FUNCTIONS*******/
void printOnConsole(char *Data)
{
  printf("%s",Data);
}

float ReadBatteryCR(int location,int BatteryNo)
{
  return BAT_CR_Value[BatteryNo][location];
}

float ReadBatterySOC(int location,int BatteryNo)
{
  return 1;
}

static float ReadBatteryTemp(int location,int BatteryNo)
{
  return 4.0;
}

void ReadBatteryStatus(int Location,int BatteryPos,char* FormatOPData)
{
  float chargeRate = ReadBatteryCR(Location,BatteryPos);
  float SOC =  ReadBatterySOC(Location,BatteryPos);
  float Temp = ReadBatteryTemp(Location,BatteryPos);
  sprintf(FormatOPData,"B%dCR:%2f,,B%dSOC:%2f,B%dTemp:%2f",BatteryPos,chargeRate,BatteryPos,SOC,BatteryPos,Temp);  
}

int PrintBatteryStatus(int NoofReadings, int TotalNoOfBattery)
{
  char FormatedData[100];
  int batterycount;
  for(int index=0; NoofReadings > index;index++)
  {
    while(TotalNoOfBattery > batterycount)
    {
      ReadBatteryStatus(index,batterycount,FormatedData);
      printOnConsole(FormatedData);
      batterycount++;
    }
    batterycount=0;
  }
  return 50;
}

