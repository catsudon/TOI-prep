#include<bits/stdc++.h>
using namespace std;
bool vst[5009];
int main()
{
    int n,k; cin >> n >> k;
    deque<int> q;
    for(int i=1;i<=n;++i) q.push_back(i);

    while(n--)
    {
        int tm = (k-1)%q.size();
        int trace = tm;
        while(tm>0)
        {
            q.push_back(q.front());
            q.pop_front();
            tm--;
        }
        cout << q.front() << endl;
     //   vst[q.front()]=1;
        q.pop_front();
   /*     while(trace>0)
        {
            q.push_front(q.back());
            q.pop_back();

            trace--;
        } */
      //  for(auto it : q) cout << it << ' '; cout << endl;
    }
}
