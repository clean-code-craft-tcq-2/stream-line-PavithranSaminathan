#define CATCH_CONFIG_MAIN

#include "test/catch.hpp"
#include "TransmitBatteryReport.h"

#define TRUE        1
#define FALSE       0


TEST_CASE("Check Battery status sending count")
{ 
PrintBatteryStatus(50,2);
}

TEST_CASE("Verify formatted output data for individual battery")
{
  int Location=6;
  int BatteryPos=1;
  char* FormatOPData;
  ReadBatteryStatus( Location, BatteryPos, FormatOPData);
  REQUIRE(strcmp(FormatOPData,"B1CR:0.600000,,B1SOC:77,B1Temp:2") == 0);
}
