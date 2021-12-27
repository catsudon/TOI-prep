#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using pii = pair<int,int>;
using edges = pair<int,pii>;
bool vst[200009];
int parent[200009];

int find_parent(int num)
{
    if(parent[num]==0) return num;
    return parent[num] = find_parent(parent[num]);
}

int merge(int x, int y)
{
    parent[find_parent(x)] = find_parent(y);
}



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,e;
    cin >> n >> e;
    priority_queue<edges> pq;

    for(int i=0;i<e;++i)
    {
        int a,b,c;
        cin >> a >> b >> c;
        pq.push({c-1,{a,b}});
    }

    int a,b,dis;
    long long sum =0;
    while(!pq.empty())
    {
        dis = pq.top().f;
        a = pq.top().s.f;
        b = pq.top().s.s;
        pq.pop();
        if(find_parent(a)==find_parent(b)) continue;
        else{
            merge(a,b);
            sum+=dis;
        }
    }

    cout << sum;

}
