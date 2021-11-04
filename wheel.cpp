#include<bits/stdc++.h>
using namespace std;
int n,k;
vector<int> v[11];
string w[11];
bool a[11][200];
int llenn[11];
int mn = INT_MAX;

int dfs(int lv, int p)
{
    cerr << lv << " " << p << " real one : " << w[lv][p%w[lv].length()] << endl;
    if(!a[lv][p%llenn[lv]]) return 0; /// failed

    if(lv==n) mn = min(mn,p);
    else dfs(lv+1,p);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    for(int i=1;i<=n;++i)
    {
        cin >> w[i]; llenn[i] = w[i].length();
        cerr << "lv." << i << " : ";
        for(int j=1;j<=w[i].length();++j)
        {
            int idx = j-1;
            /// query from idx but when put use j
            if(w[i][idx]-48 == k)
            {
                v[i].push_back(j); cerr << j << " ";
                a[i][j] = 1;
            }
        }
        cerr << endl;
    }
    for(auto it : v[1]) /// on lv1
    {
        if(it==1) continue;
        dfs(2,it);
    }

    cout << mn-1;
}
