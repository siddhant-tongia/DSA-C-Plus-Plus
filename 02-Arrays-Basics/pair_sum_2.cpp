/*
 * Problem: Two Sum II - Input Array Is Sorted
 * Description: Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number.
 * Return the indices of the two numbers.
 * Example:
 * Input: numbers = [2,7,11,15], target = 9
 * Output: [0,1] (or [1,2] for 1-based indexing)
 */
#include<iostream>
#include<vector>
using namespace std;
vector<int>pairsum(vector<int>nums,int target)
{
    int n=nums.size();
    int i=0,j=n-1;
    while(i<j)
    {
        if(nums[i]+nums[j]>target)
        {
            j--;
        }
        else if(nums[i]+nums[j]<target)
        {
            i++;
        }
        else
        {
            return {i,j};
        }
    }
    return {};  
}
 
int main()
{
    vector<int> nums = {2, 7, 11, 15};
    int target = 18;

    vector<int> result = pairsum(nums, target);

        cout << result[0] << " " << result[1];
return 0;
}