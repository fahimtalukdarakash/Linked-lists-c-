#include<iostream>
using namespace std;
struct Node{
           int data;
           Node* next;
};
Node* insert(Node* head, int x)
{
           Node* temp= new Node();
           temp->data=x;
           temp->next=head;
           head=temp;
           return head;
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
            for(i=0;i<n;i++)
            {
                       cout<<"Enter the number"<<endl;
                       cin>>x;
                       head=insert(head, x);
                       print(head);
            }
}
