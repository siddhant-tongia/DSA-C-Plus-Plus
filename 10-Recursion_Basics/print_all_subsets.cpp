#include<iostream>
#include<vector>
using namespace std;
void printsubset(vector<int> &nums,vector<int> &ans,int i){
    if(i==nums.size()){
        for(int val:ans){
            cout<<val<<" ";
        }
        cout<<endl;
        return;
    }
    ans.push_back(nums[i]); // inclusion
    printsubset(nums,ans,i+1);
    ans.pop_back(); // Backtracking
    printsubset(nums,ans,i+1); //exclusion
}
int main()
{
    vector<int> nums={1,2,3};
    vector<int> ans;
    printsubset(nums,ans,0);
return 0;
}
