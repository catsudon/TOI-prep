#include<iostream>

using namespace std;

int check(char yn){

if(yn == 'Y' || yn == 'y' || yn =='N' || yn =='n'){
    cout << "yes";
    return 0;
}
cout << "no";

}


main(){

char yn;
cin >> yn;
check(yn);
}
