#include<iostream>
#include<vector>
#include<list>
#include<stack>
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

    void helper(int u, vector<bool> &vis,stack<int> &topologicalorder){
        vis[u] = true;

        for(int v : l[u]){
            if(!vis[v]){
                helper(v,vis,topologicalorder);
            }
        }
        topologicalorder.push(u);
    }

    void topologicalsort(){
        vector<bool> vis(V,false);
        stack<int> s;

        for(int i=0 ; i<V ; i++){
            if(!vis[i]){
                helper(i,vis,s);
            }
        }

        while(s.size() > 0){
            cout << s.top() << " ";
            s.pop();
        }
    }
};
 
int main()
{
    Graph g(6);

    g.addEdge(3,1);
    g.addEdge(2,3);
    g.addEdge(4,0);
    g.addEdge(4,1);
    g.addEdge(5,0);
    g.addEdge(5,3);

    g.topologicalsort();

return 0;
}