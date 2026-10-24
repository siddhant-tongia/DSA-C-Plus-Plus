/*
 * Problem: Binary Search (Recursive) (LeetCode #704)
 * Description: Given an array of integers nums sorted in ascending order, and an integer target,
 * search for target in nums using recursive divide-and-conquer. Return its index if found,
 * otherwise return -1.
 * Example:
 * Input: nums = [-1, 0, 3, 5, 9, 12], target = 9
 * Output: 4
 * Explanation: 9 exists in nums and its index is 4.
 */
#include<iostream>
#include<vector>
using namespace std;
int BinarySearch(vector<int> &nums,int start,int end,int target){
    if (start>end){
    return -1;
    }
    int mid=start+(end-start)/2;
    if(nums[mid]>target){
        return BinarySearch(nums,start,mid-1,target);
    }else if(nums[mid]<target){
        return BinarySearch(nums,mid+1,end,target);
    }else{
        return mid;
    }
}
 
int main()
{
    vector<int> nums={-1,0,3,5,9,12};
    int target=9;
    cout<<BinarySearch(nums,0,nums.size()-1,target)<<endl;
return 0;
}