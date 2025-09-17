// Aniket 1024030063 2C71
// 4) Reverse a linked list
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

    void reverse() {
        Node* prev = nullptr;
        Node* curr = head;
        Node* next = nullptr;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
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
    int arr[] = {1, 2, 3, 4};
    for (int val : arr) list.insertAtEnd(val);

    cout << "Original list: ";
    list.display();

    list.reverse();

    cout << "Reversed list: ";
    list.display();

    return 0;
}

/*
Output:
Original list: 1->2->3->4
Reversed list: 4->3->2->1
*/
