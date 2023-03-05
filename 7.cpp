#include <bits/stdc++.h>
using namespace std;

void print(list<int>l)
{
    auto a = l.begin();
    while(a!=l.end())
    {
        cout<<*a<<" ";
        a++;
    }
    cout<<"\n";
}
void deleteValue(list<int>&l,int value)
{
    auto it = l.begin();
    while(*it!=value)
    {
        it++;
    }
    l.erase(it);

}
int main()
{
    list<int> l;
    l.push_back(7);
    l.push_back(3);
    l.push_back(8);

    print(l);
    l.push_back(4);
    l.push_back(5);
    l.push_back(4);

    print(l);

    deleteValue(l,4);
    print(l);


    return 0;
}

