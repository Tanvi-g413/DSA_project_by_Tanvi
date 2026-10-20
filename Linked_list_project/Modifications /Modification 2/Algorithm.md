# Algorithm – Lab Equipment Return Tracker Using Circular Linked List, Stack, and Queue

## Step 1

Start the program.

## Step 2

Initialize the circular linked list with `last = nullptr`, and initialize an empty Stack and Queue.

## Step 3

Display the following menu:

* Add Equipment

* Display Equipment

* Search Equipment

* Delete Equipment

* Add Return Request

* Process Return Request

* Display Return Requests

* Display Activity History

* Exit

## Step 4 – Add Equipment

* Create a new node.

* Enter Equipment ID, Equipment Name, and Quantity.

* If the list is empty, make the new node point to itself and set `last` to the new node.

* Otherwise, insert the new node at the end of the circular linked list.

* Update the links so the last node points to the first node.

* Push the add action into the Stack.

## Step 5 – Display Equipment

* Check whether the circular linked list is empty.

* If empty, display No equipment records available.

* Otherwise, start traversal from `last->next`.

* Display each equipment record.

* Stop when traversal reaches the first node again.

## Step 6 – Search Equipment

* Enter the Equipment ID.

* Traverse the circular linked list starting from `last->next`.

* If the ID matches, display the equipment details.

* Otherwise, display Equipment not found.

## Step 7 – Delete Equipment

* Enter the Equipment ID.

* Search for the corresponding node and its previous node.

* Update the links to remove the node from the circular linked list.

* Update `last` if the last node is deleted.

* Release the allocated memory.

* Push the delete action into the Stack.

## Step 8 – Add Return Request

* Enter the Equipment ID.

* Insert the ID into the Queue.

* Display Return request added to queue.

## Step 9 – Process Return Request

* Check whether the Queue is empty.

* If empty, display No pending return requests.

* Otherwise, remove the oldest request from the Queue.

* Push the processed request action into the Stack.

* Display the processed equipment ID.

## Step 10 – Display Return Requests

* Check whether the Queue is empty.

* If empty, display No pending return requests.

* Otherwise, copy the Queue and display all pending return requests in FIFO order.

## Step 11 – Display Activity History

* Check whether the Stack is empty.

* If empty, display No activity history available.

* Otherwise, copy the Stack and display recent activities in LIFO order.

## Step 12

Repeat the menu operations until the user selects Exit.

## Step 13

Release the memory allocated to all nodes in the circular linked list.

## Step 14

Stop the program.

Note: In your current C++ program, return requests are processed from the Queue, but equipment quantities and return statuses are not updated automatically.
