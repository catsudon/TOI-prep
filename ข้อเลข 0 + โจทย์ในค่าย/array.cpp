#include<iostream>

using namespace std;

int main(){

int id[5],temp;

for(int i=0;i<5;i++) cin >> id[i];
for(int i=0;i<5;i++){
    for(int j=i+1;j<5;j++){
        if(id[j]>id[i]){
            temp = id[i];
            id[i] = id[j];
            id[j] = temp;
        }
    }
}
for(int i=0;i<5;i++) cout << id[i];

}
