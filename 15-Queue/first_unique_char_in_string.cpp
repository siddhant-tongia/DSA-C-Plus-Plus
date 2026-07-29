#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;

int firstUniqChar(string s) {
    unordered_map<char,int> m;
    queue<int> q;
    int ans = -1;
    for(int i=0 ; i<s.length() ; i++){
        if(m.find(s[i]) == m.end()){
            q.push(i);
        }
        m[s[i]]++;
        while(q.size() > 0 && m[s[q.front()]] > 1){
            q.pop();
        }
    }
    if(q.empty()){
        return -1;
    }else{
        return q.front();
    }
}

int main(){
    string s1 = "leetcode";
    cout << firstUniqChar(s1) << "\n";

    string s2 = "loveleetcode";
    cout << firstUniqChar(s2) << "\n";

    string s3 = "aabb";
    cout << firstUniqChar(s3) << "\n";
return 0;
}