/*
 * Problem: 2D Array Input and Output
 * Description: Take input for a 2D matrix of dimensions row x col from the user
 * using nested loops and print the matrix in tabular format.
 * Example:
 * Input: row = 4, col = 3, elements = [matrix elements]
 * Output: Matrix printed row-by-row separated by tabs
 * Explanation: Nested loops iterate over rows and columns for input reading and output display.
 */
#include<iostream>
using namespace std;
int main(){
    int matrix[4][3];
    int row=4,col=3;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>matrix[i][j];
        }
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<matrix[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<endl;
return 0;
}