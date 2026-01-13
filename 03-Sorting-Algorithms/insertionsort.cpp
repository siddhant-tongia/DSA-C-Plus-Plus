#include<iostream>
#include<vector>
using namespace std;
void insertionsort(vector<int> &vec)
{
    int n=vec.size();
    for(int i=1;i<n;i++)
    {
        int curr=vec[i],previous=i-1;
        while(previous>=0 && curr<vec[previous])
        {
            vec[previous+1]=vec[previous];
            previous--;
        }
        vec[previous+1]=curr;
    }
}
 
int main()
{
    vector<int>vec={4,2,5,3,1};
    insertionsort(vec);
    for(int val:vec)
    {
        cout<<val<<"\t";
    }
    
return 0;
}