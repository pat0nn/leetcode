

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int i = 0, j=0;
    int  n = nums1.size(), m = nums2.size();
    
    nums1.insert(nums1.end(), nums2.begin(), nums2.end());
    sort(nums1.begin(), nums1.end());
    for (auto &&i : nums1)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    
    float median = 0;
    if((m+n) % 2 != 0 ){
        median = nums1[int((m+n)/2)];
    }else {
        median = (nums1[(m+n)/2 - 1] + nums1[(m+n)/2])*1.0 /2 ;
    }
    return median;
}


int main() {
    vector<int> nums1 = {1,3};
    vector<int> nums2 = {2,4};
    cout<<findMedianSortedArrays(nums1, nums2);

}

// 7 0 1 2 3 4 5 6