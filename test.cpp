#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int trap(vector<int>& height) {
    vector<vector<int>> blocks;
    int result = 0;
    int i = 0;
    int last = height.size()-1;
    while (height[last] < height[last-1])
    {
        last--;
    }
    cout<<"Last: "<<last<<endl;
    while(i<last){
        
        if(i==0){
            i++;
        }else {
            cout<<"LOOP: "<<i<<endl;
        
            cout<<"i: "<<i<<endl;
            int j = i+1;
            while(height[j] < height[i]){
                cout<<"height[i]" << height[i]<<endl;
                cout<<"height[j]" << height[j]<<endl;
                result+= height[i]-height[j];
                cout<<"result"<<result<<endl;
                j++;
            }
        }
        cout<<"======================="<<endl;
        i++;
    }
    return result;


            
}

int main(){
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<trap(height)<<endl;
}