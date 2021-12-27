#include<iostream>
#include<queue>

using namespace std;


priority_queue<int> item;


int main(){

int n;
cin >> n;
char command;
int price;
for(int i=0;i<n;i++){
    cin >> command;
    if(command=='P'){
        cin>> price;
        item.push(price);
    }
    else{
        if(item.size()==0){
            cout << -1 << endl;
        }
        else{
            cout << item.top() << endl;
            item.pop();
        }
    }
}



}
