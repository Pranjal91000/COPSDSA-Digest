# Sorting Colors
**Link**: https://leetcode.com/problems/sort-colors/description/, https://codingninjas.com/studio/problems/sort-an-array-of-0s-1s-and-2s_892977
## Problem Statement

Given an array `nums` with `n` objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the colors red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

## Examples

### Example 1:

Input: `nums = [2,0,2,1,1,0]`

Output: `[0,0,1,1,2,2]`

### Example 2:

Input: `nums = [2,0,1]`

Output: `[0,1,2]`

## Constraints:

- `n == nums.length`
- `1 <= n <= 300`
- `nums[i]` is either 0, 1, or 2.

## Follow-up:

Could you come up with a one-pass algorithm using only constant extra space?

## Approach 1: Counting Sort

**Explanation:**

Counting sort is a straightforward algorithm where we count the occurrences of each color (0, 1, 2) and then overwrite the array accordingly. This approach doesn't fulfill the follow-up constraint of using only constant extra space and might not be the most optimal.

**Algorithm Steps:**

1. Initialize an array `count` of size 3 to keep track of the count of each color.
2. Iterate through the input array `nums` and update the count of each color.
3. Iterate through the count array and update the input array `nums` based on the counts.

**C++ Code:**

```cpp
#include <vector>

void sortColors(std::vector<int>& nums) {
    int count[3] = {0};
    for (int num : nums) {
        count[num]++;
    }

    int index = 0;
    for (int i = 0; i < 3; i++) {
        while (count[i] > 0) {
            nums[index++] = i;
            count[i]--;
        }
    }
}
```

## Approach 2: Dutch National Flag Algorithm

**Explanation:**

The Dutch National Flag algorithm is a three-way partitioning scheme that separates the array into three parts: elements less than a pivot, elements equal to the pivot, and elements greater than the pivot.

**Algorithm Steps:**

1. Initialize three pointers - `low`, `high`, and `i`.
2. Iterate through the array using pointer `i`:
   - If `nums[i]` is 0, swap it with `nums[low]`, increment both `low` and `i`.
   - If `nums[i]` is 2, swap it with `nums[high]`, decrement `high`.
   - If `nums[i]` is 1, just increment `i`.
3. Continue these steps until `i` crosses `high`.

**C++ Code:**

```cpp
#include <vector>

void sortColors(std::vector<int>& nums) {
    int low = 0, high = nums.size() - 1, i = 0;

    while (i <= high) {
        if (nums[i] == 0) {
            std::swap(nums[i], nums[low]);
            low++;
            i++;
        } else if (nums[i] == 2) {
            std::swap(nums[i], nums[high]);
            high--;
        } else {
            i++;
        }
    }
}
```

Both approaches provide a solution to the problem, but the Dutch National Flag algorithm (Approach 2) achieves the sorting in-place and in a single pass with constant extra space, making it more efficient for this particular problem and fulfilling the follow-up constraint.