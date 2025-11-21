#include <iostream>
using namespace std;

void solve() {
    long long a, b, n;
    cin >> a >> b >> n;

    if (a >= b * n) {
        cout << 1 << "\n";
        return;
    }

    long long ans = (b * n + a - 1) / a;
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
