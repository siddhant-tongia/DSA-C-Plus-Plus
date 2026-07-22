#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2){

    stack<int> s;
    unordered_map<int,int> m;
    
    for(int i=nums2.size()-1 ; i>=0 ; i--){
        while(!s.empty() && s.top() <= nums2[i]){
            s.pop();
        }

        if(s.empty()){
            m[nums2[i]] = -1;
        }else{
            m[nums2[i]] = s.top();
        }
        s.push(nums2[i]);

    }
    
    vector<int> ans;

    for(int j=0 ; j<nums1.size() ; j++){
        ans.push_back(m[nums1[j]]);
    }
    
    return ans;
}

int main(){

    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};

    vector<int> result = nextGreaterElement(nums1, nums2);

    for(int i=0 ; i<result.size() ; i++){
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}