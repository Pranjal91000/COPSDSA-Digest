### Problem Statement:

Given an array `nums`, determine whether it was originally sorted in non-decreasing order and then rotated some number of positions (including zero). There may be duplicates in the original array.

**Link**:https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/ , https://www.codingninjas.com/studio/problems/ninja-and-the-sorted-check_6581957

### Explanation:

An array A rotated by x positions results in an array B of the same length such that A[i] == B[(i+x) % A.length], where % is the modulo operation.

### Examples:

1. **Example 1:**
   - Input: `nums = [3,4,5,1,2]`
   - Output: `true`
   - Explanation: `[1,2,3,4,5]` is the original sorted array. You can rotate the array by x = 3 positions to begin on the element of value 3: `[3,4,5,1,2]`.

2. **Example 2:**
   - Input: `nums = [2,1,3,4]`
   - Output: `false`
   - Explanation: There is no sorted array once rotated that can make `nums`.

3. **Example 3:**
   - Input: `nums = [1,2,3]`
   - Output: `true`
   - Explanation: `[1,2,3]` is the original sorted array. You can rotate the array by x = 0 positions (i.e., no rotation) to make `nums`.

### Brute Force Solution:

The brute force approach would be to check every possible rotation and see if it forms a sorted array. We can do this by rotating the array and then checking if it's sorted.

**Brute Force Code (C++):**
```cpp
#include <vector>

class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            bool sorted = true;
            for (int j = 1; j < n; ++j) {
                if (nums[(i + j) % n] < nums[(i + j - 1) % n]) {
                    sorted = false;
                    break;
                }
            }
            if (sorted) return true;
        }
        return false;
    }
};
```

**Time Complexity:**
- The time complexity of this solution is O(n^2), where n is the length of the array.

### Better Solution:

A better solution involves finding the index of the smallest element in the array. If the array is rotated, this index will give us the number of rotations. We can then check if the array becomes sorted after rotation.

**Better Solution Code (C++):**
```cpp
#include <vector>

class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int rotations = 0;

        // Find the index of the smallest element
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] > nums[i + 1]) {
                rotations = i + 1;
                break;
            }
        }

        // Rotate the array based on the found index
        reverse(nums.begin(), nums.begin() + rotations);
        reverse(nums.begin() + rotations, nums.end());
        reverse(nums.begin(), nums.end());

        // Check if the array is sorted
        for (int i = 1; i < n; ++i) {
            if (nums[i] < nums[i - 1]) {
                return false;
            }
        }

        return true;
    }
};
```

**Time Complexity:**
- The time complexity of this solution is O(n), where n is the length of the array.

### Optimal Solution:

An optimal solution involves observing that the original array was non-decreasing. Thus, the smallest element in the rotated array will be less than or equal to the first element of the original array. We can use this insight to simplify the solution.

**Optimal Solution Code (C++):**
```cpp
#include <vector>

class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int smallestIndex = 0;

        // Find the index of the smallest element
        for (int i = 1; i < n; ++i) {
            if (nums[i] < nums[smallestIndex]) {
                smallestIndex = i;
            }
        }

        // Check if the array is sorted
        for (int i = 0; i < n; ++i) {
            int index = (smallestIndex + i) % n;
            if (nums[index] != nums[(index + 1) % n] && nums[index] > nums[(index + 1) % n]) {
                return false;
            }
        }

        return true;
    }
};
```

**Time Complexity:**
- The time complexity of this solution is O(n), where n is the length of the array.

### DSA Digest:

**Title:** Determining Rotated Sorted Array

**Introduction:**
In this DSA Digest, we unravel the challenge of determining whether an array was originally sorted in non-decreasing order and then rotated some number of positions. We explore different solutions, providing clear explanations and code snippets in C++.

**Brute Force Solution:**
The brute force solution involves checking every possible rotation of the array to see if it forms a sorted array. We present the C++ code and discuss its time complexity.

**Better Solution:**
A more efficient solution is introduced, leveraging the index of the smallest element to determine the number of rotations needed. The code is provided in C++, and its time complexity is explained.

**Optimal Solution:**
An optimal solution is presented, recognizing that the smallest element in the rotated array will be less than or equal to the first element of the original array. The C++ code is shared, along with insights into its time complexity.

**Conclusion:**
By examining different approaches, we enhance our understanding of the problem and discover more efficient solutions. The DSA Digest serves as a valuable resource for mastering algorithms and data structures.