#include<bits/stdc++.h>
using namespace std;
vector<int> prefix = {0,1,6,8,9};
vector<int> v;
int match[10];
int expo[] = {1,10,100,1000,10000,100000,1000000,10000000,100000000};

int llenn=0;
bool isOdd = 0;

int perm(int sum,int num,int len)
{
    sum*=10;
    sum+=num;
    len++;
    if(len == llenn)
    {
        if(llenn == 1 and( sum == 6 or sum ==9) ) return 0;
        v.push_back(sum);
        return 0;
    }
    if(len == llenn/2)
    {
        if(isOdd) // make palindrome then fill mid with 0 1 8   // 1 .. 1  // 6 .. 9
        {
            int temp = sum;
            temp *= expo[llenn-len]; //  o o x 1 1 to   1 1 x 0 0
            int cf = 1;
            for(int i = expo[llenn-1] ; i > expo[len] ; i/=10)
            {
                temp+=match[ (temp/i) % 10  ] * cf;
                cf*=10;

            }
         //   cerr << temp << endl;

            v.push_back(temp);
            temp += expo[len]*1;
            v.push_back(temp);
            temp -= expo[len]*1;
            temp += expo[len]*8;
            v.push_back(temp);

        }
        if(!isOdd) // just make palindrome
        {
            int temp = sum; // o o 1 1  to 1 1 0 0
            temp *= expo[len];
            int cf = 1;
            for(int i = expo[llenn-1] ; i >= expo[len] ; i/=10)
            {
                temp+=match[ (temp/i) % 10 ] * cf;
                cf*=10;
            }
       //     cerr << temp << endl;
            v.push_back(temp);


        }


        return 0;
    }
    for(auto it : prefix)
    perm(sum,it,len);
}

int main()
{
    match[0] = 0;
    match[1] = 1;
    match[6] = 9;
    match[9] = 6;
    match[8] = 8;

    int n; cin >> n;
    for(int target = 1;target <=10000000 ; target*=10)
    {
        isOdd = !isOdd;
        llenn++;
        for(auto it : prefix)
            if(target>1 and it ==0) continue; // 0 1 0 is not valid
            else perm(0,it,0);
    }

    cout << v[n-1];
}
