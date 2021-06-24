#include<iostream>
using namespace std;
struct Node{
           int data;
           Node* next;
};
Node* head;
void Insert(Node* temp2, int x)
{
           Node* temp=new Node();
           temp->data=x;
           temp->next=NULL;
           while(temp2->next!=NULL)
           {
                      temp2=temp2->next;
           }
           temp2->next=temp;
}
void sortlist()
{
           Node* curr=head;
           Node* temp=NULL;
           int temp2;
           while(curr!=NULL)
           {
                      temp=curr->next;
                      while(temp!=NULL)
                      {
                                 if(curr->data>temp->data)
                                 {
                                            temp2=curr->data;
                                            curr->data=temp->data;
                                            temp->data=temp2;
                                 }
                                 temp=temp->next;
                      }
                      curr=curr->next;
           }
}
void print(Node* head)
{
           cout<<"List is:";
           while(head != NULL)
           {
                      cout<<head->data;
                      head=head->next;
           }
           cout<<endl;
}
int main()
{
           head= NULL;
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
                                  head=temp;
                       }
                       else
                       {
                                  Insert(head,x);
                       }
            }
            print(head);
            sortlist();
            print(head);
            return 0;
}
