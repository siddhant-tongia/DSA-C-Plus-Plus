#include<iostream>
using namespace std;
bool Palindrome(string str){
    string new_str;
    for(int i=0;i<str.length();i++){
        if(isalnum(str[i])){
            new_str+=toupper(str[i]);
        }
    }    
    int n=new_str.length();
    for(int i=0;i<n/2;i++){
        if(new_str[i]!=new_str[n-i-1]){
            return false;
        }
    }
    return true;
}
 
int main()
{
    string str="Ac3?e3c&a";
    cout<<Palindrome(str);
return 0;
}