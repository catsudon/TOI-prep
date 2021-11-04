#include<iostream>

using namespace std;

int main(){

int n;
cin >> n;
int day[n];
int i;
int sum[n];
for(i=0;i<n;i++){
        cin >> day[i];
        i==0?sum[i]=0:sum[i]=sum[i-1];

        if(day[i]>day[i-1] && i!=0){sum[i]+=day[i]-day[i-1];}
    }
int time;
cin >> time;
for(i=0;i<time;i++){
    int a,b;
    cin >> a >> b;
    cout << sum[b-1]-sum[a-1] <<endl;
}


}
