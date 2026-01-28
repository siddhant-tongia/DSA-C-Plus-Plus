/*
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
vector<vector<int>> threesum(vector<int> &nums){
    int n=nums.size();
    set<vector<int>> uniquetriplet;
    for(int i=0;i<n;i++){
        int tar=-nums[i];
        set<int> s;
        for(int j=i+1;j<n;j++){
            int third=tar-nums[j];
            if(s.find(third)!=s.end()){
                vector<int> trip ={nums[i],nums[j],third};
                sort(trip.begin(),trip.end());
                uniquetriplet.insert(trip);
            }
            s.insert(nums[j]);
        }
    }

vector<vector<int>>ans (uniquetriplet.begin(),uniquetriplet.end());
return ans;
}
 
int main()
{
    vector<int> nums={1,0,-1,2,-1,-4};
    vector<vector<int>> result =threesum(nums);
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++){
            cout<<result[i][j]<<"\t";
        }
        cout<<endl;
    }
return 0;
}
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
      int n= nums.size();
      vector<vector<int>> ans;
      for(int i=0 ;i<n ;i++){
        if(i>0 && nums[i]==nums[i-1]){
            continue;
        }
        int j=i+1,k=n-1;
        while(j<k){
            int sum=nums[i]+nums[j]+nums[k];
            if(sum>0){
                k--;
            }else if(sum<0){
                j++;
            }else{
                ans.push_back({nums[i],nums[j],nums[k]});
                k--;
                j++;
                while(j<k && nums[j]==nums[j-1]){
                    j++;
                }
            }
        }
      }  
    return ans;
}
 
int main()
{
    vector<int> nums={1,0,-1,2,-1,-4};
    vector<vector<int>> result =threeSum(nums);
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++){
            cout<<result[i][j]<<"\t";
        }
        cout<<endl;
    }
return 0;
}