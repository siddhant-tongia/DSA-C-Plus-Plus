/*
 * Problem: Majority Element (Boyer-Moore Voting Algorithm)
 * Description: Given an array nums of size n, return the majority element (the element that appears more than ⌊n / 2⌋ times).
 * Example:
 * Input: nums = [2,2,1,1,1,2,2]
 * Output: 2
 */
#include<iostream>
#include<vector>
using namespace std;
int ME(vector<int>nums)
{
    int n=nums.size();
    int freq=0,ans=0;
    for(int i=0;i<n;i++)
    {
        if(freq==0)
        {
            ans=nums[i];
        }
        if(ans==nums[i])
        {
            freq++;
        }
        else 
        {
            freq--;
        }
    }
return ans;
}
 
int main()
{
    vector<int>nums={1,2,1,2,1};
   cout<<"The number is :"<<ME(nums); 
return 0;
}