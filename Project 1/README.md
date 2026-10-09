Lab Equipment Return Tracker

Title

Lab Equipment Return Tracker Using Circular Doubly Linked List, Stack and Queue

---

Problem Statement

Implement a lab equipment management system using a circular doubly linked list, stack, and queue to maintain records of laboratory equipment issued to students. Each equipment record stores the equipment ID, student ID, issue time, and return status.

The system should allow users to add, display, and search equipment records, manage return requests in a queue, process requests in FIFO order, delete equipment records, and maintain action history using a stack.

---

Objective

- To develop a laboratory equipment management system using a circular doubly linked list.
- To maintain equipment details issued to students.
- To perform insertion, deletion, searching, and display operations.
- To manage equipment return requests using a queue.
- To process return requests according to the FIFO principle.
- To maintain action history using a stack following the LIFO principle.
- To understand pointers, dynamic memory allocation, and linked-list operations.
- To demonstrate the practical applications of multiple data structures in one project.

---

Algorithm

1. Start the program.
2. Initialize "head = NULL", an empty stack, and an empty queue.
3. Display the menu:
   - Add Equipment
   - Display Equipment
   - Search Equipment
   - Add Return Request
   - Process Return Request
   - Delete Equipment
   - Display Action History
   - Display Return Queue
   - Exit
4. If Add Equipment is selected:
   - Enter Equipment ID, Student ID, and Issue Time.
   - Check whether the Equipment ID already exists.
   - Create a new node and set its status to "Issued".
   - Insert the node into the circular doubly linked list.
   - Push the action into the stack.
5. If Display Equipment is selected:
   - Check whether the list is empty.
   - Traverse the circular doubly linked list.
   - Display all equipment records.
6. If Search Equipment is selected:
   - Enter the Equipment ID.
   - Search the linked list.
   - Display the equipment details if found; otherwise, display an error message.
7. If Add Return Request is selected:
   - Enter the Equipment ID.
   - Check whether the equipment exists and has not already been returned.
   - Add the Equipment ID to the return queue.
8. If Process Return Request is selected:
   - Check whether the queue is empty.
   - Remove the oldest request from the front of the queue.
   - Search for the equipment.
   - Cancel the request if the equipment was deleted, or skip it if already returned.
   - Otherwise, update its status to "Returned" and push the action into the stack.
9. If Delete Equipment is selected:
   - Enter the Equipment ID and search for the node.
   - Update the previous and next pointers.
   - Update "head" if necessary.
   - Delete the node and push the action into the stack.
10. If Display Action History is selected:
    - Copy the stack.
    - Display the actions from newest to oldest without changing the original stack.
11. If Display Return Queue is selected:
    - Copy the queue.
    - Display pending return requests in FIFO order without changing the original queue.
12. Repeat the menu until the user selects Exit.
13. Release the linked-list memory and stop the program.

---

Flowchart

flowchart TD
    A([START]) --> B[Initialize Head, Stack and Queue]
    B --> C[Display Menu]
    C --> D[Enter Choice]
    D --> E{Choice?}

    E -->|1| F[Enter Equipment Details]
    F --> G[Create New Node]
    G --> H{Duplicate ID?}
    H -->|Yes| I[Display Duplicate ID Message]
    I --> C
    H -->|No| J[Insert into Circular Doubly Linked List]
    J --> K[Push Action into Stack]
    K --> C

    E -->|2| L[Traverse Linked List]
    L --> M[Display Equipment Records]
    M --> C

    E -->|3| N[Enter Equipment ID]
    N --> O[Search Equipment]
    O --> P[Display Search Result]
    P --> C

    E -->|4| Q[Enter Equipment ID for Return]
    Q --> R[Check Equipment and Status]
    R --> S[Add Request to Queue if Valid]
    S --> C

    E -->|5| T[Check Return Queue]
    T --> U[Remove Oldest Request]
    U --> V[Search Equipment]
    V --> W[Update Status to Returned]
    W --> X[Push Action into Stack]
    X --> C

    E -->|6| Y[Search Equipment to Delete]
    Y --> Z[Update Previous and Next Links]
    Z --> AA[Delete Node and Record Action]
    AA --> C

    E -->|7| AB[Copy Stack and Display History]
    AB --> C

    E -->|8| AC[Copy Queue and Display Requests]
    AC --> C

    E -->|9| AD[Free Linked List Memory]
    AD --> AE([STOP])

    E -->|Invalid| AF[Display Invalid Choice]
    AF --> C

