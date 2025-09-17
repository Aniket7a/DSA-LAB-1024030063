// Aniket 1024030063 2C71
// 4) First non-repeating character in string using Queue

#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

void firstNonRepeating(string s) {
    queue<char> q;
    unordered_map<char, int> freq;

    for (char ch : s) {
        freq[ch]++;
        q.push(ch);

        while (!q.empty() && freq[q.front()] > 1)
            q.pop();

        if (q.empty())
            cout << -1 << " ";
        else
            cout << q.front() << " ";
    }
    cout << "\n";
}

int main() {
    string input = "aabc";
    firstNonRepeating(input);

    return 0;
}

/*
Output:
a -1 b b 
*/
