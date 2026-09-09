/*
 * Problem: Squares of a Sorted Array (or Squares of an Array)
 * Description: Given an integer array nums, return an array of the squares of each number.
 * Example:
 * Input: nums = [-4,-1,0,3,10]
 * Output: [16,1,0,9,100]
 */
#include<iostream>
using namespace std;
 
int main()
{
    int n;
    cout<<"Enter the number of element in the array :";
    cin>>n;
    int a[n],sqa[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        sqa[i]=a[i]*a[i];
    }
    cout<<"The square array is :"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<sqa[i]<<endl;
    }
return 0;
}