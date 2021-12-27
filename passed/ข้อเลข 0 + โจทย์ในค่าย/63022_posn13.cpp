#include<iostream>

using namespace std;

int main(){

int n;
cout << "Input index : ";
cin >> n;
int num[n];
int max=0;
for(int i=0;i<n;i++){
    cout << "Input number [" << i << "]: ";
    cin >> num[i];
    if(num[i]>max) max=num[i];
}
cout << "  ";
for(int i=0;i<n;i++) cout << " __";
cout << endl;
for(int i=max+1;i>=0;i--){
    i>=10 ? cout << i << "|": cout << " " << i << "|";
    for(int j=0;j<n;j++){
        num[j]>=i? cout << "*":cout << " ";
        cout << " |";
    }
    cout << endl;
}
cout << "   ";
for(int i=0;i<n;i++) cout << "__ ";
cout << endl;
cout << "   ";
for(int i=0;i<n;i++) cout << i << "  ";


}
