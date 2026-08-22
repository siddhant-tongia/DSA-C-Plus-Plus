#include<iostream>
#include<vector>
using namespace std;

    void helper(vector<vector<int>>& grid, int i, int j, int color,vector<vector<bool>> &vis,int n, int m, int val){
        if(i-1 >= 0 && !vis[i-1][j] && grid[i-1][j] == val){
            grid[i-1][j] = color;
            vis[i-1][j] = true;
            helper(grid,i-1,j,color,vis,n,m,val);
        }
        if(i+1 < n && !vis[i+1][j] && grid[i+1][j] == val){
            grid[i+1][j] = color;
            vis[i+1][j] = true;
            helper(grid,i+1,j,color,vis,n,m,val);
        }
        if(j-1 >= 0 && !vis[i][j-1] && grid[i][j-1] == val){
            grid[i][j-1] = color;
            vis[i][j-1] = true;
            helper(grid,i,j-1,color,vis,n,m,val);
        }
        if(j+1 < m && !vis[i][j+1] && grid[i][j+1] == val){
            grid[i][j+1] = color;
            vis[i][j+1] = true;
            helper(grid,i,j+1,color,vis,n,m,val);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color){
        int n = image.size();
        int m = image[0].size();

        int val = image[sr][sc];
        vector<vector<bool>> vis(n,vector<bool>(m,false));

        image[sr][sc] = color;
        vis[sr][sc] = true;

        helper(image,sr,sc,color,vis,n,m,val);

    return image;
    }
 
int main()
{
    vector<vector<int>> image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };
    
    int sr = 1;
    int sc = 1;
    int color = 2;

    vector<vector<int>> ans = floodFill(image, sr, sc, color);

    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[0].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
return 0;
}