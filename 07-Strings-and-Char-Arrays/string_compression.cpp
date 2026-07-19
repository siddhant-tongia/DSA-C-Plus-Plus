#include<iostream>
#include<vector>
using namespace std;
int StringCompression(vector<char> &arr){
    int idx=0;
    for(int i=0;i<arr.size();i++){
        int count =0;
        char ch=arr[i];
        while(i<arr.size() && arr[i]==ch){
            count ++;
            i++;
        }
        if(count==1){
            arr[idx++]=ch;
        }else{
            arr[idx++]=ch;
            string str=to_string(count);
            for(char dig:str){
                arr[idx++]=dig;
            }
        }
        i--;
    }
    return idx;
}  

int main()
{
    vector<char>arr={'a','a','b','b','b','b','c'};
    cout<<StringCompression(arr);
    
return 0;
}