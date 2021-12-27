#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using pii = pair<int,int> ; // pos : hei

pii a[100009];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    if(n==1) {cout << 1 << ' ' << 'R'; return 0; }

    int streak = 1, mxstreakR = 1 , mxstreakL;
    int memo = -1 ,memoL=-1, op = -1;
    bool R=1;
    int nagai=0;
    for(int i=1;i<=n;++i) cin >> a[i].f >> a[i].s;

    memo=1,op=1,nagai=a[1].f+a[1].s; if(streak > mxstreakR) mxstreakR=streak , memo = op;

    for(int i=2;i<=n;++i)
    {
        if(a[i-1].f+a[i-1].s > a[i].f or nagai > a[i].f)
        {
            nagai = max(nagai , a[i].f+a[i].s);
            streak++;
        }
        else streak=1,op=i,nagai=a[i].f+a[i].s;

        if(streak > mxstreakR) {mxstreakR=streak , memo = op;}

        cerr << streak << " streak  from " << a[op].f << " long to " << nagai << '\n';
    }

    cerr << endl << endl;

    op = -1 , streak = 1 , nagai = INT_MAX;
    for(int i=n;i>=1;--i)
    {
        if(i==n) op = n,nagai=a[i].f-a[i].s;
        else
        {
            if(a[i+1].f-a[i+1].s < a[i].f or nagai < a[i].f)
            {
                nagai = min(nagai,a[i].f-a[i].s);
                streak++;

            }
            else {streak=1,op=i,nagai=a[i].f-a[i].s;}
        }

        if(streak >= mxstreakL) {mxstreakL = streak , memoL = op;}


    //    cerr << streak << " streak  from " << a[op].f << " long to " << nagai << '\n';
    }

    if(mxstreakR > mxstreakL)
    {
        cout << memo;
        cout << " R";
    }
    else if( mxstreakR == mxstreakL )
    {
        if(memo <= memoL) cout << memo << " R";
        else cout << memo << " L";
    }
    else cout << memoL << " L";


}
