#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    deque<int> v;
    for(int i=0;i<n;++i)
    {
        int a; cin >> a;
        v.push_back(a);
    }
    int w=v.size();
    for(int i=0;i<w-1;++i)
    {
        if(v[i] == v.back()){
            v.push_front(v.back());
            v.pop_back();
        }
    }
    cout << v.front()+v.back();
}
