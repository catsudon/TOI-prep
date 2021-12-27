#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    priority_queue<int> pq;
    while(n--)
    {
        char cmd;
        cin >> cmd;
        if(cmd=='P')
        {
            int a;
            cin >> a;
            pq.push(a);
        }
        if(cmd=='Q')
        {
            if(pq.empty()) cout << -1 << "\n";
            else
            {
                cout << pq.top() << "\n";
                pq.pop();
            }
        }

    }
}
