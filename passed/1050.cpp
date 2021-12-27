#include<bits/stdc++.h>
using namespace std;
vector<int> v[100009];
vector<int> want;
map<vector<int>, int> m;
int i,j,a;
int main()
{
    int n,p;
    scanf("%d %d",&n,&p);
    if(n==0 || p==0)
    {
        printf("NO");
        return 0;
    }
    for(i=0;i<n;++i)
    {
        vector<int> v;
        for(int j=0;j<p;++j)
        {
            scanf("%d",&a);
            v.push_back(a);
        }
      //  if(m[v]==NULL)
      m[v] = i+1;
    }
    for(int i=0;i<p;++i)
    {
        scanf("%d",&a);
        want.push_back(a);
    }
    auto it = m.find(want);
    if(it!=m.end())
    {
        printf("%d",it->second);
        return 0;
    }
    for(auto tt : m)
    {
        vector<int> wv;
        for(int j=0;j<p;++j)
        {
            a = want[j]-tt.first[j];
            wv.push_back(a);
        }
        auto it = m.find(wv);
        if(it!=m.end() && it->second!=tt.second)
        {
            printf("%d %d",min(tt.second,it->second),max(tt.second,it->second));
            return 0;
        }
    }
    printf("NO");
}
