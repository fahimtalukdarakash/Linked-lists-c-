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
void Delete(int pos)
{
           Node* cur=head;
           if(pos==1)
           {
                      head=cur->next;
                      delete cur;
           }
           else
           {
                      int i=1;
                      while(i<pos-1)
                      {
                                 cur=cur->next;
                                 i++;
                      }
                      Node* temp=cur->next;
                      cur->next=temp->next;
                      delete temp;
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
           head=NULL;
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
            int pos;
            cin>>pos;
            Delete(pos);
            print(head);
            return 0;
}
