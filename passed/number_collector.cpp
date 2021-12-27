#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
const int N = 1e5+9;
int val[N];
long long cnt=0;
int n,m,k;
vector<int> v[N];
bool vst[N];
vector<int> lo;
void dfs(int pos , int mae , bool pick)
{
    vst[pos]=1;
    bool quit=1;

 //   if(pick)lo.push_back(pos);
 //   else lo.push_back(-pos);
 //   for(auto it : lo) cerr << it << ' '; cerr << "      " << mae << endl;

    for(auto it : v[pos])
    {
        if(vst[it]) continue;

        if(abs(val[it] - mae) > k and mae!=-1) {} // didn't pick (end here)
        else
        {
            dfs(it,val[it],1);
            quit=0;
        }
        dfs(it,mae,0);
    }


  //  lo.pop_back();

    vst[pos]=0;
    if(mae!=-1) cnt++;
}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> k;
    while(m--)
    {
        int a,b; cin >> a >> b;
        v[a].emplace_back(b);
        v[b].emplace_back(a);
    }
    for(int i=1;i<=n;++i) cin >> val[i];

    dfs(1,-1,0);
    dfs(1,val[1],1);
    cout << cnt;
}
