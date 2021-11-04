#include<iostream>

using namespace std;

int main(){

int max,min;
int a;
cin >> a;
max =a;
min =a;

for(int i=0;i<9;i++){
    cin >>a;
    if(a>max) max=a;
    if(a<min) min=a;
}

cout << min << endl << max ;



}
