#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,w=0,mx=0,x,y; cin >> n;
    int p[n],h[n];
    for(int i=0;i<n;++i)
    {
        cin >> p[i] >> h[i];
        mx = max(mx,h[i]);
        w = max(w,p[i]+(2*h[i]));
    }

    char cromartie[mx][w];
    // insert .
    for(int i=0;i<mx;++i) for(int j=0;j<w;++j) cromartie[i][j] = '.';

    for(int i=0;i<n;++i)
    {
        x = mx-1;
        y = p[i]-1;
        // insert /
        for(int j=0;j<h[i];++j)
        {
            cromartie[x-j][y+j] = '/';
        }
        x = mx-h[i];
        y = y+h[i];
        // insert \

        for(int j=0;j<h[i];++j)
        {
            cromartie[x+j][y+j] = '\\';
        }
    }


    //  insert X

    for(int i=0;i<mx;++i)
    {
        for(int j=0;j<w-1;++j)
        {
            int x=0;
            for(int k=i-1;k>=0;--k) if(cromartie[k][j]=='\\' or cromartie[k][j]=='/' or cromartie[k][j]=='v') x=1;
            if(x) cromartie[i][j] = 'X';

            if((cromartie[i][j]=='/' or cromartie[i][j]=='v') and cromartie[i][j+1]=='/') cromartie[i][j+1] = 'v';
        }
    }

    // insert v

    for(int i=mx-1;i>0;--i)
    {
        for(int j=0;j<w-1;++j)
        {
            if(cromartie[i-1][j-1]=='\\' and cromartie[i-1][j+1]=='/')
            {
               cromartie[i][j] = 'v';
            }
        }
    }






    for(int i=0;i<mx;++i)
    {
        for(int j=0;j<w-1;++j) cout << cromartie[i][j];
        cout << "\n";
    }
}
