#include <iostream>
#include <stack>
#include <algorithm> 

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
    
    minSt.push(-2);
    minSt.push(0);
    minSt.push(-3);
    
    cout << "Current Min: " << minSt.getMin() << endl; 
    
    minSt.pop();
    
    cout << "Current Top: " << minSt.top() << endl;   
    cout << "Current Min: " << minSt.getMin() << endl; 

    return 0;
}