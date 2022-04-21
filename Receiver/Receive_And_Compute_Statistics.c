#include "Receive_And_Compute_Statistics.h"

float findMinimumValueInGivenArray(float *InputArray, size_t numberOfElements) {
    size_t loopCounter = 0;
    float minimumValue = InputArray[loopCounter];
    for(loopCounter=0; loopCounter<numberOfElements; loopCounter++) {
        if(minimumValue > InputArray[loopCounter])
            minimumValue = InputArray[loopCounter];
    }
    return minimumValue;
}

float findMaximumValueInGivenArray(float *InputArray, size_t numberOfElements) {
    size_t loopCounter = 0;
    float maximumValue = InputArray[loopCounter];
    for(loopCounter=0; loopCounter<numberOfElements; loopCounter++) {
        if(maximumValue < InputArray[loopCounter])
            maximumValue = InputArray[loopCounter];
    }
    return maximumValue;
}

bool checkIfRequiredNumberOfSamplesAreAvailable(size_t numberOfElements, size_t numberOfSamplesForAvg) {
    if(numberOfElements < numberOfSamplesForAvg)
        return false;
    else   
        return true;
}

float findMovingAverageForGivenValues(float *InputArray, size_t numberOfElements, size_t numberOfSamplesForAvg) {
    float sumOfSamples = 0.0, movingAverage = 0.0;
    size_t loopCounter = numberOfElements-numberOfSamplesForAvg;
    if(checkIfRequiredNumberOfSamplesAreAvailable(numberOfElements, numberOfSamplesForAvg))
    {
        for(;loopCounter<numberOfElements;loopCounter++) {
            sumOfSamples += InputArray[loopCounter]; 
        }
        movingAverage = (float) (sumOfSamples/numberOfSamplesForAvg);
    }
    return movingAverage;
}

void computeStatitics(struct Battery *BatteryParameters, size_t numberOfElements, size_t numberOfBatteries, size_t numberOfSamplesForAvg) {
    size_t i=0;
    for(i=0; i<numberOfBatteries; i++) {
        BatteryParameters->Battery[i].outputMinimumChargeRate = findMinimumValueInGivenArray(BatteryParameters->Battery[i].ChargeRate,numberOfElements);
        BatteryParameters->Battery[i].outputMaximumChargeRate = findMaximumValueInGivenArray(BatteryParameters->Battery[i].ChargeRate,numberOfElements);
        BatteryParameters->Battery[i].outputMinimumTemperature = findMinimumValueInGivenArray(BatteryParameters->Battery[i].Temperature,numberOfElements);
        BatteryParameters->Battery[i].outputMaximumTemperature = findMaximumValueInGivenArray(BatteryParameters->Battery[i].Temperature,numberOfElements);
        BatteryParameters->Battery[i].outputMinimumSOC = findMinimumValueInGivenArray(BatteryParameters->Battery[i].StateOfCharge,numberOfElements);
        BatteryParameters->Battery[i].outputMaximumSOC = findMaximumValueInGivenArray(BatteryParameters->Battery[i].StateOfCharge,numberOfElements);
        BatteryParameters->Battery[i].outputMovingAverageChargeRate = findMovingAverageForGivenValues(BatteryParameters->Battery[i].ChargeRate,numberOfElements,numberOfSamplesForAvg);
        BatteryParameters->Battery[i].outputMovingAverageTemperature = findMovingAverageForGivenValues(BatteryParameters->Battery[i].Temperature,numberOfElements,numberOfSamplesForAvg);
        BatteryParameters->Battery[i].outputMovingAverageSOC = findMovingAverageForGivenValues(BatteryParameters->Battery[i].StateOfCharge,numberOfElements,numberOfSamplesForAvg);
    }
}

void AllocateMemoryToSaveInput(struct Battery *BatteryParameters) {
    int loopCount;
    for(loopCount=0; loopCount<NUMBER_OF_BATTERY; loopCount++) {
        BatteryParameters->Battery[loopCount].ChargeRate = (float*)calloc(NUMBER_OF_ELEMENTS,sizeof(float));
        BatteryParameters->Battery[loopCount].StateOfCharge = (float*)calloc(NUMBER_OF_ELEMENTS,sizeof(float));
        BatteryParameters->Battery[loopCount].Temperature = (float*)calloc(NUMBER_OF_ELEMENTS,sizeof(float));
    }
}

void freeAllocatedMemory(struct Battery *BatteryParameters) {
    int loopCount;
    for(loopCount=0; loopCount<NUMBER_OF_BATTERY; loopCount++) {
        free(BatteryParameters->Battery[loopCount].ChargeRate);
        free(BatteryParameters->Battery[loopCount].StateOfCharge);
        free(BatteryParameters->Battery[loopCount].Temperature);
    }
}

void ReadBatteryParametersfromConsole(struct Battery *BatteryParameters, size_t numberOfSamples) {
    int innerLoopCount,outerLoopCount,BatteryNumber;
    char stringToSaveHeadings[20];

    scanf("%s",stringToSaveHeadings);
    for(outerLoopCount=0; outerLoopCount<numberOfSamples; outerLoopCount++)
    {
        for(innerLoopCount=0; innerLoopCount<2; innerLoopCount++)
        {
            scanf("%d,",&BatteryNumber);
            scanf("%f,",&BatteryParameters->Battery[BatteryNumber].ChargeRate[outerLoopCount]);
            scanf("%f,",&BatteryParameters->Battery[BatteryNumber].StateOfCharge[outerLoopCount]);
            scanf("%f ",&BatteryParameters->Battery[BatteryNumber].Temperature[outerLoopCount]);
        }
    }
}

void formatAndPrintStatisticsToConsole(struct Battery *BatteryParameters) {
    size_t loopCounter;
    for(loopCounter=0; loopCounter<2; loopCounter++) {
        printf("\n********** Battery %lu Parameters **********",loopCounter);
        printf("\nCharge Rate Statistics:\n");
        printf("Minimum: %.2f\n",BatteryParameters->Battery[loopCounter].outputMinimumChargeRate);
        printf("Maximum: %.2f\n",BatteryParameters->Battery[loopCounter].outputMaximumChargeRate);
        printf("Average: %.2f\n",BatteryParameters->Battery[loopCounter].outputMovingAverageChargeRate);
        printf("\nState Of Charge Statistics:\n");
        printf("Minimum: %.2f\n",BatteryParameters->Battery[loopCounter].outputMinimumSOC);
        printf("Maximum: %.2f\n",BatteryParameters->Battery[loopCounter].outputMaximumSOC);
        printf("Average: %.2f\n",BatteryParameters->Battery[loopCounter].outputMovingAverageSOC);
        printf("\nTemperature Statistics:\n");
        printf("Minimum: %.2f\n",BatteryParameters->Battery[loopCounter].outputMinimumTemperature);
        printf("Maximum: %.2f\n",BatteryParameters->Battery[loopCounter].outputMaximumTemperature);
        printf("Average: %.2f\n",BatteryParameters->Battery[loopCounter].outputMovingAverageTemperature);
    }
}

void ReceiverSideImplementation(struct Battery *BatteryParameters) {
    AllocateMemoryToSaveInput(BatteryParameters);
    ReadBatteryParametersfromConsole(BatteryParameters,(size_t)NUMBER_OF_ELEMENTS);
    computeStatitics(BatteryParameters, NUMBER_OF_ELEMENTS, NUMBER_OF_BATTERY, NUMBER_OF_SAMPLES_FOR_AVERAGE);
    formatAndPrintStatisticsToConsole(BatteryParameters);
    freeAllocatedMemory(BatteryParameters);
}
