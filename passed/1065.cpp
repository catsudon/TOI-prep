#include<bits/stdc++.h>
using namespace std;
typedef struct tomori
{
    int x1,y1,x2,y2;
};

int n,m;
vector<tomori> v;

bool tomoriru(tomori a ,tomori b)
{
    if(b.x1 >= a.x2) return false;
    if(a.x1 >= b.x2) return false;
    if(a.y1 <= b.y2) return false;
    if(a.y2 >= b.y1) return false;

    return true;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i=0;i<n;++i)
    {
        int a,b,c,d; cin >> a >> b >> c >> d;
        tomori t = {a,b,c,d};
        v.emplace_back(t);
    }
    while(m--)
    {
        int a,b,c,d,cnt=0; cin >> a >> b >> c >> d;
        tomori t = {a,b,c,d};
        for(auto it : v) if(tomoriru(t,it)) cnt++; cout << cnt << endl;
    }

}
