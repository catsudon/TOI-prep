#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll legend = 98765431;
const int N = 200009;
int a[N],b[N];
int n,k;
map<ll,bool> mp;
vector<int> factor[109]; // factor of 1,2,3,...100


void perm(int lv,ll hsh)
{
    if( lv > k )
    { cerr << hsh << " : " ; mp[hsh] = 1; return ;  }
    for(auto it : factor[b[lv]])
    {
        ll temp = hsh;
        temp*=legend;
        temp += it;
        cerr << lv+1 << ":"<<temp << endl;
        perm(lv+1,temp);
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    for(int i=1;i<=n;++i) {cin >> a[i]; if(a[i]==1) a[i]=101;}
    for(int i=1;i<=k;++i) {cin >> b[i]; if(b[i]==1) b[i]=101;}

    int prime[25] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    for(int i=0;i<25;++i)
    {
        int p = prime[i];
        for(int j=p;j<=100;++j) if(j%p == 0) factor[j].push_back(p);
    }

    // perm B
    perm(1,0);

  cerr << "hashed :";  for(auto it : mp) cerr << it.first << " "; cerr << "\n\n";
    ll check = 0;
    ll memo=1;
    for(int i=1;i<=k;++i)
    {
        if(i!=k-1) memo *= legend;

        check *= legend;
        check += a[i];
    }
    cerr << check << " ";
    int cnt = 0; if(mp[check]==1) cnt++;

    for(int i=k+1;i<=n;++i)
    {
        check -= memo*a[i-k];
        check *= legend;
        check += a[i];
        cerr << check << " ";
        if(mp[check]==1) cnt++;
    }

    cout << cnt;


}
