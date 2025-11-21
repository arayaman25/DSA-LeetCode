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

    long long x;
    cin >> x;

    long long mn = arr[0];
    long long mx = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] < mn) 
        mn = arr[i];
        if (arr[i] > mx) 
        mx = arr[i];
    }

    if (x >= mn && x <= mx)
        cout << "YES"<<endl;
    else
        cout << "NO"<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) solve();

    return 0;
}
