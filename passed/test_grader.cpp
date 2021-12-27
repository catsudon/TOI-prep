#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c; cin >> a >> b >> c;
    int sum = a+b+c;
    sum/=5;
    string grade = "FFFFFFFFFFDdCcBbAAAAAA";
    if(grade[sum] == 'd') cout << "D+";
    else if(grade[sum] == 'c') cout << "C+";
    else if(grade[sum] == 'b') cout << "B+";
    else cout << grade[sum];

}
