/*
 * Problem: Search a 2D Matrix (LeetCode #74 / #240 - Search a 2D Matrix II)
 * Description: Write an efficient algorithm that searches for a target value in an m x n
 * integer matrix where each row is sorted in ascending order and each column is sorted
 * in ascending order. Return the row and column indices {row, col} if found, else {-1, -1}.
 * Uses the staircase search approach starting from the top-right corner.
 * Example:
 * Input: matrix = [[1, 3, 5, 7],
 *                  [10, 11, 16, 20],
 *                  [23, 30, 34, 60]], target = 34
 * Output: {2, 2}
 * Explanation: 34 is located at row index 2 and column index 2.
 */
#include<iostream>
#include<vector>
#include<utility>
using namespace std;
pair<int,int> searchMatrix(vector<vector<int>>&matrix,int target){
    int n = matrix.size() , m = matrix[0].size();

    int low = 0;
    int high = n*m - 1;

    if (matrix.empty() || matrix[0].empty()) {
        return {-1, -1};
    }

    while(low <= high){
        int mid = low + (high-low)/2;

        int row = mid / m;
        int col = mid % m;

        int val = matrix[row][col];

        if(val == target){
            return {row,col};
        }else if(val < target){
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
    return {-1,-1};
}
 
int main()
{
    vector<vector<int>> matrix={{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target=34;
    pair<int,int> ans=searchMatrix(matrix,target);
    cout<< "{"<<ans.first<<","<<ans.second<<"}"<<endl;
return 0;
}