#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void selectionsort(vector<int> &vec)
{
    int n=vec.size();
    for(int i=0;i<n-1;i++)
    {
        int small_index=i;
        for(int j=i+1;j<n;j++)
        {
            if(vec[small_index]>vec[j])
            {
                small_index=j;
            }
        }
        swap(vec[i],vec[small_index]);
    }
}
 
int main()
{
    vector<int>vec={4,2,5,3,1};
    selectionsort(vec);
    for(int val:vec)
    {
        cout<<val<<"\t";
    }
    
return 0;
}