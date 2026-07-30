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