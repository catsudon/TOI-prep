#include<bits/stdc++.h>
using namespace std;
int mn = INT_MAX;
struct shop{
int x,y,z;
int moni,key,cpu;
};

int n,monitor,keyboard,cpu;
vector<struct shop> v;
int shop_count;
bool vst[10];
int start(int px,int py,int pz,int distance,int shop,int moni,int key,int cp)
{
    if(distance==-1)
    {
        for(int i=0;i<shop_count;++i)
        {
            if(!vst[i])
            {
                vst[i] = true;
                start(px,py,pz,0,i,0,0,0);
                vst[i] = false;
            }
        }
    }
    else
    {
        moni += v[shop].moni;
        key  += v[shop].key;
        cp  += v[shop].cpu;
        distance+=  (px - v[shop].x) * (px - v[shop].x) +
                    (py - v[shop].y) * (py- v[shop].y) +
                    (pz - v[shop].z) * (pz - v[shop].z);
        px = v[shop].x;
        py = v[shop].y;
        pz = v[shop].z;
        if(moni>=monitor && key>=keyboard && cp>=cpu)
        {
            if(distance<mn) mn = distance;

            return 0;
        }
        else{

        for(int i=0;i<shop_count;++i)
        {
            if(!vst[i])
            {
                vst[i] = true;
                start(px,py,pz,distance,i,moni,key,cp);
                vst[i] = false;
            }
        }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    cin >> n;

    monitor=n,keyboard=n,cpu=n;
    int sx,sy,sz;

    cin >> sx >> sy >> sz;

    cin >> shop_count;

    for(int i=0;i<shop_count;++i)
    {
        int a,b,c,d,e,f;
        cin >> a >> b >> c >> d >> e >> f;
        struct shop s;
        s.x=a; s.y=b; s.z=c;
        s.moni=d; s.key=e; s.cpu=f;
        v.push_back(s);
    }
    start(sx,sy,sz,-1,0,0,0,0);
    cout << mn;

}
