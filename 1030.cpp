#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using pdi = pair<double,int>;
priority_queue<pdi,vector<pdi>,greater<pdi> > pq;
int main()
{
    int n,m; cin >> n;
    for(int i=0;i<n;++i)
    {
        double price,quan; cin >> price >> quan;
        double ppp = price/quan;
        pq.push({ppp,quan});
    }

    cin >> m;
    for(int i=0;i<m;++i)
    {
        int q; cin >> q;
        double sum = 0;
        while(q)
        {
            if(pq.top().s >= q)
            {
                sum+=pq.top().f * q;
                if(pq.top().s==q) pq.pop();
                else
                {
                    double F = pq.top().f;
                    int S = pq.top().s;
                    pq.pop();
                    pq.push({F,S-q});
                }
                q=0;
            }
            else
            {
                sum+= pq.top().f * pq.top().s;
                q-=pq.top().s;
                pq.pop();
            }
        }
        printf("%.3f\n",sum);
    }
}
