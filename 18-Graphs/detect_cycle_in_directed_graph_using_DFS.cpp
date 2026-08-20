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

    bool isCycledirectedDFS(int u, vector<bool> &vis, vector<bool> &pathvis){
        vis[u] = true;
        pathvis[u] = true;

        for(int v : l[u]){
            if(!vis[v]){
                if(isCycledirectedDFS(v,vis,pathvis)){
                    return true;
                }
            }else{
                if(pathvis[v]){
                    return true;
                }
            }
        }
        pathvis[u] = false;
        return false;
    }

    bool isCycle(){
        int src = 0; //src -> source node
        vector<bool> vis(V,false);
        vector<bool> pathvis(V,false);

        for(int i=0 ; i<V ; i++){
            if(!vis[i]){
                if(isCycledirectedDFS(i,vis,pathvis)){
                    return true;
                }
            }
        }
        return false;
    }
};
 
int main()
{
    Graph g(4);

    g.addEdge(1,0);
    g.addEdge(0,2);
    g.addEdge(2,3);
    g.addEdge(3,0);

    cout<< g.isCycle();
return 0;
}