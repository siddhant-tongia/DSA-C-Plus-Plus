/*
 * Problem: String Compression
 * Description: Given an array of characters chars, compress it using the following algorithm: Begin with an empty string s. For each group of consecutive repeating characters in chars: If the group's length is 1, append the character to s. Otherwise, append the character followed by the group's length. Return the new length of the array.
 * Example:
 * Input: chars = ["a","a","b","b","c","c","c"]
 * Output: Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]
 */
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