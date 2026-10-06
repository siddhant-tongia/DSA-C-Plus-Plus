/*
 * Problem: Maximum Row Sum in 2D Matrix (LeetCode #1672 - Richest Customer Wealth)
 * Description: Given a 2D matrix of dimensions row x col, calculate the sum of elements
 * for each row and return the maximum sum among all rows.
 * Example:
 * Input: matrix = [[1, 2, 3],
 *                  [4, 5, 6],
 *                  [7, 8, 9],
 *                  [10, 11, 12]], row = 4, col = 3
 * Output: 33
 * Explanation: Row sums are row 0 = 6, row 1 = 15, row 2 = 24, row 3 = 33. Maximum is 33.
 */
#include<iostream>
#include<climits>

using namespace std;
int maximumrowsum(int matrix[4][3],int row,int column){
    int max_sum = INT_MIN;
    for(int i=0;i<row;i++){
        int sum=0;
        for(int j=0;j<column;j++){
            sum+=matrix[i][j];
        }
        max_sum=max(max_sum,sum);
    }
return max_sum;
}
 
int main()
{
     int matrix[4][3];
    int row=4,col=3;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>matrix[i][j];
        }
    }
    cout<<maximumrowsum(matrix,row,col)<<endl;
return 0;
}