/*
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>vec(vector<int> &nums)
{
    int n=nums.size();
    vector<int>ans(n,1);
    for(int i=0;i<n;i++)
    {
        int prod=1;
        for(int j=0;j<n;j++)
        {
            if(i!=j)
            {
                prod*=nums[j];
            }
        }
        ans[i]=prod;
    }
return ans;
}
int main()
{
    vector<int>nums={1,2,3,4};
    vector<int>result=vec(nums);
    for(int val:result)
    {
        cout<<val<<endl;
    }
    
return 0;
}
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>vec(vector<int>&nums)
{
    int n=nums.size();
    vector<int>ans(n);
    vector<int>prefix(n);
    vector<int>suffix(n);
    prefix[0]=1,suffix[n-1]=1;
    for(int i=1;i<n;i++)
    {
        prefix[i]=prefix[i-1]*nums[i-1];
    }
    for(int i=n-2;i>=0;i--)
    {
        suffix[i]=suffix[i+1]*nums[i+1];
    }
    for(int i=0;i<n;i++)
    {
        ans[i]=prefix[i]*suffix[i];
    }
return ans;
}
 
int main()
{
    vector<int>nums={1,2,3,4};
    vector<int>result=vec(nums);
    for(int val:result)
    {
        cout<<val<<"\t";
    }
    
return 0;
}