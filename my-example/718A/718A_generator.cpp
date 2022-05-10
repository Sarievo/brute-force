#include <bits/stdc++.h>
using namespace std;


int rnd(int a, int b){
    return a + rand() % (b - a + 1); // ???
}

int main(int argc, char* argv[]){
    int seed = atoi(argv[1]);
    srand(seed);

    int c1 = rnd(1, 8);
    int c2 = rnd(1, 8);
    string s = "??";
    s[0] = 'a' + c1 - 1;
    s[1] = '1' + c2 - 1;

    cout << s << endl;
}
