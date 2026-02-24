#include<iostream>
using namespace std;
int digonalsum(int matrix[3][3],int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=matrix[i][i]; // Primary Digonal
        if (i!=n-1-i){
            sum+=matrix[i][n-1-i]; // Secondary Digonal
        }
    }
return sum;
}
 
int main()
{
    int matrix[3][3];
    int n=3;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>matrix[i][j];
        }
    }
    cout<<digonalsum(matrix,n)<<endl;
return 0;
}