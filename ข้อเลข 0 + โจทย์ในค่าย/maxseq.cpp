#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    int num[n+1];
    pair<int,int> mx[n+1];
    mx[0]={0,0};
    int mxnum=0,mxseq,pos;
    for(int i=1;i<=n;++i)
    {
        mx[i] = {0,0};
        cin >> num[i];
        if(mx[i-1].first+num[i]>0)
        {
            mx[i].first = mx[i-1].first+num[i];
            mx[i].second = mx[i-1].second+1;
            if(mx[i].first>mxnum) {mxnum=mx[i].first;mxseq=mx[i].second;pos=i-mxseq;}
        }
    }
    if(mxnum==0) cout << "Empty sequence";
    else {
        for(int i=pos+1;i<=pos+mxseq;++i) cout << num[i] << " ";
        cout << endl;
        cout << mxnum;
    }


}
