#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int largestRectangleArea(vector<int>& heights){
    int n = heights.size();
    stack<int> sr;
    vector<int> rightSmaller(n,n);
    for(int i=n-1 ; i>=0 ; i--){
        while(!sr.empty() && heights[sr.top()] >= heights[i]){
            sr.pop();
        }

        if(!sr.empty()){
            rightSmaller[i] = sr.top();
        }
        sr.push(i);
    }
    
    stack<int> sl;
    vector<int> leftSmaller(n,-1);
    for(int i=0 ; i<n ; i++){
        while(!sl.empty() && heights[sl.top()] >= heights[i]){
            sl.pop();
        }

        if(!sl.empty()){
            leftSmaller[i] = sl.top();
        }
        sl.push(i);
    }
    
    vector<int> width(n);
    for(int i=0 ; i<heights.size() ; i++){
        width[i] = rightSmaller[i] - leftSmaller[i] - 1;
    }

    int ans = 0;
    for(int i=0 ; i<heights.size() ; i++){
        int curr_area = heights[i] * width[i];
        ans = max(curr_area,ans);
    }
return ans;
}

int main(){
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    int max_area = largestRectangleArea(heights);
    cout << "Largest Rectangle Area: " << max_area << endl;
return 0;
}