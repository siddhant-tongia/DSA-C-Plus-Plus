#include<iostream>
using namespace std;
string Reverse(string str){
    int i=0,j=str.length()-1;
    char temp;
    while(i<j){  // reverse(str.begin(),str.end());  This can be used .
        swap(str[i],str[j]);   
        i++;
        j--;
    }
return str;
}
 
int main()
{
    string str;
    getline(cin,str);
    cout<<Reverse(str);
return 0;
}