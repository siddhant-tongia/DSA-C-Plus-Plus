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
    }


    vector<int> topologicalsort(){

        vector<int> indegree(V,0);
        for(int i=0 ; i<V ; i++){
            for(int v:l[i]){
                indegree[v]++;
            }
        }
        
        queue<int> q;
        for(int i=0 ; i<V ; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        vector<int> ans;
        while(q.size() > 0){
            int u = q.front();
            q.pop();
            ans.push_back(u);

            for(int v : l[u]){
                indegree[v]--;

                if(indegree[v] == 0){
                    q.push(v);
                }
            }
        }

        return ans;
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
    g.addEdge(5,2);

    vector<int> res = g.topologicalsort();

    for(int val :res){
        cout << val << " ";
    }

return 0;
}