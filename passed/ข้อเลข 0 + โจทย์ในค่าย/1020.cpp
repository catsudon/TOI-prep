#include<bits/stdc++.h>
using namespace std;

string rev(string a)
{
    char r[a.length()];
    int x=0;
    for(int i=a.length()-1;i>=0;--i)
    {
        r[x] = a[i];
        x++;
    }
    string t = string(r);
    return r;
}


int main()
{
    string a;
    cin >> a;
    for(int i=0;i<a.length();++i)
    {
        if(a[i]>=65 && a[i]<=90) a[i] = tolower(a[i]);
    }
    string temp = rev(a);
    char r[a.length()];
    for(int i=0;i<a.length();++i) r[i]=temp[i];
    for(int i=0;i<a.length()/2;++i)
    {
        if(r[i]!=a[i])
        {
            cout << "No";
            return 0;
        }
    }
    char db[a.length()/2];
    int x=0;
    for(int i=a.length()/2 -1;i>=0;--i)
    {
        db[x]=a[i];
        x++;
    }
    for(int i=0;i<a.length()/2;++i)
    {
        if(db[i]!=a[i])
        {
            cout << "Palindrome";
            return 0;
        }
    }
    cout << "Double Palindrome";
}
