#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int peak_num(vector<int>&nums)
{
    int n=nums.size();
    int s=1,e=n-2; // the reason for putting 1 and n-1 is because value at that index is never included as a peak number .
    while(s<=e)
    {
        int mid=s+(e-s)/2;
        if(nums[mid-1]<nums[mid] && nums[mid]>nums[mid+1])
        {
            return  mid;
        }
        if( nums[mid]>nums[mid-1])
        {
            s=mid+1;
        }
        else
        {
            e=mid-1;
        }
    }
return -1;
}
 
int main()
{
    vector<int> nums= {1, 3, 2, 1, 0};
    cout<<"The index of peak number is :"<<peak_num(nums);
    
return 0;
}