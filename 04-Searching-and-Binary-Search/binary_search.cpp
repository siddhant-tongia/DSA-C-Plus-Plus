#include<iostream>  // solved by reccursion
#include<vector>
#include<algorithm>
using namespace std;
int num(vector<int>&nums,int st,int end,int target)
{
    while(end>=st)
    {
        int mid=st+(end-st)/2;
        if(nums[mid]>target)
        {
            return num(nums,st,mid-1,target);
        }
        else if (nums[mid]<target)
        {
            return num(nums,mid+1,end,target);
        }
        else
        {
            return mid;
        }
    }
return -1;
}
int main()
{
    vector<int>nums={0,3,4,5,9,12}; 
    int target =12;
    cout<<"The index of target is :"<<num(nums,0,5,target);
    
return 0;
}