#include<iostream>
#include <cmath>
using namespace std;
bool Armstrong(int n){
    int sum=0,num=n;
        while(n!=0){
            int digit=n%10;
            sum+=digit*digit*digit;
            n/=10;
        }
    if(sum==num){
        return true;
    }
    else{
        return false;
    }
}
 
int main()
{
    int n;
    cin>>n;
    cout<<Armstrong(n)<<endl;
return 0;
}