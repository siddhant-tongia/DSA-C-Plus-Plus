
#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k){
    vector<vector<pair<int,int>>> graph(n);

    for(int i=0 ; i<flights.size() ; i++){
        int u = flights[i][0];
        int v = flights[i][1];
        int wt = flights[i][2];

        graph[u].push_back({v,wt});
    }

    queue<pair<int,pair<int,int>>> q; // src,cost,k
    vector<int> dist(n,INT_MAX);

    dist[src] = 0;
    q.push({src,{0,-1}});

    while(q.size() > 0){

        auto p = q.front();
        q.pop();

        int u = p.first;
        int cost = p.second.first;
        int stops = p.second.second;

        for(auto neigh : graph[u]){
            int v = neigh.first;
            int wt = neigh.second;
            if(dist[v] > cost + wt && stops+1 <= k){
                dist[v] = cost + wt;
                q.push({v,{dist[v],stops+1}});
            }
        }
    }

    if(dist[dst] == INT_MAX){
        return -1;
    }else{
        return dist[dst];
    }
}

int main(){
    int n = 4;
    vector<vector<int>> flights = {{0,1,100},{1,2,100},{2,0,100},{1,3,600},{2,3,200}};
    int src = 0;
    int dst = 3;
    int k = 1;

    cout << findCheapestPrice(n, flights, src, dst, k);

    return 0;
}