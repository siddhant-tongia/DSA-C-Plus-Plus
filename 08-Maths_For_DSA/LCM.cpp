#include<iostream>

using namespace std;
int LCM(int n,int m){
    if (n == 0 && m == 0) return 0; 

    if(m==0){
        return n;
    }
    int gcd= LCM(m,n%m);
    int lcm=(n*m)/gcd;
return lcm;
}
int main()
{
    int a,b;
    cin>>a>>b;
    cout<<LCM(a,b);
return 0;
}