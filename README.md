# Queue_Simulaton_Program

Steps from *Data Structures Using C++*, D.S. Malik
<hr>

This program is meant to simulate a queuing type situation where a number of servers are serving as many customers during a 
selected time interval; such as a grocery store check out or theater box office. The objective is to figure the average amount
of time a customer waits in line (queue) before reaching server.

For this simulation, the user will assign the number of servers, how long is the time interval, the 
amount of time it takes to serve a customer, and the time each customer to arrives.

The servers and customers will be placed into their separate classes and queue ADT. 
<br>

# Sample run
```
Enter the simulation time: 100

Enter the number of servers: 1

Enter the transaction time: 5

Enter the time between customers arrival: 4
```

### From Simulation.txt
```
Customer number 1 arrived at time unit 4
From server number 1 customer number 1
    departed at clock unit 9
Customer number 2 arrived at time unit 11
Customer number 3 arrived at time unit 15
From server number 1 customer number 2
    departed at clock unit 16
From server number 1 customer number 3
    departed at clock unit 21
Customer number 4 arrived at time unit 22
Customer number 5 arrived at time unit 26
From server number 1 customer number 4
    departed at clock unit 27
Customer number 6 arrived at time unit 30
From server number 1 customer number 5
    departed at clock unit 32
Customer number 7 arrived at time unit 34
From server number 1 customer number 6
    departed at clock unit 37
Customer number 8 arrived at time unit 39
From server number 1 customer number 7
    departed at clock unit 42
Customer number 9 arrived at time unit 44
From server number 1 customer number 8
    departed at clock unit 47
Customer number 10 arrived at time unit 51
From server number 1 customer number 9
    departed at clock unit 52
Customer number 11 arrived at time unit 56
From server number 1 customer number 10
    departed at clock unit 57
From server number 1 customer number 11
    departed at clock unit 62
Customer number 12 arrived at time unit 62
From server number 1 customer number 12
    departed at clock unit 67
Customer number 13 arrived at time unit 70
From server number 1 customer number 13
    departed at clock unit 75
Customer number 14 arrived at time unit 75
From server number 1 customer number 14
    departed at clock unit 80
Customer number 15 arrived at time unit 80
From server number 1 customer number 15
    departed at clock unit 85
Customer number 16 arrived at time unit 85
From server number 1 customer number 16
    departed at clock unit 90
Customer number 17 arrived at time unit 90
Customer number 18 arrived at time unit 94
From server number 1 customer number 17
    departed at clock unit 95
From server number 1 customer number 18
    departed at clock unit 100

The simulation ran for 100 time units
Numbers of servers: 1
Average transaction time: 5
Total waiting time: 16
Number of customers that completed a transaction: 18
Number of customers left in the servers: 0
The number of customers left in queue: 0
Average waiting time: 0.89
```
