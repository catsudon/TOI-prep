#include<bits/stdc++.h>
using namespace std;
map<int,int> cnt;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n[5];
    for(int i=0;i<5;++i) cin >> n[i];

    for(int i=0;i<5;++i)
    {
        map<int,bool> vst;
        for(int j=0;j<n[i];++j)
        {
            int a; cin >> a;
            if(vst[a] == true) continue;
            else
            {
                vst[a] = true;
                if(cnt[a]==NULL) cnt[a] = 1;
                else cnt[a]++;
            }
        }
    }

    int ans=0;
    for(auto it:cnt) if(it.second >=3) ans++;
    cout << ans;
}
