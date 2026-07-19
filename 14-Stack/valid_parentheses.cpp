#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isValid(string s){
    int l = s.length();
    stack<char> st;
    for(int i=0 ; i<l ;i++){
        if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
            st.push(s[i]);
        }else{
            if(st.empty()){
                return false;
            }
           char top = st.top();
            if((top == '(' && s[i] == ')')|| 
               (top == '[' && s[i] == ']')|| 
               (top == '{' && s[i] == '}')){
                st.pop();
            }else{
                return false;
            }
        }
    }
return st.empty();
}

int main(){
    string s = "()[]{}";
    
    if(isValid(s)){
        cout << "true\n";
    }else{
        cout << "false\n";
    }
    return 0;
}