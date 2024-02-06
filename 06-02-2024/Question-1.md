**Problem Description and Link**
Given an array ‘arr’ of size ‘n’ find the largest element in the array.

Expected Time Complexity:
O(n), Where ‘n’ is the size of an input array ‘arr’.
Constraints :
1 <= 'n' <= 10^5
1 <= 'arr[i]' <= 10^9

Time Limit: 1 sec

*Link*: https://www.codingninjas.com/studio/problems/largest-element-in-the-array-largest-element-in-the-array_5026279


**Problem Unveiling:**

Imagine you're embarking on a journey through an array landscape, searching for the mightiest element. Your task: find the largest warrior in the array battleground.

*Array Arsenal:*

You possess an array 'arr' of size 'n,' each element representing a warrior's strength. Your mission is to pinpoint the mightiest warrior – the largest element in the array.

*Example Expedition:*

For instance, if given an array like [1, 2, 3, 4, 5], the quest is clear – the largest warrior is 5.

**Sample Challenges:**

*Challenge 1:*
```
Input: 
6
4 7 8 6 7 6
Output: 
8
```
*Explanation:* From the array [4, 7, 8, 6, 7, 6], the mightiest warrior stands tall at 8.

*Challenge 2:*
```
Input: 
8
5 9 3 4 8 4 3 10
Output: 
10
```
*Challenge Accepted:* The battle report reads [5, 9, 3, 4, 8, 4, 3, 10], and the mightiest warrior is crowned with a strength of 10.

**Constraints & Time Constraints:**

- 1 <= 'n' <= 10^5
- 1 <= 'arr[i]' <= 10^9

**Embark on the Journey:**
Your quest involves traversing the array landscape efficiently. The legendary code must deliver the mightiest warrior swiftly.

---

**Brute Force Odyssey:**

In your initial quest, you decide to follow the traditional path – a brute force approach. Armed with Python, your journey looks like this:

```python
def find_largest_element(arr, n):
    max_element = arr[0]
    for i in range(1, n):
        if arr[i] > max_element:
            max_element = arr[i]
    return max_element
```

**Time Complexity Unveiled:**
The time complexity of this journey is O(n), as you traverse the array once, identifying the mightiest warrior.

---

**Optimal Quest:**

However, there's a hidden shortcut – the Python 'max' function, a powerful ally in your quest.

```python
def find_largest_element_optimal(arr):
    return max(arr)
```

**Time Complexity Unveiled:**
The 'max' function, a wizard in Python, operates in linear time – O(n), aligning with the optimal time complexity.

---

*As you embark on this array adventure, your choice between the brute force odyssey and the optimal quest reveals your mastery of coding prowess.*