//63022 Sathana Laolugsanalerd
#include<iostream>
#include<string>

using namespace std;

int i,j;
int id[5] = {10001,10002,10003,10004,10005};
char name[5][100] = {{'C','h','r','i','s'},{'T','o','m'},{'T','a','y','l','o','r'},{'H','u','g','h'},{'K','r','i','s','t','e','n'}};
char surname[5][100] = {{'H','e','m','s','w','o','r','t','h'},{'C','r','u','i','s','e'},{'S','w','i','f','t'},{'G','r','a','n','t'},{'S','t','e','w','a','r','t'}};
int day[5] = {11,3,13,9,9};
int month[5] = {12,4,12,9,4};
int year[5] = {2552,2552,2552,2551,2552};
int joinedday[5] = {3,6,1,1,7};
int joinedmonth[5] = {5,5,5,5,5};
int joinedyear[5] = {2560,2555,2560,2560,2560};
int room[5] = {4,4,2,1,1};

int len(char c[]){
    int x = 0;
    while(c[x]!='\0') x++;
    return x;
}

typedef struct joineddate{

    int day;
    int month;
    int year;

};


typedef struct record{

    int id;
    char name[100];
    char surname[100];
    int day;
    int month;
    int year;
    struct joineddate joined;
    int room;

};

main(){

int namelength[5],surnamelength[5];

record stdrecord[5];
for(i=0;i<5;i++){
    namelength[i] = len(name[i]);
    surnamelength[i] = len(surname[i]);
    stdrecord[i].id = id[i];

    for(j=0;j<namelength[i];j++){
        stdrecord[i].name[j] = name[i][j];
    }
    for(j=0;j<surnamelength[i];j++)
        stdrecord[i].surname[j] = surname[i][j];

    stdrecord[i].day = day[i];
    stdrecord[i].month = month[i];
    stdrecord[i].year = year[i];
    stdrecord[i].joined.day = joinedday[i];
    stdrecord[i].joined.month = joinedmonth[i];
    stdrecord[i].joined.year = joinedyear[i];
    stdrecord[i].room = room[i];
}

for(i=0;i<5;i++){
    cout << stdrecord[i].id << " ";
    for(j=0;j<namelength[i];j++)
        cout << stdrecord[i].name[j];
    cout << " ";
    for(j=0;j<surnamelength[i];j++)
        cout << stdrecord[i].surname[j];
    cout << " ";
    cout << stdrecord[i].day << " ";
    cout << stdrecord[i].month << " ";
    cout << stdrecord[i].year << " ";
    cout << stdrecord[i].joined.day << " ";
    cout << stdrecord[i].joined.month << " ";
    cout << stdrecord[i].joined.year << " ";
    cout << stdrecord[i].room << endl;
}

}


