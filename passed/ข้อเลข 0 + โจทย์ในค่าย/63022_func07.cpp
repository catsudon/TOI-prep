#include<iostream>

using namespace std;

int change(int n,int x){

int bruh[10000];
int bruhcount = 0;
while(n>0){
    bruh[bruhcount] = n%x;
    n/=x;
    bruhcount++;
}
for(int i=bruhcount-1;i>=0;i--) {
    if (bruh[i]>=10){
        if(bruh[i]==10) cout << "A";
        if(bruh[i]==11) cout << "B";
        if(bruh[i]==12) cout << "C";
        if(bruh[i]==13) cout << "D";
        if(bruh[i]==14) cout << "E";
        if(bruh[i]==15) cout << "F";
    }
    else cout << bruh[i];

}
cout << endl;


}

int main(){

int n;
cin >> n;
change(n,2);
change(n,8);
change(n,16);

}
