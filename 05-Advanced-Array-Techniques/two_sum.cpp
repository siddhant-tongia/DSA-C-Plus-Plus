#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
vector<int> twoSum(vector<int> &arr,int tar){
    int n=arr.size();
    unordered_map<int,int> m;
    vector<int> ans;
    for(int i=0;i<n;i++){
        int first=arr[i];
        int second=tar-first;
        if(m.find(second) !=m.end()){
            ans.push_back(i);
            ans.push_back(m[second]);
            break;
        }
        m[first]=i;
    }
return ans;
}
 
int main()
{
    vector<int> arr={5,2,11,7,15};
    int target=9;
    vector<int> result=twoSum(arr,target);
    cout<<"{"<<result[0]<<","<<result[1]<<"}"<<endl;
return 0;
}