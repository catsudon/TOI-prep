#include<bits/stdc++.h>
using namespace std;
int ii=0,v=0,x=0,l=0,c=0;
int main()
{
    int n; cin >> n;
    for(int i=1;i<=n;++i)
    {
       int n=i;
       while (n!=0)
       if (n>=100){n-=100;c++;}
       else if (n>=90){n-=90;x++;c++;}
       else if (n>=50){n-=50;l++;}
       else if (n>=40){n-=40;x++;l++;}
       else if (n>=10){n-=10;x++;}
       else if (n>=9){n-=9;ii++;x++;}
       else if (n>=5){n-=5;v++;}
       else if (n>=4){n-=4;v++;ii++;}
       else if (n>=1){n-=1;ii++;}
    }
    cout << ii << " " << v << " " << x << " " << l << " " <<c;
}
