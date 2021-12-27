#include<bits/stdc++.h>
#define left first
#define right second
using namespace std;
using pii = pair<int,int>;
int lft[1000009];
int rght[1000009];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    int tower[n+2];

    for(int i=1;i<=n;++i)
    {
        lft[i] = i;
        rght[i] = i;
        cin >> tower[i];
        int temp = i;
        while(tower[i] >= tower[temp-1] and temp > 1) temp -= (lft[temp-1] +1) ;
        lft[i] = i-temp;
    }

 //   int ans[n+1];

    for(int i=n;i>=1;--i)
    {
        /// right
        int temp = i;
        while(tower[i] >= tower[temp+1] and temp<n) temp+= (rght[temp+1]+1);
        rght[i] = temp-i;
     //   if(tower[i] == 45) cerr << "temp of " << i << " is " << temp << endl;
    }

    for(int i=1;i<=n;++i) cout << lft[i]+1+rght[i] << " ";
}
