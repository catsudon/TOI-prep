#include<stdio.h>
#include<iostream>

using namespace std;

int main(){

    int n,i,j,k,l;
    cin >> n;
    int mountain[n];
    int max=0;
    for(i=0;i<n;i++){
        cin >> mountain[i];
        if(mountain[i]>max) max=mountain[i];
    }
    for(i=0;i<max;i++){
        for(j=0;j<n;j++){
            for(k=0;k<mountain[j];k++){
                i+k+1==max? cout << "/" : cout << " ";
            }
            for(l=mountain[j];l>0;l--){
                i+l==max? cout << "\\" : cout << " ";
            }
        }
    printf("\n");
    }



}
