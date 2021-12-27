#include<iostream>

using namespace std;

int main(){

int n;
cin >> n;
int x=1;
for(int i=0;n>1;i++){
    for(int j=0;j<=i;j++,n--){
        cout << char(64+x);
        x++;
        x%=27;
        if(x==0) x++;
        if(n==1) break;

    }
    cout << endl;
}

}
