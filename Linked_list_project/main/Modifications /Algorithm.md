# Algorithm – Lab Equipment Return Tracker Using Doubly Linked List, Stack, and Queue

## Step 1: Start the Program

Start the Lab Equipment Return Tracker program.

## Step 2: Initialize Data Structures

Initialize the doubly linked list with `head = nullptr` and `tail = nullptr`. Initialize an empty stack for activity history and an empty queue for return requests.

## Step 3: Display the Main Menu

Display the following menu:

1. Add Equipment
2. Display Equipment Forward
3. Display Equipment Backward
4. Search Equipment
5. Delete Equipment
6. Add Return Request
7. Process Return Request
8. Display Return Requests
9. Display Activity History
10. Exit

## Step 4: Read User Choice

Accept the user's menu choice and perform the corresponding operation.

## Step 5: Add Equipment

Accept the equipment ID, name, and quantity. Check whether the quantity is positive. Create a new node and insert it at the end of the doubly linked list. Record the activity in the stack.

## Step 6: Display Equipment Forward

Start from `head` and traverse the list using the `next` pointer. Display each equipment record until `nullptr` is reached.

## Step 7: Display Equipment Backward

Start from `tail` and traverse the list using the `prev` pointer. Display each equipment record in reverse order until `nullptr` is reached.

## Step 8: Search Equipment

Accept an equipment ID and search the list from `head`. If the ID is found, display the equipment details. Otherwise, display "Equipment not found."

## Step 9: Delete Equipment

Search for the equipment ID. If found, update the previous and next pointers to remove the node. Update `head` or `tail` when necessary, delete the node, and record the activity in the stack.

## Step 10: Add Return Request

Accept the equipment ID and insert it into the return queue.

## Step 11: Process Return Request

If the queue is not empty, remove and process the oldest return request. Record the activity in the stack.

## Step 12: Display Return Requests

Display all pending return requests without removing them from the queue.

## Step 13: Display Activity History

If the stack is not empty, display activities from the most recent to the oldest.

## Step 14: Repeat or Exit

If the user does not select Exit, return to the main menu. Otherwise, terminate the program and release the dynamically allocated memory.

## Conclusion

The Lab Equipment Return Tracker uses a doubly linked list to manage equipment, a stack to maintain activity history, and a queue to process return requests in First In, First Out (FIFO) order.
