#include <stdio.h>
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int lcm(int a, int b) {
    return a * b / gcd(a, b);
}
int main() {
    int n;
    int H[2000];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &H[i]);
    }

    int max_s = 0; 
    int best_a = 0, best_b = 0, best_c = 0;
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                int a = H[i], b = H[j], c = H[k];
                int lcm_ab = lcm(a, b);
                int lcm_bc = lcm(b, c);
                int lcm_ca = lcm(c, a);
                int s = (a * b * c * lcm_ab) / (lcm_ab * lcm_bc * lcm_ca);
                if (s > max_s || (s == max_s && (a < best_a || (a == best_a && (b < best_b || (b == best_b && c < best_c)))))) {
                    max_s = s;
                    best_a = a;
                    best_b = b;
                    best_c = c;
                }
            }
        }
    }
    printf("%d %d %d\n", best_a, best_b, best_c);
    return 0;
}
