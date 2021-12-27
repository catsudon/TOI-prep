#include<iostream>

using namespace std;

int main(){

int a[4],b[4];
int same=0;

for(int i=0;i<4;i++) cin >> a[i];
for(int i=0;i<4;i++) cin >> b[i];

for(int i=0;i<4;i++) {
    for(int j=0;j<4;j++){
        if(a[i]==b[j] && a[i]!=-999999 && b[j]!=-888888){
            same++;
            int x = a[i];
            int y = b[j];
            for(int k=0;k<4;k++){
                if(a[k]==x) a[k] = -999999;
            }
            for(int l=0;l<4;l++){
                if(b[l]==y) b[l] = -888888;
            }
        }
    }
}


cout << same;

}
