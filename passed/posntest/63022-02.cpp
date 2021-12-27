#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> hilo,lohi;
    if(n%2==0)
    {
        for(int i=0;i<n/2;++i)
        {
            int r = rand(); r%=99; r++;
            hilo.push_back(-r);
            r = rand(); r%=99; r++;
            lohi.push_back(r);
        }
    }
    else
    {
        for(int i=0;i<=n/2;++i)
        {
            int r = rand(); r%=99; r++;
            hilo.push_back(-r);
        }
        for(int i=n/2+1;i<n;++i)
        {
            int r = rand(); r%=99; r++;
            lohi.push_back(r);
        }
    }
    for(int i=0;i<hilo.size();++i) cout << -hilo[i] << " ";
    for(int i=0;i<lohi.size();++i) cout << lohi[i]  << " ";
    cout << endl;
    sort(lohi.begin(),lohi.end()); sort(hilo.begin(),hilo.end());
    for(int i=0;i<hilo.size();++i) cout << -hilo[i] << " ";
    cout << "| ";
    for(int i=0;i<lohi.size();++i) cout << lohi[i]  << " ";
}

