// DrMaemi - 2020KB, 1760ms
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int N, count[10001] = {0};

    cin >> N;

    for (int i=0; i<N; i++) {
        int tmp;

        cin >> tmp;
        count[tmp]++;
    }

    for (int i=1; i<=10000; i++)
        for (int j=0; j<count[i]; j++)
            cout << i << "\n";

    return 0;
}