#include<iostream>
using namespace std;
string removeoccurrences(string str,string substr){
    int length=substr.length();

    while(str.length()>0 && str.find(substr)<str.length()){
        int idx=str.find(substr);
        str.erase(idx,length);
    }
    return str;
}
 
int main()
{
    string str="daabcbaabcbc";
    string substr="abc";
    cout<<removeoccurrences(str,substr);
return 0;
}