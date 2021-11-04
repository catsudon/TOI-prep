#include<bits/stdc++.h>
using namespace std;
using ll = long long;

typedef struct
{
    ll sum;
    int index;
}DATA;

int main()
{
    int n,k; cin >> n >> k;
    deque<DATA> dq;
    DATA temp = {0,0};
    dq.emplace_back(temp);
    int sum = 0;
    ll mx=0,memo=0;
    for(int i=1;i<=n;++i)
    {
        int t; cin >> t;
        sum+=t;
        while(!dq.empty() and i - dq.front().index +1 > k) dq.pop_front();
     //   while(!dq.empty() and dq.back().sum >= sum) dq.pop_back();
        DATA temp = {sum,i};
        dq.emplace_back(temp);
        if(dq.back().sum - dq.front().sum > mx) {mx=sum;memo=i-dq.front().index;}
        else if(dq.back().sum - dq.front().sum == mx and i-dq.front().index < memo)
            memo = i-dq.front().index;
    }

    cout << mx << " " << memo;
}
