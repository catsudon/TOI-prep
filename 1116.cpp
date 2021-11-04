#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    int mae; cin >> mae;
    n--;
    int mx = -1,ans=0;
    while(n--)
    {
        int a; cin >> a;
        const clock_t begin_time = clock();
        mx = max(mx,mae); //cerr << a << " " << mae << " " << mx << endl;
        ans = max(ans,abs(mx-a));
        mae=a;
      cout <<endl;  cout << float( clock () - begin_time ) /  CLOCKS_PER_SEC; cout<<endl;
    }
  //  cout << fixed << setprecision(6);
    //cout << double(ans) / (double)2.0;
}
