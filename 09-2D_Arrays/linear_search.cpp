/*
 * Problem: Linear Search in 2D Array
 * Description: Given a 2D matrix of dimensions row x col and a target value key, search for
 * the key by scanning elements row by row. If found, return its {row, col} indices,
 * otherwise return {-1, -1}.
 * Example:
 * Input: matrix = [[1, 2, 3], [4, 5, 6], [7, 8, 9], [10, 11, 12]], key = 9
 * Output: {2, 2}
 * Explanation: Key 9 is located at row index 2 and column index 2.
 */
#include<iostream>
#include<utility>
using namespace std;
pair<int,int> cell(int matrix[4][3],int key,int row,int column){
    for(int i=0;i<4;i++){
        for(int j=0;j<3;j++){
            if(matrix[i][j]==key){
                return {i,j};
            }
        }
    }
return {-1,-1};
}
int main(){
    int matrix[4][3];
    int row=4,col=3,key=9;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>matrix[i][j];
        }
    }
    pair<int,int> ans = cell(matrix, key, row, col);
    int x = ans.first;
    int y = ans.second;
    
    if(x==-1){
        cout<<"Not found"<<endl;
    }
    else{
        cout<<x<<y<<endl;
    }
return 0;
}