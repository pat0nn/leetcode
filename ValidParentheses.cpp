#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

// (([{}]){})

bool isValid(string s) {
    if(s[0] == '}' || s[0] == ')' || s[0] == ']')
        return false;
    stack<char> st;
    unordered_map<char,char> parentheses;
    parentheses['}'] = '{';
    parentheses[')'] = '(';
    parentheses[']'] = '[';
    for (auto &&chr : s)
    {
        if( chr == '{' || chr == '(' || chr == '['){
            st.push(chr);
        }else{
            if(!st.empty() && st.top() == parentheses[chr]){
                st.pop();
            } else {
                return false;
            }
        }
    }
    
    return st.empty();
         
}

int main(){
    string s = "(){}}{";
    cout<<isValid(s)<<endl;
}