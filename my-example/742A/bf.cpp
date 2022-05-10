#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rp(i, n) for (int i = 0; i < n; i++)
#define N cout << "NO" << endl;
#define Y cout << "YES" << endl;

template <typename T> void sort(vector<T> &a, bool desc = false);
template <typename T> void print(vector<T> &A);

ll mod = 1e9;

int main() {
    int cases = 1;
    // cin >> cases;
    while (cases--) {
        int n;
        cin >> n;
        ll ans = 1;
        for (int i = 0; i < n; i++) {
            ans *= 8;
            if (ans > mod)
                ans = ans % mod;
        }
        cout << (ans % 10) << endl;
    }
    return 0;
}

//======== ⚠ Don't Complicate the Problem ⚠ ========

template <typename T>
void sort(vector<T> &a, bool desc) {
    if (desc) {
        sort(a.begin(), a.end(), [](T a, T b) {return a > b;});
    } else {
        sort(a.begin(), a.end());
    }
}

template <typename T>
void print(vector<T> &A) {
    int n = A.size();
    cout << n << endl;
    rp(i, n) cout << A[i] << " ";
    cout << endl;
}