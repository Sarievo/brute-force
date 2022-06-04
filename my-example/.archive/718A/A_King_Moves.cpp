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
        bool L = s[0] == 'a';
        bool R = s[0] == 'h';
        bool U = s[1] == '8';
        bool D = s[1] == '1';
        int ans = 0;
        if (!L && !R && !U && !D) {
            ans = 8;
        } else if (L && U || U && R || L && D || D && R) {
            ans = 3;
        } else {
            ans = 5;
        }
        cout << ans << endl;
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