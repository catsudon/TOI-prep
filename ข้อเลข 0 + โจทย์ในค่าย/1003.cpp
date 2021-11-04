#include<iostream>

using namespace std;

int main(){

int n;
cin >> n;
int isnugget = 0;
if(n>=6) isnugget=1;
else {
    cout << "no";
}

if(isnugget==1){
    for(int i=6;i<n+1;i++){
        if(i>=6 && i%3==0) cout << i << endl;
        else if(i%20==0) cout << i << endl;
        else if((i-20)>=6 && (i-20)%3==0) cout << i << endl;
        else if((i-40)>=6 && (i-40)%3==0) cout << i << endl;
        else if((i-60)>=6 && (i-60)%3==0) cout << i << endl;
        else if((i-80)>=6 && (i-80)%3==0) cout << i << endl;
    }
}

}
