#include <iostream>
#include <stack>
#include <tuple>
using namespace std;

struct Move {
    int n;
    char source, target, auxiliary;
};

void TowerOfHanoi(int n, char source, char target, char auxiliary) {
    stack<Move> stack;

    stack.push({n, source, target, auxiliary});

    while (!stack.empty()) {
        Move current = stack.top();
        stack.pop();

        if (current.n == 1) {
            cout << "Move disk 1 from " << current.source 
                 << " to " << current.target << endl;
        } else {
            stack.push({current.n - 1, current.auxiliary, current.target, current.source});
            stack.push({1, current.source, current.target, current.auxiliary});
            stack.push({current.n - 1, current.source, current.auxiliary, current.target});
        }
    }
}

int main() {
    int numDisks;
    cout << "Enter the number of disks: ";
    cin >> numDisks;

    TowerOfHanoi(numDisks, 'A', 'C', 'B');

    return 0;
}
