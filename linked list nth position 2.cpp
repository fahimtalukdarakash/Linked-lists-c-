#include<iostream>
using namespace std;
struct Node{
           int data;
           Node* next;
};
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
void insert_data_at_position(Node* head,int data,int pos)
{
           Node* temp=new Node();
           temp->data=data;
           temp->next=NULL;
           Node* cur;
           cur=head;
           if(pos==0)
           {
                      temp->next=head;
                      head=temp;
           }
           else
           {
                      int i=0;
                      while(i<pos-1)
           {
                      cur=cur->next;
                      i++;
           }
           temp->next=cur->next;
           cur->next=temp;
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
           Node* head=NULL;
           cout<<"How many numbers?"<<endl;
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
            int data,pos;
            cin>>data>>pos;
            insert_data_at_position(head,data,pos);
            print(head);
            return 0;
}
