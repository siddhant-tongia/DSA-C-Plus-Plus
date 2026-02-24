#include<iostream>
#include<climits>

using namespace std;
int maximumcolumnsum(int matrix[4][3],int row,int column){
    int max_sum=INT_MIN;
    for(int i=0;i<column;i++){
        int sum=0;
        for(int j=0;j<row;j++){
            sum+=matrix[j][i];
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
    cout<<maximumcolumnsum(matrix,row,col)<<endl;
return 0;
}