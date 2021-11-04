#include<bits/stdc++.h>
using namespace std;
map<int,int> m;
queue<int> q[11];
bool entered[11];

int main()
{
    int n,mm;
    cin >> n >> mm;
    for(int i=0;i<mm;++i)
    {
        int c,id;
        cin >> c >> id;
        m[id] = c;
    }
    int student=0;
    queue<int> classq;
    while(true)
    {
        char cmd;
        cin >> cmd;
        if(cmd=='E')
        {
            student++;
            int sid; cin >> sid;
            q[m[sid]].push(sid);
            if(!entered[m[sid]]) {classq.push(m[sid]);entered[m[sid]]=true;}
        }
        if(cmd=='D')
        {
            if(classq.empty()) {cout << "empty\n"; continue;}
            int room = classq.front();
            int sid = q[room].front();
            cout << sid << "\n";
            q[room].pop();
            if(q[room].empty()) {classq.pop();entered[room]=false;}

        }
        if(cmd=='X') {cout << 0;return 0;}
    }
}
