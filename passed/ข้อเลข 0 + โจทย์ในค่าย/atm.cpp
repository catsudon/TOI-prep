#include<iostream>

using namespace std;
const int truepassword = 136;

int main(){

int password;
for(int i=0;i<3;i++){
    cin >> password;
    if(password==truepassword){
        cout << 1 << endl;
        break;
    }
    else{
        cout << 0 << endl;
        if(i==2) return 0;
    }
}

int money;
cin >> money;
int bankleft[3] = {5,8,50};
int a,b,c;
int moreb,morec;
if(bankleft[0]>=money/1000){
    cout << money/1000 << endl;
    money = money%1000;
}
else{
    cout << bankleft[0] << endl;
    money-=1000*bankleft[0];
}

if(bankleft[1]>=money/500){
    cout << money/500 << endl;
    money = money%500;
}
else{
    cout << bankleft[1] << endl;
    money-=500*bankleft[1];
}

cout << money/100;


}
