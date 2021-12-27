#include<bits/stdc++.h>
using namespace std;

int main()
{
    stack<bool> paren;
    stack<char> op;
    stack<char> alp;
    string s = "";
    string t; cin >> t;
    for(auto it : t)
    {
       // cout << s << endl;
        if(it == '(') paren.push(1);
        else if(it == ')')
        {
            if(alp.size() >= 2)
            {
                paren.pop();
                char a = alp.top(); alp.pop();
                char b = alp.top(); alp.pop();
                char o = op.top();  op.pop();
                s.push_back(b);
                s.push_back(a);
                s.push_back(o);
            }
            else if(alp.size()==1)
            {
                paren.pop();
                char a = alp.top(); alp.pop();
                char o = op.top();  op.pop();
                s.push_back(a);
                s.push_back(o);
            }
            else
            {
                char o = op.top();  op.pop();
                s.push_back(o);
            }

        }
        else if(it == '+' or it == '-')
        {
            op.push(it);
        }
        else alp.push(it);
    }
    while(!op.empty())
    {
        s.push_back(op.top()); op.pop();
    }
    cout << s;
}
