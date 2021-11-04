#include<bits/stdc++.h>
using namespace std;
int main()
{
    stack<int> st;
    string a; cin >> a;
    int c=0;
    for(int i=0;i<a.length();++i)
    {
        if(a[i]=='(') st.push(i);
        else if(a[i]==')' && !st.empty()) st.pop();
        else if(a[i]==')' && st.empty())  c++;
    }
    cout << c+st.size();
}
