#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Edge{
public:
    int u;
    int v;
    int wt;

    Edge(int u,int v,int wt){
        this->u = u;
        this->v = v;
        this->wt = wt;
    }

    bool operator<(const Edge &other) const{
        return this->wt < other.wt; 
    }
};

class Graph{
public:
    int V;
    vector<Edge> edges;
    vector<int> par,rank;

    Graph(int V){
        this->V = V;

        for(int i=0 ; i<V ; i++){
            par.push_back(i);
            rank.push_back(0);
        }
    }

    void addEdges(int u, int v, int wt){
        edges.push_back(Edge(u,v,wt));
    }

    int find(int x){
        if(par[x] == x){
            return x;
        }

        return par[x] = find(par[x]);
    }

    void unionByRank(int a, int b){
        int parA = find(a);
        int parB = find(b);

        if(parA == parB){
            return;
        }

        if(rank[parA] == rank[parB]){
            par[parB] = parA;
            rank[parA] ++;
        }else if(rank[parA] > rank[parB]){
            par[parB] = parA;
        }else{
            par[parA] = parB;
        }
    }

    void kruskal(){
        sort(edges.begin(),edges.end());
        int mstcost = 0;

        for(int i=0 ; i<V ; i++){
            Edge e = edges[i];
            
            int parU = find(e.u);
            int parV = find(e.v);

            if(parU != parV){
                unionByRank(e.u,e.v);
                mstcost += e.wt;
            }
        }
        cout << mstcost << endl;
    }
};
int main(){
    Graph graph(4);

    graph.addEdges(0,1,10);
    graph.addEdges(0,2,6);
    graph.addEdges(0,3,5);
    graph.addEdges(1,3,15);
    graph.addEdges(2,3,4);

    graph.kruskal();
return 0;
}