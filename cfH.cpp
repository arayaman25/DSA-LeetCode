#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    long long count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            long long x = arr[i];
            long long y = arr[j];

            if (x < y && ((y % x) % 2 == 0)) {
                cout << x << " " << y << endl;
                count++;
                break;
            }
        }
        if (count > 0) break; 
    }

    if (count == 0)
        cout << "-1"<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
