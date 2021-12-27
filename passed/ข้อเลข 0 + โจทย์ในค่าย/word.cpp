#include<bits/stdc++.h>
using namespace std;
char board[26][26];

int check(int i,int j,string a)
{
    int direction[8] = {1,1,1,1,1,1,1,1};
    for(int k=1;k<a.length();++k)
    {
     //   cout << i << " " << j << " " <<  board[i+1][j+1] << " " << a[k] << endl;
        if(board[i][j+k]==a[k] && direction[0]==1){}
        else direction[0]=-1;
        if(board[i+k][j+k]==a[k] && direction[1]==1){}
        else direction[1]=-1;
        if(board[i+k][j-k]==a[k] && direction[2]==1){}
        else direction[2]=-1;
        if(board[i+k][j]==a[k] && direction[3]==1){}
        else direction[3]=-1;
        if(board[i-k][j-k]==a[k] && direction[4]==1){}
        else direction[4]=-1;
        if(board[i-k][j+k]==a[k] && direction[5]==1){}
        else direction[5]=-1;
        if(board[i-k][j]==a[k] && direction[6]==1){}
        else direction[6]=-1;
        if(board[i][j-k]==a[k] && direction[7]==1){}
        else direction[7]=-1;

    //    for(int o=0;o<8;++o) cout << direction[o] << " ";
      //  cout << endl;
    }
    for(int i=0;i<8;++i) if(direction[i]==1) return 1;
    return 0;
}

int main()
{
    int m,n; cin >> m >> n;
    for(int i=0;i<m;++i) for(int j=0;j<n;++j)
        {
            cin >> board[i][j];
            if(islower(board[i][j])) board[i][j] = toupper(board[i][j]);
        }
    int q;
    cin >> q;
    for(int i=0;i<q;++i)
    {
        int x=1;
        string a;
        cin >> a;
        for(int j=0;j<a.length();++j) if(islower(a[j])) a[j] = toupper(a[j]);
       // cout << a << endl;
       if(x)
        for(int k=0;k<m;++k)
            if(x)
            for(int l=0;l<n;++l)
        {
            if(board[k][l]==a[0] && x)
            {
                int ok = check(k,l,a);
                if(ok) {cout << k << " " << l << "\n";
                x=0;}
            }

        }
    }


}
