#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool isValid(string &substr){
    int length = substr.size();
    for(int i=0 ; i<length/2 ; i++){
        if(substr[i] != substr[length-i-1]){
            return false;
        }
    }
return true;
}

void solve(string &s, int idx, vector<string> &path, vector<vector<string>> &ans){

    if(idx == s.size()){
        ans.push_back(path);
        return;
    }
        for(int i=idx ; i < s.length() ; i++){
            string slice = s.substr(idx,i-idx+1);

            if(isValid(slice)){
                path.push_back(slice);
                solve(s,i+1,path,ans);
                path.pop_back();
            }
        }
    }
 
int main() {
    string s = "aab";
    vector<vector<string>>ans;
    vector<string>path;

    solve(s,0,path,ans);

    cout << "[";
    for (int i = 0; i < ans.size(); i++){
        cout << "[";
        for (int j = 0; j < ans[i].size(); j++){
            cout << "\"" << ans[i][j] << "\"";
            if (j < ans[i].size() - 1) cout << ", ";
        }
        cout << "]";
    }
    cout << "]" << endl;
return 0;
}