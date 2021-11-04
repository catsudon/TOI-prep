#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    int nn=n;
    queue<int> q;
    for(int i=1;i<=n;++i) q.push(i);
    while(nn--)
    {
        for(int i=1;i<m;++i)
        {
            q.push(q.front());
            q.pop();
        }
        cout << q.front() << " ";
        q.pop();
    }
}
