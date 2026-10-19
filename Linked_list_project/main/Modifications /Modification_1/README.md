# Lab Equipment Return Tracker Using Doubly Linked List

## 1. Problem Statement

The Lab Equipment Return Tracker is a menu-driven C++ application developed to manage laboratory equipment records using a Doubly Linked List. Each node stores the Equipment ID, Student ID, Issue Time, Status, and pointers to the previous and next nodes. The system allows users to add, display, search, update the return status, and delete equipment records efficiently.

## 2. Approach

- Create a node containing Equipment ID, Student ID, Issue Time, Status, a previous pointer ("prev"), and a next pointer ("next").
- Initialize "head = NULL" and "tail = NULL".
- Add new equipment records at the end of the doubly linked list.
- Traverse the list to display all equipment records.
- Search for equipment using its Equipment ID.
- Update the status to Returned when the equipment is returned.
- Delete the required node by updating the previous and next pointers.
- Release the allocated memory after deleting a node.
- Repeat the menu operations until the user selects Exit.

## 3. Operations

1. Add Equipment
2. Display Equipment
3. Search Equipment
4. Update Return Status
5. Delete Equipment
6. Exit

## 4. Complexity Analysis

Operation| Time Complexity
Add Equipment| O(1) if using the tail pointer
Display Equipment| O(n)
Search Equipment| O(n)
Update Return Status| O(n)
Delete Equipment| O(n)

Space Complexity: O(n), where n is the number of equipment records.

## 5. Advantages

- Supports insertion and deletion using both previous and next pointers.
- Makes it easier to access the previous node during deletion.
- Dynamically manages equipment records.
- Helps maintain and track equipment return status.

## 6. Conclusion

The Lab Equipment Return Tracker demonstrates the practical implementation of a Doubly Linked List in C++. It provides operations to manage equipment records, search for equipment, update return status, and delete records. The use of both "prev" and "next" pointers makes list navigation and node management more flexible.
