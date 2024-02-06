## Problem Statement

You are given an array `a` of `n` unique non-negative integers. Your task is to find the second-largest and second-smallest elements from the array. Return these two elements as another array of size 2.

*Link*: https://www.codingninjas.com/studio/problems/ninja-and-the-second-order-elements_6581960

### Example
**Input:**
- n = 5
- a = [1, 2, 3, 4, 5]

**Output:**
- [4, 2]

*Explanation:*
The second-largest element after 5 is 4, and the second-smallest element after 1 is 2.

### Sample Input 1
**Input:**
- n = 4
- a = [3, 4, 5, 2]

**Output:**
- [4, 3]

*Explanation:*
The second-largest element after 5 is 4, and the second-smallest element after 2 is 3.

### Sample Input 2
**Input:**
- n = 5
- a = [4, 5, 3, 6, 7]

**Output:**
- [6, 4]

---

## Brute Force Solution

A brute force solution involves sorting the array and then picking the second-largest and second-smallest elements. Let's implement this and analyze its time complexity.

### Brute Force Code (C++)

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

std::vector<int> findSecondLargestAndSmallest(int n, std::vector<int>& a) {
    // Sort the array in ascending order
    std::sort(a.begin(), a.end());

    // Return the second-largest and second-smallest elements
    return { a[n-2], a[1] };
}

int main() {
    int n;
    std::cout << "Enter the size of the array: ";
    std::cin >> n;

    std::vector<int> a(n);
    std::cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    std::vector<int> result = findSecondLargestAndSmallest(n, a);

    std::cout << "Second Largest: " << result[0] << std::endl;
    std::cout << "Second Smallest: " << result[1] << std::endl;

    return 0;
}
```

### Brute Force Time Complexity Analysis

1. Sorting the array takes O(n log n) time.
2. Extracting the second-largest and second-smallest elements takes constant time.

**Overall Time Complexity:** O(n log n)

---

## Better Solution

A better solution involves traversing the array once to find the second-largest and second-smallest elements without sorting. Let's implement this and analyze its time complexity.

### Better Solution Code (C++)

```cpp
#include <iostream>
#include <vector>

std::vector<int> findSecondLargestAndSmallest(int n, std::vector<int>& a) {
    int first, second;  // To store the first and second elements

    // Initialize first and second
    if (a[0] > a[1]) {
        first = a[0];
        second = a[1];
    } else {
        first = a[1];
        second = a[0];
    }

    // Traverse the array to find the second-largest and second-smallest
    for (int i = 2; i < n; ++i) {
        if (a[i] > first) {
            second = first;
            first = a[i];
        } else if (a[i] > second && a[i] != first) {
            second = a[i];
        }
    }

    return { second, first };
}

int main() {
    int n;
    std::cout << "Enter the size of the array: ";
    std::cin >> n;

    std::vector<int> a(n);
    std::cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    std::vector<int> result = findSecondLargestAndSmallest(n, a);

    std::cout << "Second Largest: " << result[0] << std::endl;
    std::cout << "Second Smallest: " << result[1] << std::endl;

    return 0;
}
```

### Better Solution Time Complexity Analysis

- Traverse the array once, taking linear time.

**Overall Time Complexity:** O(n)

---

## Optimal Solution

The optimal solution further optimizes the space usage while maintaining linear time complexity. Let's implement this and analyze its time complexity.

### Optimal Solution Code (C++)

```cpp
#include <iostream>
#include <vector>

std::vector<int> findSecondLargestAndSmallest(int n, std::vector<int>& a) {
    int first, second;  // To store the first and second elements

    // Initialize first and second
    if (a[0] > a[1]) {
        first = a[0];
        second = a[1];
    } else {
        first = a[1];
        second = a[0];
    }

    // Traverse the array to find the second-largest and second-smallest
    for (int i = 2; i < n; ++i) {
        if (a[i] > first) {
            second = first;
            first = a[i];
        } else if (a[i] > second && a[i] != first) {
            second = a[i];
        }
    }

    return { second, first };
}

int main() {
    int n;
    std::cout << "Enter the size of the array: ";
    std::cin >> n;

    std::vector<int> a(n);
    std::cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    std::vector<int> result = findSecondLargestAndSmallest(n, a);

    std::cout << "Second Largest: " << result[0] << std::endl;
    std::cout << "Second Smallest: " << result[1] << std::endl;

    return 0;
}
```

### Optimal Solution Time Complexity Analysis

- Traverse the array once, taking linear time.

**Overall Time Complexity:** O(n)

**Space Complexity:** O(1)

---

## Summary

In this DSA Digest, we explored a problem of finding the second-largest and second-smallest elements in an array. We discussed and implemented three solutions:

1. **Brute Force Solution:**
   - Time Complexity: O(n log n)
   - Involves sorting the array.

2. **Better Solution:**
   - Time Complexity: O(n)
   - Traverses the array once to find the second-largest and second-smallest elements without sorting.

3. **Optimal Solution:**
   - Time Complexity: O(n)
   - Further optimizes space usage by using constant space.

Choose the appropriate solution based on the specific requirements and constraints of your problem. The optimal solution provides a good balance between time and space

 efficiency.