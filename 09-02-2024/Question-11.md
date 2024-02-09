# DSA Digest: Find the Missing Number in an Array

## The Challenge

### The Enigma: Find the Missing Number

In the realm of arrays, a new enigma awaits. Given an integer N and an array of size N-1 containing N-1 numbers between 1 to N, your task is to unveil the missing number from the array. The goal is to determine the number between 1 to N that is absent in the given array.

**Link**:https://leetcode.com/problems/missing-number/description/

### Unravelling the Mystery

**Example Input:**
- N = 5
- Array: [1, 2, 4, 5]

**Example Output:**
- 3

**Explanation:**
The array lacks the presence of the number 3. Hence, 3 is the missing number from the sequence.

## Decoding the Approach

### The Quest for Solutions

#### Naive Approach (Brute-force approach):
Explore each number from 1 to N, searching for its existence in the given array through linear search. Upon not finding a number, conclude it as the missing number.

#### Better Approach (using Hashing):
Harness the power of hashing to store the frequency of each element in the array. Detect the missing number by identifying the number with a frequency of 0.

#### Summation Approach:
Leverage the summation of the first N natural numbers and compare it with the sum of the array elements. The difference reveals the missing number.

#### XOR Approach:
Exploit the XOR operation to find the missing number by XORing all numbers from 1 to N with the XOR of the array elements.

## The Code Breakthrough

### C++ Code

#### Naive Approach (Brute-force approach)
```cpp
#include <bits/stdc++.h>
using namespace std;

int missingNumber(vector<int>& a, int N) {
    for (int i = 1; i <= N; i++) {
        int flag = 0;
        for (int j = 0; j < N - 1; j++) {
            if (a[j] == i) {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            return i;
    }
    return -1;
}

int main() {
    int N = 5;
    vector<int> a = {1, 2, 4, 5};
    int ans = missingNumber(a, N);
    cout << "The missing number is: " << ans << endl;
    return 0;
}
```

#### Better Approach (using Hashing)
```cpp
#include <bits/stdc++.h>
using namespace std;

int missingNumber(vector<int>& a, int N) {
    int hash[N + 1] = {0};
    for (int i = 0; i < N - 1; i++)
        hash[a[i]]++;
    for (int i = 1; i <= N; i++) {
        if (hash[i] == 0)
            return i;
    }
    return -1;
}

int main() {
    int N = 5;
    vector<int> a = {1, 2, 4, 5};
    int ans = missingNumber(a, N);
    cout << "The missing number is: " << ans << endl;
    return 0;
}
```

#### Summation Approach
```cpp
#include <bits/stdc++.h>
using namespace std;

int missingNumber(vector<int>& a, int N) {
    int sum = (N * (N + 1)) / 2;
    int s2 = 0;
    for (int i = 0; i < N - 1; i++) {
        s2 += a[i];
    }
    int missingNum = sum - s2;
    return missingNum;
}

int main() {
    int N = 5;
    vector<int> a = {1, 2, 4, 5};
    int ans = missingNumber(a, N);
    cout << "The missing number is: " << ans << endl;
    return 0;
}
```

#### XOR Approach
```cpp
#include <bits/stdc++.h>
using namespace std;

int missingNumber(vector<int>& a, int N) {
    int xor1 = 0, xor2 = 0;
    for (int i = 0; i < N - 1; i++) {
        xor2 = xor2 ^ a[i];
        xor1 = xor1 ^ (i + 1);
    }
    xor1 = xor1 ^ N;
    return (xor1 ^ xor2);
}

int main() {
    int N = 5;
    vector<int> a = {1, 2, 4, 5};
    int ans = missingNumber(a, N);
    cout << "The missing number is: " << ans << endl;
    return 0;
}
```

## Complexity Analysis

- Naive Approach (Brute-force approach): O(N^2)
- Better Approach (using Hashing): O(N)
- Summation Approach: O(N)
- XOR Approach: O(N)

Among the solutions, the XOR Approach stands out as the most efficient with a linear time complexity of O(N). Choose your path wisely as you unravel the mystery of the missing number in the array.