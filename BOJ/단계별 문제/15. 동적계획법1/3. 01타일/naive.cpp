#include <iostream>
#include <vector>
using namespace std;

#define mod 15746

int main() {
    int N;

    cin >> N;

    vector<int> cald(N);
    cald[0] = 1, cald[1] = 2;

    for (int i=2; i<N; i++) 
        cald[i] = (cald[i-2]+cald[i-1])%mod;

    cout << cald.back();
    return 0;
}