#include<bits/stdc++.h>
using namespace std;
int ka,tsu,don;
vector<char> tabetai;

int dfs(int jordi,int polla)
{
    if(jordi == ka or polla == ka)
    {
        for(auto it : tabetai) cout << it << " ";
        cout << endl;
        return 0;
    }
    tabetai.push_back('W');
    dfs(jordi+1,polla);
    tabetai.pop_back();
    tabetai.push_back('L');
    dfs(jordi,polla+1);
    tabetai.pop_back();
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> ka >> tsu >> don;

    tabetai.push_back('W');
    dfs(tsu+1,don);
    tabetai.pop_back();
    tabetai.push_back('L');
    dfs(tsu,don+1);
}
