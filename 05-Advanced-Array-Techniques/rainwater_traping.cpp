/*
 * Problem: Trapping Rain Water
 * Description: Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
 * Example:
 * Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
 * Output: 6
 */

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