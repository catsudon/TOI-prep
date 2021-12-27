#include<iostream>
using namespace std;

main(){

int ar[10];
int* pt ;
*pt = 0;
int* arpt = ar;
for(int i=0;i<10;i++) {
    cin >> *(arpt+i);
    *pt += *(arpt+i);
}

cout << *pt;


}
