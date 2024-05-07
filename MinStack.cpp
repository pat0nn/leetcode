#include <iostream>
#include <vector>
using namespace std;

class MinStack {
    
    public:

        vector<pair<int, int>> items;
        MinStack() {
            
        }
        
        void push(int val) {
            if(items.empty()){
                items.push_back({val, val});
            }else {
                items.push_back({val, min(val, items.back().second)});
            }
        }
        
        void pop() {
            items.pop_back();
        }
        
        int top() {
            return items.back().first;
        }
        
        int getMin() {
            return items.back().second;
        }
};