#include<bits/stdc++.h>
using namespace std;
int parent
int find(int num)
{
    if(parent[num]==0) return num;
    return parent[num] = find(parent[num]);
}

int main()
{

}
