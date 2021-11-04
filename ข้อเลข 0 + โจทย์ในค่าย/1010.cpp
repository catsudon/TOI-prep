#include <cctype>
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int main(){


int n,m;
cin >> n >>m;

string table[n];
int i,j,k,l;
for(i=0;i<n;i++){
    cin >> table[i];
}

int wordcount;
cin >> wordcount;
string word[wordcount];

for(i=0;i<wordcount;i++){
    cin >> word[i];
}

for(i=0;i<wordcount;i++){
    int wannabreak=0;
if(wannabreak==0){
    for(j=0;j<n;j++){
    if(wannabreak==0){
        for(k=0;k<m;k++){
           // cout << toupper(word[i][0])<< endl;
            if(toupper(table[j][k])==toupper(word[i][0])){
                //check 8 direction
                // E
                int len = word[i].length();
                cout << len << endl;
                if(1>0){
                    for(l=1;l<len;l++){
                        cout << l;
                        if (toupper(table[j][k+l])==toupper(word[i][l])){
                            if(l==len-1){
                        //    cout << j <<" "<< k <<" E "<< endl;
                            wannabreak=1;
                            break;
                            }
                        }
                        else{
                            l=999;
                        }
                    }
                }
                // ES
                if(1>0){
                    for(l=1;l<len;l++){
                        if (toupper(table[j+l][k+l])==toupper(word[i][l])){
                                cout <<"es "<< l <<endl;
                            if(l==len-1){
                            cout << j <<" "<< k << endl;
                            wannabreak=1;
                            break;
                            }
                        }
                        else{
                            l=999;
                        }
                    }
                }

                // S
                if(1>0){
                    for(l=1;l<len;l++){
                        if (toupper(table[j+l][k])==toupper(word[i][l])){
                            cout << " s " << word[i][l] << endl;
                            if(l==len-1){
                            cout << j <<" "<< k << endl;
                            wannabreak=1;
                            break;
                            }
                        }
                        else{
                            l=999;
                        }
                    }
                }
                // WS
                if(1>0){
                    for(l=1;l<len;l++){
                        if (toupper(table[j+l][k-l])==toupper(word[i][l])){
                            if(l==len-1){
                            cout << j <<" "<< k << endl;
                            wannabreak=1;
                            break;
                            }
                        }
                        else{
                            l=999;
                        }
                    }
                }
                // W
                if(1>0){
                    for(l=1;l<len;l++){
                        if (toupper(table[j][k-l])==toupper(word[i][l])){
                            if(l==len-1){
                            cout << j <<" "<< k << endl;
                            wannabreak=1;
                            break;
                            }
                        }
                        else{
                            l=999;
                        }
                    }
                }
                // WN
                if(1>0){
                    for(l=1;l<len;l++){
                        if (toupper(table[j-l][k-l])==toupper(word[i][l])){
                            if(l==len-1){
                            cout << j <<" "<< k << endl;
                            wannabreak=1;
                            break;
                            }
                        }
                        else{
                            l=999;
                        }
                    }
                }
                // N
                if(1>0){
                    for(l=1;l<len;l++){
                        if (toupper(table[j-l][k])==toupper(word[i][l])){
                            if(l==len-1){
                            cout << j <<" "<< k << endl;
                            wannabreak=1;
                            break;
                            }
                        }
                        else{
                            l=999;
                        }
                    }
                }
                // NE
                if(1>0){
                    for(l=1;l<len;l++){
                        if (toupper(table[j-l][k+l])==toupper(word[i][l])){
                            if(l==len-1){
                            cout << j <<" "<< k << endl;
                            wannabreak=1;
                            break;
                            }
                        }
                        else{
                            l=999;
                        }
                    }
                }
            }
        }
    }
else{
    break;
}
    }


}
else {
    break;
}
}




}
