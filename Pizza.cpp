#include <iostream>
using namespace std;
class customer
{
public:
 void pizza_lover(char pizza[], int n)
 {
 cout << "\n";
 for (int i = 0; i < n; i++)
 {
 cout << "Does Customer " << i + 1 << " like pizza (y/n) :";
 cin >> pizza[i];
 }
 cout << "\n";
 }
 void burger_lover(char burger[], int n)
 {
 for (int i = 0; i < n; i++)
 {
 cout << "Does Customer " << i + 1 << " like burger (y/n) :";
 cin >> burger[i];
 }
 }
};

int main()
{
 customer C;
 int n;
 cout << "Enter number of customers :";
 cin >> n;
 char pizza[n];
 char burger[n];
 C.pizza_lover(pizza, n);
 C.burger_lover(burger, n);
 int ch;
 cout << "\n1]Set of customers who like either pizza or burger or both " << endl;
 cout << "2]Set of customers who like both pizza and burger" << endl;
 cout << "3]Set of customers who like only pizza, not burger" << endl;
 cout << "4]Set of customers who like only burger not pizza" << endl;
 cout << "5]Number of customers who like neither pizza nor burger" << endl;
 cout << "6]Enter 0 to exit" << endl;
 do
 {
 cout << "\nEnter your choice : ";
 cin >> ch;
 switch (ch)
 {
 case 1:
 cout << "Customers who like either pizza or burger or both are";
 for (int j = 0; j < n; j++)
 {
 if (pizza[j] == 'y' || burger[j] == 'y')
 {
 cout << "\nCustomer " << j + 1;
 }
 }
 cout << endl;
 break;
 case 2:
 cout << "Customers who like both pizza and burger are";
 for (int j = 0; j < n; j++)
 {
if (pizza[j] == 'y' && burger[j] == 'y')
 {
 cout << "\nCustomer " << j + 1;
 }
 }
 cout << endl;
 break;
 case 3:
 cout << "Customers who like only pizza, not burger are";
 for (int j = 0; j < n; j++)
 {
 if (pizza[j] == 'y' && burger[j]=='n')
 {
 cout << "\nCustomer " << j + 1;
 }
 }
 cout << endl;
 break;
 case 4:
 cout << "Customers who like only burger not pizza are";
 for (int j = 0; j < n; j++)
 {
 if (burger[j] == 'y' && pizza[j]=='n')
 {
 cout << "\nCustomer " << j + 1;
 }
 }
 cout << endl;
 break;
 case 5:
 cout << "Customers who like neither pizza nor burger are";
 for (int j = 0; j < n; j++)
 {
 if (pizza[j] == 'n' && burger[j] == 'n')
 {
 cout << "\nCustomer " << j + 1;
 }
 }
 cout << endl;
 break;
 };
} while (ch != 0);
}
