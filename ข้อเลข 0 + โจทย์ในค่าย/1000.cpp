#include<iostream>


using namespace std;

int main(){

int len;
cin >> len;
int n;
cin >> n;
string words[n+1];

cin >> words[0];

for(int i=1;i<n+1;i++){
    if(i<n) cin >> words[i];
    int mistake =0;
    for(int j=0;j<len;j++){
        if(words[i][j]!=words[i-1][j]) mistake++;
    }
    if(mistake>=3) {
        cout << words[i-1];
        break;
    }

}

}
