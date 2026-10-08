#include <iostream>
#include <string>
using namespace std;

struct Node {
    int equipmentID;
    int studentID;
    string issueTime;
    string status;
    Node* next;
};

Node* head = NULL;

// Add equipment record
void addEquipment() {
    Node* newNode = new Node;

    cout << "\nEnter Equipment ID: ";
    cin >> newNode->equipmentID;

    cout << "Enter Student ID: ";
    cin >> newNode->studentID;

    cout << "Enter Issue Time: ";
    cin >> newNode->issueTime;

    newNode->status = "Issued";
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
    }

    cout << "Equipment record added successfully.\n";
}

// Display all records
void displayEquipment() {
    if (head == NULL) {
        cout << "\nNo equipment records found.\n";
        return;
    }

    Node* temp = head;

    cout << "\n--- Equipment Records ---\n";

    while (temp != NULL) {
        cout << "Equipment ID : " << temp->equipmentID << endl;
        cout << "Student ID   : " << temp->studentID << endl;
        cout << "Issue Time   : " << temp->issueTime << endl;
        cout << "Status       : " << temp->status << endl;
        cout << "-------------------------\n";

        temp = temp->next;
    }
}

// Search equipment
void searchEquipment() {
    int id;
    cout << "\nEnter Equipment ID to search: ";
    cin >> id;

    Node* temp = head;

    while (temp != NULL) {
        if (temp->equipmentID == id) {
            cout << "\nEquipment Found!\n";
            cout << "Equipment ID : " << temp->equipmentID << endl;
            cout << "Student ID   : " << temp->studentID << endl;
            cout << "Issue Time   : " << temp->issueTime << endl;
            cout << "Status       : " << temp->status << endl;
            return;
        }

        temp = temp->next;
    }

    cout << "Equipment not found.\n";
}

// Update return status
void updateStatus() {
    int id;
    cout << "\nEnter Equipment ID: ";
    cin >> id;

    Node* temp = head;

    while (temp != NULL) {
        if (temp->equipmentID == id) {
            temp->status = "Returned";
            cout << "Equipment status updated to Returned.\n";
            return;
        }

        temp = temp->next;
    }

    cout << "Equipment not found.\n";
}

// Delete equipment record
void deleteEquipment() {
    int id;
    cout << "\nEnter Equipment ID to delete: ";
    cin >> id;

    Node* temp = head;
    Node* previous = NULL;

    while (temp != NULL && temp->equipmentID != id) {
        previous = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Equipment not found.\n";
        return;
    }

    if (previous == NULL)
        head = temp->next;
    else
        previous->next = temp->next;

    delete temp;

    cout << "Equipment record deleted successfully.\n";
}

int main() {
    int choice;

    do {
        cout << "\n===== LAB EQUIPMENT RETURN TRACKER =====\n";
        cout << "1. Add Equipment\n";
        cout << "2. Display Equipment\n";
        cout << "3. Search Equipment\n";
        cout << "4. Update Return Status\n";
        cout << "5. Delete Equipment\n";
        cout << "6. Exit\n";

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
                updateStatus();
                break;

            case 5:
                deleteEquipment();
                break;

            case 6:
                cout << "\nProgram terminated successfully.\n";
                break;

            default:
                cout << "\nInvalid choice! Try again.\n";
        }

    } while (choice != 6);

    return 0;
}
