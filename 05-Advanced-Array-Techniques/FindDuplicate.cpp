/*
#include<iostream>                      //TC = O(n) and SC = O(n)
#include<vector>
#include<unordered_set>
using namespace std;
int findDuplicate(vector<int> &nums){
    int n=nums.size();
    unordered_set<int> s;
    for(int i=0;i<n;i++){
        if(s.find(nums[i])!=s.end()){
            return nums[i];
        }
        s.insert(nums[i]);
    }
return -1;
}
 
int main()
{
    vector<int> nums={1,2,3,3,4};
    cout<<findDuplicate(nums)<<endl;
return 0;
}
*/
#include<iostream>                      //TC = O(n) and SC = O(1)  
#include<vector>                        // Using Linked List
#include<unordered_set>
using namespace std;
int findDuplicate(vector<int> &nums){
    int slow=nums[0],fast=nums[0];
    do{
        slow=nums[slow];
        fast=nums[nums[fast]];
    } while(slow!=fast);
    slow=nums[0];
    while(slow!=fast){
        slow=nums[slow];
        fast=nums[fast];
    }
    return fast;
}
int main()
{
    vector<int> nums={1,2,3,3,4};
    cout<<findDuplicate(nums)<<endl;
return 0;
}