#include<iostream>
using namespace std;
struct Node
{
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
void insert_in_sorted_likedlist(int data,int n)
{
           Node* temp=new Node();
           temp->data=data;
           temp->next=NULL;
           temp->prev=NULL;
           Node* curr;
           curr=head;
           Node* curr2;
           curr2=head;
           int count1=0;
           while(curr2!=NULL)
           {
                      curr2=curr2->next;
                      count1++;
           }
           int count=0;
           while(curr!=NULL)
           {
                      count++;
                      if(curr->data>temp->data)
                      {
                                 if(count==1)
                                 {
                                            Node* temp2;
                                            temp2=curr->prev;
                                            temp->next=curr;
                                            temp->prev=curr->prev;
                                            curr->prev=temp;
                                            head=temp;
                                            break;
                                 }
                                 else
                                 {
                                            Node* temp2;
                                            temp2=curr->prev;
                                            temp->next=curr;
                                            temp->prev=curr->prev;
                                            curr->prev=temp;
                                            temp2->next=temp;
                                            break;
                                 }
                      }
                      else{
                                 curr=curr->next;
                                 if(count==count1)
                                 {
                                            curr=head;
                                            while(curr->next!=NULL)
                                            {
                                                       curr=curr->next;
                                            }
                                            curr->next=temp;
                                            temp->prev=curr;
                                 }
                      }
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
           int data;
           cin>>data;
           insert_in_sorted_likedlist(data,n);
           print(head);
           return 0;
}
