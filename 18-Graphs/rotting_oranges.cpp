#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

class Graph{
int V;
list<int> *l; 
// int *arr;

public:
    Graph(int V){
        this->V = V;
        l = new list<int> [V];
        //arr = new int [V];
    }

    void addEdge(int u, int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void helper(vector<vector<int>> &grid, vector<vector<bool>> &vis,int &ans,int n, int m){
        
        queue<pair<pair<int,int>,int>> q;

        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                }
            }
        }
        while(q.size() > 0){
            int i = q.front().first.first;
            int j = q.front().first.second;
            int time = q.front().second;
            q.pop();
            ans = max(ans,time);
            
            if(i-1 >= 0 && !vis[i-1][j] && grid[i-1][j] == 1){
                q.push({{i-1,j},time+1});
                grid[i-1][j] = 2;
                vis[i-1][j] = true;
            }
            if(i+1 < n && !vis[i+1][j] && grid[i+1][j] == 1){
                q.push({{i+1,j},time+1});
                grid[i+1][j] = 2;
                vis[i+1][j] = true;
            }
            if(j-1 >= 0 && !vis[i][j-1] && grid[i][j-1] == 1){
                q.push({{i,j-1},time+1});
                grid[i][j-1] = 2;
                vis[i][j-1] = true;
            }
            if(j+1 < m && !vis[i][j+1] && grid[i][j+1] == 1){
                q.push({{i,j+1},time+1});
                grid[i][j+1] = 2;
                vis[i][j+1] = true;
            }
        }
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(grid[i][j] == 1){
                    ans = -1;
                    return;
                }
            }
        }
    return;
    }

    int orangesRotting(vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        int ans = 0;
        helper(grid,vis,ans,n,m);
        return ans;
    }
};
 
int main(){
    Graph g(1);
    vector<vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };
    cout << g.orangesRotting(grid);
    return 0;
}