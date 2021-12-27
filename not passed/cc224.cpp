#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
const int N = 300009;
const long long MOD = 1e9+7;
long long bin[N];
short col[N];
bool err=0;
vector<pair<int,int> > v[N]; /// pos : (ikus/isrik)
int hen[3] = {69,2,1};

int reArrange(int pos,int color,int p)
{
    if(err) return 0;

    bool haschanged = 0;
    if(col[pos]!=color) haschanged = 1;
    col[pos] = color;
    bool traveled = 0;

    int rev = 2;
    if(color = 2) rev=1;

    for(auto it : v[pos])
    {
        int node_v = it.f;
        int relation = it.s; // 0=hate 1=unite
        if(node_v==p) continue;
        if(relation and haschanged) reArrange(node_v,color,pos);
        else if(haschanged) reArrange(node_v,rev,pos); // if we do not changed NO NEED TO UPDATE

        traveled=1;
    }
    if(!traveled and haschanged) err = 1;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    bin[0]=1;
    for(int i=1;i<=300000;++i)
    {
        bin[i] = bin[i-1]*2;
        bin[i]%=MOD;
    }

    int n,m; cin >> n >> m;
    int ignorant_lion = n; /// LOL
    while(m--)
    {
        int op,a,b; cin >> op >> a >> b;
        v[a].push_back({b,op});
        v[b].push_back({a,op});
        if(err){cout <<0<<endl; continue;}
        if(col[a] == 0 and col[b] == 0) /// both are ignorant
        {
            if(op==0)col[a] = 1,col[b] = 2;
            else col[a] = 1,col[b] = 1;
            ignorant_lion-=2;
            // update
            reArrange(a,1,-1);
        }
        else
        {
            if(col[a] == 0 or col[b] == 0) ignorant_lion--;
            if(col[a] == 0)
            {
                if(op == 0)
                {
                    int rev=hen[col[b]];
                    reArrange(a,rev,-1);
                }
                else reArrange(a,col[b],-1);
            }
            if(col[b] == 0)
            {
                if(op == 0)
                {
                    int rev=hen[col[a]];
                    reArrange(b,rev,-1);
                }
                else reArrange(b,col[a],-1);
            }
        }
        if(err){cout <<0<<endl; continue;}
        cout << bin[ignorant_lion]*2 << endl;
    }



}
