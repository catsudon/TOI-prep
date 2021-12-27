#include<bits/stdc++.h>
using namespace std;
queue<int> q;
int roll[110];
int sum[25];
int main()
{
    int n,k; cin >> n >> k;
    for(int i=0;i<n;++i)
    {
        int t; cin >> t;
        q.push(t);
    }
    for(int i=0;i<n;++i) cin >> roll[i];

    int hito=0,dice_idx=0;
    while(!q.empty())
    {
        for(int i=0;i<roll[dice_idx];++i)
        {
            q.push(q.front());
            q.pop();
        }
        sum[hito%k]+=q.front();
        q.pop();
        hito++; dice_idx++;
    }

    for(int i=0;i<k;++i) cout << sum[i] << endl;
}
