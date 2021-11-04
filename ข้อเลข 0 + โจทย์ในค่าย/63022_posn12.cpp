#include<iostream>
#include<string>

using namespace std;
int x;
typedef struct{

char seq[100];
int count = 1;
int stringlen=0;

}sequence;

int main(){

sequence list[100];
string a;
cin >> a;
int count = 0;
int len = 0;
for(int i=0;i<a.length();i++){
    if(a[i]=='0'){
        list[count].seq[len] = a[i];
        list[count].stringlen = len+1;
        for(int k=0;k<count;k++){
            x=0;
            if(list[count].stringlen == list[k].stringlen && (char)list[k].seq[0] != '0')
              //  cout << list[k].seq[0];
                for(int j=0;j<list[count].stringlen;j++){
                    if(list[count].seq[j]==list[k].seq[j]) x++;
                    else break;
                }
              //  cout << list[k].stringlen << " and " << x << endl;
                if(x == list[k].stringlen){
                    list[k].count++;
                    list[count].seq[0] = '0';
                }
        }
        len = 0;
        count++;
    }
    else if(a[i]>='0' && a[i]<='9'){
        list[count].seq[len] = a[i];
        len++;
    }
    else{
        cout << "error";
        return 0;
    }
}

for(int i=0;i<count;i++){
    if(list[i].seq[0]!='0'){
    for(int j=0;j<list[i].stringlen;j++)
        cout << list[i].seq[j];
    for(int j=0;j<15-list[i].stringlen;j++) cout << " ";
    cout << list[i].count << endl;
    }
}



}
