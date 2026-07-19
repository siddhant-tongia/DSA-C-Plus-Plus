#include<iostream>
using namespace std;
bool prime_check(int n){
    if(n<=1){
        return false;
    }
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            return false;
        }
    }
return true;
}
int main(){
    int n;
    cin>>n;
    if(prime_check(n)){
        cout<<"Prime";
    }
    else{
        cout<<"Non-Prime";
    }
return 0;
}