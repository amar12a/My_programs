#include <iostream>
#include<stdlib.h>
using namespace std;
struct node
{
    int value;
    node * next;
} * f=0,*r=0;
void enqueue(int val)
{
    //creating node using malloc function
    struct node *s=(struct node *)malloc(sizeof(node));
    s->next=0;
    s->value=val;
    if(f==0)
    {
        f=s;
        r=s;
    }
    else
    {
        r->next=s;
        r=s;

    }
    cout<<"Insertion is successful"<<endl;

}
void dequeue()
{struct node * temp;
    if(f==0)
        cout<<"No element in queue to dequeue";
    else
    {
        if(f->next==NULL)
        {
            temp=f;
            cout<<"Deleted element is:"<<temp->value<<endl;
            f=0;
            r=0;
            free(temp);

        }
        else
        {

            temp=f;
            cout<<"Deleted element:"<<temp->value;
            f=f->next;
            free(temp);
        }

    }

}
int is_Empty()
{
    if(f==0 && r==0)
        return 1;
    else
        return 0;
}
void display()
{

    if(f==0)
    {
        cout<<"No element to delete"<<endl;
    }
    else
    {struct node * temp=f;
        while(temp->next!=NULL)
        {
            cout<<temp->value<<"--";
            temp=temp->next;
        }
        cout<<temp->value;
        cout<<endl;
    }

}
int main()
{
    int ch=0,val;
    while(1)
    {
        cout<<"1.Enqueue"<<endl;
        cout<<"2.Dequeue"<<endl;
        cout<<"3.Is_EMPTY"<<endl;
        cout<<"4.Display"<<endl;
        cout<<"5.Exit"<<endl<<endl;
        cout<<"Enter Your choice :";
        cin>>ch;
        cout<<endl;
        switch(ch)
        {
            case 1:
                {cout<<"Enter the value you want to insert in a queue :";
                    cin>>val;cout<<endl;
                    enqueue(val);
                    break;
                }
            case 2:
                {
                    dequeue();
                    break;
                }
            case 3:
                {
                  int temp=is_Empty();
                    if(temp==1)
                        cout<<"Queue is empty";
                    else
                        cout<<"Queue is Not empty";
                    break;
                }
            case 4:
                {
                  display();
                    break;
                }
            case 5:exit(0);
            default:cout<<"Wrong Selection, Please try again later"; break;

        }
        cout<<endl;

    }

    return 1;
}
