#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int num(vector<int>nums,int target)
{
    int n=nums.size();
    int st=0,end=n-1;
    while(st<=end)
    {
        int mid=st+(end-st)/2;
        if(nums[mid]==target)
        {
            return mid;
        }
        if(nums[st]>=nums[mid])
        {
            if(nums[mid]<=target && target<=nums[end])
            {
                st=mid+1;
            }
            else
            {
                end=mid-1;
            }
        }
        if(nums[st]<=nums[mid])
        {
            if(nums[st]<=target && target<=nums[mid])
            {
                end=mid-1;
            }
            else
            {
                st=mid+1;
            }
        }
        
    }
return -1;
}
 
int main()
{
    vector<int>nums={6,7,0,1,2,3,4,5};
    int target=0;
    cout<<"The index of the target is :"<<num(nums,target);
    
return 0;
}