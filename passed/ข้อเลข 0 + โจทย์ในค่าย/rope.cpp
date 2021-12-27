#include<bits/stdc++.h>

using namespace std;

int main(){

int n;
cin >> n;

int a[n];
int b[n];
for(int i=0;i<n;++i){
    cin >> a[i];
}
for(int i=0;i<n;++i){
    cin >> b[i];
}
sort(a,a+n);
sort(b,b+n);

int ans = 0;
for(int i=0;i<n;++i){
    ans+= abs(a[i]-b[i]);
}

cout << ans;



}
