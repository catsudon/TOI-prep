#include<bits/stdc++.h>
using namespace std;
char a[1009][1009];
bool vst[1009][1009];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int main()
{
    ios_base::sync_with_stdio(0); cin.tie();
    int n,m; cin >> n >> m;
    for(int i=0;i<n;++i) for(int j=0;j<m;++j) cin >> a[i][j];
    int score = 0;
    int q; cin >> q;
    while(q--)
    {
        int x,y; char cmd; cin >> x >> y >> cmd;
        if(x < 0 or x >= n or y < 0 or y >= n ){score-=5; continue;}
        if(a[x][y] == '-' or a[x][y] == '#' ){score-=5; continue;}
        if(cmd == 'L')
        {
            if(a[x][y-1] != '-'){score-=5; continue;}
            if(y-1<0){score-=5; continue;}
            swap(a[x][y],a[x][y-1]);
        }
        if(cmd == 'R')
        {
            if(a[x][y+1] != '-'){score-=5; continue;}
            if(y+1>=m){score-=5; continue;}
            swap(a[x][y],a[x][y+1]);
        }

        bool change = 1;
        while(change)
        {
            change=0;
            bool gravity = 1;
            while(gravity)
            {
                // gravity
                gravity = 0;
                for(int x=0;x<n-1;++x)
                {
                    for(int y=0;y<m;++y)
                    {
                        if(a[x][y] == '-' or a[x][y] == '#') continue;
                        if(a[x+1][y] != '-') continue;
                        swap(a[x+1][y],a[x][y]);
                        change=1; gravity=1;
                  //      cerr << "gravity worked\n";
                    }
                }
            }
            for(int i=0;i<n;++i){for(int j=0;j<m;++j) cerr << a[i][j] << " ";cerr << endl;} cerr << endl;

            // scorepoint
            queue<pair<pair<int,int>,char> > q; // x:y :: A/B
            for(int i=0;i<n;++i)
            for(int j=0;j<m;++j) vst[i][j] = 0;

            for(int x=0;x<n;++x)
            for(int y=0;y<m;++y)
            {
                if(a[x][y] == '-' or a[x][y] == '#') continue;
                q.push({{x,y},a[x][y]});
                change=0;
                while(q.size())
                {
                    int xx = q.front().first.first;
                    int yy = q.front().first.second;
                    char c = q.front().second;
                    q.pop();

                    cerr << xx << " "<< yy << " "<< c<<endl;
                    change=0;
                    for(int i=0;i<4;++i)
                    {
                        int ax = xx+dx[i];
                        int ay = yy+dy[i];
                        if(ax < 0 or ay < 0 or ax >=n or ay >=m) continue;
                        if(a[ax][ay] == c)
                        {q.push({{ax,ay},c}); change=1; vst[ax][ay]=1;}
                    }
                    if(change or vst[x][y]) a[x][y] = '-',score+=5;
                }
            }

            if(gravity) change=1;
        }
        for(int i=0;i<n;++i){for(int j=0;j<m;++j) cerr << a[i][j] << " ";cerr << endl;} cerr << endl;



    }

    cout << score << endl;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j) cout << a[i][j] << " ";
        cout << endl;
    }
}
