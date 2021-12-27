#include<bits/stdc++.h>
using namespace std;
int blueprint[10][10];
int test[10][10];


bool check_ver(int y)
{
    bool ok = true;
    vector<bool> have(10,false);
    for(int i=1;i<=9;++i) /// [i][y]
    {
        if(test[i][y]!=blueprint[i][y] and blueprint[i][y]!=0) {ok=false; break;}
        if(have[test[i][y]]) {ok=false; break;}
        have[test[i][y]] = true;
    }
    return ok;
}

bool check_hori(int x)
{
    bool ok = true;
    vector<bool> have(10,false);
    for(int i=1;i<=9;++i) /// [x][i]
    {
        if(test[x][i]!=blueprint[x][i] and blueprint[x][i]!=0) {ok=false; break;}
        if(have[test[x][i]]) {ok=false; break;}
        have[test[x][i]] = true;
    }
    return ok;
}


int main()
{
    int n; cin >> n;
    for(int i=1;i<=9;++i) for(int j=1;j<=9;++j) cin >> blueprint[i][j];

    for(int k=1;k<=n;++k)
    {
        int x=1;
        for(int i=1;i<=9;++i) for(int j=1;j<=9;++j) cin >> test[i][j];
        //  | | |
        for(int i=1;i<=9 and x;++i) if(check_ver(i)==false) x=0;

        // _ _ _
        for(int i=1;i<=9 and x;++i) if(check_hori(i)==false) x=0;

        if(x) cout << k << endl;
    }
    cout << "END";
}

