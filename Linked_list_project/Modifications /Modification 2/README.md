# Lab Equipment Return Tracker Using Circular Linked List

## 1. Problem Statement

The Lab Equipment Return Tracker is designed to manage laboratory equipment records and return requests using a Circular Linked List. In this structure, the last node points back to the first node, forming a circle.

## 2. Approach

A Circular Linked List is used to store equipment records. Each node contains the equipment ID, equipment name, and quantity. A pointer to the last node helps manage the circular structure.

A Stack is used to maintain activity history, and a Queue is used to manage equipment return requests.

## 3. Operations

- Add Equipment
- Display Equipment
- Search Equipment
- Delete Equipment
- Add Return Request
- Process Return Request
- Display Pending Return Requests
- Display Activity History
- Exit

## 4. Complexity Analysis

- Add Equipment: O(1) when using a last pointer
- Display Equipment: O(n)
- Search Equipment: O(n)
- Delete Equipment: O(n)
- Add Return Request: O(1)
- Process Return Request: O(1)
- Display Return Requests: O(n)
- Display Activity History: O(n)

Space Complexity: O(n)

Here, n represents the number of equipment records, return requests, and activity history entries.

## 5. Advantages

- The last node points back to the first node.
- Supports continuous traversal through the list.
- Adding equipment can be performed in O(1) time when a last pointer is maintained.
- Uses a Stack for activity history and a Queue for return requests.

## 6. Conclusion

The Circular Linked List implementation provides a convenient way to manage laboratory equipment records. The circular structure supports continuous traversal, while the Stack and Queue handle activity history and return requests.
