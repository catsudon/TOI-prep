#include<iostream>

using namespace std;

int main(){

cout << "Enter a number : ";
int n;
cin >> n;

int count = 1;
for(int i=1;i<=n;i++){
    for(int j=1;j<=i;j++){
        cout << char(64+count);
        count++;
        count = count%27;
        if(count==0) count++;
    }
    cout << endl;
}


}
