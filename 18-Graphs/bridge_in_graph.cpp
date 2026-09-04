#include<iostream>
#include<vector>
using namespace std;

int time;
vector<int> dt,low;

void dfs(int u, int parU, vector<vector<int>> &adj, vector<vector<int>> &bridges){
    dt[u] = low[u] = ++time;

    for(int i=0 ; i<adj[u].size() ; i++){
        int v = adj[u][i];
        if(dt[v] == -1){
            dfs(v,u,adj,bridges);
            low[u] = min(low[u],low[v]);

            if(low[v] > dt[u]){
                bridges.push_back({u,v});
            }
        }else{
            if(v != parU){
                low[u] = min(dt[v],low[u]);
            }
        }
    }

}

vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
    vector<vector<int>> adj(n);
    for(int i=0 ; i<connections.size() ; i++){
        int u = connections[i][0];
        int v = connections[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    time = 0;
    dt.resize(n,-1);
    low.resize(n);
    vector<vector<int>> bridges;

    for(int i=0 ; i<n ; i++){
        if(dt[i] == -1){
            dfs(i,-1,adj,bridges);
        }
    }

    return bridges;
}

int main(){
    int n = 4;
    vector<vector<int>> connections = {{0, 1}, {1, 2}, {2, 0}, {1, 3}};

    vector<vector<int>> result = criticalConnections(n, connections);
    
    for(int i = 0; i < result.size(); i++) {
        cout << result[i][0] << " " << result[i][1] << "\n";
    }
    return 0;
}