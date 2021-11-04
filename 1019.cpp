#include<bits/stdc++.h>
using namespace std;

int main()
{
    string a,b; cin >> a >> b;
    string ans = "";
    string temp = "";
    if(a.length() > b.length()) swap(a,b);
    for(int i=0;i<a.length();++i)
    {
        for(int j=0;j<b.length();++j)
        {
           // if(j+i > a.length()) continue;
            int k=0;
            if(a[i]==b[j])
            while(true)
            {
                if(i+k < a.length() and j+k < b.length() and a[i+k]==b[j+k]){temp.push_back(a[i+k]);
                                     if(temp.length() > ans.length()) ans = temp;}
                else {temp = "";break;}
                k++;
            }
        }
        temp = "";
    }

    cout << ans;
}
