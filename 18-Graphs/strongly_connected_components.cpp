#include<iostream>
#include<vector>
#include<stack>
#include<list>
using namespace std;

class Graph{
    list<int> *l;
    list<int> *rl;
    int V;

public:
    Graph(int V){
        this->V = V;
        l = new list<int> [V];
        rl = new list<int> [V];
    }

    void addEdge(int u, int v){
        l[u].push_back(v);
        rl[v].push_back(u);
    }

    void topologicalsort(int curr, vector<bool> &vis, stack<int> &s){
        vis[curr] = true;
    
        for(int v : l[curr]){
            if(!vis[v]){
                topologicalsort(v,vis,s);
            }
        }

        s.push(curr);
    }

    void dfs(int curr, vector<bool> &vis,vector<int> &result){

        vis[curr] = true;

        result.push_back(curr);
        for(int v : rl[curr]){
            if(!vis[v]){
                dfs(v,vis,result);
            }
        }
}

    vector<vector<int>> SCC(){
        vector<bool> vis(V,false);
        stack<int> s;

        for(int i=0 ; i<V ; i++){
            if(!vis[i]){
                topologicalsort(i,vis,s);
            }
        }
        vis.assign(V,false);
        vector<vector<int>> ans;
        
        while(s.size() > 0){
            int top = s.top();
            s.pop();
            if(!vis[top]){
                vector<int> result;
                dfs(top,vis,result);
                ans.push_back(result);
            }
        }
        return ans;
    }
};

 
int main(){
    Graph g(5);
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(3, 4);

    vector<vector<int>> ans = g.SCC();

    for(int i = 0; i < ans.size(); i++) {
        for(int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}