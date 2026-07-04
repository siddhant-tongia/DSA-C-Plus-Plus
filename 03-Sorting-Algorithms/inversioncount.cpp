#include<iostream>
#include<vector>
using namespace std;

int merge(int st, int mid, int end, vector<int> &arr){
    int invcount = 0;
    vector<int> temp(end-st+1);
    int idx = 0;
    int i = st, j = mid+1;
    while(i <= mid && j <= end){
        if(arr[i] <= arr[j]){
            temp[idx++] = arr[i++];
        }else{
            temp[idx++] = arr[j++];
            invcount += (mid-i+1);
        }
    }
    while(i <= mid){
        temp[idx++] = arr[i++];
    }
    while(j <= end){
        temp[idx++] = arr[j++];
    }
    for(int k=st ; k<=end ; k++){
        arr[k] = temp[k-st];
    }
return invcount;
}

int mergesort(vector<int> &nums, int st, int end){
    int n = nums.size();
    if(st >= end){
        return 0;
    }
        int mid = st+(end-st)/2;
        int leftinvcount = mergesort(nums,st,mid);
        int rightinvcount = mergesort(nums,mid+1,end);

        int invcount = merge(st,mid,end,nums);

return (invcount + rightinvcount + leftinvcount);
}
 
int main() {
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};
    int n = arr.size();

    int InvCount = mergesort(arr, 0, n-1);
    cout<<(InvCount);
    return 0;
}