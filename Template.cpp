#include <iostream>
using namespace std; 

template<class T>
class Vector
{
public:
    T v[20];
    int size;
   
    
    void create()
    {
        int i=0;
        T value;
        char ans;
        size=0;
        do{
            cout<<"\nEnter the value:";
            cin>>value;
            v[i]=value;
            i++;
            size++;
            cout<<"\nDo you want more elements?";
            cin>>ans;
        }while(ans=='y'||ans=='Y');
    }
    
    void modify()
    {
        int i;
        T newvalue;
        cout<<"\nEnter key & new value: ";
        cin>>i>>newvalue;
        v[i]=newvalue;
            
        }
    void mult(){
        int scaler;
        cout<<"\nScaler value: ";
        cin>>scaler;
        for (int i=0; i<size ; i++)
        {
            v[i] = v[i]*scaler;
        }
    }
    void display()
    {
        cout<<"\nDisplaying the vector\n(";
        for(int i=0; i<size; i++){
            cout<<v[i]<<" ";
            }
        cout<<")"<<endl;
    } 

};




int main() {
    int a;
    Vector<int> ob;
    do{
    cout<<"\n\n\n";
    cout<<"\n1 Create"<<endl;
    cout<<"2 Modify"<<endl;
    cout<<"3 Multiple"<<endl;
    cout<<"4 Display"<<endl;
    cout<<"0 Exit"<<endl;
    cout<<"Enter your choice: ";
    cin>>a;
    
    switch (a) {
        case 1:
            ob.create();
            break;
            
        case 2:
            ob.modify();
            break;
           
        case 3:
            ob.mult();
            break;
           
        case 4:
            ob.display();
            break;
        case 0:
            exit(1);
        default:
            cout<<"\nEnter a valid choice";     
    }
    }while (a!=0); 

    return 0;
}
