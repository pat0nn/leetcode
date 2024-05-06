#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;


vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    

    int i = 0;
    while(i < nums.size()-3){
        if(nums[i] == nums[i+1]){
            i++;
        }
        
        int j = nums.size();

        unordered_map<int , int> temp_twoSum;
        while (j > i){
            if(nums[j] > nums[i] * 2){
                j--;
            } else {
                int check = 0 - nums[i] - nums[j];
                if(temp_twoSum.count(check)){
                    result.push_back({nums[i], nums[j], check});
                    j--;
                }else{
                    temp_twoSum[nums[j]] = j;
                    j--;
                }
            }
        }
        temp_twoSum.clear();
        i++;

    } 
    return result;
}





int main() {

    vector<int> nums = { -1,0,1,2,-1,-4 };
    vector<vector<int>> result = threeSum(nums);

    for (auto &&it : result)
    {
        for(int i=0; i<it.size(); i++){
            cout<<it[i]<<" ";
        }
        cout<<endl;
        
    }
    


}