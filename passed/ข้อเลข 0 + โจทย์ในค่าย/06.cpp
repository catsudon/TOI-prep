#include<iostream>

using namespace std;

int main(){

int n,x;
cin >> n >> x;
int l = 0;
char ans[x];
int anscount=0;
for(int i=n;i>0;--i){
    for(int j=1;j<i;++j) cout << " ";
    for(int k=n-i;k>=0;--k){
        cout << char(65+(k+l)%26);
        // << i << " " << k << " ";
        if(k==x){
            ans[anscount] = char(65+(k+l)%26);
            anscount++;
        }
    }
    l+=n-i+1;
cout << endl;
}

for(int i=0;i<anscount;++i) cout << ans[i];


}
