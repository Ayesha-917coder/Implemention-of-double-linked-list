#include <iostream>
using namespace std;

// =====================
// NODE STRUCTURE
// =====================
struct Node {
    int data;
    Node* prev;
    Node* next;
};

// HEAD POINTER
Node* head = NULL;

// =====================
// CHECK IF LIST IS EMPTY
// =====================
bool IsEmpty() {
    return (head == NULL);
}

// =====================
// INSERT NODE AT FRONT (HEAD)
// =====================
void InsertAtFront(int val) {
    // CREATE NEW NODE
    Node* newNode = new Node();
    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = head;

    // IF LIST NOT EMPTY, UPDATE PREV POINTER OF OLD HEAD
    if (head != NULL) {
        head->prev = newNode;
    }

    // MOVE HEAD TO NEW NODE
    head = newNode;

    cout << "NODE INSERTED AT FRONT" << endl;
}

// =====================
// INSERT NODE AT TAIL (END)
// =====================
void InsertAtTail(int val) {
    // CREATE NEW NODE
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = NULL;

    // IF LIST IS EMPTY
    if (IsEmpty()) {
        newNode->prev = NULL;
        head = newNode;
        cout << "NODE INSERTED AT TAIL" << endl;
        return;
    }

    Node* temp = head;

    // MOVE TO LAST NODE
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // LINK LAST NODE TO NEW NODE
    temp->next = newNode;
    newNode->prev = temp;

    cout << "NODE INSERTED AT TAIL" << endl;
}

// =====================
// INSERT NODE AT ANY INDEX
// =====================
void InsertAtAnyNode(int val, int index) {
    if (index < 1) {
        cout << "INVALID INDEX" << endl;
        return;
    }

    // INDEX = 1 MEANS INSERT AT FRONT
    if (index == 1) {
        InsertAtFront(val);
        return;
    }

    Node* temp = head;
    int pos = 1;

    // MOVE TO (INDEX - 1) POSITION
    while (temp != NULL && pos < index - 1) {
        temp = temp->next;
        pos++;
    }

    if (temp == NULL) {
        cout << "INDEX OUT OF RANGE" << endl;
        return;
    }

    // CREATE NEW NODE
    Node* newNode = new Node();
    newNode->data = val;

    // INSERTING BETWEEN NODES
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }

    temp->next = newNode;

    cout << "NODE INSERTED AT INDEX " << index << endl;
}

// =====================
// DELETE NODE FROM START
// =====================
void DeleteFromStart() {
    if (IsEmpty()) {
        cout << "LIST EMPTY" << endl;
        return;
    }

    Node* temp = head;

    // SHIFT HEAD TO NEXT NODE
    head = head->next;

    // IF LIST STILL HAS NODES
    if (head != NULL) {
        head->prev = NULL;
    }

    delete temp;

    cout << "NODE DELETED FROM START" << endl;
}

// =====================
// DELETE NODE FROM END
// =====================
void DeleteFromEnd() {
    if (IsEmpty()) {
        cout << "LIST EMPTY" << endl;
        return;
    }

    // SINGLE NODE CASE
    if (head->next == NULL) {
        delete head;
        head = NULL;
        cout << "LAST NODE DELETED" << endl;
        return;
    }

    Node* temp = head;

    // MOVE TO LAST NODE
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // DISCONNECT LAST NODE
    temp->prev->next = NULL;

    delete temp;

    cout << "NODE DELETED FROM END" << endl;
}

// =====================
// DELETE NODE FROM ANY INDEX
// =====================
void DeleteNodeFromAnyIndex(int index) {
    if (index < 1 || IsEmpty()) {
        cout << "INVALID INDEX" << endl;
        return;
    }

    // DELETE FROM INDEX 1
    if (index == 1) {
        DeleteFromStart();
        return;
    }

    Node* temp = head;
    int pos = 1;

    // MOVE TO TARGET INDEX
    while (temp != NULL && pos < index) {
        temp = temp->next;
        pos++;
    }

    if (temp == NULL) {
        cout << "INDEX OUT OF RANGE" << endl;
        return;
    }

    // CONNECT PREVIOUS AND NEXT NODES
    temp->prev->next = temp->next;

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    delete temp;

    cout << "NODE DELETED FROM INDEX " << index << endl;
}

// =====================
// PRINT THE LINKED LIST
// =====================
void PrintLinkedList() {
    if (IsEmpty()) {
        cout << "LIST IS EMPTY" << endl;
        return;
    }

    Node* temp = head;

    cout << "LINKED LIST: ";

    // TRAVERSE LIST
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

// =====================
// MAIN MENU
// =====================
int main() {
    int choice, val, index;

    while (true) {
        cout << endl;
        cout << "1. INSERT AT FRONT" << endl;
        cout << "2. INSERT AT TAIL" << endl;
        cout << "3. INSERT AT ANY INDEX" << endl;
        cout << "4. DELETE FROM START" << endl;
        cout << "5. DELETE FROM END" << endl;
        cout << "6. DELETE FROM ANY INDEX" << endl;
        cout << "7. CHECK IF EMPTY" << endl;
        cout << "8. PRINT LINKED LIST" << endl;
        cout << "9. EXIT" << endl;

        cout << "ENTER YOUR CHOICE: ";
        cin >> choice;

        if (choice == 9) break;

        switch (choice) {
        case 1:
            cout << "ENTER VALUE: ";
            cin >> val;
            InsertAtFront(val);
            break;

        case 2:
            cout << "ENTER VALUE: ";
            cin >> val;
            InsertAtTail(val);
            break;

        case 3:
            cout << "ENTER VALUE: ";
            cin >> val;
            cout << "ENTER INDEX: ";
            cin >> index;
            InsertAtAnyNode(val, index);
            break;

        case 4:
            DeleteFromStart();
            break;

        case 5:
            DeleteFromEnd();
            break;

        case 6:
            cout << "ENTER INDEX: ";
            cin >> index;
            DeleteNodeFromAnyIndex(index);
            break;

        case 7:
            if (IsEmpty()) cout << "LIST IS EMPTY" << endl;
            else cout << "LIST IS NOT EMPTY" << endl;
            break;

        case 8:
            PrintLinkedList();
            break;

        default:
            cout << "INVALID CHOICE" << endl;
        }
    }

    return 0;
}
