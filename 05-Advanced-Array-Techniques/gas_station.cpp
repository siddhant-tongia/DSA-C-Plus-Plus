/*
 * Problem: Gas Station
 * Description: There are n gas stations along a circular route, where the amount of gas at the ith station is gas[i]. You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from the ith station to its next (i + 1)th station. Return the starting gas station's index if you can travel around the circuit once in the clockwise direction, otherwise return -1.
 * Example:
 * Input: gas = [1,2,3,4,5], cost = [3,4,5,1,2]
 * Output: 3
 */
#include <iostream>
#include <vector>
using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost){
    
    int total_gas = 0;
    int total_cost = 0;
    for(int i=0 ; i<gas.size() ; i++){
        total_gas += gas[i];
        total_cost += cost[i];
    }

    if(total_cost > total_gas){
        return -1;
    }

    int start = 0;
    int curr_gas = 0;

    for(int i=0 ; i<gas.size() ; i++){
        curr_gas += gas[i] - cost[i];
        if(curr_gas < 0){
            start = i+1;
            curr_gas = 0;
        }
    }
return start;
}

int main() {
    vector<int> gas = {1, 2, 3, 4, 5};
    vector<int> cost = {3, 4, 5, 1, 2};
    
    cout << canCompleteCircuit(gas, cost) << "\n";
return 0;
}