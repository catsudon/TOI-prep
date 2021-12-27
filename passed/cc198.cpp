#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll legend = 98765431;
int n,m;
int a[200009];
int b[200009];
int prime[25] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
ll memo[200009];
unordered_set<ll> hsh;


int main()
{
    ios_base::sync_with_stdio(0); cin.tie();
    cin >> n >> m;
    vector<int> ONE_POS;
    memo[0]=1;
    for(int i=1;i<=n;++i)
    {
        cin >> a[i];
        memo[i] = memo[i-1]*legend;
    }
    ll cmp=0,sum=0;
    for(int j=1;j<=m;++j)
    {
        cin >> b[j];
        if(b[j] == 1) ONE_POS.push_back(j);
        cmp*=legend;
        cmp+=b[j];
        sum*=legend;
        sum+=a[j];
    }
    ll temp = sum;
    cerr << "compare  =  " << cmp << endl;
  //  cerr << "temp = " << temp << endl;
    for(auto it : ONE_POS)
    {
    //    cerr << it << ' ' << a[it] << " * " << m-it << endl;
        temp -= a[it]*memo[m-it];
        temp += memo[m-it];
    }
  //  cerr << "temp = " << temp << endl;

    int cnt=0;
    if(temp == cmp) cnt++;
    cerr << "from "<<sum<<" to "<<temp << '\n' <<endl;


    for(int i=m+1;i<=n;++i)
    {
        int l = i-m;
        sum -= a[i-m]*memo[m-1];       // legend^(m-1)
        sum *= legend;
        sum += a[i];

        temp = sum;

        for(auto it : ONE_POS)
        {
         //   cerr << "pos " <<it << ' ' << "val = " << a[l+it] << ' ' <<"10^"<< m-it << endl;
            sum -= a[l+it]*memo[m-it];
            sum += memo[m-it];
        }
        if(sum == cmp) cnt++; //cerr << "from "<< temp<<" to "<< sum << '\n' <<'\n';
        sum = temp;

    }


    cout << cnt;





}
