#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
    void subset(vector<int> &nums,vector<int> &ans,int i,set<vector<int>> &s){
        if(i==nums.size()){
            s.insert(ans);
            return;
        }
        ans.push_back(nums[i]);
        subset(nums,ans,i+1,s);
        ans.pop_back();
        subset(nums,ans,i+1,s);
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
       sort(nums.begin(),nums.end());
       set<vector<int>>reset;
       vector<int>ans;
       subset(nums,ans,0,reset);
       return vector<vector<int>>(reset.begin(),reset.end());
    }
 
    int main()
    {
        vector<int>nums={1,2,2};
        vector<vector<int>> result =subsetsWithDup(nums);
        for(int i=0;i<result.size();i++){
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j]<<"\t";
            }
            cout<<endl;
        }
    return 0;
    }