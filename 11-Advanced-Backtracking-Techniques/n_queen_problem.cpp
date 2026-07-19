#include<iostream>
#include<vector>
using namespace std;

bool isSafe(vector<string> &grid, int n ,int row , int col){
    for(int i=0 ; i<n ; i++){
        if(grid[row][i] == 'Q'){
            return false;
        }
    }
    for(int i=row ; i>=0 ; i--){
        if(grid[i][col] == 'Q'){
            return false;
        }
    }
    for(int i = row, j = col; i>=0 && j>=0 ; i--,j--){
        if(grid[i][j] == 'Q'){
            return false;
        }
    }
    for(int i = row, j = col; i>=0 && j<n ; i--,j++){
        if(grid[i][j] == 'Q'){
            return false;
        }
    }
return true;
}

void result(vector<string> &grid , int n ,int row, vector<vector<string>> &ans){
    if(row == n){
        ans.push_back(grid);
        return;
    }
    for(int col=0 ; col<n ; col++){
        if(isSafe(grid,n,row,col)){
            grid[row][col] = 'Q';
            result(grid,n,row+1,ans);
            grid[row][col] = '.';
        }
    }
}
 
int main()
{
    int n = 4;
    vector<vector<string>> ans;
    vector<string> grid(n, string(n, '.'));

    result(grid, n, 0, ans);

    for (int i = 0; i < ans.size(); i++) {
        for (int row = 0; row < n; row++) {
            cout << ans[i][row] << "    " << endl;
        }
        cout << "--------\n";
    }

    return 0;
}