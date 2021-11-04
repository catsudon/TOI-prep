#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n[30];
    int i=1;
    int mx;
    while(i++){
        cin >> n[i];
        if(n[i]==-1)
        {
            mx = i;
            break;
        }
    }
    for(int i=2;i<mx;++i)
    {
        int a=1,b=1,c=0;
        for(int j=0;j<n[i];++j)
        {
            int tb=b,tc=c;
            c=0;
            c+=tb;
            b+=tc+1;
        }
        cout << b << " " << a+b+c << endl;
    }

}
