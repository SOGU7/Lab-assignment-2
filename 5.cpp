#include<bits/stdc++.h>
using namespace std;
template<class T>
class node
{
public:
    T data;
    node *prv,*nxt;
};
template<class T>
class  Deque
{
public:
    node<T> *head,*tail;
    int sz;

    Deque()
    {
        head=NULL;
        tail=NULL;
        sz=0;
    }
    node<T> *create_new_node(T value)
    {
        node<T> *tmp = new node<T>;
        tmp->data=value;
        tmp->prv=NULL;
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
        tmp->prv=tail;
        tail=tmp;
        sz++;
    }
    void PushFront(T value)
    {
        node<T> *tmp = create_new_node(value);
        if(sz==0)
        {
            head=tmp;
            tail=tmp;
            sz++;
            return;
        }
        head->prv=tmp;
        tmp->nxt=head;
        head=tmp;
        sz++;
    }
    void PopBack()
    {
        if(sz==0)
        {
            cout<<"Deque is empty\n";
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
        node<T> *tmp=tail;
        tail = tmp->prv;
        delete tmp;
        tail->nxt=NULL;
        sz--;
    }
    void PopFront()
    {
        if(sz==0)
        {
            cout<<"Deque is empty\n";
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
        head = tmp->nxt;
        delete tmp;
        head->prv=NULL;
        sz--;
    }
    T front()
    {
        if(sz==0)
        {
            cout<<"Deque is empty\n";
            return -1;
        }
        return head->data;
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
    Deque<int> d;
    d.PushBack(20);
    d.PushBack(30);
    d.PushBack(40);
    d.PushBack(50);

    d.PushFront(100);


    cout<<"Front = "<<d.front()<<" Back = "<<d.back()<<"\n";

    d.PopBack();

    cout<<"Front = "<<d.front()<<" Back = "<<d.back()<<"\n";

    d.PopFront();

    cout<<"Front = "<<d.front()<<" Back = "<<d.back()<<"\n";

    Deque<char> d1;
    d1.PushBack('a');
    d1.PushBack('b');
    d1.PushBack('c');
    d1.PushBack('d');

    d1.PushFront('e');


    cout<<"Front = "<<d1.front()<<" Back = "<<d1.back()<<"\n";

    d1.PopBack();

    cout<<"Front = "<<d1.front()<<" Back = "<<d1.back()<<"\n";

    d1.PopFront();

    cout<<"Front = "<<d1.front()<<" Back = "<<d1.back()<<"\n";


    return 0;
}
