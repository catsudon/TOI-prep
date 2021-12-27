#include<bits/stdc++.h>
using namespace std;
const int X = 1e5+9;
vector<int> v[X];
int gender[X]; // 0 = dontknow 1 = male 2 = female
int n,m;
bool gay = false;

int solve(int sex,int pos)
{
    if(gay) return 0;
    if(gender[pos] == 1 and sex == 2) {gay = true; return 0;}
    if(gender[pos] == 2 and sex == 1) {gay = true; return 0;}
    if(gender[pos] == 0 ) gender[pos] = sex;
    //else return 0;
    int nsex;
    if(sex==1) nsex=2;
    else nsex=1;

    for(auto it : v[pos]) solve(nsex,it);

}

int main()
{
    int q; cin >> q;
    while(q--)
    {
        cin >> n >> m;
        gay = false;
        for(int i=0;i<=n;++i) {v[i].clear();gender[i]=0;}
        while(m--)
        {
            int a,b; cin >> a >> b;
            if(b<a) swap(a,b);
            v[a].emplace_back(b);
        }
        for(int i=0;i<n;++i)
        {
            if(gender[i]==0) solve(1,i);
        }
        gay ? cout << "Gay found!\n" : cout << "Gay not found!\n";
    }

}
