/** 
 * Sarievo.
 * DESCRIPTION: generate randomized test cases with arg[1] as the seed
 */

#include <bits/stdc++.h>
#define poly vector<int>
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL) // make io faster
#define rep(i, n) for(int i = 0; i < n; i++)
#define ll long long
#define mp make_pair
#define mt make_tuple
#define pa pair<int,int>
#define fi first
#define se second
#define inf 1e18
#define int ll
#define all(a) (a).begin(), (a).end()
#define foreach(it, a) for(__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++) // iterate from sequence for a given type
template<typename X> inline X abs(const X& a) { return (a < 0 ? -a : a); }
template<typename X> inline X sqr(const X& a) { return (a * a); }
using namespace std;

// generate a number from the range inclusively
int rnd(int a, int b);

signed main(signed argc, char* argv[]){
    int seed = atoi(argv[1]);
    srand(seed);

    int T = 1;
    // T = rnd(1, 10); cout << T << endl;

    rep(i, T) {
        int n = rnd(1, 5);
        int K = rnd(1, 10); // see, if we input a very large number like 1e18, we may not find the edge cases at all.
        string S = "";
        rep(i, n) {
            int choice_of_char = rnd(1, 3);
            S += ('0'+choice_of_char);
        }
        cout << S << endl;
        cout << K << endl;
    }
}

int rnd(int a, int b) {
    return a + rand() % (b - a + 1);
}
