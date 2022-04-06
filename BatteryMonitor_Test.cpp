#define CATCH_CONFIG_MAIN

#include "test/catch.hpp"
#include "TransmitBatteryReport.h"

#define TRUE        1
#define FALSE       0


TEST_CASE("Check TransmitBatteryStatus function")
{ 
  REQUIRE(TransmitBatteryStatus(50,2) == 50);
}

TEST_CASE("Verify formatted CSV output data for individual battery ")
{
  int Location=5;
  int BatterySNo=1;
  char FormatOPData[100];
  ReadBatteryStatus( Location, BatterySNo, FormatOPData);
  REQUIRE(strcmp(FormatOPData,"B:1,CR:0.60,SOC:77,Temp:2") == 0);
}
