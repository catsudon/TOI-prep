#include<bits/stdc++.h>
using namespace std;
int n;
int start(string s1,int point)
{
    if(point==n)
    {
        cout << s1 << "E" << "\n";
        return 0;
    }
    else if(point>n) return 0;
    string s2 = s1;
    s1.push_back('-');s1.push_back('-');s1.push_back('\n');
    s2.push_back('|');s2.push_back('|');s2.push_back('\n');
    start(s1,point+1);
    if(point+2<=n)start(s2,point+2);
}

int main()
{
    cin >> n;

        string s1 = "--\n";
        string s2 = "||\n";
        start(s1,1);
        start(s2,2);

}
