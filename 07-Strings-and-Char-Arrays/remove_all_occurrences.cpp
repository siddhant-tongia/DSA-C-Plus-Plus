/*
 * Problem: Remove All Occurrences of a Substring
 * Description: Given two strings s and part, perform the following operation on s until all occurrences of the substring part are removed: Find the leftmost occurrence of the substring part and remove it from s. Return s after removing all occurrences of part.
 * Example:
 * Input: s = "daabcbaabcbc", part = "abc"
 * Output: "dab"
 */
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