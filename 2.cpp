
#include<bits/stdc++.h>
using namespace std;
template<class T>
class node
{
public:
    T data;
    node *nxt;
};
template<class T>
class  Stack
{
public:
    node <T> *head,*tail;
    int sz;

    Stack()
    {
        head=NULL;
        tail=NULL;
        sz=0;
    }
    node<T> *create_new_node(T value)
    {
        node<T> *tmp = new node<T>;
        tmp->data=value;
        tmp->nxt=NULL;
        return tmp;
    }
    void PushBack(T value)
    {
        node<T> *tmp = create_new_node(value);
        if(sz==0)
        {
            head=tmp;
            tail=tmp;
            sz++;
            return;
        }
        tail->nxt=tmp;
        tail=tmp;
        sz++;
    }

    void PopBack()
    {
        if(sz==0)
        {
            cout<<"Stack is empty\n";
            return;
        }
        if(sz==1)
        {
            delete tail;
            head=NULL;
            tail=NULL;
            sz--;
            return;
        }
        node<T> *tmp=head;
        while(tmp->nxt!=tail)
            tmp=tmp->nxt;
        node<T> *tmp2=tail;
        tail=tmp;
        delete tmp2;
        tail->nxt=NULL;
        sz--;
    }
    int Getsize()
    {
        return sz;
    }
    T back()
    {
        if(sz==0)
        {
            cout<<"Deque is empty\n";
            return -1;
        }
        return tail->data;
    }
};

int main()
{
    Stack <int>d;
    d.PushBack(20);
    d.PushBack(30);
    d.PushBack(40);
    d.PushBack(50);
    cout<<"Back = "<<d.back()<<"\n";
    d.PopBack();
    cout<<"Back = "<<d.back()<<"\n";

    cout<<"Size of Stack = "<<d.Getsize()<<"\n";
    Stack <char>d1;
    d1.PushBack('a');
    d1.PushBack('b');
    d1.PushBack('c');
    d1.PushBack('d');
    cout<<"Back = "<<d1.back()<<"\n";
    d1.PopBack();
    cout<<"Back = "<<d1.back()<<"\n";

    cout<<"Size of Stack = "<<d1.Getsize()<<"\n";
    return 0;
}
