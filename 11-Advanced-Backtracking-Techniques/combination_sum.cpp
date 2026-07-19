#include<iostream>
#include<vector>
using namespace std;

void solve(vector<int> &candidates, int target, int  idx, vector<int> &arr, vector<vector<int>> &ans){
    if(target == 0){
        ans.push_back(arr);
        return;
    }

    if(target < 0 || idx == candidates.size()){
        return;
    }

    arr.push_back(candidates[idx]);
    solve(candidates,target-candidates[idx],idx,arr,ans);
    arr.pop_back();

    solve(candidates,target,idx+1,arr,ans);
}

int main() {
    vector<int>candidates = {2,3,6,7};
    int target = 7;
    
    vector<int> arr;
    vector<vector<int>> ans;
        solve(candidates,target,0,arr,ans);

    for (int i=0 ; i<ans.size() ; i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
return 0;
}