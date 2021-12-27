#include <iostream>
#include <set>
#include <string>
#include <cstdlib>
using namespace std;
int main() {
   set<int> st;
   set<int> it;
   int c, i;
   while (1) {
      cout<<"1.Size of the Set"<<endl;
      cout<<"2.Insert Element into the Set"<<endl;
      cout<<"3.Delete Element of the Set"<<endl;
      cout<<"4.Find Element in a Set"<<endl;
      cout<<"5.Display the set: "<<endl;
      cout<<"6.Exit"<<endl;
      cout<<"Enter your Choice: ";
      cin>>c;
      switch(c) {
         case 1:
            cout<<"Size of the Set: ";
            cout<<st.size()<<endl;
         break;
         case 2:
            cout<<"Enter value to be inserted: ";
            cin>>i;
            st.insert(i);
         break;
         case 3:
            cout<<"Enter the element to be deleted: ";
            cin>>i;
            st.erase(i);
         break;
         case 4:
            cout<<"Enter the element to be found: ";
            cin>>i;
            it = st.find(i);
            if (it != st.end())
               cout<<"Element "<<*it<<" found in the set" <<endl;
            else
               cout<<"No Element Found"<<endl;
         break;
         case 5:
            cout<<"Displaying Set by Iterator: ";
            for (it = st.begin(); it != st.end(); it++) {
               cout << (*it)<<" ";
            }
            cout<<endl;
         break;
         case 6:
            exit(1);
         break;
         default:
            cout<<"Wrong Choice"<<endl;
      }
   }
return 0;
}
