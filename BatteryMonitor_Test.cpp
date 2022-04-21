#define CATCH_CONFIG_MAIN

#include "test/catch.hpp"
#include "TransmitBatteryReport.h"

#define TRUE        1
#define FALSE       0


TEST_CASE("Check TransmitBatteryStatus function positive result with both positive arguments")
{ 
  int TotalCounts =50;
  int TotalBatteries = 2;
  REQUIRE(TransmitBatteryStatus(TotalCounts,TotalBatteries) == TRUE);
}

TEST_CASE("Check TransmitBatteryStatus function negative result with invalid arguments")
{  
  int TotalCounts =0;
  int TotalBatteries = 0;
  REQUIRE(TransmitBatteryStatus(TotalCounts,TotalBatteries) == FALSE);
}

TEST_CASE("Check TransmitBatteryStatus function negative result with first invalid arguments")
{ 
  int TotalCounts =0;
  int TotalBatteries = 2;
  REQUIRE(TransmitBatteryStatus(TotalCounts,TotalBatteries) == FALSE);
}

TEST_CASE("Check TransmitBatteryStatus function negative result with second invalid argument")
{ 
  int TotalCounts =50;
  int TotalBatteries = 0;
  REQUIRE(TransmitBatteryStatus(TotalCounts,TotalBatteries) == FALSE);
}

TEST_CASE("Verify formatted CSV output data for battery 1 result")
{
  int Location=5;
  int BatterySNo=1;
  char FormatOPData[100];
  ReadBatteryStatus( Location, BatterySNo, FormatOPData);
  REQUIRE(strcmp(FormatOPData,"1,0.60,77,2") == 0);
}
