#include<iostream>
#include <algorithm>
#include<vector>
using namespace std; 
int main()
{
    vector<int>nums={1,2,1,1,2};
    int n=nums.size();
    sort(nums.begin(),nums.end());
    int freq=1,ans=nums[0];
    for(int i=1;i<n;i++)
    {
        if(nums[i]==nums[i-1])
        {
            freq++;
        }
        else
        {
            freq=1;
            ans=nums[i];
        }
        if(freq>n/2)
        {
           cout<<"The number is :"<<ans; 
           break;
        }
    }
return 0;
}