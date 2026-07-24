/*#include<iostream>
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
} */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int trap(vector<int>& height){
    int ans = 0;
    int n = height.size();

    int l = 0 , r = n-1;

    int lmax = 0;
    int rmax = 0;

    while(l < r){
        lmax = max(lmax,height[l]);
        rmax = max(rmax,height[r]);

        if(lmax < rmax){
            ans += lmax - height[l];
            l++;
        }else{
            ans += rmax - height[r];
            r--;
        }
    }
return ans;
}

int main(){
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int total_water = trap(height);
    cout << total_water;
return 0;
}