#include<bits/stdc++.h>
using namespace std;
stack<int> s;
stack<char> op;
int cost[309];
int sol()
{
    int a = s.top();
    s.pop();
    int b = s.top();
    s.pop();
    int sum = a+b;
    sum *= (100+cost[op.top()]);
    sum /= 100;
    op.pop();
    s.push(sum);
    return sum;
}

int main()
{
    string a; cin >> a;
    a='['+a+']';
    cost['1'] = 4;
    cost['2'] = 8;
    cost['3'] = 16;

    for(auto it : a)
    {
        if(it >= '1' and it <= '3')
        {
            while(op.size() and op.top()!='[' and  op.top() >= it ) sol();
            op.push(it);
        }
        else if(it == '[')
        {
            op.push('[');
        }
        else if(it == ']')
        {
            while(op.size() and op.top()!='[') sol();
            op.pop();
        }
        else
        {
            s.push(20);
        }
        cerr << s.size() << ' ' << op.size() << endl;
    }

    cout << s.top();
}
