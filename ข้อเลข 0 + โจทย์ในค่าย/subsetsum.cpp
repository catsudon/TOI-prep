#include<bits/stdc++.h>
using namespace std;
int s[1009];
int n,sum;
bool found = false;
int start(int num,vector<bool> used,int ss)
{
    ss+=s[num];
    used[num] = true;
//    for(int i=0;i<n;++i) if(used[i]) cout << s[i] << " ";
  //  cout << ss << endl;
    if(ss>sum) return 0;
    if(ss==sum)
    {
        cout << "yes";
        found = true;
        return 0;
    }
    for(int i=0;i<n;++i)
    {
        if(!used[i]) start(i,used,ss);
    }
}

int main()
{
    cin >> n;
    for(int i=0;i<n;++i)
    {
        cin >> s[i];
    }
    cin >> sum;

    for(int i=0;i<n;++i)
    {
        vector<bool> u(n,false);
        start(i,u,0);
        if(found) return 0;
    }
    cout << "no";
}
