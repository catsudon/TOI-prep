#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    priority_queue<int> pq;

    for(int i=0;i<n;++i)
    {
        char cmd;
        cin >> cmd;
        if(cmd == 'Q')
        {
            if(pq.empty()) cout << -1 << endl;
            else {cout << pq.top() << endl; pq.pop();}
        }
        else
        {
            int a; cin >> a;
            pq.push(a);
        }
    }
}
