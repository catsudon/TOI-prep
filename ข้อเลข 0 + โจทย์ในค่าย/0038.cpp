#include<iostream>
#include<algorithm>

using namespace std;

int main(){

    int n;
    cin >> n;
    string array[n];
    for(int i=0;i<n;i++){
        cin >> array[i];
    }
    sort(array,array+n);
    for(int i=0;i<n;i++){
        if(array[i]==array[i-1] && i!=0) ;
        else cout << array[i] << endl;
    }

}
