#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int r,p,s;
    cin >> r >> p >> s;
    if(r+p+s != 100)
    {
        cout << "BUG";
        exit(0);
    }
    int mx = r , mem = 'R';
    if(p == mx and mx > s) {cout << "I DON'T KNOW"; exit(0);}
    if(p >  mx) mx = p , mem = 'P';
    if(s == mx) {cout << "I DON'T KNOW"; exit(0);}
    if(s >  mx) mx = s , mem = 'S';

    if(mem == 'R') cout << "PAPER";
    if(mem == 'P') cout << "SCISSORS";
    if(mem == 'S') cout << "ROCK";
}
