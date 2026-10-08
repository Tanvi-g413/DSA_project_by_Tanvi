# Algorithm – Lab Equipment Return Tracker

### Step 1
Start the program.

### Step 2
Initialize the linked list with `head = NULL`.

### Step 3
Display the following menu:

1. Add Equipment
2. Display Equipment
3. Search Equipment
4. Update Return Status
5. Delete Equipment
6. Exit

### Step 4 – Add Equipment
- Create a new node.
- Enter Equipment ID, Student ID, and Issue Time.
- Set the status as **Issued**.
- Insert the node at the end of the linked list.

### Step 5 – Display Equipment
- Traverse the linked list from `head` to `NULL`.
- Display all equipment records.

### Step 6 – Search Equipment
- Enter the Equipment ID.
- Traverse the linked list.
- If the ID matches, display the equipment details.
- Otherwise, display **Equipment not found**.

### Step 7 – Update Return Status
- Enter the Equipment ID.
- Search for the corresponding node.
- Change its status to **Returned**.

### Step 8 – Delete Equipment
- Enter the Equipment ID.
- Search for the corresponding node.
- Remove the node from the linked list.
- Release the allocated memory.

### Step 9
Repeat the menu operations until the user selects **Exit**.

### Step 10
Stop the program.
