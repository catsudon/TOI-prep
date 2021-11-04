#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using ll = long long;
const int sze = 1034001;
const int pls = 3;
pair<int,string> code[100009];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie();
    int k,m; cin >> k >> m;
    int verify[k+9];
    bool check[100009]; for(int i=1;i<=k;++i) check[i] = 0;
    vector<int> table(sze,-1);
    for(int i(1);i<=k;++i){cin >> code[i].s; code[i].f = i;}
    shuffle(code+1,code+1+k,default_random_engine('H'+'E'+'L'+'L'+' '+'N'+'O'+'!'));
    for(int i(1);i<=k;++i)
    {
        string t = code[i].s;
        int idx = code[i].f;
        ll sum(0);
        ll lg(1);
        for(int j=m-1;j>=0;--j)
        {
            sum+=(int(t[j])-48)*lg;
            lg=(lg<<1);
        }
        ll sum2 = (sum)%sze;
        while(table[sum2] != -1)
        {
            sum2+=pls;
            sum2%=sze;
        }
        table[sum2] = idx;
        verify[idx] = sum;
    }
    int n; cin >> n;
    while(n--)
    {
        ll lg = 1;
        ll llenn;
        string t;
        cin >> llenn >> t;;
        if(llenn < m)
        {
            cout << "OK\n";
            continue;
        }
        ll sum = 0,memo = (1<<m-1);
        for(int j=m-1;j>=0;--j)
        {
            sum+=(int(t[j])-48)*lg;
            lg*=2;
        }
        ll sum2=(sum)%sze;
        while(table[sum2]!=-1)
        {
            if(verify[table[sum2]] == sum) {check[table[sum2]]=1; break;}
            sum2+=pls;
            sum2%=sze;
        }
        for(int j=m;j<llenn;++j)
        {
            sum-=(t[(j-m)]-48)*memo;
            sum=(sum<<1);
            sum+=t[j]-48;
            sum2 = sum%sze; //cerr << sum2 << endl;
            while(table[sum2]!=-1)
            {
                if(verify[table[sum2]] == sum)
                {check[table[sum2]]=1; break;}
                sum2+=pls; //cerr << sum2 << endl;
                sum2%=sze;
            }
        }
        bool ok=1;
        for(int i=1;i<=k;++i)
        {
            if(!check[i]) continue;
            cout << i<< " "; ok=0; check[i]=0;
        }
        if(ok) cout << "OK";
        cout << "\n";
    }
}
