# Deep Dive DSA Digest: Two Sum Problem
**Link**: https://leetcode.com/problems/two-sum/description , https://www.codingninjas.com/studio/problems/reading_6845742
## Problem Statement

Given an array of integers `nums` and an integer `target`, return indices of the two numbers such that they add up to `target`.

You may assume that each input would have exactly one solution, and you may not use the same element twice. You can return the answer in any order.

**Example 1:**

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

**Example 2:**

Input: nums = [3,2,4], target = 6
Output: [1,2]

**Example 3:**

Input: nums = [3,3], target = 6
Output: [0,1]

**Constraints:**

- 2 <= nums.length <= 10^4
- -10^9 <= nums[i] <= 10^9
- -10^9 <= target <= 10^9
- Only one valid answer exists.

**Follow-up:**

Can you come up with an algorithm that is less than O(n^2) time complexity?

## Approaches

### 1. Brute Force Approach

The brute force approach involves checking every pair of elements in the array to see if their sum equals the target. This can be done using nested loops.

#### C++ Code:

```cpp
#include <vector>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {}; // No solution found
    }
};
```

#### Time Complexity: O(n^2)

#### Space Complexity: O(1)

### 2. Two-Pass Hash Table Approach

Use a hash table to store the indices of elements. In the first pass, store each element's index. In the second pass, check if the complement (target - current element) exists in the hash table.

#### C++ Code:

```cpp
#include <unordered_map>
#include <vector>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> hashTable;
        
        // First pass: Store each element's index in the hash table
        for (int i = 0; i < nums.size(); ++i) {
            hashTable[nums[i]] = i;
        }
        
        // Second pass: Check if complement exists in the hash table
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            if (hashTable.find(complement) != hashTable.end() && hashTable[complement] != i) {
                return {i, hashTable[complement]};
            }
        }
        
        return {}; // No solution found
    }
};
```

#### Time Complexity: O(n)

#### Space Complexity: O(n)

### 3. One-Pass Hash Table Approach

Combine the two passes of the previous approach into a single pass. While iterating through the array, check if the complement of the current element exists in the hash table.

#### C++ Code:

```cpp
#include <unordered_map>
#include <vector>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> hashTable;
        
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            
            if (hashTable.find(complement) != hashTable.end()) {
                return {hashTable[complement], i};
            }
            
            hashTable[nums[i]] = i;
        }
        
        return {}; // No solution found
    }
};
```

#### Time Complexity: O(n)

#### Space Complexity: O(n)

## Conclusion

The Two Sum problem can be solved using various approaches. The brute force approach is simple but has higher time complexity. The hash table approaches provide more efficient solutions with O(n) time complexity, especially the one-pass hash table approach. Depending on the constraints and requirements, the appropriate approach can be chosen.