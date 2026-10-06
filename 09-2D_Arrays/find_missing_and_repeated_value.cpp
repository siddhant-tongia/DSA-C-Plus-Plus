/*
 * Problem: Find Missing and Repeated Values (LeetCode #2965)
 * Description: You are given a 0-indexed 2D integer matrix grid of size n * n with values
 * in the range [1, n^2]. Each integer appears exactly once except a which appears twice
 * and b which is missing. The task is to find the repeating and missing numbers a and b.
 * Return a 2D array [a, b] containing the repeated and the missing numbers.
 * Example:
 * Input: grid = [[1,3],[2,2]]
 * Output: [2,4]
 * Explanation: Number 2 is repeated and number 4 is missing so the answer is [2,4].
 */
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid){
    unordered_set<int> s;
    vector<int>ans;
    int m=grid.size();
    int n=grid[0].size();
    int sum=0,toatl_sum=0,result_sum;
    for(int i=1;i<=m*m;i++){
        toatl_sum+=i;
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(s.find(grid[i][j])!=s.end()){
                ans.push_back(grid[i][j]);
                break;
            }
            s.insert(grid[i][j]);
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            sum+=grid[i][j];
        }
    }
    result_sum=abs(sum-ans[0]-toatl_sum);
    ans.push_back(result_sum);
return ans;
}
int main()
{
    vector<vector<int>> grid={{1,2,3},{4,9,6},{7,8,9}};
    vector<int>answer=findMissingAndRepeatedValues(grid);
    cout<<"{"<<answer[0]<<","<<answer[1]<<"}"<<endl;
    
return 0;
}