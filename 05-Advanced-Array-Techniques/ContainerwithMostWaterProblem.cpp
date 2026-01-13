/*
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int area(vector<int>amount)
{
    int max_area=0;
    int n=amount.size();
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(amount[i]<amount[j])
            {
                max_area=max(max_area,amount[i]*(j-i));
            }
            if(amount[j]<amount[i])
            {
                max_area=max(max_area,amount[j]*(j-i));
            }
        }
    }
return max_area;
}
 
int main()
{
    vector<int>amount={1,8,6,2,5,4,8,3,7};
    cout<<"The maximum area of this sample is :"<<area(amount)<<endl;
return 0;
}
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int area(vector<int>amount)
{
    int n=amount.size();
    int i=0,j=n-1;
    int max_area=0;
    while(i<j)
    {
        int width=j-i;
        int height=min(amount[i],amount[j]);
        int curr_area=height*width;
        amount[i]<amount[j]?i++:j--;
        max_area=max(max_area,curr_area);
    }
return max_area;
}
 
int main()
{
    vector<int>amount={1,8,6,2,5,4,8,3,7};
    cout<<"The maximum area of this sample is :"<<area(amount)<<endl;
return 0;
}