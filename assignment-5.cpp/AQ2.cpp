// Aniket 1024030063 2C71
// 2) Count and delete all occurrences of a key in singly linked list
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d): data(d), next(nullptr) {}
};

class LinkedList {
    Node* head;
public:
    LinkedList() { head = nullptr; }

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

    int countOccurrences(int key) {
        int count = 0;
        Node* temp = head;
        while (temp) {
            if (temp->data == key)
                count++;
            temp = temp->next;
        }
        return count;
    }

    void deleteAllOccurrences(int key) {
        while (head && head->data == key) {
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
        }
        if (!head) return;

        Node* temp = head;
        while (temp->next) {
            if (temp->next->data == key) {
                Node* toDelete = temp->next;
                temp->next = temp->next->next;
                delete toDelete;
            } else {
                temp = temp->next;
            }
        }
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data;
            if (temp->next) cout << "->";
            temp = temp->next;
        }
        cout << "\n";
    }
};

int main() {
    LinkedList list;
    int arr[] = {1,2,1,2,1,3,1};
    for (int val : arr) list.insertAtEnd(val);

    int key = 1;
    cout << "Original list: ";
    list.display();

    int count = list.countOccurrences(key);
    cout << "Count: " << count << "\n";

    list.deleteAllOccurrences(key);
    cout << "Updated list: ";
    list.display();

    return 0;
}

/*
Output:
Original list: 1->2->1->2->1->3->1
Count: 4
Updated list: 2->2->3
*/
