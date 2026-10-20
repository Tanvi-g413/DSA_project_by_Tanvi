# Lab Equipment Return Tracker Using Doubly Linked List

## 1. Problem Statement

The Lab Equipment Return Tracker is designed to manage laboratory equipment records and return requests using a Doubly Linked List. Each node contains equipment details and pointers to both the previous and next nodes.

## 2. Approach

A Doubly Linked List is used to store equipment records. Each node contains the equipment ID, equipment name, quantity, a pointer to the previous node, and a pointer to the next node.

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

- Add Equipment: O(1) if inserted at the beginning or end using a suitable pointer; otherwise, it may be O(n).
- Display Equipment: O(n)
- Search Equipment: O(n)
- Delete Equipment: O(n) when searching for the equipment first
- Add Return Request: O(1)
- Process Return Request: O(1)
- Display Return Requests: O(n)
- Display Activity History: O(n)

Space Complexity: O(n)

Here, n represents the number of equipment records, return requests, and activity history entries.

## 5. Advantages

- Supports traversal in both forward and backward directions.
- Makes node deletion easier once the node is located.
- Uses a Stack to maintain activity history.
- Uses a Queue to process return requests in FIFO order.

## 6. Conclusion

The Doubly Linked List implementation provides an effective way to manage laboratory equipment records and return requests. The Stack and Queue support activity tracking and return-request processing.
