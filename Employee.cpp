#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
class Employee
{
    public:
    int emp_id,age;
    float salary;
    string name;
    string department;
    void getData()
    {
    cout<<"\nEnter the emp_id: ";
    cin>>this->emp_id;
    cout<<"\nEnter the NAME: ";
    cin>>this->name;
    cout<<"\nEnter the AGE: ";
    cin>>this->age;
    cout<<"\nEnter the DEPARTMENT: ";
    cin>>this->department;
    cout<<"\nEnter the SALARY: ";
    cin>>this->salary;
    }
    void showData()
    {
    cout<<"Name: "<<this->name<<endl;
    cout<<"age: "<<this->age<<endl;
    cout<<"Employee ID: "<<this->emp_id<<endl;
    cout<<"Department: "<<this->department<<endl;
    cout<<"Salary: "<<this->salary<<endl;
   } 

    void SearchData(int emp)
    {
        ifstream fin;
        fin.open("EmployeeDatabase.txt",ios::in|ios::binary);
        fin.read((char*)this,sizeof(*this));
        while(fin)
        {
           if(this->emp_id==emp)
           {
            cout<<endl<<endl;
            showData();
            return;
           }
           fin.read((char*)this,sizeof(*this));
        }
        
        cout<<"\nEmployee Not Found";
     fin.close();
    } 

    void update(int emp)
    {
        fstream file;
        int count=0; file.open("EmployeeDatabase.txt",ios::in|ios::binary|ios::out|ios::ate);
        file.seekg(0);
        while(file)
        {
            file.read((char*)this,sizeof(*this));
            count++;
            if(this->emp_id==emp)
            {
                getData();
                file.seekp((count-1)*sizeof(*this));
                    file.write((char*)this,sizeof(*this));
            }
        }
        file.close();
    }
};
int main()
{
    Employee e;
    int n,a;
    char choice;
    fstream f;
    /*
    e.ShowDataFromFile();
    cout<<endl;
    cout<<"Insert into the file: "<<endl;
    e.InsertintoFile();
    cout<<endl;
    cout<<"Displaying From files"<<endl;
    e.ShowDataFromFile();
    cout<<endl;
    cout<<"Enter the emp id to be sreached: "<<endl;
    cin>>n;
    e.SearchData(n);
    cout<<endl;
    cout<<"Enter the emp id to be updated: ";
    cin>>n;
    e.update(n);
    cout<<"-------------------------------------------";
    cout<<endl;
    e.ShowDataFromFile();
    cout<<"Thankyou"<<endl;
    */
    
     do{
    cout<<"\n\n";
    cout<<"\n1. Add Employee"<<endl;
    cout<<"2. Display"<<endl;
    cout<<"3. Search"<<endl;
    cout<<"4. Update"<<endl;
    cout<<"0 Exit"<<endl;
    cout<<"Enter your choice: ";
    cin>>a;
    
    switch (a) {
        case 1:
            cout<<endl<<endl;
       f.open("EmployeeDatabase.txt",ios::out|ios::binary|ios::app);
            do{
               e.getData();
          f.write((char*)&e,sizeof(e));
                cout<<"\nDo you want to add more?: ";
                cin>>choice;
                cout<<choice;
                cout<<endl;
            }while(choice=='y'|| choice=='Y');
            f.close();
            break; 

        case 2:
        f.open("EmployeeDatabase.txt",ios::in|ios::binary);
        cout<<endl<<endl;
        f.read((char*)&e,sizeof(e));
        while(!f.eof())
      {
        e.showData();
        cout<<endl<<endl;
        f.read((char*)&e,sizeof(e));
      }
            f.close();
            
            break;
           
        case 3:
            cout<<endl<<endl;
            cout<<"\nEnter the emp id to be searched: "<<endl;
            cin>>n;
            e.SearchData(n);
            cout<<endl;
            break;
           
        case 4:
            cout<<endl<<endl;
            cout<<"\nEnter the emp id to be updated: ";
            cin>>n;
            e.update(n);
            cout<<endl;
            break;
        case 0:
            exit(1);
        default:
            cout<<"\nEnter a valid choice";     
    }
    }while (a!=0);
    return 0;
}
