# Ferris Wheel

**Problem Statement:** You are given the number of persons \(n\) and the maximum weight \(x\) that the ferris wheel can carry. Each person has a weight \(ai\). Your task is to determine the minimum number of gondolas needed to carry all the persons while ensuring that the weight limit of each gondola is not exceeded.

## Input
The first line of input contains two integers \(n\) and \(x\): the number of persons and the maximum weight limit of each gondola, respectively.
The second line contains \(n\) integers \(a1, a2, ...., aN\): the weights of the persons.

## Output
Print the minimum number of gondolas needed to carry all the persons.

## Constraints
- 1 <= n <= 2 x 10^5
- 1 <= x, ai <= 10^9

## Examples

**Input:**
```
4 10
7 2 3 9
```

**Output:**
```
3
```

## Approaches

### 1. Greedy Approach

**Algorithm / Intuition:**
We can sort the weights of the persons in non-decreasing order. Then, we can try to assign persons to gondolas one by one, starting with the lightest person. We'll put as many persons in one gondola as long as their total weight does not exceed the weight limit of the gondola.

**Approach:**
1. Sort the array of person weights in non-decreasing order.
2. Initialize two pointers, \(left\) and \(right\), at the beginning and end of the sorted array, respectively.
3. Initialize a variable \(gondolaCount\) to 0.
4. Repeat until \(left <= right\):
   - If the weight of the person at index \(left\) plus the weight of the person at index \(right\) does not exceed the weight limit \(x\), increment \(left\) and decrement \(right\).
   - Otherwise, only increment \(right\).
   - Increment \(gondolaCount\) after each iteration.
5. Return \(gondolaCount\).

#### Code

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> weights(n);
    for (int i = 0; i < n; ++i) {
        cin >> weights[i];
    }

    sort(weights.begin(), weights.end());
    int left = 0, right = n - 1;
    int gondolaCount = 0;

    while (left <= right) {
        if (weights[left] + weights[right] <= x) {
            left++;
            right--;
        } else {
            right--;
        }
        gondolaCount++;
    }

    cout<<gondolaCount<<"\n";
}
```

**Complexity Analysis:**
- Time complexity: \(O(n log n)\) due to sorting
- Space complexity: \(O(n)\)


### Solve Problem
[CSES](https://cses.fi/problemset/task/1090)


