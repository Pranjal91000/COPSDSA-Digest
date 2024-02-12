# Longest Subarray With Sum K - Deep Dive DSA Digest

**Link**: https://www.codingninjas.com/studio/problems/longest-subarray-with-sum-k_5713505

## Problem Statement

Ninja and his friend are playing a game of subarrays. They have an array `NUMS` of length `N`. Ninja’s friend gives him an arbitrary integer `K` and asks him to find the length of the longest subarray in which the sum of elements is equal to `K`.

Ninjas asks for your help to win this game. Find the length of the longest subarray in which the sum of elements is equal to `K`.

If there is no subarray whose sum is `K`, then you should return 0.

### Example:

**Input:**
- `N` = 5,  `K` = 4, `NUMS` = [1, 2, 1, 0, 1]

**Output:**
- 4

There are two subarrays with sum = 4, [1, 2, 1] and [2, 1, 0, 1]. Hence the length of the longest subarray with sum = 4 is 4.

### Constraints:
- 1 <= T <= 10
- 1 <= N <= 10^5
- -10^6 <= NUMS[i] <= 10^6
- -10^6 <= K <= 10^6
- Sum of N over all the test cases <= 10^5

## Approaches

### Approach 1: Brute Force

**Algorithm:**
1. Initialize a variable `maxLen` to 0.
2. Iterate over all subarrays and find the sum of each subarray.
3. If the sum is equal to `K`, update `maxLen` with the maximum length encountered so far.
4. Return `maxLen` as the result.

**C++ Code:**
```cpp
int findMaxLengthBruteForce(vector<int>& nums, int k) {
    int n = nums.size();
    int maxLen = 0;

    for (int start = 0; start < n; ++start) {
        int sum = 0;
        for (int end = start; end < n; ++end) {
            sum += nums[end];
            if (sum == k) {
                maxLen = max(maxLen, end - start + 1);
            }
        }
    }

    return maxLen;
}
```

### Approach 2: Prefix Sum

**Algorithm:**
1. Calculate the prefix sum array `prefixSum` of the given array.
2. Iterate over all pairs of indices (i, j) and find the sum of the subarray between them using `prefixSum`.
3. If the sum is equal to `K`, update `maxLen` with the maximum length encountered so far.
4. Return `maxLen` as the result.

**C++ Code:**
```cpp
int findMaxLengthPrefixSum(vector<int>& nums, int k) {
    int n = nums.size();
    int maxLen = 0;
    unordered_map<int, int> prefixSum;  // Map to store prefix sums

    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += nums[i];
        if (sum == k) {
            maxLen = i + 1;  // Subarray from index 0 to i has sum equal to K
        } else if (prefixSum.find(sum - k) != prefixSum.end()) {
            maxLen = max(maxLen, i - prefixSum[sum - k]);
        }
        if (prefixSum.find(sum) == prefixSum.end()) {
            prefixSum[sum] = i;  // Store the first occurrence of prefix sum
        }
    }

    return maxLen;
}
```

## Conclusion

The problem "Longest Subarray With Sum K" can be solved using different approaches. The brute force approach involves checking all subarrays, while the prefix sum approach is more optimized. Choose the approach based on the size of the input data and the desired runtime complexity.