/*
 * Problem: Single Element in a Sorted Array
 * Description: You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once. Find this single element that appears only once.
 * Example:
 * Input: nums = [1, 1, 2, 3, 3, 4, 4, 8, 8]
 * Output: 2
 */
#include<iostream>
#include<vector>
using namespace std;
int num(vector<int>nums)
{
    int n=nums.size();
    int st=0,end=n-1;
    while(st<=end)
    {
        int mid=st+(end-st)/2;
        if(mid==0 && nums[0]!=nums[1]) // edge case
        {
            return nums[0];
        }
        if(mid==n-1 && nums[n-1]!=nums[n-2]) // edge case
        {
            return nums[n-1];
        }
        if(nums[mid]!=nums[mid+1] && nums[mid]!=nums[mid-1])
        {
            return nums[mid];
        }
        if(mid%2==0)//remaining even number on both side 
        {
            if(nums[mid]==nums[mid-1])
            {
                end=mid-2;
            }
            else
            {
                st=mid+2;
            }
        }
        else
        {
            if(nums[mid]==nums[mid-1])
            {
                st=mid+1;
            }
            else
            {
                end=mid-1;
            }
        }
    }
return -1;
}
 
int main()
{
    vector<int> nums_1={1,1,2,3,3,4,4,8,8};
    vector<int> nums_2={1,1,2,2,3,3,4,8,8};
    vector<int> nums_3={3,3,7,7,10,11,11};
    vector<int> nums_4={3,3,7,10,10,11,11};
    cout<<"The single number  :"<<num(nums_1)<<endl;
    cout<<"The single number  :"<<num(nums_2)<<endl;
    cout<<"The single number  :"<<num(nums_3)<<endl;
    cout<<"The single number  :"<<num(nums_4)<<endl;
    
return 0;
}