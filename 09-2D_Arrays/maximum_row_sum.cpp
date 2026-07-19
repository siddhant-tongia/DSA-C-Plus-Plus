#include<iostream>
#include<climits>

using namespace std;
int maximumrowsum(int matrix[4][3],int row,int column){
    int max_sum = INT_MIN;
    for(int i=0;i<row;i++){
        int sum=0;
        for(int j=0;j<column;j++){
            sum+=matrix[i][j];
        }
        max_sum=max(max_sum,sum);
    }
return max_sum;
}
 
int main()
{
     int matrix[4][3];
    int row=4,col=3;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>matrix[i][j];
        }
    }
    cout<<maximumrowsum(matrix,row,col)<<endl;
return 0;
}