#include<iostream>
#include<climits>

using namespace std;
int reversenumber(int n){
    int reverse_num=0;
    while(n>0){
        int digit=n%10;
        if(reverse_num>INT_MAX/10 || reverse_num<INT_MIN/10){
            return 0;
        }
        reverse_num=(reverse_num*10)+digit;
        n/=10;
    }
return reverse_num;
} 
int main()
{
    int n;
    cin>>n;
    cout<<reversenumber(n)<<endl;
return 0;
}