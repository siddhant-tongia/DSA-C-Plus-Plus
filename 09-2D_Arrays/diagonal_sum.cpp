/*
 * Problem: Matrix Diagonal Sum (LeetCode #1572)
 * Description: Given a square matrix mat, return the sum of the matrix diagonals.
 * Only include the sum of all the elements on the primary diagonal and all the elements
 * on the secondary diagonal that are not part of the primary diagonal.
 * Example:
 * Input: mat = [[1,2,3],
 *               [4,5,6],
 *               [7,8,9]]
 * Output: 25
 * Explanation: Diagonals sum: 1 + 5 + 9 + 3 + 7 = 25. Notice that element mat[1][1] = 5
 * is counted only once.
 */
#include<iostream>
using namespace std;
int digonalsum(int matrix[3][3],int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=matrix[i][i]; // Primary Digonal
        if (i!=n-1-i){
            sum+=matrix[i][n-1-i]; // Secondary Digonal
        }
    }
return sum;
}
 
int main()
{
    int matrix[3][3];
    int n=3;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>matrix[i][j];
        }
    }
    cout<<digonalsum(matrix,n)<<endl;
return 0;
}