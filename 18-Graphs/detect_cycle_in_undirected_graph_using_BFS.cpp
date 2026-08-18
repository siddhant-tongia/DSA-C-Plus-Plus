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

    bool isCycleUndirectedBFS(int src,vector<bool> &vis){
        queue<pair<int,int>> q;
        
        q.push({src,-1});
        vis[src] = true;

        while(q.size() > 0){
            int u = q.front().first;
            int par = q.front().second;
            q.pop();

            for(int v : l[u]){
                if(!vis[v]){
                    vis[v] = true;
                    q.push({v,u});
                }else{
                    if(v != par){
                        return true;
                    }
                }
            }
            
        }
        return false;
    }

    bool isCycle(){
        vector<bool> vis(V,false);
        for(int i=0 ; i<V ; i++){
            if(!vis[i]){
                if(isCycleUndirectedBFS(i,vis)){
                    return true;
                }
            }
        }
        return false;
    }
};
 
int main()
{
    Graph g(5);

    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,3);
    g.addEdge(2,4);

    int par = -1;
    cout << g.isCycle();

return 0;
}