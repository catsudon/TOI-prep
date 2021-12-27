#include<iostream>

using namespace std;

int main(){

int n;
cin >> n;
int x=0;
for(int i=1;i<=n;i++){
    if(i%2==0){
        for(int j=n;j>0;j--) cout << "  ";
        for(int k=1;k<=i;k++){
            int cf = x+k;
            cf%=26;
            if(cf==0) cf=26;
            cout << char(64+cf) << " ";
        }
        x+=i;
    }
    else if(i%2==1){
        for(int j=n-i;j>=0;j--) cout << "  ";
        for(int k=i;k>0;k--){
            int cf = x+k;
            cf%=26;
            if(cf==0) cf=26;
            cout << char(64+cf) << " ";
        }
        x+=i;
    }
    cout << endl;
}





}
