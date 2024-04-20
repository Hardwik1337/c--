# Set Template Class

This repository contains a C++ template class implementation for a Set data structure. A Set is a collection of distinct elements, where each element occurs only once within the collection.

## Features

- **Generic**: The Set class is implemented using templates, allowing it to hold elements of any data type.
- **Dynamic Memory Management**: The class dynamically manages memory for the elements to accommodate variable sizes.
- **Basic Set Operations**: Supports typical set operations such as addition, removal, checking containment, clearing, union, intersection, and difference.

## Usage

To use the Set class, follow these steps:

1. **Include the Header File**: Include the `Set.h` header file in your C++ source files.
2. **Instantiate Set Objects**: Create Set objects for the desired data types using the template syntax, e.g., `Set<int> intSet;`.
3. **Perform Set Operations**: Use the available member functions to perform set operations such as adding elements (`add()`), removing elements (`remove()`), checking containment (`contains()`), etc.
4. **Customize Output**: Utilize the overloaded `operator<<` to print the set contents.

## Example

```cpp
#include <iostream>
#include "Set.h"

using namespace std;

int main() {
    // Create Set1
    Set<int> set1;
    set1.add(1);
    set1.add(2);
    set1.add(3);
    cout << "Set1: " << set1 << "\n";

    // Create Set2
    Set<int> set2;
    set2.add(2);
    set2.add(3);
    set2.add(4);
    cout << "Set2: " << set2 << "\n";

    // Connect Set1 and Set2
    Set<int> connectSet = set1.connectSet(set2);
    cout << "Set1 <3 Set2: " << connectSet << "\n";

    // Find the Intersection of Set1 and Set2
    Set<int> intersectionSet = set1.intersection(set2);
    cout << "Intersection: " << intersectionSet << "\n";

    // Find the Difference between Set1 and Set2
    Set<int> differenceSet = set1.difference(set2);
    cout << "Difference: " << differenceSet << "\n";
    
    // Find the Difference between Set2 and Set1
    Set<int> differenceSet2 = set2.difference(set1);
    cout << "Difference: " << differenceSet2 << "\n";

    return 0;
}


