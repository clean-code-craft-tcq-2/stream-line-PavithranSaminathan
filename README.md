# Streaming BMS Data

This project is about sending and receiving BMS data.

## Decomposition

At a top level, the program runs in two processes - the sender and the receiver.

```mermaid
flowchart LR
A((sensor1)) --> Sender
B((sensor2)) --> Sender
Sender --> |line-by-line-via-console|Receiver
Receiver --> |statistics|C((Output))
```

The Sender simulates and processes data from sensors. It sends data line-by-line to the console, in a format that it defines.
The Receiver inputs this data and computes statistics.

The Sender sends data to the Receiver using [console redirection and pipes](https://ss64.com/nt/syntax-redirection.html).
They need to run on the command-line as follows:

`sender-executable | receiver-executable`

This would make the console-writes of the sender
become the console-reads of the receiver.
It gives us the flexibility of decoupling the sender and receiver -
they can even be written in different languages.

## Phases

The project is divided into two phases:

- Develop the Sender in the first phase, complete with test cases. The syntax and meaning of the data must be evident by reading your test cases.
Do not develop the Receiver yet.

We will instruct you to handover your Sender to another participant and take-over another Sender.

- Develop the Receiver for the Sender you take-over.

## The Interface

We document the interface between the Sender and the Receiver as test cases.

The Sender and Receiver are testable on their own:

- The Sender is testable without the Receiver - so we can develop
for another sensor, test and be confident about integration.
- The Receiver is testable without the Sender - so we can enhance with additional statistics,
without re-testing against all Senders again.

## Decomposition of responsibility

The naming of source files within the Sender and within the Receiver
give their internal decomposition.

## Minimum Functionality

This section lists the minimum functionality of the Sender and Receiver.

### The Sender

- simulates and sends at least two Battery / Charging parameters
- sends fifty readings in a stream
- can either generate values for the parameters, or read from a file
- uses console output to communicate the parameters.

### The Receiver

- reads the parameters from the console input
- after reading every parameter, it prints the following:
    - maximum and minimum values in the incoming stream
    - [simple moving average](https://www.investopedia.com/terms/s/sma.asp) of the last 5 values

## Quality Parameters

Setup the quality parameters of your project (duplication, complexity, coverage, warnings) using GitHub workflow yml files.

## Test Execution explanation with sequence diagram

Test Case 1: Check TransmitBatteryStatus function positive result with both positive arguments

    Both arguments pass as positive to make result true.
    
Test Case 2: Check TransmitBatteryStatus function negative result with invalid arguments

    Both argument send as invalid data to make result false.  

Test Case 3: Check TransmitBatteryStatus function negative result with first invalid arguments
      
     Send argument send as invalid TotalCounts data to make result false.

Test Case 4: Check TransmitBatteryStatus function negative result with second invalid argument
    
    Send argument send as invalid TotalBatteries data to make result false.
  
  Below sequence diagram mentioned for above 4 test cases
 
 ```mermaid
sequenceDiagram
    BatteryMonitorTest->>+TransmitBatteryReport: TransmitBatteryStatus(int NoofReadings, int TotalNoOfBattery):int
    TransmitBatteryReport->>+TransmitBatteryReport: ReadBatteryStatus()
    TransmitBatteryReport->>+TransmitBatteryReport: printOnConsole(char * Data)
    BatteryMonitorTest-->>+BatteryMonitorTest:Assert of TransmitBatteryStatus function
```
Test Case 5:
    Verify formatted CSV output data for individual battery
    
    Sample Output data is : "B:1,CR:0.60,SOC:77,Temp:2"
    
       - BatteryNo =1
       - Charge rate = 0.6
       - SOC = 77
       - Temp =2 
       
       
    
 ```mermaid
sequenceDiagram
    BatteryMonitorTest->>+TransmitBatteryReport: ReadBatteryStatus(int , int , char*):int
    TransmitBatteryReport-->>-BatteryMonitorTest:Assert of formattted output value
```
