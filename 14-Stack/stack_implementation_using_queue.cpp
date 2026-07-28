#include <iostream>
#include <queue>
using namespace std;

class MyStack {
    queue<int> Q1;
    queue<int> Q2;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        if(empty()){
            Q1.push(x);
        }else{
            while(!Q1.empty()){
                Q2.push(Q1.front());
                Q1.pop();
            }
            Q1.push(x);
            while(!Q2.empty()){
                Q1.push(Q2.front());
                Q2.pop();
            }
        }
    }
    
    int pop() {
        int ans = Q1.front();
        Q1.pop();
        return ans;
    }
    
    int top() {
        return Q1.front();
    }
    
    bool empty() {
       return Q1.empty();
    }
};

int main(){
    MyStack myStack;
    
    myStack.push(1);
    myStack.push(2);
    
    cout << myStack.top() << "\n";
    cout << myStack.pop() << "\n";
    cout << myStack.empty() << "\n";
return 0;
}