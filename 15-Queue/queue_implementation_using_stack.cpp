#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
    stack<int> s1;
    stack<int> s2;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        if(s1.empty()){
            s1.push(x);
        }else{
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();  
            }
            s1.push(x);
            while(!s2.empty()){
                s1.push(s2.top());
                s2.pop();
            }
        }
    }
    
    int pop() {
        int ans = s1.top();
        s1.pop();
        return ans;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        return s1.empty();
    }
};

int main(){
    MyQueue myQueue;
    
    myQueue.push(1);
    myQueue.push(2);
    
    cout << myQueue.peek() << "\n";
    cout << myQueue.pop() << "\n";
    cout << myQueue.empty() << "\n";
return 0;
}