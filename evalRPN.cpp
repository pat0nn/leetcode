#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>


using namespace std;


int evalRPN(vector<string>& tokens) {

    stack<int> st;
    for (auto &&i : tokens)
    {
        if(i == "+"){
            int temp = st.top();
            st.pop();
            temp+= st.top();
            st.pop();
            st.push(temp);
        } else if(i == "-"){
            int temp = st.top();
            st.pop();
            temp = st.top() - temp;
            st.pop();
            st.push(temp);
        }else if(i == "*"){
            int temp = st.top();
            st.pop();
            temp*= st.top();
            st.pop();
            st.push(temp);
        }else if(i == "/"){
            int temp = st.top();
            st.pop();
            temp = st.top()/temp;
            st.pop();
            st.push(temp);
        }else{
            if(i!=""){
                st.push(stoi(i));
            }
            
        }
    }
    
    return st.top();
}

int main(){
    vector<string> tokens = {
"10","6","9","3","+","-11","","/","","17","+","5","+"

        };
    cout<<evalRPN(tokens)<<endl;
}

// ((9+3)/11)