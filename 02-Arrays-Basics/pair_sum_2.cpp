#include<iostream>
#include<vector>
using namespace std;
vector<int>pairsum(vector<int>nums,int target)
{
    int n=nums.size();
    int i=0,j=n-1;
    while(i<j)
    {
        if(nums[i]+nums[j]>target)
        {
            j--;
        }
        else if(nums[i]+nums[j]<target)
        {
            i++;
        }
        else
        {
            return {i,j};
        }
    }
    return {};  
}
 
int main()
{
    vector<int> nums = {2, 7, 11, 15};
    int target = 18;

    vector<int> result = pairsum(nums, target);

        cout << result[0] << " " << result[1];
return 0;
}