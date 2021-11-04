#include<iostream>

using namespace std;

int main(){


int n;
cin >> n;
int mount[n],max=0;
for(int i=0;i<n;i++){

    cin >> mount[i];
    if(mount[i]>max) max=mount[i];

}
for(int i=0;i<max;i++){

    for(int j=0;j<n;j++){
        for(int k=1;k<mount[j]+1;k++){
            i+k==max ? cout << "/" : cout << " ";
        }
        for(int l=mount[j];l>0;l--){
            i+l==max ? cout << "\\" : cout << " ";
        }

    }
cout << endl;


}
}
