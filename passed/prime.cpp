#include<bits/stdc++.h>
using namespace std;
bool skip[8000000];
int main()
{
    int n; cin >> n;
    int c=0;

    for(int i=2;i<=8000000;++i)
    {
        if(!skip[i])
        {
            c++;
            if(c==n)
            {
                cout << i;
                return  0;
            }
            for(int j=i;j<=8000000;j+=i)
            {
                skip[j] = true;
            }
        }
    }

}
