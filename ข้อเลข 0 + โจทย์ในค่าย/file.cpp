//63022 Sathana Laolugsanalerd
#include<iostream>
#include <fstream>

using namespace std;

int main(){
    ofstream fp("oddnumber.txt",ofstream::app);
    for(int i=1;i<100;i+=2)
    fp << i << endl;
}

