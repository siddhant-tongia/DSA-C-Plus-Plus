#include <iostream>
#include <stack>
#include <algorithm> /

using namespace std;

class MinStack{
public:

    stack<pair<int,int>> s;
    
    MinStack(){
        
    }
    
    void push(int val){
        if(s.empty()){
            s.push({val,val});
        }else{
            int minVal = min(val,s.top().second);
            s.push({val,minVal});
        }
    }
    
    void pop(){
        s.pop();
    }
    
    int top(){
        return s.top().first;
    }
    
    int getMin(){
        return s.top().second;
    }
};

int main(){

    MinStack minSt;
    
    // Simulating the LeetCode example
    minSt.push(-2);
    minSt.push(0);
    minSt.push(-3);
    
    cout << "Current Min: " << minSt.getMin() << endl; // Should output -3
    
    minSt.pop();
    
    cout << "Current Top: " << minSt.top() << endl;    // Should output 0
    cout << "Current Min: " << minSt.getMin() << endl; // Should output -2

    return 0;
}