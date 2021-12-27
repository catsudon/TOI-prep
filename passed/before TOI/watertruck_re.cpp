#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const int N = 1e5+9;
int u[N] , v[N] , deg[N];
int morph[N];
ll cost[N];
bool forbidden[N];
bool byebye[N];
int vst[N];
int n,e;
int all = 0;
long long sum = 0;
vector<pii> adj1[N],adj2[N];
vector<int> adj3[N] ;
long long ans = LONG_MAX;


void dfs(int i , int cnt , long long kost)
{
    if(cnt == all and i==0)
    {
        ans=min(ans,kost);
        return ;
    }
  //  cerr << endl << i << ' ' << cnt << ' ' << kost;
    for(auto it : adj3[i])
    {
        int nxt = u[it];
        if(nxt==i) nxt=v[it];

        if(vst[it]==2) continue;
        if(vst[it]==0) cnt++;
        vst[it]++;
        dfs(nxt,cnt,kost+cost[it]);
        vst[it]--;
        if(vst[it]==0) cnt--;

    }

}

void deg2()
{//      1   2  3  4          10
    //  A--B--C---D--E ==> A-----E
    queue<int> deg2;
    for(int i=1;i<=n;++i)
    {
        if(forbidden[i]) continue;
        if(deg[i] == 2) deg2.push(i);
    }
    while(deg2.size())
    {
        int idx = deg2.front();
        deg2.pop();


        int mainedge = adj2[idx][0].s; if(morph[mainedge]!=0) mainedge=morph[mainedge];
        int sideedge = adj2[idx][1].s; if(morph[sideedge]!=0) sideedge=morph[sideedge];
        int left_node = u[mainedge]; if(left_node==idx) left_node = v[mainedge];
        int right_node = u[sideedge]; if(right_node==idx) right_node = v[sideedge];
        ll sum = cost[mainedge] + cost[sideedge];
        if(forbidden[left_node] or left_node==0 or right_node==0 or left_node==right_node or mainedge==sideedge) continue;
        // a---b---c => a----c   // b merge with a

        if(u[mainedge] == left_node and v[mainedge]==idx) v[mainedge] = right_node;
        else
        {
            u[mainedge] = right_node;
        }
        cerr << "joined " << left_node << "-----"<<idx <<"------"<<right_node << "the cost is " << cost[mainedge] << " + " << cost[adj2[idx][1].s]<<endl;
        cost[mainedge] = sum;



        forbidden[idx]=1;
        byebye[sideedge]=1;
        morph[sideedge] = mainedge;
    }
}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> e >> n;
    for(int i=1;i<=e;++i)
    {
        cin >> u[i] >> v[i] >> cost[i];
        adj1[u[i]].push_back({v[i],i}); // destination :: edgeIDX
        adj1[v[i]].push_back({u[i],i}); // destination :: edgeIDX
        deg[u[i]]++; deg[v[i]]++;
    }

    // cut 1 deg node;
    queue<int> q;
    for(int i=1;i<=n;++i) if(deg[i] == 1) q.push(i);

    while(q.size())
    {
        int idx = q.front();
        q.pop();
        for(auto it : adj1[idx] )
        {
        //    if(it.f==0) continue;
            if(forbidden[it.f]) continue;
            if(byebye[it.s]) continue;
            sum+=cost[it.s]*2;
            byebye[it.s] = 1;

            deg[u[it.s]]--; if(deg[u[it.s]]==1) if(u[it.s]!=0) q.push(u[it.s]);
            deg[v[it.s]]--; if(deg[v[it.s]]==1) if(v[it.s]!=0) q.push(v[it.s]);

            break;
        }
        forbidden[idx]=1;
        cerr << idx << " is forbidden\n";
    }

    // make new adj eliminating forbidden nodes
    for(int i=0;i<=n;++i)
    {
        if(forbidden[i]) continue;
        for(auto it : adj1[i])
        {
            if(byebye[it.s]) continue;
            if(forbidden[u[it.s]] or forbidden[v[it.s]] ) continue;
            adj2[i].push_back(it);
       //     cerr << u[it.s] << ' ' << v[it.s] << endl;
        }
    }

  //  cerr << sum << endl << endl;

  //  for(int i=1;i<=e;++i) cerr << u[i] << ' ' << v[i] << ' ' << cost[i] << endl;
    deg2();

    for(int i=1;i<=e;++i)
    {
        if(byebye[i] or forbidden[u[i]] or forbidden[v[i]]) continue;
        adj3[u[i]].emplace_back(i);
        adj3[v[i]].emplace_back(i);
        all++;
    }

    dfs(0,0,0);

    cerr << endl <<endl;
    cout << sum+ans;

}
