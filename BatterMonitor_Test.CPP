#define CATCH_CONFIG_MAIN

#include "test/catch.hpp"
#include "Batter_Monitor_Sender.h"


TEST_F("Check Battery status sending count")
{ 
  //int chargeRate = ReadBatteryCR();
  //int SOC =  ReadBatterySOC();
  //int Temp = ReadBatteryTemp();
  SendBatteryStatus(Temp,SOC,ChargeRate);
}
