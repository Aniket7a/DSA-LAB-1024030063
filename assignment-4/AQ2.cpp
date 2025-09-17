// Aniket 1024030063 2C71
// 2) Circular Queue operations

#include <iostream>
using namespace std;

class CircularQueue {
    int* queue;
    int front, rear, size;
public:
    CircularQueue(int s) {
        size = s;
        queue = new int[size];
        front = rear = -1;
    }
    bool isEmpty() {
        return front == -1;
    }
    bool isFull() {
        return (rear + 1) % size == front;
    }
    void enqueue(int val) {
        if (isFull()) {
            cout << "Queue is full\n";
            return;
        }
        if (isEmpty()) front = 0;
        rear = (rear + 1) % size;
        queue[rear] = val;
    }
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        int val = queue[front];
        if (front == rear) front = rear = -1;
        else front = (front + 1) % size;
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
        int i = front;
        while (true) {
            cout << queue[i] << " ";
            if (i == rear) break;
            i = (i + 1) % size;
        }
        cout << "\n";
    }
};

int main() {
    CircularQueue q(3);
    q.enqueue(5);
    q.enqueue(10);
    q.display();
    cout << "Dequeued: " << q.dequeue() << "\n";
    q.display();
    cout << "Peek: " << q.peek() << "\n";

    return 0;
}

/*
Output:
5 10 
Dequeued: 5
10 
Peek: 10
*/
