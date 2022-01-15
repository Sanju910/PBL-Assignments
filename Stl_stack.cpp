#include<iostream>
#include<stack>
using namespace std;
stack<int> read()
 {
 stack<int> s;
 char x;
 int n,i;
 cout<<"\nEnter the no. of bits in the no. : ";
 cin>>n;
 cout<<n;
 cout<<"\nEnter the binary number : ";
 for(i=0;i<n;i++)
 {
 cin>>x;
 cout<<x;
 s.push((int)x-48);
 }
 return s;
 }
 
void display(stack<int> &s)
 {
 cout<<" ";
 while(!s.empty())
 {
 cout<<s.top()<<" ";
 s.pop();
}
 }
 
stack<int> add(stack<int> &s1,stack<int> &s2)
 {
 stack<int> s;
 int sum,carry=0,b1,b2;
 while(!s1.empty()||!s2.empty())
 {
 b1=b2=0;
 if(!s1.empty())
 {
 b1=s1.top();
 s1.pop();
 }
 if(!s2.empty())
 {
 b2=s2.top();
 s2.pop();
 
 }
 sum=(b1+b2+carry)%2;
 carry=(b1+b2+carry)/2;
 s.push(sum);
 }
 if(carry==1)
 s.push(1);
 return s;
 }
 /* MAIN FUNCTION*/
int main()
 {
 stack<int> s1,s2,s3;
 char ch;
 cout<<"\n\t\t\t***Binary Adder***\n";
 do
 {
 
 s1=read();
cout<<endl;
 s2=read();
 cout<<endl;
 cout<<"\nThe result of addition is :";
 s3=add(s1,s2);
 display(s3);
 
 cout<<"\n\nWanna Add more?(y/n) : ";
 cin>>ch;
 cout<<ch;
 cout<<"\n\n";
 }while(ch=='y' || ch=='Y');
 return 0;
 }