---

Program

C++ Implementation

#include <iostream>
#include <string>
#include <stack>
#include <queue>
using namespace std;

struct Node {
    int equipmentID;
    int studentID;
    string issueTime;
    string status;
    Node* next;
    Node* prev;
};

Node* head = NULL;

stack<string> actionHistory;
queue<int> returnQueue;

// Search for equipment
Node* findEquipment(int id) {
    if (head == NULL)
        return NULL;

    Node* temp = head;

    do {
        if (temp->equipmentID == id)
            return temp;

        temp = temp->next;
    } while (temp != head);

    return NULL;
}

// Add equipment
void addEquipment() {
    Node* newNode = new Node;

    cout << "Enter Equipment ID: ";
    cin >> newNode->equipmentID;

    if (findEquipment(newNode->equipmentID) != NULL) {
        cout << "Equipment ID already exists!\n";
        delete newNode;
        return;
    }

    cout << "Enter Student ID: ";
    cin >> newNode->studentID;

    cout << "Enter Issue Time: ";
    cin >> newNode->issueTime;

    newNode->status = "Issued";

    if (head == NULL) {
        head = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
    } else {
        Node* last = head->prev;

        newNode->next = head;
        newNode->prev = last;
        last->next = newNode;
        head->prev = newNode;
    }

    actionHistory.push(
        "Added equipment " + to_string(newNode->equipmentID)
    );

    cout << "Equipment added successfully!\n";
}

// Display all equipment
void displayEquipment() {
    if (head == NULL) {
        cout << "No equipment records found.\n";
        return;
    }

    Node* temp = head;

    cout << "\n--- Equipment Records ---\n";

    do {
        cout << "Equipment ID: " << temp->equipmentID
             << "\nStudent ID: " << temp->studentID
             << "\nIssue Time: " << temp->issueTime
             << "\nStatus: " << temp->status << "\n\n";

        temp = temp->next;
    } while (temp != head);
}

// Search equipment
void searchEquipment() {
    int id;

    cout << "Enter Equipment ID to search: ";
    cin >> id;

    Node* temp = findEquipment(id);

    if (temp != NULL) {
        cout << "Equipment found!\n";
        cout << "Student ID: " << temp->studentID << "\n";
        cout << "Issue Time: " << temp->issueTime << "\n";
        cout << "Status: " << temp->status << "\n";
    } else {
        cout << "Equipment not found.\n";
    }
}

// Add return request
void addReturnRequest() {
    int id;

    cout << "Enter Equipment ID for return: ";
    cin >> id;

    Node* temp = findEquipment(id);

    if (temp == NULL) {
        cout << "Equipment not found.\n";
    } else if (temp->status == "Returned") {
        cout << "Equipment is already returned.\n";
    } else {
        returnQueue.push(id);
        cout << "Return request added to queue.\n";
    }
}

// Process return request
void processReturnRequest() {
    if (returnQueue.empty()) {
        cout << "No pending return requests.\n";
        return;
    }

    int id = returnQueue.front();
    returnQueue.pop();

    Node* temp = findEquipment(id);

    if (temp == NULL) {
        cout << "Equipment " << id
             << " was deleted. Request cancelled.\n";
        return;
    }

    if (temp->status == "Returned") {
        cout << "Equipment " << id
             << " is already returned. Request skipped.\n";
        return;
    }

    temp->status = "Returned";

    actionHistory.push(
        "Returned equipment " + to_string(id)
    );

    cout << "Equipment " << id
         << " returned successfully.\n";
}

