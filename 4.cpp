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
string infixtopostfix(string T)
{
    stack<char>s;
    string ans;
    for(int i=0; i<T.size(); i++)
    {
        char ch= T[i];
        if(T[i]>='a'&&T[i]<='z'||(T[i]>='A'&&ch<='Z')||(T[i]>='0'&&T[i]<='9'))
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
    return ans;
}
void postfixResult(string T)
{
    stack<int>s;
    for(int i=0; i<T.size(); i++)
    {
        if(T[i]=='+')
        {
            int A=s.top();
            s.pop();
            int B=s.top();
            s.pop();
            int c=B+A;
            s.push(c);
        }
        else if(T[i]=='-')
        {
            int A=s.top();
            s.pop();
            int B=s.top();
            s.pop();
            int c=B-A;
            s.push(c);
        }
        else if(T[i]=='*')
        {
            int A=s.top();
            s.pop();
            int B=s.top();
            s.pop();
            int c=B*A;
            s.push(c);
        }
        else if(T[i]=='/')
        {
            int A=s.top();
            s.pop();
            int B=s.top();
            s.pop();
            int c=B/A;
            s.push(c);
        }
        else
        {
            int nn=T[i]-'0';
            s.push(nn);
        }
    }
    cout<<s.top()<<"\n";
}
int main()
{
    string T;
    cin>>T;
    string ans = infixtopostfix(T);
    postfixResult(ans);
    return 0;
}
