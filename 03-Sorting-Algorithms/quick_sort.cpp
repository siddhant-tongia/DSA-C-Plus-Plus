/*
 * Problem: Quick Sort
 * Description: Implement Quick Sort to sort an array of integers in ascending order.
 * Quick sort is a divide and conquer algorithm that picks an element as pivot and partitions the given array around the picked pivot.
 * Example:
 * Input: arr = [4, 6, 2, 5, 7, 9, 1, 3]
 * Output: [1, 2, 3, 4, 5, 6, 7, 9]
 */
#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int> &nums, int st, int end){
    int piv = nums[end];
    int j = 0;
    int idx = st - 1;
    for(int j=st ; j<end ; j++){
        if(nums[j] <= piv){
            idx++;
            swap(nums[idx],nums[j]);
        }
    }
    idx++;
    swap(nums[idx],nums[end]);
return idx;
}

void quicksort(vector<int> &nums, int st, int end){

    if(st >= end){
        return;
    }
    if(st < end){
        int pividx = partition(nums,st,end);

        quicksort(nums,st,pividx-1);
        quicksort(nums,pividx+1,end);
    }
}
 
int main() {
    vector<int> arr = {4, 6, 2, 5, 7, 9, 1, 3};
    int n = arr.size();

    quicksort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}