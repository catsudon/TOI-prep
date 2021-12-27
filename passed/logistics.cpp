#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using pii = pair<int,int>;
bool vst[30];
vector<pii> path; // before && now
vector<pii> v[30];
bool fin = false;
double ssum = 0;
int start(int x,int y)
{
    if(vst[y] or fin) return 0;
  //  cout << char(96+x) << " " << char(96+y) << endl;
    if(x!=y) path.push_back({x,y});
    if(y+96=='{') fin = true;
    vst[y] = true;
    if(!fin)
    {
        for(auto it : v[y]) if(!vst[it.s]) start(y,it.s); // now && next
    }
    if(x!=y and !fin) path.pop_back();
    vst[y] = false;
}
double median(vector<int> lst)
{
    int n = lst.size();
    sort(lst.begin(),lst.end());
    if(n%2==0) return (lst[n/2-1]+lst[n/2])*0.5;
    else return lst[n/2];
}
int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n;++i)
    {
        char a,b;
        int dis;
        cin >> a >> b >> dis;
        if(a=='X') a = char(96);
        else if(a=='Y') a = char(123);
        if(b=='X') b = char(96);
        else if(b=='Y') b = char(123);
        v[a-96].push_back({dis,b-96});
        v[b-96].push_back({dis,a-96});
    }
    // DFS
    start(0,0); // 0 to 0 (X to X)
    if(!fin)
    {
        cout << "broken"; return 0;
    }
    for(auto it : path)
    {
        if(it.f==0) cout << "X";
        else cout << char(96+it.f);
        cout << " ";
        if(it.s==27) cout << "Y";
        else cout << char(96+it.s);
        cout << " " ;
        // med
        vector<int> mv;
        for(auto ti : v[it.f])
        {
            if(ti.s == it.s) mv.push_back(ti.f);
        }
        double sum = median(mv);
        printf("%.1f\n",sum);
        ssum += sum;
    }
    printf("%.1f\n",ssum);
}
