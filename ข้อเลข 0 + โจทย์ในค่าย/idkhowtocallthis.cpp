#include<iostream>

using namespace std;

int main(){

int n,x;
cin >> n >> x;
char ans[x];
int cf=0;
int coun=0;
for(int i=1;i<=n;i++){
    for(int j=n-i;j>0;j--) cout << " ";
    for(int j=i;j>0;j--){
        int l = (cf+j)%27;
        if(l==0)l++;
        cout << char(64+l);
        if(j==x){
            ans[coun] = char(64+l);
            coun++;
        }
    }
    cf+=i;
    cout << endl;
}

for(int i=0;i<coun;i++) cout << ans[i];
}
