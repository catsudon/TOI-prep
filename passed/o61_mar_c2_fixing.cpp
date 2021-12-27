#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,k; cin >> n >> m >> k;
    int sum = 0; int last = 0;
    cin >> last;
    sum+=last-1;
    priority_queue<int> pq;
    for(int i=2;i<=m;++i)
    {
        int a; cin >> a;

        pq.push(a-last-1);

        last=a;
    }
    sum+=n-last;
    k--;
    while(k and pq.size())
    {
     //   cerr << pq.top() << endl;
        sum+=pq.top();
        pq.pop();
        k--;
    }
    cout << n-m-sum;
}
