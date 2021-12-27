#include<bits/stdc++.h>
using namespace std;
string shift = " SHIFT";
string space = " SPACEBAR";
bool valid[300];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);


    valid['Q']=1;
    valid['W']=1;
    valid['E']=1;
    valid['A']=1;
    valid['S']=1;
    valid['D']=1;
    valid['V']=1;

    int len; cin >> len;
    int cnt = 0;
    int val = 0;
    string a; cin >> a;
    int state = 0; // 0 = no streak : 69 = started with s (may be both)
    // -1 -2 -3  = shift
    //  1  2  3  = spacebar
    for(auto it : a)
    {
        if(valid[it] ) val++;

        if(state == 0  and it == 'S')
        {
            state = 69;
            val = 1;
        }
        else if(state == 0 and it != 'S')
        {
            if(valid[it]) cnt++;
            val=0;
        }
        else if(state == 69)
        {
            if(it == shift[2]) state = -2;
            else if(it == space[2]) state =  2;
            else if(it == 'S') cnt++ , val=1;
            else state=0 , cnt+=val , val = 0;
        }
        else if(state < 0 )
        {
            if(shift[abs(state-1)] == it) state--;
            else if(it == 'S') cnt+=val-1 , state = 69 , val=1;
            else cnt += val , state = 0;

            if(state == -5) state = 0 , cnt++ , val=0;
        }
        else if(state > 0)
        {
            if(space[state+1] == it ) state++;
            else if(it == 'S') cnt+=val-1 , state = 69 , val=1;
            else cnt += val , state = 0;

            if(state == 8) state = 0 , cnt++ , val = 0;
        }

   //     cerr << cnt << ' ' << val << "    " << state << endl;
    }

    cnt+=val;

    cout << cnt;
}
