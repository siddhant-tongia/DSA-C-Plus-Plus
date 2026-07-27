#include<iostream>
#include<vector>
using namespace std;

class CircularQueue{
    int *arr;
    int currsize,cap;
    int f,r;

    public:
        CircularQueue(int size){
            cap = size;
            arr = new int[cap];
            f = 0;
            r = -1;
            currsize = 0;
        }

        void push(int val){
            if(currsize == cap){
                return;
            }
            r = (r+1) % cap;
            arr[r] = val; 
            currsize++;
        }

        void pop(){
            if(empty()){
                return;
            }
            f = (f+1) % cap;
            currsize--;
        }

        int front(){
            if(empty()){
                return -1;
            }
            return arr[f];
        }

        bool empty(){
            return currsize == 0;
        }
};

 
int main()
{
    CircularQueue cq(5);

    cq.push(1);
    cq.push(2);
    cq.push(3);
    cq.pop();
    cq.push(4);
    while(!cq.empty()){
        cout<<cq.front()<<" ";
        cq.pop();
    }
return 0;
}