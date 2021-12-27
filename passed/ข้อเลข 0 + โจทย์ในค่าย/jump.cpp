#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;

pair<int,int> ar[30009];
int main(){

int n,ability;
scanf("%d %d",&n,&ability);
int point[n];
int m=0;
int left=0,here=0;;
for(int i=0;i<n;++i){
    scanf("%d",&point[i]);
    ar[here+left].f = point[i];
    for(int j=0;j<left;++j){
        if(ar[here+j].f+ability>=point[i]) {
          //  cout << "ar[here+j].f = " << ar[here+j].f << " +  ability = " << ability << " >=  point = " << point[i] << endl;
            ar[here+j].s++;
            if(ar[here+j].s>m) m = ar[here+j].s;
        }
        else {
            left--;
            here++;
            j--;
        //    cout << "entered else  ";
        }
      //  cout << "point[i] = " << point[i] << "  ar[here+j] = " << ar[here+j].f << "  here = " << here << "  left = " << left << endl;
    }
    left++;
}
//cout << endl;
//for(int i=0;i<n;++i) cout << ar[i].s << " ";
printf("%d",m);
}
