#include<bits/stdc++.h>
using namespace std;
using ll = long long;

stack<int> gift;
stack<char> op;
ll sum = 0;

int henshin[300];

int sol()
{
    int a = gift.top(); gift.pop();
    int b = gift.top(); gift.pop();
    int coef = henshin[op.top()]; op.pop();
    int sum = (a+b)*(100+coef)/100;
    gift.push(sum);
}

int main()
{
    henshin['1'] = 4; henshin['2'] = 8; henshin['3'] = 16;
    string s ; cin >> s;
    s = '['+s+']';



    for(auto it : s)
    {
        if(it == '[')
        {
            op.push('[');
        }
        else if(it >= '1' and it <= '3')
        {
            while(op.size() and op.top()!='[' and op.top() >= it) sol(); // need to be >= because the progress is fixed to be done left to to right
            op.push(it);
        }
        else if(it == ']')
        {
            while(op.size() and op.top()!='[') sol();
            op.pop();
        }
        else gift.push(20);
    }
    cout << gift.top();

for(int i=1;i<=1700;++i) for(int j=1;j<=9000;++j) {cout<<'\n';}
//    cerr << endl << endl << " gift left " << gift.size() << "    operator left " << op.size();
}
