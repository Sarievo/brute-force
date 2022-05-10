#include <bits/stdc++.h>
#define ll long long

using namespace std;

int mod = 1e9;

// generate a number from the range inclusively
int rnd(int a, int b);
ll rnd(ll a, ll b);

int main(int argc, char* argv[]){
    int seed = atoi(argv[1]);
    srand(seed);

    int t = rnd(1, 5);
    int n = rnd(1, 5);
    int q = rnd(1, 5);
    vector<int> candies(n, 0);
    vector<int> queries(q, 0);
    for (int i = 0; i < n; i++) {
        candies[i] = rnd(1, 10);
    }
    for (int i = 0; i < q; i++) {
        queries[i] = rnd(1, 50);
    }
    cout << t << endl;
    cout << n << " " << q << endl;
    for (int i = 0; i < n; i++) cout << candies[i] << " ";
    cout << endl;
    for (int i = 0; i < q; i++) cout << queries[i] << endl;
}

int rnd(int a, int b) {
    return a + rand() % (b - a + 1);
}

ll rnd(ll a, ll b) {
    return a + rand() % (b - a + 1);
}