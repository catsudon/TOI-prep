#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    int num[n];
    for(int i=0;i<n;++i) cin >> num[i];
    for(int i=1;i<n;i++){
      int temp=num[i];
      int j=i-1;
      while((temp<num[j])&&(j>=0)){
         num[j+1]=num[j];
         j=j-1;
      }
      num[j+1]=temp;
   }

   for(int i=0;i<n;++i) cout << num[i] << " ";
}
