#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
    int a[10] = {200,350,100,400,500,600,220,900,830,300};
    int n = sizeof(a)/sizeof(a[0]);
    vector<int> b(a,a+n);
    //for(int i=0;i<10;i++) b.push_back(a[i]);
    sort(b.begin(),b.end());
    b.insert(b.begin()+2,999,0);
    for(auto i=b.rbegin();i<b.rend();++i) cout << *b[i] << " ";



}



