# Stock Buy And Sell

**Problem Statement:** You are given an array of prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock. Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

## Examples

**Example 1:**

Input: `prices = [7,1,5,3,6,4]`
Output: `5`
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.

**Example 2:**

Input: `prices = [7,6,4,3,1]`
Output: `0`
Explanation: In this case, no transactions are done and the max profit = 0.

## Practice

### Solve Problem
[Coding-Ninja](https://www.codingninjas.com/studio/problems/reading_6845742)

[LeetCode](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)

**Disclaimer:** Don’t jump directly to the solution, try it out yourself first.

## Brute Force Approach

**Algorithm / Intuition:**
We can simply use 2 loops and track every transaction and maintain a variable maxPro to contain the max value among all transactions.

**Approach:**
1. Use a for loop of ‘i’ from 0 to n.
2. Use another for loop of j from ‘i+1’ to n.
3. If arr[j] > arr[i], take the difference and compare and store it in the maxPro variable.
4. Return maxPro.

#### Code

```cpp
#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &arr) {
    int maxPro = 0;
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[i]) {
                maxPro = max(arr[j] - arr[i], maxPro);
            }
        }
    }

    return maxPro;
}

int main() {
    vector<int> arr = {7,1,5,3,6,4};
    int maxPro = maxProfit(arr);
    cout << "Max profit is: " << maxPro << endl;
}
```

**Output:**

```
Max profit is: 5
```

**Complexity Analysis:**
- Time complexity: O(n^2)
- Space Complexity: O(1)

## Optimal Approach

**Algorithm / Intuition:**
We will linearly travel the array. We can maintain a minimum from the start of the array and compare it with every element of the array, if it is greater than the minimum then take the difference and maintain it in max, otherwise update the minimum.

**Approach:**
1. Create a variable maxPro and store 0 initially.
2. Create a variable minPrice and store some larger value(ex: MAX_VALUE) value initially.
3. Run a for loop from 0 to n.
4. Update the minPrice if it is greater than the current element of the array.
5. Take the difference of the minPrice with the current element of the array and compare and maintain it in maxPro.
6. Return the maxPro.

#### Code

```cpp
#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &arr) {
    int maxPro = 0;
    int n = arr.size();
    int minPrice = INT_MAX;

    for (int i = 0; i < arr.size(); i++) {
        minPrice = min(minPrice, arr[i]);
        maxPro = max(maxPro, arr[i] - minPrice);
    }
    
    return maxPro;
}

int main() {
    vector<int> arr = {7,1,5,3,6,4};
    int maxPro = maxProfit(arr);
    cout << "Max profit is: " << maxPro << endl;
}
```

**Output:** Max profit is: 5

**Complexity Analysis:**
- Time complexity: O(n)
- Space Complexity: O(1)