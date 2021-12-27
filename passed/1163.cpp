#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie();
    int n; cin >> n;
    for(int i=0;i<(1<<n);++i)
    {
        int bin[100];
        int temp = i;
        int p = n;

        while(temp)
        {
            bin[p--] = (temp%2);
            temp/=2;
        }
        while(p >= 1) bin[p--]=0;

        for(int i=n;i>=1;--i)
        {
            if(bin[i] == 1) continue;
            for(int j=1;j<=n;++j) cout << bin[j];
            cout << " ";
            bin[i] = 1;
            for(int j=1;j<=n;++j) cout << bin[j];
            cout << endl;
            bin[i] = 0;


        }
    }
}
