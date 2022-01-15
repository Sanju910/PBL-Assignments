
#include<iostream>
using namespace std;
class node
{
  public:
  int seat_no;
  char status;
  node *prev,*next;
};


class ticket
{
  public:
  node *head[10],*last[10];
  ticket()
  {
   for(int i=0;i<10;i++)
   {
    head[i]=NULL;
    last[i]=NULL;
   }
  }
  public:
  void  create_bookingsys();
  void display();
  void booking();
  void cancel_booking();
};
void ticket::create_bookingsys()
{
  int i,j;
  for(i=0;i<10;i++)
  {
   for(j=0;j<15;j++)
   {
    node *ptr;
    ptr=new node();
    ptr->prev=ptr->next=NULL;
    ptr->seat_no=j+1;
    ptr->status='F';
    if(head[i]==NULL)
    {
     head[i]=ptr;
     last[i]=ptr;
    }
    else
    {
     last[i]->next=ptr;
     ptr->prev=last[i];
     ptr->next=head[i];
     last[i]=ptr;
    }
   }
   head[i]->prev=last[i];
  }
}
void ticket::display()
{
  node *temp;
  for(int i=0;i<10;i++)
  {
   temp=head[i];
   cout<<"\nROW NO"<<" "<<i+1<<"->"<<"\t";
   do
   {
    if(temp->status=='F')
        cout<<temp->seat_no<<"\t";
    else
        cout<<"B\t";
    
    temp=temp->next;
   }while(temp!=head[i]);
   cout<<"\n";
   }
}
void ticket::booking()
{
  int row,seatno,count=0;
  node *temp;
  cout<<"ENTER THE ROW NO";
  cin>>row;
  cout<<"Enter the no of seats";
  cin>>seatno;
  temp=head[row-1];
  do
  {
   if(temp->status=='F')
    {
     count++;
    }
   else if(temp->status=='B')
    {
     count=0;
    }
   if(count==seatno)
     {
      temp=head[row-1];
      if(temp->status!='F')
      {
        while(temp->status!='F')
        {
         temp=temp->next;
        }
        for(int i=0;i<seatno;i++)
        {
         temp->status='B';
         temp=temp->next;
        }
       }
      else
      {
       for(int i=0;i<seatno;i++)
       {
        temp->status='B';
        temp=temp->next;
       }
      }
    }
    temp=temp->next;
   }while(temp!=head[row-1]);
}
void ticket::cancel_booking()
{
  int row,seatno,loc;
  node *temp;
  cout<<"Enter the row from where you want to cancel booking"<<endl;
  cin>>row;
  cout<<"Enter the location for booking"<<endl;
  cin>>loc;
  cout<<"Enter the no of seats to be cancelled"<<endl;
  cin>>seatno;
  temp=head[row-1];
  for(int i=0;i<loc-1;i++)
  {
   temp=temp->next;
  }
  for(int i=0;i<seatno;i++)
  {
   temp->status='F';
   temp=temp->next;
  }
}
int main()
{
int ch;
ticket c;
c.create_bookingsys();

cout<<"-------Welcome to CINEMAX-------\n\n";
do
{

c.display();
cout<<"\n\n";
cout<<"\n1. Book a Show \n2. Cancel Booking\n3. Exit";
cin>>ch;

switch (ch)
{
  
  case 1:
        c.display();
        c.booking();
        break;
  case 2:
        c.cancel_booking();
        c.display();
        break;
  case 3:
        exit(0);
        break;
    
  default:
      cout<<"Please enter a valid option!!";
}
}while(ch!=3);

return 0;
} 


