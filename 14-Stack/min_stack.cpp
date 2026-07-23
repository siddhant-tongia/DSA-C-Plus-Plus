#include <iostream>
#include <stack>
#include <algorithm> 

using namespace std;

class MinStack{
public:

    stack<long long int > s;
    long long int minVal;
    
    MinStack(){
        
    }
    
    void push(int val){

        if(s.empty()){
            s.push(val);
            minVal = val;

        }else{
            if(val < minVal){
                s.push((long long)2*val - minVal);
                minVal = val;
            }else{
                s.push(val);
            }
        }
    }
    void pop(){
       if(s.top() < minVal){
        minVal = 2*minVal - s.top();
        s.pop();
       }else{
        s.pop();
       }
    }
    
    int top(){
        if(s.top() < minVal){
            return minVal;
        }else{
            return s.top();
        }
    }
    
    int getMin(){
        return minVal;
    }
};

int main(){

    MinStack minSt;
    
    minSt.push(-2);
    minSt.push(0);
    minSt.push(-3);
    
    cout << "Current Min: " << minSt.getMin() << endl; 
    
    minSt.pop();
    
    cout << "Current Top: " << minSt.top() << endl;   
    cout << "Current Min: " << minSt.getMin() << endl; 

    return 0;
}