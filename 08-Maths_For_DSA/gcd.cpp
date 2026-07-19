// #include<iostream>
// #include<algorithm>
// using namespace std;
// int GCD(int n,int m){
// if (n == 0) return m;
//     if (m == 0) return n;

//     int gcd = 1;
//     for (int i = 1; i <= min(n, m); i++) {
//         if (n % i == 0 && m % i == 0) {
//             gcd = i;
//         }
//     }
//     return gcd;
// }
 
// int main()
// {
//     int a,b;
//     cin>>a>>b;
//     cout<<GCD(a,b)<<endl;
// return 0;
// }
#include<iostream>

using namespace std;
int GCD(int n,int m){
    if (n == 0 && m == 0) return 0; 

    if(m==0){
        return n;
    }
    return GCD(m,n%m);
}
int main()
{
    int a,b;
    cin>>a>>b;
    cout<<GCD(a,b);
return 0;
}