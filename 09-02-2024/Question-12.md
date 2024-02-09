# DSA Digest: Count Maximum Consecutive Ones in the Array

## The Challenge

### Count Maximum Consecutive Ones

In the realm of arrays consisting solely of 0s and 1s, a challenge awaits. Your task is to determine the count of maximum consecutive ones in the given array.

**Link**:https://leetcode.com/problems/max-consecutive-ones/description/

### Example

**Example Input:**
- Array: {1, 1, 0, 1, 1, 1}

**Example Output:**
- 3

**Explanation:**
Within the array, there are two instances of consecutive 1s, and the maximum count of consecutive 1s is 3.

**Example Input:**
- Array: {1, 0, 1, 1, 0, 1}

**Example Output:**
- 2

**Explanation:**
There are two consecutive 1s in the array, resulting in a maximum count of consecutive 1s.

### The Quest for Solutions

#### Approach:
Maintain two variables: `count` to track the number of consecutive 1s while traversing the array, and `max_count` to store the maximum count of consecutive 1s encountered so far.

1. Traverse the array:
   - If the value at the current index is 1, increment `count` by one.
   - If the value at the current index is 0, reset `count` to 0 as there are no more consecutive ones.

2. Update `max_count` with the maximum value between `max_count` and `count`.

#### Code:

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int max_count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                count++;
            } else {
                count = 0;
            }
            max_count = max(max_count, count);
        }
        return max_count;
    }
};

int main() {
    vector<int> nums = {1, 1, 0, 1, 1, 1};
    Solution obj;
    int ans = obj.findMaxConsecutiveOnes(nums);
    cout << "The maximum consecutive 1's are " << ans;
    return 0;
}
```

### Complexity Analysis

- Time Complexity: O(N) as the solution requires only a single pass through the array.
- Space Complexity: O(1) as no extra space is utilized.

Embark on this quest to count the maximum consecutive ones in the array, unraveling the mystery with an efficient solution.