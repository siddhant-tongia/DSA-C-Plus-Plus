#include<iostream>
#include<vector>
using namespace std;

int single(vector<int> &nums){
    int n = nums.size();
    int st = 0 , end = n-1;
    while(st <= end){
        int mid = st +(end-st)/2;

        if(mid==0 && nums[0]!=nums[1]) 
        {
            return nums[0];
        }
        if(mid==n-1 && nums[n-1]!=nums[n-2]) 
        {
            return nums[n-1];
        }

        if(nums[mid+1]!=nums[mid] && nums[mid-1] != nums[mid]){
            return nums[mid];
        }
        if (mid %2 == 0){
            if (nums[mid] == nums[mid+1]){
                st = mid+2;
            }else{
                end = mid-2;
            }
        }
        else{
            if (nums[mid] == nums[mid-1]){
                st = mid+1;
            }else{
                end = mid-1;
            }
        }
    }
        return -1;
}
 
int main()
{
    vector<int> nums_1={1,1,2,3,3,4,4,8,8};
    vector<int> nums_2={1,1,2,2,3,3,4,8,8};
    vector<int> nums_3={3,3,7,7,10,11,11};
    vector<int> nums_4={3,3,7,10,10,11,11};
    cout<<"The single number  :"<<single(nums_1)<<endl;
    cout<<"The single number  :"<<single(nums_2)<<endl;
    cout<<"The single number  :"<<single(nums_3)<<endl;
    cout<<"The single number  :"<<single(nums_4)<<endl;
    
return 0;
}