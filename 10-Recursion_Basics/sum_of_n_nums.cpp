#include<iostream>
using namespace std;
int sumOfnNums(int n){
    int sum=0;
    if(n==1){
        return 1;
    }
    return(n+sumOfnNums(n-1));
}
 
int main()
{
    int n;
    cin>>n;
    cout<<sumOfnNums(n)<<endl;
return 0;
}