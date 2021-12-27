#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using pii = pair<int,int>;
bool sh[1009][1009];
int collision2 = 0 , collision3 = 0;
pii fu[5009];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie();
    int n,m; cin >> n >> m;
    for(int i=1;i<=m;++i)
    {
        int a,b; cin >> a >> b;
        sh[a][b] = 1;
        sh[b][a] = 1;
        fu[i] = {a,b};
    }

    for(int i=1;i<=m;++i)
    {
        for(int j=i+1;j<=m;++j)
        {
            int bass = fu[i].f;
            int guitar = fu[i].s;
            int drum = fu[j].f;
            int keyboard = fu[j].s;

            if(bass == drum or bass == keyboard or guitar == drum or guitar == keyboard) continue;

            int relation = 2;
            if(sh[bass][drum]) relation++;
            if(sh[bass][keyboard]) relation++;
            if(sh[guitar][drum]) relation++;
            if(sh[guitar][keyboard]) relation++;

            if(relation==5) collision2++;
            if(relation==6) collision3++;
        }
    }

    cout << collision2/2 + collision3/3;


}
