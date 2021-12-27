#include<iostream>

using namespace std;

int main(){

int a;
while(1){
cout << "Enter a number : ";
cin >> a;
if(a==1) cout << "Hello" << endl;
else if(a==2) cout << "Thank you" << endl;
else if(a==3){
    cout << "Good bye";
    return 0;
}
else cout << "Sorry" << endl;

}



}
