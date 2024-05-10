#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int largestRectangleArea(vector<int>& heights) {
    stack<int> st;
    st.push(heights[0]);
    for(int i=1; i<heights.size(); i++){
        int j = i+1;
        int temp = heights[i];
        while(heights[j] >= heights[i] && j<heights.size()){
            temp += heights[i];
            j++;
        }
        if(temp > st.top()){
            st.push(temp);
        }else if(heights[i] > st.top()){
            st.push(heights[i]);
        }
    }
    return st.top();
}

int main() {
    vector<int> heights = {2,1,2};
    cout<<largestRectangleArea(heights);
}