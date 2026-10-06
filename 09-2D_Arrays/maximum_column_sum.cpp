/*
 * Problem: Maximum Column Sum in 2D Matrix
 * Description: Given a 2D matrix of dimensions row x col, calculate the sum of elements
 * for each column and return the maximum sum among all columns.
 * Example:
 * Input: matrix = [[1, 2, 3],
 *                  [4, 5, 6],
 *                  [7, 8, 9],
 *                  [10, 11, 12]], row = 4, col = 3
 * Output: 30
 * Explanation: Column sums are col 0 = 22, col 1 = 26, col 2 = 30. Maximum is 30.
 */
#include<iostream>
#include<climits>

using namespace std;
int maximumcolumnsum(int matrix[4][3],int row,int column){
    int max_sum=INT_MIN;
    for(int i=0;i<column;i++){
        int sum=0;
        for(int j=0;j<row;j++){
            sum+=matrix[j][i];
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
    cout<<maximumcolumnsum(matrix,row,col)<<endl;
return 0;
}