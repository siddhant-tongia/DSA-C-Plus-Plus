#include<iostream>
#include<vector>
using namespace std;

bool isValid(vector<int> &nums,int n , int m , int maxAllocation){
    int pages = 0 ,student = 1;
    for(int i=0 ; i<n ; i++){
        if(nums[i] > maxAllocation){
            return false;
        }
        if(nums[i] + pages <= maxAllocation){
            pages += nums[i];
        }
        else{
            pages = nums[i];
            student++;
        }
    }
    if(student <= m){
        return true;
    }else{
        return false;
    }
}

int solution(vector<int> &nums,int n ,int m){
    if(n<m){
        return -1;
    }
    int sum = 0;
    for(int i=0 ; i<n ;i++){
        sum += nums[i];
    }
    int st = 0 , end = sum;
    int ans = -1;
    while(st <= end){
        int mid = st + (end-st)/2;
        if(isValid(nums,n,m,mid)){
            ans = mid;
            end = mid-1;
        }else{
            st = mid+1;
        }
    }
return ans;
}


 
int main()
{
    vector<int>vec={2,1,3,4};
    int n=vec.size(),m=2;
    cout<<solution(vec,n,m);
return 0;
}