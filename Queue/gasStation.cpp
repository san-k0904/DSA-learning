#include<iostream>
#include<vector>
using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int totalGas = 0, startIndex = 0, currGas = 0;

    for (int i = 0; i < gas.size(); ++i) {
        currGas += gas[i] - cost[i];
        totalGas += gas[i] - cost[i];//if this <0 then that means it was not possible to as gas<cost

        if (currGas < 0) {
            startIndex = i + 1;
            currGas = 0;
        }
    }

    return totalGas>=0?startIndex:-1;
}