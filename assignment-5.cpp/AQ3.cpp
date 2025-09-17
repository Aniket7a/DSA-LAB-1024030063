// Aniket 1024030063 2C71
// 3) Find middle of linked list
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
    int findMiddle() {
        if (!head) return -1;
        Node* slow = head;
        Node* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow->data;
    }
};

int main() {
    LinkedList list;
    int arr[] = {1, 2, 3, 4, 5};
    for (int val : arr) list.insertAtEnd(val);

    cout << "Middle element: " << list.findMiddle() << "\n";

    return 0;
}

/*
Output:
Middle element: 3
*/
