#include<iostream>
#include<vector>
using namespace std;
vector<int> spiralorder(vector<vector<int>>& matrix){
   
    int m=matrix.size();
    int n=matrix[0].size();
    vector<int> ans;
    int srow=0,erow=m-1;
    int scol=0,ecol=n-1;
    while(srow<=erow && scol<=ecol){
        for(int i=scol;i<=ecol;i++){
            ans.push_back(matrix[srow][i]);
        }
        for(int i=srow+1;i<=erow;i++){
            ans.push_back(matrix[i][ecol]);
        }
        if(srow<erow){
            for(int i=ecol-1;i>=scol;i--){
                ans.push_back(matrix[erow][i]);
            }
        }
        if(scol<ecol){
            for(int i=erow-1;i>srow;i--){
                ans.push_back(matrix[i][scol]);
            }
        }
        srow++;erow--;scol++;ecol--;
    }
return ans;
}
 
int main()
{
    vector<vector<int>> matrix={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    vector<int>result=spiralorder(matrix);
    for(int val : result){
        cout<<val<<"\t";
    }
return 0;
}