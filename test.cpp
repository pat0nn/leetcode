#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>

using namespace std;


int main() {
    unordered_map<int , int> s1;
    s1[1] = 1;
    s1[2] = 2;

    unordered_map<int , int> s2(s1);
    s2.erase(1);

    for (auto &&i : s1)
    {
        cout<<i.first<<" ";
    }
    
}