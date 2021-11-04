#include<iostream>

using namespace std;

int main(){

int n,m;
cin >> n >> m;
int obj[m];
int continuehere[m];
string table[n];

for(int i=0;i<n;i++){
    cin >> table[i];
}

for(int i=0;i<m;i++){
    cin >> obj[i];
    continuehere[i] = n-1;
    for(int k=0;k<n;k++){
        if(table[k][i]=='O') {
                continuehere[i] = k-1;
                break;
        }
    }
    for(int j=obj[i];j>0;j--){
        if(continuehere[i]>-1){
            table[continuehere[i]][i] = '#';
            continuehere[i]--;
        }
    }
}
for(int i=0;i<n;i++){
    cout << table[i] << endl;
}
}
