# The Quest for a Number in the Array

## The Challenge

In the vast realm of arrays, your quest is to determine the existence and location of a mysterious integer within their numeric domains. Your trusty array, named 'arr', harbors 'n' integers, and your goal is to ascertain whether a certain integer, known as 'num', is lurking within its borders.

If 'num' reveals itself in the array, your duty is to unveil its 0-based index, marking the first occurrence. Yet, if 'num' chooses to remain elusive, your answer shall be -1.

**Link** : https://www.codingninjas.com/studio/problems/linear-search_6922070

## Unraveling the Mystery

### Example

**Input:**
```
n = 5, num = 4
arr = [6, 7, 8, 4, 1]
```

**Output:**
```
3
```

**Explanation:**
The cryptic number 4 makes its presence known at the 3rd index in the array.

### Sample Input 1
```
n = 4, num = 2
arr = [2, 5, 6, 2]
```

### Sample Output 1
```
0
```

**Explanation:**
The elusive number 2 reveals itself at the 0th index in the array.

## The Quest Continues...

# Unveiling the Enigma

## Brute Force Approach
Our journey begins with a straightforward approach. We traverse the array, inspecting each element, and when the coveted 'num' is found, its index is revealed to the world. If 'num' remains elusive, -1 shall be our answer.

```cpp
int findIndexBruteForce(int n, int num, int arr[]) {
    for (int i = 0; i < n; ++i) {
        if (arr[i] == num) {
            return i;
        }
    }
    return -1;
}
```

**Time Complexity:** O(n)

**Space Complexity:** O(1)

## A Glimmer of Improvement

## Better Approach
A spark of improvement emerges with a range-based for loop. This approach, concise and readable, offers a slight enhancement in our quest for the elusive 'num'.

```cpp
int findIndexBetter(int n, int num, int arr[]) {
    int index = 0;
    for (int element : arr) {
        if (element == num) {
            return index;
        }
        ++index;
    }
    return -1;
}
```

**Time Complexity:** O(n)

**Space Complexity:** O(1)

## The Optimal Path

## Optimal Approach
On the optimal path, we embrace the reality that our quest is inherently linear. A linear search, with a time complexity of O(n), satisfies the enigma without the need for further optimization.

```cpp
int findIndexOptimal(int n, int num, int arr[]) {
    for (int i = 0; i < n; ++i) {
        if (arr[i] == num) {
            return i;
        }
    }
    return -1;
}
```

**Time Complexity:** O(n)

**Space Complexity:** O(1)

# The Conclusion

The journey through the array in search of a number unfolds as a classic example of a linear search. The brute force, better, and optimal solutions, all with a time complexity of O(n), present themselves as choices guided by readability and personal preference.

Feel free to embark on this quest using the approach that resonates with your coding style and preferences. May your arrays be ever sorted, and your numbers not too elusive!