#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using pii = pair<int,int>;
string sms[3][3] = {
                        {"","ABC","DEF"},
                        {"GHI","JKL","MNO"},
                        {"PQRS","TUV","WXYZ"}
                    };
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    vector<char> vt;
    int n,s,m; cin >> n >> s >> m;
    int v,h;
    s--;
    v = s/3;
    h = s%3;

    queue<pair<pii,int> > q;
    q.push({{0,0},m});
    for(int i=0;i<n-1;++i)
    {
        int a,b,c; cin >> a >> b >> c;
        q.push({{a,b},c}); // horizon // ventri // time;
    }

    while(!q.empty())
    {
        int F = q.front().f.f;
        int S = q.front().f.s;
        int t = q.front().s;
        q.pop();
        h+=F;
        v+=S;
        t--;
        if(h==0 and v==0) {for(int i=0;i<t+1;++i) if(vt.size()) vt.pop_back();cerr << "kuy";}
        else
        {
          //  cout << h << v;
            int coef = 3;
            if(v==2 and h!=1) coef = 4;
            int ttemp = t%coef;
            char temp = sms[v][h][ttemp];


            vt.push_back(temp);
        }
    }

    if(!vt.empty()) for(int i=0;i<vt.size();++i) cout << vt[i];
    else cout << "null";
}
