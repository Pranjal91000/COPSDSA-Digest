# DSA Digest: Move Zeros to the End

## Deciphering the Challenge

### The Enigma: Move Zeros to the End

In the realm of arrays, a mysterious challenge awaits. Given an array 'arr' with 'n' non-negative integers, your quest is to rearrange the elements. The goal is to move all the zeros to the end while preserving the order of the non-zero elements at the array's beginning. The task involves decoding this puzzle and returning the modified array.

**Link**: https://www.codingninjas.com/studio/problems/ninja-and-the-zero-s_6581958

### The Ciphered Array

**Example Input:**
- n = 5
- arr = [1, 2, 0, 0, 2, 3]

**Example Output:**
- [1, 2, 2, 3, 0, 0]

**Explanation:**
The array undergoes a transformation where all zeros find their way to the end, while the non-zero elements maintain their original order at the start.

### Unveiling the Mystery through Examples

**Sample Input 1:**
- n = 4
- arr = [0, 0, 0, 1]

**Sample Output 1:**
- [1, 0, 0, 0]

**Explanation:**
Zeros are elegantly moved to the end, and the non-zero element retains its position at the beginning.

**Sample Input 2:**
- n = 5
- arr = [4, 0, 3, 2, 5]

**Sample Output 2:**
- [4, 3, 2, 5, 0]

**Explanation:**
The array undergoes a metamorphosis, positioning zeros at the end while preserving the order of non-zero elements.

## Decoding the Approach

### The Quest for Solutions

#### Brute Force:
Embark on a journey through the array, and whenever a non-zero element is encountered, initiate a swap with the first zero element found.

#### Better Solution:
Maintain two pointers – one for array iteration (i) and another (nonZeroPointer) for placing non-zero elements at their correct position. Iterate through the array, and when a non-zero element is found, swap it with the position indicated by the nonZeroPointer and increment both pointers.

#### Optimal Solution:
Navigate through the array in a single pass. Keep a pointer (nonZeroPointer) to track the position for the next non-zero element. Encounter a non-zero element, swap it with the element at nonZeroPointer, and increment the pointer. This ensures non-zero elements at the beginning and zeros at the end.

## The Code Breakthrough

### C++ Code

#### Brute Force
```cpp
void moveZerosToEndBruteForce(vector<int>& arr, int n) {
    for (int i = 0; i < n; ++i) {
        if (arr[i] != 0) {
            for (int j = i + 1; j < n; ++j) {
                if (arr[j] == 0) {
                    swap(arr[i], arr[j]);
                    break;
                }
            }
        }
    }
}
```

#### Better Solution
```cpp
void moveZerosToEndBetter(vector<int>& arr, int n) {
    int nonZeroPointer = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] != 0) {
            swap(arr[i], arr[nonZeroPointer]);
            nonZeroPointer++;
        }
    }
}
```

#### Optimal Solution
```cpp
void moveZerosToEndOptimal(vector<int>& arr, int n) {
    int nonZeroPointer = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] != 0) {
            swap(arr[i], arr[nonZeroPointer++]);
        }
    }
}
```

## Complexity Analysis

- Brute Force: O(n^2)
- Better Solution: O(n)
- Optimal Solution: O(n)

The optimal solution stands out as the most efficient, unraveling the mystery with a linear time complexity of O(n). Choose your path wisely in the array's labyrinth, where efficiency meets elegance.