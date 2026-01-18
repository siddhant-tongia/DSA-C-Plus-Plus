#include<iostream>
#include<vector>
using namespace std;
void mergearray(vector<int>&vec_1,vector<int>&vec_2,int n,int m)
{
    vec_1.resize(n+m,0);
    int i=n-1;
    int j=m-1;
    int ind=m+n-1;
    while(i>=0 && j>=0)
    {
        if(vec_1[i]>=vec_2[j])
        {
            vec_1[ind--]=vec_1[i--];
        }
        else
        {
            vec_1[ind--]=vec_2[j--];
        }
    }
    while(j>=0)
    {
        vec_1[ind--]=vec_2[j--];
    }
}
 
int main()
{
    vector<int>vec_1={1,2,3};
    vector<int>vec_2={2,5,6};
    int n=vec_1.size();
    int m=vec_2.size();
    mergearray(vec_1,vec_2,n,m);
    for(int val:vec_1)
    {
        cout<<val<<" ";
    }
return 0;
}