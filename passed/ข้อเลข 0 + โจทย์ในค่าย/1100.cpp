#include<iostream>

using namespace std;

int main(){


int n;
long long int count=0;
cin >> n;
string students[n];
int i,j;


for(i=0;i<n;i++){
    cin >> students[i];
    for(j=0;j<i;j++){
        if(students[i][0]==students[j][0]){
            count++;
            //cout << count << "  k=0  " << students[i] << " " << students[j] <<endl;
        }


        else if(students[i][1]==students[j][1]){
            count++;
            //cout << count << "  k=1  " << students[i] << " " << students[j] <<endl;
        }


        else if(students[i][2]==students[j][2]){
            count++;
            // cout << count << "  k=2  " << students[i] << " " << students[j] <<endl;
        }

    }

}

//cout << (students[2]/10) %10;


cout << count;




}
