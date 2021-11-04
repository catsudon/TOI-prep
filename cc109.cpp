#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using pii = pair<int,int>;

int main()
{
    int n,k; cin >> n >> k;
    vector<int> bruh(n);
    for(int i=0;i<n;++i) cin >> bruh[i];
    int day = 0;
    priority_queue<pii,vector<pii>,greater<pii> > pq; /// ready_to_use_date : refresh
    priority_queue<int > zero;
    for(int i=0;i<n;++i) zero.push(bruh[i]);
    int nk = n+k;

    while(pq.size() or zero.size())
    {
        bool tomoriru = false;
        if(pq.size())
        {
            int F = pq.top().f;
            int S = pq.top().s;
            if(F > day) tomoriru = true;
            else
            {
                pq.pop();
                day++;
                if(k and F+S < nk) {pq.push({F+S,S}); k--;}
            }
        }
        else tomoriru = true;

        if(tomoriru and zero.size())
        {
            int S = zero.top();
            zero.pop();
            day++;
            if(k and S < nk) {pq.push({S,S}); k--;}
        }

    }
    cout << day;
}
