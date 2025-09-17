// Aniket 1024030063 2C71
// 1) Menu driven program for operations on Singly Linked List

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d): data(d), next(nullptr) {}
};

class SinglyLinkedList {
    Node* head;
public:
    SinglyLinkedList() { head = nullptr; }

    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }

    void insertBefore(int val, int beforeVal) {
        if (!head) return;
        if (head->data == beforeVal) {
            insertAtBeginning(val);
            return;
        }
        Node* prev = nullptr;
        Node* curr = head;
        while (curr && curr->data != beforeVal) {
            prev = curr;
            curr = curr->next;
        }
        if (curr) {
            Node* newNode = new Node(val);
            prev->next = newNode;
            newNode->next = curr;
        } else {
            cout << "Value " << beforeVal << " not found\n";
        }
    }

    void insertAfter(int val, int afterVal) {
        Node* curr = head;
        while (curr && curr->data != afterVal)
            curr = curr->next;
        if (curr) {
            Node* newNode = new Node(val);
            newNode->next = curr->next;
            curr->next = newNode;
        } else {
            cout << "Value " << afterVal << " not found\n";
        }
    }

    void deleteFromBeginning() {
        if (!head) {
            cout << "List is empty\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteFromEnd() {
        if (!head) {
            cout << "List is empty\n";
            return;
        }
        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        Node* prev = nullptr;
        while (temp->next) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = nullptr;
        delete temp;
    }

    void deleteNode(int val) {
        if (!head) {
            cout << "List is empty\n";
            return;
        }
        if (head->data == val) {
            deleteFromBeginning();
            return;
        }
        Node* temp = head;
        Node* prev = nullptr;
        while (temp && temp->data != val) {
            prev = temp;
            temp = temp->next;
        }
        if (!temp) {
            cout << "Value " << val << " not found\n";
            return;
        }
        prev->next = temp->next;
        delete temp;
    }

    int search(int val) {
        Node* temp = head;
        int pos = 1;
        while (temp) {
            if (temp->data == val) return pos;
            temp = temp->next;
            pos++;
        }
        return -1;
    }

    void display() {
        if (!head) {
            cout << "List is empty\n";
            return;
        }
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    SinglyLinkedList list;
    int choice, val, val2;
    while (true) {
        cout << "1.Insert at beginning\n2.Insert at end\n3.Insert before a node\n4.Insert after a node\n5.Delete from beginning\n6.Delete from end\n7.Delete specific node\n8.Search\n9.Display\n10.Exit\nChoice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value: "; cin >> val;
                list.insertAtBeginning(val);
                break;
            case 2:
                cout << "Enter value: "; cin >> val;
                list.insertAtEnd(val);
                break;
            case 3:
                cout << "Enter value to insert: "; cin >> val;
                cout << "Enter value before which to insert: "; cin >> val2;
                list.insertBefore(val, val2);
                break;
            case 4:
                cout << "Enter value to insert: "; cin >> val;
                cout << "Enter value after which to insert: "; cin >> val2;
                list.insertAfter(val, val2);
                break;
            case 5:
                list.deleteFromBeginning();
                break;
            case 6:
                list.deleteFromEnd();
                break;
            case 7:
                cout << "Enter value to delete: "; cin >> val;
                list.deleteNode(val);
                break;
            case 8:
                cout << "Enter value to search: "; cin >> val;
                val2 = list.search(val);
                if (val2 == -1)
                    cout << "Not found\n";
                else
                    cout << "Found at position " << val2 << "\n";
                break;
            case 9:
                list.display();
                break;
            case 10:
                return 0;
            default:
                cout << "Invalid choice\n";
        }
    }
}

/*
Sample Output:
1.Insert at beginning
2.Insert at end
3.Insert before a node
4.Insert after a node
5.Delete from beginning
6.Delete from end
7.Delete specific node
8.Search
9.Display
10.Exit
Choice: 1
Enter value: 10
Choice: 2
Enter value: 20
Choice: 4
Enter value to insert: 15
Enter value after which to insert: 10
Choice: 9
10 -> 15 -> 20 -> NULL
Choice: 8
Enter value to search: 15
Found at position 2
Choice: 7
Enter value to delete: 15
Choice: 9
10 -> 20 -> NULL
Choice: 10
*/
