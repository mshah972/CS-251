# C++ Notes

## **Maps**

Maps in C++ are used to store key-value pairs. The keys are unique, and the values associated with each key can be accessed quickly. Maps are implemented as a red-black tree, which ensures that operations like insertion, deletion, and search have a time complexity of O(log n).

Here's an example of how to use maps in C++:

### **Declaration and Initialization**

A map can be declared and initialized using the following syntax

```c
#include<map>
using namespace std;

map<key_type, value_type> map_name;

```

Here, **`key_type`** specifies the data type of the key, and **`value_type`** specifies the data type of the value.

For example, if we want to store names and ages of people in a map, we can declare it as follows:

```c
#include<map>
using namespace std;

map<string, int> people;

// initializing map
people["Alice"] = 25;
people["Bob"] = 30;
people["Charlie"] = 35;
```

### **Insertion and Accessing Elements**

To insert a new key-value pair into the map, we can use the **`insert()`** function or the **`[]`** operator:

```c
// using insert()
people.insert(make_pair("David", 40));

// using []
people["Emily"] = 45;
```

To access the value associated with a key, we can use the **`[]`** operator:

```c
int age = people["Bob"];
```

### **Iterating through a Map**

We can use a for-each loop to iterate through a map:

```c
for (auto p : people) {
    cout << p.first << ": " << p.second << endl;
}
```

Here, **`p.first`** refers to the key, and **`p.second`** refers to the value.

---

## **Sets**

A set in C++ is an ordered collection of unique elements. The elements are stored in sorted order, and each element can be accessed quickly. Sets are implemented as a red-black tree, which ensures that operations like insertion, deletion, and search have a time complexity of O(log n).

### **Declaration and Initialization**

A set can be declared and initialized using the following syntax:

```c
#include<set>
using namespace std;

set<type> set_name;
```

Here, **`type`** specifies the data type of the elements.

For example, if we want to store a set of integers, we can declare it as follows:

```c
#include<set>
using namespace std;

set<int> numbers;

// initializing set
numbers.insert(5);
numbers.insert(3);
numbers.insert(7);
```

### **Insertion and Accessing Elements**

To insert a new element into the set, we can use the **`insert()`** function:

```c
numbers.insert(4);
```

To check if an element is present in the set, we can use the **`count()`** function:

```c
if (numbers.count(5) > 0) {
    cout << "5 is present in the set" << endl;
}
```

### **Iterating through a Set**

We can use a for-each loop to iterate through a set:

```c
for (auto x : numbers) {
    cout << x << endl;
}
```

---

## ****Vectors****

A vector in C++ is a dynamic array that can resize itself. Vectors can be used to store a collection of elements, and they support fast random access. Vectors have a time complexity of O(1) for accessing elements and O(n) for insertion and deletion at the end of the vector.

### **Declaration and Initialization**

A vector can be declared and initialized using the following syntax:

```c
vector<datatype> variable_name;
```

Here, the `datatype` refers to the data type of the elements that will be stored in the vector, and `variable_name` is the name of the vector. For example, to create a vector of integers, the following syntax can be used:

```c
std::vector<int> myvector;
```

### Adding Elements to a Vector:

To add elements to a vector, the `push_back()` function is used. The syntax for adding an element to a vector is:

```c
vector_name.push_back(element);
```

For example, to add the integer value "10" to the vector `myvector` , the following syntax can be used:

```c
myvector.push_back(10);
```

### Accessing Elements in a Vector:

Elements in a vector can be accessed using the square bracket operator `[ ]` . The syntax for accessing an element in a vector is:

```c
vector_name[index];
```

For example, to access the first element in the vector `myvector` , the following syntax can be used:

```c
myvector[0];
```

### Iterating Over a Vector:

Vectors can be iterated over using a for loop. The syntax for iterating over a vector is:

```c
for (auto it = vector_name.begin(); it != vector_name.end(); ++it)
{
    // Do something with the current element
}
```

In the above code, `it` is an iterator that points to the current element in the vector. The `begin()` function returns an iterator pointing to the first element in the vector, while the `end()` function returns an iterator pointing to the element just after the last element in the vector.

```c
vector_name.clear() // to clear the vector data
```

---

## Linked List

A linked list is a data structure that consists of a collection of nodes, each of which contains a value and a pointer to the next node in the list. Linked lists are useful for implementing dynamic data structures that can be resized during runtime.

### Creating a Linked List:

To create a linked list, a node structure must be defined first. The node structure contains the value and the pointer to the next node. The following code can be used to define a node structure:

```c
struct Node
{
    int value;
    Node* next;
};
```

Here, `value` is the value of the node, and `next` is a pointer to the next node in the list. To create a linked list, a pointer to the first node in the list (also called the `head` of the list) is needed. The following code can be used to create a linked list with one node:

```c
Node* head = new Node;
head->value = 10;
head->next = nullptr;
```

Here, `new Node` creates a new node in memory, and the pointer `head` points to this node. The value of the node is set to `10`, and the pointer `next` is set to `nullptr` (or `NULL` in older versions of C++) to indicate that there are no more nodes in the list.

```c
#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    void insert(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
```

In this example, we define a **`Node`** struct that contains an **`int`** data field and a **`Node*`** pointer to the next node in the list. We also define a **`LinkedList`** class that contains a **`head`** pointer to the first node in the list.

The **`insert`** method inserts a new node with the given value at the end of the list. If the list is empty, the new node becomes the head. Otherwise, we traverse the list to find the last node, and then append the new node to the end.

The **`display`** method prints out the data fields of all the nodes in the list, separated by spaces.

Here's an example of the main function:

```c
int main() {
    LinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.display(); // Output: 1 2 3
    return 0;
}
```

This creates a new **`LinkedList`** object, inserts three values into it, and then displays the list.

Note that this is just a simple example of a singly linked list, and there are many variations and extensions to this data structure.