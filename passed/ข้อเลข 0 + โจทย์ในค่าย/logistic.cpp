#include<bits/stdc++.h>

using namespace std;

vector<pair<char,int> > v[26];
vector<pair<char,int> > X;
vector<pair<char,int> > Y;

int main(){

int n;
cin >> n;
char haved[26];
int c=0;
for(int i=0;i<n;++i){
    char a,b;
    int c;
    cin >> a >> b >> c;
    int x=1;
    if(a!='X' && a!='Y'){
        for(int i=0;i<c;++i){
            if(haved[i]==a) x=0;
        }
        if(x) {
            haved[c] = a;
            c++;
        }
    }

    int x=1;
    if(b!='X' && b!='Y'){
        for(int i=0;i<c;++i){
            if(haved[i]==b) x=0;
        }
        if(x) {
            haved[c] = b;
            c++;
        }
    }
    if(a=='X'){
        X.push_back({b,c});
    }
    if(a=='Y'){
        Y.push_back({a,c});
    }
    v[a-96].push_back({b,c});
    v[b-96].push_back({a,c});
}


}
