#include<iostream>
#include<bits/stdc++.h>
#include<math.h>

using namespace std;

int n;
int numlist[5000];
int maxnum=0;

int horror(){
int x=0;
for(int i=maxnum;i>=1;i--){
        x=0;
    for(int j=0;j<n;j++){
        if(numlist[j]%i==0) {
            x++;
        }
        if(x==n){
            cout << "gcd = " << i;
            return 0;
        }
    }
}

}

int korror(int a,int b){
    for(int i=1;i<=a*b;i++){
        if(i%a==0 && i%b==0){
            return i;
        }
    }
}


int main(){

cin >> n;
for(int i=0;i<n;i++){
    cin >> numlist[i];
    if(numlist[i]>maxnum) maxnum=numlist[i];
}

int x=numlist[0];
for(int i=1;i<n;i++){
    x = korror(x,numlist[i]);
}
cout << "lcm = " << x << endl;
horror();



}
