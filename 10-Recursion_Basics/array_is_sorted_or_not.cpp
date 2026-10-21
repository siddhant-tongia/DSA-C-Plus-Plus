/*
 * Problem: Check if Array is Sorted
 * Description: Given an array arr of size n, determine if the elements are sorted
 * in non-decreasing order using recursion. Return true if sorted, otherwise false.
 * Example:
 * Input: nums = [1, 2, 3, 4, 5], n = 5
 * Output: 1 (true)
 * Explanation: Each element is greater than or equal to the preceding one, so the array is sorted.
 */
#include<iostream>
#include<vector>
using namespace std;
bool ArrayIsSortedOrNot(vector<int> &arr , int n){
    if(n==0 || n==1){
        return true;
    }
    return arr[n-1] >= arr[n-2] && ArrayIsSortedOrNot(arr,n-1);
}
 
int main()
{
    vector<int> nums={1,2,3,4,5};
    int n=nums.size();
    cout<<ArrayIsSortedOrNot(nums,n);
return 0;
}