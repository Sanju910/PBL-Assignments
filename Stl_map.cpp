#include <iostream>
#include <map>
#include<vector>

using namespace std;

class Person{
    string dob;
    long long tele;
    
    public:
    
    Person(){
        dob="";
        tele = 123456789;
    }
    

    
    void getdata(){
        cin>>dob>>tele;
    }
    
    void display(){
        cout<<dob<<endl;
        cout<<tele<<endl;
    }
};

int main(){
     map<string, Person*> m;
     string name;
     vector<string>v;
     int ch;
     char c;
     
     Person* p;
     
     do{
         cout<<"\n......Menu......";
         cout<<"\n1. Add a record";
         cout<<"\n2. Display all records";
         cout<<"\n3. Search a record";
         cout<<"\n4. Update a record";
         cout<<"\n5. Delete a record";
         cout<<"\n0. Exit";
         cout<<"\n\nEnter a choice: ";
         cin>>ch;
     switch(ch){
         
         case 1:
             do{
             p = new Person();
             cout<<"\nEnter the name of the person: ";
             cin>>name;
             p->getdata();
             m[name] = p;
             cout<<"\nDo you want to add more records?(y/n): ";
             cin>>c;
             }while(c== 'y' || c=='Y');
             
         break;
        
         case 2:
             for(const auto&elem: m){
                 cout<<endl<<endl;
                 cout<<elem.first<<endl;
                 elem.second->display();
                 
             }
        
        break;
        
        case 3:
             cout<<"\nEnter the name of the person to be searched: ";
             cin>>name;
             if(m[name] == NULL)
                 cout<<"\nPerson not found";
             else{
             cout<<"\n\n";
             cout<<name<<endl;
             m[name]->display();
             }
            
        break;
           
        case 4:
            cout<<"\nEnter the name of the person: ";
             cin>>name;
             if(m[name] == NULL)
                 cout<<"\nPerson not found";
             else{
             cout<<"\n\n";
             m[name]->getdata();
             }
          
        break;
          
        case 5:
            cout<<"\nEnter the name of the person: ";
             cin>>name;
             if(m[name] == NULL)
                 cout<<"\nPerson not found";
             else{
             cout<<"\n\n";
             m.erase(name);
             cout<<"\nRecord deleted";
             }
     }
     }while(ch!=0);
}
