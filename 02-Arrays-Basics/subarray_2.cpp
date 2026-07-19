#include<iostream>
using namespace std;
 
int main()
{
    int arr[]={1,2,3,4,5};
    int max_sum=0;
    for(int st=0;st<5;st++)
    {
        int sum=0;
        for(int end=st;end<5;end++)
        {
            sum +=arr[end];
            max_sum=max(max_sum,sum);
        }
    }
    cout<<"The maximum subarry value is "<<max_sum;
return 0;
}