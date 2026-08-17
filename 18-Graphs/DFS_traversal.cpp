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

    void DFShelper(int u, vector<int> &vis){
        cout << u << " ";
        vis[u] = true;

        for(int v : l[u]){
            if(!vis[v]){
                DFShelper(v,vis);
            }
        }
    }

    void DFS(){
        int src = 0; //src -> source node
        vector<int> vis(V,false);

        DFShelper(src,vis);
        cout << endl;
    }
};
 
int main()
{
    Graph g(5);

    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,4);

    g.DFS();

return 0;
}