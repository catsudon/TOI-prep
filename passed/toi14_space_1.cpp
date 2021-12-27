#include<bits/stdc++.h>
using namespace std;
int n,m;
int k=0,t=0,mr=0;
int r=0,l=0,d=0;
int far_l,far_r,depth;
int dx[4] = {69,0,0,1};  /// 1 == right  2 == left
int dy[4] = {9,1,-1,0};  /// 3 == down
int jordi,polla;
bitset<2001> a[10001];

int sol(int x,int y)
{
    if(!a[x][y] or a[x][y]==NULL or x < 1 or y < 1 or x > n or y > m) return 0;
    a[x][y] = NULL;
    far_l = min(far_l,y);
    far_r = max(far_r,y);
    depth = max(depth,x);
    if(y > polla) r++;
    if(y < polla) l++;
    if(x > jordi) d++;
    for(int i=1;i<=3;++i)
    {
        sol(x+dx[i],y+dy[i]);
    }
}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> m >> n;
    char temp;
    for(int i=1;i<=n;++i) for(int j=1;j<=m;++j)
    {
        cin >> temp; temp-='0';
        a[i][j] = temp;
    }
    for(int i=1;i<=n;++i) for(int j=1;j<=m;++j)
    {
        if(a[i][j]==NULL or !a[i][j]) continue;
        jordi = i , polla = j , l = 0 , r = 0 , d = 0;
        far_l = 696969 , far_r = -1 , depth = -1;
        sol(i,j); depth -=i;
   //     cerr << "at " << i << " " << j << " : l = " << l << "  r = " << r << " d = " << d << endl;
     //   cerr << "       left = " << far_l << " right = " << far_r << " " << "depth = " << depth << endl;
        if(l==0 and r == d) k++;
        else if(depth == far_r-far_l) t++;
        else mr++;
    }

    cout << k << " " << t << " " << mr;
}
