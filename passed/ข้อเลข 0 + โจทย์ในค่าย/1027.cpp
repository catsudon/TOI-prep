#include<bits/stdc++.h>
using namespace std;
int point[8] = {0,0,0,0,0,0,0};
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int left=7;
    while(true)
    {
        int mn = INT_MAX,x=1;
        string a;
        cin >> a;
        if(a[0]=='!') break;
        for(int i=0;i<a.length();++i)
        {
            if(point[a[i]-'A']>=0) point[a[i]-'A']++;
        }
        int prepare_to_kick;
        for(int i=0;i<7;++i)
        {
            if(point[i]<mn && point[i]>=0)
            {
                mn = point[i];
                prepare_to_kick = i;
            }
        }
        for(int j=0;j<7;++j)
        {
            if(point[j]==mn && j!=prepare_to_kick) x=0;
        }
        if(x && left!=1) {point[prepare_to_kick] = -300002;left--;}
    }


    vector<pair<int,char> > v;
    for(int i=0;i<7;++i)
    {
        if(point[i]>=0) v.push_back({-point[i],'A'+i});
    }
    sort(v.begin(),v.end());
    cout << v.size() << "\n" ;
    for(auto it : v)
    {
        cout << it.second << " " << -it.first << "\n";
    }
}
