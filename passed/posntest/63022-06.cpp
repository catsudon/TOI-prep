#include<iostream>
using namespace std;
char a[20][200];
int main()
{
    int h,n,c;
    cout << "h : "; cin >> h;
    cout << "n : "; cin >> n;
    cout << "c : "; cin >> c;
//[i][j]
    for(int i=1;i<=n;++i)
    {
        int c=0;
        for(int j=h;j>=1;--j)
        {
            int coef = i+c;
            while(coef > h) coef-=h;
            a[j][i] = 64+coef;
            c++;
        }
    }

    for(int i=h;i>=1;--i)
    {
        cout << a[i][c];
        if(i!=1) cout << ", ";
    }


}
