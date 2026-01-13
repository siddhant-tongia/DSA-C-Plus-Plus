#include<iostream>
using namespace std;
double pow(double x,int n) 
{
    long binary_form=n;
    double ans=1;
    if(n<0)
    {
        x=1/x;
        binary_form= -binary_form;
    }
    while(binary_form>0)
    {
        if(binary_form%2==1)
        {
            ans=ans*x;
        }
        x *=x;
        binary_form/=2;
    }
return ans;
}
int main()
{
    double x =-5;
    int n=3;
    cout<<"The answer is :"<<pow(x,n);
return 0;
}