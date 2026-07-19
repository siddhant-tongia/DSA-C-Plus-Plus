#include<iostream>
using namespace std;
bool isfreqsame(int freq1[26],int freq2[26]){
    for(int i=0;i<26;i++){
        if(freq1[i]!=freq2[i]){
            return false;
        }
    }
    return true;
}

bool permutation(string s1,string s2){
    int freq[26]={0};
    for(int i=0;i<s1.length();i++){
        freq[s1[i]-'a']++;
    }
    for(int i=0;i<s2.length();i++){
        int idx=i,winidex=0;
        int winfreq[26]={0};
        while(winidex<s1.length() && idx<s2.length()){
            winfreq[s2[idx]-'a']++;
            winidex++,idx++;
        }
        if(isfreqsame(freq,winfreq)){
            return true;
        }
    }
return false;
}
int main()
{
    string s1="ab";
    string s2="eidbaoo";
    cout<<permutation(s1,s2);

return 0;
}