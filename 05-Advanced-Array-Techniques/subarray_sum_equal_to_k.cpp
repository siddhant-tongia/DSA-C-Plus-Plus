/*
 * Problem: Subarray Sum Equals K
 * Description: Given an array of integers nums and an integer k, return the total number of continuous subarrays whose sum equals to k.
 * Example:
 * Input: nums = [1,1,1], k = 2
 * Output: 2
 */


 #include<iostream>
 #include<vector>
 #include<unordered_map>
 using namespace std;

 int subarraySum(vector<int> &nums,int tar){
    vector<int> prefix(nums.size(),0);
    prefix[0] = nums[0];
    int count = 0;

    for(int i=1 ; i<nums.size() ; i++){
        prefix[i] = nums[i] + prefix[i-1];
    }

    unordered_map<int,int> m;

    for(int i=0 ; i<nums.size() ; i++){
        if(prefix[i] == tar){
            count ++;
        }

        int second = prefix[i] - tar;
        if(m.find(second) != m.end()){
            count += m[second];
        }
        if(m.find(prefix[i]) == m.end()){
            m[prefix[i]] = 0;
        }
        m[prefix[i]]++;
    }
    return count;
}
  
 int main()
 {
    vector<int> nums = {9,4,20,3,10,5};
    cout << subarraySum(nums,33);
 return 0;
 }