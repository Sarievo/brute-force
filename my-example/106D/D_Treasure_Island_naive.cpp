#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rp(i, n) for (int i = 0; i < n; i++)
#define N cout << "NO" << endl;
#define Y cout << "YES" << endl;

template <typename T> void sort(vector<T> &a, bool desc = false);
template <typename T> void print(vector<T> &A);

bool checkLegal(vector<vector<char>> map, int codeI, int codeJ, vector<pair<int, int>> dir) {
    int x = codeI;
    int y = codeJ;
    // cout << "start at " << map[codeI][codeJ] << " " << codeI << ":" << codeJ << endl;
    for (int i = 0; (int) i < dir.size(); i++) {
        int newX = x + dir[i].first;
        int newY = y + dir[i].second;
        // cout << "getting" << dir[i].first << ":" << dir[i].second << endl \
             << "new x:" << newX << " new y:" << newY << endl << endl;
        
        if (newX < 1 || newY < 1 || (newX + 1) >= map.size() || (newY + 1) >= map[0].size()) 
            return false; // if sea
        for (int k = min(x, newX); k <= max(x, newX); k++) {
            for (int j = min(y, newY); j <= max(y, newY); j++) {
                if (map[k][j] == '#')
                    return false;
            }
        }
        x = newX;
        y = newY;
    }
    return true;
}

int main() {
    int cases = 1;
    // cin >> cases;
    while (cases--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> map(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> map[i][j];
            }
        }
        int k;
        cin >> k;
        vector<pair<int, int>> dir;
        for (int i = 0; i < k; i++) {
            char c; int dist;
            cin >> c >> dist;
            if (c == 'N') 
                dir.push_back({-dist, 0});
            else if (c == 'S')
                dir.push_back({+dist, 0});
            else if (c == 'W')
                dir.push_back({0, -dist});
            else if (c == 'E')
                dir.push_back({0, +dist});
        }
        // for (int i = 0; i < k; i++) {
        //     auto p = dir[i];
        //     cout << p.first << ":" << p.second << endl;
        // }

        /*
        Brute Force Solution is easy:
        just iterate though each of the coordination
        exclude the illegal ones and print the legal ones
        but it will likely get a TLE
        */
       string answer = "";
       for (int i = 1; i < n - 1; i++) {
           for (int j = 1; j < m - 1; j++) {
               char sign = map[i][j];
               if (sign != '#' && sign != '.') {
                   if (checkLegal(map, i, j, dir))
                       answer += sign;
               }
           }
       }
       sort(answer.begin(), answer.end());
       cout << (answer.length() > 0 ? answer : "no solution") << endl;
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