#include<bits/stdc++.h>

using namespace std;

int ar[0];

int main(){

vector<int> item(ar,ar);
make_heap(item.begin(),item.end());

for(int i=0;i<15;i++){
    item.push_back(rand()/1000);
    push_heap(item.begin(),item.end());
}
//pop_heap(item.begin(),item.end());

for(int i=0;i<15;i++){
    cout << " " << item[i];
}
pop_heap(item.begin(),item.end());
item.pop_back();
cout << endl;
for(int i=0;i<item.size();i++){
    cout << " " << item[i];
}




}
