#include<bits/stdc++.h>
using namespace std;
int n,w;
int mx=0;
int items[10009];
int knap(int num,vector<bool> pkd,int sum)
{
    pkd[num] = true;
    sum+=items[num];
    if(sum>w) return 0;
    if(sum>mx) mx=sum;
    for(int i=0;i<n;++i)
    {
        if(!pkd[i]) knap(i,pkd,sum);
    }

}

int main()
{
    cin >> n >> w;
    for(int i=0;i<n;++i)
    {
        cin >> items[i];
    }
    for(int i=0;i<n;++i)
    {
        vector<bool> pkd(n,false);
        knap(i,pkd,0);
    }
    cout << mx;
}
