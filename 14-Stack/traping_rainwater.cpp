#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int trap(vector<int>& height){
    int ans = 0;
    int current = 0;
    stack<int> s;
    
    while (current < height.size()){
        while (!s.empty() && height[current] > height[s.top()]){
            int top = s.top();
            s.pop();
            
            if (s.empty()){
                break;
            }

            int distance = current - s.top() - 1;      
            int bounded_height = min(height[current], height[s.top()]) - height[top];
            
            ans += distance*bounded_height;
        }
        s.push(current);
        current++;
    }
return ans;
}

int main(){
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1}; 
    int total_water = trap(height); 
    cout << total_water;
return 0;
}