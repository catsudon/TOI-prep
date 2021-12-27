#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;

map<int,int> m;

int main(){

int c,n;
cin >> c >> n;
for(int i=0;i<n;++i){
    int a,b;
    cin >> a >> b;
    m.insert({b,a});

}
char cmd;
vector <pair<int,int> > v;
while(true){
    cin >> cmd;
    if(cmd=='X'){
        cout << "0";
        return 0;
    }
    if(cmd=='E'){
        int c;
        cin >> c;
        int t=0;
        for(int i=v.size()-1;i>=0;--i){
            if(v[i].f == m[c]) {
                v.insert(v.begin()+i+1,{m[c],c});
                t=1;
                break;
            }
        }
        if(t==0) v.push_back({m[c],c});
    }
    if(cmd=='D'){
        cout << v.front().s << endl;
        v.erase(v.begin());
    }
}

}
