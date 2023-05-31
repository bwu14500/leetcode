#include <iostream>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i+1; j < nums.size(); j++) {
            if (nums[i]+nums[j] == target) {
                return {i,j};
            }
        }
    }
    return {};
}

int findMaxConsecutiveOnes(vector<int>& nums) {
    int max = 0;
    int temp = 0;
    int check = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 1) {
            temp += 1;
            check = 1;
        }
        else {
            temp = 0;
            check = 0;
        }
        if (max < temp) {
            max = temp;
        }
    }
    return max;
}