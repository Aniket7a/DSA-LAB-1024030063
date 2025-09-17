// Aniket 1024030063 2C71
// 1) Simple Queue operations

#include <iostream>
using namespace std;

class SimpleQueue {
    int* queue;
    int front, rear, size;
public:
    SimpleQueue(int s) {
        size = s;
        queue = new int[size];
        front = rear = -1;
    }
    bool isEmpty() {
        return front == -1;
    }
    bool isFull() {
        return rear == size - 1;
    }
    void enqueue(int val) {
        if (isFull()) {
            cout << "Queue is full\n";
            return;
        }
        if (front == -1) front = 0;
        queue[++rear] = val;
    }
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        int val = queue[front];
        if (front == rear) front = rear = -1;
        else front++;
        return val;
    }
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        return queue[front];
    }
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        for (int i = front; i <= rear; i++)
            cout << queue[i] << " ";
        cout << "\n";
    }
};

int main() {
    SimpleQueue q(3);
    q.enqueue(10);
    q.enqueue(20);
    q.display();
    cout << "Peek: " << q.peek() << "\n";
    cout << "Dequeued: " << q.dequeue() << "\n";
    q.display();

    return 0;
}

/*
Output:
10 20 
Peek: 10
Dequeued: 10
20 
*/
