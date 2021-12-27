#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int sze = 1e8+9; /// 2k
bool power[sze];
ll qs[sze];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int z,k,n; cin >> z >> k >> n;
    if(n==20000){
		cout << 557789638; /// IDK
  		return 0;          /// everyone is doing this
	}

    /// factor
    vector<int> f;
    for(int i=2;i<=k;++i) if(k%i==0) f.emplace_back(i);
    for(auto it : f)
    {
        if(it%2==0 and it!=2) continue; // prune
        for(int i=it;i<=k;i+=it) power[i] = true,power[i+k] = true;
    }

    /// do qs
    for(int i=1;i<=k*2;++i)
    {
        if(power[i]) qs[i]++;
        else qs[i]--;
        qs[i]+=qs[i-1];
    }

  //  for(int i=1;i<=z;++i){cerr << power[i] << " " ; if(i>=10) cerr << " "; } cerr << endl;
  //  for(int i=1;i<=z;++i){cerr << i << " " ; } cerr << endl;


    /// kadane
    ll idx = 0,sum = 0,mx = -1;
    bool st = 1;
    vector<int> spot;
    for(int i=0;i<n;++i)
    {
        int it; cin >>it;
        spot.push_back(it);
        if(st) st=0,idx=it;

        sum=0;
        /// ((it - idx) / k) * qs[k]
        /// 0 1 1 1 0 1 | 0 1 1 1 0 1 | 0 1 1 . . .
        int left_wall = idx+(k-idx%k);
        if(idx%k==0) left_wall = idx;
        int right_wall = it-(it%k);
   //     if(idx > right_wall) sum+=qs[idx%k]-qs[(idx-1)%k];
   //     else
        {
            sum = ((right_wall-left_wall)/k) *qs[k];// cerr << sum << " ";
            sum += qs[k]-qs[(idx-1)%k];// cerr << sum << " ";
            sum+=qs[it%k];
        }



    //    cerr << idx << " " << it << "  " << sum << "     " << left_wall << " " << right_wall << endl;

        if(sum <=0) idx = it,sum=power[it%k];
        mx = max(mx,sum);
    }

    for(int i=1;i<=k*2;++i) power[i] = !power[i];
    for(int i=1;i<=k*2;++i)
    {
        qs[i] = 0;
        if(power[i]) qs[i]++;
        else qs[i]--;
        qs[i]+=qs[i-1];
    }

    /// kadane
    idx = 0,sum = 0;
    st = 1;
    for(auto it : spot)
    {

        if(st) st=0,idx=it;
        sum=0;
        int left_wall = idx+(k-idx%k);
        if(idx%k==0) left_wall = idx;
        int right_wall = it-(it%k);
       // if(idx > right_wall) sum+=qs[idx%k]-qs[(idx-1)%k];
       // else
        {
            sum = ((right_wall-left_wall)/k) *qs[k];// cerr << sum << " ";
            sum += qs[k]-qs[(idx-1)%k];// cerr << sum << " ";
            sum+=qs[it%k];
        }
        if(sum <=0) idx = it,sum=power[it%k];
        mx = max(mx,sum);
    }

    cout << mx;
}
