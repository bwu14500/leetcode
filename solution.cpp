#include <iostream>
#include <vector>

using namespace std;

// 1. Two Sum
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

// 7. Reverse Integer
// 9. Palindrome Number
// 13. Roman to Integer
// 14. Longest Common Prefix
// 20. Valid Parentheses
// 21. Merge Two Sorted Lists
// 26. Remove Duplicates from Sorted Array
// 27. Remove Element
// 36. Valid Sudoku
// 88. Merge Sorted Array
// 121. Best Time to Buy and Sell Stock
// 200. Number of Islands
// 217. Contains Duplicate
// 238. Product of Array Except Self
// 283. Move Zeroes
// 485. Max Consecutive Ones
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
// 905. Sort Array By Parity
// 941. Valid Mountain Array
// 977. Squares of a Sorted Array
vector<int> sortedSquares(vector<int>& nums) {
    vector<int> result(nums.size());
    int left = 0;
    int right = nums.size()-1;
    int n = nums.size()-1;
    while (left <= right) {
        int lsquare = nums[left]*nums[left];
        int rsquare = nums[right]*nums[right];
        if (lsquare > rsquare) {
            result[n] = lsquare;
            ++left;
        }
        else {
            result[n] = rsquare;
            --right;
        }
        --n;
    }
    return result;
}
// 1051. Height Checker
int heightChecker(vector<int>& heights) {
    if (heights.size() < 2) {
        return 0;
    }
    vector<int> map(101, 0);
    for (int h:heights) {
        ++map[h];
    }
    int res = 0;
    int h_ptr = 1;
    for (int h:heights) {
        while (map[h_ptr] == 0) {
            ++h_ptr;
        }
        if (h_ptr != h) {
            res++;
        }
        map[h_ptr]--;
    }
    return res;
}
// 1089. Duplicate Zeros
void duplicateZeros(vector<int>& arr) {
    int i = 0;
    int n = arr.size();
    while (i < n) {
        if (arr[i] == 0) {
            arr.insert(arr.begin()+i, 0);
            i += 2;
        }
        else {
            i++;
        }
    }
    arr.resize(n);
}
// 1295. Find Numbers with Even Number of Digits
// 1299. Replace Elements with Greatest Element on Right Side
// 1346. Check If N and Its Double Exist
// 1381. Design a Stack With Increment Operation
// 1456. Maximum Number of Vowels in a Substring of Given Length
bool isVowel(char ch) {
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

int maxVowels(string s, int k) {
    int res = 0;
    for (int i = 0; i < k; i++) {
        res += isVowel(s[i]);
    }
    int count = res;
    for (int i = k; i < s.length(); i++) {
        count += isVowel(s[i]);
        count -= isVowel(s[i-k]);
        if (count > res) {
            res = count;
        }
    }
    return res;
}







