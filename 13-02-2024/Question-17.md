# Majority Element

**Link**: https://leetcode.com/problems/majority-element/description/ , https://www.codingninjas.com/studio/problems/majority-element_6783241

## Problem Statement
Given an array `nums` of size `n`, the task is to find the majority element. The majority element is the element that appears more than ⌊n / 2⌋ times. It is guaranteed that the majority element always exists in the array.

## Example

### Example 1:

**Input:** 
```plaintext
nums = [3, 2, 3]
```
**Output:** 
```plaintext
3
```

### Example 2:

**Input:** 
```plaintext
nums = [2, 2, 1, 1, 1, 2, 2]
```
**Output:** 
```plaintext
2
```

## Constraints

- `n == nums.length`
- `1 <= n <= 5 * 10^4`
- `-10^9 <= nums[i] <= 10^9`

---

## Approach 1: Hash Map

We can use a hash map to count the occurrences of each element in the array. By iterating through the array and maintaining a count for each element, we can determine the majority element.

### Code

```cpp
#include <unordered_map>
#include <vector>

int majorityElement(std::vector<int>& nums) {
    std::unordered_map<int, int> count;

    for (int num : nums) {
        count[num]++;
        if (count[num] > nums.size() / 2) {
            return num;
        }
    }

    // The majority element is guaranteed to exist, so this line should never be reached.
    return -1;
}
```

### Explanation

- We use an unordered map (`count`) to store the count of occurrences for each element.
- While iterating through the array, we increment the count for the current element.
- If at any point the count exceeds half of the array size, we return the current element as the majority element.

---

## Approach 2: Boyer-Moore Voting Algorithm

The Boyer-Moore Voting Algorithm is an efficient algorithm for finding the majority element in a sequence. It cancels out each occurrence of an element with another non-majority element, and the majority element will still remain.

### Code

```cpp
int majorityElement(std::vector<int>& nums) {
    int candidate = nums[0];
    int count = 1;

    for (int i = 1; i < nums.size(); i++) {
        if (count == 0) {
            candidate = nums[i];
            count = 1;
        } else if (candidate == nums[i]) {
            count++;
        } else {
            count--;
        }
    }

    return candidate;
}
```

### Explanation

- We initialize a `candidate` variable with the first element and a `count` variable to 1.
- For each subsequent element, if the `count` becomes 0, we update the `candidate` to the current element and reset the `count` to 1.
- If the current element is the same as the `candidate`, we increment the `count`; otherwise, we decrement it.
- The final value of the `candidate` is the majority element.

---

## Conclusion

Both approaches are valid solutions to finding the majority element. The hash map approach is more straightforward and easier to understand, while the Boyer-Moore Voting Algorithm is more efficient in terms of space complexity. The choice between them depends on the specific requirements of the problem.