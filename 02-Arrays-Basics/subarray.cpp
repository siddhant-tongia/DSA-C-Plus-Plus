/*
 * Problem: Print All Subarrays
 * Description: Given an array of integers, print all possible contiguous subarrays.
 * A subarray is a contiguous non-empty sequence of elements within an array.
 * Example:
 * Input: arr = [1, 2, 3]
 * Output: 
 * 1 
 * 1 2 
 * 1 2 3 
 * 2 
 * 2 3 
 * 3 
 */
#include<iostream>
using namespace std;
 
int main()
{
    int a[]={1,2,3,4,5};
    for(int st=0;st<5;st++)
    {
        for(int end=st;end<5;end++)
        {
            for(int i=st;i<=end;i++)
            {
                cout<<a[i];
            }
        cout<<" ";
        }
    cout<<endl;
    }
return 0;
}