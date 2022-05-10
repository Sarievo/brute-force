#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rp(i, n) for (int i = 0; i < n; i++)
#define N cout << "NO" << endl;
#define Y cout << "YES" << endl;

template <typename T> void sort(vector<T> &a, bool desc = false);
template <typename T> void print(vector<T> &A);


int main() {
    int cases = 1;
    // cin >> cases;
    while (cases--) {
        string s;
        cin >> s;
        string cmp = "hello";
        int idx = 0;
        for (int i = 0; i < s.length(); i++) {
            char c1 = cmp[idx];
            char c2 = s[i];
            if (c1 == c2) {
                idx++;
                if (idx >= cmp.length()) {
                    cout << "YES" << endl;
                    return 0;
                }
            }
        }
        N;
    }
    return 0;
}

//======== ⚠ Do't Complicate the Problem ⚠ ========

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