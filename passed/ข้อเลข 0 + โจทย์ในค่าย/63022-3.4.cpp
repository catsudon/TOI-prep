#include<iostream>

using namespace std;

int main(){

int n;
cin >> n;

int allnum[n+1];

for(int i=1;i<n+1;i++){
    allnum[i] = i;
}
int primelist[n];
int primecount =0;
for(int i=2;i<n+1;i++){
    if(allnum[i]!=0){
        primelist[primecount] = allnum[i];
        primecount++;
        for(int j=2;i*j<n+1;j++){
            allnum[i*j] = 0;
        }
    }
}
cout << primecount << endl;
for(int i=0;i<primecount;i++){
    cout << primelist[i] << " ";
}

}
