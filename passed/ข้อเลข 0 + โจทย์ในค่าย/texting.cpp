#include<bits/stdc++.h>
using namespace std;

char phone[10][4] = {{'n'},{'n'},{'A','B','C'},{'D','E','F'},{'G','H','I'},{'J','K','L'},{'M','N','O'},{'P','Q','R','S'},{'T','U','V'},{'W','X','Y','Z'}};
char text[1000];
int c = 0,s;

int main(){


int n;
cin >> n;
int t;
int r;
cin >> t >> r;
if(t==7 || t==9){
    s=4;
    text[c] = phone[t][(r-1)%s];
    c++;
}
else if(t>=2){
    s=3;
    text[c] = phone[t][(r-1)%s];
    c++;
}
else if(t==1){
    for(int i=0;i<r;++i){
        if(c>0){
            text[c]='0';
            c--;
        }
    }
}


for(int i=1;i<n;++i){
    int h,v;
    cin >> h >> v >> r;
    t+=v*3;
    t+=h;
    if(t==7 || t==9){
    s=4;
    text[c] = phone[t][(r-1)%s];
    c++;
    }
    else if(t>=2){
        s=3;
        text[c] = phone[t][(r-1)%s];
        c++;
    }
    else if(t==1){
        for(int i=0;i<r;++i){
            if(c>0){
                text[c]='0';
                c--;
            }
        }
    }
}

for(int i=0;i<c;++i) cout << text[i];
if(c==0) cout << "null";

}
