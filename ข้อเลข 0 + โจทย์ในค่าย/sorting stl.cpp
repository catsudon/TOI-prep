#include <bits/stdc++.h>

using namespace std;

int main()
{
    string arr[] = { "c","ab","ac","c"};
    cout << sizeof(arr) << endl;
    int n = size(arr) / size(arr[0]);

    sort(arr,arr+n);

    cout << "Array after sorting : \n";
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";

    return 0;
}
