#include<iostream>
#include<vector>
using namespace std;
void nextpermutation(vector<int>&vec)
{
    int n=vec.size();
    int piv=-1;
   for(int i=n-2;i>=0;i--){     // To find the pivot point.
    if(vec[i]<vec[i+1]){
        piv=i;
        break;
    }
   } 
   if(piv==-1){     //if the existing array is already maximum.
    int i=0,j=n-1;
    while(i<j){
        swap(vec[i],vec[j]);
        i++;
        j--;
    }
    return;
   }
   for(int i=n-1;i>piv;i--){        //swaping the value.
    if(vec[i]>vec[piv]){
        swap(vec[i],vec[piv]);
        break;
    }
   }
   int i=piv+1,j=n-1;
   while(i<j){      //reversing the array.
    swap(vec[i],vec[j]);
    i++;
    j--;
   }
}
 
int main()
{
   vector<int> vec={};
   nextpermutation(vec);
   for(int val : vec){
    cout<<val<<" ";
   } 
return 0;
}