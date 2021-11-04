#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,mm; cin >> n >> mm;
    queue<int> room[11];
    queue<int> line;
    map<int,int> m; // id :: room;
    for(int i=0;i<mm;++i)
    {
        int a,b;
        cin >> a >> b;
        m[b] = a;
    }

    while(1)
    {
        char cmd; cin >> cmd;
        if(cmd == 'X')
        {
            cout << 0;
            return 0;
        }
        if(cmd == 'E')
        {
            int a; cin >> a;
            if(room[m[a]].empty())
            {
                line.push(m[a]);
                room[m[a]].push(a);
            }
            else room[m[a]].push(a);
        }
        if(cmd == 'D')
        {
            int frontroom = line.front();
            cout << room[frontroom].front() << "\n";
            room[frontroom].pop();
            if(room[frontroom].empty()) line.pop();
        }
    }
}
