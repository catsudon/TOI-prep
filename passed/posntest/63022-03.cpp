#include<iostream>
#include<vector>
using namespace std;

bool isprime(int n)
{
    for(int i=2;i<=n/2;++i) if(n%i==0) return false;
    return true;
}

int main()
{
    int n; cin >> n;
    vector<int> prime;
    for(int i=2;i<1000000;++i)
    {
        if(prime.size()==n) break;
        if(isprime(i)) prime.push_back(i);
    }
    for(int i=0;i<prime.size();++i)
    {
        cout << prime[i];
        if(i!=prime.size()-1) cout << ", ";
    }
}
