#include<bits/stdc++.h>
using namespace std;
int parent[100009];

int f(int i)
{
    if(parent[i]==0) return i;
    return parent[i] = f(parent[i]);
}

void u(int i,int j)
{
    parent[f(i)] = f(j);
}

int main()
{
  //  ios_base::sync_with_stdio(0); cin.tie(0);
    int n,q; cin >> n >> q;
    vector<int> tomo(n+9,0);
    for(int i=1;i<=n;++i) cin >> tomo[i];
    while(q--)
    {
        int a,b; cin >> a >> b;
        int pa = f(a);
        int pb = f(b);
        if(pa == pb) cout << -1 << endl;
        else if(tomo[pa] < tomo[pb])
        {
            tomo[pb]+=tomo[pa]/2;
            cout << pb << endl;
            u(pa,pb);
        }
        else if(tomo[pa] > tomo[pb])
        {
            tomo[pa]+=tomo[pb]/2;
            cout << pa << endl;
            u(pb,pa);
        }
        else
        {
            if(pa < pb)
            {
               tomo[pa]+=tomo[pb]/2;
               cout << pa << endl;
               u(pb,pa);
            }

            else
            {
               tomo[pb]+=tomo[pa]/2;
               cout << pb << endl;
               u(pa,pb);
            }

        }
    }
}