// Delete equipment
void deleteEquipment() {
    int id;

    cout << "Enter Equipment ID to delete: ";
    cin >> id;

    Node* temp = findEquipment(id);

    if (temp == NULL) {
        cout << "Equipment not found.\n";
        return;
    }

    if (temp->next == temp) {
        head = NULL;
    } else {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;

        if (temp == head)
            head = temp->next;
    }

    actionHistory.push(
        "Deleted equipment " + to_string(id)
    );

    delete temp;

    cout << "Equipment deleted successfully.\n";
}

// Display action history
void displayActionHistory() {
    if (actionHistory.empty()) {
        cout << "No action history available.\n";
        return;
    }

    stack<string> temp = actionHistory;

    cout << "\n--- Action History (Latest First) ---\n";

    while (!temp.empty()) {
        cout << temp.top() << "\n";
        temp.pop();
    }
}

// Display return queue
void displayReturnQueue() {
    if (returnQueue.empty()) {
        cout << "Return queue is empty.\n";
        return;
    }

    queue<int> temp = returnQueue;

    cout << "\n--- Return Queue (FIFO) ---\n";

    while (!temp.empty()) {
        cout << "Equipment ID: " << temp.front() << "\n";
        temp.pop();
    }
}

// Free linked-list memory
void cleanup() {
    if (head == NULL)
        return;

    Node* current = head->next;

    while (current != head) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }

    delete head;
    head = NULL;
}

