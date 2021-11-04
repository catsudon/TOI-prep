#include<bits/stdc++.h>
using namespace std;
const int MXN = 1e9;

struct fenwick
{
    int a[MXN+9];
    void update(int i,int val)
    {
        for(;i<=MXN;i+=i&-i) a[i]+=val;
    }
    int query(int i)
    {
        int sum=0;
        for(; i>0; i-=i&-i) sum+=a[i];
        return sum;
    }
};

int main()
{

}
