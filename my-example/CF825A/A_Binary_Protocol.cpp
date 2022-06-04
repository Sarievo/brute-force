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
        vector<string> tokens;
        bool started = false;
        string current = "";
        for (int i = 0; i < n; i++) {
            // cout << "read" << s[i] << endl;
            if (s[i] == '1') {
                if (!started) started = true;
                if (started) current += s[i];
            } else {
                if (started) tokens.push_back(current);
                else tokens.push_back("");
                current = "";
                started = false;
            }
        }
        if (started) tokens.push_back(current);
        else tokens.push_back("");
        
        string number = "";
        for (int i = 0; (int) i < tokens.size(); i++) {
            number += '0' + tokens[i].length();
        }
        cout << number << endl;
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