#include<iostream>
#include<vector>
#include<utility>
using namespace std;
pair<int,int> searchMatrix(vector<vector<int>>&matrix,int target){
    int row=0;
    int col=matrix[0].size()-1;
    while(row<matrix.size() && col>=0){
        if(matrix[row][col]==target){
            return {row,col};
        }
        else if(matrix[row][col]<target){
            row++;
        }
        else{
            col--;
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