#include<bits/stdc++.h>
using namespace std;
// canonical list
int canon[3*262150];
// if index start from 1
// left node = 2x
// right node = 2x+1
// parent = x/2

int n,q;
int idx,val; // updating idx , val
void insert(int x , int l , int r)
{
    if(l==r)
    {
        canon[x] = val; // reached leaf node
    }
    else
    {
        int mid = (l+r)/2;
        if(idx <= mid ) insert(2*x,l,mid);
        if(idx >  mid ) insert(2*x+1,mid+1,r);
    //    canon[x] = max(canon[x],val);  // can't be used because it doesn't update the val
        canon[x] = max(canon[2*x],canon[2*x+1]);
    }

}

int L,R;
int query(int x , int l , int r)
{
    int mid=(l+r)/2;
    if(l >= L and r <= R) return canon[x]; // x is a subset of the query
    if(r < L  or  l >  R) return INT_MIN;  // out of range
    return max(query(2*x,l,mid) , query(2*x+1,mid+1,r));
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
        // for(int i=1;i<=14;++i)  cerr << canon[i] << ' ';
        // cerr << "__________________________\n";
    }

}
