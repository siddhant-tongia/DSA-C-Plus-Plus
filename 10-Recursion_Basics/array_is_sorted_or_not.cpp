#include<iostream>
#include<vector>
using namespace std;
bool ArrayIsSortedOrNot(vector<int> &arr , int n){
    if(n==0 || n==1){
        return true;
    }
    return arr[n-1] >= arr[n-2] && ArrayIsSortedOrNot(arr,n-1);
}
 
int main()
{
    vector<int> nums={1,2,3,4,5};
    int n=nums.size();
    cout<<ArrayIsSortedOrNot(nums,n);
return 0;
}