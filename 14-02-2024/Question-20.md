# Coin Piles

**Problem Statement:** You have two coin piles containing a and b coins. On each move, you can either remove one coin from the left pile and two coins from the right pile, or two coins from the left pile and one coin from the right pile. Your task is to efficiently find out if you can empty both the piles.

## Input
The first input line has an integer t: the number of tests. After this, there are t lines, each of which has two integers a and b: the numbers of coins in the piles.

## Output
For each test, print "YES" if you can empty the piles and "NO" otherwise.

## Constraints
- 1 <= t <= 10^5
- 0 <= a, b <= 10^9

## Examples

**Input:**
```
3
2 1
2 2
3 3
```

**Output:**
```
YES
NO
YES
```

## Approaches


**Algorithm / Intuition:**
We can observe that it's only possible to empty both piles if the total number of coins in both piles is divisible by 3 and if the number of coins removed from one pile is twice the number of coins removed from the other pile.

**Approach:**
1. Check if \(a + b\) is divisible by 3.
2. If so, check if \(2a >= b\) and \(2b >= a\). If both conditions are met, return "YES", otherwise return "NO".

#### Code

```cpp
#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int a, b;
        cin >> a >> b;

        if ((a + b)%3==0 && 2*min(a, b)>=max(a, b)) cout<<"YES"<<"\n";
        else cout<<"NO"<<"\n";
    }

    return 0;
}
```

**Complexity Analysis:**
- Time complexity: \(O(1)\)
- Space complexity: \(O(1)\)

### Solve Problem
[CSES](https://cses.fi/problemset/task/1754)
