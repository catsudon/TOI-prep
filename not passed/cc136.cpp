/// seems to be ez
/// idk what I'm doing wrong

#include<bits/stdc++.h>
using namespace std;
int parent[450];
bool vst[450];

int find_parent(int i)
{
    if(parent[i]==0) return i;
    return parent[i] = find_parent(parent[i]);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q; cin >> q;
    while(q--)
    {
        int n,m,c=0; cin >> n >> m;
        for(int i=0;i<=430;++i) parent[i]=0,vst[i]=false;

        while(m--)
        {
            int a,b; cin >> a >> b;
            if(find_parent(a) != find_parent(b))
            parent[find_parent(a)] = find_parent(b);
        }
        for(int i=1;i<=n;++i)
        {
         //   cerr << i << " " << find_parent(i) << endl;
            if(!vst[find_parent(i)])
            {
                vst[find_parent(i)] = true;
                c++;
            }
        }
        if(c>2) cout << -1;
        else cout << c;
        cout << endl;

    }
}
