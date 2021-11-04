#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,l;
    cin >> n >> l;
    string words[l];
    for(int i=0;i<l;++i)
        cin >>  words[i];
    for(int i=0;i<l;++i){
        int pts=0;
        for(int j=0;j<n;++j)
            if(words[i][j]!=words[i+1][j]) pts++;
        if(pts>2)
        {
            cout << words[i];
            return 0;
        }
    }
}
