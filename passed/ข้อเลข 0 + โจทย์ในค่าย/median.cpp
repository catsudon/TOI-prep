#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
pair<int,int> num[1000009]; // upper / lower
long long c = 0;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int pos,n,k;
    cin >> n >> k;
    for(int i=1;i<=n;++i) {cin >> num[i].f;if(num[i].f==k)pos=i;}
    num[pos] = {0,0};

    for(int i=pos+1;i<=n;++i)
    {
        if(num[i].f>k) num[i] = {num[i-1].f+1,num[i-1].s} ;
        else if(num[i].f<k) num[i] = {num[i-1].f,num[i-1].s+1} ;
     //   cout << num[i].f << ":" << num[i].s << "\n";
    }
    for(int i=pos-1;i>=1;--i)
    {
        if(num[i].f>k) num[i] = {num[i+1].f+1,num[i+1].s} ;
        else if(num[i].f<k) num[i] = {num[i+1].f,num[i+1].s+1} ;
    }
    for(int i=pos;i<=n;++i)
    {
        for(int j=pos;j>=1;--j)
        {
         //   cout << num[i].f << ":" << num[i].s << " " << num[j].f << ":" << num[j].s << "\n";
            if(num[i].f+num[j].f==num[i].s+num[j].s) c++;
        }
    }

    cout << c;
}
