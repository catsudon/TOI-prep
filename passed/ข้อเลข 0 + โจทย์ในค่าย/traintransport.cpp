#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    //vector<pair<int,int> > v[n+9];
    priority_queue<pair<int,int> > pq;
    for(int i=1;i<=n;++i)
    {
        int a,b;
        cin >> a>> b;
        pq.push({-a,b}); // day & pts
    }
    int day=1;
    int bonus=0;
    vector<int> plused;
    while(!pq.empty())
    {
        int F = pq.top().f;
        int S = pq.top().s;
        pq.pop();
        if(-F<day)
        {
            int mn=INT_MAX,memo=-1;
            for(int i=0;i<plused.size();++i)
            {
                if(plused[i]<mn)
                {
                    mn=plused[i];
                    memo=i;
                }
            }
            if(S>mn) {
               // cout << S << " " << plused[memo];
                bonus+=S;
                bonus-=plused[memo];
                plused.erase(plused.begin()+memo);
            }
            continue;
        }
        //cout << F << ":" << S << " " << day << endl;
        bonus+=S;
        plused.push_back(S);
        day++;
    }
    cout << bonus;
}
