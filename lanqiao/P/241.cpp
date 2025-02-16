#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int T;
    cin >> T;
    long long sum[T];
    for (int i = 0; i < T; i++) {
        int A, B, C, N;
        cin >> A >> B >> C >> N;
        sum[i] = pow(A * B * C, pow(2, N));
    }
    for (int i = 0; i < T; i++) {
        cout << sum[i] << endl;
    }
    return 0;
}