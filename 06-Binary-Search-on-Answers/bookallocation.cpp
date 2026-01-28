#include<iostream>
#include<vector>
using namespace std;
bool isValid(vector<int>&vec,int n,int m,int maxAllowedpages)
{
    int pages=0,stu=1;
    
    for(int i=0;i<n;i++)
    {
        if(vec[i]>maxAllowedpages)
        {
            return false;
        }
        if(vec[i]+pages<=maxAllowedpages)
        {
            pages+=vec[i];
        }
        else
        {
            pages=vec[i];
            stu++;
        }
    }
    if(stu<=m)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int solution(vector<int>&vec,int n,int m)
{
    if(n<m)
    {
        return -1;
    }
    int sum=0,max_value=0;
    for(int i=0;i<n;i++){
        sum+=vec[i];
        max_value=max(max_value,vec[i]);
    }
    int st=max_value,end=sum,ans=-1;
    while(st<=end)
    {
        int mid=st+(end-st)/2;
        if(isValid(vec,n,m,mid))
        {
            ans=mid;
            end=mid-1;
        }
        else
        {
            st=mid+1;
        }
    }
return ans;
}
 
int main()
{
    vector<int>vec={2,1,3,4};
    int n=vec.size(),m=2;
    cout<<solution(vec,n,m);
return 0;
}