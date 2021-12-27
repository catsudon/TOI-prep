#include<bits/stdc++.h>
using namespace std;
// canonical list
int kanon[2*262145]; // in this problem max N is 262144, which is power of two, but if not we need to multiply by 4
// if index start from 1
// left node = 2x
// right node = 2x+1
// parent = x/2

int n,q;
int idx,val; // updating idx , val
void insert(int x , int l , int r)
{
    if(l==r) kanon[x] = val;
    else
    {
        int mid = (l+r)/2;
        if(idx > mid) insert(2*x+1,mid+1,r);
        else insert(2*x,l,mid);
        kanon[x] = max(kanon[2*x],kanon[2*x+1]);
    }
}

int L,R;
int query(int x , int l , int r)
{
    int mid = (l+r)/2;
    if(l >= L and r <= R) return kanon[x];
    if(r < L or l > R) return INT_MIN;

    return max(query(2*x,l,mid),query(2*x+1,mid+1,r));
}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> q;
    while(q--)
    {
        char cmd;
        int a,b; cin >> cmd >> a >> b;
        if(cmd == 'U')
        {
            idx=a , val=b;
            insert(1,1,n);
        }
        else
        {
            L=a , R=b;
            cout << query(1,1,n) << '\n';
        }
        // cerr << "__________________________";
        // for(int i=1;i<=14;++i)  cerr << kanon[i] << ' ';
        // cerr << "__________________________\n";
    }

}
