/*
 * Problem: Maximum Subarray
 * Description: Given an integer array nums, find the subarray with the largest sum, and return its sum.
 * Example:
 * Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
 * Output: 6
 * Explanation: The subarray [4,-1,2,1] has the largest sum 6.
 */
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