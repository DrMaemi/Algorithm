#include <iostream>
using namespace std;
typedef long long ll;

int A, B, C;

ll pow(int x, int n) {
    if (!n)
        return 1;
    else if (n == 1)
        return x%C;
    else if (n%2)
        return (pow(x, n-1)*x)%C;
    else {
        ll h = pow(x, n/2)%C;
        return (h*h)%C;
    }
}

int main() {
    cin >> A >> B >> C;
    cout << pow(A, B);
    return 0;
}