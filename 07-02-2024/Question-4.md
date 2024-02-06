**Title: "Removing Duplicates in Sorted Array - A Deep Dive into DSA"**

**Introduction:**
Welcome, fellow programmers! Today, let's delve into an interesting Data Structures and Algorithms (DSA) problem that involves arrays and efficient manipulation techniques. The problem at hand is about removing duplicates from a sorted array in-place, while maintaining the relative order of elements.

**Problem Description:**
Given a sorted integer array `nums`, our task is to remove duplicates in-place and return the number of unique elements. We need to modify the array such that the first `k` elements contain the unique elements in the order they were initially present. The remaining elements beyond `k` are not important. The ultimate goal is to return `k`.

Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/, https://www.codingninjas.com/studio/problems/remove-duplicates-from-sorted-array_1102307


**Example:**
Consider the array `nums = [1, 1, 2]`. The expected output is `2`, and the modified array is `[1, 2, _]`. Another example is `nums = [0, 0, 1, 1, 1, 2, 2, 3, 3, 4]`, which should return `5`, and the modified array becomes `[0, 1, 2, 3, 4, _, _, _, _, _]`.

**Brute Force Approach:**
A simple brute force approach is to iterate through the array and compare each element with the next one. If a duplicate is found, we can shift the subsequent elements to fill the gap. While this works, it is not the most efficient way and may result in a time complexity of O(n^2).

**Better Approach:**
A better approach involves using two pointers. One pointer iterates through the array, while the other keeps track of the position where the next unique element should be placed. If a unique element is encountered, it is swapped with the element at the unique position. This approach has a time complexity of O(n) and is more efficient than the brute force method.

**Optimal Solution:**
The optimal solution is even more elegant. Since the array is sorted, we can leverage the fact that duplicates will always be adjacent. We iterate through the array and whenever a unique element is found, we move it to the next position in the array. The returned value `k` indicates the number of unique elements, and the modified array contains only those unique elements.



**1. Brute Force Approach:**

```cpp
int removeDuplicatesBruteForce(vector<int>& nums) {
    int n = nums.size();
    if (n <= 1) return n; // No duplicates possible
    
    for (int i = 0; i < n - 1; ++i) {
        while (i < n - 1 && nums[i] == nums[i + 1]) {
            nums.erase(nums.begin() + i + 1);
            n--;
        }
    }
    
    return n;
}
```

**2. Better Approach using Two Pointers:**

```cpp
int removeDuplicatesTwoPointers(vector<int>& nums) {
    int n = nums.size();
    if (n <= 1) return n; // No duplicates possible
    
    int uniquePos = 1;
    for (int i = 1; i < n; ++i) {
        if (nums[i] != nums[i - 1]) {
            nums[uniquePos++] = nums[i];
        }
    }
    
    return uniquePos;
}
```

**3. Optimal Solution with Sorted Array Property:**

```cpp
int removeDuplicatesOptimal(vector<int>& nums) {
    int n = nums.size();
    if (n <= 1) return n; // No duplicates possible
    
    int uniquePos = 1;
    for (int i = 1; i < n; ++i) {
        if (nums[i] != nums[uniquePos - 1]) {
            nums[uniquePos++] = nums[i];
        }
    }
    
    return uniquePos;
}
```

**Conclusion:**
Removing duplicates from a sorted array is a classic problem that allows us to explore different approaches, from brute force to more optimized solutions. By understanding the problem constraints and applying the right algorithm, we can efficiently solve such challenges in the realm of Data Structures and Algorithms. Happy coding!