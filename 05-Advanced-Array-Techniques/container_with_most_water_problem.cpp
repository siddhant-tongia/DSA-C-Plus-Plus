/*
 * Problem: Container With Most Water
 * Description: Given an integer array height of length n, find two lines that together with the x-axis form a container, such that the container contains the most water.
 * Example:
 * Input: height = [1,8,6,2,5,4,8,3,7]
 * Output: 49
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