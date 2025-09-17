// Aniket 1024030063 2C71
// 3) Interleave first half of queue with second half

#include <iostream>
#include <queue>
using namespace std;

void interleaveQueue(queue<int>& q) {
    int size = q.size();
    int half = size / 2;
    queue<int> firstHalf;

    for (int i = 0; i < half; i++) {
        firstHalf.push(q.front());
        q.pop();
    }

    while (!firstHalf.empty()) {
        q.push(firstHalf.front());
        firstHalf.pop();
        q.push(q.front());
        q.pop();
    }
}

int main() {
    queue<int> q;
    int arr[] = {4, 7, 11, 20, 5, 9};
    for (int val : arr) q.push(val);

    interleaveQueue(q);

    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << "\n";

    return 0;
}

/*
Output:
4 20 7 5 11 9 
*/
