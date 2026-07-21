// span -> Maximum number of consecutive days from today were price is <= today's price.

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> span(vector<int> &price){

    int n = price.size();
    vector<int> ans(n);
    stack<int> s;

    s.push(0);
    ans[0] = 1;
    for(int i=1 ; i<n ; i++){

        while (!s.empty() && price[s.top()] <= price[i]){
            s.pop();
        }

        if(s.empty()){
            ans[i] = i+1;
        }else{
            ans[i] = i-s.top();
        }
        s.push(i);
    }
return ans;
}
 
int main(){

    vector<int> price = {100, 80, 60, 70, 60, 75, 85};
    vector<int> result;

    result = span(price);

    for(int i=0 ; i<result.size() ; i++){
        cout << result[i] << " ";
    }
    cout << endl;

return 0;
}