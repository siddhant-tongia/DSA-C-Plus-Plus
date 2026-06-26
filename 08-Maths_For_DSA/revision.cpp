#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int reverse(int n){
    int num = n;
    int i = 1;
    int reverse_num = 0;
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
    
return 0;
}