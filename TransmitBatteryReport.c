/****** INCLUDES  *********/
#include "TransmitBatteryReport.h"
#include<stdlib.h>
#include<float.h>
#include<stdio.h>
#include<string.h>
#include<stdbool.h>

/*******MACROS***********/
#define TRUE        1
#define FALSE       0
/***** DEFINES***********/

/******VARIABLES***********/

char *FormatedOPData;

/***********FUNCTIONS*******/
void printOnConsole(char *Data)
{
  printf("%s",Data);
}

char* formatOutputData(float chargeRate,float SOC,float Temp)
{
  sprintf(FormatedOPData,"CR:",chargeRate,",SOC",SOC,",Temp:",Temp);
  return FormatedOPData;
}

float ReadBatteryCR()
{
  return 5.0;
}

float ReadBatterySOC()
{
  return 1;
}

static float ReadBatteryTemp()
{
  return 4.0;
}

bool SendBatteryStatus()
{
  float chargeRate = ReadBatteryCR();
  float SOC =  ReadBatterySOC();
  float Temp = ReadBatteryTemp();
  FormatedOPData = formatOutputData(chargeRate,SOC,Temp);
  printOnConsole(FormatedOPData);
  return TRUE;
}
