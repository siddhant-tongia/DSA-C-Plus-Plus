#include<iostream>
#include<vector>
#include<set>

using namespace std;

int find(int x, vector<int> &par, vector<int> &rank){
    if(x == par[x]){
    return x;
    }   
return par[x] = find(par[x], par, rank);
}

void unionByRank(int a, int b, vector<int> &par, vector<int> &rank){

    int parA = find(a, par, rank);
    int parB = find(b, par, rank);

    if(parA == parB){
        return;
    }

    if(rank[parA] == rank[parB]){
        par[parB] = parA;
        rank[parA]++;
    }else if(rank[parA] > rank[parB]){
        par[parB] = parA;
    }else{
        par[parA] = parB;
    }
}

int findCircleNum(vector<vector<int>>& isConnected){
    int n = isConnected.size();
    vector<int> par,rank;
    for(int i=0; i<n; i++){
        par.push_back(i);
        rank.push_back(0);
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(isConnected[i][j] == 1){
            unionByRank(i, j, par, rank);
            }
        }
    }

    set<int> s = {};

    for(int p: par){
        s.insert(find(p, par, rank));
    }
    return s.size();
    }

 
int main(){
    vector<vector<int>> v = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    };
    
    cout << findCircleNum(v) << "\n";
return 0;
}