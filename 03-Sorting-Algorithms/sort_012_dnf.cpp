/*
 * Problem: Sort Colors (Dutch National Flag Problem)
 * Description: Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
 * We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
 * You must solve this problem without using the library's sort function.
 * Example:
 * Input: nums = [2,0,2,1,1,0,1,2,0,0]
 * Output: [0,0,0,0,1,1,1,2,2,2]
 */
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void dutchNationalFlag(vector<int>&nums)
{
    int l=0,m=0,h=nums.size()-1;
    while(m<=h)
    {
        if(nums[m]==0)
        {
            swap(nums[l],nums[m]);
            {
                l++;
                m++;
            }
        }
        else if(nums[m]==1)
        {
            m++;
        }
        else
        {
            swap(nums[m],nums[h]);
            h--;
        }
    }
}

int main() {
    vector<int>vec={2,0,2,1,1,0,1,2,0,0};
    dutchNationalFlag(vec);
    cout<<"Sorted array(One-Pass):";
    for(int val:vec)
    {
        cout<<val<<" ";
    }
    return 0;
}