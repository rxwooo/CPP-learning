#include <bits/stdc++.h>
using namespace std;

int a, b, c;

int w[31][31][31];

int f(int a, int b, int c) {
    if (a <= 0 || b <= 0 || c <= 0) {
        return 1;
    }
    if (w[a][b][c] != -1) {
        return w[a][b][c];
    }
    if (a > 20 || b > 20 || c > 20) {
        return w[a][b][c] = f(20, 20, 20);
    }
    if (a < b && b < c) {
        return w[a][b][c] = f(a, b, c - 1) + f(a, b - 1, c - 1) - f(a, b - 1, c);
    }
    return w[a][b][c] = f(a - 1, b, c) + f(a - 1, b - 1, c) + f(a - 1, b, c - 1) - f(a - 1, b - 1, c - 1);
}

int main() {
    while (cin >> a >> b >> c) {
        memset(w, -1, sizeof(w));
        cout << f(a, b, c) << endl;
    }
    return 0;
}