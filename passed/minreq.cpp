#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll lift[69];
ll adult[69];
ll qs[10000009];
ll T[69];
ll point[69];
ll lim=0; bool ok;
int n,s,x; // lift/student/case

void simulate()
{
//    cerr << "adult : ";
 //   for(int i=1;i<=n;++i) cerr << adult[i] << " " ;
 //   cerr << endl << "   Time limit = " << lim << endl;
    bool pass = 1;
    for(int i=1;i<=n and pass;++i) // lift
    {
        ll sum = 0;
        ll op = 1;
      //  cerr << "lift " << i <<  " : \n";
        ll cnt=0;
        while(op<=point[i+1])
        {
            ll l = point[i];
            ll r = point[i+1];
        //    cerr << l << " " << r << endl;
            while(l<=r)
            {
                ll mid = (l+r)/2;
                if(qs[mid]-qs[op-1] + adult[i] > lift[i]) r=mid-1;
                else l=mid+1;
             //   cerr << "   " << l << " " << r << " " << mid << endl;
            }
            cnt++;
          //  cerr << "from " << op << " to " << l << " costed " << qs[l]-qs[op-1]+adult[i] << " (lim is " << lift[i] <<") on position " << point[i+1] << endl;
            if(op == l and qs[l]-qs[op-1]+adult[i] > lift[i]) {pass=0;break;}
            op = l;
            if(op==point[i+1] and qs[op]-qs[op-1] <= lift[i])
            {
                cnt++;
                if(cnt <= lim ) {pass = 1; break;}
            }
            if(cnt > lim) {pass=0; break;}
        }
    }
    if(pass) ok=1;
}

void sol()
{
    for(int i=1;i<=n;++i) cin >> point[i];
    point[n+1] = s;
    do // compute all the possibilities
    {

        simulate();

    }while(!ok and next_permutation(adult+1,adult+1+n));

}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> s >> x;
    for(int i=1;i<=n;++i) cin >> lift[i];
    for(int i=1;i<=n;++i) cin >> adult[i];
    for(int i=1;i<=s;++i)
    {
        cin >> qs[i];
        qs[i]+=qs[i-1];
    }
    for(int i=1;i<=x;++i) cin >> T[i];

    for(int i=1;i<=x;++i)
    {
        lim = T[i]; ok = 0;
        sol();
        if(ok) cout << "P\n" ; else cout << "F\n";

     //   cerr << endl << endl;
    }

}
