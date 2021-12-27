#include<bits/stdc++.h>
#define f first
#define s second

using namespace std;
int visited[200009];
vector<pair<int,int> > v[200009];
pair<pair<int,int>,int> e[1000009];
int main(){

int n,m;
long long int flag=0;
scanf("%d %d",&n,&m);

for(int i=0;i<m;i++){
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    v[a].push_back({c,b});
    v[b].push_back({c,a});
}
priority_queue<pair<int,int>> pq;
for(auto it : v[1]){
    pq.push({it.f,it.s});
    //cout << it.f << " : " << it.s << endl;
}
visited[1]=1;
while(!pq.empty()){
    int F = pq.top().f;
    int S = pq.top().s;
    pq.pop();
    //cout << F << " : " << S << endl;
    if(visited[S]==1) continue;
    else{
    flag+=-1+F;
    //cout << flag << "from+" << S << endl;
    for(int i=0;i<v[S].size();++i){
        if(!visited[v[S][i].second]){
            pq.push({v[S][i].f,v[S][i].s});
        }
    }
    visited[S] = 1;
    }
}

printf("%lld",flag);
}
