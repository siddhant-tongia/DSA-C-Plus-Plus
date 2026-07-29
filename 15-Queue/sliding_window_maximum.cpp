#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {

    deque<int> dq;
    vector<int> ans;
    int n = nums.size();

    for(int i=0 ; i<k ; i++){

        while(dq.size() > 0 && nums[dq.back()] < nums[i]){
            dq.pop_back();
        }
        dq.push_back(i);
    }

    for(int i=k ; i<n ; i++){

        ans.push_back(nums[dq.front()]);

        while(dq.size() > 0 && dq.front() <= i-k){
        dq.pop_front();
        }

        while(dq.size() > 0 && nums[dq.back()] < nums[i]){
        dq.pop_back();
        }

        dq.push_back(i);
    }

    ans.push_back(nums[dq.front()]);
return ans;
}

int main(){
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    
    vector<int> result = maxSlidingWindow(nums, k);
    
    for(int i=0 ; i<result.size() ; i++){
        cout << result[i] << " ";
    }
    cout << "\n";
return 0;
}