#include<iostream>

using namespace std;

int main(){

long long int dec;
cin >>dec;
int bin[300];
int i=0;
while(dec>0){
    bin[i]=dec%2;
    dec/=2;
    i++;
}

for(int j=i-1;j>=0;j--){
    cout << bin[j];
}

}
