# DSA Digest: Find the Number That Appears Once, and the Other Numbers Twice

## The Challenge

Given a non-empty array of integers `arr`, every element appears twice except for one. Find that single element.

**Link**:https://takeuforward.org/arrays/find-the-number-that-appears-once-and-the-other-numbers-twice/

### Examples:

**Example 1:**

**Input:** `arr[] = {2, 2, 1}`  
**Result:** `1`  
**Explanation:** In this array, only the element 1 appears once, so it is the answer.

**Example 2:**

**Input:** `arr[] = {4, 1, 2, 1, 2}`  
**Result:** `4`  
**Explanation:** In this array, only the element 4 appears once, while the other elements appear twice. So, 4 is the answer.

## Brute Force Approach

**Algorithm / Intuition:**

- For every element present in the array, perform a linear search and count the occurrences.
- If for any element, the occurrence is 1, return it.

**Approach:**

- Run a loop to select the elements of the array one by one.
- For every element `arr[i]`, perform a linear search to count its occurrence.
- If the occurrence of any element is 1, return it.

**Code (C++):**

```cpp
// Function to get the single element
int getSingleElement(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        int num = arr[i];
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (arr[j] == num)
                cnt++;
        }
        if (cnt == 1)
            return num;
    }
    return -1;
}
```

**Complexity Analysis:**

- Time Complexity: O(N^2), where N is the size of the given array.
- Space Complexity: O(1) as no extra space is used.

## Better Approach 1: Using Hashing (Array Hashing)

**Algorithm / Intuition:**

- Hash the elements along with their occurrences in an array.
- Search for the element with a frequency of 1.

**Approach:**

- Find the maximum element `maxi` to determine the size of the hash array.
- Declare a hash array of size `maxi + 1`.
- Hash the given array elements.
- Search for the single element in the hash array and return it.

**Code (C++):**

```cpp
// Function to get the single element using array hashing
int getSingleElement(vector<int>& arr) {
    int n = arr.size();
    int maxi = arr[0];
    for (int i = 0; i < n; i++) {
        maxi = max(maxi, arr[i]);
    }
    vector<int> hash(maxi + 1, 0);
    for (int i = 0; i < n; i++) {
        hash[arr[i]]++;
    }
    for (int i = 0; i < n; i++) {
        if (hash[arr[i]] == 1)
            return arr[i];
    }
    return -1;
}
```

**Complexity Analysis:**

- Time Complexity: O(N) + O(N) + O(N), where N is the size of the array.
- Space Complexity: O(maxElement + 1), where `maxElement` is the maximum element of the array.

## Better Approach 2: Using Hashing (Map Data Structure)

**Algorithm / Intuition:**

- Hash the elements along with their occurrences in a map.
- Search for the element with a frequency of 1.

**Approach:**

- Declare a map.
- Hash the given array elements.
- Search for the single element in the map and return it.

**Code (C++):**

```cpp
// Function to get the single element using map data structure
int getSingleElement(vector<int>& arr) {
    int n = arr.size();
    map<int, int> mpp;
    for (int i = 0; i < n; i++) {
        mpp[arr[i]]++;
    }
    for (auto it : mpp) {
        if (it.second == 1)
            return it.first;
    }
    return -1;
}
```

**Complexity Analysis:**

- Time Complexity: O(N*logM) + O(M), where M is the size of the map.
- Space Complexity: O(M), where M is the size of the map.

## Optimal Approach: Using XOR

**Algorithm / Intuition:**

- Perform XOR of all elements of the array.
- The result will be the single element.

**Approach:**

- XOR all the elements of the array and return the result.

**Code (C++):**

```cpp
// Function to get the single element using XOR
int getSingleElement(vector<int>& arr) {
    int n = arr.size();
    int xorr = 0;
    for (int i = 0; i < n; i++) {
        xorr = xorr ^ arr[i];
    }
    return xorr;
}
```

**Complexity Analysis:**

- Time Complexity: O(N), where N is the size of the array.
- Space Complexity: O(1) as no extra space is used.