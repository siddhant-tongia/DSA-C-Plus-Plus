/*
 * Problem: Fibonacci Number (LeetCode #509)
 * Description: The Fibonacci numbers, commonly denoted F(n), form a sequence where each
 * number is the sum of the two preceding ones, starting from 0 and 1 (F(0) = 0, F(1) = 1).
 * Given n, calculate F(n) using recursion.
 * Example:
 * Input: n = 4
 * Output: 3
 * Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.
 */
#include<iostream>
#include<vector>
using namespace std;
int fibo(int n){
    if(n==0 || n==1){
        return n;
    }
    return fibo(n-1)+fibo(n-2);
}
 
int main()
{
    int n;
    cin>>n;
    cout<<fibo(n)<<endl;
return 0;
}