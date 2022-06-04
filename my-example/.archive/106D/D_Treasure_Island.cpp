#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>     // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key

// find_by_order-> int ele=*find_by_order(idx);->gives idx th pos ele in ordered set and 0 based indexing is used;
// order_of_key->  int n=order_of_key(x);-> gives the no of element strictly smaller than x;
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define endl "\n"
#define ll long long
#define f first
#define s second
#define pii pair<int, int>
#define lui long unsigned int

const int N = 5000005;
const ll MOD = 1e9 + 7;
const ll MOD1 = 998244353;
const ll INF = 1e18;

long long binpow(long long a, long long b, long long m){
    a %= m;
    long long res = 1; /**/

    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }

    return res;
}

int gcd_equation(int a, int b, int &x, int &y) {
    x = 1, y = 0;
    int x1 = 0, y1 = 1, a1 = a, b1 = b;

    while (b1) {
        int q = a1 / b1;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }

    return a1;
}

void prime_generator(vector<bool> &is_prime) {
    int n = N;
    is_prime.resize(n);
    fill(is_prime.begin(), is_prime.end(), true);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
}

void lowest_prime_factor(vector<int> &lp) {
    int n = 10000000;
    lp.resize(n + 1);
    fill(lp.begin(), lp.end(), 0);
    vector<int> pr;

    for (int i = 2; i <= n; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }

        for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= n; ++j) {
            lp[i * pr[j]] = pr[j];
        }
    }
}

void ncr(int n, vector<ll> &factorial, vector<ll> &facinv, ll MOD) {
    factorial[0] = 1;

    for (ll i = 1; i <= n; i++) {
        factorial[i] = factorial[i - 1] * i;
        factorial[i] %= MOD;
    }

    ll modinv = binpow(factorial[n], MOD - 2, MOD);
    facinv[n] = modinv;

    for (ll i = n - 1; i >= 0; i--) {
        facinv[i] = facinv[i + 1] * (i + 1);
        facinv[i] %= MOD;
    }
}

bool cycle_dectector_dg(int s, vector<int> adj[], vector<int> &vis) {
    vis[s] = 1;
    
    for (auto child : adj[s]) {
        if (vis[child] == 0) {
            if (cycle_dectector_dg(child, adj, vis))
                return true;
        }
        else if (vis[child] == 1)
            return true;
    }
    vis[s] = 2;
    return false;
}

bool cycle_dectector_ug(int s, int par, vector<int> adj[], vector<int> &vis) {
    vis[s] = 1;
    for (auto child : adj[s]) {
        if (child == par)
            continue;

        if (vis[child])
            return true;
        else {
            if (cycle_dectector_ug(child, s, adj, vis))
                return true;
        }
    }
    return false;
}

bool is_bipartite(int s, vector<int> &vis, vector<int> adj[], vector<int> &col, int curr, int &one, int &sz) {
    col[s] = curr;
    sz += 1;
    if (curr == 1)
        one += 1;

    vis[s] = 1;

    for (auto child : adj[s]) {

        if (vis[child]) {
            if (col[child] == col[s])
                return false;
        } else {
            if (is_bipartite(child, vis, adj, col, (curr ^ 1), one, sz) == false)
                return false;
        }
    }

    return true;
}

void dijkstra(int s, vector<pair<int, int>> adj[], vector<ll> &dist) {
    int n = dist.size();
    vector<int> vis(n, 0);
    dist[s] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> mnheap; // mnheap.push(), mnheap.top(), mnheap.pop()
    mnheap.push({0, s});

    while (!mnheap.empty()) {
        ll node = mnheap.top().second;
        ll d = mnheap.top().first;

        mnheap.pop();

        if (vis[node])
            continue;

        vis[node] = 1;

        for (auto child : adj[node]) {
            if (dist[node] != INF) {
                ll curr = d + child.second;

                if (dist[child.first] > curr) {
                    dist[child.first] = curr;
                    mnheap.push({curr, child.first});
                }
            }
        }
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int test;
    test = 1;
    // cin>>test;

    int test_no = 1;

    while (test--) {
        int n, m;
        cin >> n >> m;

        vector<string> mat(n);

        for (int i = 0; i < n; i++) {
            cin >> mat[i];
        }

        int k;
        cin >> k;

        vector<char> dir(k);
        vector<int> len(k);

        for (int i = 0; i < k; i++) {
            cin >> dir[i] >> len[i];
        }

        vector<vector<int>> left_row(n, vector<int>(m, 0)), right_row(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            int len = 0;

            for (int j = 0; j < m; j++) {
                if (mat[i][j] == '#') {
                    len = 0;
                } else {
                    len += 1;
                    left_row[i][j] = len;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            int len = 0;

            for (int j = m - 1; j >= 0; j--) {
                if (mat[i][j] == '#') {
                    len = 0;
                } else {
                    len += 1;
                    right_row[i][j] = len;
                }
            }
        }

        vector<vector<int>> up_col(n, vector<int>(m, 0)), down_col(n, vector<int>(m, 0));

        for (int j = 0; j < m; j++) {
            int len = 0;

            for (int i = 0; i < n; i++) {

                if (mat[i][j] == '#')
                    len = 0;
                else {
                    len += 1;
                    up_col[i][j] = len;
                }
            }
        }

        for (int j = 0; j < m; j++) {
            int len = 0;

            for (int i = n - 1; i >= 0; i--) {

                if (mat[i][j] == '#')
                    len = 0;
                else {
                    len += 1;
                    down_col[i][j] = len;
                }
            }
        }

        string ans;

        // for(int i=0;i<n;i++) {
        //      for(int j=0;j<m;j++) {
        //          cout<<down_col[i][j]<<" ";
        //      }

        //      cout<<endl;
        // }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] != '#' && mat[i][j] != '.') {
                    int x = i, y = j;
                    bool ok = true;

                    for (int p = 0; p < k; p++) {

                        if (dir[p] == 'S') {
                            if (down_col[x][y] <= len[p]) {
                                ok = false;
                                break;
                            }

                            x += len[p];
                        } else if (dir[p] == 'N') {
                            if (up_col[x][y] <= len[p]) {
                                ok = false;
                                break;
                            }

                            x -= len[p];
                        } else if (dir[p] == 'E') {
                            if (right_row[x][y] <= len[p]) {
                                ok = false;
                                break;
                            }

                            y += len[p];
                        } else {
                            if (left_row[x][y] <= len[p]) {
                                ok = false;
                                break;
                            }

                            y -= len[p];
                        }

                        // cout<<x<<" "<<y<<endl;

                        if (x < 0 || x >= n || y < 0 || y >= m) {
                            ok = false;
                            break;
                        }
                    }

                    if (ok)
                        ans += mat[i][j];
                }
            }
        }

        sort(ans.begin(), ans.end());

        if (!ans.empty())
            cout << ans << endl;
        else {
            cout << "no solution" << endl;
        }
    }

    clock_t time_req = clock();
    // cout<<(float)time_req/CLOCKS_PER_SEC << " seconds" << endl;

    return 0;
}