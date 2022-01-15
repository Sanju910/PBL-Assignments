#include <iostream>
using namespace std;




class Vehicle {
    public:
        
        float mileage;
        float price;
        
        
        Vehicle(float m, float p) {
            mileage = m;
            price = p;
        }
};


class Car: public Vehicle {
    public:
        
        float ownership_cost;
        int warranty;
        int seating_capacity;
        string fuel_type;
        
        
        Car(float m, float p, float oc, int w, int sc, string ft) : Vehicle(m,p)  {
            ownership_cost = oc;
            warranty = w;
            seating_capacity = sc;
            fuel_type = ft;
        }
};




class Bike: public Vehicle {
    public:
        
        int num_of_cylinders;
        int num_of_gears;
        string cooling_type;
        string wheel_type;
        int fuel_tank_size;
        
        
        Bike(float m, float p, int noc, int nog, string ct, string wt, int s) :  Vehicle(m,p) {
            num_of_cylinders = noc;
            num_of_gears = nog;
            cooling_type = ct;
            wheel_type = wt;
            fuel_tank_size = s;
        }
};




class Audi: public Car {
    public:
        
        string model_type;
        
       
        Audi(float m, float p, float oc, int w, int sc, string ft, string mt) 
         :  Car(m, p, oc, w, sc, ft) {
            model_type= mt;
        }


        void display(){
            cout<<"\nModel type : "<<model_type;
            cout<<"\nOwnersip cost : "<<ownership_cost;
            cout<<"\nWarranty : "<<warranty;
            cout<<"\nSeating capacity : "<<seating_capacity;
            cout<<"\nFuel type : "<<fuel_type;
            cout<<"\nMileage : "<<mileage;
            cout<<"\nPrice : "<<price;
        }
};






class Ford: public Car {
    public:
        string model_type;
        
        
        Ford(float m, float p, float oc, int w, int sc, string ft, string mt) 
        : Car(m, p, oc, w, sc, ft) {
            model_type= mt;
        }


        void display(){
            cout<<"\nModel type : "<<model_type;
            cout<<"\nOwnersip cost : "<<ownership_cost;
            cout<<"\nWarranty : "<<warranty;
            cout<<"\nSeating capacity : "<<seating_capacity;
            cout<<"\nFuel type : "<<fuel_type;
            cout<<"\nMileage : "<<mileage;
            cout<<"\nPrice : "<<price;
        }
};




class Bajaj: public Bike {
    public:
        string make_type;
        
    
    Bajaj(float m, float p, int noc, int nog, string ct, string wt, int s, string mt)
       : Bike(m,p,noc,nog,ct,wt,s) {
             make_type = mt;
        }


        void display(){
            cout<<"\nMake type : "<<make_type;
            cout<<"\nMileage : "<<mileage;
            cout<<"\nPrice : "<<price;
            cout<<"\nNo. of cylinders : "<<num_of_cylinders;
            cout<<"\nNo. of gears  : "<<num_of_gears;
            cout<<"\nCooling type : "<<cooling_type;
            cout<<"\nWheel type : "<<wheel_type;
            cout<<"\nTank size  : "<<fuel_tank_size;
        }        
};




class TVS: public Bike {
    public:
        string make_type;
        
        TVS(float m, float p, int noc, int nog, string ct, string wt, int s, string mt)
        : Bike(m,p,noc,nog,ct,wt,s){
             make_type = mt;
        }


        void display(){
            cout<<"\nMake type : "<<make_type;
            cout<<"\nMileage : "<<mileage;
            cout<<"\nPrice : "<<price;
            cout<<"\nNo. of Cylinders : "<<num_of_cylinders;
            cout<<"\nNo. of gears  : "<<num_of_gears;
            cout<<"\nCooling type : "<<cooling_type;
            cout<<"\nWheel type : "<<wheel_type;
            cout<<"\nTank size  : "<<fuel_tank_size;
        }    
};




int main()
{
      
      Ford f(25,670,790,3,5, "Diesel", "EcoSport");
     
      Audi a(20,500,600,5,7, "Petrol", "Q2");
      
      Bajaj b(15,200,3,4,"Air","Alloys",20.5,"Honda");
      
      TVS t(12,250,4,3,"Liquid","Spokes",10.5,"Activa");
      
      
      f.display();
      
      cout<<"\n\n\n";
      
      a.display();
      
      cout<<"\n\n\n";
      
      b.display();
      
      cout<<"\n\n\n";
     
      t.display();


    return 0;
}
