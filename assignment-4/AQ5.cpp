// Aniket 1024030063 2C71
// 5a) Stack using Two Queues
#include <iostream>
#include <queue>
using namespace std;

class StackTwoQueues {
    queue<int> q1, q2;
public:
    void push(int x) {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }
    int pop() {
        if (q1.empty()) return -1;
        int val = q1.front();
        q1.pop();
        return val;
    }
    int top() {
        if (q1.empty()) return -1;
        return q1.front();
    }
    bool empty() {
        return q1.empty();
    }
};

int main() {
    StackTwoQueues s;
    s.push(10);
    s.push(20);
    cout << s.pop() << "\n";  // 20
    cout << s.top() << "\n";  // 10

    return 0;
}

/*
Output:
20
10
*/
