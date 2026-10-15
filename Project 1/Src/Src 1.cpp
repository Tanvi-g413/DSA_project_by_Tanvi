#include <iostream>
#include <string>
#include <stack>
#include <queue>
using namespace std;

struct Equipment {
    int id;
    string name;
    int quantity;
    Equipment* prev;
    Equipment* next;
};

class LabEquipmentTracker {
private:
    Equipment* head;
    Equipment* tail;
    stack<string> history;
    queue<int> returnQueue;

public:
    LabEquipmentTracker() {
        head = nullptr;
        tail = nullptr;
    }

    // Add equipment to Doubly Linked List
    void addEquipment(int id, string name, int quantity) {
        Equipment* newNode = new Equipment;
        newNode->id = id;
        newNode->name = name;
        newNode->quantity = quantity;
        newNode->prev = nullptr;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }

        history.push("Added equipment: " + name);
        cout << "Equipment added successfully!\n";
    }

    // Display equipment from first to last
    void displayForward() {
        if (head == nullptr) {
            cout << "No equipment records available.\n";
            return;
        }

        Equipment* temp = head;
        cout << "\n--- Equipment Records (Forward) ---\n";

        while (temp != nullptr) {
            cout << "ID: " << temp->id
                 << " | Name: " << temp->name
                 << " | Quantity: " << temp->quantity << '\n';
            temp = temp->next;
        }
    }

    // Display equipment from last to first
    void displayBackward() {
        if (tail == nullptr) {
            cout << "No equipment records available.\n";
            return;
        }

        Equipment* temp = tail;
        cout << "\n--- Equipment Records (Backward) ---\n";

        while (temp != nullptr) {
            cout << "ID: " << temp->id
                 << " | Name: " << temp->name
                 << " | Quantity: " << temp->quantity << '\n';
            temp = temp->prev;
        }
    }

    // Search equipment by ID
    void searchEquipment(int id) {
        Equipment* temp = head;

        while (temp != nullptr) {
            if (temp->id == id) {
                cout << "Equipment found!\n";
                cout << "ID: " << temp->id
                     << " | Name: " << temp->name
                     << " | Quantity: " << temp->quantity << '\n';
                return;
            }
            temp = temp->next;
        }

        cout << "Equipment not found.\n";
    }

    // Delete equipment by ID
    void deleteEquipment(int id) {
        Equipment* temp = head;

        while (temp != nullptr && temp->id != id) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Equipment not found.\n";
            return;
        }

        string deletedName = temp->name;

        if (temp == head) {
            head = temp->next;
        }

        if (temp == tail) {
            tail = temp->prev;
        }

        if (temp->prev != nullptr) {
            temp->prev->next = temp->next;
        }

        if (temp->next != nullptr) {
            temp->next->prev = temp->prev;
        }

        delete temp;

        history.push("Deleted equipment: " + deletedName);
        cout << "Equipment deleted successfully!\n";
    }

    // Add return request to Queue
    void addReturnRequest(int id) {
        returnQueue.push(id);
        cout << "Return request added to queue.\n";
    }

    // Process the oldest return request
    void processReturnRequest() {
        if (returnQueue.empty()) {
            cout << "No pending return requests.\n";
            return;
        }

        int id = returnQueue.front();
        returnQueue.pop();

        history.push("Processed return request for equipment ID: "
                     + to_string(id));

        cout << "Processed return request for equipment ID: "
             << id << '\n';
    }

    // Display pending return requests
    void displayReturnRequests() {
        if (returnQueue.empty()) {
            cout << "No pending return requests.\n";
            return;
        }

        queue<int> temp = returnQueue;

        cout << "\n--- Pending Return Requests ---\n";
        while (!temp.empty()) {
            cout << "Equipment ID: " << temp.front() << '\n';
            temp.pop();
        }
    }

    // Display recent activity history
    void displayHistory() {
        if (history.empty()) {
            cout << "No activity history available.\n";
            return;
        }

        stack<string> temp = history;

        cout << "\n--- Recent Activity History ---\n";
        while (!temp.empty()) {
            cout << temp.top() << '\n';
            temp.pop();
        }
    }

    // Menu-driven program
    void menu() {
        int choice, id, quantity;
        string name;

        do {
            cout << "\n===== LAB EQUIPMENT RETURN TRACKER =====\n";
            cout << "1. Add Equipment\n";
            cout << "2. Display Equipment Forward\n";
            cout << "3. Display Equipment Backward\n";
            cout << "4. Search Equipment\n";
            cout << "5. Delete Equipment\n";
            cout << "6. Add Return Request\n";
            cout << "7. Process Return Request\n";
            cout << "8. Display Return Requests\n";
            cout << "9. Display Activity History\n";
            cout << "10. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    cout << "Enter equipment ID: ";
                    cin >> id;

                    cout << "Enter equipment name: ";
                    getline(cin >> ws, name);

                    cout << "Enter quantity: ";
                    cin >> quantity;

                    if (quantity <= 0) {
                        cout << "Quantity must be positive.\n";
                        break;
                    }

                    addEquipment(id, name, quantity);
                    break;

                case 2:
                    displayForward();
                    break;

                case 3:
                    displayBackward();
                    break;

                case 4:
                    cout << "Enter equipment ID to search: ";
                    cin >> id;
                    searchEquipment(id);
                    break;

                case 5:
                    cout << "Enter equipment ID to delete: ";
                    cin >> id;
                    deleteEquipment(id);
                    break;

                case 6:
                    cout << "Enter equipment ID for return request: ";
                    cin >> id;
                    addReturnRequest(id);
                    break;

                case 7:
                    processReturnRequest();
                    break;

                case 8:
                    displayReturnRequests();
                    break;

                case 9:
                    displayHistory();
                    break;

                case 10:
                    cout << "Exiting program. Thank you!\n";
                    break;

                default:
                    cout << "Invalid choice. Please try again.\n";
            }

        } while (choice != 10);
    }

    // Free dynamically allocated memory
    ~LabEquipmentTracker() {
        Equipment* temp = head;

        while (temp != nullptr) {
            Equipment* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
    }
};

int main() {
    LabEquipmentTracker tracker;
    tracker.menu();
    return 0;
}
