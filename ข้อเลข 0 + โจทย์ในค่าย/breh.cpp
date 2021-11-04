#include<bits/stdc++.h>

using namespace std;

int main(){

string a,b;
cin >> a >> b;
int ans[9999];
int anscount=0;
int tod=0;
int l = a.length();
int k = b.length();
int x = max(l,k);
for(int i=1;i<=x;i++){
    if(l-i>=0 && k-i>=0){
        ans[anscount] = ((int)a[l-i] +(int)b[k-i]-96 + tod);
        tod=0;
        if(ans[anscount]>=10)
        tod+= 1;
        ans[anscount]%=10;
        anscount++;
       // cout << (int)a[l-i]-48 <<endl;
    }
    else if(k-i>=0){
        ans[anscount] = ((int)b[k-i]-48+tod);
      //  cout << "here : " << ans[anscount] << endl;
        tod=0;
        if(ans[anscount]>=10)
        tod+=1;
        ans[anscount]%=10;
        anscount++;
    }
    else if(l-i>=0){
        ans[anscount] = ((int)a[l-i]-48+tod);
        tod=0;
        if(ans[anscount]>=10)
        tod+=1;
        ans[anscount]%=10;
        anscount++;
    }
   // cout << l-i << "  " << k-i << endl;
}

for(int i=anscount-1;i>=0;--i) cout << ans[i];

}
