# Algorithm – Lab Equipment Return Tracker Using Circular Doubly Linked List, Stack and Queue

## Step 1: Start
- Start the program.

## Step 2: Initialize Data Structures
- Initialize the circular doubly linked list with `head = NULL`.
- Initialize an empty stack `actionHistory`.
- Initialize an empty queue `returnQueue`.

## Step 3: Display Menu
Display the following menu:

1. Add Equipment
2. Display Equipment
3. Search Equipment
4. Add Return Request
5. Process Return Request
6. Delete Equipment
7. Display Action History (Stack)
8. Display Return Queue
9. Exit

## Step 4: Add Equipment
- Create a new node.
- Enter Equipment ID, Student ID, and Issue Time.
- Check whether the Equipment ID already exists.
- If it exists, display a duplicate ID message.
- Otherwise, set the status to **Issued**.
- Insert the node at the end of the circular doubly linked list.
- Push the action into the stack.

## Step 5: Display Equipment
- Check whether the list is empty.
- Traverse the circular doubly linked list starting from `head`.
- Display Equipment ID, Student ID, Issue Time, and Status.
- Stop when traversal reaches `head` again.

## Step 6: Search Equipment
- Enter the Equipment ID.
- Search for the corresponding node.
- If found, display the equipment details.
- Otherwise, display **Equipment not found**.

## Step 7: Add Return Request
- Enter the Equipment ID.
- Search for the corresponding equipment node.
- If the equipment does not exist, display an error message.
- If its status is already **Returned**, display a message.
- Otherwise, insert the Equipment ID into the queue.

## Step 8: Process Return Request
- Check whether the queue is empty.
- If empty, display **No pending return requests**.
- Otherwise, retrieve and remove the front Equipment ID.
- Search for the corresponding equipment node.
- If the node was deleted, cancel the request.
- If the equipment is already returned, skip the request.
- Otherwise, change the status to **Returned**.
- Push the return action into the stack.

## Step 9: Delete Equipment
- Enter the Equipment ID.
- Search for the corresponding node.
- If not found, display **Equipment not found**.
- Otherwise, update the `next` and `prev` pointers.
- Update `head` if the first node is deleted.
- Push the deletion action into the stack.
- Release the allocated memory.

## Step 10: Display Action History
- Check whether the stack is empty.
- If empty, display **No action history available**.
- Otherwise, display actions from the top of a temporary stack.

## Step 11: Display Return Queue
- Check whether the queue is empty.
- If empty, display **Return queue is empty**.
- Otherwise, display pending Equipment IDs in FIFO order using a temporary queue.

## Step 12: Repeat Operations
- Repeat the menu operations until the user selects **Exit**.

## Step 13: Release Memory
- Free the dynamically allocated nodes in the circular doubly linked list.

## Step 14: Stop
- Display the exit message.
- Stop the program.

