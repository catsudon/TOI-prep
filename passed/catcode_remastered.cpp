#include <bits/stdc++.h>
using namespace std;
#define big 1000000
int hashing[big];
bool check[big];
int val[100010];
int main()
{
    ios_base::sync_with_stdio(0);
    int codes, length;
    int i,j;
    cin>>codes>>length;
    memset(hashing, -1, sizeof(hashing));
    memset(val, 0, sizeof(val));
    string s;
    int num,hx;
    for (i = 0; i < codes; i++)
    {
        cin >> s;
        num = 0;
        for (j = 0; j < length; j++)
        {
            num = (num << 1) + s[j] - '0';
        }
        hx = num % big;
        while (hashing[hx] != -1)
        {
            hx++;
            hx %= big;
        }
        hashing[hx] = i;
        val[i] = num;
    }
    int tests;
    cin >> tests;
    memset(check, 0, sizeof(check));
    bool okay = true;
    int len;
    while (tests--)
    {
        cin >> len >> s;
        if (len < length)
        {
            cout << "OK" << endl;
            continue;
        }
        num = 0;
        for (i = len - length; i < len; i++)
        {
            num = (num << 1) + s[i] - '0';
        }
        for (i = len - length; i > -1; i--)
        {
            if (len - length - 1 >= i)
            {
                num += (1 << (length - 1)) * (s[i] - '0');
            }
            hx = num % big;
            while (hashing[hx] != -1)
            {
                j = hashing[hx];
                if (val[j] == num)
                {
                    check[j] = 1;
                    okay = false;
                    break;
                }
                hx++;
                hx %= big;
            }
            num = (num >> 1);
        }
        if (okay)
        {
            cout << "OK";
        }
        else
        {
            for (i = 0; i < codes; i++)
            {
                if (check[i])
                {
                    cout << i + 1 << " ";
                    check[i] = false;
                }
            }
            okay = true;
        }
        cout<<endl;
    }
}
