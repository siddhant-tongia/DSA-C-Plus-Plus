/*
 * Problem: Sum of First N Natural Numbers
 * Description: Given an integer n, calculate the sum of the first n natural numbers
 * (1 + 2 + 3 + ... + n) using linear recursion.
 * Example:
 * Input: n = 5
 * Output: 15
 * Explanation: Sum of numbers from 1 to 5 is 1 + 2 + 3 + 4 + 5 = 15.
 */
#include<iostream>
using namespace std;
int sumOfnNums(int n){
    int sum=0;
    if(n==1){
        return 1;
    }
    return(n+sumOfnNums(n-1));
}
 
int main()
{
    int n;
    cin>>n;
    cout<<sumOfnNums(n)<<endl;
return 0;
}