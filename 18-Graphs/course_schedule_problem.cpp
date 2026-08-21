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
    }

    bool isCycleDFS(int src, vector<bool> &vis, vector<bool> &pathvis){
        vis[src] = true;
        pathvis[src] = true;

        for(int v : l[src]){
            if(!vis[v]){
                if(isCycleDFS(v,vis,pathvis)){
                    return true;
                }
            }else{
                if(pathvis[v]){
                    return true;
                }
            }
        }
        pathvis[src] = false;
        return false;
    }

    bool canFinish(){
        int src = 0; //src -> source node
        vector<bool> vis(V,false);                                
        vector<bool> pathvis(V,false);

        for(int i=0 ; i<V ; i++){
            if(!vis[i]){
                if(isCycleDFS(i,vis,pathvis)){
                    return false;
                }
            }
        }
        return true;
    }
};
 
int main()
{
    Graph g(4);

    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(2,1);

    cout << g.canFinish();

return 0;
}