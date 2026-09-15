/*
 * Problem: Find the Duplicate Number
 * Description: Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive, find the one repeated number.
 * Example:
 * Input: nums = [1,3,4,2,2]
 * Output: 2
 */
#include<iostream>                      //TC = O(n) and SC = O(1)  
#include<vector>                        // Using Linked List
#include<unordered_set>
using namespace std;
int findDuplicate(vector<int> &nums){
    int slow=nums[0],fast=nums[0];
    do{
        slow=nums[slow];
        fast=nums[nums[fast]];
    } while(slow!=fast);
    slow=nums[0];
    while(slow!=fast){
        slow=nums[slow];
        fast=nums[fast];
    }
    return fast;
}
int main()
{
    vector<int> nums={1,2,3,3,4};
    cout<<findDuplicate(nums)<<endl;
return 0;
}