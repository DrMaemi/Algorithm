#include<iostream>
#include<algorithm>
using namespace std;
int f(int n) {
	return n < 2 ? 0 : min(f(n / 2) + n % 2, f(n / 3) + n % 3) + 1;
}

int main() {
	int n;
	cin >> n;
	cout << f(n);
	return 0;
}