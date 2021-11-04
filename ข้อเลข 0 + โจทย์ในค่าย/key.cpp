#include<bits/stdc++.h>
using namespace std;
int n,alen,blen;
string a,b;

map<vector<char>,bool > us;

int start(int x,int y,vector<char> v,int xy)
{
    if(xy==1)
    {
        v.push_back(a[x]);
        x++;
    }
    else if(xy==2)
    {
        v.push_back(a[y]);
        y++;
    }
    //cout << x << " " << y << " " << alen << endl;
    if(x!=alen)
    start(x,y,v,1);
    if(y!=blen)
    start(x,y,v,2);

    if(x+y==n) {us[v]=true;
       // for(auto it  : v ) cout << it << " " ;
       // cout << endl;
     return 0;}

}

int main()
{
    cin >> a >> b;
    alen = a.length();
    blen = b.length();
    n = alen+blen;
    char mix[n];
    vector<char> v;
    start(0,0,v,1);
    start(0,0,v,2);

    int q;
    cin >> q;
    for(int i=0;i<q;++i)
    {
        string qu;
        cin >> qu;
        vector<char> fnd;
        for(int j=0;j<qu.length();j++) fnd.push_back(qu[j]);
        if(us[fnd]==true) cout << "Yes\n"; else cout << "No\n";
    }

}
