#include<bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define eb emplace_back
using namespace std;
typedef tuple<int,int,int> iii;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int,int>> vpii;
const int N = 100005;
bool mark[N], vis[N];
int deg[N];
vector<pii> g[N];
vector<iii> new_g[8]; // (node, weight, id)
map<int,int> mp; // id of node in compressed graph
map<vi,int> edge_id; // id of edge
int n, m;
queue<int> bfs;
priority_queue<iii> dijk; // (weight, node, masks)
int ans;
vvi dp;
int main(){
	int i, j, k, l;
	scanf("%d%d",&m,&n);
	//while(n > 100000);
	mark[0] = true;
	for(i=1;i<=m;++i){
		int a, b, c;
		scanf("%d%d%d",&a,&b,&c);
		g[a].eb(b,c);
		g[b].eb(a,c);
		deg[a]++;
		deg[b]++;
	}
	for(i=1;i<n;++i){
		if(deg[i]==1){
			bfs.push(i);
		}
	}
	while(!bfs.empty()){
		int u = bfs.front();
		vis[u] = true;
		//printf("visit %d\n",u);
		bfs.pop();
		for(pii e : g[u]){
			int v = e.x;
			int w = e.y;
			if(vis[v]) continue;
			deg[v]--;
			ans += 2*w;
			if(deg[v]==1&&!mark[v]){
				bfs.push(v);
			}
		}
	}
	// compress graph
	//puts("start compressing graph");
	int cnt = 1, cnt2 = 0;
	for(i=1;i<n;++i){
		if(!vis[i]&&deg[i]>2){
			//printf("marked %d\n",i);
			mark[i] = true;
			mp[i] = cnt++;
		}
	}
	for(i=0;i<n;++i){
		if(!mark[i])continue;
		//printf("{%d}\n",i);
		int selfloop = 0;
		for(pii e : g[i]){
			int v = e.x, w = e.y;
			if(!vis[v]){
				//printf("visit %d\n",v);
				vi path;
				path.eb(i);
				path.eb(v);
				int p = i, now = v, sum = w;
				while(!mark[now]){
					for(pii f : g[now]){
						if(vis[f.x] || f.x == p) continue;
						sum += f.y;
						p = now;
						now = f.x;
						break;
					}
					path.eb(now);
					//printf("visit %d\n",now);
				}
				if(i == now){
					selfloop += sum;
					continue;
				}
				int a = mp[i], b = mp[now];
				if(a > b) reverse(path.begin(),path.end());
				/*
				printf("[");
				for(int e : path) printf(" %d",e);
				printf(" ]\n");
				*/
				if(edge_id.find(path)==edge_id.end()){
					edge_id[path] = cnt2++;
				}
				//printf("add (%d,%d,%d) id = %d\n",i,now,sum,edge_id[path]);
				new_g[mp[i]].eb(mp[now],sum,edge_id[path]);
			}
		}
		ans += selfloop/2;
	}
	// dijkstra, dp bitmasks
	//puts("start dijkstra");
	dp.resize(cnt,vi(1<<cnt2,INT_MAX));
	dp[0][0] = 0;
	dijk.emplace(0,0,0);
	while(!dijk.empty()){
		int u, mask, w;
		tie(w,u,mask) = dijk.top();
		dijk.pop();
		w *= -1;
		if(dp[u][mask] != w) continue;
		for(auto [v, ww, id] : new_g[u]){
			if(dp[v][mask|(1<<id)] > w+ww){
				dp[v][mask|(1<<id)] = w+ww;
				dijk.emplace(-w-ww, v, mask|(1<<id));
			}
		}
	}
	printf("%d",ans+dp[0][(1<<cnt2)-1]);
	return 0;
}
