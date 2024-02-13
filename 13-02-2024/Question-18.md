# Maximum Subarray Sum
**Link** : https://leetcode.com/problems/maximum-subarray/description/, https://www.codingninjas.com/studio/problems/630526?topList=striver-sde-sheet-problems 
## Problem Statement

Given an integer array `nums`, find the subarray with the largest sum, and return its sum.

**Examples:**

**Example 1:**
```
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.
```

**Example 2:**
```
Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.
```

**Example 3:**
```
Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
```

**Constraints:**
- 1 <= nums.length <= 105
- -104 <= nums[i] <= 104

**Follow up:** If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

---

## Approach 1: Kadane's Algorithm (Dynamic Programming)

The Kadane's algorithm is a simple and efficient approach to find the maximum subarray sum. It iterates through the array while maintaining two variables: `current_sum` and `max_sum`. At each step, it updates the `current_sum` by adding the current element or starting a new subarray if the sum becomes negative. It also updates the `max_sum` to keep track of the maximum subarray sum encountered so far.

### C++ Code:

```cpp
#include <vector>
#include <algorithm>

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int current_sum = nums[0];
        int max_sum = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            current_sum = max(nums[i], current_sum + nums[i]);
            max_sum = max(max_sum, current_sum);
        }

        return max_sum;
    }
};
```

This approach has a time complexity of O(n), where n is the size of the input array.

---

## Approach 2: Divide and Conquer

The divide and conquer approach involves splitting the array into two halves and recursively finding the maximum subarray sum in each half. The maximum subarray sum can either be entirely in the left half, entirely in the right half, or crossing the midpoint. The result is the maximum of these three possibilities.

### C++ Code:

```cpp
#include <vector>
#include <algorithm>

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return divideAndConquer(nums, 0, nums.size() - 1);
    }

    int divideAndConquer(vector<int>& nums, int left, int right) {
        if (left == right) {
            return nums[left];
        }

        int mid = left + (right - left) / 2;

        // Find the maximum subarray sum in the left and right halves
        int leftMax = divideAndConquer(nums, left, mid);
        int rightMax = divideAndConquer(nums, mid + 1, right);

        // Find the maximum subarray sum crossing the midpoint
        int leftCrossMax = INT_MIN;
        int leftCrossSum = 0;
        for (int i = mid; i >= left; --i) {
            leftCrossSum += nums[i];
            leftCrossMax = max(leftCrossMax, leftCrossSum);
        }

        int rightCrossMax = INT_MIN;
        int rightCrossSum = 0;
        for (int i = mid + 1; i <= right; ++i) {
            rightCrossSum += nums[i];
            rightCrossMax = max(rightCrossMax, rightCrossSum);
        }

        // Return the maximum of the three possibilities
        return max({leftMax, rightMax, leftCrossMax + rightCrossMax});
    }
};
```

This approach has a time complexity of O(n log n) due to the recursive nature of the divide and conquer algorithm. It is more subtle but may be less efficient than Kadane's algorithm for large arrays.

---

Choose the approach that best fits your needs and the constraints of the problem. The Kadane's algorithm is a widely used and efficient solution for this problem.