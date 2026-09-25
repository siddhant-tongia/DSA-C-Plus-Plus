/*
 * Problem: Aggressive Cows (SPOJ AGGRCOW)
 * Description: Given an array of stall positions and an integer k (number of cows),
 * place k cows in the stalls such that the minimum distance between any two cows
 * is maximized. Return the largest possible minimum distance.
 * Example:
 * Input: stalls = [1, 2, 8, 4, 9], k = 3
 * Output: 3
 * Explanation: Sort stalls -> [1, 2, 4, 8, 9]. Place cows at positions 1, 4, 8.
 * Distances: (4-1)=3, (8-4)=4. Minimum distance = 3, which is the maximum possible.
 */
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool Ispossible(vector<int> &arr,int n,int c,int minallowed){
    if(c>n){
        return false;
    }
    int cow=1,lastStallposition=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]-lastStallposition>=minallowed){
            cow++;
            lastStallposition=arr[i];
        }
        if(cow==c){
            return true;
        }
    }
    return false ;
}
int getdistance(vector<int> &arr,int n,int c){
    sort(arr.begin(),arr.end());
    int st=1,end=arr[n-1]-arr[0],ans=-1;
    while(st<=end){
        int mid=st+(end-st)/2;
        if(Ispossible(arr,n,c,mid)){
            ans=mid;
            st=mid+1;
        }
        else{
            end=mid-1;
        }
    }
return ans;
}
 
int main()
{
    int n=5,c=3;
    vector<int>arr={1,2,8,4,9};
    cout<<getdistance(arr,n,c)<<endl;
    
return 0;
}