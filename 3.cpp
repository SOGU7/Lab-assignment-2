#include<bits/stdc++.h>
using namespace std;
int prec(char c)
{
    if(c=='^')
        return 3;
    else if(c=='*'||c=='/')
        return 2;
    else if(c=='+'||c=='-')
        return 1;
    else
        return -1;
}

int main()
{
    string T;
    cin>>T;
    stack<char>s;
    string ans;
    for(int i=0; i<T.size(); i++)
    {
        char ch= T[i];
        if((T[i]>='a'&&T[i]<='z')||(T[i]>='A'&&ch<='Z')||(T[i]>='0'&&T[i]<='9'))
            ans+=ch;
        else if(ch=='(')
            s.push('(');
        else if(ch==')')
        {
            while(s.top()!='(')
            {
                ans+=s.top();
                s.pop();
            }
            s.pop();
        }
        else
        {
            while(s.size()&&prec(ch)<=prec(s.top()))
            {
                ans+=s.top();
                s.pop();
            }
            s.push(ch);
        }
    }
    while(s.size())
    {
        ans+=s.top();
        s.pop();
    }
    cout<<ans<<"\n";
    return 0;
}
