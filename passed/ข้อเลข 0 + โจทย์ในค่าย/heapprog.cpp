#include<iostream>
#include<queue>

using namespace std;

int main(){

int n,item;
priority_queue<int> items;
cin >> n;
char cmd;
for(int i=0;i<n;i++){

cin >> cmd;
if(cmd == 'P'){
    cin >> item;
    items.push(item);
}
else if(cmd == 'Q'){
    if(items.empty()) cout << -1 << endl;
    else{
    cout << items.top() << endl;
    items.pop();
    }

}

}





}
