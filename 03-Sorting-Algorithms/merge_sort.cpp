/*
 * Problem: Merge Sort
 * Description: Implement Merge Sort to sort an array of integers in ascending order.
 * Merge sort is a divide and conquer algorithm that divides the array into two halves, sorts them, and then merges the sorted halves.
 * Example:
 * Input: arr = [38, 27, 43, 3, 9, 82, 10]
 * Output: [3, 9, 10, 27, 38, 43, 82]
 */
#include<iostream>
#include<vector>
using namespace std;

void merge(int st, int mid, int end, vector<int> &arr){
    vector<int> temp(end-st+1);
    int idx = 0;
    int i = st, j = mid+1;
    while(i <= mid && j <= end){
        if(arr[i] >= arr[j]){
            temp[idx++] = arr[j++];
        }else{
            temp[idx++] = arr[i++];
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
}

void mergesort(vector<int> &nums, int st, int end){
    int n = nums.size();
    if(st >= end){
        return;
    }
        int mid = st+(end-st)/2;
        mergesort(nums,st,mid);
        mergesort(nums,mid+1,end);

        merge(st,mid,end,nums);
}
 
int main() {
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};
    int n = arr.size();

    mergesort(arr, 0, n-1);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}