#include<bits/stdc++.h>
#define f first
#define s second
#define INF 1e7
using namespace std;
using pii = pair<int,int>;
using ppp = pair<pii,int>;
int e,n,ans = 0;
const int N = 50009;
vector<pii> v[N];
stack<pii> st,st2; /// node : cost (not multiplied)
short vst[N]; bool cyc=0;
int walk_back_till = 0;
int lose_money = 0;
int do_it_later = 0;
int sum=0;
bool paid[N];
int dfs(int pos,int p,int edgecost)
{
    cerr << "visited " << pos << " total cost : " << sum  << "     parent is " << p << endl;
    vst[pos] = 1;
    st.push({pos,edgecost}); // node : cost
    for(auto it : v[pos])
    {
        int cost = it.f;
        int node_v = it.s;
        if(node_v == p) continue;
        if(node_v == pos) {sum+=cost; continue;}
        if(vst[node_v] == 1) /// found cyc
        {
            int chg1 = cost; // sum over cyc
            int mxE  = cost;
            vst[pos] = 2;
            while(st.size() and st.top().f != node_v)
            {
                int name = st.top().f;
                int cst  = st.top().s;
                paid[name]=1; vst[name]=2;
                st.pop();
                chg1+=cst;
                mxE = max(mxE,cst);
            }
           // int chg2 = (chg1-mxE) * 2; // sum over cyc - most value
           // lose_money = min(chg2,chg1);
            lose_money = chg1;

            sum+=lose_money;
       //     cerr << "found cycle at " << pos << " going to " << node_v << " has ";
 //           if(chg2 < chg1) cerr << "chosen to walkback  costed" << lose_money;
   //         else cerr << "chosen to walkthrough  costed" << lose_money;
     //       cerr << endl;
        }
        else if(vst[node_v] == 0)
        {
            if(pos==3) cerr << "special analysis for 3 " << "going to " << node_v << endl;
            dfs(node_v,pos,cost);
            if(pos==3) cerr << "from 3 to " << node_v << " success \n";
        }
    }
    if(st.top().f == pos) st.pop();
    vst[pos] = 2;
    if(!paid[pos]) paid[pos]=1,sum+=edgecost*2;
    cerr << "checkedout from " << pos << " total sum : " << sum << endl;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> e >> n;
    while(e--)
    {
        int a,b,c; cin >> a >> b >> c;
    //    bool ok=1;
      //  for(int i=0;i<v[a].size();++i) if(v[a][i].s == b) v[a][i].s = min(v[a][i].s,c),ok=0;
        //for(int i=0;i<v[b].size();++i) if(v[b][i].s == a) v[b][i].s = min(v[b][i].s,c);
//        if(ok)
  //      {
        v[a].push_back({c,b});
        v[b].push_back({c,a});
    //    }
    }
    dfs(0,-1,0);
    cout << sum;
}
