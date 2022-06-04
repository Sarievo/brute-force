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
        int n;
        string s;
        cin >> n >> s;
        string ans = "";
        int curr = -1;
        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (c == '1') {
                if (curr == -1) {
                    curr = 1;
                } else curr++;
            } else {
                if (curr > 0) ans += '0' + curr;
                else ans += '0';
                curr = -1;
            }
        }
        if (curr > 0) ans += '0' + curr;
                else ans += '0';
        cout << ans << endl;
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