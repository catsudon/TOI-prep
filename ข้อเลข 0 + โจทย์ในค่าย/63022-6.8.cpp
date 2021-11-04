#include<iostream>

using namespace std;

int main(){

string a;
cin >> a;
int b[16];
int bcount=0,acount=0;
for(int i=18;i>=0;i--){
    if(a[i]!='-'){
        b[bcount] = a[i]-48;
        bcount++;
    }
}
//for(int x=0;x<bcount;x++) cout << b[x] << " ";
//cout <<endl;
for(int i=1;i<16;i+=2){
    b[i]*=2;
    if(b[i]>=10){
        int x = b[i]/10;
        b[i] = (b[i]%10) + x;
    }
}

int sum=0;
//for(int i=0;i<16;i++) {sum+=b[i];cout << b[i] << " ";}

if(sum%10==0) cout << "real creditcard";
else cout << "fake creditcard";


}
