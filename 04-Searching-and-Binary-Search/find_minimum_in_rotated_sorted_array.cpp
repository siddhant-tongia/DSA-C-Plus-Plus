#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findMin(vector<int> &nums){
    int n = nums.size();
    int low = 0, high = n-1;
    int small = nums[0];
    while(low <= high){
        int mid = low + (high-low)/2;

        if(nums[low] <= nums[high]){
            small = min(small,nums[low]);
            break;
        }

        if(nums[low] <= nums[mid]){
            small = min(small,nums[low]);
            low = mid+1;
        }else{
            small = min(small,nums[mid]);
            high = mid-1;
        }
    }
return small;
}

int main(){
    vector<int> nums = {3, 4, 5, 1, 2};
    cout << findMin(nums) << "\n";
return 0;
}