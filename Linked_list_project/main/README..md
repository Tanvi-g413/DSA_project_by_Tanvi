# Lab Equipment Return Tracker Using Singly Linked List

## Problem Statement

Managing laboratory equipment records manually can be difficult and time-consuming. It becomes challenging to track which student has borrowed equipment, when it was issued, and whether it has been returned.

The objective of this project is to develop a C++ program using a Singly Linked List to manage equipment records, search for equipment, update return status, display records, and delete records efficiently.

## Approach

The project uses a Singly Linked List in which each node stores:

- Equipment ID
- Student ID
- Issue Time
- Equipment Status
- Pointer to the next node

Initially, "head = NULL". When equipment is added, a new node is created and inserted at the end of the list. The program provides menu-driven operations to display, search, update, and delete equipment records.

## Operations

1. Add Equipment
2. Display Equipment
3. Search Equipment
4. Update Return Status
5. Delete Equipment
6. Exit

## Complexity Analysis

Let "n" be the number of equipment records.

Operation| Time Complexity
Add Equipment| O(n)
Display Equipment| O(n)
Search Equipment| O(n)
Update Return Status| O(n)
Delete Equipment| O(n)
Exit| O(1)

Space Complexity: O(n), because each equipment record requires one linked-list node.

## Advantages

- Dynamic memory allocation
- Easy insertion and deletion of records
- No fixed size required
- Simple equipment tracking

## Conclusion

The Lab Equipment Return Tracker demonstrates the practical use of a Singly Linked List in C++. It allows users to add, display, search, update, and delete equipment records. The project provides a simple and efficient way to manage laboratory equipment and track return status using dynamic memory allocation.
