#include<iostream>

using namespace std;

int n,x=1;
int temp1=0,temp2=1;

void fibo(int n){

for(int i=0;i<n;i++){
    cout << x << " ";
    x=temp2+temp1;
    temp1=temp2;
    temp2=x;
}

}


int main(){
    cin >> n;
    fibo(n);
}
