#include "ll.h"

void insertNode(node *&head, int index, int data)
{
    node* newNode=new node;
    newNode->data=data;
    newNode->next=nullptr;

    if(index==0)
    {
        newNode->next=head;
        head=newNode;
    }
    else
    {
        node* walker=head;
        int wIndex = 0;
        while(walker != NULL && wIndex < index -1)
        {
            walker = walker->next;
            wIndex++;
        }
        if(walker == nullptr)
        {
            cout<<"Index is too large, cant insert."<<endl;
            return;
        }
        else
        {
            newNode->next=walker->next;
            walker->next=newNode;
        }
    }
}
void deleteNode(node *&head, int index)
{
    if(head==nullptr) //if list is empty cant delete something thats not there
    {
        cout<<"List is empty, can't delete"<<endl;
        return;
    }
    if(index==0)//if deleting first node
    {
        node *temp=head;
        head=head->next;
        delete temp;
    }
    else//if not deleting first node need to go through the data until we get to the correct node
    {
        node *walker=head;
        int wIndex=0;
        while(walker != nullptr && wIndex<index - 1)//looking through the data
        {
            walker=walker->next;
            wIndex++;
        }
        if(walker==nullptr||walker->next==nullptr)
        {
            cout<<"Index is too large, can't delete"<<endl;
            return;
        }
        else//deleting the correct node
        {
            node *temp = walker->next;
            walker->next=temp->next;
            delete temp;
        }
    }
}
void displayList(node *&head)
{
    node* walker = head;

    while(walker != nullptr)
    {
        cout<<walker->data<<" ";
        walker = walker->next;
    }
    cout<<endl;
}
void reverseList(node *&head)
{
    node* prev = nullptr;//keeps track of previous node
    node* current = head;//tracks the current node
    node* next = nullptr;//next node in the line to reverse

    while (current != nullptr)//reversing the list
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    head=prev;
}
node* searchNode(node *&head, int key)
{
    node* walker=head;
    while (walker !=nullptr && walker->data != key)
    {
        walker=walker->next;
    }
    if(walker == nullptr)
    {
        cout<<key<<" Not found"<<endl;
        return nullptr;
    }
    else
    {
        return walker;
    }
}

