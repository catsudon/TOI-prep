#include<iostream>
#include<vector>

using namespace std;

struct student{

int room;
int id;

};


int main(){

int Nc,Ns;
cin >> Nc >> Ns;
vector<student> line;
vector<student> student;


int rm,id,i,j;
for(i=0;i<Ns;i++){
    cin >> rm >> id;
    student.push_back({rm,id});
}

int loop=1;
char command;
int num;
while(loop==1){
    cin >> command;
    if(command=='E'){
        int ed = 0;
        cin >> num;
        int room;
        for(i=0;i<Ns;i++){
            if(num==student[i].id) {
                room = student[i].room;
                break;
            }

        }
        for(j=line.size()-1;j>-1;j--){
            if(room==line[j].room) {
                line.insert(line.begin()+j+1,{room,num});
                ed = 1;
                break;
            }

        }
        if(line.size()==0){
            line.push_back({room,num});
        }
        else if(ed==0){
                line.push_back({room,num});
               // cout << "inn else " << room << " " << num << endl;

            }
    }
    else if(command=='D'){
        cout << line[0].id << endl;
        line.erase(line.begin());
    }
    else if(command=='X'){
        loop=0;
        cout << "0";
    }
}

}
