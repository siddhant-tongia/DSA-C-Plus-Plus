#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int manDist(vector<vector<int>>& points,int p1,int p2){
    return (abs(points[p1][0] - points[p2][0]) + abs(points[p1][1] - points[p2][1])) ;
}

int minCostConnectPoints(vector<vector<int>>& points){
     int n = points.size();

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > pq;

    vector<bool> mstSet(n,false);
    int mstcost = 0;

    pq.push({0,0});

    while(pq.size() > 0){
        auto p = pq.top();
        int wt = p.first;
        int node = p.second;

        pq.pop();

        if(mstSet[node]) continue;

        mstSet[node] = true;
        mstcost += wt;

        for(int i=0 ; i<n ; i++){
            if(mstSet[i] == false){
                int edgewt = manDist(points,node,i);
                pq.push({edgewt,i});
            }
        }
    }
    return mstcost; 
}
 
int main() {
    vector<vector<int>> p = {{0,0}, {2,2}, {3,10}, {5,2}, {7,0}};
    cout << minCostConnectPoints(p);
    return 0;
}