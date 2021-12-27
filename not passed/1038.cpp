#include<bits/stdc++.h>
using namespace std;
int n;
double mx = 0;
int tomo[30][30]; /// mission : prior
bool vst[30];

double riru(int mission,int prior,double possi)
{
    if(vst[mission]) return 0;
    if(prior == n) mx = max(mx,possi);
    vst[mission] = true;
    prior++;
    for(int i=1;i<=n;++i)
    {
        if(!vst[i])
        {
            double t = (double)possi*(double)tomo[i][prior]/100;
            riru(i,prior,t);
        }
    }
    vst[mission] = false;
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) scanf("%d",&tomo[j][i]);
    riru(25,0,1); mx*=100; printf("%.5f",mx);
}
