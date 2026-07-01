#include<iostream>
#include<vector>
using namespace std;

bool isValid(int row, int col, vector<vector<int>> &maze,int n, vector<vector<bool>> &visited){
    if((row >= 0 && row < n) && (col >= 0 && col < n) && (maze[row][col] == 1 )&& (visited[row][col] == false)){
        return true;
    }
return false;
}

void solve(int row, int col, vector<vector<int>> &maze,int n, vector<vector<bool>> &visited, string path, vector<string> &ans){
    if(row == n-1 && col == n-1){
        ans.push_back(path);
        return;
    }

    visited[row][col] = true;
    if(isValid(row+1,col,maze,n,visited)){
        solve(row+1,col,maze,n,visited,path + "D",ans);
    }
    if(isValid(row,col+1,maze,n,visited)){
        solve(row,col+1,maze,n,visited,path + "R",ans);
    }
    if(isValid(row-1,col,maze,n,visited)){
        solve(row-1,col,maze,n,visited,path + "U",ans);
    }
    if(isValid(row,col-1,maze,n,visited)){
        solve(row,col-1,maze,n,visited,path + "L",ans);
    }
    visited[row][col] = false;
}

int main() {
    int n = 4;
    
    // 1 = Path, 0 = Wall
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };

    vector<vector<bool>> visited(n, vector<bool>(n, false));
    vector<string> ans;
    if (maze[0][0] == 1){
        solve(0, 0, maze, n, visited, "", ans);
    }
    else{
        return 0;
    }
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << endl;
    }

    return 0;
}