#include <iostream>
#include <vector>

using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int left = 0, right = matrix.size()-1;
    int mid = 0;
    int index = 0;

    if(right+1 > 1)
    while(left <= right){
        mid = left + (right -left)/2;
        if(target >= matrix[mid].front() && target <= matrix[mid].back()){
            index = mid;
            break;
        }else if (target <= matrix[mid].front()){
            right = mid -1;
        }else if (target >= matrix[mid].back()){
            left = mid + 1;
        }
    }

    left = 0, right = matrix[mid].size()-1;
    if(right+1 > 1){
        while(left <= right){
            mid = left + (right -left)/2;
            if(matrix[index][mid] == target){
                return true;
            }else if(target < matrix[index][mid]){
                right = mid - 1;
            } else if(target > matrix[index][mid]){
                left = mid + 1;
            }
        }
    }else if(matrix[index][0] == target){
        return true;
    }
    return false;
}

int main() {
    vector<vector<int>> matrix = {{1},{3}};
    cout<< searchMatrix(matrix, 3);
}