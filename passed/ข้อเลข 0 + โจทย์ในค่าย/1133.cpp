#include<bits/stdc++.h>
using namespace std;
unordered_set<int> us[1000009];
int mn,n,m;
bool vst[1000009];
int start(int round,int a,int b)
{
    cout << round << " " << a << " " << b << endl;
    vst[a]=true;
    round++;

    if(round>=mn) return 0;
    if(b==a) if(round<mn) mn=round;
    else{
        for(auto it : us[a])
            if(!vst[it]) start(round,it,b);
    }



    vst[a]=false;
}

int main()
{
 //   ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i=0;i<m;++i)
    {
        int w; cin >> w;
        int aa[w];
        for(int j=0;j<w;++j)
        {
            cin >> aa[j];
        }
        for(int j=0;j<w;++j)
        {
            for(int k=j+1;k<w;++k)
            {
                us[aa[j]].insert(aa[k]);
                us[aa[k]].insert(aa[j]);
            }

        }
    }

    int q; cin >> q;
    for(int i=0;i<q;++i)
    {
        mn = 1000;
        int a,b;
        cin >> a >> b;
        start(-1,a,b);
        if(mn==1000) cout << "impossible\n"; else cout << mn << "\n";
    }


}
