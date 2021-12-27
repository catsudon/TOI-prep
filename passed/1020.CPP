#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s; cin >> s;
    for(int i=0;i<s.length();++i) if(s[i] >= 'A' and s[i] <='Z') s[i]+=32;
    string rev = s;
    reverse(rev.begin(),rev.end());

    string half1 = "",half2 = "";
    for(int i=0;i<s.length()/2;++i) half1.push_back(s[i]);
    if(s.length()%2==0)
    for(int i=s.length()/2;i<s.length();++i) half2.push_back(s[i]);
    else for(int i=s.length()/2 +1;i<s.length();++i) half2.push_back(s[i]);

    string rev1 = half1;
    string rev2 = half2;

    reverse(rev1.begin(),rev1.end());
    reverse(rev2.begin(),rev2.end());

    if(rev == s and rev1 == half1 and rev2 == half2) cout << "Double Palindrome";
    else if(rev == s) cout << "Palindrome";
    else cout << "No";

}
