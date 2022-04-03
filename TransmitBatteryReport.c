/****** INCLUDES  *********/
#include "TransmitBatteryReport.h"
#include<stdlib.h>
#include<float.h>
#include<stdio.h>
#include<string.h>
#include<stdbool.h>

/*******MACROS***********/

/***** DEFINES***********/

/******VARIABLES***********/

char *FormatedOPData;

FormatedOPData = malloc(sizeof(char));

/***********FUNCTIONS*******/
void printOnConsole(char *Data)
{
  printf("%s",Data);
}

char* formatOutputData(float chargeRate,float SOC,float Temp)
{
 FormatedOPData = '\0';
 strcat(FormatedOPData,chargeRate);
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
  return True;
}
