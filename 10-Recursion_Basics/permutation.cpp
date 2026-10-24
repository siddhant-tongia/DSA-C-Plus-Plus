/*
 * Problem: Permutations (LeetCode #46)
 * Description: Given an array nums of distinct integers, return all possible permutations
 * using recursive backtracking (swap, recurse, backtrack).
 * Example:
 * Input: nums = [1, 2, 3]
 * Output: [[1, 2, 3], [1, 3, 2], [2, 1, 3], [2, 3, 1], [3, 2, 1], [3, 1, 2]]
 * Explanation: There are 3! = 6 unique permutations for an array of 3 distinct numbers.
 */
#include<iostream>
#include<vector>
using namespace std;
 
void getPerms(vector<int> &nums,int idx, vector<vector<int>> &ans){
if(idx==nums.size()){
    ans.push_back({nums});
    return;
}
    for(int i=idx;i<nums.size();i++){
        swap(nums[idx],nums[i]);
        getPerms(nums,idx+1,ans);
        swap(nums[idx],nums[i]);
    }
}

vector<vector<int>> permute(vector<int>& nums){
    vector<vector<int>>ans;
    getPerms(nums,0,ans);
    return ans;
}

int main(){
    vector<int>nums={1,2,3};
    vector<vector<int>> result=permute(nums);
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++){
            cout<<result[i][j];
        }
        cout<<endl;
    }
}