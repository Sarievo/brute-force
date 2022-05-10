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

    int n = rnd(0, 4);
    string s = "1";
    for (int i = 0; i < n; i++) {
        s += rnd(0, 1) ? "1" : "0";
    }
    cout << (n + 1) << endl;
    cout << s << endl;
}

int rnd(int a, int b) {
    return a + rand() % (b - a + 1);
}

ll rnd(ll a, ll b) {
    return a + rand() % (b - a + 1);
}