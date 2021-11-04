#include<bits/stdc++.h>
using namespace std;
map<vector<bool>,int> mp;
int mn = INT_MAX;
int n;
 ///      bulb             offcnt    timecnt
int jordi(vector<bool> el,int nino,int polla) /// use Jordi Polla's algorithm
{
    if(mp[el]!=NULL and mp[el]<=polla or polla >=mn) return 0;
    if(nino == n) {
            mn=min(mn,polla);
   // cerr << "yabai " << polla << endl;
            return 0;}
    mp[el] = polla;
    polla++;

   // for(auto it : el) cerr << it << " " ;
   // cerr << nino << endl;

    for(int i=0;i<n;++i)
    {
        vector<bool> kus = el;
        int temp = nino;
        if(kus[i]) {temp++; kus[i]=0;}
        else {temp--; kus[i] = 1;}

        if(i>0)
        {
            if(kus[i-1]) {temp++; kus[i-1]=0;}
            else {temp--; kus[i-1]=1;}
        }

        if(i<n-1)
        {
            if(kus[i+1]) {temp++; kus[i+1]=0;}
            else {temp--; kus[i+1]=1;}
        }


        jordi(kus,temp,polla);

    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    vector<bool> v(n);
    int cnt=0;
    for(int i=0;i<n;++i)
    {
        int a; cin >> a;
        a==0 ? v[i] = false,cnt++ : v[i]=true;
    }
    jordi(v,cnt,0);
    if(mn==INT_MAX) cout << -1; else cout << mn;
}
