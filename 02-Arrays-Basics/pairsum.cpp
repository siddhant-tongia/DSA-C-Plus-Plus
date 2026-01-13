#include<iostream>
#include<vector>
using namespace std;

vector<int> pairSum(vector<int> nums, int target)
{
    int n = nums.size();
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(nums[i] + nums[j] == target)
            {
                return {i, j};   
            }
        }
    }
    return {}; 
}

int main()
{
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = pairSum(nums, target);

        cout << nums[result[0]] << "&" << nums[result[1]];
    return 0;
}
