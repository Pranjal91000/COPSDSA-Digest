# Merge 2 Sorted Arrays

## Problem Statement

Given two sorted arrays, `a` and `b`, of size `n` and `m` respectively, return the union of the arrays.

The union of two sorted arrays is an array consisting of the common and distinct elements of the two arrays. The final array should be sorted in ascending order.

**Note:** Arrays `a` and `b` may contain duplicate elements, but the union array must contain unique elements.

**Link** : https://www.codingninjas.com/studio/problems/sorted-array_6613259

### Example

**Input:**
```
n = 5, m = 3
a = [1, 2, 3, 4, 6]
b = [2, 3, 5]
```

**Output:**
```
[1, 2, 3, 4, 5, 6]
```

**Explanation:**
Common elements in `a` and `b` are: [2, 3]
Distinct elements in `a` are: [1, 4, 6]
Distinct elements in `b` are: [5]
Union of `a` and `b` is: [1, 2, 3, 4, 5, 6]

### Constraints
- 1 <= n, m <= 10^5
- -10^9 <= a[i], b[i] <= 10^9

### Expected Time Complexity
O((N + M)), where 'N' and 'M' are the sizes of Arrays `A` and `B`.

## Brute Force Approach

One way to solve this problem is to iterate through both arrays, identify common elements, and merge the distinct elements. The time complexity of this approach is O(N + M) where N and M are the sizes of Arrays `A` and `B`.

```cpp
// C++ Brute Force Solution
vector<int> mergeArrays(const vector<int>& A, const vector<int>& B) {
    vector<int> result;
    int i = 0, j = 0;
    
    while (i < A.size() && j < B.size()) {
        if (A[i] < B[j]) {
            result.push_back(A[i]);
            i++;
        } else if (A[i] > B[j]) {
            result.push_back(B[j]);
            j++;
        } else {
            // Common element, add to result and move both pointers
            result.push_back(A[i]);
            i++;
            j++;
        }
    }

    // Add remaining elements from both arrays
    while (i < A.size()) {
        result.push_back(A[i]);
        i++;
    }

    while (j < B.size()) {
        result.push_back(B[j]);
        j++;
    }

    return result;
}
```

## Better Approach

A more efficient solution is to use a set to keep track of unique elements while iterating through both arrays. This eliminates the need for a separate merging step.

```cpp
// C++ Better Solution
vector<int> mergeArrays(const vector<int>& A, const vector<int>& B) {
    set<int> uniqueElements;
    vector<int> result;

    for (int num : A)
        uniqueElements.insert(num);

    for (int num : B)
        uniqueElements.insert(num);

    // Copy unique elements to result vector
    copy(uniqueElements.begin(), uniqueElements.end(), back_inserter(result));

    return result;
}
```

## Optimal Approach

The optimal solution takes advantage of the fact that both arrays are sorted. It uses two pointers to efficiently identify common and distinct elements while traversing the arrays.

```cpp
// C++ Optimal Solution
vector<int> mergeArrays(const vector<int>& A, const vector<int>& B) {
    vector<int> result;
    int i = 0, j = 0;

    while (i < A.size() && j < B.size()) {
        if (A[i] < B[j]) {
            result.push_back(A[i]);
            i++;
        } else if (A[i] > B[j]) {
            result.push_back(B[j]);
            j++;
        } else {
            // Common element, add to result and move both pointers
            result.push_back(A[i]);
            i++;
            j++;
        }
    }

    // Add remaining elements from both arrays
    while (i < A.size()) {
        result.push_back(A[i]);
        i++;
    }

    while (j < B.size()) {
        result.push_back(B[j]);
        j++;
    }

    return result;
}
```

These solutions provide different trade-offs in terms of time and space complexity. Choose the most suitable approach based on the specific requirements and constraints of your application.