#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void dutchNationalFlag(vector<int>&nums){
    int n = nums.size();
    int low =0,mid = 0 ;
    int high =n-1;

    while(mid<=high){
        if (nums[mid] == 0){
            swap(nums[mid++],nums[low++]);
        }
        else if (nums[mid] == 1){
            mid++;
        }
        else{
            swap(nums[mid],nums[high--]);
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