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

    void helper(int src, vector<bool> &vis, stack<int> &s){
        vis[src] = true;

        for(int v:l[src]){
            if(!vis[v]){
                helper(v,vis,s);
            }
        }
        s.push(src);
    }

    void courseSchedule(vector<int> &ans){
        vector<bool> vis(V,false);
        stack<int> s;
        
        for(int i=0 ; i<V ; i++){
            if(!vis[i]){
                helper(i,vis,s);
            }
        }
        
        while(s.size() > 0){
            ans.push_back(s.top());
            s.pop();
        }
    }
};

int main(){
    Graph g(4);
    
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(2,1);
    
    vector<int> ans;
    g.courseSchedule(ans);

    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }

return 0;
}