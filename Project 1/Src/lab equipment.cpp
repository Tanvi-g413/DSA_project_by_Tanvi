#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <sstream>
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

// Convert integer to string for older compilers
string numberToString(int number) {
    stringstream ss;
    ss << number;
    return ss.str();
}

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
        "Added equipment " +
        numberToString(newNode->equipmentID)
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
        cout << "Equipment ID: " << temp->equipmentID << "\n";
        cout << "Student ID: " << temp->studentID << "\n";
        cout << "Issue Time: " << temp->issueTime << "\n";
        cout << "Status: " << temp->status << "\n";
    } else {
        cout << "Equipment not found.\n";
    }
}

// Add return request to queue
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

// Process the oldest return request
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
        "Returned equipment " + numberToString(id)
    );

    cout << "Equipment " << id
         << " returned successfully.\n";
}

// Delete equipment record
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
        "Deleted equipment " + numberToString(id)
    );

    delete temp;

    cout << "Equipment deleted successfully.\n";
}

// Display action history using stack
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

// Display pending return requests
void displayReturnQueue() {
    if (returnQueue.empty()) {
        cout << "Return queue is empty.\n";
        return;
    }

    queue<int> temp = returnQueue;

    cout << "\n--- Return Queue (FIFO) ---\n";

    while (!temp.empty()) {
        cout << "Equipment ID: "
             << temp.front() << "\n";
        temp.pop();
    }
}

// Release linked-list memory
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
