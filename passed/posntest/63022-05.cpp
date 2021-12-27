#include<iostream>
using namespace std;
using ll = long long;
ll dp[600];
ll fibo(int n)
{
    if(n<=0) return 0;
    if(dp[n]!=0) return dp[n];
    return dp[n] = fibo(n-1) + fibo(n-2);
}

int main()
{
    int n; cin >> n;
    dp[1] = 1;
    cout << fibo(n-2) << endl;
    cout << fibo(n-1) << endl;
    cout << fibo(n);
}

// n = 20 : 2584,4181,6765
// n = 35 : 3524578,5702887,9227465
