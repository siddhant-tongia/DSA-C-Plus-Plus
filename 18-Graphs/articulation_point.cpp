#include<iostream>
#include<vector>
#include<climits>
#include<set>
using namespace std;

class Graph{
public:
    int time;
    vector<int> dt,low;
    vector<vector<int>> adj;
    int V;

    Graph(int V){
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    void dfs(int u, int parU, set<int> &criticalPoints){
        dt[u] = low[u] = ++time;
        int children = 0;

        for(int i=0 ; i<adj[u].size() ; i++){
            int v = adj[u][i];
            if(dt[v] == -1){
                children++;
                dfs(v,u,criticalPoints);
                low[u] = min(low[u],low[v]);

                if(parU != -1 && low[v] >= dt[u]){
                    criticalPoints.insert(u);
                }
            }else if(v != parU){
                low[u] = min(low[u],dt[v]);
            }
        }

        if(parU == -1 && children > 1){
            criticalPoints.insert(u);
        }
    }
    
    int articulationPoints(){
        time = 0;
        dt.assign(V,-1);
        low.assign(V,0);

        set<int> criticalPoints;

        for(int i=0 ; i<V ; i++){
            if(dt[i] == -1){
                dfs(i,-1,criticalPoints);
            }
        }

        return criticalPoints.size();
    }
};
 
int main()
{
    Graph graph(6);

    graph.addEdge(0,1);
    graph.addEdge(1,2);
    graph.addEdge(4,3);
    graph.addEdge(4,5);
    graph.addEdge(4,1);

    cout << graph.articulationPoints() << endl;
return 0;
}