#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int search(vector<int>& nums, int target) {
    int left, right;
    int n = nums.size();

    if( n>2 && nums[n/2 ] > nums[n/2 +1] ){
        if(target < nums[0] ){
        left = nums.size()/2;
        right = nums.size()-1;
        }else if(target > nums[0]){
            left = 0;
            right = nums.size()/2;
        }
        else{ 
            return 0;
        }
    }else{
        
        for(int i = 0; i<n; i++){
            if(nums[i] == target){
                return i;
            }
        }
    }

    
    while(left <= right){
        int mid = left + (right-left)/2;
        if(nums[mid] == target){
            return mid;
        }else if(nums[mid] > target){
            right = mid -1;
        }else if(nums[mid] < target){
            left = mid +1;
        }
    }
    return -1;
}

int main(){
    vector<int> nums = {1};
    cout<<search(nums, 0);
}



class Solution {
public:
    int search(vector<int>& nums, int target) {
        int ans = 0;

        int l = 0, r = nums.size() - 1;
        while(l <= r)
        {
            int mid = (r-l)/2 + l;
            if (nums[mid] == target) return mid;

            if (nums[l] <= nums[mid])
            {
                if (nums[l] <= target && target <= nums[mid]){
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }
            else
            {
                if (nums[mid] <= target && target <= nums[r])
                {
                    l = mid + 1;
                }
                else
                {
                    r = mid - 1;
                }
            }
        }

        return -1;
    }
};