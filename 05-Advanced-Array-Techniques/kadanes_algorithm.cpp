/*
 * Problem: Maximum Subarray (Kadane's Algorithm)
 * Description: Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
 * Example:
 * Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
 * Output: 6
 */
#include<iostream>
#include<climits>
using namespace std;
 
int main()
{
    int a[]={1,2,3,4,5};
    int max_sum = INT_MIN;
    int sum=0;
    for(int i=0;i<5;i++)
    {
        sum+=a[i];
        max_sum=max(max_sum,sum);
        if(sum<0)
        {
            sum=0;
        }
    }

    cout << max_sum;
return 0;
}