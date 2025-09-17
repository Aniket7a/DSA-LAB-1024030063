// Aniket 1024030063 2C71
// 5b) Stack using One Queue

#include <iostream>
#include <queue>
using namespace std;

class StackOneQueue {
    queue<int> q;
public:
    void push(int x) {
        q.push(x);
        int sz = q.size();
        for (int i = 0; i < sz - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    int pop() {
        if (q.empty()) return -1;
        int val = q.front();
        q.pop();
        return val;
    }
    int top() {
        if (q.empty()) return -1;
        return q.front();
    }
    bool empty() {
        return q.empty();
    }
};

int main() {
    StackOneQueue s;
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
