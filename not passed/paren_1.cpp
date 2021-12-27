#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using pii = pair<int,int>;
const int N = 1009;

int n,op,ed;
vector<int> v[N];
int op_to[N];
int every_to_ed[N];
bool vst[N];
bool ban_op_to[N];
int req_for_i_to_ed[N];
string icon;

void sol2(int st)
{
    queue<pair<pii,bool > > q;
    for(int i=1;i<=n;++i) vst[i] = 0;
    q.push({{st,0},0});
    while(q.size())
    {
       int idx = q.front().f.f;
       int riru = q.front().f.s;
       bool banned = q.front().s;
       q.pop();
       int pos = idx;

       if(vst[pos]) continue;
       vst[pos] = 1;

       if(icon[idx] == '(') riru++;
       else riru--;

       req_for_i_to_ed[st] = max(req_for_i_to_ed[st],-riru);

 //      cerr << st << " goint to ed   " << " pos = " << pos << " riru = " << riru << endl;

       if(idx==ed)
       {every_to_ed[st] = riru; return ;}

       for(auto it : v[idx])
       {
           if(vst[it]) continue;
           q.push({{it,riru},banned});
       }


    }
}

void sol1()
{
   queue<pair<pii,bool> > q; // idx : paren
   q.push({{op,0},0});
   while(q.size())
   {
       int idx = q.front().f.f;
       int riru = q.front().f.s;
       bool banned = q.front().s;
       q.pop();
       int pos = idx;

       if(vst[pos]) continue;
       vst[pos] = 1;

       if(icon[idx] == '(') riru++;
       else riru--;

       if(riru < 0 ) banned=1;
       if(banned) ban_op_to[idx] = 1;

       op_to[idx] = riru;

       for(auto it : v[idx])
       {
           if(vst[it]) continue;
           q.push({{it,riru},banned});
       }
   }
}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> op >> ed;

    for(int i=1;i<n;++i)
    {
        int a,b; cin >> a >> b ;
        v[a].push_back(b);
        v[b].push_back(a);
    } cin >> icon;
    icon = " " + icon;

    sol1();


    for(int i=1;i<=n;++i) sol2(i);


    cerr << endl;for(int i=1;i<=n;++i) cerr << op_to[i] << ' '; cerr << endl;
    for(int i=1;i<=n;++i) cerr << ban_op_to[i] << ' '; cerr << endl;
    for(int i=1;i<=n;++i) cerr << every_to_ed[i] << ' '; cerr << endl;
    for(int i=1;i<=n;++i) cerr << req_for_i_to_ed[i] << ' '; cerr << endl; cerr << endl;

    int cnt = 0;
    for(int i=1;i<=n;++i)
    {
        int tomo = op_to[i];
        if(ban_op_to[i]) continue;
        for(int j=1;j<=n;++j)
        {
            int riru = every_to_ed[j];
            if(tomo < req_for_i_to_ed[j]) continue;
            if(tomo+riru != 0 ) continue;
            cnt++; cerr << i << ' ' << j << endl;
        }
    }

    cout << cnt;
}
