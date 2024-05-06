#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;

int trap(std::vector<int>& height) {
    int n = height.size();
    if (n < 3) // Need at least three walls to trap water
        return 0;

    int first_wall = 0, last_wall = n - 1;
    std::vector<std::vector<int>> blocks;
    int result = 0;

    while (first_wall < n - 1 && height[first_wall] <= height[first_wall + 1]) {
        first_wall++;
    }

    while (last_wall > 0 && height[last_wall] <= height[last_wall - 1]) {
        last_wall--;
    }

    // Trapping water between two non-decreasing walls
    while (first_wall < last_wall) {
        int temp_wall = first_wall + 1;

        std::vector<int> temp_block;
        temp_block.push_back(height[first_wall]);
        while (temp_wall < last_wall && height[temp_wall] < height[first_wall]) {
            temp_block.push_back(height[temp_wall]);
            temp_wall++;
        }
        


        first_wall = temp_wall;
        if(height[first_wall] == height[first_wall+1]){
            first_wall++;
        }

        blocks.push_back(temp_block);
    }


    for (auto &&i : blocks)
    {
        for (auto &&it : i)
        {
            cout<<it<<" ";
        }
        cout<<endl;
        
    }
    

    // Calculating the trapped water
    for (auto& i : blocks) {
        if (i.size() >= 2) {
            int left = i[0];
            int right = i[i.size() - 1];
            int selected_wall = std::min(left, right);
            for (auto& it : i) {
                if (selected_wall > it) {
                    
                    result += selected_wall - it;
                }
            }
            cout<<endl;
        }
    }
    return result;
}
//[50,51,52,53,54,55,58,59,60,62,63,66,67,68,69,70,71,73,74,77,80,82,83,84,86,89,90,92,94,97,100,103,104,107,108,109,110,112,113,114,115,118,121,124,127,128,131,134,135,137,138,139,140,141,142,144,146,147,148,149,152,153,155,156,157,159,160,161,163,165,167,170,173,176,177,179,180,182,184,185,186,188,190,192,193,195,196,199,201,202,203,204,206,208,210,213,216,217,218,220,222]

int trap2(std::vector<int>& height) {
    int n = height.size();
    if (n < 3) // Cần ít nhất ba tường để giữ nước
        return 0;

    int first_wall = 0, last_wall = n - 1;
    std::vector<std::vector<int>> blocks;
    int result = 0;

    // Tìm tường đầu tiên không giảm từ trái qua phải
    while (first_wall < n - 1 && height[first_wall] <= height[first_wall + 1]) {
        first_wall++;
    }

    // Tìm tường đầu tiên không giảm từ phải qua trái
    while (last_wall > 0 && height[last_wall] <= height[last_wall - 1]) {
        last_wall--;
    }

    while (first_wall < last_wall) {
        int temp_wall = first_wall + 1;

        std::vector<int> temp_block;
        temp_block.push_back(height[first_wall]);
        while (temp_wall < last_wall && height[temp_wall] < height[first_wall]) {
            temp_block.push_back(height[temp_wall]);
            temp_wall++;
        }
        if (temp_wall < n)
            temp_block.push_back(height[temp_wall]);

        first_wall = temp_wall;

        blocks.push_back(temp_block);
    }

    // Tính lượng nước giữa các tường
    for (auto& i : blocks) {
        if (i.size() >= 2) {
            int left = i[0];
            int right = i[i.size() - 1];
            int selected_wall = std::min(left, right);
            for (auto& it : i) {
                if (selected_wall > it) {
                    result += selected_wall - it;
                }
            }
        }
    }
    return result;
}


int trap3(std::vector<int>& height) {
    if (height.size() < 3) // Need at least three walls to trap water
        return 0;

    int left = 0, right = height.size() - 1;
    int max_left = 0, max_right = 0;
    int water = 0;

    while(left < right){
        if(height[left] < height[right]){
            if(height[left] >= max_left){
                max_left = height[left];
            }else {
                water += max_left - height[left];
            }
            left++;
        }
        else{
            if(height[right] >= max_right){
                max_right = height[right];
            }else{
                water+= max_right - height[right];
            }
            right--;

        }
    }
    return water;
}

int main() {
    vector<int> height = {
9,6,8,8,5,6,3
};
cout<<trap3(height);

}
    
    
