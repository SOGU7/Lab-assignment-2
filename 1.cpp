#include<bits/stdc++.h>
using namespace std;
template<class T>
class Queue
{
public:
    T *a;
    int array_cap;
    int l,r;
    int sz;

    Queue()
    {
        a = new T[1];
        array_cap =1;
        l=0;
        r=-1;
        sz=0;
    }
    void increase_size()
    {
        T *tmp = new T[array_cap*2];
        for(int i =0;i<array_cap;i++)
        {
            tmp[i]=a[i];
        }
        swap(tmp,a);
        delete []tmp;
        array_cap*=2;
    }
    void enqueue(T value)
    {
        if(sz==array_cap)
        {
            increase_size();
        }
        r++;
        a[r]=value;
        sz++;
    }
    void dequeue()
    {
        if(sz==0)
        {
            cout<<"Underflow\n";
            return;
        }
        l++;
    }
    T front()
    {
        if(sz==0)
        {
            cout<<"Queue is empty\n";
            return -1;
        }
        return a[l];
    }
};

int main()
{
    Queue<int> q;
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);

    cout<<q.front()<<"\n";
    q.dequeue();
    cout<<q.front()<<"\n";
    q.dequeue();
    cout<<q.front()<<"\n";
    q.dequeue();

    Queue<char> q1;
    q1.enqueue('a');
    q1.enqueue('b');
    q1.enqueue('c');

    cout<<q1.front()<<"\n";
    q1.dequeue();
    cout<<q1.front()<<"\n";
    q1.dequeue();
    cout<<q1.front()<<"\n";
    q1.dequeue();

    return 0;
}
