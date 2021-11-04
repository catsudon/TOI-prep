#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;

int main()
{
    int n;
    cout << "Node : ";cin >> n;
    vector<int> v[n+1];
    int e;
    cout << "Edge : ";cin >> e;
    for(int i=0;i<e;++i)
    {
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
    }

    vector<int> l;
    stack<pair<int,vector<int> > > st;
    st.push({1,l});

    while(!st.empty())
    {
        int F = st.top().f;
        vector<int> S = st.top().s;
        st.pop();
        S.push_back(F);
        if(v[F].empty())
        {
            for(auto it : S) cout << it;
            cout << "\n";
            continue;
        }
        for(auto it : v[F])
        {
            st.push({it,S});
        }

    }
}

