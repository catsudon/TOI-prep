#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i=7;
    for(;i<=500;i+=i&-i) cout << i << endl;
}
