# Longest Subarray With Sum K - Deep Dive DSA Digest
**Link**: https://www.codingninjas.com/studio/problems/longest-subarray-with-sum-k_6682399
## Problem Statement:

You are given an array 'a' of size 'n' and an integer 'k'. Find the length of the longest subarray of 'a' whose sum is equal to 'k'.

### Example:

**Input:**
- `n = 7`
- `k = 3`
- `a = [1, 2, 3, 1, 1, 1, 1]`

**Output:**
- `3`

**Explanation:**
Subarrays whose sum equals '3' are: [1, 2], [3], [1, 1, 1], and [1, 1, 1]. The length of the longest subarray is 3, which is our final answer.

### Sample Input 1:
- `7 3`
- `1 2 3 1 1 1 1`

### Sample Output 1:
- `3`

**Explanation:**
Subarrays whose sum equals '3' are: [1, 2], [3], [1, 1, 1], and [1, 1, 1]. The length of the longest subarray is 3, which is our final answer.

### Sample Input 2:
- `4 2`
- `1 2 1 3`

### Sample Output 2:
- `1`

### Sample Input 3:
- `5 2`
- `2 2 4 1 2`

### Sample Output 3:
- `1`

## Approaches:

### 1. Brute Force Approach:

Iterate through all possible subarrays, calculate their sums, and find the longest subarray with the sum equal to 'k'.

```cpp
// C++ Code for Brute Force Approach
int longestSubarraySumKBruteForce(int n, int k, int a[]) {
    int maxLength = 0;

    for (int start = 0; start < n; ++start) {
        int currentSum = 0;
        for (int end = start; end < n; ++end) {
            currentSum += a[end];
            if (currentSum == k) {
                maxLength = max(maxLength, end - start + 1);
            }
        }
    }

    return maxLength;
}
```

**Time Complexity:** O(n^2)

### 2. Prefix Sum Approach:

Use prefix sum to efficiently calculate the sum of any subarray. Maintain a map to store the prefix sum and find the longest subarray with sum equal to 'k'.

```cpp
// C++ Code for Prefix Sum Approach
int longestSubarraySumKPrefixSum(int n, int k, int a[]) {
    unordered_map<int, int> prefixSumIndex;
    int maxLength = 0;
    int currentSum = 0;

    for (int i = 0; i < n; ++i) {
        currentSum += a[i];

        if (currentSum == k) {
            maxLength = i + 1;
        } else if (prefixSumIndex.find(currentSum - k) != prefixSumIndex.end()) {
            maxLength = max(maxLength, i - prefixSumIndex[currentSum - k]);
        }

        if (prefixSumIndex.find(currentSum) == prefixSumIndex.end()) {
            prefixSumIndex[currentSum] = i;
        }
    }

    return maxLength;
}
```

**Time Complexity:** O(n)

### 3. Sliding Window Approach:

Use a sliding window to efficiently find the longest subarray with sum equal to 'k'.

```cpp
// C++ Code for Sliding Window Approach
int longestSubarraySumKSlidingWindow(int n, int k, int a[]) {
    int maxLength = 0;
    int start = 0;
    int currentSum = 0;

    for (int end = 0; end < n; ++end) {
        currentSum += a[end];

        while (currentSum > k) {
            currentSum -= a[start];
            ++start;
        }

        if (currentSum == k) {
            maxLength = max(maxLength, end - start + 1);
        }
    }

    return maxLength;
}
```

**Time Complexity:** O(n)

## Conclusion:

The problem of finding the length of the longest subarray with a sum equal to 'k' can be efficiently solved using different approaches. The Brute Force approach has a higher time complexity, while the Prefix Sum and Sliding Window approaches provide more optimized solutions. The choice of approach depends on the specific requirements and constraints of the problem.