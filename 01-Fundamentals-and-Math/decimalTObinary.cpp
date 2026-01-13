#include<iostream>
using namespace std;
long binary(int decimal_num)
{
    int reversed=0;
    int i=1;
    if(decimal_num==0)
    {
        return 0;
    }
    while(decimal_num>0)
    {
        int remainder =decimal_num%2;
        reversed=reversed+remainder*i;
        decimal_num/=2;
        i*=10;
    }
return reversed;
}

int main()
{
    int decimal_num;
    cin>> decimal_num;
    cout<<binary(decimal_num);

    
return 0;
}