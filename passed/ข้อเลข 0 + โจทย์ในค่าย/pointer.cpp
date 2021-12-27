#include<iostream>

using namespace std;

int blank;
int* a=&blank;
int** sum = &a;

int main(){


for(int i=0;i<10;i++){
    cin >> blank;
    **sum = **sum+*a;
}

cout << **sum;



}
