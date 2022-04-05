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

//char *FormatedOPData;

/***********FUNCTIONS*******/
void printOnConsole(char *Data)
{
  printf("%s",Data);
}

/*
char* formatOutputData(float chargeRate,float SOC,float Temp)
{
   return FormatedOPData;
}
*/

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
char* ReadBatteryStatus(int Location)
{
  char FormatedOPData[100];
  float chargeRate = ReadBatteryCR(Location);
  float SOC =  ReadBatterySOC(Location);
  float Temp = ReadBatteryTemp(Location);
  sprintf(FormatedOPData,"CR:%f,,SOC:%f,Temp:%f",chargeRate,SOC,Temp);
  return FormatedOPData;
}

int PrintBatteryStatus(int NoofReadings)
{
  int FormatedData[100];
  for(int index; NoofReadings > index;index)
  {
    FormatedData=ReadBatteryStatus(index);
    printOnConsole(FormatedOPData);
  }  
  return index;
}

