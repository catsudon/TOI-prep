#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v  ={10, 12, 15, 19, 20, 1, -3, -7, 8, 14, 12, 30, 58, -100, 44};
    sort(v.begin(),v.end());
    for(auto it : v) cout << it << " ";
    cout << endl;
    for(int it=v.size()-1;it>=0;--it) cout << v[it] << " ";
    cout << endl;
    cout << *(max_element(v.begin(),v.end())) << " " << *(min_element(v.begin(),v.end())) << endl;
    cout << binary_search(v.begin(),v.end(),7) << " " << binary_search(v.begin(),v.end(),-7) << endl;
    for(int it = (lower_bound(v.begin(),v.end(),0)-v.begin());it!=v.size();++it) cout << v[it] << " ";
    cout << endl;
    for(int it = 0;it<(upper_bound(v.begin(),v.end(),40)-v.begin());++it) cout << v[it] << " ";
}
