/*
 * Problem: Factorial of a Number
 * Description: Given a non-negative integer n, calculate its factorial (n!) using recursion.
 * The factorial of n is the product of all positive integers less than or equal to n,
 * where 0! = 1 and 1! = 1.
 * Example:
 * Input: n = 5
 * Output: 120
 * Explanation: 5! = 5 * 4 * 3 * 2 * 1 = 120.
 */
#include<iostream>
#include<vector>
using namespace std;

int factorial(int n){
    if(n==1 || n==0){
        return 1;
    }
    return n*factorial(n-1);
}
int main()
{
    int n;
    cin>>n;
    cout<<factorial(n);
return 0;
}