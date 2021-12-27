#include<bits/stdc++.h>

using namespace std;
vector<pair<int,int> >node[200009];
pair<pair<int,int>,int> r[1000009];

int flag=0;
int main(){

int n,m;
scanf("%d %d",&n,&m);

for(int i=0;i<m;++i)
{
    scanf("%d %d %d",&r[i].first.first,&r[i].first.second,&r[i].second);
    node[r[i].first.first].push_back({r[i].second,r[i].first.second});
    node[r[i].first.second].push_back({r[i].second,r[i].first.first});
}

priority_queue<pair<int,int> > pq;

int x=1;
for(int i=0;i<node[1].size();++i){
    // if node[node[1][i].second].first != -1
    pq.push({node[1][i].first,node[1][i].second});
}
while(x!=n){
    int vrhere = pq.top().second;
    flag+= -1+pq.top().first;
    for(auto it : node[vrhere]) cout << it.first << " " << it.second << endl;
    printf("%d %d\n",pq.top().first,vrhere);
    node[vrhere][0].first = -1;
    pq.pop();
    x++;

}

printf("%d",flag);


}
