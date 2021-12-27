// big thanks for sadboy

#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using pii = pair<int,int>;
int n,e;
const int N = 100009;
const int E = 100009;
vector<pii> v1[N],v2[N];
vector<int> v3[N];
int edge_cost[E];
int deg[N];
int cut_edge = 0; // sum of the cost of the edge we cut off
int morph[E];
bool trashed[E];
bool forbidden[N];
bool just_compressed[E];
int lu[E] , lv[E];
int vst[E]; // 0 = unvst 1 = vst once 2 = worst case ( no need to visit any edges more than 2 times )
int mnsum = INT_MAX;
int all_edges = 0;




int dfs(int pos , int sum , int edgecnt)
{
    if(sum >= mnsum) return 0; // prune
    if(edgecnt == all_edges and pos == 0)
    {
        mnsum = min(mnsum,sum);
        return 0;
    }

  //  cerr << pos << ' ' << sum << ' ' << edgecnt << endl;

    for(auto it : v3[pos])
    {
        int v = lv[it];
        if(v == pos) v = lu[it];
        int cost = edge_cost[it];
        if(vst[it] == 2) continue;



        int coef=0;
        if(vst[it]==0) coef=1;
        vst[it]++;
        dfs( v , sum+cost , edgecnt+coef);
        vst[it]--;
    }

}

void compress()             //  _______________
{                           // |              |
    queue<int> q;           // 1 -- 2 -- 3 -- 4    in this case 1 2 3 4 1 is the same with 1 2 1 4 3 2 1 ( better solution btw )
    for(int i=1;i<=e;++i)
    {
        if(lu[i]==0 or lv[i]==0 ) continue;
        if(deg[lu[i]] != 2) continue;
        q.push(i);
    }
    while(q.size())
    {
        int idx = q.front();
        q.pop();
        int u = lu[idx] , v = lv[idx];
 //       cerr <<endl<< u << ":"<<v << endl;
        if(forbidden[u] or forbidden[v] or just_compressed[idx]) continue;
  //      cerr << deg[u] << " ";
        if(deg[u] == 2)
        {
  //          cerr << "entered \n";
            int newline = 0;

            if(v2[u][1].f != idx) newline = v2[u][1].f;
            else newline = v2[u][0].f;

            if(morph[newline]!=0) newline = morph[newline];

            int tu = lu[newline] , tv = lv[newline];
       //     cerr << "tu = " << tu << "  tv = " << tv << endl;
            if(forbidden[tu] or forbidden[tv]) continue;
            if(tu == u)
            {
           //     cerr << lu[newline] << " kara " << v << " ni natta\n";
                lu[newline] = v;
            }
            else
            {
           //     cerr << lv[newline] << " kara " << v << " ni natta\n";
                lv[newline] = v;
            }

            edge_cost[newline]+=edge_cost[idx];
            trashed[idx] = true;
            morph[idx]=newline;

            forbidden[u] = 1; // bye bye node u ~~
   //         just_compressed[idx] = 1;
   //         just_compressed[newline] = 1;

   //         cerr << " compressed " << tu << ':' << tv << "  and  " << u << ':' << v << endl;
            //      u    v                  v
            // o----o----o   ==>   o--------o
            // v    u              v
            // o----o----o   ==>   o--------o

        }

    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> e >> n;
    for(int i=1;i<=e;++i)
    {
        int a,b,c; cin >> a >> b >> c;
        if(a==b)
        {
            cut_edge+=c; trashed[i]=1;
            continue;
        }
        edge_cost[i] = c;
        v1[a].push_back({i,b});
        v1[b].push_back({i,a});
        lu[i]=a; lv[i]=b;
        deg[a]++ , deg[b]++;
    }

    queue<int> deg1_node;
    for(int i=1;i<=n;++i) if(deg[i] == 1 ) deg1_node.push(i);

    /// compress edges with deg == 1
    while(deg1_node.size())
    {
        int pos = deg1_node.front();
        int nxt = v1[pos][0].s;
        int edge_idx = v1[pos][0].f;
        deg1_node.pop();

        cut_edge += 2*edge_cost[edge_idx]; // guaranteed to get walk through only once
        deg[pos]-- , deg[nxt]--;
        forbidden[pos] = true;
        trashed[edge_idx] = true;

        if(deg[nxt] == 1 and nxt != 0) deg1_node.push(nxt);
    }

    for(int i=0;i<=n;++i)           // make a new adjacency list
    for(auto it : v1[i])
    {
        int edge_idx = it.f;
        int node_v   = it.s;
        if(trashed[edge_idx] or forbidden[i] or forbidden[node_v]) continue;
        v2[i].push_back({edge_idx , node_v});
    }

    compress(); // compress deg2 nodes

    for(int i=1;i<=e;++i)
    {
        if(trashed[i]) continue;
        v3[lu[i]].push_back(i);
        v3[lv[i]].push_back(i);
        all_edges++;
   //     cerr << lu[i] << " <---> " << lv[i] << " cost = " << edge_cost[i] << endl;
    }

    dfs(0 , 0 , 0);

    cout << cut_edge + mnsum;





}
