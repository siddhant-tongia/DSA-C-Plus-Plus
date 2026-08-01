#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

int longestConsecutive(vector<int>& nums){
    if (nums.empty()){
        return 0;
    }

    unordered_set<int> s(nums.begin(), nums.end());
    int max_count = 0;

    for (int curr_element : s){
        if (s.find(curr_element - 1) == s.end()){
            int current_num = curr_element;
            int current_count = 1;
            while (s.find(current_num + 1) != s.end()){
                current_num++;
                current_count++;
            }
            max_count = max(max_count, current_count);
        }
    }
return max_count;
}

int main(){
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    cout << longestConsecutive(nums) << "\n";
return 0;
}