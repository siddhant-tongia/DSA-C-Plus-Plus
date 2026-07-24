#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int trap(vector<int> &height){
    int n = height.size();
    int ans = 0;

    vector<int> lmax;
    vector<int> rmax;

    for(int i=1 ; i<n ; i++){
        lmax[i] = max(height[i],lmax[i-1]);
    }
    for(int i=n-2 ; i>=0 ; i--){
        rmax[i] = max(height[i],rmax[i+1]);
    }
    for(int i=0 ; i<n ; i++){
        ans += min(lmax[i],rmax[n-i-1]) - height[i];
    }
return ans;
}
int main()
{
    vector<int> boundaries = {4,2,0,3,2,5};
    int result = trap(boundaries);

    cout<<result;
return 0;
}