int main() {
    int choice;

    do {
        cout << "\n===== LAB EQUIPMENT RETURN TRACKER =====\n";
        cout << "1. Add Equipment\n";
        cout << "2. Display Equipment\n";
        cout << "3. Search Equipment\n";
        cout << "4. Add Return Request\n";
        cout << "5. Process Return Request\n";
        cout << "6. Delete Equipment\n";
        cout << "7. Display Action History (Stack)\n";
        cout << "8. Display Return Queue\n";
        cout << "9. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addEquipment();
                break;

            case 2:
                displayEquipment();
                break;

            case 3:
                searchEquipment();
                break;

            case 4:
                addReturnRequest();
                break;

            case 5:
                processReturnRequest();
                break;

            case 6:
                deleteEquipment();
                break;

            case 7:
                displayActionHistory();
                break;

            case 8:
                displayReturnQueue();
                break;

            case 9:
                cleanup();
                cout << "Exiting program. Thank you!\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 9);

    return 0;
}

---

Sample Output

The following is a sample console session demonstrating all menu choices. The values are illustrative.

===== LAB EQUIPMENT RETURN TRACKER =====
1. Add Equipment
2. Display Equipment
3. Search Equipment
4. Add Return Request
5. Process Return Request
6. Delete Equipment
7. Display Action History (Stack)
8. Display Return Queue
9. Exit

Enter your choice: 1
Enter Equipment ID: 101
Enter Student ID: 205
Enter Issue Time: 10AM
Equipment added successfully!

Enter your choice: 1
Enter Equipment ID: 102
Enter Student ID: 218
Enter Issue Time: 11AM
Equipment added successfully!

Enter your choice: 2

--- Equipment Records ---
Equipment ID: 101
Student ID: 205
Issue Time: 10AM
Status: Issued

Equipment ID: 102
Student ID: 218
Issue Time: 11AM
Status: Issued

Enter your choice: 3
Enter Equipment ID to search: 101
Equipment found!
Student ID: 205
Issue Time: 10AM
Status: Issued

Enter your choice: 4
Enter Equipment ID for return: 101
Return request added to queue.

Enter your choice: 4
Enter Equipment ID for return: 102
Return request added to queue.

Enter your choice: 8

--- Return Queue (FIFO) ---
Equipment ID: 101
Equipment ID: 102

Enter your choice: 5
Equipment 101 returned successfully.

Enter your choice: 7

--- Action History (Latest First) ---
Returned equipment 101
Added equipment 102
Added equipment 101

Enter your choice: 6
Enter Equipment ID to delete: 102
Equipment deleted successfully.

Enter your choice: 2

--- Equipment Records ---
Equipment ID: 101
Student ID: 205
Issue Time: 10AM
Status: Returned

Enter your choice: 8

--- Return Queue (FIFO) ---
Equipment ID: 102

Enter your choice: 5
Equipment 102 was deleted. Request cancelled.

Enter your choice: 7

--- Action History (Latest First) ---
Deleted equipment 102
Returned equipment 101
Added equipment 102
Added equipment 101

Enter your choice: 9
Exiting program. Thank you!

---

Data Structures Used

1. Circular Doubly Linked List

Each node contains:

- Equipment ID
- Student ID
- Issue Time
- Return Status
- Pointer to the next node ("next")
- Pointer to the previous node ("prev")

The last node points forward to the head, and the head points backward to the last node.

2. Stack

The stack stores action history, such as adding, returning, and deleting equipment.

- Principle: LIFO — Last In, First Out.
- The latest action is displayed first.

3. Queue

The queue stores equipment return requests.

- Principle: FIFO — First In, First Out.
- The oldest return request is processed first.

---

Operations Performed

Operation| Description
Insertion| Adds a new equipment record to the circular doubly linked list
Traversal| Displays all equipment records
Searching| Finds equipment using its ID
Return Request| Adds an equipment ID to the queue
Return Processing| Processes the oldest request and updates status
Deletion| Removes an equipment record
Stack Operation| Stores and displays action history
Queue Operation| Maintains pending return requests

---

Time Complexity

Let "n" be the number of equipment records, "a" the number of recorded actions, and "r" the number of pending return requests.

Operation| Time Complexity
Add Equipment| O(n), due to duplicate checking
Display Equipment| O(n)
Search Equipment| O(n)
Add Return Request| O(n), due to searching
Process Return Request| O(n), due to searching
Delete Equipment| O(n), due to searching
Display Action History| O(a)
Display Return Queue| O(r)

---

Advantages

- Maintains equipment records dynamically.
- Supports forward and backward traversal.
- Detects duplicate equipment IDs when adding records.
- Processes return requests in FIFO order.
- Stores recent actions using a stack.
- Supports insertion and deletion without shifting other records.
- Demonstrates the combined use of three data structures.

---

Limitations

- Searching requires traversing the linked list.
- Data is not saved permanently after the program exits.
- The program uses console-based input and output.
- Duplicate pending return requests are not prevented.

---

Applications

- College laboratory equipment management.
- Tracking equipment issued to students.
- Managing equipment return requests.
- Maintaining a history of equipment-related actions.
- Understanding linked lists, stacks, and queues through a practical project.

---

Conclusion

The Lab Equipment Return Tracker was implemented in C++ using a circular doubly linked list, stack, and queue. The circular doubly linked list manages equipment records, the queue processes return requests in FIFO order, and the stack maintains action history in LIFO order.

This project demonstrates insertion, traversal, searching, deletion, return processing, pointer handling, and dynamic memory management. It provides practical experience in combining multiple data structures to solve a real-world laboratory management problem.

---

Project Structure

Lab-Equipment-Return-Tracker/
│
├── Algorithm/
│   └── README.md
│
├── Output/
│   └── README.md
│
├── Src/
│   └── main.cpp
│
├── Flowchart/
│   └── README.md
│
└── README.md

---

Technologies Used

- Programming Language: C++
- Data Structures: Circular Doubly Linked List, Stack, Queue
- IDE: Any C++ compatible IDE
- Version Control: GitHub
