#include<bits/stdc++.h>
using namespace std;
int main()
{
    string T;
    cin>>T;
    deque<char>d;
    for(int i=0;i<T.size();i++)
    {
        d.push_back(T[i]);

    }
    for(int i=0;i<T.size()/2;i++)
    {
        if(d.front()==d.back())
        {
            d.pop_back();
            d.pop_front();
        }
    }
    if(d.size()==1)
        cout<<"Yes\n";
    else
        cout<<"No\n";
    return 0;
}
