#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Initializing a vector
    vector<int> numbers;

    // push_back(): Adds elements to the end of the vector
    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);

    // Displaying the vector
    cout << "Vector after push_back(): ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    // pop_back(): Removes the last element from the vector
    numbers.pop_back();

    // Displaying the vector after pop_back()
    cout << "Vector after pop_back(): ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    // size(): Returns the number of elements in the vector
    cout << "Size of the vector: " << numbers.size() << endl;

    // empty(): Checks if the vector is empty
    if (numbers.empty()) {
        cout << "Vector is empty." << endl;
    } else {
        cout << "Vector is not empty." << endl;
    }

    // insert(): Inserts elements at a specified position in the vector
    numbers.insert(numbers.begin() + 1, 99);

    // Displaying the vector after insert()
    cout << "Vector after insert(): ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    // Sorting the vector
    sort(numbers.begin(), numbers.end());

    // Displaying the vector after sorting
    cout << "Vector after sorting: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    // at(): Accesses the element at a specified index with bounds checking
    int index = 2;
    if (index < numbers.size()) {
        cout << "Element at index " << index << ": " << numbers.at(index) << endl;
    } else {
        cout << "Index out of bounds." << endl;
    }

    // front(): Returns a reference to the first element in the vector
    cout << "First element in the vector: " << numbers.front() << endl;

    // back(): Returns a reference to the last element in the vector
    cout << "Last element in the vector: " << numbers.back() << endl;

    // begin() and end(): Provide iterators for iteration
    cout << "Vector elements using iterators: ";
    for (auto it = numbers.begin(); it != numbers.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // clear(): Removes all elements from the vector, leaving it empty
    numbers.clear();

    // Displaying the vector after clear()
    cout << "Vector after clear(): ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
