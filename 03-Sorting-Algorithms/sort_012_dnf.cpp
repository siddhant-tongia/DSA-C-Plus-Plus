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