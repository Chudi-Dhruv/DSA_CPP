#include <bits/stdc++.h>
#include <stack> 
bool findRedundantBrackets(string &s)
{
    stack<int> st;
    for (int i=0;i<s.size();i++){
        if(s[i]=='('||s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            int count =0;
            while(!st.empty()&&st.top()!='('){
                char ch = st.top();
                if(ch=='+'||ch=='-'||ch=='*'||ch=='/') count++;
                st.pop();
            }
            st.pop();
            if (count==0) return true;
        }

    }
    return false;
}
