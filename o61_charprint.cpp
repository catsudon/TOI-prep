#include<bits/stdc++.h>
using namespace std;
bool mode;
string a,b;
long long sum = 0;
queue<int> v[200];
bool ok = 1;
int fw[300009];

int update(int i,int val)
{
    for(;i<=a.size();i+=i&-i)
    {
        fw[i]+=val;
    }
}

int query(int i)
{
    int sum=0;
    for(;i>=1;i-=i&-i) sum+=fw[i];
    return sum;
}


int solve1()
{
    /// fenwick update(i,-1)
  //  for(int i=1;i<=a.size();++i) update(i,1);
    int p=1;
    for(auto it : a)
    {
        v[it].push(p);
        p++;
    }
    for(auto it : b)
    {
        if(v[it].empty())
        {
            ok=0; break;
        }
        sum+=(long long)v[it].front()+query(v[it].front());
        update(v[it].front(),-1);
        v[it].pop();
    }

}
int solve0()
{
    int p=1;
    for(auto it : a)
    {
        v[it].push(p);
        p++;
    }
    for(auto it : b)
    {
        if(v[it].empty())
        {
            ok=0; break;
        }
        sum+=(long long)v[it].front();
        v[it].pop();
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> mode >> a >> b;

    if(mode==0) solve0();
    else solve1();

    if(ok) cout << sum;
    else cout << -1;

}
