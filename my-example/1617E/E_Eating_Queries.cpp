#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rp(i, n) for (int i = 0; i < n; i++)
#define N cout << "NO" << endl;
#define Y cout << "YES" << endl;

template <typename T> void sort(vector<T> &a, bool desc = false);
template <typename T> void print(vector<T> &A);


int findDist(char a, char b) {
    int less = min(a, b);
    int more = max(a, b);
    return more - less;
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        vector<int> candies(n, 0);
        // ll sum = 0;
        rp(i, n) {
            cin >> candies[i];
            // sum += candies[i];
        }
        
        sort(candies, true);
        for (int i = 1; i < n; i++) {
            candies[i] += candies[i - 1];
        }
        // print(candies);

        rp(i, q) {
            int target;
            cin >> target;

            if (target > candies[n - 1]) {
                cout << -1 << endl;
            } else if (target == candies[n - 1]) {
                cout << n << endl;
            } else {
                int L = 0;
                int R = n - 1;
                bool found = false;
                while (L <= R) {
                    int M = L + (R - L) / 2;
                    if (candies[M] == target) {
                        cout << (M + 1) << endl;
                        found = true;
                        break;
                    } else if (candies[M] > target) {
                        R = M - 1;
                    } else {
                        L = M + 1;
                    }
                }

                if (!found) cout << (L + 1) << endl;
                // for (int i = 0; i < n; i++) {
                //     if (candies[i] >= target) {
                //         cout << i + 1 << endl;
                //         break;
                //     }
                // }
            }
        }
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
    // cout << n << endl;
    rp(i, n) cout << A[i] << " ";
    cout << endl;
}