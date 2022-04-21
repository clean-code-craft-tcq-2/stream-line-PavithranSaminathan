#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "Receive_And_Compute_Statistics.h"
#include "../test/catch.hpp"

TEST_CASE("Tests to verify the calculate statistics") {
	struct Battery BatteryParameters;
	ReceiverSideImplementation(&BatteryParameters);
	
	float ExpectedChargeRate[][3] = {{0.60,1.10,0.8},{0.00,1.20,0.94}};
	float ExpectedTemperature[][3] = {{5.00,45.00,15.80},{0.00,45.00,35.40}};
	float ExpectedSOC[][3] = {{20.00,45.00,15.80},{21.00,80.00,51.00}};
		
	for(int i=0; i<NUMBER_OF_BATTERY; i++)
	{
		REQUIRE(BatteryParameters.Battery[i].outputMinimumChargeRate == ExpectedChargeRate[i][0]);
		REQUIRE(BatteryParameters.Battery[i].outputMaximumChargeRate == ExpectedChargeRate[i][1]);
		REQUIRE(BatteryParameters->Battery[i].outputMovingAverageChargeRate == ExpectedChargeRate[i][2]);
    		REQUIRE(BatteryParameters.Battery[i].outputMinimumTemperature == ExpectedTemperature[i][0]);
    		REQUIRE(BatteryParameters.Battery[i].outputMaximumTemperature == ExpectedTemperature[i][1]);
		REQUIRE(BatteryParameters->Battery[i].outputMovingAverageTemperature == ExpectedTemperature[i][2]);
    		REQUIRE(BatteryParametersBattery[i].outputMinimumSOC == ExpectedSOC[i][0]);
    		REQUIRE(BatteryParameters->Battery[i].outputMaximumSOC == ExpectedSOC[i][1]);
		REQUIRE(BatteryParameters->Battery[i].outputMovingAverageSOC == ExpectedSOC[i][0]);
	}	
}
