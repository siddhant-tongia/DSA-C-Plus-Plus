#include<iostream>
#include<vector>
using namespace std;
void bubblesort(vector<int> &vec)
{
    int n=vec.size();
    for(int i =0;i<n-1;i++)
    {
        bool isSwap=false;
        for(int j=0;j<n-i-1;j++)
        {
            if(vec[j]>vec[j+1])
            {
                swap(vec[j],vec[j+1]);
                isSwap=true;
            }
        }
        if(!isSwap)
        {
            return ;
        }
    }
}
 
int main()
{
    vector<int>vec={4,2,5,3,1};
    bubblesort(vec);
    for(int val:vec)
    {
        cout<<val<<"\t";
    }
    
return 0;
}