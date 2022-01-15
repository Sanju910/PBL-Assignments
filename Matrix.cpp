#include <iostream>
#include<exception>
using namespace std; 

class ADT{
    
    int r1, c1, r2, c2, i, j, k;
    int mat1[4][4], mat2[4][4], sum[4][4], prod[4][4],diff[4][4];
    
    public:
        ADT():r1(0),c1(0),r2(0),c2(0){}
        void getData(){
            
            try{
                cout<<"\nEnter the number of  rows  for matrix 1: ";
                cin>>r1;
                cout<<"\nEnter the number of column for matrix 1: ";
                cin>>c1;
                cout<<"\nEnter the number of  rows  for matrix 2: ";
                cin>>r2;
                cout<<"\nEnter the number of column for matrix 2: ";
                cin>>c2;
                
                if(r1>4 || r2>4 || c1>4 || c2>4) throw exception();
                
                else{
                    cout<<"\nEnter the values for the first matrix: \n";
                    for (i = 0; i < r1; i++) {
                        for (j = 0; j < c1; j++) {
                            cout<<"mat1["<<i<<"]["<<j<<"]: ";
                            cin>>mat1[i][j];
                        }
                    }
                    
                    cout<<"\nEnter the values for the second matrix: \n";
                    for (i = 0; i < r2; i++) {
                        for (j = 0; j < c2; j++) {
                            cout<<"mat2["<<i<<"]["<<j<<"]: ";
                            cin>>mat2[i][j];
                        }
                    }
                }
                
            }
            catch(exception &){
                cout<<"\nERROR: Row or column size greater than the array size entered.\n";
                exit(0);
            }
        }
        
        void display(){
            cout<<"\nMatrix 1 is: \n";
            for (i = 0; i < r1; i++) {
                for (j = 0; j < c1; j++) {
                    cout<<mat1[i][j]<<"\t";
                }
                cout<<endl;
            }
            
            cout<<"\nMatrix 2 is: \n";
            for (i = 0; i < r2; i++) {
                for (j = 0; j < c2; j++) {
                    cout<<mat2[i][j]<<"\t";
                }
                cout<<endl;
            }    
        }
        
        void operations(){
            try{
                if (r1 == r2 && c1 == c2) {
                cout<<"\nAddition of the 2 matrices is: \n";
                for (i = 0; i < r2; i++) {
                    for (j = 0; j < c2; j++) {
                        sum[i][j] = mat1[i][j] + mat2[i][j];
                    }
                }
                for (i = 0; i < r2; i++) {
                    for (j = 0; j < c2; j++) {
                        cout<<sum[i][j]<<"\t";
                    }
                    cout<<endl;
                }
        
            } else throw exception();
            }
            
            catch(exception &){
                cout<<"\nAddition is not possible for the 2 matrices as the dimensions do not match.\n";
                exit(0);
            } 

            try{
                if (r1 == r2 && c1 == c2) {
                cout<<"\nSubtraction of the 2 matrices is: \n";
                for (i = 0; i < r2; i++) {
                    for (j = 0; j < c2; j++) {
                        diff[i][j] = mat1[i][j] - mat2[i][j];
                    }
                }
                for (i = 0; i < r2; i++) {
                    for (j = 0; j < c2; j++) {
                        cout<<diff[i][j]<<"\t";
                    }
                    cout<<endl;
                }
        
            } else throw exception();
            }
     catch(exception &){
                cout<<"\nSubtraction is not possible for the 2 matrices as the dimensions do not match.\n";
                exit(0);
            }
            
            try{
                if (c1 == r2) {
                    cout<<"\nProduct of the 2 matrices is: \n";
                
                    for (i = 0; i < r1; i++) {
                        for (j = 0; j < c2; j++) {
                            prod[i][j] = 0;
                            for (k = 0; k < r1; k++) {
                                prod[i][j] += mat1[i][k] * mat2[k][j];
                            }
                        }
                    }
                    for (i = 0; i < r1; i++) {
                        for (j = 0; j < c2; j++) {
                            cout<<prod[i][j]<<"\t";
                        }
                        cout<<endl;
                    }
                } else throw exception();
            }
            catch(exception &){
                cout<<"\nProduct is not possible as the required conditions for multiplication are unsatisfied\n";
                exit(0);
            }
        }
        
        
}; 

int main() {
    ADT obj;
    obj.getData();
    obj.display();
    obj.operations();
}
