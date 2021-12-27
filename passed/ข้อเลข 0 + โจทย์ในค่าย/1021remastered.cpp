#include<iostream>
#include<vector>
#include<bits/stl_heap.h>

using namespace std;

int a[0];

int main(){

int n;
cin >> n;

vector<int> item(a,a+sizeof(a)/sizeof(a[0]));

make_heap(item.begin(),item.end());

string cmd;
int a;
for(int i=0;i<n;i++){
    cin >> cmd;
    if(cmd[0]=='P'){
        cin >> a;
        item.push_back(a);
        push_heap(item.begin(),item.end());
    }
    if(cmd[0]=='Q'){
        if(item.size()==0){
            cout << -1 << endl;
        }
        else{
            cout << item.front() << endl;
            pop_heap(item.begin(),item.end());
            item.pop_back();

        }

    }
}






}
