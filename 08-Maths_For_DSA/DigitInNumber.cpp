#include<iostream>

using namespace std;

int main()
{
    int n,digit=0,sum=0;
    cin>>n;
    if(n==0){
        digit=1;
        sum=0;
    }
    else{
        n = abs(n);
        while(n!=0){
            sum+=n%10;
            n/=10;
            digit++;
        }
    }
    cout<<"Digit ="<<digit<<endl;
    cout<<"Sum ="<<sum<<endl;
return 0;
}