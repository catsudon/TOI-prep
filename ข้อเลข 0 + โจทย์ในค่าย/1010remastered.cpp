#include <cctype>
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;


int n,m;


int check1(string word,string table[],int j,int k){

int len = word.length();
int count = 1;
if(len>m-k){return 0;}
for(int i=1;i<len;i++){
    int b = tolower(word[i]);
    char aa = table[j][k+i];
    int a = tolower(aa);
    if(b==a){
        count++;
    }
    if(count==len){
        return 1;
    }
}

return 0;

}

int check2(string word,string table[],int j,int k){

int len = word.length();
int count = 1;
if(len>n-j ||len>m-k){return 0;}
for(int i=1;i<len;i++){
    int b = tolower(word[i]);
    char aa = table[j+i][k+i];
    int a = tolower(aa);
    if(b==a){
        count++;
    }
    if(count==len){
        return 1;
    }
}

return 0;

}

int check3(string word,string table[],int j,int k){

int len = word.length();
int count = 1;
if(len>n-j){return 0;}
for(int i=1;i<len;i++){
    int b = tolower(word[i]);
    char aa = table[j+i][k];
    int a = tolower(aa);
    if(b==a){
        count++;
    }
    if(count==len){
        return 1;
    }
}

return 0;

}

int check4(string word,string table[],int j,int k){

int len = word.length();
int count = 1;
if(len>n-j ||k<len-1){return 0;}
for(int i=1;i<len;i++){
    int b = tolower(word[i]);
    char aa = table[j+i][k-i];
    int a = tolower(aa);
    if(b==a){
        count++;
    }
    if(count==len){
        return 1;
    }
}

return 0;

}

int check5(string word,string table[],int j,int k){

int len = word.length();
int count = 1;
if(k<len-1){return 0;}
for(int i=1;i<len;i++){
    int b = tolower(word[i]);
    char aa = table[j][k-i];
    int a = tolower(aa);
    if(b==a){
        count++;
    }
    if(count==len){
        return 1;
    }
}

return 0;

}

int check6(string word,string table[],int j,int k){

int len = word.length();
int count = 1;
if(j<len-1 ||k<len-1){return 0;}
for(int i=1;i<len;i++){
    int b = tolower(word[i]);
    char aa = table[j-i][k-i];
    int a = tolower(aa);
    if(b==a){
        count++;
    }
    if(count==len){
        return 1;
    }
}

return 0;

}

int check7(string word,string table[],int j,int k){

int len = word.length();
int count = 1;
if(j<len-1){return 0;}
for(int i=1;i<len;i++){
    int b = tolower(word[i]);
    char aa = table[j-i][k];
    int a = tolower(aa);
    if(b==a){
        count++;
    }
    if(count==len){
        return 1;
    }
}

return 0;

}

int check8(string word,string table[],int j,int k){

int len = word.length();
int count = 1;
if(j<len-1 || len>m-k){return 0;}
for(int i=1;i<len;i++){
    int b = tolower(word[i]);
    char aa = table[j-i][k+i];
    int a = tolower(aa);
    if(b==a){
        count++;
    }
    if(count==len){
        return 1;
    }
}

return 0;

}





int main(){

cin >> n>>m;
string table[n];

for(int i=0;i<n;i++){
    cin >> table[i];
}
int w;
cin >> w;
string words[w];
for(int i=0;i<w;i++){
    cin >> words[i];
}
int check,limitbreak;
for(int i=0;i<w;i++){
      //  cout << "i : " << i << endl;
    check=0;
    limitbreak=0;
    string word = words[i];
    for(int j=0;j<n;j++){
          //  cout << "j : " << j << endl;
        for(int k=0;k<m;k++){
          //  cout << "k : " << k << endl;
            if(tolower(table[j][k])==tolower(word[0])){

                check = check1(word,table,j,k);
                if(check==1){
                    cout << j << " " << k << endl;
                    limitbreak =1;
                    break;
                }
                check = check2(word,table,j,k);
                if(check==1){
                    cout << j << " " << k << endl;
                    limitbreak =1;
                    break;
                }
                check = check3(word,table,j,k);
                if(check==1){
                    cout << j << " " << k << endl;
                    limitbreak =1;
                    break;
                }
                check = check4(word,table,j,k);
                if(check==1){
                    cout << j << " " << k << endl;
                    limitbreak =1;
                    break;
                }
                check = check5(word,table,j,k);
                if(check==1){
                    cout << j << " " << k << endl;
                    limitbreak =1;
                    break;
                }
                check = check6(word,table,j,k);
                if(check==1){
                    cout << j << " " << k << endl;
                    limitbreak =1;
                    break;
                }
                check = check7(word,table,j,k);
                if(check==1){
                    cout << j << " " << k << endl;
                    limitbreak =1;
                    break;
                }
                check = check8(word,table,j,k);
                if(check==1){
                    cout << j << " " << k << endl;
                    limitbreak =1;
                    break;
                }

            }
        if(limitbreak==1){
            break;
        }
        }
        if(limitbreak==1){
            break;
        }
    }







}






}

