#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> time(100009,0);

    for(int i=0;i<n;++i)
    {
        int s,e; cin >> s >> e;
        time[s]++;
        time[e]--;
    }

    int mx=-1;
    int memo=-1;
    for(int i=1;i<100001;++i)
    {
        time[i] += time[i-1];
        if(time[i]>mx) mx=time[i],memo=i;
    }

    time[memo]==n ? cout << "yes " : cout << "no ";
    cout << memo;


}
