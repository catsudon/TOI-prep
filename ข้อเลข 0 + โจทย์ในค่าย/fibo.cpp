#include<bits/stdc++.h>
using namespace std;

int fib(int n)
{
    if(n<=0) return 0;
    if(n==1) return 1;
    else return fib(n-1)+fib(n-2);
}

int main()
{
    for(int i=1;i<=10;++i) cout << fib(i) << " ";
}
