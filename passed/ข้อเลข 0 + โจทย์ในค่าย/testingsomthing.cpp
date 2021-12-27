#include<bits/stdc++.h>

using namespace std;
int main(){

vector<int> a = {1,2,3};
a.push_back(4);
a.push_back(5);
vector<int> ::iterator it;

for(it = a.begin()+1;it!=a.end()-1;++it) cout << *it << " ";



}
