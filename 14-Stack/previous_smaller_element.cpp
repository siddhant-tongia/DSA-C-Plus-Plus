#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> PSE(vector<int> &arr){

    vector<int> ans(arr.size());
    stack<int> s;
    for(int i=0 ; i<arr.size() ; i++){
        while(!s.empty() && s.top() >= arr[i]){
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

    vector<int> arr = {3,1,0,8,6};
    vector<int> result = PSE(arr);

    for(int i=0 ; i<result.size() ; i++){
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}