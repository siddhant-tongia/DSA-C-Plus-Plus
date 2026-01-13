/*
#include<iostream>
using namespace std;
int stock(int price[],int n)
{
    int min=price[0];
    int max=0;
    for(int i=0;i<n;i++)
    {
        if(price[i]<min)
        {
            min=price[i];
        }
        for(int j=i+1;j<n;j++)
        {
            if(price[j]-price[i]>max)
            {
                max=price[j]-price[i];
            }
        }
    }
return max;
}
int main()
{
    int n;
    cout<<"Enter the the number of element in the array:";
    cin>>n;
    int price[n];
    for(int i=0;i<n;i++)
    {
        cin>>price[i];
    }
    cout<<"The maximum profit for this sale is :"<<stock(price,n);
    
return 0;
}
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int stock(vector<int>price)
{
    int profit=0,best_buy=price[0];
    for(int i=0;i<price.size();i++)
    {
        // if(best_buy<price[i])
        // {
        //     profit=max(profit,price[i]-best_buy);
        // }
        // best_buy=min(best_buy,price[i]);
        if(price[i]<best_buy)     // my logic 
        {
            best_buy=price[i];
        }
        profit=max(profit,price[i]-best_buy);
    }
return profit;
}
 
int main()
{
    vector <int>price={7,1,5,3,6,4};
    cout<<"The maximum profit for this sale is :"<<stock(price);
    
return 0;
}