#include<iostream>
#include<cmath>
using namespace std;
int decimal_num(long binary_num)
{
    int ans=0,num,i=0;
    while(binary_num>0)
    {
        num=binary_num%10;
        if(num!=0 && num!=1)
        {
            cout<<"Invalid";
        }
        ans+=pow(2,i)*num;
        binary_num/=10;
        i++;
    }
return ans;
}
int main()
{
    long binary_num;
    cin>>binary_num;
    cout<<decimal_num(binary_num);
    
return 0;
}