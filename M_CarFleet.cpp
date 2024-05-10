#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

float timeToMeet(double x1, double v1, double x2, double v2) {
    return (x2 - x1) / (v1 - v2);
}

int carFleet(int target, vector<int>& position, vector<int>& speed) {
    stack<pair<float, int>> st;


    st.push({position[0], speed[0]});
    for(int i=1; i<position.size(); i++){
        float position_meet = timeToMeet(position[i], speed[i], st.top().first, st.top().second) * speed[i] + position[i];
        if(position_meet >= 0 && position_meet <= target){
            int temp = st.top().second;
            st.pop();
            st.push({position_meet, min(temp, speed[i])});
        }else{
            st.push({position[i], speed[i]});
        }
    }
    return st.size();
}


int carFleet2(int target, vector<int>& position, vector<int>& speed) {
    stack<float> st;

     std::vector<std::pair<int, int>> cars;
    for (size_t i = 0; i < position.size(); ++i) {
        cars.push_back(std::make_pair(position[i], speed[i]));
    }

    // Sắp xếp các cặp theo vị trí xuất phát của các xe
    sort(cars.begin(), cars.end());


    for(int i=1; i<position.size(); i++){
        float time_meet = (target-cars[i].first)/cars[i].second;
        // float time_meet_stack = (target-st.top().first)/st.top().second;
        // if(time_meet >= time_meet_stack){
        //     st.push(cars[i]);
        // }else{
        //     while(!st.empty() && time_meet < time_meet_stack){
        //         st.pop();
        //         time_meet_stack = (target-st.top().first)/st.top().second;
        //         float position_meet = timeToMeet(position[i], speed[i], st.top().first, st.top().second) * st.top().second + st.top().first;
        //         if(position_meet<=target)
        //             st.push({position_meet, min(st.top().second, cars[i].second)});
                
        //         break;
        //     }
        // }
        for (auto &&car : cars)
        {
             float time_meet = (target-car.first)*1.0/car.second;
             while(!st.empty() && time_meet >= st.top()){
                st.pop();
             }
             st.push(time_meet);
        }
        


    }
    cout<<endl;
    return st.size();
}

int main(){
    int target = 31;
    vector<int> position = {5,26,18,25,29,21,22,12,19,6};
    vector<int> speed = {7,6,6,4,3,4,9,7,6,4};
    cout<<carFleet2(target, position, speed);
}