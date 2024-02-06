### Problem Statement:

You are given an integer array `nums` and a non-negative integer `k`. Rotate the array to the right by `k` steps.

LINK: https://leetcode.com/problems/rotate-array/description/, https://www.codingninjas.com/studio/problems/left-rotate-an-array-by-one_5026278

### Example:

**Example 1:**
```
Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
```

**Example 2:**
```
Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
```

### Constraints:
- `1 <= nums.length <= 105`
- `-231 <= nums[i] <= 231 - 1`
- `0 <= k <= 105`

### Problem Explanation:

You need to rotate an array to the right by `k` steps. This means that the last `k` elements of the array should be moved to the beginning.

### Brute Force Approach:

One simple approach is to perform the rotation step-by-step, moving the last element to the front one step at a time. You can do this by repeatedly shifting the elements of the array.

```cpp
void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n;  // In case k is greater than the array length
    
    for (int i = 0; i < k; ++i) {
        int temp = nums.back();
        nums.pop_back();
        nums.insert(nums.begin(), temp);
    }
}
```

This approach has a time complexity of O(k * n) since we perform the rotation step `k` times, and each rotation operation takes O(n) time.

### Better Approach:

A better approach is to use an auxiliary array to store the rotated values. Copy the last `k` elements to the auxiliary array, then shift the remaining elements to the right, and finally, copy the auxiliary array back to the beginning of the original array.

```cpp
void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n;  // In case k is greater than the array length
    
    vector<int> aux(nums.end() - k, nums.end());
    nums.erase(nums.end() - k, nums.end());
    nums.insert(nums.begin(), aux.begin(), aux.end());
}
```

This approach has a time complexity of O(n) as we perform three array operations (copying, erasing, and inserting), each taking O(n) time.

### Optimal Approach:

The optimal approach involves reversing portions of the array. Reverse the entire array, then reverse the first `k` elements, and finally, reverse the remaining `n - k` elements.

```cpp
void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n;  // In case k is greater than the array length
    
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
}
```

This approach has a time complexity of O(n) since we perform three reverse operations, each taking O(n) time.

### Conclusion:

The optimal approach achieves the rotation in a more efficient manner. By understanding the problem constraints and leveraging array manipulation techniques, you can arrive at a solution with better time complexity.

Remember to test your code with various inputs to ensure its correctness and efficiency.