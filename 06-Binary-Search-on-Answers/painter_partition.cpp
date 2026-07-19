#include<iostream>
#include<vector>
using namespace std;
bool Isvalid(vector<int>&arr,int n,int m,int max_allocated){
    int worker =1;
    int board=0;
    for(int i=0;i<n;i++){
        if(arr[i]>max_allocated){
            return false;
        }
        if(board+arr[i]<=max_allocated){
            board+=arr[i];
        }
        else{
            board=arr[i];
            worker++;
        }
        if(worker>m){
            return false;
        }
    }
return true;
}
int min_time(vector<int>&arr,int n,int m){
    if(n < m) {
        return -1;
    }

    int sum=0,max_value=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        max_value=max(max_value,arr[i]);
    }
    int ans=-1;
    int st=max_value,end=sum;
    while(st<=end){
        int mid=st+(end-st)/2;
        if(Isvalid(arr,n,m,mid)){
            ans=mid;
            end=mid-1;
        }
        else{
            st=mid+1; 
        }
    }
return ans;
}
 
int main()
{
    vector<int>arr={40,30,10,20};
    int n=4, m=2;
    cout<<min_time(arr,n,m);
return 0;
}