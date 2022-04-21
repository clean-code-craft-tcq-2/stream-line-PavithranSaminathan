#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define NUMBER_OF_ELEMENTS 50
#define NUMBER_OF_BATTERY 2
#define NUMBER_OF_SAMPLES_FOR_AVERAGE 5

struct BatteryHealthParameters {
    float *ChargeRate;
    float *StateOfCharge;
    float *Temperature;
    float outputMinimumChargeRate;
    float outputMaximumChargeRate;
    float outputMinimumSOC;
    float outputMaximumSOC;
    float outputMinimumTemperature;
    float outputMaximumTemperature;
    float outputMovingAverageChargeRate;
    float outputMovingAverageTemperature;
    float outputMovingAverageSOC;
};

struct Battery {
    struct BatteryHealthParameters Battery[2];
};

void ReceiverSideImplementation(struct Battery *BatteryParameters);
