#include<iostream>


using namespace std;

int main(){

    int n;
    cin >> n;
    int mountain[n];
    for(int i=0;i<n;i++){
        cin >> mountain[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<mountain[i];j++){
            for(int k=0;k<j;k++){
            cout << ' ';
            }
            cout << '\\' << endl ;
        }
        for(int x=0;x<mountain[i];x++){
            for(int l=mountain[i]-x;l>1;l--){
            cout << ' ';
            }
            cout << '/' << endl;
        }

    }

}
