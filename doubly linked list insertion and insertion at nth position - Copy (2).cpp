#include<iostream>
using namespace std;
struct Node{
           int data;
           Node* next;
           Node* prev;
};
Node* head;
void Insert(Node* temp2,int x)
{
           Node* temp=new Node();
           temp->data=x;
           temp->prev=NULL;
           temp->next=NULL;
           while(temp2->next!=NULL)
           {
                      temp2=temp2->next;
           }
           temp2->next=temp;
           temp->prev=temp2;
}
void Insertatposition(int data, int pos, int n)
{
           Node* temp=new Node();
           temp->data=data;
           temp->next=NULL;
           temp->prev=NULL;
           Node* curr=head;
           Node* temp2;
           if(pos==0)
           {
                      temp->next=curr;
                      head=temp;
                      curr->prev=temp;
           }
           else if(pos==n)
           {
                      while(curr->next!=NULL)
                      {
                                 curr=curr->next;
                      }
                      curr->next=temp;
                      temp->prev=curr;
           }
           else
           {
                      int i=0;
                      while(i<pos-1)
                      {
                                 curr=curr->next;
                                 i++;
                      }
                      temp2=curr->next;
                      temp2->prev=temp;
                      temp->next=curr->next;
                      temp->prev=curr;
                      curr->next=temp;
           }
}
void print(Node* head)
{
           while(head != NULL)
           {
                      cout<<head->data;
                      head=head->next;
           }
           cout<<endl;
}
int main()
{
           head=NULL;
           int n,i,x;
           cin>>n;
           for(i=1;i<=n;i++)
           {
                      cin>>x;
                      if(i==1)
                      {
                                 Node* temp=new Node();
                                 temp->data=x;
                                 temp->next=NULL;
                                 temp->prev=NULL;
                                 head=temp;
                      }
                      else
                      {
                                 Insert(head,x);
                      }
           }
           print(head);
           int data,pos;
           cin>>data;
           cin>>pos;
           Insertatposition(data,pos,n);
           print(head);
           return 0;
}
