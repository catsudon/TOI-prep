#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
map<vector<int>,bool> vst;
map<vector<int>,bool> goal;

int evaluate()
{

}

int main()
{
/*goal[{0,1,2,3,4,5,6,7,8}] = true;
goal[{1,0,2,3,4,5,6,7,8}] = true;
goal[{1,2,0,3,4,5,6,7,8}] = true;
goal[{1,2,3,0,4,5,6,7,8}] = true;
goal[{1,2,3,4,0,5,6,7,8}] = true;
goal[{1,2,3,4,5,0,6,7,8}] = true;
goal[{1,2,3,4,5,6,0,7,8}] = true;
goal[{1,2,3,4,5,6,7,0,8}] = true; */
    goal[{1,2,3,4,5,6,7,8,0}] = true;
    vector<int> ss(9);
    for(int i=0;i<9;++i) cin >> ss[i];

    queue<pair<int,vector<int> > > q;
    q.push({0,ss});
    while(!q.empty())
    {
        int F = q.front().f;
        vector<int> S = q.front().s;
        q.pop();
        if(vst[S]) continue;
        vst[S] = true;
        if(goal[S]!=NULL)
        {
            cout << F;
            return 0;
        }
        for(int i=0;i<9;++i) if(i%3==2)cout << S[i] << " " << endl; else cout << S[i] << " ";
        cout << "\n";
        for(int i=0;i<9;++i)
        {
            if(S[i]==0)
            {
                if(i==0 || i==3 || i==6 || i==1 || i==4 || i==7)
                {
                    vector<int> tempv = S;
                    swap(tempv[i],tempv[i+1]); //right
                    q.push({F+1,tempv});
                }
                if(i<6)
                {
                    vector<int> tempv = S;
                    swap(tempv[i],tempv[i+3]); //down
                    q.push({F+1,tempv});
                }
                if(i==1 || i==2 || i==4 || i==5 || i==7 || i==8)
                {
                    vector<int> tempv = S;
                    swap(tempv[i],tempv[i-1]); //left
                    q.push({F+1,tempv});
                }
                if(i>2)
                {
                    vector<int> tempv = S;
                    swap(tempv[i],tempv[i-3]); //up
                    q.push({F+1,tempv});
                }
                break;
            }
        }
    }
    cout << "no way";

}
