#include<iostream>
#include<vector>
#include<list>
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

};

void component(vector<vector<char>>& grid,vector<vector<bool>> &vis,int i,int j,int n,int m){

    if(i < 0 || j < 0 || i >= n || j >= m || vis[i][j] || grid[i][j] == '0'){
        return;
    }
    vis[i][j] = true;

    component(grid,vis,i-1,j,n,m);
    component(grid,vis,i,j+1,n,m);
    component(grid,vis,i+1,j,n,m);
    component(grid,vis,i,j-1,n,m);
}

int numIslands(vector<vector<char>>& grid){
    int isIslands = 0;
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>> vis (n,vector<bool>(m,false));

    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if(grid[i][j] == '1' && !vis[i][j]){
                component(grid,vis,i,j,n,m);
                isIslands++;
            }
        }
    }
return isIslands;
}
 
int main(){
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };

    cout << "Number of Islands: " << numIslands(grid) << endl;
return 0;
}