#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,e;
int aa,bb,cc,dd,ee; string nope;
vector<int> v;
bool solved = 0;

void sol(int p,int n)
{
    if(nope[p]-48==n or a < 0 or b < 0 or c < 0 or d < 0) return ;
    if(solved or p==e) return ;
    if(p==e-1)
    {
        if(a or b or c or d) return ;
        else
        {
            solved = 1;
            for(auto it : v) cout << it; cout << n << endl;
        }
    }
    else
    {
        v.push_back(n);
        for(int i=1;i<=4;++i)
        {
            if(nope[p+1]-48==i) continue;
            if(i==1){ a--; sol(p+1,1); a++;}
            if(i==2){ b--; sol(p+1,2); b++;}
            if(i==3){ c--; sol(p+1,3); c++;}
            if(i==4){ d--; sol(p+1,4); d++;}
        }
        v.pop_back();
    }
}

void start()
{
    for(int i=1;i<=4;++i)
    {
        if(nope[0]-48==i) continue;
        if(i==1){ a--; sol(0,1); a++;}
        if(i==2){ b--; sol(0,2); b++;}
        if(i==3){ c--; sol(0,3); c++;}
        if(i==4){ d--; sol(0,4); d++;}
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q; cin >> q;
    while(q--)
    {
        cin >> aa >> bb >> cc >> dd >> ee >> nope; nope = nope+"X";
        a=aa,b=bb,c=cc,d=dd,e=ee;
        solved = 0; v.clear(); start();
    }
}
