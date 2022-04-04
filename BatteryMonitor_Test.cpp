#define CATCH_CONFIG_MAIN

#include "test/catch.hpp"
#include "TransmitBatteryReport.h"

#define TRUE        1
#define FALSE       0


TEST_CASE("Check Battery status sending count")
{ 
  //int chargeRate = ReadBatteryCR();
  //int SOC =  ReadBatterySOC();
  //int Temp = ReadBatteryTemp();
  REQUIRE(SendBatteryStatus() == FALSE);
}

