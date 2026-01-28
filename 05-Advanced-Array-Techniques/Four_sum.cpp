#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int>> FourSum(vector<int> &nums){
    vector<vector<int>> ans;
    int n=nums.size();
    sort(nums.begin(),nums.end());
    for(int i=0;i<n;i++){
        if(i>0 && nums[i]==nums[i-1]){
            continue;
        }
        for(int j=i+1;j<n;j++){
            if(j>i+1 && nums[j]==nums[j-1]){
                continue;
            }
            int k=j+1,l=n-1;
            while (k<l){
                int sum=nums[i]+nums[j]+nums[k]+nums[l];
                if(sum>0){
                    l--;
                }else if(sum<0){
                    k++;
                }else{
                    ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                    k++;l--;
                    while(k<l && nums[k]==nums[k-1]){
                        k++;
                    }
                    while(k<l && nums[l]==nums[l-1]){
                        l--;
                    }
                }
            }
        }
    }
    return ans;
}
 
int main()
{
    vector<int> nums={-2,-1,2,2,1,-1,1};
    vector<vector<int>> result =FourSum(nums);
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++){
            cout<<result[i][j]<<"\t";
        }
        cout<<endl;
    }
return 0;
}