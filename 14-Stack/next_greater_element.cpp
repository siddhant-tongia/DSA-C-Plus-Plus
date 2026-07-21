#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> NGE(vector<int> &arr){

    int n = arr.size();
    vector<int> ans(n);
    stack<int> s;
    for(int i=n-1 ; i>=0 ; i--){

        while(!s.empty() && s.top()<=arr[i]){
            s.pop();
        }
        if(s.empty()){
            ans[i] = -1;            
        }else{
            ans[i] = s.top();
        }

        s.push(arr[i]);
    }
    return ans;
}
 
int main(){
    vector<int> arr = {6,8,0,1,3};
    vector<int> result;

    result = NGE(arr);

    for(int i=0 ; i<result.size() ; i++){
        cout << result[i] << " ";
    }
    cout << endl;

return 0;
}