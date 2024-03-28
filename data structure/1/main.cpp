#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main() {
    stack<int> s;
    vector<int> v;

    while (!s.empty()) {
        s.pop();
        printf("Stack is empty\n");
    }
    return 0;
}