#include<bits/stdc++.h>
using namespace std;

int main()
{
    string a; cin >> a;
    bool up = 0;
    if(a[0] >= 'A' and a[0] <= 'Z') up=1;
    int p=0;
    for(auto it : a)
    {
        if(p==0) {p++;continue;}
        if(it >= 'A' and it <= 'Z' and up) continue;
        if(it >= 'a' and it <= 'z' and up)
        {
            cout << "Mix"; return 0;
        }
        if(it >= 'a' and it <= 'z' and !up) continue;
    }
    if(up) cout << "All Capital Letter";
    else cout << "All Small Letter";
}
