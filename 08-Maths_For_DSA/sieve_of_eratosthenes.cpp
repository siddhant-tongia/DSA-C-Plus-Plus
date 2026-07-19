#include<iostream>
#include<vector>
using namespace std;
int numberofprime(int n){
    int count=0;
    vector<bool> IsPrime(n+1,true);
    for(int i=2;i<n;i++){
        if(IsPrime[i]){
            count++;
            for(int j=i*2;j<n;j+=i){
                IsPrime[j]=false;
            }
        }
    }
return count;
}
 
int main()
{
    int n;
    cin>>n;
    cout<<numberofprime(n)<<endl;
return 0;
}