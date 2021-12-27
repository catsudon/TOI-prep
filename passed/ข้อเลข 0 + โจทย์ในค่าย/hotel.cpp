#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    long long sum=0;

    sum += 3000*(n/15);
    n%=15;
    if(n>=9) sum+=3000;
    else if(n==8) sum+=2800;
    else if(n==7) sum+=2300;
    else if(n==6) sum+=2000;
    else if(n==5 || n==4) sum+=1500;
    else if(n==3) sum+=1300;
    else if(n==2) sum+=800;
    else if(n==1) sum+=500;

    cout << sum;
}
