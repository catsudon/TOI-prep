#include<bits/stdc++.h>
using namespace std;
int cnt[200];
int main()
{
    string a,b;
    cin >> a >> b;
    for(int i=0;i<a.length();++i)
    {
        cnt[a[i]]++;
    }
    int point=0;
    for(int i=0;i<b.length();++i)
    {
        if(cnt[b[i]]>0)
        {
            point++;
            cnt[b[i]]--;
        }
    }
    cout << point;
}
