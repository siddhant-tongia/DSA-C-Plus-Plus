#include<iostream>
#include<vector>
using namespace std;

int ME(vector<int>nums)
{
    int n=nums.size();
    for(int val:nums)
    {
        int freq=0;
        for(int element:nums)
        {
            if(element==val)
            {
                freq++;
            }
        }
        if(freq>n/2)
        {
            return val;
        }
    }
return 0;
}

 
int main()
{
    vector<int>nums={1,2,2,1,1};
    int ans=ME(nums);
    cout<<"The majority element in the given array is :"<<ans;  
return 0;
}