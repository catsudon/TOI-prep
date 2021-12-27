#include<iostream>
using namespace std;

int main()
{
    string s;
    getline(cin,s);
    int sze; cin >> sze;
    for(int i=0;i<s.length();++i) if(s[i]==' ') s[i] = '7';
    char table[sze][sze];
    for(int i=0;i<sze;++i) for(int j=0;j<sze;++j) table[i][j] = 0;
    int llenn = s.length(),p=0;
    int x=0,y=0;
    while(p<llenn)
    {
        table[x][y++] = s[p++];
        if(y==sze) y=0,x++;
    }
    for(int i=0;i<sze;++i)
    {
        for(int j=0;j<sze;++j)
        {
            if(table[j][i]==0) continue;
            cout << table[j][i];
        }
    }

}
